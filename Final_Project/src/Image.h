/**
 * @file Image.h
 * Contains your declaration of the interface for the Image class.
 */

#pragma once
#include <iostream>
#include "cs225/PNG.h"
#include <cmath>
class Image : public cs225::PNG {
    public:
        //Image() = default;
        //Image(unsigned int w, unsigned int h):cs225::PNG(w,h){};
        // Image(const Image& other):cs225::PNG(other){};
        void lighten ();
        void lighten (double amount);
        void darken ();
        void darken (double amount);
        void saturate ();
        void saturate (double amount);
        void desaturate ();
        void desaturate (double amount);
        void grayscale ();
        void rotateColor (double degrees);
        void illinify ();
        void scale (double factor);
        void scale (unsigned w, unsigned h);
        void setlocation(unsigned x, unsigned y){
            _x = x;
            _y = y;
        };
        unsigned get_x(){return _x;};
        unsigned get_y(){return _y;};
        // graph representation:
        void addline(std::pair<unsigned, unsigned> src, std::pair<unsigned, unsigned> des) {
            //x1 <= x2, y1 <= y2
            des.first -= 10;
            if (src.first <= des.first && src.second <= des.second) {
                unsigned n = 1;
                for (unsigned x = src.first; x < des.first; x++) {
                    unsigned y = std::round(src.second + n * 1.0 * abs(int(des.second) - int(src.second))/ abs(int(des.first) - int(src.first)));
                    getPixel(x,y) = cs225::HSLAPixel(360,1,1,0.6);
                    n++;
                }
            }
            //x1 <= x2, y1 >= y2
            else if (src.first <= des.first && des.second <= src.second) {
                unsigned n = 1;
                for (unsigned x = src.first; x < des.first; x++) {
                    unsigned y = std::round(src.second - n * 1.0 *abs(int(des.second) - int(src.second))/ abs(int(des.first) - int(src.first)));
                    getPixel(x,y) = cs225::HSLAPixel(360,1,1,0.6);
                    n++;
                }
            }
            //x1 >= x2, y1 <= y2
            else if (src.first >= des.first && src.second <= des.second) {
                unsigned n = 1;
                for (unsigned x = src.first; x > des.first; x--) {
                    unsigned y = std::round(src.second + n * 1.0 *abs(int(des.second) - int(src.second))/ abs(int(des.first) - int(src.first)));
                    getPixel(x,y) = cs225::HSLAPixel(360,1,1,0.6);
                    n++;
                }
            } 
            //x1 >x2 , y1>y2
            else {
                unsigned n = 1;
                for (unsigned x = src.first; x > des.first; x--) {
                    unsigned y = std::round(src.second - n * 1.0 *abs(int(des.second) - int(src.second))/ abs(int(des.first) - int(src.first)));
                    getPixel(x,y) = cs225::HSLAPixel(360,1,1,0.6);
                    n++;
                }
            }
        };


    private:
        unsigned _x = 0;
        unsigned _y = 0;
};