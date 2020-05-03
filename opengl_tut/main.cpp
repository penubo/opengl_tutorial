//
//  main.cpp
//  opengl_tut
//
//  Created by YongJoon Kim on 2020/04/30.
//  Copyright © 2020 YongJoon Kim. All rights reserved.
//


#ifdef __APPLE__
#   define GL_SILENCE_DEPRECATION
#   include <OpenGL/gl.h>
#   include <OpenGL/glu.h>
#   include <GLUT/glut.h>
#elif _WIN32
#   include <windows.h>
#   include <GL/glut.h>
#   include <GL/glu.h>
#   include <GL/gl.h>
#endif

#include <iostream>
#include <math.h>

void MyDisplay() {
    const double Pi  =3.141592653589793238463;
    GLfloat Size[2], Angle;
    
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glGetFloatv(GL_POINT_SIZE_RANGE, Size);
    glPointSize(Size[0] * 5);
    glBegin(GL_POINTS);
        for (Angle = 0.0; Angle <= 2.0 * Pi; Angle += Pi/3000.0)
            glVertex3f(0.5*cos(Angle), 0.5*sin(Angle), 0.0);
    glEnd();
    glutSwapBuffers();

    glFlush();

}

int main(int argc, char * argv[]) {
    // insert code here...
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("GLUT Sample");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glutDisplayFunc(MyDisplay);
    glutMainLoop();
    return 0;
}
