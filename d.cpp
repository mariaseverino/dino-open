/*
 * Copyright (c) 1993-1997, Silicon Graphics, Inc.
 * ALL RIGHTS RESERVED
 * Permission to use, copy, modify, and distribute this software for
 * any purpose and without fee is hereby granted, provided that the above
 * copyright notice appear in all copies and that both the copyright notice
 * and this permission notice appear in supporting documentation, and that
 * the name of Silicon Graphics, Inc. not be used in advertising
 * or publicity pertaining to distribution of the software without specific,
 * written prior permission.
 *
 * THE MATERIAL EMBODIED ON THIS SOFTWARE IS PROVIDED TO YOU "AS-IS"
 * AND WITHOUT WARRANTY OF ANY KIND, EXPRESS, IMPLIED OR OTHERWISE,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY OR
 * FITNESS FOR A PARTICULAR PURPOSE.  IN NO EVENT SHALL SILICON
 * GRAPHICS, INC.  BE LIABLE TO YOU OR ANYONE ELSE FOR ANY DIRECT,
 * SPECIAL, INCIDENTAL, INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY
 * KIND, OR ANY DAMAGES WHATSOEVER, INCLUDING WITHOUT LIMITATION,
 * LOSS OF PROFIT, LOSS OF USE, SAVINGS OR REVENUE, OR THE CLAIMS OF
 * THIRD PARTIES, WHETHER OR NOT SILICON GRAPHICS, INC.  HAS BEEN
 * ADVISED OF THE POSSIBILITY OF SUCH LOSS, HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, ARISING OUT OF OR IN CONNECTION WITH THE
 * POSSESSION, USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * US Government Users Restricted Rights
 * Use, duplication, or disclosure by the Government is subject to
 * restrictions set forth in FAR 52.227.19(c)(2) or subparagraph
 * (c)(1)(ii) of the Rights in Technical Data and Computer Software
 * clause at DFARS 252.227-7013 and/or in similar or successor
 * clauses in the FAR or the DOD or NASA FAR Supplement.
 * Unpublished-- rights reserved under the copyright laws of the
 * United States.  Contractor/manufacturer is Silicon Graphics,
 * Inc., 2011 N.  Shoreline Blvd., Mountain View, CA 94039-7311.
 *
 * OpenGL(R) is a registered trademark of Silicon Graphics, Inc.
 */

/*
 * robot.c
 * This program shows how to composite modeling transformations
 * to draw translated and rotated hierarchical models.
 * Interaction:  pressing the s and e keys (shoulder and elbow)
 * alters the rotation of the robot arm.
 */
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>

GLfloat angle, fAspect, rotX, rotY;
GLdouble obsX, obsY, obsZ;

GLfloat a1 = 0.2, b1 = 0.2, c1 = 0.2, d1 = 1.0;
GLfloat a2 = 0.7, b2 = 0.7, c2 = 0.7, d2 = 1.0;

GLfloat especularidade[4] = {1.0, 1.0, 1.0, 1.0};
GLint especMaterial = 60;

static int shoulder = 0, elbow = 35;
static int shoulderE = 15, elbowE = 35;

using namespace std;

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);

    glShadeModel(GL_FLAT);

    angle = 50;

    rotX = 30;
    rotY = 0;
    obsZ = 180;
}

void dedo2(void)
{
    GLfloat luz[4] = {a1, b1, c1, d1};
    GLfloat posicaoLuz[4] = {0.0, 0.0, 0.0, 1.0};

    glMaterialfv(GL_BACK, GL_SPECULAR, especularidade);
    glMateriali(GL_BACK, GL_SHININESS, especMaterial);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luz);
    glLightfv(GL_LIGHT0, GL_AMBIENT, luz);
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);

    glColor3f(0.0f, 0.0f, 1.0f);

    glPushMatrix();
    glTranslatef(-1.0, 0.0, 0.0);
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    glPopMatrix();
}

