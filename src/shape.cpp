#include "shape.hpp"

void poly(float x, float y, float x_size, float y_size, float sides, float rotation, unsigned int SHAPE_MODE)
{
    GLfloat angleIncrement = (360.0f / sides) * M_PI / 180.0f;
    glBegin(SHAPE_MODE);
        glPushMatrix();
        GLfloat angle = 0.0f;
        for (size_t _k = 0; _k < sides; ++_k) {
            glVertex2f(x + (x_size * cos(angle + (M_PI * rotation))), y + (y_size * sin(angle + (M_PI * rotation))));
            angle += angleIncrement;
        }
        glPopMatrix();
    glEnd();
}

void circle(float x, float y, float x_size, float y_size){
    poly(x, y, x_size, y_size, 720.0, 10, GL_TRIANGLE_FAN);
}