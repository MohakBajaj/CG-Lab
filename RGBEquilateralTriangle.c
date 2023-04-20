#include <GL/gl.h>
#include <GL/freeglut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    // equilateral triangle
    // rainbow color
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(0.0, 0.0);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(0.5, 0.866);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(1.0, 0.0);
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("RGB Equilateral Triangle");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}