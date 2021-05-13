#include "Vector.hpp"

/**
 * Możemy za jego pomocą dostać się do poszczególnych współrzędnych wektora.
 * Umożliwa on dostęp do współrzędnych, z możliwością modyfikacji.
 * Gdy indeks jest spoza zakresu [0;SIZE] zostanie wypisanystosowny komunikat
 * oraz nastąpi wyjście z programu
 *
 * @tparam SIZE - Określa wymiarowość w jakiej znajduje się wektor
 * @param index - indeks współrzędnej do której chcemy uzyskać dostęp
 * @return Modyfikowalna referencja do  określonej indeksem współrzędnej
 */
template <uint32_t SIZE>
double &Vector<SIZE>::operator[](uint32_t index) {
  if (index < 0 || index > SIZE) {
    std::cerr << "Poza pamiecia!" << std::endl;
    exit(0);
  }
  return cords[index];
}

/**
 * Możemy za jego pomocą dostać się do poszczególnych współrzędnych wektora.
 * Umożliwa on dostęp do współrzędnych, bez możliwości modyfikacji.
 * Gdy indeks jest spoza zakresu [0;SIZE] zostanie wypisanystosowny komunikat
 * oraz nastąpi wyjście z programu
 *
 * @tparam SIZE - Określa wymiarowość w jakiej znajduje się wektor
 * @param index - indeks współrzędnej do której chcemy uzyskać dostęp
 * @return Niemodyfikowalna wartość określonej indeksem współrzędnej
 */
template <uint32_t SIZE>
const double &Vector<SIZE>::operator[](uint32_t index) const {
  if (index < 0 || index > SIZE) {
    std::cerr << "Poza pamiecia!" << std::endl;
    exit(0);
  }
  return cords[index];
}

/**
 * Dodaje odpowiednie składowe dwóch wektorów i zwraca wynik.
 *
 * @tparam SIZE - Określa wymiar wektora
 * @param Arg2 - Wektor który dodajemy
 * @return Zwraca wynik dodawania dwóch wektorów
 */
template <uint32_t SIZE>
Vector<SIZE> Vector<SIZE>::operator+(const Vector<SIZE> &Arg2) const {
  Vector<SIZE> Wynik;
  for (uint32_t i = 0; i < SIZE; ++i) {
    Wynik[i] = this->cords[i] + Arg2[i];
  }

  return Wynik;
}

/**
 * Odejmuje odpowiednie składowe dwóch wektorów i zwraca wynik.
 *
 * @tparam SIZE - Określa wymiar wektora
 * @param Arg2 - Wektor który odejmujemy
 * @return Zwraca wynik odejmowania dwóch wektorów
 */
template <uint32_t SIZE>
Vector<SIZE> Vector<SIZE>::operator-(const Vector<SIZE> &Arg2) const {
  Vector<SIZE> Wynik;
  for (uint32_t i = 0; i < SIZE; ++i) {
    Wynik[i] = this->cords[i] - Arg2[i];
  }

  return Wynik;
}

/**
 * Mnoży wszystkie składowe wektora przez przysłaną stałą.
 *
 * @tparam SIZE - Określa wymiar wektora
 * @param Arg2 - stała przez którą mnożymy
 * @return Zwraca wynik przemnożenia wektora przez stałą.
 */
template <uint32_t SIZE>
Vector<SIZE> Vector<SIZE>::operator*(const double &Arg2) const {
  Vector<SIZE> Wynik;
  for (uint32_t i = 0; i < SIZE; ++i) {
    Wynik[i] = this->cords[i] * Arg2;
  }

  return Wynik;
}

/**
 * Mnoży odpowiednie składowe wektora przez składowe drugiego wektora oraz
 * dodaje je do siebie
 *
 * @tparam SIZE - Określa wymiar wektora
 * @param Arg2 - stała przez którą mnożymy
 * @return Zwraca wynik przemnożenia wektora przez wektor.
 */
template <uint32_t SIZE>
double Vector<SIZE>::operator*(const Vector<SIZE> &Arg2) const {
  double Wynik = 0;
  for (uint32_t i = 0; i < SIZE; ++i) {
    Wynik += this->cords[i] * Arg2[i];
  }
  return Wynik;
}

/**
 * Liczy długość wektora
 * @tparam SIZE - Określa wymiar wektora
 * @return Zwraca długość wektora
 */
template <uint32_t SIZE>
double Vector<SIZE>::dlugosc() const {
  double Wynik = 0;
  for (uint32_t i = 0; i < SIZE; ++i) {
    Wynik += pow(this->cords[i], 2);
  }

  return sqrt(Wynik);
}

/**
 * Wczytanie wektora z odpowiedniego strumienia
 *
 * @param strm - strumien z którego ma zostać wczytany wektor
 * @param Vector - wektor który ma zostać wczytany
 * @return zwracamy referencję do przysłanego strumienia
 */
template <uint32_t SIZE>
std::istream &operator>>(std::istream &strm, Vector<SIZE> &Vector) {
  for (uint32_t i = 0; i < SIZE; ++i) {
    strm >> Vector[i];
  }
  // compilator sam ustawi failbita na strm jezeli zostanie wczytana
  // nieprawidlowa wartosc
  if (!strm.good()) {
    strm.clear();
    strm.ignore(std::numeric_limits<int>::max(), '\n');
    std::cerr << "Blad danych - brak conajmniej jednej skladowej wierzcholka"
              << std::endl;
    exit(0);
  }
  return strm;
}

/**
 * Wypisanie wektora na odpowiedni strumień
 *
 * @param strm - strumien na który ma zostać wypisany wektor
 * @param Vector - wektor który ma zostać wypisany
 * @return zwracamy referencję do przysłanego strumienia
 */
template <uint32_t SIZE>
std::ostream &operator<<(std::ostream &strm, const Vector<SIZE> &Vector) {
  for (uint32_t i = 0; i < SIZE; ++i) {
    strm << std::setw(12) << std::fixed << std::setprecision(10) << Vector[i]
         << " ";
  }
  strm << std::endl;
  return strm;
}

template class Vector<3>;

template std::ostream &operator<<(std::ostream &strm, const Vector<3> &Vector);
template std::istream &operator>>(std::istream &strm, Vector<3> &Vector);