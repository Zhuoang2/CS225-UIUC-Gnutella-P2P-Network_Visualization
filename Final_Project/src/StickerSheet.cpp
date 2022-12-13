#include "StickerSheet.h"
#include <algorithm>
StickerSheet::StickerSheet(const Image &picture, unsigned max){
    _max = max;
    _base = Image(picture);
    // for (unsigned w = 0; w < picture.width(); w++)
    //     for (unsigned h = 0; h < picture.height(); h++) {
    //         _base.getPixel(w,h).a = picture.getPixel(w,h).a;
    //         _base.getPixel(w,h).h = picture.getPixel(w,h).h;
    //         _base.getPixel(w,h).s = picture.getPixel(w,h).s;
    //         _base.getPixel(w,h).l = picture.getPixel(w,h).l;
    //     }
}
StickerSheet::~StickerSheet (){
    if(_images.empty()) return;
    for (size_t i = 0; i < _images.size(); i++) {
       delete _images[i];
    }
    _images.clear();
}

StickerSheet::StickerSheet (const StickerSheet &other):_max(other._max){
    _base = Image(other._base);
    //_base = Image(other._base.width(),other._base.height());
    // for (unsigned w = 0; w < other._base.width(); w++)
    //     for (unsigned h = 0; h < other._base.height(); h++) {
    //         _base.getPixel(w,h).a = other._base.getPixel(w,h).a;
    //         _base.getPixel(w,h).h = other._base.getPixel(w,h).h;
    //         _base.getPixel(w,h).s = other._base.getPixel(w,h).s;
    //         _base.getPixel(w,h).l = other._base.getPixel(w,h).l;
    //     }
    
    for (size_t i = 0; i < other._images.size(); i++) {
        Image *topush = new Image(*other._images[i]);
        //Image *topush = new Image(other._images[i]->width(), other._images[i]->height());
        topush->setlocation(other._images[i]->get_x(),other._images[i]->get_y());
        // for (unsigned w = 0; w < other._images[i]->width(); w++)
        //     for (unsigned h = 0; h < other._images[i]->height(); h++) {
        //         topush->getPixel(w,h).a = other._images[i]->getPixel(w,h).a;
        //         topush->getPixel(w,h).h = other._images[i]->getPixel(w,h).h;
        //         topush->getPixel(w,h).s = other._images[i]->getPixel(w,h).s;
        //         topush->getPixel(w,h).l = other._images[i]->getPixel(w,h).l;
        //     }
        _images.push_back(topush);
    }

}

const StickerSheet & StickerSheet::operator= (const StickerSheet &other) {
    if (this==&other) return *this;
    //this->~StickerSheet();
    _max = other._max;
    _base = Image(other._base);
    //_base = Image(other._base.width(),other._base.height());
    // for (unsigned w = 0; w < other._base.width(); w++)
    //     for (unsigned h = 0; h < other._base.height(); h++) {
    //         _base.getPixel(w,h).a = other._base.getPixel(w,h).a;
    //         _base.getPixel(w,h).h = other._base.getPixel(w,h).h;
    //         _base.getPixel(w,h).s = other._base.getPixel(w,h).s;
    //         _base.getPixel(w,h).l = other._base.getPixel(w,h).l;
    //     }
    for (size_t i = 0; i < other._images.size(); i++) {
        Image *topush = new Image (*other._images[i]);
        //Image *topush = new Image(other._images[i]->width(), other._images[i]->height());
        topush->setlocation(other._images[i]->get_x(),other._images[i]->get_y());
        // for (unsigned w = 0; w < other._images[i]->width(); w++)
        //     for (unsigned h = 0; h < other._images[i]->height(); h++) {
        //         topush->getPixel(w,h).a = other._images[i]->getPixel(w,h).a;
        //         topush->getPixel(w,h).h = other._images[i]->getPixel(w,h).h;
        //         topush->getPixel(w,h).s = other._images[i]->getPixel(w,h).s;
        //         topush->getPixel(w,h).l = other._images[i]->getPixel(w,h).l;
        //     }
        _images.push_back(topush);
    }
    return *this;
}

