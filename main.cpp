#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>


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
    gluPerspective(90, w / h, 1, 10);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt
        (
        1, 0, 3,
        0, 0, 0,
        0, 0, 1
        );
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

        // 햞ea Maior
        glVertex3f(.8, 1.25, 0.1);
        glVertex3f(.8, 2.1, 0.1);

        glVertex3f(-0.8, 1.25, 0.1);
        glVertex3f(-0.8, 2.1, 0.1);

        glVertex3f(-0.8, 1.25, 0.1);
        glVertex3f(0.8, 1.25, 0.1);

        // 햞ea menor
        glVertex3f(.4, 1.7, 0.1);
        glVertex3f(.4, 2.1, 0.1);

        glVertex3f(-.4, 1.7, 0.1);
        glVertex3f(-0.4, 2.1, 0.1);

        glVertex3f(-0.4, 1.7, 0.1);
        glVertex3f(0.4, 1.7, 0.1);


        // Direita

        // 햞ea maior
        glVertex3f(0.8, -2.1, 0.1);
        glVertex3f(0.8, -1.25, 0.1);

        glVertex3f(-0.8, -2.1, 0.1);
        glVertex3f(-0.8, -1.25, 0.1);

        glVertex3f(-0.8, -1.25, 0.1);
        glVertex3f(0.8, -1.25, 0.1);

        // 햞ea menor
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

void display()
{
    glClearColor(.1, .1, .1, .8);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    setView();
    field();

    drawLines();
    beam();
    curves();

    glutSwapBuffers();
}

int main( int argc, char **argv )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(1200, 800);
    glutCreateWindow("FIFA");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
