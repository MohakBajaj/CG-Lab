// Cohen Sutherland Line Clipping Algorithm

#include <stdio.h>
#include <GL/freeglut.h>

#define WIDTH 640
#define HEIGHT 480

int xmin = 100, ymin = 100, xmax = 250, ymax = 250;
int clippedLines[4][4];
int LineCount = 0;

void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 640, 0, 480);
}

void setPixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void drawLine(int x1, int y1, int x2, int y2)
{
    glBegin(GL_LINES);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glEnd();
}

int computeCode(int x, int y)
{
    int code = 0;
    if (y > ymax)
        code |= 8;
    else if (y < ymin)
        code |= 4;
    if (x > xmax)
        code |= 2;
    else if (x < xmin)
        code |= 1;
    return code;
}

void cohenSutherlandLineClip(int x1, int y1, int x2, int y2)
{
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    int accept = 0;
    while (1)
    {
        if (code1 == 0 && code2 == 0)
        {
            accept = 1;
            break;
        }
        else if (code1 & code2)
            break;
        else
        {
            int x, y;
            int codeOut = code1 ? code1 : code2;
            if (codeOut & 8)
            {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            }
            else if (codeOut & 4)
            {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            }
            else if (codeOut & 2)
            {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            }
            else if (codeOut & 1)
            {
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }
            if (codeOut == code1)
            {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }
    if (accept)
    {
        clippedLines[LineCount][0] = x1;
        clippedLines[LineCount][1] = y1;
        clippedLines[LineCount][2] = x2;
        clippedLines[LineCount][3] = y2;
        LineCount++;
        if (LineCount == 4)
            LineCount = 0;
        glColor3f(1.0, 1.0, 1.0);
        drawLine(x1, y1, x2, y2);
        glFlush();
    }
}

void mouse(int btn, int state, int x, int y)
{
    static int x1, y1, x2, y2;
    if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        x1 = x;
        y1 = HEIGHT - y;
    }
    else if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        x2 = x;
        y2 = HEIGHT - y;
        cohenSutherlandLineClip(x1, y1, x2, y2);
    }
}

void drawClippedLines()
{
    int i;
    for (i = 0; i < 4; i++)
        drawLine(clippedLines[i][0], clippedLines[i][1], clippedLines[i][2], clippedLines[i][3]);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    drawLine(xmin, ymin, xmax, ymin);
    drawLine(xmax, ymin, xmax, ymax);
    drawLine(xmax, ymax, xmin, ymax);
    drawLine(xmin, ymax, xmin, ymin);
    drawClippedLines();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Cohen Sutherland Line Clipping Algorithm");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    init();
    glutMainLoop();
    return 0;
}