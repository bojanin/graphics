#include "Lab.h"
#include "Camera.h"
#include "Lights.h"



/********************** GLOBALS ******************************/
LightSource ambientLight(color(0.15, 0.15, 0.15, 1.0));
PositionalLight lightPos(dvec3(-3, 3, -3), dvec4(0.75, 0.75, 0.75, 1.0));
DirectionalLight lightDir(dvec3(1, 1, 1), dvec4(1.0, 1.0, 1.0, 1.0));
SpotLight lightSpot(dvec3(0.0, 10.0, 0.0), dvec3(0.0, -1.0, 0.0), glm::cos(glm::radians(15.0)), RED);

std::vector<LightSource*> lights;

const GLint FRAMES_PER_SECOND = 60; // Desired maximum number of frames per second
const GLint FRAME_INTERVAL = 1000 / FRAMES_PER_SECOND; // Interval in milliseconds between frames

// Frame buffer that contains both the color and depth buffers
FrameBuffer frameBuffer(WINDOW_WIDTH, WINDOW_HEIGHT);

// Objects in the scene


Pyramid cyanPyr(CYAN, 1.0, 1.0);//
Pyramid bluePyr(BLUE, 1.0, 1.0);//
Pyramid whitePyr(WHITE, 1.0, 1.0);//
Sphere graySphere(GRAY, 1.0, 16, 16);//
Box magBox(MAGENTA, 1.0, 1.0, 1.0);//
Box whiteBox(WHITE, 1.0, 1.0, 1.0);//
Box blackBox(BLACK, 1.0, 1.0, 1.0);
Box bluBox(BLUE, 1.0, 1.0, 1.0);//
Box bluBox2(BLUE, 1.0, 1.0, 1.0);//
Box greenBox(GREEN, 2.0, 2.0, 2.0);


Camera camera(dvec3(0.0, 0.0, 12.0));
// Reference plane
ReferencePlane referencePlane;

// Global to hold the rotation angle of objects in the scene
double angle = glm::radians(45.0);
double zTrans = -14.0f;
float rotationX = 0.0f; 
float rotationY = 0.0f;

enum View_Type { FULL_SCREEN, VERTICAL_SPLIT, HORIZONTAL_SPLIT };
View_Type view = FULL_SCREEN;
/********************** END GLOBALS ******************************/

void renderObjects()
{
    referencePlane.setPosition(dvec3(0.0, -3.0, 0.0));
    referencePlane.draw();

    // Set the position and orientation of the left pyramid and render it.
    cyanPyr.setPosition( dvec3( -3.0, 0.0, 0.0  )  );
    cyanPyr.setOrientation( angle, dvec3( 0.0, 0.0, 1.0  )  );
    cyanPyr.setScale(2.0);
    cyanPyr.draw(  );
    
    bluBox2.setPosition(dvec3(3.5, -2.5, -3.5));
    bluBox2.draw();

    bluePyr.setPosition(dvec3(3.5, -1.5, -3.5));
    bluePyr.draw();

    graySphere.setPosition(dvec3(3.0, 0.0, 0.0));
    graySphere.setOrientation(angle, dvec3(1.0, 0.0, 0.0));
    graySphere.draw();

    whitePyr.setPosition(dvec3(10.0 * glm::sin(-angle), 3.0, 10 * glm::cos(-angle)));
    whitePyr.setOrientation(0, dvec3(1.0, 1.0, 1.0));
    whitePyr.draw();

    magBox.setPosition(dvec3(-0.5, -2.5, -0.5));
    magBox.draw();

   	whiteBox.setPosition(dvec3(0.5, -2.5, -0.5));
   	whiteBox.draw();

    blackBox.setPosition(dvec3(0.0, -2.5, 0.5));
    blackBox.draw();
    
    bluBox.setPosition(dvec3(0.0, -1.5, 0.0));
    bluBox.setOrientation(glm::radians(45.0), dvec3(0.0, 1.0, 0.0));
    bluBox.draw();

    greenBox.setPosition(dvec3(-3.0, -2.0, 3.0));
    greenBox.draw();
}


dmat4 myPerspective(double fovy, double aspect, double near, double far) {
    dmat4 mat;
    //return glm::perspective(fovy, aspect, near, far);
    double y = 1.0 / glm::tan((M_PI / 180.0) * fovy / 2);
    double x = y / aspect;
    mat[0][0] = x;
    mat[1][1] = y;
    mat[2][2] = (near + far) / (near - far);
    mat[3][2] = (2.0 * far * near) / (near - far);
    mat[2][3] = -1;
    return mat;
}

