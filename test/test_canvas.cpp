#ifdef STAND_ALONE
#   define BOOST_TEST_MODULE DemoTests
#endif

#include <boost/test/unit_test.hpp>
#include <shared/Color.h>
#include <shared/Canvas.h>
#include <iostream>
#include <shared/Point.h>
#include <shared/Projectile.h>
#include <shared/Environment.h>
#include <shared/World.h>
#include <fstream>

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

        BOOST_CHECK_EQUAL(ppm, c.header());

    }

    BOOST_AUTO_TEST_CASE(constructing_the_ppm_pixel_data_test) {
        auto c = Canvas(5, 3);

        auto c1 = Color(1.5, 0, 0);
        auto c2 = Color(0, 0.5, 0);
        auto c3 = Color(-0.5, 0, 1);

        c.writePixel(0, 0, c1);
        c.writePixel(2, 1, c2);
        c.writePixel(4, 2, c3);

        std::string ppm =
                "255 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n"
                "0 0 0 0 0 0 0 128 0 0 0 0 0 0 0\n"
                "0 0 0 0 0 0 0 0 0 0 0 0 0 0 255\n";

        BOOST_CHECK_EQUAL(ppm, c.pixelData());

    }

    BOOST_AUTO_TEST_CASE(splitting_long_lines_in_ppm_files_test) {
        auto c = Canvas(10, 2, Color(1, 0.8, 0.6));

        std::string ppm =
                "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204\n"
                "153 255 204 153 255 204 153 255 204 153 255 204 153\n"
                "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204\n"
                "153 255 204 153 255 204 153 255 204 153 255 204 153\n";


        std::cout << c.pixelData() << std::endl;
        std::cout << "--------------------" << std::endl;
        std::cout << c.pixelData().length() << std::endl;
        std::cout << ppm.length() << std::endl;
        std::cout << "--------------------" << std::endl;
        std::cout << ppm << std::endl;
        std::cout << "--------------------" << std::endl;
        BOOST_CHECK_EQUAL(ppm, c.pixelData());

    }

    BOOST_AUTO_TEST_CASE(projectile_test) {
        auto c = Canvas(900, 550);

        auto projectile = Projectile(Point(0, 1, 0), Vector(1, 1.8, 0).normalize().multiply(11.25));
        auto e = Environment(Vector(0, -0.1, 0), Vector(-0.01, 0, 0));
        auto w = World();

        int step = 0;
        const Color &white = Color(255, 255, 0);

        while (projectile.position.y > 0 && step++ < 200) {
            std::cout << "step " << step << "x " << projectile.position.x << " y  " << projectile.position.y << " z "
                      << projectile.position.z << std::endl;

            c.writePixel(projectile.position.x, c.height - projectile.position.y, white);
            projectile = w.tick(e, projectile);
        }

        c.toFile("projectile.ppm");

        BOOST_TEST(projectile.position.y <= 0);
    }

BOOST_AUTO_TEST_SUITE_END()

