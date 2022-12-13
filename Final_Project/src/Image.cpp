#include "Image.h"
#include <algorithm>
#include <cmath>
void Image::lighten (){
    for (unsigned int w = 0; w < width(); w++)
        for (unsigned int h = 0; h < height(); h++)
            (getPixel(w,h).l <= 0.9) ? (getPixel(w,h).l += 0.1) : getPixel(w,h).l = 1;
}

void Image::lighten (double amount){
    for (unsigned int w = 0; w < width(); w++)
        for (unsigned int h = 0; h < height(); h++)
            (getPixel(w,h).l + amount <= 1) ? (getPixel(w,h).l += amount) : getPixel(w,h).l = 1;
}

void Image::darken (){
    for (unsigned int w = 0; w < width(); w++)
        for (unsigned int h = 0; h < height(); h++)
            (getPixel(w,h).l >= 0.1) ? (getPixel(w,h).l -= 0.1) : getPixel(w,h).l = 0;
}

void Image::darken (double amount){
    for (unsigned int w = 0; w < width(); w++)
        for (unsigned int h = 0; h < height(); h++)
            (getPixel(w,h).l - amount >= 0) ? (getPixel(w,h).l -= amount) : getPixel(w,h).l = 0;
}

void Image::saturate (){
    for (unsigned int w = 0; w < width(); w++)
        for (unsigned int h = 0; h < height(); h++)
            (getPixel(w,h).s <= 0.9) ? (getPixel(w,h).s += 0.1) : getPixel(w,h).s = 1;
}

void Image::saturate (double amount){
    for (unsigned int w = 0; w < width(); w++)
        for (unsigned int h = 0; h < height(); h++)
            (getPixel(w,h).s + amount <= 1) ? (getPixel(w,h).s += amount) : getPixel(w,h).s = 1;
}

void Image::desaturate (){
    for (unsigned int w = 0; w < width(); w++)
        for (unsigned int h = 0; h < height(); h++)
            (getPixel(w,h).s >= 0.1) ? (getPixel(w,h).s -= 0.1) : getPixel(w,h).s = 0;
}

void Image::desaturate (double amount){
    for (unsigned int w = 0; w < width(); w++)
        for (unsigned int h = 0; h < height(); h++)
            (getPixel(w,h).s - amount >= 0) ? (getPixel(w,h).s -= amount) : getPixel(w,h).s = 0;
}

void Image::grayscale (){
    for (unsigned int w = 0; w < width(); w++)
        for (unsigned int h = 0; h < height(); h++)
            getPixel(w,h).s = 0;
}

void Image::rotateColor (double degrees){
    for (unsigned int w = 0; w < width(); w++)
        for (unsigned int h = 0; h < height(); h++){
            getPixel(w,h).h += degrees;
            if (getPixel(w,h).h > 0) while (getPixel(w,h).h > 360) getPixel(w,h).h -= 360;
            else while (getPixel(w,h).h < 0) getPixel(w,h).h += 360;
        }
}

void Image::illinify (){
    for (unsigned int w = 0; w < width(); w++)
        for (unsigned int h = 0; h < height(); h++){
            if(getPixel(w,h).h >= 113.5 && getPixel(w,h).h <= 293.5){
                getPixel(w,h).h = 216;
            } else getPixel(w,h).h = 11;
        }
}

void Image::scale (double factor){
    PNG image = PNG(width(),height());
    for (unsigned int w = 0; w < width(); w++)
        for (unsigned int h = 0; h < height(); h++){
            image.getPixel(w,h).a = getPixel(w,h).a;
            image.getPixel(w,h).l = getPixel(w,h).l;
            image.getPixel(w,h).s = getPixel(w,h).s;
            image.getPixel(w,h).h = getPixel(w,h).h;
        }
    resize(factor * width(), factor * height());
    for (unsigned int w = 0; w < width(); w++)
        for (unsigned int h = 0; h < height(); h++){
            getPixel(w,h).a = image.getPixel(std::floor(w/factor),std::floor(h/factor)).a;
            getPixel(w,h).h = image.getPixel(std::floor(w/factor),std::floor(h/factor)).h;
            getPixel(w,h).l = image.getPixel(std::floor(w/factor),std::floor(h/factor)).l;
            getPixel(w,h).s = image.getPixel(std::floor(w/factor),std::floor(h/factor)).s;
        }
}

void Image::scale (unsigned w, unsigned h){
    double factor = std::min(w*1.0/width(),h*1.0/height());
    scale(factor);
}