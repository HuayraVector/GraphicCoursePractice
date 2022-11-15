#include<GL/glut.h>
#include<iostream>
//void divide_triangle(GLfloat *a, GLfloat *b, GLfloat *c, int m);
void triangle(GLfloat *a, GLfloat *b, GLfloat *c);
//void draw_tetrahedra(int m);
void display();
double wH = 500, wW = 500;
GLfloat transX = 0, transY = 0, transZ = 0;
GLfloat RotX = 0, RotY = 0, RotZ = 0, angle = 0;

/* initial triangle */
GLfloat v[3][2] = { { -1.0, -0.58 },
{ 1.0, -0.58 },{ 0.0, 1.15 } };
int n = 1; /* number of recursive steps */

static GLfloat color[4][3] = { { 0.0, 0.0, 0.0 },//Black
{ 0.0, 1.0, 0.0 },//Green
{ 1.0, 0.0, 0.0 },//Red
{ 0.0, 0.0, 1.0 } };//Blue

int RGBchoice[4] = { 0,1,2,3 };

void triangle(GLfloat *a, GLfloat *b, GLfloat *c)
{
	GLfloat ambient[] = { 0.8, 0.5, 0.5, 0.6 };
	GLfloat diffuse[] = { 1, 1, 1, 1 };
	GLfloat specular[] = { 0.7, 0.6, 0.6, 0.5 };
	GLfloat shine = 50.0;
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialf(GL_FRONT, GL_SHININESS, shine);
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
}
void myReshape(int w, int h)
{

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-4.0, 4.0, -4.0 * (GLfloat)h / (GLfloat)w, 4.0 * (GLfloat)h / (GLfloat)w, -4.0, 4.0);
	else
		glOrtho(-4.0 * (GLfloat)w / (GLfloat)h, 4.0 * (GLfloat)w / (GLfloat)h, -4.0, 4.0, -4.0, 4.0);
	glMatrixMode(GL_MODELVIEW);
}
void myinit() {
	GLfloat lightP_position[] = { 0.0, 1.5, 2.5, 0.0 };
	GLfloat lightP_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat lightP_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat lightP_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, lightP_position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightP_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightP_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightP_specular);
	glEnable(GL_LIGHT0);

	GLfloat lightPR_position[] = { 0.0, 1.5, 2.5, 0.0 };
	GLfloat lightPR_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat lightPR_diffuse[] = { 1.0, 0.5, 0.5, 1.0 };
	GLfloat lightPR_specular[] = { 1.0, 0.5, 0.5, 1.0 };
	glLightfv(GL_LIGHT1, GL_POSITION, lightPR_position);
	glLightfv(GL_LIGHT1, GL_AMBIENT, lightPR_ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightPR_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, lightPR_specular);

	GLfloat lightPG_position[] = { 0.0, 1.5, 2.5, 0.0 };
	GLfloat lightPG_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat lightPG_diffuse[] = { 0.5, 1.0, 0.5, 1.0 };
	GLfloat lightPG_specular[] = { 0.5, 1.0, 0.5, 1.0 };
	glLightfv(GL_LIGHT2, GL_POSITION, lightPG_position);
	glLightfv(GL_LIGHT2, GL_AMBIENT, lightPG_ambient);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, lightPG_diffuse);
	glLightfv(GL_LIGHT2, GL_SPECULAR, lightPG_specular);

	GLfloat lightPB_position[] = { 0.0, 1.5, 2.5, 0.0 };
	GLfloat lightPB_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat lightPB_diffuse[] = { 0.0, 0.5, 1.0, 1.0 };
	GLfloat lightPB_specular[] = { 0.0, 0.5, 1.0, 1.0 };
	glLightfv(GL_LIGHT3, GL_POSITION, lightPB_position);
	glLightfv(GL_LIGHT3, GL_AMBIENT, lightPB_ambient);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, lightPB_diffuse);
	glLightfv(GL_LIGHT3, GL_SPECULAR, lightPB_specular);

	GLfloat lightM_position[] = { -3.0, -6.0, -15.0, 0.0 };
	GLfloat lightM_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat lightM_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat lightM_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	glLightfv(GL_LIGHT4, GL_POSITION, lightM_position);
	glLightfv(GL_LIGHT4, GL_AMBIENT, lightM_ambient);
	glLightfv(GL_LIGHT4, GL_DIFFUSE, lightM_diffuse);
	glLightfv(GL_LIGHT4, GL_SPECULAR, lightM_specular);
	glLightf(GL_LIGHT4, GL_CONSTANT_ATTENUATION, 0.5);
	glEnable(GL_LIGHT4);
	glEnable(GL_LIGHTING);

	glClearColor(0.3, 0.3, 0.3, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-4.0, 4.0, -4.0, 4.0, -4.0, 4.0);
	glMatrixMode(GL_MODELVIEW);

}

