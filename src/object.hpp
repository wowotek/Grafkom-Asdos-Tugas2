#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "shape.hpp"

class Object{
    private:
        float posx, posy;
        
        float sizex, sizey;
        bool bigger;

        float color[3];
        int colorIncrement;
        bool colorIncrementing;

        float scale, rotation;
    
        bool squeezing;
    public:
        Object(float, float, float, float, unsigned char, unsigned char, unsigned char);
        void render(void);
        void update(void);

};

#endif