dmat4 myOrtho(double left, double right, double bottom, double top, double near, double far) {
    dmat4 mat;

    mat[0][0] = 2.0 / (right - left);
    mat[1][1] = 2.0 / (top - bottom);
    mat[2][2] = -2.0 / (far - near);
    mat[3][3] = 1;

    mat[3][0] = -((right + left) / (right - left));
    mat[3][1] = -((top + bottom) / (top - bottom));
    mat[3][2] = -((far + near) / (far - near));
    
    return mat;
}

// Draws two views of the scene. One on the right and one on the left.
void twoViewsSplitVertically()
{
	// Render left side view
    double viewportWidth = (PerVertex::xViewportMax-PerVertex::xViewportMin)/2.0;
	double viewportHeight = (PerVertex::yViewportMax - PerVertex::yViewportMin);

	PerVertex::projectionTransformation = myPerspective(45.0, 
    ((double)viewportWidth) / ((double)viewportHeight), 0.1f, 100.0);
	// Set viewport transformation for left view
	PerVertex::viewportTransformation =
		glm::translate(dvec3(0.0, 0.0, 0.0)) *
		glm::scale(dvec3((double)(viewportWidth)/(PerVertex::xNdcMax-
        PerVertex::xNdcMin),
		(double)(viewportHeight)/(PerVertex::yNdcMax-PerVertex::yNdcMin),1.0)) *
		glm::translate(dvec3(-PerVertex::xNdcMin, -PerVertex::yNdcMin, 0.0));

	renderObjects();

    PerVertex::projectionTransformation = myOrtho(-8.0, 8.0, -6.0, 6.0, 1.0, 100.0);
	PerVertex::viewportTransformation =
		glm::translate(dvec3(4.0, 0.0, 0.0)) *
		glm::scale(dvec3((double)(viewportWidth)/(PerVertex::xNdcMax-
        PerVertex::xNdcMin),
		(double)(viewportHeight)/(PerVertex::yNdcMax-PerVertex::yNdcMin),1.0)) *
		glm::translate(dvec3(3, -PerVertex::yNdcMin, 0.0));

	renderObjects();
} // end twoViewsSplitVertically

void twoViewsSplitHorizontally() {
	// Render left side view
    double viewportWidth = (PerVertex::xViewportMax-PerVertex::xViewportMin);
	double viewportHeight = (PerVertex::yViewportMax - PerVertex::yViewportMin)/ 2.0;

	PerVertex::projectionTransformation = myPerspective(45.0, 
    ((double)viewportWidth) / ((double)viewportHeight), 0.1f, 100.0);

	PerVertex::viewportTransformation =
		glm::translate(dvec3(0.0, 0.0, 0.0)) *
		glm::scale(dvec3((double)(viewportWidth)/(PerVertex::xNdcMax-
        PerVertex::xNdcMin),
		(double)(viewportHeight)/(PerVertex::yNdcMax-PerVertex::yNdcMin),1.0)) *
		glm::translate(dvec3(-PerVertex::xNdcMin, -PerVertex::yNdcMin, 0.0));
	renderObjects();

    PerVertex::projectionTransformation = myOrtho(-8.0, 8.0, -6.0, 6.0, 1.0, 100.0);
	PerVertex::viewportTransformation =
		glm::translate(dvec3(0.0, 4.0, 0.0)) *
		glm::scale(dvec3((double)(viewportWidth)/(PerVertex::xNdcMax-
        PerVertex::xNdcMin),
		(double)(viewportHeight)/(PerVertex::yNdcMax-PerVertex::yNdcMin),1.0)) *
		glm::translate(dvec3(-PerVertex::xNdcMin, 3.0, 0.0));
	renderObjects();
}
/**
* Acts as the display function for the window.
*/
static void RenderSceneCB()
{
	// time in milliseconds of last frame render
	static GLint lastRenderTime = 0;

	int currentTime = glutGet(GLUT_ELAPSED_TIME); // Get current time
	int elapsedTime = currentTime - lastRenderTime; // Calc time since last frame

	// Check if enough time has elapsed since the last render.
	if (elapsedTime >= FRAME_INTERVAL) {

		// Save time for this frame render
		lastRenderTime = currentTime;

		// Clear the color buffer
		frameBuffer.clearColorAndDepthBuffers();

		angle += glm::radians(1.0);

		// Determine the position of the viewpoint in world coordinates
		PerVertex::eyePositionInWorldCoords = glm::inverse(PerVertex::viewingTransformation)[3].xyz;

        switch(view) {
            case VERTICAL_SPLIT:
                twoViewsSplitVertically();
                break;
            case HORIZONTAL_SPLIT:
                // TODO
                twoViewsSplitHorizontally();
                break;
            default:
                renderObjects(); 
        }
		// Display the color buffer
		frameBuffer.showColorBuffer();
	}

} // end RenderSceneCB

