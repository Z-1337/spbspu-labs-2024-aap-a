#include <iomanip>
#include <cstring>
#include "f.cpp"
#include "stdf.cpp"

int main()
{
  double first_member = 0.0, last_member = 0.0;
  size_t max_members = 0;
  std::cin >> first_member >> last_member >> max_members;

  const double error = 0.001;
  const double step = 0.05;
  const char * errormsg = "<MATH ERROR>";
  const size_t second_column_width = std::strlen(errormsg);
  const size_t others_columns = 10;

  for (auto i = first_member ; i < last_member; i += step)
  {
    size_t oth = others_columns;
    std::cout << std::setw(oth) << i;
    std::cout << " ";
    size_t snd = second_column_width;
    try
    {
      std::cout << std::setw(snd) << kushekbaev::f(i, max_members, error);
    }
    catch (const std::logic_error & e)
    {
      std::cout << std::setw(snd) << errormsg;
    }
    std::cout << " " << std::setw(oth) << kushekbaev::stdf(i);
    std::cout << "\n";
  }
  std::cout << last_member;
  try
  {
    std::cout << " " << kushekbaev::f(last_member, max_members, error);
  }
  catch (const std::logic_error & e)
  {
    std::cout << errormsg;
  }

  std::cout << " " << kushekbaev::stdf(last_member) << "\n";
}