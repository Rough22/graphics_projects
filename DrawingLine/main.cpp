#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

float x1, x2, y1, y2;

void direct_equation(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    float dx, dy, m, c, _count, increment;

    dx = x2 - x1;
    dy = y2 - y1;
    m = dy/dx;
    c = y1 - (m * x1);

    if(abs(dy) < abs(dx))
        _count = abs(dy) * 100;
    else
        _count = abs(dx) * 100;

    increment = abs(dx) / _count;

    for(float x = x1; x <= x2; x += increment)
    {
        float y = (m * x) + c;
        glBegin(GL_POINTS);
        glVertex2f(x, y);
        glEnd();

    }
    glFlush();
    glutSwapBuffers();
}

void dda(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    float dx, dy, _count, incrementx, incrementy, x, y;

    dx = x2 - x1;
    dy = y2 - y1;

    if(abs(dy) > abs(dx))
        _count = abs(dy) * 100;
    else
        _count = abs(dx) * 100;

    incrementx = dx / _count;
    incrementy = dy / _count;

    x = x1;
    y = y1;

    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
    glFlush();


    for(float i = 1; i <= _count; i++)
    {
        x += incrementx;
        y += incrementy;

        glBegin(GL_POINTS);
        glVertex2f(x, y);
        glEnd();

    }
    glFlush();
    glutSwapBuffers();
}

void bresenham_algo(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    float dx, dy, x, y, di;

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);


    glBegin(GL_POINTS);
    glVertex2f(x1, y1);
    glEnd();
    glFlush();

    if(dx > dy) // when m is less than 1
    {
        x = x1;
        y = y1;
        di = (2 * dy) - dx;

        for(int i = 0; i < dx; i++)
        {
            if(di >= 0)
            {
                di = di + 2 * (dy - dx);

                if(y1 > y2)
                    y--;
                else
                    y++;
            }
            else
                di = di + (2 * dy);
            x++;

            glBegin(GL_POINTS);
            glVertex2f(x, y);
            glEnd();

        }
        glFlush();
        glutSwapBuffers();
    }
    else // when m is greater than 1
    {
        di = (2 * dx) - dy;

        for(int i = 0; i < dy; i++)
        {
            if(y1 > y2)
                y--;
            else
                y++;

            if(di >= 0)
            {
                x++;
                di = di + 2 * (dx - dy);
            }
            else
                di = di + (2 * dx);



            glBegin(GL_POINTS);
            glVertex2f(x, y);
            glEnd();

        }
        glFlush();
        glutSwapBuffers();
    }

}

int main(int argc, char *argv[])
{
    cout << "Enter X1: ";
    cin >> x1;
    cout << "Enter Y1: ";
    cin >> y1;
    cout << "Enter X2: ";
    cin >> x2;
    cout << "Enter Y2: ";
    cin >> y2;

    if(x1 > x2)
    {
        swap(x1, x2);
        swap(y1, y2);
    }

    cout << "Choose anyone :" <<endl;
    cout << "1 for Direct Equation" << endl;
    cout << "2 for DDA" << endl;
    cout << "3 for Bresenham Algo" << endl;

    int n;
    cout << "Your Choice: ";
    cin >> n;

    glutInit(&argc, argv);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(150,150);
    glutInitDisplayMode(GLUT_RGBA|GLUT_SINGLE);
    glutCreateWindow("Direct Equation Algorithm");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500, 500, -500, 500);

    if(n == 1)
        glutDisplayFunc(direct_equation);
    else if(n == 2)
        glutDisplayFunc(dda);
    else
        glutDisplayFunc(bresenham_algo);


    glutMainLoop();

    return 0;
}
