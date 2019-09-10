#include <GL/glut.h>
#include <cmath>
#include <iostream>

using namespace std;

double center_x, center_y, radius, theta;

void trigonometric()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    double x = 0, y = 0;

    glBegin(GL_POINTS);

    for(theta = 90; theta >= 45; theta -= .0001)
    {
        x = radius * cos(theta);
        y = radius * sin(theta);

        glVertex2f(center_x + x, center_y + y);
        glVertex2f(center_x + x, center_y - y);
        glVertex2f(center_x - x, center_y + y);
        glVertex2f(center_x - x, center_y - y);
        glVertex2f(center_x + y, center_y + x);
        glVertex2f(center_x + y, center_y - x);
        glVertex2f(center_x - y, center_y + x);
        glVertex2f(center_x - y, center_y - x);
    }
    glEnd();
    glFlush();
}

void polynomial()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    double x = 0, y = radius;

    glBegin(GL_POINTS);

    for(x = 0.01; x <= (radius / sqrt(2)); x += 0.001)
    {
        glVertex2f(center_x + x, center_y + y);
        glVertex2f(center_x + x, center_y - y);
        glVertex2f(center_x - x, center_y + y);
        glVertex2f(center_x - x, center_y - y);
        glVertex2f(center_x + y, center_y + x);
        glVertex2f(center_x + y, center_y - x);
        glVertex2f(center_x - y, center_y + x);
        glVertex2f(center_x - y, center_y - x);

        y = sqrt(radius*radius - x*x);
    }
    glEnd();
    glFlush();
}

void midpoint()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    int x = 0, y = radius, mid = 1 - radius;

    glBegin(GL_POINTS);

    while(x <= y)
    {
        glVertex2i(center_x + x, center_y + y);
        glVertex2i(center_x + x, center_y - y);
        glVertex2i(center_x - x, center_y + y);
        glVertex2i(center_x - x, center_y - y);
        glVertex2i(center_x + y, center_y + x);
        glVertex2i(center_x + y, center_y - x);
        glVertex2i(center_x - y, center_y + x);
        glVertex2i(center_x - y, center_y - x);

        if(mid < 0)
            mid = mid + (2 * x) + 3;
        else
        {
            mid = mid + 2 * (x - y) + 5;
            y--;
        }
        x++;
    }
    glEnd();
    glFlush();
}

void bresenham()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    int x = 0, y = radius, d = 3 - (2 * radius);

    glBegin(GL_POINTS);

    while(x <= y)
    {
        glVertex2i(center_x+x, center_y+y);
        glVertex2i(center_x+x, center_y-y);
        glVertex2i(center_x-x, center_y+y);
        glVertex2i(center_x-x, center_y-y);
        glVertex2i(center_x+y, center_y+x);
        glVertex2i(center_x+y, center_y-x);
        glVertex2i(center_x-y, center_y+x);
        glVertex2i(center_x-y, center_y-x);

        if(d < 0)
            d = d + (4 * x) + 6;
        else
        {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
    glEnd();
    glFlush();
}

int main(int argc, char *argv[]) {

    cout << "Center of the circle:" << endl;
    cin >> center_x >> center_y;
    cout << "Radius of the circle:" << endl;
    cin >> radius;

    cout << "Choose the method:" << endl;
    cout << "1 for Trigonometric" << endl;
    cout << "2 for Polynomial" << endl;
    cout << "3 for Midpoint" << endl;
    cout << "4 for Bresenham" << endl;

    int n;
    cout << "Your Choice: ";
    cin >> n;

    glutInit(&argc, argv);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(150,150);
    glutInitDisplayMode(GLUT_RGBA|GLUT_SINGLE);
    glutCreateWindow("Circle Drawing Algorithm");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500, 500, -500, 500);

    if(n == 1)
        glutDisplayFunc(trigonometric);
    else if(n == 2)
        glutDisplayFunc(polynomial);
    else if(n == 3)
        glutDisplayFunc(midpoint);
    else
        glutDisplayFunc(bresenham);

    glutMainLoop();

    return 0;
}