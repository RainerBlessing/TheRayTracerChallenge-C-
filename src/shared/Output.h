#ifndef CMAKE_BOOST_DEMO_OUTPUT_H
#define CMAKE_BOOST_DEMO_OUTPUT_H

#include <ostream>
#include "Translation.h"
#include "Point.h"

extern std::ostream& operator << (std::ostream& os, const Translation t);
extern std::ostream& operator << (std::ostream& os, const Tuple t);
extern std::ostream& operator << (std::ostream& os, const Point p);
extern std::ostream& operator << (std::ostream& os, const Vector v);

#endif //CMAKE_BOOST_DEMO_OUTPUT_H