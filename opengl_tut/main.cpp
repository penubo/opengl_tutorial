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

GLubyte rasters[24] = {
    0xc0, 0x00,
    0xc0, 0x00,
    0xc0, 0x00,
    0xc0, 0x00,
    0xc0, 0x00,
    0xff, 0x00,
    0xff, 0x00,
    0xc0, 0x00,
    0xc0, 0x00,
    0xc0, 0x00,
    0xff, 0xc0,
    0xff, 0xc0};


void MyDisplay() {
    

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.5, 0.4, 0.3);


//    glRasterPos2i (100, 100);
    glRasterPos2i(0, 0);
    glBitmap (0, 6, 0.0, 0.0, 11.0, 0.0, rasters);
    glBitmap (1, 6, 0.0, 0.0, 11.0, 0.0, rasters);

    glBitmap (10, 12, 0.0, 0.0, 11.0, 0.0, rasters);
    glBitmap (10, 12, 0.0, 0.0, 11.0, 0.0, rasters);
    glutSwapBuffers();
    glFlush();

}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
//    gluPerspective(0, (GLdouble)h / (GLdouble)w, 0.01f, 100.0f);
//    gluPerspective(0.0, 1440.0/900.0*float(w)/float(h), 0.1, 100.0);
//    gluOrtho2D(-1 * w/2, w/2, -1 * h/2, h/2);
    glMatrixMode(GL_MODELVIEW);

}

int main(int argc, char * argv[]) {
    // insert code here...
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);

    glutInitWindowSize(400, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("GLUT Sample");

    glutReshapeFunc(reshape);
    glutDisplayFunc(MyDisplay);
    glutMainLoop();
    return 0;
}