void cameraMenu(int value)
{
	switch( value ) {
        case(0):
            camera.view(dvec3(0.0, 0.0, 12.0));
            break;
		case(1):
            camera.view(dvec3(0.0, 0.0, -12.0));
			break;
		case(2):
            camera.view(dvec3(0.0, 15.0 * glm::pow(2, 0.5), -15.0 * glm::pow(2, 0.5)));
            break;

		case(3):
            camera.view(dvec3(0.0, 15.0, 0.0), dvec3(0.0, 0.0, 0.0), dvec3(1.0, 0.0, -1.0));
			break;
		default:
			std::cout << "Invalid view selection " << std::endl;
	}

    PerVertex::viewingTransformation = camera.getViewingTransformation();

	// Signal GLUT to call display callback
	glutPostRedisplay( );


}


// Reset viewport limits for full window rendering each time the window is resized.
// This function is called when the program starts up and each time the window is 
// resized.
static void ResizeCB(int width, int height)
{
	// Size the color buffer to match the window size.
	frameBuffer.setFrameBufferSize(width, height); 

	// Set rendering window parameters for viewport transfomation
	PerVertex::xViewportMin = 0;
	PerVertex::yViewportMin = 0;
	PerVertex::xViewportMax = (double)width;
	PerVertex::yViewportMax = (double)height;

	// Create a perspective projection matrix. glm::perspective vertical field of view is specifed in degrees.
	PerVertex::projectionTransformation = myPerspective( 45.0, ( (double)PerVertex::xViewportMax - PerVertex::xViewportMin ) /
		( (double)PerVertex::yViewportMax - PerVertex::yViewportMin ), 1.0, 50.0 );
		
	// Set viewport transformation
	PerVertex::viewportTransformation =
		glm::translate(dvec3(PerVertex::xViewportMin, PerVertex::yViewportMin, 0.0)) *
		glm::scale(dvec3((double)(PerVertex::xViewportMax - PerVertex::xViewportMin) / 
			(PerVertex::xNdcMax - PerVertex::xNdcMin), 
			(double)(PerVertex::yViewportMax - PerVertex::yViewportMin) / 
			(PerVertex::yNdcMax - PerVertex::yNdcMin), 1.0)) *
		glm::translate(dvec3(-PerVertex::xNdcMin, -PerVertex::yNdcMin, 0.0));

	// Signal the operating system to re-render the window
	glutPostRedisplay();

} // end ResizeCB


// Responds to 'f' and escape keys. 'f' key allows 
// toggling full screen viewing. Escape key ends the
// program. Allows lights to be individually turned on and off.
static void KeyboardCB(unsigned char key, int x, int y)
{
	switch (key) {

	case('f') : case('F') : // 'f' key to toggle full screen
		//glutFullScreenToggle();
		break;
	case(27) : // Escape key
		//glutLeaveMainLoop();
		break;
    case('w'):
        ++zTrans;
        break;
    case ('s'):
        --zTrans;
        break;

	default:
		std::cout << key << " key pressed." << std::endl;
	}

glm::mat4 transView = glm::translate(glm::vec3(0.0f, 0.0f, zTrans));
glm::mat4 rotateViewX = glm::rotate(glm::radians(rotationX), glm::vec3(1.0f, 0.0f, 0.0f));
glm::mat4 rotateViewY = glm::rotate(glm::radians(rotationY), glm::vec3(0.0f, 1.0f, 0.0f));

PerVertex::viewingTransformation = transView * rotateViewX * rotateViewY;

	glutPostRedisplay();

} // end KeyboardCB

