#include<GL/freeglut.h>

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	glRasterPos2f(-1*0.8,1*0.8);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (unsigned char*)("Press R-Red, G-Green B-Blue Text"));
	
	
	glBegin(GL_TRIANGLES);
		glColor3f(1.0,0.0,1.0);
		glVertex2f(-0.7, -0.7);
		glVertex2f(0.7, -0.7);
		glVertex2f(0, 0.7);
	glEnd();
		
	glColor3f(0.0,0.0,0.0);
	glRasterPos2f(-0.145,-0.15);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (unsigned char*)("Mohak Bajaj"));
	
	glFlush();
}

void key(unsigned char key, int x, int y){

	glClear(GL_COLOR_BUFFER_BIT);
	
	glBegin(GL_TRIANGLES);
		glColor3f(1.0,0.0,1.0);
		glVertex2f(-0.7, -0.7);
		glVertex2f(0.7, -0.7);
		glVertex2f(0, 0.7);
	glEnd();
	
	if(key == 'r'){	
		glColor3f(1.0,0.0,0.0);
	}
	else if(key == 'g'){
		glColor3f(0.0,1.0,0.0);
	}
	else if(key == 'b'){	
		glColor3f(0.0,0.0,1.0);
	}
	else{
		glColor3f(1.0,1.0,1.0);
	}
	glRasterPos2f(-1*0.8,1*0.8);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (unsigned char*)("Press R-Red, G-Green B-Blue Text"));
	glRasterPos2f(-0.145,-0.15);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (unsigned char*)("Mohak"));
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	
	glutInitWindowPosition(300,200);
	glutInitWindowSize(500,500);
	
	glutCreateWindow("Trianglewithname");
	
	glutDisplayFunc(display);
	glutKeyboardFunc(key);
	
	glutMainLoop();
	
	return 0;
}
