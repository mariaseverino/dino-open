#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

#define checkImageWidth 64
#define checkImageHeight 64
static GLubyte checkImage[checkImageHeight][checkImageWidth][4];

#ifdef GL_VERSION_1_1
static GLuint texName;
#endif

void textura()
{
    int i, j, c;

    for (i = 0; i < checkImageHeight; i++)
    {
        for (j = 0; j < checkImageWidth; j++)
        {
            c = ((((i & 0x8) == 0) ^ ((j & 0x8)) == 0)) * 250;
            checkImage[i][j][0] = (GLubyte)c;
            checkImage[i][j][1] = (GLubyte)25;
            checkImage[i][j][2] = (GLubyte)c;
            checkImage[i][j][3] = (GLubyte)25;
        }
    }
}

GLfloat chao = -0.3;
GLfloat xDino = -10.0, yDino = chao + 0.3;
GLfloat xCacto = xDino + 20.0, yCacto = chao + 0.3;
GLfloat cenarioX = 0.0;
GLfloat proxObstaculo;
GLfloat p1 = 0.1, p2 = 0.0;
GLfloat pc1 = 0.0, pc2 = 0.0;

int indexProxObstaculo = 0;

GLfloat posicoesObstaculos[100];

bool inicio = false;

// Luzes
GLfloat luzAmbiente[4] = {0.2, 0.2, 0.2, 1.0};
GLfloat luzDifusa[4] = {0.7, 0.7, 0.7, 1.0};    // "cor"
GLfloat luzEspecular[4] = {1.0, 1.0, 1.0, 1.0}; // "brilho"
GLfloat posicaoLuz[4] = {0.0, 50.0, 50.0, 1.0};

// Capacidade de brilho do material
GLfloat especularidade[4] = {1.0, 1.0, 1.0, 1.0};
GLint especMaterial = 60;

using namespace std;

void desenhaDino()
{
    // glColor3f(0.71, 0.74, 0.81);
    glColor3f(0.071, 0.074, 0.081);

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
    // //-- -- -- -- -- -- -- -- -- -
    glBegin(GL_POLYGON);
    glVertex2f(-0.15, 0.35);
    glVertex2f(-0.1, 0.35);

    glVertex2f(-0.1, -0.1);
    glVertex2f(-0.15, -0.1);
    glEnd();
    // //-- -- -- -- -- -- -- -- -- -
    glBegin(GL_POLYGON);
    glVertex2f(-0.25, 0.3);
    glVertex2f(-0.15, 0.3);

    glVertex2f(-0.15, -0.1);
    glVertex2f(-0.25, -0.1);
    glEnd();
    // //-- -- -- -- -- -- -- -- -- -
    glBegin(GL_POLYGON);
    glVertex2f(-0.3, 0.25);
    glVertex2f(-0.25, 0.25);

    glVertex2f(-0.25, -0.1);
    glVertex2f(-0.3, -0.1);
    glEnd();
    //-- -- -- -- -- -- -- -- -- -? ? ? ? ? ? ?
    glBegin(GL_POLYGON);
    glVertex2f(-0.3, 0.2);
    glVertex2f(-0.35, 0.2);

    glVertex2f(-0.35, -0.1);
    glVertex2f(-0.3, -0.1);
    glEnd();
    //-- -- -- -- -- -- -- -- -- -
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
    //--------perna1-----------
    //------------------- isso aqui
    glPushMatrix();
    glTranslatef(0.0, p1, 0.0);
    // glBegin(GL_POLYGON);
    // glVertex2f(-0.3, 0.2);
    // glVertex2f(-0.35, 0.2);

    // glVertex2f(-0.35, -0.1);
    // glVertex2f(-0.3, -0.1);
    // glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-0.15, -0.1);
    glVertex2f(-0.3, -0.1);

    glVertex2f(-0.3, -0.15);
    glVertex2f(-0.15, -0.15);
    glEnd();

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
    glPopMatrix();
    //---------perna2----------
    glPushMatrix();
    glTranslatef(0.0, p2, 0.0);
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

    //----------------
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(0.05, 0.73);
    glVertex2f(0.05, 0.68);
    glVertex2f(0.1, 0.68);
    glVertex2f(0.1, 0.73);
    glEnd();
    glPopMatrix();
}

void desenhaCacto()
{
    glColor3f(0.2, 1.0, 0.2);

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
}

void desenhaChao()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
#ifdef GL_VERSION_1_1
    glBindTexture(GL_TEXTURE_2D, texName);
