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


GLfloat MyVertices[8][3] = {
    {-0.25, -0.25, 0.25},
    {-0.25, 0.25, 0.25},
    {0.25, 0.25, 0.25},
    {0.25, -0.25, 0.25},
    {-0.25, -0.25, -0.25},
    {-0.25, 0.25, -0.25},
    {0.25, 0.25, -0.25},
    {0.25, -0.25, -0.25}
};

GLfloat MyColors[8][3] = {
    {0.2, 0.2, 0.2},
    {1.0, 0.0, 0.0},
    {1.0, 1.0, 0.0},
    {0.0, 1.0, 0.0},
    {0.0, 0.0, 1.0},
    {1.0, 0.0, 1.0},
    {1.0, 1.0, 1.0},
    {0.0, 1.0, 1.0}
};

GLubyte MyVertexList[24] = {
    0, 3, 2, 1,
    2, 3, 7, 6,
    0, 4, 7, 3,
    1, 2, 6, 5,
    4, 5, 6, 7,
    0, 1, 5, 4
};

void MyDisplay() {
    

    glClear(GL_COLOR_BUFFER_BIT);
    glFrontFace(GL_CCW);
    glEnable(GL_CULL_FACE);
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    glColorPointer(3, GL_FLOAT, 0, MyColors);
    glVertexPointer(3, GL_FLOAT, 0, MyVertices);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(30.0, 1.0, 1.0, 1.0);
    for (GLint i = 0; i < 6; i++)
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, &MyVertexList[4*i]);
    glFlush();

}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
//    gluPerspective(0, 10, 0.01f, 100.0f);
//    gluPerspective(0.0, 1440.0/900.0*float(w)/float(h), 0.1, 100.0);
    gluOrtho2D(-1 * w/2, w/2, -2 * h, 2*h);
    glMatrixMode(GL_MODELVIEW);

}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char * argv[]) {
    // insert code here...
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);

    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("GLUT Sample");
//    glPixelStorei (GL_UNPACK_ALIGNMENT, 1);
    init();
//    glutReshapeFunc(reshape);
    glutDisplayFunc(MyDisplay);
    glutMainLoop();
    return 0;
}
