#ifndef RAY_TRACER_CHALLENGE_OUTPUT_H
#define RAY_TRACER_CHALLENGE_OUTPUT_H

#include <ostream>
#include "Translation.h"
#include "Point.h"
#include "Color.h"

extern std::ostream& operator << (std::ostream& os, const Translation t);
extern std::ostream& operator << (std::ostream& os, const Tuple t);
extern std::ostream& operator << (std::ostream& os, const Point p);
extern std::ostream& operator << (std::ostream& os, const Vector v);
extern std::ostream& operator << (std::ostream& os, const Matrix m);
extern std::ostream& operator << (std::ostream& os, const Color c);

#endif //RAY_TRACER_CHALLENGE_OUTPUT_H