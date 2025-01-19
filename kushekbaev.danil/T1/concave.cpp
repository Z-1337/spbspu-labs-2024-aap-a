#include "concave.hpp"
#include <stdexcept>
#include <array>
#include "base-types.hpp"
#include "shapeBreeding.hpp"

namespace kushekbaev
{
  Concave::Concave(point_t first, point_t second, point_t third, point_t last):
    points_{first, second, third, last}
  {
    if (!isTriangle(first, second, third) || !isPointInsideTriangle(first, second, third, last))
    {
      throw std::invalid_argument("Incorrect concave\n");
    }
  }

  double Concave::getArea() const
  {
    double standart = getAreaOfTriangle(first_, second_, third_);
    double concavity = getAreaOfTriangle(second_, third_, last_);
    return standart - concavity;
  }

  rectangle_t Concave::getFrameRect() const
  {
    double lowerLeftx = std::min(std::min(std::min(first_.x, second_.x), third_.x), last_.x);
    double lowerLefty = std::min(std::min(std::min(first_.y, second_.y), third_.y), last_.y);
    double upperRightx = std::max(std::max(std::max(first_.x, second_.x), third_.x), last_.x);
    double upperRighty = std::max(std::max(std::max(first_.y, second_.y), third_.y), last_.y);

    point_t lowerLeft { lowerLeftx, lowerLefty };
    point_t upperRight { upperRightx, upperRighty };

    double width = upperRight.x - lowerLeft.x;
    double height = upperRight.y - lowerLeft.y;
    point_t middle;
    middle.x = lowerLeft.x + width / 2;
    middle.y = lowerLeft.y + height / 2;
    return { width, height, middle };
  }

  void Concave::move(point_t scalePoint)
  {
    point_t middle = getFrameRect().pos;
    double dx = scalePoint.x - middle.x;
    double dy = scalePoint.y - middle.y;

    move(dx, dy);
  }

  void Concave::move(double dx, double dy)
  {
    std::array<point_t*, 4> points = { &first_, &second_, &third_, &last_ };

    for (point_t* point: points)
    {
      point->x += dx;
      point->y += dy;
    }
  }

  void Concave::scale(double scaleCoeff)
  {
    if (scaleCoeff <= 0)
    {
      throw std::out_of_range("Scale coefficient should be greater than zero\n");
    }
    point_t middle = getFrameRect().pos;
    std::array<point_t*, 4> points = { &first_, &second_, &third_, &last_ };

    for (point_t* point: points)
    {
      point->x = middle.x + (point->x - middle.x) * scaleCoeff;
      point->y = middle.y + (point->y - middle.y) * scaleCoeff;
    }
  }
}
