#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>
#include <stdio.h>
#include <string.h>

float ballRotateX, ballRotateY, speedX, speedY = 0.0;
float auxSpeedX, auxSpeedY = 0.0;
int timeAzul, timeVermelho = 0;

void field()
{
    GLfloat color[] = {0.0, 0.6, 0.2};
    GLfloat pointsField[4][3] = {
        {-1.7, -2.3, 0},
        {-1.7, 2.3, 0},
        {1.7, 2.3, 0},
        {1.7, -2.3, 0},
    };

    glColor3fv(color);
    glBegin(GL_QUADS);
        glVertex3fv(pointsField[0]);
        glVertex3fv(pointsField[1]);
        glVertex3fv(pointsField[2]);
        glVertex3fv(pointsField[3]);
    glEnd();
}

void setView()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    int w = glutGet(GLUT_WINDOW_WIDTH);
    int h = glutGet(GLUT_WINDOW_HEIGHT);
    gluPerspective(88, w / h, 1, 10);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt
        (
        1, 0, 3,
        0, 0, 0,
        0, 0, 1
        );
}

void drawString(char *message) {
    glPushMatrix();
        glColor3f(.6, 1, 1);
        glTranslatef(-2.5, -2.5, 1);
        glScalef(0.001, 0.001, 0.001);
        glRotated(90, 0, 0, 1);
        for(int i = 0; i < strlen(message); i++)
            glutStrokeCharacter(GLUT_STROKE_ROMAN, message[i]);
    glPopMatrix();
}

void drawLines()
{
    GLfloat lines[] = {1, 1, 1};
    glLineWidth(4.0);
    glColor3fv(lines);
    glBegin(GL_LINES);

        // Linhas laterais
        glVertex3f(-1.5, 2.1, 0.1);
        glVertex3f(1.5, 2.1, 0.1);

        glVertex3f(-1.5, -2.1, 0.1);
        glVertex3f(1.5, -2.1, 0.1);

        glVertex3f(-1.5, -2.1, 0.1);
        glVertex3f(-1.5, 2.1, 0.1);

        glVertex3f(1.5, -2.1, 0.1);
        glVertex3f(1.5, 2.1, 0.1);

        // Linhas laterais
        glVertex3f(-1.5, 2.1, 0.1);
        glVertex3f(1.5, 2.1, 0.1);

        glVertex3f(-1.5, -2.1, 0.1);
        glVertex3f(1.5, -2.1, 0.1);

        glVertex3f(-1.5, -2.1, 0.1);
        glVertex3f(-1.5, 2.1, 0.1);

        glVertex3f(1.5, -2.1, 0.1);
        glVertex3f(1.5, 2.1, 0.1);

        // Linhas centrais
        glVertex3f(-1.5, 0, 0.1);
        glVertex3f(1.5, 0, 0.1);

        // Esqueda

        // Área Maior
        glVertex3f(.8, 1.25, 0.1);
        glVertex3f(.8, 2.1, 0.1);

        glVertex3f(-0.8, 1.25, 0.1);
        glVertex3f(-0.8, 2.1, 0.1);

        glVertex3f(-0.8, 1.25, 0.1);
        glVertex3f(0.8, 1.25, 0.1);

        // Área menor
        glVertex3f(.4, 1.7, 0.1);
        glVertex3f(.4, 2.1, 0.1);

        glVertex3f(-.4, 1.7, 0.1);
        glVertex3f(-0.4, 2.1, 0.1);

        glVertex3f(-0.4, 1.7, 0.1);
        glVertex3f(0.4, 1.7, 0.1);


        // Direita

        // Área maior
        glVertex3f(0.8, -2.1, 0.1);
        glVertex3f(0.8, -1.25, 0.1);

        glVertex3f(-0.8, -2.1, 0.1);
        glVertex3f(-0.8, -1.25, 0.1);

        glVertex3f(-0.8, -1.25, 0.1);
        glVertex3f(0.8, -1.25, 0.1);

        // Área menor
        glVertex3f(0.4, -2.1, 0.1);
        glVertex3f(0.4, -1.7, 0.1);

        glVertex3f(-0.4, -2.1, 0.1);
        glVertex3f(-0.4, -1.7, 0.1);

        glVertex3f(-0.4, -1.7, 0.1);
        glVertex3f(0.4, -1.7, 0.1);

        // Detalhes

        glVertex3f(-1.5, -1.9, 0.1);
        glVertex3f(-1.2, -2.1, 0.1);

        glVertex3f(1.5, -1.9, 0.1);
        glVertex3f(1.2, -2.1, 0.1);

        glVertex3f(-1.5, 1.9, 0.1);
        glVertex3f(-1.2, 2.1, 0.1);

        glVertex3f(1.5, 1.9, 0.1);
        glVertex3f(1.2, 2.1, 0.1);

    glEnd();
}

