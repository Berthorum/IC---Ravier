///////////////////////////////////////////////////////////////////////
//
// polygon.cpp
//
///////////////////////////////////////////////////////////////////////
#include <GL/glew.h>
#include <GL/glut.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

// Declara��o e inicializa��o de Vari�veis Globais \\

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
	glGenVertexArrays(NumVAOs, VAOs);// Aloca objetos na matriz de objetos de v�rtice.
	glBindVertexArray(VAOs[Triangles]); // Ativa os v�rtices da matriz de objeto de v�rtice.
	GLfloat vertices[NumVertices][2] = {  // Determina os v�rtices da matriz do objeto.
		{  0.0,  0.0 }, // Triangle 1
		{ -0.7, -0.3 },
		{ -0.4, -0.6 },

		{  0.0,  0.0 }, // Triangle 2
		{  0.7, -0.3 },
		{  0.4, -0.6 },

		{  0.0,  0.0 }, // Triangle 3
		{ -0.4, -0.6 },
		{  0.4, -0.6 },

		{  0.0,  0.0 }, // Triangle 4
		{ -0.7,  0.3 },
		{ -0.4,  0.6 },

		{  0.0,  0.0 }, // Triangle 5
		{  0.7,  0.3 },
		{  0.4,  0.6 },

		{  0.0,  0.0 }, // Triangle 6
		{ -0.4,  0.6 },
		{  0.4,  0.6 },

		{  0.0,  0.0 }, // Triangle 7
		{ -0.7, -0.3 },
		{ -0.7,  0.3 },

		{  0.0,  0.0 }, // Triangle 8
		{  0.7, -0.3 },
		{  0.7,  0.3 },


	};
	glGenBuffers(NumBuffers, Buffers); // Aloca buffers para armazenamento do objeto.
	glBindBuffer(GL_ARRAY_BUFFER, Buffers[ArrayBuffer]); // Inicializar	os objetos para serem alocados especificandoo buffer para o tipo de objeto.
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),
		vertices, GL_STATIC_DRAW); // Armazenar os dados do objeto no buffer.


	glVertexAttribPointer(vPosition, 2, GL_FLOAT,
		GL_FALSE, 0, (void*)0); // Fun��o que associa um variavel de entrada para o shader para percorrer a matriz do objeto e processa-lo
	glEnableVertexAttribArray(vPosition); // Ativa a matriz de v�rtices para ser percorrida pela variavel de entrada do Shader
}
//---------------------------------------------------------------------
//
// display
//
void
display(void)
{
	glClearColor(0, 1, 1, 1); // Limpa o framebuffer ao acontecer uma modifica��o da forma��o padr�o da janela na cor RGBA especificada.
	glBindVertexArray(VAOs[Triangles]); // Inicializa os dados do objetos para serem desenhados
	glDrawArrays(GL_TRIANGLES, 0, NumVertices); // Desenha os objetos especificando qual o seu tipo.
	glFlush(); // Encaminha para o servidor OpenGL as fun��es OpenGL que ficaram pendentes ap�s o Draw.
}

//---------------------------------------------------------------------
//
// main
//
int
main(int argc, char** argv)
{
	glutInit(&argc, argv); // Inicializa a biblioteca GLUT
	glutInitDisplayMode(GLUT_RGBA); // Dstermina o tipo de janela que ser� utilizada na aplica��o
	glutInitWindowSize(512, 512); // Especifica o tamanho da janela.


	glutCreateWindow("Polygon"); // Cria a janela de acordo com a interface do SO.
	if (glewInit()) {
		cerr << "Unable to initialize GLEW ... exiting" << endl;  //Verificar se o GLEW foi inicializado com sucesso.
		exit(EXIT_FAILURE);
	}
	init(); // Inicializa as fun��es relevantes ligadas ao OpenGL
	glutDisplayFunc(display);// Passa o ponteiro para fun��o display para atualiza��o da tela quando necess�rio.
	glutMainLoop(); // Loop infinito que ir� processar a aplica��o.
}
