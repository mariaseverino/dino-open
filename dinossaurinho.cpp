#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

GLfloat chao = -1.0;
GLfloat xDino = -4.0, yDino = chao;
GLfloat xCacto = xDino + 4.0, yCacto = chao;
GLboolean iluminacaoAtivada = GL_FALSE;

// Luz Inicial
GLfloat luzAmbiente[4]={0.2,0.2,0.2,0.2};
GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0}; // "cor"
GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};// "brilho" 
GLfloat posicaoLuz[4]={0.0, 50.0, 50.0, 1.0};

// Luz Vermelha
GLfloat luzAmbienteVermelha[4] = {0.2,0.0,0.0,1.0};
GLfloat luzDifusaVermelha[4] = {0.7,0.0,0.0,1.0}; // Cor da Luz

// Capacidade de brilho do material
GLfloat especularidade[4]={1.0,1.0,1.0,1.0}; 
GLint especMaterial = 60;

using namespace std;

void desenhaDino()
{
    glColor3f(0.5, 0.5, 0.5);

    glPushMatrix();
    glTranslatef(xDino, yDino, 0.0);

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
    glPopMatrix();
}

void desenhaCacto()
{
    glColor3f(0.0, 1.0, 0.0);

    glPushMatrix();
    glTranslatef(xCacto, yCacto, 0.0);

    glBegin(GL_POLYGON);
    glVertex2f(0.2, -0.3);
    glVertex2f(0.0, -0.3);

    glVertex2f(0.0, 0.75);
    glVertex2f(0.2, 0.75);

    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.03, 0.75);
    glVertex2f(0.17, 0.75);

    glVertex2f(0.17, 0.8);
    glVertex2f(0.03, 0.8);

    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.1, 0.0);
    glVertex2f(0.3, 0.0);

    glVertex2f(0.3, 0.2);
    glVertex2f(-0.1, 0.2);

    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(-0.1, 0.2);
    glVertex2f(-0.1, 0.0);
    glVertex2f(-0.25, 0.15);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.1, 0.15);
    glVertex2f(-0.25, 0.15);

    glVertex2f(-0.25, 0.55);
    glVertex2f(-0.1, 0.55);

    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.13, 0.55);
    glVertex2f(-0.22, 0.55);

    glVertex2f(-0.22, 0.58);
    glVertex2f(-0.13, 0.58);

    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(0.3, 0.2);
    glVertex2f(0.3, 0.0);
    glVertex2f(0.45, 0.15);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.3, 0.15);
    glVertex2f(0.45, 0.15);

    glVertex2f(0.45, 0.55);
    glVertex2f(0.3, 0.55);

    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.33, 0.55);
    glVertex2f(0.42, 0.55);

    glVertex2f(0.42, 0.58);
    glVertex2f(0.33, 0.58);

    glEnd();

    glPopMatrix();
}

void AlterarLuz() {
    if(iluminacaoAtivada){
        iluminacaoAtivada = GL_FALSE;
        glDisable(GL_LIGHT1);
    } else {
        iluminacaoAtivada = GL_TRUE;
        glEnable(GL_LIGHT1);
    }
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // GL_DEPTH_BUFFER_BIT valores de profundidade maiores possíveis
    glShadeModel(GL_SMOOTH);

       // Define a refletância do material 
	glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
	// Define a concentração do brilho
	glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

	// Ativa o uso da luz ambiente 
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	// Define os parâmetros da luz de número 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente); 
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );

   	// Define os parâmetros da luz de número 1
	glLightfv(GL_LIGHT1, GL_AMBIENT, luzAmbienteVermelha); 
	glLightfv(GL_LIGHT1, GL_DIFFUSE, luzDifusaVermelha);
	glLightfv(GL_LIGHT1, GL_SPECULAR, luzEspecular);
	glLightfv(GL_LIGHT1, GL_POSITION, posicaoLuz);

	// Habilita a definição da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);
	//Habilita o uso de iluminação
	glEnable(GL_LIGHTING);  
	// Habilita a luz de número 0
    //glEnable(GL_LIGHT0);
	// Habilita o depth-buffering
	glEnable(GL_DEPTH_TEST);

    desenhaDino();
    desenhaCacto();

    glutSwapBuffers();
}

void timer(int value)
{
    if (xCacto - 0.3 < floor(xDino))
    {
        cout << "colisao ";
    }
    else if (xDino < 4.0)
    {
        xDino = xDino + 0.1;
        glutPostRedisplay();
        glutTimerFunc(50, timer, 1);
    }
    else if (yDino > chao)
    {
        yDino = yDino - 0.1;
        glutPostRedisplay();
        glutTimerFunc(50, timer, 1);
    }

    cout << xDino << " " << xCacto << " " << xCacto - 0.30 << endl;
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
        yDino += 2.0;
        glutPostRedisplay();
        break;
    case 27:
        exit(0);
        break;
    case 'l':
        AlterarLuz();
        glutPostRedisplay();
        break;
    default:
        break;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1200, 720);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("dinossaurinho");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(50, timer, 1);
    glutMainLoop();
    return 0;
}