void curves()
{
    glPointSize(3.0);
    glBegin(GL_POINTS);
        for (float i = 0.0; i <= 8; i += 0.01)
            glVertex3f((sin(i))/2, (cos(i))/2, .1);

        for (float i = 2; i <= 4.3; i += 0.01)
            glVertex3f((sin(i))/3, (cos(i) + 4.1)/3, .1);

        for (float i = 2; i <= 4.3; i += 0.01)
            glVertex3f((sin(i))/3, -(cos(i) + 4.1)/3, .1);

    glEnd();
}

void beam()
{
    glColor3f(1, 1, 0.9);
    glBegin(GL_LINES);

        // Esquerda
        glVertex3f(-0.9, -2.1, 0.3);
        glVertex3f(-0.1, -2.1, 0.3);

        glVertex3f(-0.9, -2.1, 0.3);
        glVertex3f(-0.3, -2.1, 0.1);

        glVertex3f(-0.1, -2.1, 0.3);
        glVertex3f(.3, -2.1, 0.1);

        // Direita
        glVertex3f(-.9, 2.1, 0.3);
        glVertex3f(-.1, 2.1, 0.3);

        glVertex3f(-0.9, 2.1, 0.3);
        glVertex3f(-0.3, 2.1, 0.1);

        glVertex3f(-0.1, 2.1, 0.3);
        glVertex3f(.3, 2.1, 0.1);

	glEnd();
}

void ball()
{
    glPushMatrix();
        glRotatef(1.5, 1, 0, 0);
        glTranslatef(speedX, speedY, .2);
        glColor3f(1.0,0.9,0.0);
        glScalef(0.04,0.04,0.04);
        glutSolidSphere(1,50,50);
    glPopMatrix();
}

void placar()
{
    char str[30];
    glLineWidth(2);
    sprintf(str, "Time Azul: %d  VS  Time Vermelho: %d", timeAzul, timeVermelho);

    drawString(str);
}

void players(float x, float y, GLfloat* color)
{
    // Corpo
    glPushMatrix();
        glColor3fv(color);
        glTranslatef(x, y, 0);
        glutSolidCube(.2);
    glPopMatrix();

    // Cabeça
    glPushMatrix();
        glTranslatef(x, y, .2);
        glColor3f(0.6, 0.3, 0);
        glScalef(0.08,0.08,0.08);
        glutSolidSphere(1,50,50);
    glPopMatrix();
}

void playerManage()
{
    // Time Azul
    GLfloat azul[] = {0.0, 0.0, 0.8};
    players(1, -1, azul);
    players(-.1, -1.8, azul);
    players(-.1, -0.5, azul);
    players(-1, -1, azul);

    // Time Vermelho
    GLfloat vermelho[] = {0.8, 0.0, 0.0};
    players(1, 1, vermelho);
    players(-.1, 1.8, vermelho);
    players(-.1, 0.5, vermelho);
    players(-1, 1, vermelho);

}

void display()
{
    glClearColor(.1, .1, .1, .8);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    setView();
    field();

    drawLines();
    beam();
    curves();
    ball();
    placar();
    playerManage();

    glutSwapBuffers();
}

void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
        case 97:
            auxSpeedY = -0.025;
            break;
        case 100:
            auxSpeedY = 0.025;
            break;
        case 115:
            auxSpeedX = 0.025;
            break;
        case 119:
            auxSpeedX = -0.025;
            break;
        case 27:
            exit(0);
    }
}

void KeyboardUpHandler(unsigned char key, int x, int y) {
    switch (key) {
        case 97:
            auxSpeedY = 0;
            break;
        case 100:
            auxSpeedY = 0;
            break;
        case 115:
            auxSpeedX = 0;
            break;
        case 119:
            auxSpeedX = 0;
            break;
        case 27:
            exit(0);
    }
}

void update(int value)
{
    speedX += auxSpeedX;
    if ((ballRotateX > -0.3 && ballRotateX < 0.3) && auxSpeedX != 0)
        ballRotateX += speedX / 15;

    speedY += auxSpeedY;
    if ((ballRotateY > -0.3 && ballRotateY < 0.3) && auxSpeedY != 0)
        ballRotateY += speedY / 15;



    if ((speedX > -0.3 && speedX < 0.3) && speedY <= -2)
    {
        timeVermelho += 1;
        speedX = speedY = 0;
    }

    if ((speedX > -0.3 && speedX < 0.3) && speedY >= 2)
    {
        timeAzul += 1;
        speedX = speedY = 0;
    }

    glutPostRedisplay();
    glutTimerFunc(20, update, 0);
}

int main( int argc, char **argv )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(1200, 800);
    glutCreateWindow("FIFA");
    glutKeyboardFunc(handleKeypress);
    glutKeyboardUpFunc(KeyboardUpHandler);
    glutDisplayFunc(display);
    glutTimerFunc(25, update, 0);
    glutMainLoop();
    return 0;
}
