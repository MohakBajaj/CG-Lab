// Polar Coordinate Circle Drawing Algorithm

#include <stdio.h>
#include <math.h>
#include <GL/freeglut.h>

#define WIDTH 640
#define HEIGHT 480

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
}

void setPixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void circlePolar(int h, int k, int r)
{
    int x, y;
    float theta;
    for (theta = 0; theta <= 360; theta += 0.01)
    {
        x = r * cos(theta) + h;
        y = r * sin(theta) + k;
        setPixel(x, y);
    }
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    circlePolar(320, 240, 100);
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Polar Coordinate Circle Drawing Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}