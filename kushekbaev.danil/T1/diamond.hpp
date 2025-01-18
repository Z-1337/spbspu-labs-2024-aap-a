#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "shape.hpp"
#include "parallelogram.hpp"

namespace kushekbaev
{
  class Diamond final: public Shape
  {
  public:
    Diamond(const point_t middle, const point_t diffX, const point_t diffY);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t scalePoint) override;
    void move(const double dx, const double dy) override;
    void scale(const double scaleCoeff) override;

  private:
    Parallelogram parallelogram_;
  };
}

#endif
