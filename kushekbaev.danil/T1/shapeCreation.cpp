#include "shapeCreation.hpp"
#include <iomanip>
#include "shapeBreeding.hpp"
#include "shapeManipulations.hpp"

namespace kushekbaev
{
  std::string shapeName;
  bool errorexit = false;

  void createShape(std::istream& input, Shape** capacity, size_t& shapeCounter, point_t& scalePoint, double& scaleCoeff)
  {
    while (input >> shapeName)
    {
      if (shapeName == "RECTANGLE")
        {
          try
          {
            capacity[shapeCounter++] = kushekbaev::makeRectangle(input);
          }

          catch (const std::invalid_argument& e)
          {
            throw std::invalid_argument("Some of inputed shapes were incorrectly inputed\n");
          }
        }

        else if (shapeName == "CONCAVE")
        {
          try
          {
            capacity[shapeCounter++] = kushekbaev::makeConcave(input);
          }

          catch (const std::invalid_argument& e)
          {
            throw std::invalid_argument("Some of inputed shapes were incorrectly inputed\n");
          }
        }

        else if (shapeName == "PARALLELOGRAM")
        {
          try
          {
            capacity[shapeCounter++] = kushekbaev::makeParallelogram(input);
          }

          catch (const std::invalid_argument& e)
          {
            throw std::invalid_argument("Some of inputed shapes were incorrectly inputed\n");
          }
        }

        else if (shapeName == "DIAMOND")
        {
          try
          {
            capacity[shapeCounter++] = kushekbaev::makeDiamond(input);
          }

          catch (const std::invalid_argument& e)
          {
            throw std::invalid_argument("Some of inputed shapes were incorrectly inputed\n");
          }
        }

        else if (shapeName == "SCALE")
        {
          scalePoint = kushekbaev::makeScale(input);
          input >> scaleCoeff;
          if (scaleCoeff <= 0)
          {
            throw std::invalid_argument("incorrect scaleCoeff");
            errorexit = true;
            kushekbaev::clearMemory(capacity, shapeCounter);
          }
          break;
        }
    }

    if (shapeCounter == 0)
    {
      std::cerr << "Shapeless input" << "\n";
    }
  }
}
