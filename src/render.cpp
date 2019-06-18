#include "render.hpp"
#include "object.hpp"

Object c1(240, 240, 240, 240, 0, 0, 254);

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

// 672016135
// TUGAS3_GRAFKOM_G_672017282_1