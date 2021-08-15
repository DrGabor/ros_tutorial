#include "geometry/line_segment.h"

namespace common {
namespace geometry {
double LineSegment::length() const {
  return compute_dist(_beg_pt, _end_pt);
}
} // namespace geometry
} // namespace common