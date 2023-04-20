#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>

int colors[4][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {1, 1, 1}};
int n = 1;
float r = 1, g = 1, b = 1;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glRasterPos2f(-1 * 0.8, 1 * 0.8);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (unsigned char *)("Press Any Mouse Button"));

	glBegin(GL_TRIANGLES);
	glColor3f(r, g, b);
	glVertex2f(-0.7, -0.7);
	glVertex2f(0.7, -0.7);
	glVertex2f(0, 0.7);
	glEnd();

	glColor3f(1.0, 0.0, 1.0);
	glRasterPos2f(-0.145, -0.15);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (unsigned char *)("Mohak Bajaj"));

	glFlush();
}

void mouse(int button, int state, int x, int y)
{

	if (state == GLUT_DOWN)
	{
		int k = n % 4;
		r = colors[k][0];
		g = colors[k][1];
		b = colors[k][2];
		n += 1;
		if (n > 10)
		{
			n = 0;
		}
	}

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glRasterPos2f(-1 * 0.8, 1 * 0.8);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (unsigned char *)("Press Any Mouse Button"));

	glBegin(GL_TRIANGLES);
	glColor3f(r, g, b);
	glVertex2f(-0.7, -0.7);
	glVertex2f(0.7, -0.7);
	glVertex2f(0, 0.7);
	glEnd();

	glColor3f(1.0, 0.0, 1.0);
	glRasterPos2f(-0.145, -0.15);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (unsigned char *)("Mohak Bajaj"));

	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);

	glutInitWindowPosition(300, 200);
	glutInitWindowSize(500, 500);

	glutCreateWindow("Mouse Callback");

	glutDisplayFunc(display);
	glutMouseFunc(mouse);

	glutMainLoop();

	return 0;
}
