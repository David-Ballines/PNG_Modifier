#include <string>
#include <cmath>
#include "Image.h"
#include "iostream"
#include "PNG_reader/PNG.h"
#include "PNG_reader/HSLAPixel.h"

using namespace std;
using namespace im;

//rotate image clockwise 90 degrees
void Image::rotateClockwise(){
	unsigned width = this->width();
	unsigned height = this->height();
	PNG * hold = new PNG(height,width);
    for(unsigned x = 0; x < width; x++){
		for(unsigned y = 0; y < height; y++){
			HSLAPixel & pix = this->getPixel(x,y);
			hold->getPixel(height - y - 1, x) = pix;
		}
	}

	this->resize(height,width);
	for(unsigned x = 0; x < height; x++){
		for(unsigned y = 0; y < width; y++){
			this->getPixel(x,y) = hold->getPixel(x,y);
		}
	}
	delete hold;
}

void Image::rotateCounterClock(){
	unsigned width = this->width();
	unsigned height = this->height();
	PNG * hold = new PNG(height,width);
    for(unsigned x = 0; x < width; x++){
		for(unsigned y = 0; y < height; y++){
			HSLAPixel & pix = this->getPixel(x,y);
			hold->getPixel(y, width - x - 1) = pix;
		}
	}

	this->resize(height,width);
	for(unsigned x = 0; x < height; x++){
		for(unsigned y = 0; y < width; y++){
			this->getPixel(x,y) = hold->getPixel(x,y);
		}
	}
	delete hold;
}

void Image::rotate180(){
	unsigned width = this->width();
	unsigned height = this->height();
	PNG * hold = new PNG(width,height);
    for(unsigned x = 0; x < width; x++){
		for(unsigned y = 0; y < height; y++){
			HSLAPixel & pix = this->getPixel(x,y);
			hold->getPixel(width - x - 1, height - y - 1) = pix;
		}
	}

	for(unsigned x = 0; x < width; x++){
		for(unsigned y = 0; y < height; y++){
			this->getPixel(x,y) = hold->getPixel(x,y);
		}
	}
	delete hold;
}

void Image::reflectHorizontal(){
	unsigned width = this->width();
	unsigned height = this->height();
	for(unsigned x = 0; x < width/2; x++){
		for(unsigned y = 0; y < height; y++){
			HSLAPixel hold = this->getPixel(x,y);
			this->getPixel(x,y) = this->getPixel(width - x - 1,y);
			this->getPixel(width - 1 - x,y) = hold; 
		}
	}
}

void Image::reflectVertical(){
	unsigned width = this->width();
	unsigned height = this->height();
	for(unsigned x = 0; x < width; x++){
		for(unsigned y = 0; y < height/2; y++){
			HSLAPixel hold = this->getPixel(x,y);
			this->getPixel(x,y) = this->getPixel(x, height - 1 - y);
			this->getPixel(x,height - 1 - y) = hold; 
		}
	}
}

void Image::lighten(double amount){
    for(unsigned int x = 0; x < this->width(); x++){
        for(unsigned int y = 0; y < this->height(); y++){
            HSLAPixel & pix = this->getPixel(x,y);
            if((pix.l + amount) >= .9){
                pix.l = 1.0;
            }
            else{
                pix.l += amount;
            }
        }
    }
}

void Image::darken(double amount){
    for(unsigned int x = 0; x < this->width(); x++){
        for(unsigned int y = 0; y < this->height(); y++){
            HSLAPixel & pix = this->getPixel(x,y);
            if((pix.l - amount) <= .1){
                pix.l = 0;
            }
            else{
                pix.l -= amount;
            }
        }
    }
}

void Image::saturate(double amount) {
	for (unsigned int x = 0; x < this->width(); x++) {
		for (unsigned int y = 0; y < this->height(); y++) {
			HSLAPixel &pix = this->getPixel(x, y);
			if ((pix.s + amount) >= 1.0) {
				pix.s = 1.0;
			}
			else {
				pix.s += amount;
			}
		}
	}
}

void Image::desaturate(double amount) {
	for (unsigned int x = 0; x < this->width(); x++) {
		for (unsigned int y = 0; y < this->height(); y++) {
			HSLAPixel &pix = this->getPixel(x, y);
			if ((pix.s - amount) <= 0) {
				pix.s = 0;
			}
			else {
				pix.s -= amount;
			}
		}
	}
}

void Image::grayscale() {
	for (unsigned int x = 0; x < this->width(); x++) {
		for (unsigned int y = 0; y < this->height(); y++) {
			HSLAPixel &pix = this->getPixel(x, y);
			pix.s = 0;
		}
	}
}

void Image::rotateColor(double degrees) {
	double hold;

	for (unsigned int x = 0; x < this->width(); x++) {
		for (unsigned int y = 0; y < this->height(); y++) {
			HSLAPixel &pix = this->getPixel(x, y);
			hold = pix.h + degrees;
			if (hold < 0) {
				pix.h = 360 + hold;
			}
			else if (hold > 360) {
				pix.h = hold - 360;
			}
			else {
				pix.h = hold;
			}
		}
	}
}

void Image::scale(double factor){
	if(factor == 1){
		return;
	}

	unsigned int width = this->width();
	unsigned int height = this->height();

	unsigned int nwidth = width * factor;
	unsigned int nheight = height * factor;
	PNG * hold = new PNG(width,height);

	for(unsigned int x = 0; x < width; x++){
		for(unsigned int y = 0; y < height; y++){
			hold->getPixel(x,y) = this->getPixel(x,y);
		}
	}

	this->resize(nwidth,nheight);

	if(factor > 1){
		for(unsigned int x = 0; x < width; x++){
			for(unsigned int y = 0; y < height; y++){
				for(unsigned int i = 0; i < factor; i++){
					for(unsigned int j = 0; j < factor; j++){
						this->getPixel(x*factor + i, y*factor + j) = hold->getPixel(x,y);
					}
				}
			}
		}
	}
	else{

		for(unsigned int x = 0; x < nwidth; x++){
			for(unsigned int y = 0; y < nheight; y++){
				this->getPixel(x,y) = hold->getPixel((int) (x/factor),(int) (y/factor));
			}
		}
	}
	delete hold;

}