void StickerSheet::changeMaxStickers (unsigned max) {
    if (max == 0) {
       for (size_t i = 0; i < _images.size(); i++) {
            delete _images[i];
        }
        _images.clear();
       //std::cout<<"size ="<<_images.size()<<" "<<" _max = "<< _max<<std::endl;
        _max = max;
        return;
    }
    //for (size_t i = 0; i < _images.size(); i++) std::cout<<_images[i]<<std::endl;
    if (_images.size()>max) {
        for (size_t i = _images.size() - 1; i >= max; i--) {
            delete _images[i];
            _images.pop_back();
        }
    }
    _max = max;
    std::cout<<"size ="<<_images.size()<<" "<<" _max = "<< _max<<std::endl;
    
}

int StickerSheet::addSticker (Image &sticker, unsigned x, unsigned y){
    Image *topush = new Image(sticker);
    if (_images.size() >= _max) return -1;
    //Image *topush = new Image(sticker);
    // for (unsigned w = 0; w < sticker.width(); w++)
    //     for (unsigned h = 0; h < sticker.height(); h++) {
    //         topush->getPixel(w,h).a = sticker.getPixel(w,h).a;
    //         topush->getPixel(w,h).h = sticker.getPixel(w,h).h;
    //         topush->getPixel(w,h).s = sticker.getPixel(w,h).s;
    //         topush->getPixel(w,h).l = sticker.getPixel(w,h).l;
    //     }
    _images.push_back(topush);
    //_images.at(_images.size()-1)->setlocation(x,y);
    topush->setlocation(x,y);
    // delete[] topush;
    //std::cout<<_images.size()<< " "<<_max<<std::endl;
    return _images.size()-1;
}

bool StickerSheet::translate (unsigned index, unsigned x, unsigned y) {
    if (index < 0 || index >= _images.size()) return false;
    _images[index]->setlocation(x,y);
    return 0;
}

void StickerSheet::removeSticker (unsigned index) {
    delete _images[index];
    _images.erase(_images.begin()+index);
}
Image * StickerSheet::getSticker (unsigned index) {
    if (index < 0 || index >= _images.size()) return NULL;
    return _images[index];
}

Image StickerSheet::render () const {
    Image toreturn = _base;
   //Image toreturn = Image(_base.width(),_base.height());
    // for (unsigned w = 0; w < _base.width(); w++){
    //     for (unsigned h = 0; h < _base.height(); h++) {
    //         toreturn.getPixel(w,h).a = _base.getPixel(w,h).a;
    //         toreturn.getPixel(w,h).h = _base.getPixel(w,h).h;
    //         toreturn.getPixel(w,h).s = _base.getPixel(w,h).s;
    //         toreturn.getPixel(w,h).l = _base.getPixel(w,h).l;
    //     }
    // }

    for (size_t i = 0; i < _images.size();i++) {
        if (_images[i]->get_x() + _images[i]->width() > toreturn.width()) {
            toreturn.resize(_images[i]->get_x() + _images[i]->width(),toreturn.height());
        }

        if(_images[i]->get_y() + _images[i]->height()> toreturn.height()){
            toreturn.resize(toreturn.width(),_images[i]->get_y()+_images[i]->height());
        }
        //std::cout<<_images[i]<<std::endl;
        for (unsigned w = 0; w < _images[i]->width(); w++){
            for (unsigned h = 0; h <_images[i]->height(); h++) {
                if (_images[i]->getPixel(w,h).a == 0) continue;
                toreturn.getPixel(w+_images[i]->get_x(),h+_images[i]->get_y()).a = _images[i]->getPixel(w,h).a;
                toreturn.getPixel(w+_images[i]->get_x(),h+_images[i]->get_y()).h = _images[i]->getPixel(w,h).h;
                toreturn.getPixel(w+_images[i]->get_x(),h+_images[i]->get_y()).s = _images[i]->getPixel(w,h).s;
                toreturn.getPixel(w+_images[i]->get_x(),h+_images[i]->get_y()).l = _images[i]->getPixel(w,h).l;
            }
        }
    }
    return toreturn;
}