#include "matrixInitiallization.hpp"
#include <stdexcept>

void asafov::initializationMatrixAuto(std::istream& in, int* mtx, size_t& n, size_t& m)
{
  in >> n;
  if (in.fail() || in.eof()) {
    throw std::logic_error("err");
  }
  in >> m;
  if (in.fail() || in.eof()) {
    throw std::logic_error("err");
  }
  for (size_t i = 0; i < n * m; i++) {
    in >> mtx[i];
    if (in.fail() || in.eof()) {
      throw std::logic_error("err");
    }
  }
}
