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


// Quadrics object
GLUquadricObj *qobj = gluNewQuadric();

const GLfloat white[] = {1.0, 1.0, 1.0, 1.0};
const GLfloat light_pos[] = {0.0, 0.0, 0.0, 1.0};
GLfloat const_att = 1.0;

void MyDisplay() {
    

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glShadeModel(GL_SMOOTH);

    
    glTranslatef(-0.5, 0.0, 0.0);
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(0.5, 0.5, -0.7);
    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, const_att);
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
    
    glDisable(GL_LIGHTING);
    glColor3d(0.9, 0.9, 0.5);
    glutSolidSphere(0.05, 10, 10);
    glEnable(GL_LIGHTING);

    glPopMatrix();
    
    gluQuadricDrawStyle(qobj, GLU_FILL);
    gluQuadricNormals(qobj, GLU_SMOOTH);
    gluQuadricOrientation(qobj, GLU_OUTSIDE);
    gluQuadricTexture(qobj, GL_FALSE);
    gluSphere(qobj, 0.3, 50, 50);
    
    glutSwapBuffers();
    glFlush();

}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    glOrtho(-2.5, 2.5, -2.5 * (GLfloat)h / (GLfloat)w, 2.5*(GLfloat)h/(GLfloat)w, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

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
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("GLUT Sample");
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
    glLightfv(GL_LIGHT0, GL_SPECULAR, white);
//    glPixelStorei (GL_UNPACK_ALIGNMENT, 1);
//    init();

    glutDisplayFunc(MyDisplay);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
