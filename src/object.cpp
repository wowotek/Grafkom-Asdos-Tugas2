#include "object.hpp"

Object::Object( float initPosX, float initPosY,
                float initSizeX, float initSizeY,
                float initR, float initG, float initB)
{
    posx = initPosX;
    posy = initPosY;

    sizex = initSizeX;
    sizey = initSizeY;

    r = initR;
    g = initG;
    b = initB;

    scale = 0.1f;
    rotation = 0.0f;

    squeezing = true;
}

void Object::render(void)
{
    glPushMatrix();
    glTranslated(posx, posy, 0);
    glScalef(scale, scale, 1.0f);

    glColor3f(r, g, b);
    poly(0, 0, sizex, sizey, 3, rotation, GL_TRIANGLE_FAN);

    glPopMatrix();
}

void Object::update(void)
{
    scale += 0.000001f;
    rotation += 0.00001f;
    std::cout   << "scale : " << scale << " | "
                << "rotation : " << rotation << "\r";
}