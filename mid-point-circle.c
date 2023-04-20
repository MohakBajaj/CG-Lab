// Mid Point Circle Drawing Algorithm

#include <stdio.h>
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

void circleMidpoint(int h, int k, int r)
{
    int x = 0;
    int y = r;
    int p = 1 - r;

    setPixel(x + h, y + k);
    setPixel(-x + h, y + k);
    setPixel(x + h, -y + k);
    setPixel(-x + h, -y + k);

    while (x < y)
    {
        x++;
        if (p < 0)
            p += 2 * x + 1;
        else
        {
            y--;
            p += 2 * (x - y) + 1;
        }
        setPixel(x + h, y + k);
        setPixel(-x + h, y + k);
        setPixel(x + h, -y + k);
        setPixel(-x + h, -y + k);
        setPixel(y + h, x + k);
        setPixel(-y + h, x + k);
        setPixel(y + h, -x + k);
        setPixel(-y + h, -x + k);
    }
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    circleMidpoint(320, 240, 100);
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Mid Point Circle Drawing Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}