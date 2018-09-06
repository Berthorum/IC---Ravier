///////////////////////////////////////////////////////////////////////
//
// triangles2.cpp
//
///////////////////////////////////////////////////////////////////////
#include <GL/glew.h>
#include <GL/glut.h>
#include <GLFW/glfw3.h>
#include <iostream>
using namespace std;

enum VAO_IDs { Triangles, NumVAOs };
enum Buffer_IDs { ArrayBuffer, NumBuffers };
enum Attrib_IDs { vPosition = 0 };
GLuint VAOs[NumVAOs];
GLuint Buffers[NumBuffers];
const GLuint NumVertices = 24;

//---------------------------------------------------------------------
//
// init
//
void
init(void)
{
	glGenVertexArrays(NumVAOs, VAOs);
	glBindVertexArray(VAOs[Triangles]);
	GLfloat vertices[NumVertices][2] = {
	{  0.0,  0.0 }, // Triangle 1
	{ -0.7, -0.3 },
	{ -0.4, -0.6 },

	{  0.0,  0.0 }, // Triangle 2
	{  0.7, -0.3 },
	{  0.4, -0.6 },

	{  0.0,  0.0 }, // Triangle 3
	{ -0.3, -0.6 },
	{  0.3, -0.6 },

	{  0.0,  0.0 }, // Triangle 4
	{ -0.7,  0.3 },
	{ -0.4,  0.6 },

	{  0.0,  0.0 }, // Triangle 5
	{  0.7,  0.3 },
	{  0.4,  0.6 },

	{  0.0,  0.0 }, // Triangle 6
	{ -0.3,  0.6 },
	{  0.3,  0.6 },

	{  0.0,  0.0  }, // Triangle 7
	{ -0.7, -0.22 },
	{ -0.7,  0.22 },

	{  0.0,  0.0  }, // Triangle 8
	{  0.7, -0.22 },
	{  0.7,  0.22 },


	};
	glGenBuffers(NumBuffers, Buffers);
	glBindBuffer(GL_ARRAY_BUFFER, Buffers[ArrayBuffer]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),
		vertices, GL_STATIC_DRAW);
	
	
	glVertexAttribPointer(vPosition, 2, GL_FLOAT,
		GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(vPosition);
}
//---------------------------------------------------------------------
//
// display
//
void
display(void)
{
	glClearColor(1, 0, 0, 0);
	glBindVertexArray(VAOs[Triangles]);
	glDrawArrays(GL_TRIANGLES, 0, NumVertices);
	glFlush();
}

//---------------------------------------------------------------------
//
// main
//
int
main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(512, 512);
	

	glutCreateWindow("Triangles 2");
	if (glewInit()) {
		cerr << "Unable to initialize GLEW ... exiting" << endl;
		exit(EXIT_FAILURE);
	}
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}
