#include "render.hpp"
#include "object.hpp"

Object c1(240, 240, 120, 120, 1, 0, 0);

void renderDisplay(void)
{
    glClearColor(1.0f, 1.00f, 1.00f, 1.00f);
    glClear(GL_COLOR_BUFFER_BIT);

    c1.render();

    glutSwapBuffers();
    glutPostRedisplay();
}

void updateScreen(int value)
{
    c1.update();

    glutPostRedisplay();
    glutTimerFunc(value, updateScreen, value);
}