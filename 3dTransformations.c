// 3D Transformations - Translation, Rotation, Scaling - tetrahedron

#include <GL/freeglut.h>
#include <math.h>

#define WIDTH 1280
#define HEIGHT 720

float x = 100, y = 100, z = 100;
float x2 = 250, y2 = 100, z2 = 100;
float x3 = 250, y3 = 250, z3 = 100;
float x4 = 100, y4 = 250, z4 = 100;
float x5 = 100, y5 = 100, z5 = 250;
char operation;

void drawTetrahedron()
{
    glBegin(GL_LINE_LOOP);
    glVertex3i(x, y, z);
    glVertex3i(x2, y2, z2);
    glVertex3i(x3, y3, z3);
    glVertex3i(x4, y4, z4);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3i(x, y, z);
    glVertex3i(x2, y2, z2);
    glVertex3i(x5, y5, z5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3i(x, y, z);
    glVertex3i(x4, y4, z4);
    glVertex3i(x5, y5, z5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3i(x4, y4, z4);
    glVertex3i(x3, y3, z3);
    glVertex3i(x5, y5, z5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3i(x3, y3, z3);
    glVertex3i(x2, y2, z2);
    glVertex3i(x5, y5, z5);
    glEnd();
}

void translate(int tx, int ty, int tz)
{
    x += tx;
    y += ty;
    z += tz;
    x2 += tx;
    y2 += ty;
    z2 += tz;
    x3 += tx;
    y3 += ty;
    z3 += tz;
    x4 += tx;
    y4 += ty;
    z4 += tz;
    x5 += tx;
    y5 += ty;
    z5 += tz;
}

void inverseTranslate(int tx, int ty, int tz)
{
    x -= tx;
    y -= ty;
    z -= tz;
    x2 -= tx;
    y2 -= ty;
    z2 -= tz;
    x3 -= tx;
    y3 -= ty;
    z3 -= tz;
    x4 -= tx;
    y4 -= ty;
    z4 -= tz;
    x5 -= tx;
    y5 -= ty;
    z5 -= tz;
}

void rotateX(float angle)
{
    angle = angle * 3.14 / 180;
    int tempX = x, tempY = y, tempZ = z;
    inverseTranslate(tempX, tempY, tempZ);
    y = tempY * cos(angle) - tempZ * sin(angle);
    z = tempY * sin(angle) + tempZ * cos(angle);
    translate(tempX, tempY, tempZ);
    tempX = x2, tempY = y2, tempZ = z2;
    inverseTranslate(tempX, tempY, tempZ);
    y2 = tempY * cos(angle) - tempZ * sin(angle);
    z2 = tempY * sin(angle) + tempZ * cos(angle);
    translate(tempX, tempY, tempZ);
    tempX = x3, tempY = y3, tempZ = z3;
    inverseTranslate(tempX, tempY, tempZ);
    y3 = tempY * cos(angle) - tempZ * sin(angle);
    z3 = tempY * sin(angle) + tempZ * cos(angle);
    translate(tempX, tempY, tempZ);
    tempX = x4, tempY = y4, tempZ = z4;
    inverseTranslate(tempX, tempY, tempZ);
    y4 = tempY * cos(angle) - tempZ * sin(angle);
    z4 = tempY * sin(angle) + tempZ * cos(angle);
    translate(tempX, tempY, tempZ);
    tempX = x5, tempY = y5, tempZ = z5;
    inverseTranslate(tempX, tempY, tempZ);
    y5 = tempY * cos(angle) - tempZ * sin(angle);
    z5 = tempY * sin(angle) + tempZ * cos(angle);
    translate(tempX, tempY, tempZ);
}

void rotateY(float angle)
{
    angle = angle * 3.14 / 180;
    int tempX = x, tempY = y, tempZ = z;
    inverseTranslate(tempX, tempY, tempZ);
    x = tempX * cos(angle) + tempZ * sin(angle);
    z = -tempX * sin(angle) + tempZ * cos(angle);
    translate(tempX, tempY, tempZ);
    tempX = x2, tempY = y2, tempZ = z2;
    inverseTranslate(tempX, tempY, tempZ);
    x2 = tempX * cos(angle) + tempZ * sin(angle);
    z2 = -tempX * sin(angle) + tempZ * cos(angle);
    translate(tempX, tempY, tempZ);
    tempX = x3, tempY = y3, tempZ = z3;
    inverseTranslate(tempX, tempY, tempZ);
    x3 = tempX * cos(angle) + tempZ * sin(angle);
    z3 = -tempX * sin(angle) + tempZ * cos(angle);
    translate(tempX, tempY, tempZ);
    tempX = x4, tempY = y4, tempZ = z4;
    inverseTranslate(tempX, tempY, tempZ);
    x4 = tempX * cos(angle) + tempZ * sin(angle);
    z4 = -tempX * sin(angle) + tempZ * cos(angle);
    translate(tempX, tempY, tempZ);
    tempX = x5, tempY = y5, tempZ = z5;
    inverseTranslate(tempX, tempY, tempZ);
    x5 = tempX * cos(angle) + tempZ * sin(angle);
    z5 = -tempX * sin(angle) + tempZ * cos(angle);
    translate(tempX, tempY, tempZ);
}

void rotateZ(float angle)
{
    angle = angle * 3.14 / 180;
    int tempX = x, tempY = y, tempZ = z;
    inverseTranslate(tempX, tempY, tempZ);
    x = tempX * cos(angle) - tempY * sin(angle);
    y = tempX * sin(angle) + tempY * cos(angle);
    translate(tempX, tempY, tempZ);
    tempX = x2, tempY = y2, tempZ = z2;
    inverseTranslate(tempX, tempY, tempZ);
    x2 = tempX * cos(angle) - tempY * sin(angle);
    y2 = tempX * sin(angle) + tempY * cos(angle);
    translate(tempX, tempY, tempZ);
    tempX = x3, tempY = y3, tempZ = z3;
    inverseTranslate(tempX, tempY, tempZ);
    x3 = tempX * cos(angle) - tempY * sin(angle);
    y3 = tempX * sin(angle) + tempY * cos(angle);
    translate(tempX, tempY, tempZ);
    tempX = x4, tempY = y4, tempZ = z4;
    inverseTranslate(tempX, tempY, tempZ);
    x4 = tempX * cos(angle) - tempY * sin(angle);
    y4 = tempX * sin(angle) + tempY * cos(angle);
    translate(tempX, tempY, tempZ);
    tempX = x5, tempY = y5, tempZ = z5;
    inverseTranslate(tempX, tempY, tempZ);
    x5 = tempX * cos(angle) - tempY * sin(angle);
    y5 = tempX * sin(angle) + tempY * cos(angle);
    translate(tempX, tempY, tempZ);
}

void inverseRotateX(float angle)
{
    rotateX(-angle);
}
void inverseRotateY(float angle)
{
    rotateY(-angle);
}
void inverseRotateZ(float angle)
{
    rotateZ(-angle);
}

void scale(int sx, int sy, int sz)
{
    int tempX = x, tempY = y, tempZ = z;
    inverseTranslate(tempX, tempY, tempZ);
    x = tempX * sx;
    y = tempY * sy;
    z = tempZ * sz;
    translate(tempX, tempY, tempZ);
    tempX = x2, tempY = y2, tempZ = z2;
    inverseTranslate(tempX, tempY, tempZ);
    x2 = tempX * sx;
    y2 = tempY * sy;
    z2 = tempZ * sz;
    translate(tempX, tempY, tempZ);
    tempX = x3, tempY = y3, tempZ = z3;
    inverseTranslate(tempX, tempY, tempZ);
    x3 = tempX * sx;
    y3 = tempY * sy;
    z3 = tempZ * sz;
    translate(tempX, tempY, tempZ);
    tempX = x4, tempY = y4, tempZ = z4;
    inverseTranslate(tempX, tempY, tempZ);
    x4 = tempX * sx;
    y4 = tempY * sy;
    z4 = tempZ * sz;
    translate(tempX, tempY, tempZ);
    tempX = x5, tempY = y5, tempZ = z5;
    inverseTranslate(tempX, tempY, tempZ);
    x5 = tempX * sx;
    y5 = tempY * sy;
    z5 = tempZ * sz;
    translate(tempX, tempY, tempZ);
}

void inverseScale(int sx, int sy, int sz)
{
    scale(1 / sx, 1 / sy, 1 / sz);
}

void reset()
{
    x = 100, y = 100, z = 100;
    x2 = 250, y2 = 100, z2 = 100;
    x3 = 250, y3 = 250, z3 = 100;
    x4 = 100, y4 = 250, z4 = 100;
    x5 = 100, y5 = 100, z5 = 250;
}

void keyboard(unsigned char key, int x, int y)
{
    operation = key;
    switch (key)
    {
    case 'x':
        rotateX(10);
        break;
    case 'X':
        inverseRotateX(10);
        break;
    case 'y':
        rotateY(10);
        break;
    case 'Y':
        inverseRotateY(10);
        break;
    case 'z':
        rotateZ(10);
        break;
    case 'Z':
        inverseRotateZ(10);
        break;
    case 's':
        scale(1.1, 1.1, 1.1);
        break;
    case 'S':
        inverseScale(1.1, 1.1, 1.1);
        break;
    case 't':
        translate(10, 10, 10);
        break;
    case 'T':
        inverseTranslate(10, 10, 10);
        break;
    case 'r':
        reset();
        break;
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    drawTetrahedron();
    glFlush();
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // glOrtho(-500, 500, -500, 500, -500, 500);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluPerspective(60, WIDTH / HEIGHT, 1, 1000);
    gluLookAt(250, 250, 500, 0, 0, 0, 0, 1, 0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("3D Transformations");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}