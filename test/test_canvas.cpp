#ifdef STAND_ALONE
#   define BOOST_TEST_MODULE DemoTests
#endif

#include <boost/test/unit_test.hpp>
#include <shared/Color.h>
#include <shared/Canvas.h>
#include <iostream>

BOOST_AUTO_TEST_SUITE(canvas_suite)

    BOOST_AUTO_TEST_CASE(creating_a_canvas_test) {
        auto c = Canvas(10, 20);

        BOOST_CHECK_EQUAL(c.width, 10);
        BOOST_CHECK_EQUAL(c.height, 20);
        for (Color pixel: c.getPixels()) {
            BOOST_TEST(pixel.equals(Color(0, 0, 0)));
        }
    }

    BOOST_AUTO_TEST_CASE(writing_pixels_to_a_canvas_test) {
        auto c = Canvas(10, 20);
        auto red = Color(1, 0, 0);

        c.writePixel(2, 3, red);

        BOOST_TEST(c.pixelAt(2, 3).equals(red));

    }

    BOOST_AUTO_TEST_CASE(constructing_the_ppm_header_test) {
        auto c = Canvas(5, 3);

        std::string ppm =
                "P3\n"
                "5 3\n"
                "255\n";

        BOOST_CHECK_EQUAL(ppm, c.toPPM());

    }

    BOOST_AUTO_TEST_CASE(constructing_the_ppm_pixel_data_test) {
        auto c = Canvas(5, 3);

        auto c1 = Color(1.5,0,0);
        auto c2 = Color(0,0.5,0);
        auto c3 = Color(-0.5,0,1);

        c.writePixel(0,0,c1);
        c.writePixel(2,1,c2);
        c.writePixel(4,2,c3);

        std::string ppm =
                "255 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n"
                "0 0 0 0 0 0 0 128 0 0 0 0 0 0 0\n"
                "0 0 0 0 0 0 0 0 0 0 0 0 0 0 255\n";

        BOOST_CHECK_EQUAL(ppm, c.data());

    }

BOOST_AUTO_TEST_SUITE_END()