void timerProc(int id){
	glutTimerFunc(33, timerProc, 0);//需要在函数中再调用一次，才能保证循环


	if (RotX != 0 || RotY != 0 || RotZ != 0)
	{
		display();
		glRotatef(10, RotX, RotY, RotZ);
	}

}

void key(unsigned char key, int x, int y)             //按鍵反應
{

	if (key == '+')
	{
		glTranslatef(transX, transY, transZ);
		display();
	}
	else if (key == '-')
	{
		glTranslatef(-transX, -transY, -transZ);
		display();
	}
}

void processMenuEvents(int option)      //main menu
{
	int lightPMenuOn;
	switch (option)
	{
		int lightPMenuOn;
	case 1:
		n = 1;
		break;
	case 2:
		n = 2;
		break;
	case 3:
		n = 3;
		break;
	case 4:
		n = 4;
		break;
	case 5:
		n = 5;
		break;
	case 6:
		glDisable(GL_LIGHT0);
		glDisable(GL_LIGHT2);
		glDisable(GL_LIGHT3);
		glEnable(GL_LIGHT1);
		break;
	case 7:
		glDisable(GL_LIGHT0);
		glDisable(GL_LIGHT1);
		glDisable(GL_LIGHT3);
		glEnable(GL_LIGHT2);
		break;
	case 8:
		glDisable(GL_LIGHT0);
		glDisable(GL_LIGHT1);
		glDisable(GL_LIGHT2);
		glEnable(GL_LIGHT3);
		break;
	case 9:
		glDisable(GL_LIGHT1);
		glDisable(GL_LIGHT2);
		glDisable(GL_LIGHT3);
		glEnable(GL_LIGHT0);
		break;
	case 10:
		exit(1);


	case 14:
		RotX = 0; RotY = 0; RotZ = 0;

		break;
	case 15:
		transX = 0.25;
		transY = 0;
		transZ = 0;

		break;
	case 16:
		transY = 0.25;
		transX = 0;
		transZ = 0;

		break;
	case 17:
		transZ = 0.25;
		transY = 0;
		transX = 0;

		break;
	case 18:
		transX = 0;
		transY = 0;
		transZ = 0;
		break;
	case 21:
		glDisable(GL_LIGHT0);
		glDisable(GL_LIGHT1);
		glDisable(GL_LIGHT2);
		glDisable(GL_LIGHT3);
		break;
	case 22:
		glEnable(GL_LIGHT4);
		break;
	case 23:
		glDisable(GL_LIGHT4);
		break;
	case 24:
		RotX = 1;

		break;
	case 25:
		RotX = 0;

		break;

	case 26:
		RotY = 1;

		break;
	case 27:
		RotY = 0;

		break;
	case 28:
		RotZ = 1;

		break;
	case 29:
		RotZ = 0;

		break;


	}
	display();
}


