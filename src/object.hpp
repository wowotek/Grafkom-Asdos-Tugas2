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
        float r, g, b;

        float scale, rotation;
    
        bool squeezing;
    public:
        Object(float, float, float, float, float, float, float);
        void render(void);
        void update(void);

};

#endif