void dedo1(void)
{
    GLfloat luz[4] = {a2, b2, c2, d2}; // "cor"
    GLfloat posicaoLuz[4] = {0.0, 0.0, 0.0, 1.0};

    glMaterialfv(GL_BACK, GL_SPECULAR, especularidade);
    glMateriali(GL_BACK, GL_SHININESS, especMaterial);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luz);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luz);
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);

    glBegin(GL_POLYGON);

    glVertex2f(0.0, 0.8);
    glVertex2f(0.4, 0.8);

    glVertex2f(0.4, 0.75);
    glVertex2f(0.0, 0.75);
    glEnd();
    // ------------------
    glBegin(GL_POLYGON);
    glVertex2f(-0.05, 0.75);
    glVertex2f(0.45, 0.75);

    glVertex2f(0.45, 0.5);
    glVertex2f(-0.05, 0.5);
    glEnd();
    // -------------------
    glBegin(GL_POLYGON);
    glVertex2f(-0.05, 0.5);
    glVertex2f(0.2, 0.5);

    glVertex2f(0.2, 0.4);
    glVertex2f(-0.05, 0.4);
    glEnd();
    // -------------------
    glBegin(GL_POLYGON);
    glVertex2f(0.2, 0.45);
    glVertex2f(0.35, 0.45);

    glVertex2f(0.35, 0.4);
    glVertex2f(0.2, 0.4);
    glEnd();
    // ------------------
    glBegin(GL_POLYGON);
    glVertex2f(-0.1, 0.4);
    glVertex2f(0.15, 0.4);

    glVertex2f(0.15, 0.05);
    glVertex2f(-0.1, 0.05);
    glEnd();
    // -----------------
    glBegin(GL_POLYGON);
    glVertex2f(0.15, 0.3);
    glVertex2f(0.25, 0.3);

    glVertex2f(0.25, 0.25);
    glVertex2f(0.15, 0.25);
    glEnd();
    // -----------------
    glBegin(GL_POLYGON);
    glVertex2f(0.20, 0.25);
    glVertex2f(0.25, 0.25);

    glVertex2f(0.25, 0.2);
    glVertex2f(0.20, 0.2);
    glEnd();
    // -----------------
    glBegin(GL_POLYGON);
    glVertex2f(0.1, 0.05);
    glVertex2f(-0.15, 0.05);

    glVertex2f(-0.15, 0.0);
    glVertex2f(0.1, 0.0);
    glEnd();
    // -----------------
    glBegin(GL_POLYGON);
    glVertex2f(0.05, 0.0);
    glVertex2f(-0.15, 0.0);

    glVertex2f(-0.15, -0.05);
    glVertex2f(0.05, -0.05);
    glEnd();
    //-------------------
    glBegin(GL_POLYGON);
    glVertex2f(0.0, -0.05);
    glVertex2f(-0.1, -0.05);

    glVertex2f(-0.1, -0.15);
    glVertex2f(0.0, -0.15);
    glEnd();
    //-------------------
    glBegin(GL_POLYGON);
    glVertex2f(-0.15, 0.35);
    glVertex2f(-0.1, 0.35);

    glVertex2f(-0.1, -0.1);
    glVertex2f(-0.15, -0.1);
    glEnd();
    //-------------------
    glBegin(GL_POLYGON);
    glVertex2f(-0.25, 0.3);
    glVertex2f(-0.15, 0.3);

    glVertex2f(-0.15, -0.15);
    glVertex2f(-0.25, -0.15);
    glEnd();
    //-------------------
    glBegin(GL_POLYGON);
    glVertex2f(-0.3, 0.25);
    glVertex2f(-0.25, 0.25);

    glVertex2f(-0.25, -0.15);
    glVertex2f(-0.3, -0.15);
    glEnd();
    //-------------------
    glBegin(GL_POLYGON);
    glVertex2f(-0.3, 0.2);
    glVertex2f(-0.35, 0.2);

    glVertex2f(-0.35, -0.1);
    glVertex2f(-0.3, -0.1);
    glEnd();
    //-------------------
    glBegin(GL_POLYGON);
    glVertex2f(-0.3, 0.2);
    glVertex2f(-0.35, 0.2);

    glVertex2f(-0.35, -0.1);
    glVertex2f(-0.3, -0.1);
    glEnd();
    //-------------------
    glBegin(GL_POLYGON);
    glVertex2f(-0.35, 0.2);
    glVertex2f(-0.4, 0.2);

    glVertex2f(-0.4, -0.05);
    glVertex2f(-0.35, -0.05);
    glEnd();
    //-------------------
    glBegin(GL_POLYGON);
    glVertex2f(-0.4, 0.25);
    glVertex2f(-0.45, 0.25);

    glVertex2f(-0.45, -0.0);
    glVertex2f(-0.4, -0.0);
    glEnd();
    //-------------------
    glBegin(GL_POLYGON);
    glVertex2f(-0.45, 0.3);
    glVertex2f(-0.5, 0.3);

    glVertex2f(-0.5, 0.05);
    glVertex2f(-0.45, 0.05);
    glEnd();
    //-------------------
    glBegin(GL_POLYGON);
    glVertex2f(-0.5, 0.4);
    glVertex2f(-0.55, 0.4);

    glVertex2f(-0.55, 0.1);
    glVertex2f(-0.5, 0.1);
    glEnd();
    //-------------------
    glBegin(GL_POLYGON);
    glVertex2f(-0.2, -0.15);
    glVertex2f(-0.3, -0.15);

    glVertex2f(-0.3, -0.2);
    glVertex2f(-0.2, -0.2);
    glEnd();
    //-------------------
    glBegin(GL_POLYGON);
    glVertex2f(-0.3, -0.2);
    glVertex2f(-0.25, -0.2);

    glVertex2f(-0.25, -0.3);
    glVertex2f(-0.3, -0.3);
    glEnd();
    //-------------------
    glBegin(GL_POLYGON);
    glVertex2f(-0.25, -0.25);
    glVertex2f(-0.2, -0.25);

    glVertex2f(-0.2, -0.3);
    glVertex2f(-0.25, -0.3);
    glEnd();
    //-------------------
    glBegin(GL_POLYGON);
    glVertex2f(-0.05, -0.15);
    glVertex2f(0.0, -0.15);

    glVertex2f(0.0, -0.3);
    glVertex2f(-0.05, -0.3);
    glEnd();
    //-------------------
    glBegin(GL_POLYGON);
    glVertex2f(-0.05, -0.25);
    glVertex2f(0.05, -0.25);

    glVertex2f(0.05, -0.3);
    glVertex2f(-0.05, -0.3);
    glEnd();

    //----------------
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(0.05, 0.73);
    glVertex2f(0.05, 0.68);
    glVertex2f(0.1, 0.68);
    glVertex2f(0.1, 0.73);
    glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    dedo1();
    // dedo2();

    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 's':
        if (elbowE < 180)
        {
            elbowE = (elbowE + 5) % 360;
            glutPostRedisplay();
        }
        break;
    case 'S':
        if (elbow > 0)
        {
            elbow = (elbow - 5) % 360;
            glutPostRedisplay();
        }
        break;
    case 'e':

        if (elbow < 180)
        {
            elbow = (elbow + 5) % 360;
            glutPostRedisplay();
        }
        break;
    case 'E':
        if (elbow > 0)
        {
            elbow = (elbow - 5) % 360;
            glutPostRedisplay();
        }
        break;
    case 'a':
        a1 = 0.7, b1 = 0.7, c1 = 0.7, d1 = 1.0;
        a2 = 0.2, b2 = 0.2, c2 = 0.2, d2 = 1.0;

        glutPostRedisplay();
        break;
    case 'b':
        a1 = 0.2, b1 = 0.2, c1 = 0.2, d1 = 1.0;
        a2 = 0.7, b2 = 0.7, c2 = 0.7, d2 = 1.0;
        glutPostRedisplay();
        break;
    case 27:
        exit(0);
        break;
    default:
        break;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}