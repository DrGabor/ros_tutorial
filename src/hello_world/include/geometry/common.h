#pragma once
#include <cmath>
#include <cstdio>
namespace common {
namespace geometry {
struct SPointXYZ {
  double x;
  double y;
  double z;
  SPointXYZ(double xx = 0.0, double yy = 0.0, double zz = 0.0)
      : x(xx), y(yy), z(yy) {}
};

double compute_dist(const SPointXYZ &pt0, const SPointXYZ &pt1);

} // namespace geometry
} // namespace common