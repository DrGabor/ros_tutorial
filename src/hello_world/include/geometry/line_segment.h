#pragma once
#include "common.h"

namespace common {
namespace geometry {

class LineSegment {
public:
  LineSegment() {}
  virtual ~LineSegment() {}

  bool init() { return true; }
  double length() const;
  // getters
  const SPointXYZ &getBeg() const { return _beg_pt; }
  const SPointXYZ &getEnd() const { return _end_pt; }
  // setters
  void setBeg(const SPointXYZ &pt) { _beg_pt = pt; }
  void setEnd(const SPointXYZ &pt) { _end_pt = pt; }

private:
  SPointXYZ _beg_pt;
  SPointXYZ _end_pt;
};

} // namespace geometry
} // namespace common