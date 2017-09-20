#ifndef MEDIA_H_INCLUDED
#define MEDIA_H_INCLUDED

#include "Shapes.h"

using namespace std;

class MediaVisitor;

class Media {

public:

    virtual double area() const = 0;
    virtual double perimeter () const = 0;
   
    virtual void accept(MediaVisitor * mv) = 0;

};
class ShapeMedia : public Media {

private:
    Shape * shape;

public:
    ShapeMedia(Shape * sh):shape(sh){}

    Shape * getShape();

    double area() const;

    double perimeter() const;

    

};
class ComboMedia : public Media {
private:
    vector<Media *> medias;
public:
    ComboMedia();

    ComboMedia(vector<Media *> & mds): medias(mds){}

    void add(Media * ma);

    void removeMedia(Media * ma);

    vector<Media *> getMedias();

    double area() const;

    double perimeter() const;

  
};
class TextMedia : public Media {
private:
    Rectangle boundingBox;

    string text;
public:
    TextMedia(Rectangle boundingBox, string text):boundingBox(boundingBox), text(text){}

    string getText();

    double area() const;

    double perimeter() const;

};
#endif // MEDIA_H_INCLUDED
