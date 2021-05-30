#include "CoordinateS.hpp"

void CoordS::translation(const Vector<3> &vector) {
  for (uint32_t i = 0; i < 3; ++i) {
    this->center = this->center + vector;
  }
}

void CoordS::rotation(const MatrixRot<3> &matrix) {
  this->orientation = this->orientation * matrix;
}

Vector<3> CoordS::pointInPredec(Vector<3> point) {
  return (this->orientation * point + this->center);
}
Vector<3> CoordS::coordSInGlob(Vector<3> resultV) {
  if (this->predecessor != nullptr) {
    resultV = pointInPredec(resultV);
    return this->predecessor->coordSInGlob(resultV);
  }
  return pointInPredec(resultV);
}

drawNS::Point3D CoordS::convert(const Vector<3> &vector) {
  return drawNS::Point3D(vector[0], vector[1], vector[2]);
}