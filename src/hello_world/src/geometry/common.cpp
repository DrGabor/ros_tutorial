#include "geometry/common.h"

namespace common {
namespace geometry {
double compute_dist(const SPointXYZ &pt0, const SPointXYZ &pt1) {
  double length = 0.0;
  length += pow(pt0.x - pt1.x, 2);
  length += pow(pt0.y - pt1.y, 2);
  length += pow(pt0.z - pt1.z, 2);
  length = sqrt(length);
  return length;
}
} // namespace geometry
} // namespace common