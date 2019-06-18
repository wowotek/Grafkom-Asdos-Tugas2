#include "object.hpp"

Object::Object( float initPosX, float initPosY,
                float initSizeX, float initSizeY,
                unsigned char initR, unsigned char initG, unsigned char initB)
{
    posx = initPosX;
    posy = initPosY;

    sizex = initSizeX;
    sizey = initSizeY;
    bigger = true;

    color[0] = initR;
    color[1] = initG;
    color[2] = initB;
    colorIncrement = 0;
    colorIncrementing = true;


    scale = 0.0f;
    rotation = 0.0f;

    squeezing = true;
}

void Object::render(void)
{
    glPushMatrix();
    glTranslated(posx, posy, 0);
    glScalef(scale, scale, 1.0f);
    
    glRotatef(rotation, 0, 0, 1);
    glColor3ub(color[0], color[1], color[2]);
    poly(0, 0, sizex, sizey, 3, 0.5, GL_TRIANGLE_FAN);
    poly(0, 0, sizex, sizey, 3, 1.5, GL_TRIANGLE_FAN);


    glPopMatrix();
}

void Object::update(void)
{
    rotation += 1.0f;
    if(rotation >= 360){
        rotation = 0;
    }

    if(bigger)  scale += 0.001f;
    else        scale -= 0.001f;

    if(scale >= 1.5f){
        bigger = false;
    } else if (scale < 0.0f){
        bigger = true;
    }
    if(squeezing)   sizex -= 17.5f;
    else            sizex += 17.5f;

    if(sizex >= sizey)  squeezing = true;
    else if(sizex <= 0) squeezing = false;

    if(colorIncrementing) color[colorIncrement] += 5.0f;
    else color[colorIncrement] -= 5.0f;

    if(color[0] >= 255 && color[1] >= 255 && color[2] >= 255){
        colorIncrementing = false;
    } else if(color[0] <= 0 && color[1] <= 0 && color[2] <= 0){
        colorIncrementing = true;
    } else if(color[colorIncrement] <= 0){
        color[colorIncrement] = 0;
        colorIncrement--;
    } else if(color[colorIncrement] >= 255){
        color[colorIncrement] = 255;
        colorIncrement++;
    }

    if(colorIncrement > 2){
        colorIncrement = 0;
    }


    std::cout   << "scale : " << scale << " | rotation : " << rotation << " | "
                << "colorcmp : " << color[0] << " "
                                    << color[1] << " "
                                    << color[2] << "| "
                << "color : " << colorIncrement << "           \r";
    fflush(stdout);
}