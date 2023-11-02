#include <iostream>
#include <GL/freeglut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Set the background color to light blue
    glClearColor(0.6, 0.6, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    // Calculate the position for the flag to be in the center
    int flagWidth = 500;  // Adjust this according to your flag's width
    int flagHeight = 300; // Adjust this according to your flag's height
    int canvasWidth = glutGet(GLUT_WINDOW_WIDTH);
    int canvasHeight = glutGet(GLUT_WINDOW_HEIGHT);
    int xOffset = (canvasWidth - flagWidth) / 2;
    int yOffset = (canvasHeight - flagHeight) / 2;

    // Draw the red and white stripes of the flag
    glColor3f(1.0, 1.0, 1.0); // White
    glBegin(GL_POLYGON);
    glVertex2f(xOffset, yOffset);
    glVertex2f(xOffset + flagWidth, yOffset);
    glVertex2f(xOffset + flagWidth, yOffset + flagHeight / 2);
    glVertex2f(xOffset, yOffset + flagHeight / 2);
    glEnd();

    glColor3f(1.0, 0.0, 0.0); // Red
    glBegin(GL_POLYGON);
    glVertex2f(xOffset, yOffset + flagHeight / 2);
    glVertex2f(xOffset + flagWidth, yOffset + flagHeight / 2);
    glVertex2f(xOffset + flagWidth, yOffset + flagHeight);
    glVertex2f(xOffset, yOffset + flagHeight);
    glEnd();

    // Draw the national emblem (if desired)

    glFlush();
}

void myinit() {
    // Set the initial background color to light blue
    glClearColor(0.6, 0.6, 1.0, 1.0);
    glColor3f(1.0, 0.0, 0.0); // Red outline and points
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 800.0, 0.0, 600.0); // Adjusted the ortho values for the flag's dimensions
}

void myMouse(int button, int state, int x, int y) {
    std::cout << button << " " << state << " " << x << " " << y << std::endl;
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600); // Adjusted the window size
    glutInitWindowPosition(100, 100); // Adjusted the window position
    glutCreateWindow("Indonesian Flag");
    glutDisplayFunc(display);
    glutMouseFunc(myMouse);

    myinit();
    glutMainLoop();

    return 0;
}
