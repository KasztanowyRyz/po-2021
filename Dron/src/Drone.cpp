#include "Drone.hpp"

#include <initializer_list>
#include <utility>

#include "Animation.hpp"

void wait4key() {
  do {
    std::cout << "\n Press a key to continue..." << std::endl;
  } while (std::cin.get() != '\n');
}

void Drone::goForward(const double &distance) {
  Vector<3> course({0, distance, 0});
  course = this->orientation * course;
  this->center = this->center + course;
}

void Drone::goVertical(const double &height) {
  Vector<3> altitude({0, 0, height});
  this->center = this->center + altitude;
}
void Drone::rotate(const double &angle) {
  MatrixRot<3> matrixR(angle, Axis::OZ);
  this->orientation = this->orientation * matrixR;
}

void Drone::draw(std::shared_ptr<drawNS::Draw3DAPI> api) {
  dBody.draw(api);
  for (uint32_t i = 0; i < 4; ++i) rotor[i].draw(api);
  for (uint32_t i = 0; i < 2; ++i) searchlight[i].draw(api);
  for (uint32_t i = 0; i < 4; ++i) {
    for (uint32_t j = 0; j < 2; ++j) rotorBlades[i][j].draw(api);
  }
  rotorSpin();
}
void Drone::animation(double height, double angle, double distance,
                      std::shared_ptr<drawNS::Draw3DAPI> api) {
  route(height, angle, distance, api);
  double fall = -height;
  std::initializer_list<std::pair<Animation::droneFPtr, const double &> >
      fPairL = {{&Drone::goVertical, height},
                {&Drone::rotate, angle},
                {&Drone::goForward, distance},
                {&Drone::goVertical, fall}};
  Animation::animeTime(fPairL, this, api);
  api->erase_shape(routeId);

}  // w innej klasie
void Drone::rotorSpin() {
  for (uint32_t i = 0; i < 4; ++i) {
    for (uint32_t j = 0; j < 2; ++j)
      rotorBlades[i][j].rotation(MatrixRot<3>(15, Axis::OZ));
  }
}

void Drone::route(double height, double angle, double distance,
                  std::shared_ptr<drawNS::Draw3DAPI> api) {
  int tmp;
  tmp = api->draw_polygonal_chain(
      {convert(this->center), convert(this->center + Vector<3>({0, 0, height})),
       convert(this->orientation * MatrixRot<3>(angle, Axis::OZ) *
                   Vector<3>({0, distance, height}) +
               this->center),
       convert(this->orientation * MatrixRot<3>(angle, Axis::OZ) *
                   Vector<3>({0, distance, 0}) +
               this->center)},
      "blue");

  if (routeId != -1) {
    api->erase_shape(routeId);
  }
  routeId = tmp;
}