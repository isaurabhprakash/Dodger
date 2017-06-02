#include<GL/glut.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
#define startScreen 2
using namespace std;
int WIDTH = 600;
int HEIGHT = 600;
int gamestate=startScreen;

void reshape(int w, int h)
{
	HEIGHT=h;
	WIDTH=w;
	glViewport(0,0,w,h);
	double asp=(float)w/(float)h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
		glOrtho(0,500,0,500,-10,10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glutPostRedisplay();

}
void startScreenDisplay()
{

	char text0[]="DODGER\n";
	char text1[]="Press 1 to Play\n";
	char text2[]="Press 2 for Instructions\n";
	char dev[]="Developed by\n";
	char name1[]="Saurabh Prakash : 1MV14CS093\n";
	char name2[]="Sudarshan Kumar: 1MV14CS109\n";
	char cgl[]="For Computer Graphics";
	char cgl1[]="AND";
	char cgl2[]="Visualisation Laboratory Project";
    glColor3f(1,1,1);

	glRasterPos2f(170,320);
	int i;
	for(i=0;i<sizeof(text1);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,text1[i]);
	glRasterPos2f(170,300);
	for(i=0;i<sizeof(text2);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,text2[i]);
	glRasterPos2f(210,400);
	for(i=0;i<sizeof(text0);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,text0[i]);
	glRasterPos2f(200,240);
		for(i=0;i<sizeof(dev);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,dev[i]);
	glRasterPos2f(130,210);
		for(i=0;i<sizeof(name1);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,name1[i]);
	glRasterPos2f(130,180);
		for(i=0;i<sizeof(name2);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,name2[i]);
    glRasterPos2f(155,110);
		for(i=0;i<sizeof(cgl);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,cgl[i]);
    glRasterPos2f(218,90);
		for(i=0;i<sizeof(cgl1);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,cgl1[i]);
     glRasterPos2f(125,70);
		for(i=0;i<sizeof(cgl2);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,cgl2[i]);

	glFlush();
	glutPostRedisplay();
	glutSwapBuffers();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	switch(gamestate)
	{

		case startScreen: startScreenDisplay();
		break;
	}


}
void myinit()
{
	int i;
	int inc=10;
    glClearColor(20/255.0,20/255.0,20/255.0,1);
}


int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(400,0);
	glutCreateWindow("Star Rage");
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);

	glutSetCursor(GLUT_CURSOR_NONE);
	glEnable(GL_TEXTURE_2D);
	myinit();
	glutMainLoop();
}


