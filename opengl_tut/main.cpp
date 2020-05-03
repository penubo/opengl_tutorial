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
    
    
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.5, 0.4, 0.3);
    glBegin(GL_LINE_STRIP);
    
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(-1.0, 1.0, 0.0);
    
//    glVertex3f(-1.0, 1.0, 0.0);
    glVertex3f(-1.0, -1.0, 0.0);
    
//    glVertex3f(-1.0, -1.0, 0.0);
    glVertex3f(1.0, -1.0, 0.0);
    
//    glVertex3f(1.0, -1.0, 0.0);
    glVertex3f(1.0, 1.0, 0.0);

    
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
    glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
    glutDisplayFunc(MyDisplay);
    glutMainLoop();
    return 0;
}