void polygonRenderMenu( int value )
{
    switch( value ) {

        case( 0 ):

            PerVertex::polygonRenderMode = FILL;
            break;
        case( 1 ):

            PerVertex::polygonRenderMode = LINE;
            break;

        default:
            std::cout << "Invalid polygon render selection " << std::endl;
    }

    // Signal GLUT to call display callback
    glutPostRedisplay( );

} // end polygonRenderMenu

void viewPortMenu(int value)
{
	switch (value) {

	case(0):

		// "Quit" selected on the menu
		//glutLeaveMainLoop();
		break;
	case(1):

		view = FULL_SCREEN;

		ResizeCB((int)PerVertex::xViewportMax,
			(int)PerVertex::yViewportMax);

		break;

	case(2):

		view = VERTICAL_SPLIT;
		std::cout << "vertical" << std::endl;
		break;

	case(3):

		view = HORIZONTAL_SPLIT;

		std::cout << "horizontal" << std::endl;

		break;

	default:
		std::cout << "Invalid view selection " << std::endl;
	}

	// Signal GLUT to call display callback
	glutPostRedisplay();

} // end viewPortMenu

void viewMenu( int value )
{
	switch( value ) {
		case( 1 ):
			camera.view(dvec3(0.0, 0.0, -12.0));
			break;
		case( 2 ):
			camera.view(dvec3(0.0, 15.0 * glm::pow(2, 0.5), -15.0 * glm::pow(2, 0.5)));
			break;

		case( 3 ):
			camera.view(dvec3(0.0, 15.0, 0.0), dvec3(0.0, 0.0, 0.0), dvec3(1.0, 0.0, -1.0));
			break;
		case( 4 ):
            PerVertex::viewingTransformation = glm::lookAt(dvec3(0.0, 0.0, 14.0), dvec3(0.0, 0.0, 0.0), dvec3(0.0, 1.0, 0.0)); 
			break;
		case( 5 ):
            {
            double diff = 7 * sqrt(2);
            PerVertex::viewingTransformation = glm::lookAt(dvec3(0.0, diff, diff), dvec3(0.0, 0.0, 0.0), dvec3(0.0, 0.5, 0.0)); 
			break;
            }
		case( 6 ):
            PerVertex::viewingTransformation = glm::lookAt(dvec3(0.0, 14.0, 0.0), dvec3(0.0, 0.0, 0.0), dvec3(1.0, 0., 0.0)); 
			break;
		default:
			std::cout << "Invalid view selection " << std::endl;
	}

 	PerVertex::viewingTransformation = camera.getViewingTransformation();
	// Signal GLUT to call display callback
	glutPostRedisplay( );

} // end viewMenu


// Responds to presses of the arrow keys
static void SpecialKeysCB(int key, int x, int y)
{
	static const double rotateInc = glm::radians(20.0);

	switch (key) {

	case(GLUT_KEY_RIGHT) :
        --rotationY;
		break;
	case(GLUT_KEY_LEFT) :
        ++rotationY;
		break;
	case(GLUT_KEY_UP) :
        ++rotationX;
		break;
	case(GLUT_KEY_DOWN) :
        --rotationX;
		break;

	default:
		std::cout << key << " key pressed." << std::endl;
	}

glm::dmat4 transView = glm::translate(glm::vec3(0.0f, 0.0f, zTrans));
glm::dmat4 rotateViewX = glm::rotate(glm::radians(rotationX), 
   glm::vec3(1.0f, 0.0f, 0.0f));
glm::dmat4 rotateViewY = glm::rotate(glm::radians(rotationY), 
   glm::vec3(0.0f, 1.0f, 0.0f));

PerVertex::viewingTransformation = transView * rotateViewX * rotateViewY;
	glutPostRedisplay();

} // end SpecialKeysCB


// Register as the "idle" function to have the screen continously
// repainted. Due to software rendering, the frame rate will not
// be fast enough to support motion simulation
static void animate()
{
	glutPostRedisplay();

} // end animate


void mainMenu(int value)
{
	switch (value) {

	case(0):

		// "Quit" selected on the menu
		//glutLeaveMainLoop();
		break;

	default:
		std::cout << "Invalid main menu selection " << std::endl;
	}

	// Signal GLUT to call display callback
	glutPostRedisplay();

} // end mainMenu

