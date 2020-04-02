#pragma once

#include <string>
#include <iostream>
#include <cmath>
#include "225/PNG.h"
#include "225/HSLAPixel.h"

using namespace std;
using namespace im;


class Image : public PNG{
public:
    void rotateClockwise();

	void rotateCounterClock();

    void rotate180();

	void reflectHorizontal();

	void reflectVertical();

	void lighten(double amount);

	void darken(double amount);

	void saturate(double amount);

	void desaturate(double amount);

	void grayscale();

	void rotateColor(double degrees);

	void scale(double factor);
};