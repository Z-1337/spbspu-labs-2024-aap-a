#include "matrixOutput.hpp"

void asafov::outputMatrix(std::ostream& out, const int* mtx, const unsigned long long n, const unsigned long long m)
{
  out << n << ' ' << m << ' ';
  for (int i = 0; i < n * m; i++) {
    out << mtx[i] << ' ';
  }
}