#endif

    glColor3f(0.139, 0.0, 0.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex2f(-20.0, chao);

    glTexCoord2f(0.0, 1.0);
    glVertex2f(posicoesObstaculos[99] + 3.0, chao);

    glTexCoord2f(1.0, 1.0);
    glVertex2f(posicoesObstaculos[99] + 3.0, chao - 7.0);

    glTexCoord2f(1.0, 0.0);
    glVertex2f(-20.0, chao - 7.0);

    glEnd();
}

void AcenderLuz()
{
    glEnable(GL_LIGHT0);
}

void ApagarLuz()
{
    glDisable(GL_LIGHT0);
}

void constroiTextura()
{
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);

    textura();
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

#ifdef GL_VERSION_1_1
    glGenTextures(1, &texName);
    glBindTexture(GL_TEXTURE_2D, texName);
#endif

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
#ifdef GL_VERSION_1_1
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth, checkImageHeight,
                 0, GL_RGBA, GL_UNSIGNED_BYTE, checkImage);
#else
    glTexImage2D(GL_TEXTURE_2D, 0, 4, checkImageWidth, checkImageHeight,
                 0, GL_RGBA, GL_UNSIGNED_BYTE, checkImage);
#endif
}
void init()
{
    glClearColor(0.71, 0.74, 0.81, 0.0);
    // Habilita a definição da cor do material a partir da cor corrente
    glEnable(GL_COLOR_MATERIAL);
    // Habilita o uso de iluminação
    glEnable(GL_LIGHTING);
    // Habilita a luz de número 0
    glEnable(GL_LIGHT0);
    // Habilita o depth-buffering
    glEnable(GL_DEPTH_TEST);
    // glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    // Define a refletância do material
    glMaterialfv(GL_FRONT, GL_SPECULAR, especularidade);
    // // Define a concentração do brilho
    glMateriali(GL_FRONT, GL_SHININESS, especMaterial);
    glEnable(GL_DEPTH_TEST);

    // glShadeModel(GL_FLAT);

    GLfloat posicaoAnterior = xDino + 4.0;

    for (int i = 0; i < 100; i++)
    {
        posicoesObstaculos[i] = posicaoAnterior + 16.0;
        posicaoAnterior = posicoesObstaculos[i];
    }
    proxObstaculo = posicoesObstaculos[0];
}
void cena()
{
    glPushMatrix();
    glTranslatef(cenarioX, 0.0, 0.0);
    desenhaChao();

    for (int i = 0; i < 100; i++)
    {
        glPushMatrix();
        glTranslatef(posicoesObstaculos[i], yCacto, 0.0);
        desenhaCacto();
        glPopMatrix();
    }
    glPopMatrix();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

    // // Define os parâmetros da luz de número 0
    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
    glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);

    cena();
    desenhaDino();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(9.0, 0.0);
    glVertex2f(-10.0, 0.0);
    glVertex2f((-10.0) + (15.0), 0.0);
    glEnd();

    glutSwapBuffers();
}

void timer(int value)
{
    if (p1 > pc1)
    {
        if (p2 < 0.005)
        {
            p2 = 0.0;
        }

        p1 = p1 - 0.005;
        p2 = p2 + 0.005;
    }
    else if (p2 > pc2)
    {
        if (p1 < 0.005)
        {
            p1 = 0.0;
        }
        p1 = p1 + 0.005;
        p2 = p2 - 0.005;
    }

    if (inicio == true)
    {
        cenarioX = cenarioX - 0.4;
        proxObstaculo = proxObstaculo - 0.4;

        if (yDino > chao + 0.3)
        {
            yDino = yDino - 0.2;
        }

        if (proxObstaculo <= -10.0 and yDino <= chao + 0.3)
        {
            cout << "colisao \n";

            inicio = false;
        }
        else if (proxObstaculo <= -10.0 and yDino > chao + 0.3)
        {
            proxObstaculo = 6.0;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(50, timer, 1);
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(105.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'a':
        AcenderLuz();
        glutPostRedisplay();
        break;
    case 'r':
        chao = -0.3;
        xDino = -10.0, yDino = chao + 0.3;
        xCacto = xDino + 20.0, yCacto = chao + 0.3;
        cenarioX = 0.0;
        indexProxObstaculo = 0;

        inicio = true;
        glutPostRedisplay();

        break;
    case 32:
        if (yDino <= chao + 0.3)
        {
            yDino += 3.0;
            glutPostRedisplay();
        }
        break;
    case 'd':
        ApagarLuz();
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
    glutInitWindowSize(1200, 720);
    glutCreateWindow("Dino Open");
    init();
    constroiTextura();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(50, timer, 1);
    glutMainLoop();
    return 0;
}