void createGLUTMenus()
{
	int menu, subMenu, lightPMenuOn, lightPMenu, RotationX, RotationY, RotationZ, Translation, lightMMenu;

	subMenu = glutCreateMenu(processMenuEvents);
	glutAddMenuEntry("1", 1);
	glutAddMenuEntry("2", 2);
	glutAddMenuEntry("3", 3);
	glutAddMenuEntry("4", 4);
	glutAddMenuEntry("5", 5);

	lightPMenuOn = glutCreateMenu(processMenuEvents);
	glutAddMenuEntry(" R ", 6);
	glutAddMenuEntry(" G ", 7);
	glutAddMenuEntry(" B ", 8);
	glutAddMenuEntry(" W ", 9);

	lightPMenu = glutCreateMenu(processMenuEvents);
	glutAddSubMenu("ON", lightPMenuOn);
	glutAddMenuEntry("OFF", 21);

	lightMMenu = glutCreateMenu(processMenuEvents);
	glutAddMenuEntry("ON", 22);
	glutAddMenuEntry("OFF", 23);

	RotationX = glutCreateMenu(processMenuEvents);
	glutAddMenuEntry("ON", 24);
	glutAddMenuEntry("OFF", 25);

	RotationY = glutCreateMenu(processMenuEvents);
	glutAddMenuEntry("ON", 26);
	glutAddMenuEntry("OFF", 27);

	RotationZ = glutCreateMenu(processMenuEvents);
	glutAddMenuEntry("ON", 28);
	glutAddMenuEntry("OFF", 29);



	Translation = glutCreateMenu(processMenuEvents);
	glutAddMenuEntry(" X ", 15);
	glutAddMenuEntry(" Y ", 16);
	glutAddMenuEntry(" Z ", 17);
	glutAddMenuEntry("Release", 18);

	menu = glutCreateMenu(processMenuEvents);
	glutAddSubMenu("Subdivision", subMenu);
	glutAddSubMenu("Light P", lightPMenu);
	glutAddSubMenu("Light M", lightMMenu);
	glutAddSubMenu("RotationX", RotationX);
	glutAddSubMenu("RotationY", RotationY);
	glutAddSubMenu("RotationZ", RotationZ);
	glutAddSubMenu("Translation", Translation);
	glutAddMenuEntry("Exit", 10);

	glutAttachMenu(GLUT_RIGHT_BUTTON);


}



int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(wW, wH);
	glutCreateWindow("3D Gasket");
	glutDisplayFunc(display);
	glutReshapeFunc(myReshape);
	glEnable(GL_DEPTH_TEST);
	glutTimerFunc(33, timerProc, 0);
	glutKeyboardFunc(key);

	createGLUTMenus();

	myinit();
	glutMainLoop();

}
void divide_triangle(GLfloat *a, GLfloat *b, GLfloat *c, GLfloat *d)
{
	triangle(a, b, c);
	triangle(a, b, d);
	triangle(a, d, c);
	triangle(b, c, d);
}

void draw_tetrahedra(GLfloat *a, GLfloat *b, GLfloat *c, GLfloat *d, int k) {
	int j;
	GLfloat ab[3], bc[3], ac[3], ad[3], bd[3], cd[3];

	if (k > 0) {
		for (j = 0; j < 3; j++) ab[j] = (a[j] + b[j]) / 2.0;
		for (j = 0; j < 3; j++) bc[j] = (b[j] + c[j]) / 2.0;
		for (j = 0; j < 3; j++) ac[j] = (a[j] + c[j]) / 2.0;
		for (j = 0; j < 3; j++) ad[j] = (a[j] + d[j]) / 2.0;
		for (j = 0; j < 3; j++) bd[j] = (b[j] + d[j]) / 2.0;
		for (j = 0; j < 3; j++) cd[j] = (c[j] + d[j]) / 2.0;

		draw_tetrahedra(a, ab, ac, ad, k - 1);
		draw_tetrahedra(ab, b, bc, bd, k - 1);
		draw_tetrahedra(ac, bc, c, cd, k - 1);
		draw_tetrahedra(ad, bd, cd, d, k - 1);
	}
	else
		divide_triangle(a, b, c, d);
}

void display()
{
	GLfloat a[3] = { 0.0, 0.0, 4.0 },
		b[3] = { -2.3,1.7, 0.0 },
		c[3] = { 2.3, 1.7, 0.0 },
		d[3] = { 0.0, -2.3, 0.0 };

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	draw_tetrahedra(a, b, c, d, n);
	glEnd();
	glFlush();
}