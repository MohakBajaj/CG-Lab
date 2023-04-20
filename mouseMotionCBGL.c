#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>

int colors[4][3] = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
int n = 1;
float r, g, b;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glRasterPos2f(-1 * 0.5, 1 * 0.5);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (unsigned char *)("Move Mouse in Window"));
	glFlush();
	glutSwapBuffers();

}

void motion(int x, int y)
{
	char s[10];
	sprintf(s, "(%d, %d)", x, y);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glRasterPos2f(-1 * 0.5, 1 * 0.5);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (unsigned char *)("A Mouse Button is Pressed"));
	glRasterPos2d(-0.1, 0);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (unsigned char *)(s));
	glFlush();
	glutSwapBuffers();
}

void PassiveMotion(int x, int y)
{
	char s[10];
	sprintf(s, "(%d, %d)", x, y);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glRasterPos2f(-1 * 0.5, 1 * 0.5);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (unsigned char *)("Move Mouse in Window"));
	glRasterPos2d(-0.1, 0);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (unsigned char *)(s));
	glFlush();
	glutSwapBuffers();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);

	glutInitWindowPosition(300, 200);
	glutInitWindowSize(500, 500);

	glutCreateWindow("Mouse Motion Callback");

	glutDisplayFunc(display);
	glutMotionFunc(motion);
	glutPassiveMotionFunc(PassiveMotion);

	glutMainLoop();

	return 0;
}
