#ifndef RAY_TRACER_CHALLENGE_OUTPUT_H
#define RAY_TRACER_CHALLENGE_OUTPUT_H

#include <ostream>
#include "Translation.h"
#include "Point.h"
#include "Color.h"
#include "Object.h"
#include "Sphere.h"
#include "Intersection.h"

extern std::ostream& operator << (std::ostream& os, const Translation t);
extern std::ostream& operator << (std::ostream& os, const Tuple t);
extern std::ostream& operator << (std::ostream& os, const Point p);
extern std::ostream& operator << (std::ostream& os, const Vector v);
extern std::ostream& operator << (std::ostream& os, const Matrix m);
extern std::ostream& operator << (std::ostream& os, const Color c);
extern std::ostream& operator << (std::ostream& os, const Object o);
extern std::ostream& operator << (std::ostream& os, const Sphere s);
extern std::ostream& operator << (std::ostream& os, const Intersection i);

#endif //RAY_TRACER_CHALLENGE_OUTPUT_H