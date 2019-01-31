#include "Lab1.h"
#include "MyRectangle.h"
#include "Square.h"
/**
* Frame buffer that maintains the individual pixel colors in memory
* before they are displayed on the screen.
* This object is a global variable.
*/
FrameBuffer frameBuffer(WINDOW_WIDTH, WINDOW_HEIGHT);

/**
* Acts as the display function for the window.
*/

MyRectangle r1(150, 75, 200, 150, color(233,0,0,1.0f));
MyRectangle r2(300, 250, 75, 35, color(0, 255, 255, 1.0f));
MyRectangle r0;

Square s1;
Square s2(350, 400, 150, color(255, 255, 0, 1.0f));
static void RenderSceneCB()
{
	// Clear the color buffer
	frameBuffer.clearColorAndDepthBuffers(); // Not necessary for ray tracin

	// Rendering code that updates the color buffer
    r0.draw(frameBuffer);
    r1.draw(frameBuffer);
    r2.draw(frameBuffer);
    s1.draw(frameBuffer);
    s2.draw(frameBuffer);
	 // Display the color buffer
	frameBuffer.showColorBuffer();

} // end RenderSceneCB


  // Reset viewport limits for full window rendering each time the window is resized.
  // This function is called when the program starts up and each time the window is 
  // resized.
static void ResizeCB(int width, int height)
{
	// Size the color buffer to match the window size.
	frameBuffer.setFrameBufferSize(width, height);

	// Signal the operating system to re-render the window
	glutPostRedisplay();

} // end ResizeCB


  // Register as the "idle" function to have the screen continously
  // repainted. Due to software rendering, the frame rate will not
  // be fast enough to support motion simulation
static void animate()
{
	glutPostRedisplay();

} // end animate


int main(int argc, char** argv)
{
	// freeGlut and Window initialization ***********************

	// Pass any applicable command line arguments to GLUT. These arguments
	// are platform dependent.
	glutInit(&argc, argv);

	// Set the initial display mode.
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA);

	// Set the initial window size
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);

	// Create a window using a string and make it the current window.
    //GLuint world_Window = glutCreateWindow("2D Shapes");
    glutCreateWindow("2D Shapes");
    glutPushWindow();
	// Indicate to GLUT that the flow of control should return to the program after
	// the window is closed and the GLUTmain loop is exited.
#warning glutSetOption(X,Y) doesnt exist..
	//glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	// Callback for window redisplay
	glutDisplayFunc(RenderSceneCB);
	glutReshapeFunc(ResizeCB);
    glutIdleFunc(animate);

	// ColorBuffer initialization ***********************

	// Create a clear color for the window
	color blue(0.784, 0.784, 1.0, 1.0);

	// Set red, green, blue, and alpha to which the color buffer is cleared.
	frameBuffer.setClearColor(blue);

	// Enter the GLUT main loop. Control will not return until the window is closed.
	glutMainLoop();

	// To keep the console open on shutdown, start the project with Ctrl+F5 instead of just F5.
	return 0;

} // end main
