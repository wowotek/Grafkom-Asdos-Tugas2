#include <iostream>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "render.hpp"

#define WIDTH  480
#define HEIGHT 480
#define FRAME_RATE 120/1000

void init(void)
{
    glMatrixMode(GL_MODELVIEW);
    // Canvas -----
    glutDisplayFunc(renderDisplay);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    // ------------

    glutTimerFunc(10, updateScreen, 10);
    gluOrtho2D(0, WIDTH, HEIGHT, 0);
}

int main(int argc, char * argv[])
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_MULTISAMPLE);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(2220, 200);
    glutCreateWindow("Grafkom-Asdos-Tugas2");

    init();
    
    glutMainLoop();
}

