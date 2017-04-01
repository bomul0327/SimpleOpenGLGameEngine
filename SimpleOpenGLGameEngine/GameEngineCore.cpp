#include <GL\glut.h>
#include "GameEngineCore.h"
#include "UserScript.h"

//Global Variables
Time* Time::instance = nullptr;
const Vector3 Vector3::zero(0, 0, 0);
const Vector3 Vector3::one(1, 1, 1);

const Color Color::red(255, 0, 0);
const Color Color::green(0, 255, 0);
const Color Color::blue(0, 0, 255);
const Color Color::white(255, 255, 255);
const Color Color::black(0, 0, 0);

//Class Methods
Time * Time::GetInstance()
{
	if (instance == nullptr) {
		instance = new Time();
	}
	return instance;
}

void Time::CalculateDeltaTime()
{
	int timeSinceStart = glutGet(GLUT_ELAPSED_TIME);
	int intDeltaTime = timeSinceStart - pastTimeSinceStart;
	pastTimeSinceStart = timeSinceStart;
	deltaTime = intDeltaTime * 0.001 * timeScale;
}

void SetOpenGLCallback(int argc, char ** argv, int windowSizeX, int windowSizeY, char* title)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(windowSizeX, windowSizeY);
	glutCreateWindow(title);
	glutReshapeFunc(Reshape);
	glutDisplayFunc(Display);

	Init();

	glutMainLoop();
}

//OpenGL Callback Function
void Init(void)
{
	//Only initialize OpenGL things here, Use Start() for the game logic
	glClearColor(0, 0, 0, 1);
	glColor3f(1, 1, 1);

}

//Manually set size of the world
void Reshape(int width, int height)
{
	//Example one. You need to fix this.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (width <= height) {
		gluOrtho2D(-50.0, 50.0, -50.0 * (GLfloat)height / (GLfloat)width, 50.0 * (GLfloat)height / (GLfloat)width);
	}
	else {
		gluOrtho2D(-50.0*(GLfloat)width / (GLfloat)height, 50.0*(GLfloat)width / (GLfloat)height, -50.0, 50.0);
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Display()
{
	Time::GetInstance()->CalculateDeltaTime();
	Update(Time::GetInstance()->deltaTime);

	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	//Render part
	//Add specific things you want
	//TODO: Users do not have to directly add what they want to draw
	/*Example
	for (int i = 0; i < actorVector.size(); ++i){
		actorVector[i]->Render();
	}
	*/
}

void Idle()
{
	glutPostRedisplay();
}

//TODO: Connect with Input class
void MousePress(GLint button, GLint state, GLint mousePosX, GLint mousePosY)
{
}

//Connect with Input class
void MouseMotion(GLint mousePosX, GLint mousePosY)
{
}

//Connect with Input class
void MousePassiveMotion(GLint mousePosX, GLint mousePosY)
{
}
//TODO: Connect with Input Class
void KeyboardPress(unsigned char key, GLint mousePosX, GLint mousePosY)
{
}
