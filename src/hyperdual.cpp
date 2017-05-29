#include <iostream>
#include <hyperdual.h>

template <typename T>
T f(T a, T b, T c) {
  return a * a * a * sin(b) * cos(c);
}

template <typename T>
T dfa(T a, T b, T c) {
  return T(3.0) * a * a * sin(b) * cos(c);
}

template <typename T>
T dfaa(T a, T b, T c) {
  return T(6.0) * a * sin(b) * cos(c);
}

template <typename T>
T dfb(T a, T b, T c) {
  return a * a * a * cos(b) * cos(c);
}

template <typename T>
T dfab(T a, T b, T c) {
  return T(3.0) * a * a * cos(b) * cos(c);
}

template <typename T>
T dfbc(T a, T b, T c) {
  return -a * a * a * cos(b) * sin(c);
}

template <typename T>
T dfbb(T a, T b, T c) {
  return -a * a * a * sin(b) * cos(c);
}

template <typename T>
T dfc(T a, T b, T c) {
  return -a * a * a * sin(b) * sin(c);
}

template <typename T>
T dfac(T a, T b, T c) {
  return -T(3.0) * a * a * sin(b) * sin(c);
}

template <typename T>
T dfcc(T a, T b, T c) {
  return -a * a * a * sin(b) * cos(c);
}

int main() {
  std::cout << f(hyperdual(1.0, 1.0, 1.0, 0.0), hyperdual(2.0, 0.0, 0.0, 0.0),
                 hyperdual(3.0, 0.0, 0.0, 0.0))
                   .eps1eps2()
            << " ";
  std::cout << f(hyperdual(1.0, 1.0, 0.0, 0.0), hyperdual(2.0, 0.0, 1.0, 0.0),
                 hyperdual(3.0, 0.0, 0.0, 0.0))
                   .eps1eps2()
            << " ";
  std::cout << f(hyperdual(1.0, 1.0, 0.0, 0.0), hyperdual(2.0, 0.0, 0.0, 0.0),
                 hyperdual(3.0, 0.0, 1.0, 0.0))
                   .eps1eps2()
            << std::endl;

  std::cout << f(hyperdual(1.0, 0.0, 1.0, 0.0), hyperdual(2.0, 1.0, 0.0, 0.0),
                 hyperdual(3.0, 0.0, 0.0, 0.0))
                   .eps1eps2()
            << " ";
  std::cout << f(hyperdual(1.0, 0.0, 0.0, 0.0), hyperdual(2.0, 1.0, 1.0, 0.0),
                 hyperdual(3.0, 0.0, 0.0, 0.0))
                   .eps1eps2()
            << " ";
  std::cout << f(hyperdual(1.0, 0.0, 0.0, 0.0), hyperdual(2.0, 1.0, 0.0, 0.0),
                 hyperdual(3.0, 0.0, 1.0, 0.0))
                   .eps1eps2()
            << std::endl;

  std::cout << f(hyperdual(1.0, 0.0, 1.0, 0.0), hyperdual(2.0, 0.0, 0.0, 0.0),
                 hyperdual(3.0, 1.0, 0.0, 0.0))
                   .eps1eps2()
            << " ";
  std::cout << f(hyperdual(1.0, 0.0, 0.0, 0.0), hyperdual(2.0, 0.0, 1.0, 0.0),
                 hyperdual(3.0, 1.0, 0.0, 0.0))
                   .eps1eps2()
            << " ";
  std::cout << f(hyperdual(1.0, 0.0, 0.0, 0.0), hyperdual(2.0, 0.0, 0.0, 0.0),
                 hyperdual(3.0, 1.0, 1.0, 0.0))
                   .eps1eps2()
            << std::endl;

  std::cout << std::endl;

  std::cout << dfaa(1.0, 2.0, 3.0) << " " << dfab(1.0, 2.0, 3.0) << " "
            << dfac(1.0, 2.0, 3.0) << std::endl;
  std::cout << dfab(1.0, 2.0, 3.0) << " " << dfbb(1.0, 2.0, 3.0) << " "
            << dfbc(1.0, 2.0, 3.0) << std::endl;
  std::cout << dfac(1.0, 2.0, 3.0) << " " << dfbc(1.0, 2.0, 3.0) << " "
            << dfcc(1.0, 2.0, 3.0) << std::endl;

 //std::cout <<"ERF "<< erf(hyperdual(1.0, 1.0, 1.0, 0.0)).eps1()<< std::endl;
 //std::cout <<"ERF "<< erf(hyperdual(1.0, 1.0, 1.0, 0.0)).eps1eps2()<< std::endl;

  return 0;
}
