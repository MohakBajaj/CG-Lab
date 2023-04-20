#include <GL/glut.h>
void displayMe(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	glColor3f(0, 1, 0);
	glVertex2f(-0.7, -0.7);
	glVertex2f(0.7, -0.7);
	glVertex2f(0, 0.7);
	glEnd();
	glFlush();
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Equilateral Triangle");
	glutDisplayFunc(displayMe);
	glutMainLoop();
	return 0;
}
