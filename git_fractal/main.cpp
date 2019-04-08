#include <iostream>
#include <glut.h>
#include <time.h>
#include <random>
#include <vector>
using namespace std;

typedef std::vector<float> vec;
typedef std::vector<int> vec32;

void Display() {
	glClear(GL_COLOR_BUFFER_BIT);
	srand(time(0));
	/*int middle_x = 680;
	int middle_y = 360;
	int raduis = (int)(0.1*middle_y);
	float x = 1.0;
	float y = 1.0;
	for (int i = 0; i < 15000; i++) {
		float p = (rand()%RAND_MAX)/(double)(RAND_MAX);
		float t = x;
		if (p <= 0.85) {
			x = 0.84*x - 0.045*y;
			y = 0.045*t + 0.86*y + 1.6;
		}
		else if (p < 0.92) {
			x = 0.25*x - 0.26*y;
			y = 0.23*t + 0.25*y + 1.6;
		}
		else if (p < 0.99) {
			x = -0.135*x + 0.28*y;
			y = 0.26*t + 0.245*y + 0.44;

		}
		else {
			x = 0.0;
			y = 0.16*y;
		}
		glColor3f(255.0, 0.0, 0.0);
		glBegin(GL_POINTS);
		glVertex2f(middle_x + floor(61*x)+1, middle_y - (floor(40*y) + 1));
		glEnd();
	}*/

	vec axisX, axisY;


	int x_new = 250;
	int y_new = 170;

	int number = 0;
	int number1 = 0;
	int x1 = 5;
	int y1 = 10;
	int x2 = 100;
	int y2 = 160;
	int x3 = 300;
	int y3 = 20;


	glColor3f(255.0f, 246.0, 0.0f);
	glPointSize(3);
	glBegin(GL_POINTS);
	glVertex2f(x1, y1);
	glEnd();
	glColor3f(255.0f, 0.0f, 0.0f);
	glPointSize(3);
	glBegin(GL_POINTS);
	glVertex2f(x2, y2);
	glEnd();
	glColor3f(0.0f, 255.0f, 0.0f);
	glPointSize(3);
	glBegin(GL_POINTS);
	glVertex2f(x3, y3);
	glEnd();




	glPointSize(1.3);
	for (int i = 0; i < 100000; i++) {
		int random = rand() % 6 + 1;

		if (random == 1 || random == 2) {

			if (x1 < x_new) {
				x_new = ((x_new - x1) / 2) + x1;
			}
			else {
				x_new = ((x1 - x_new) / 2) + x_new;
			}
			if (y1 < y_new)
			{
				y_new = ((y_new - y1) / 2) + y1;
			}
			else {
				y_new = ((y1 - y_new) / 2) + y_new;
			}

			glColor3f(255, 0, 0);
			glBegin(GL_POINTS);
			glVertex2f(x_new, y_new);
			glEnd();
			axisX.push_back(x_new);
			axisY.push_back(y_new);
			//Sleep(10);
		}

		if (random == 3 || random == 4) {
			if (x2 < x_new)
			{
				x_new = ((x_new - x2) / 2) + x2;
			}
			else {
				x_new = ((x2 - x_new) / 2) + x_new;
			}

			if (y2 < y_new) {
				y_new = ((y_new - y2) / 2) + y2;
			}
			else {
				y_new = ((y2 - y_new) / 2) + y_new;
			}

			glColor3f(0, 255, 0);
			glBegin(GL_POINTS);
			glVertex2f(x_new, y_new);
			glEnd();
			axisX.push_back(x_new);
			axisY.push_back(y_new);
			//Sleep(10);
		}

		if (random == 5 || random == 6) {
			if (x3 < x_new) {
				x_new = ((x_new - x3) / 2) + x3;
			}
			else {
				x_new = ((x3 - x_new) / 2) + x_new;
			}

			if (y3 < y_new) {
				y_new = ((y_new - y3) / 2) + y3;
			}
			else {
				y_new = ((y3 - y_new) / 2) + y_new;
			}

			glColor3f(255.0f, 246.0, 0.0f);
			glBegin(GL_POINTS);
			glVertex2f(x_new, y_new);
			glEnd();
			axisX.push_back(x_new);
			axisY.push_back(y_new);
			//Sleep(10);
		}

	}
	glFlush();
}

void Initialize() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-300.0, 300.0, -300.0, 300.0, -5.0, 5.0);
}

int main(int argc, char ** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1280, 720);
	glutInitWindowPosition(100, 200);
	glutCreateWindow("Our first GLUT application!");
	glutDisplayFunc(Display);
	Initialize();
	glutMainLoop();
	return 0;
}