void fogMenu( int value )
{
	switch( value ) {

		case( 0 ):
			FragmentOperations::fogSetting = NO_FOG;
			break;
		case( 1 ):
			FragmentOperations::fogSetting = LINEAR_FOG;
			break;
		case( 2 ):
			FragmentOperations::fogSetting = EXPONENTIAL_FOG;
			break;
		case( 3 ):
			FragmentOperations::fogSetting = EXPONENTIAL_2_FOG;
			break;
		default:
			std::cout << "no fog" << std::endl;
	}

	std::cout << "fog type: " << value << std::endl;

	// Signal GLUT to call display callback
	glutPostRedisplay( );

}


// To keep the console open on shutdown, start the project with Ctrl+F5 instead of just F5.
int main(int argc, char** argv)
{
	// freeGlut and Window initialization ***********************

	// initialize random seed
	srand((unsigned int)time(NULL));

	// Pass any applicable command line arguments to GLUT. These arguments
	// are platform dependent.
	glutInit(&argc, argv);

	// Set the initial display mode.
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);

	// Set the initial window size
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);

	// Create a window using a string and make it the current window.
	GLuint world_Window = glutCreateWindow("cse287 Project two - Bojanits");

	// Indicate to GLUT that the flow of control should return to the program after
	// the window is closed and the GLUTmain loop is exited.
	//glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	// Callback for window redisplay
	glutDisplayFunc(RenderSceneCB);
	glutReshapeFunc(ResizeCB);
	glutKeyboardFunc(KeyboardCB);
	glutSpecialFunc(SpecialKeysCB);
	glutIdleFunc(animate);

	int fogMenuID = glutCreateMenu( fogMenu );
	glutAddMenuEntry( "No Fog", 0 );
	glutAddMenuEntry( "Linear Fog", 1 );
	glutAddMenuEntry( "Exponential Fog", 2 );
	glutAddMenuEntry( "Exponential 2 Fog", 3 );


	// Create polygon render submenu
	int polyMenuid = glutCreateMenu(polygonRenderMenu);
	// Specify menu items and integer identifiers
	glutAddMenuEntry( "Fill", 0 );
	glutAddMenuEntry( "Line", 1 );

// Create view submenu
	int viewMenuid = glutCreateMenu( viewMenu );
	// Specify menu items and integer identifiers
	glutAddMenuEntry( "View 1", 1 );
	glutAddMenuEntry( "View 2", 2 );
	glutAddMenuEntry( "View 3", 3 );
	glutAddMenuEntry( "View 4", 4 );
	glutAddMenuEntry( "View 5", 5 );
	glutAddMenuEntry( "View 6", 6 );

	int cameraMenuID = glutCreateMenu(cameraMenu);
    glutAddMenuEntry("View 0", 0);
    glutAddMenuEntry("View 1", 1);
    glutAddMenuEntry("View 2", 2);
    glutAddMenuEntry("View 3", 3);

	int viewportMenuid = glutCreateMenu(viewPortMenu);
	// Specify menu items and integer identifiers
	glutAddMenuEntry("Full Screen", 1);
	glutAddMenuEntry("Vertical Split", 2);
	glutAddMenuEntry("Horizontal Split", 3);
    
	// Create main submenu
	int menu1id = glutCreateMenu( mainMenu );
	glutAddSubMenu( "Render", polyMenuid );
	glutAddSubMenu( "Fog Type", fogMenuID  );
	 glutAddSubMenu("Camera", cameraMenuID);
	glutAddSubMenu( "View", viewMenuid );
    glutAddSubMenu("ViewPort", viewportMenuid);
	glutAddMenuEntry( "Quit", 0 );

	// Attach menu to right mouse button
	glutAttachMenu( GLUT_RIGHT_BUTTON );
	lights.push_back(&ambientLight);
    lights.push_back(&lightPos);
    lights.push_back(&lightDir);
    lights.push_back(&lightSpot);

	// Create main submenu

	// Attach menu to right mouse button
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	// Request that the window be made full screen
	//glutFullScreenToggle();

	color clearColor(0.0, 0.5, 1.0, 1.0);

	// Set red, green, blue, and alpha to which the color buffer is cleared.
	frameBuffer.setClearColor(clearColor);

	// ************* Object vertex coordinate initialization ***********************

	// Set the initial viewing tranformation for the scene
	PerVertex::viewingTransformation = glm::translate(dvec3(0.0, 0.0, -12.0));

	// Enter the GLUT main loop. Control will not return until the window is closed.
	glutMainLoop();

	return 0;

} // end main


