// Naufil Moten, 20I-0642, PROJECT CS-B

#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
//#include "Board.h"
#include "util.h"
#include <iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

int val = 0;
int z  = -5;
int u = 1;
int w = 19;
int xco[77];
int yco[77];
int dicerandom = 0;
int c = 0;
int o = 37;
int lock = 0;
int goth = 0;
int F = 0;
int FF = 0;
int unlock = 0;
int unlock1 = 0;
char tt = 'd';

void dice();
void ludoboard();

void dice() {

	dicerandom = rand() % 6 + 1;
	
	//Draw Dice
	DrawSquare( 780 , 685 ,70,colors[WHITE]);
 
	
	switch (dicerandom) {
	
	
	case 1:
	// Draw 1
	DrawCircle(815,720,10,colors[MAROON]);
	break;
	
	case 2:
	// Draw 2
	DrawCircle(800,720,8,colors[MAROON]);
	DrawCircle(830,720,8,colors[MAROON]);
	break;
	
	case 4:
	// Draw 4
	DrawCircle(800,740,8,colors[MAROON]);
	DrawCircle(830,740,8,colors[MAROON]);
	DrawCircle(800,700,8,colors[MAROON]);
	DrawCircle(830,700,8,colors[MAROON]);
	break;
	
	case 3:
	// Draw 3
	DrawCircle(795,720,6,colors[MAROON]);
	DrawCircle(815,720,6,colors[MAROON]);
	DrawCircle(835,720,6,colors[MAROON]); 
	break;
	
	case 5:
	// Draw 5
	DrawCircle(795,735,6,colors[MAROON]);
	DrawCircle(835,735,6,colors[MAROON]);
	DrawCircle(795,705,6,colors[MAROON]);
	DrawCircle(835,705,6,colors[MAROON]);
	DrawCircle(815,720,6,colors[MAROON]); 
	break;
	
	case 6:
	// Draw 6
	DrawCircle(800,740,6,colors[MAROON]);
	DrawCircle(830,740,6,colors[MAROON]);
	DrawCircle(800,720,6,colors[MAROON]);
	DrawCircle(830,720,6,colors[MAROON]);
	DrawCircle(800,700,6,colors[MAROON]);
	DrawCircle(830,700,6,colors[MAROON]);
	break;}	
	
	

	// Intializing first 6 squares
	int st = 25;
	int i;
	
	for (i = 0; i < 6; i++) {
	xco[i] = 325;
	yco[i] = st;
	st = st + 50; 
	}
	
	
	// Intializing next 6-12 squares
	st = 275;
	
	for (i = 6; i < 12; i++) {
	xco[i] = st;
	st = st - 50;
	yco[i] = 325;
	}
	
	
	// Next 6 position
	st = xco[11];
	
	for (i = 12; i < 18; i++) {
	xco[i] = st;
	st = st + 50;
	yco[i] = yco[11] + 50;
	}
	
	// Next 6 position
	st = xco[11];
	
	for (i = 18; i < 24; i++) {
	yco[i] = yco[12] + 50;
	xco[i] = st;
	st = st + 50;
	}
	
	// Next 6 position
	st = yco[23] + 50;
	
	for (i = 24; i < 30; i++) {
	xco[i] = 325;
	yco[i] = st;
	st = st + 50; 
	}
	
	// Next 6 position
	st = yco[29];
	
	for (i = 30; i < 36; i++) {
	xco[i] = 375;
	yco[i] = st;
	st = st - 50;
	}
	
	// Next 6 position
	st = yco[29];
	
	for (i = 36; i < 42; i++) {
	xco[i] = 425;
	yco[i] = st;
	st = st - 50;
	}
	
	// Next 6 position
	st = xco[41] + 50;
	
	for (i = 42; i < 48; i++) {
	xco[i] = st;
	st = st + 50;
	yco[i] = yco[41] - 50;
	}
	
	// Next 6 position
	st = xco[47];
	
	for (i = 48; i < 54; i++) {
	yco[i] = yco[47] - 50;
	xco[i] = st;
	st = st - 50;
	}
	
	
	// Next 6 position
	st = xco[47];
	
	for (i = 54; i < 60; i++) {
	yco[i] = yco [53] - 50;
	xco[i] = st;
	st = st - 50;
	}
	
	
	// Next 6 position
	st = yco[59] - 50;
	
	for (i = 60; i < 66; i++) {
	xco[i] = xco[59] - 50;
	yco[i] = st;
	st =  st - 50;
	} 


	// Next 6 position
	st = yco[65];
	
	
	for (i = 66; i < 72; i++) {
	xco[i] = xco[65] - 50;
	yco[i] = st;
	st = st + 50;
	}
	
	
	if (F == 0) {
	// RED TOKEN MOVING
	
	if ( (dicerandom == 6) && (lock == 0) )  {
	lock = 1;
	dicerandom = 0;
	c = c + 1;
	}
	
	if ( (lock == 1) & (c < 5) ) {
	u = u + dicerandom; 
	
	// Condition to check token doesnt go in any one else house apart from own. 
	if ( ( u > 12 && u < 18) ||  ( u > 30 && u < 36) || ( u > 48 && u < 54) ) {
	u = u + 5; }
	
	if (u > 70) {
	DrawCircle(xco[71],yco[71],17,colors[MAROON]);
	u = 1;
	lock = 0;
	dicerandom = 0;
	if ( c > 4)
	F = 1;
	}
	else 
	DrawCircle(xco[u],yco[u],17,colors[MAROON]);
	}
	
	if (c == 1){
	DrawCircle(100,100,30,colors[RED]);}
	
	if (c == 2){
	DrawCircle(100,100,30,colors[RED]);
	DrawCircle(100,200,30,colors[RED]);}
	
	if (c == 3){
	DrawCircle(100,100,30,colors[RED]);
	DrawCircle(100,200,30,colors[RED]);
	DrawCircle(200,200,30,colors[RED]);}
	
	if (c == 4){
	DrawCircle(200,100,30,colors[RED]);
	DrawCircle(100,100,30,colors[RED]);
	DrawCircle(100,200,30,colors[RED]);
	DrawCircle(200,200,30,colors[RED]);
	} }
	
	// MOVING BLUE TOKEN
	
	
	if (F == 1) {
	DrawCircle(200,100,30,colors[RED]);
	DrawCircle(100,100,30,colors[RED]);
	DrawCircle(100,200,30,colors[RED]);
	DrawCircle(200,200,30,colors[RED]);
	w = 19; 
	goth = 1;}
	
	
	if ( (dicerandom == 6) && (unlock == 0) && (c > 4))  {
	c = c + 1;
	unlock = 1;
	dicerandom = 0;
	}
	
	if (unlock == 1) 
	w = w + dicerandom; 
	
	// Condition to check token doesnt go in any one else house apart from own. 
	if ( ( w > 30 && w < 36) || ( w > 48 && w < 54) || ( w > 64 && w < 72) ) {
	w = w + 5; 
	}
	
	
	if ((w > 65) & (unlock == 1)) {
	z = z + dicerandom;
	DrawCircle(xco[z],yco[z],17,colors[LIGHT_BLUE]);
	}
	else if (unlock == 1)
	DrawCircle(xco[w],yco[w],17,colors[LIGHT_BLUE]);
	
	if (z > 17) {
	DrawCircle(xco[17],yco[17],17,colors[LIGHT_BLUE]);
	F = 2;
	unlock = 0;
	w = 19;
	z = -5;
	FF = FF + 1;}
	
	if (FF == 1){
	DrawCircle(100,555,30,colors[BLUE]);}
	
	if (FF == 2){
	DrawCircle(100,555,30,colors[BLUE]);
	DrawCircle(200,555,30,colors[BLUE]);}
	
	if (FF ==3){
	DrawCircle(100,555,30,colors[BLUE]);
	DrawCircle(200,555,30,colors[BLUE]);
	DrawCircle(100,655,30,colors[BLUE]);}
	
	if (FF ==4){
	DrawCircle(100,555,30,colors[BLUE]);
	DrawCircle(200,555,30,colors[BLUE]);
	DrawCircle(100,655,30,colors[BLUE]);
	DrawCircle(200,655,30,colors[BLUE]);
	F = 2;}
	
	// Yellow Token MOVING
	
	if (F == 2) {
	o = 37; }
	
	
	if ( (dicerandom == 6) && (unlock1 == 0) && (F == 2))  {
	c = c + 1;
	unlock1 = 1;
	dicerandom = 0;
	}
	if (unlock1 == 1) 
	o = o + dicerandom; 
	
	// Condition to check token doesnt go in any one else house apart from own. 
	if ( ( o > 48 && o < 54) || ( o > 64 && o < 72) ) {
	o = o + 5; 
	}
	
	
	if ((o > 65) & (unlock1 == 1)) {
	z = z + dicerandom;
	DrawCircle(xco[z],yco[z],17,colors[LAWN_GREEN]);
	}
	else if (unlock1 == 1)
	DrawCircle(xco[o],yco[o],17,colors[LAWN_GREEN]);
	
	if (z > 35) {
	DrawCircle(xco[35],yco[35],17,colors[LAWN_GREEN]);
	unlock1 = 0;
	w = 19;
	z = -5;
	goth = goth + 1;}
	
	if (goth == 1){
	DrawCircle(555,555,30,colors[ORANGE]);;}
	
	if (goth == 2){
	DrawCircle(555,555,30,colors[ORANGE]);
	DrawCircle(555,655,30,colors[ORANGE]);}
	
	if (goth ==3){
	DrawCircle(555,555,30,colors[ORANGE]);
	DrawCircle(555,655,30,colors[ORANGE]);
	DrawCircle(655,555,30,colors[ORANGE]);}
	
	if (goth ==4){
	DrawCircle(555,555,30,colors[ORANGE]);
	DrawCircle(555,655,30,colors[ORANGE]);
	DrawCircle(655,555,30,colors[ORANGE]);
	DrawCircle(655,655,30,colors[ORANGE]);}
	
	}



void ludoboard() {
	
	//Red Square
	DrawSquare( 0 , 0 ,300,colors[RED]); 
	//Green Square
	DrawSquare( 455 , 0 ,300,colors[GREEN]); 
	//Blue Square
	DrawSquare( 0 , 455 ,300,colors[NAVY]); 
	//Yellow Square
	DrawSquare( 455 , 455 ,300,colors[ORANGE]); 
	//Middle Square
	DrawSquare( 300 , 300 ,155,colors[WHITE]); 
	//Display Score
	
	
	//Red Triangle
	DrawTriangle( 300, 300 , 455, 300 , 377.5 , 377.5, colors[RED] );
	//Blue Triangle
	DrawTriangle( 300, 300 , 300, 455 , 377.5 , 377.5, colors[NAVY] );
	//Yellow Triangle
	DrawTriangle( 300, 455 , 455, 455 , 377.5 , 377.5, colors[ORANGE] );
	//Green Triangle
	DrawTriangle( 455, 300 , 455, 455 , 377.5 , 377.5, colors[GREEN] );
	
	
	// Blue White Square 1
	DrawSquare( 0 , 300 ,49.5,colors[WHITE]);
	DrawSquare( 50 , 300 ,49.5,colors[WHITE]);
	DrawSquare( 100 , 300 ,49.5,colors[GRAY]);
	DrawSquare( 150 , 300 ,49.5,colors[WHITE]);
	DrawSquare( 200 , 300 ,49.5,colors[WHITE]);
	DrawSquare( 250 , 300 ,49.5,colors[WHITE]);
	
	// Blue White Square 2
	DrawSquare( 0 , 353 ,49.5,colors[WHITE]);
	DrawSquare( 50 , 353 ,49.5,colors[NAVY]);
	DrawSquare( 100 , 353 ,49.5,colors[NAVY]);
	DrawSquare( 150 , 353,49.5,colors[NAVY]);
	DrawSquare( 200 , 353 ,49.5,colors[NAVY]);
	DrawSquare( 250 , 353 ,49.5,colors[NAVY]);
	
	// Blue White Square 3
	DrawSquare( 0 , 406 ,49.5,colors[WHITE]);
	DrawSquare( 50 , 406 ,49.5,colors[NAVY]);
	DrawSquare( 100 , 406 ,49.5,colors[WHITE]);
	DrawSquare( 150 , 406 ,49.5,colors[WHITE]);
	DrawSquare( 200 , 406 ,49.5,colors[WHITE]);
	DrawSquare( 250 , 406 ,49.5,colors[WHITE]);
	
	
	// Red White Square 1
	DrawSquare( 300 , 0 ,49.5,colors[WHITE]);
	DrawSquare( 300 , 50 ,49.5,colors[RED]);
	DrawSquare( 300 , 100 ,49.5,colors[WHITE]);
	DrawSquare( 300 , 150 ,49.5,colors[WHITE]);
	DrawSquare( 300 , 200 ,49.5,colors[WHITE]);
	DrawSquare( 300 , 250 ,49.5,colors[WHITE]);
	
	// Red White Square 2
	DrawSquare( 353 , 0 ,49.5,colors[WHITE]);
	DrawSquare( 353 , 50 ,49.5,colors[RED]);
	DrawSquare( 353 , 100 ,49.5,colors[RED]);
	DrawSquare( 353 , 150 ,49.5,colors[RED]);
	DrawSquare( 353 , 200 ,49.5,colors[RED]);
	DrawSquare( 353 , 250 ,49.5,colors[RED]);
	
	// Red White Square 3
	DrawSquare( 406 , 0 ,49.5,colors[WHITE]);
	DrawSquare( 406 , 50 ,49.5,colors[WHITE]);
	DrawSquare( 406 , 100 ,49.5,colors[GRAY]);
	DrawSquare( 406 , 150 ,49.5,colors[WHITE]);
	DrawSquare( 406 , 200 ,49.5,colors[WHITE]);
	DrawSquare( 406 , 250 ,49.5,colors[WHITE]);
	
	// Green White Square 1
	DrawSquare( 455 , 300 ,49.5,colors[WHITE]);
	DrawSquare( 505 , 300 ,49.5,colors[WHITE]);
	DrawSquare( 555 , 300 ,49.5,colors[WHITE]);
	DrawSquare( 605 , 300 ,49.5,colors[WHITE]);
	DrawSquare( 655 , 300 ,49.5,colors[GREEN]);
	DrawSquare( 705 , 300 ,49.5,colors[WHITE]);
	
	// Green White Square 2
	DrawSquare( 455 , 353 ,49.5,colors[GREEN]);
	DrawSquare( 505 , 353 ,49.5,colors[GREEN]);
	DrawSquare( 555 , 353 ,49.5,colors[GREEN]);
	DrawSquare( 605 , 353 ,49.5,colors[GREEN]);
	DrawSquare( 655 , 353 ,49.5,colors[GREEN]);
	DrawSquare( 705 , 353 ,49.5,colors[WHITE]);
	
	// Green White Square 3
	DrawSquare( 455 , 406 ,49.5,colors[WHITE]);
	DrawSquare( 505 , 406 ,49.5,colors[WHITE]);
	DrawSquare( 555 , 406 ,49.5,colors[WHITE]);
	DrawSquare( 605 , 406 ,49.5,colors[GRAY]);
	DrawSquare( 655 , 406 ,49.5,colors[WHITE]);
	DrawSquare( 705 , 406 ,49.5,colors[WHITE]);
	
	// Yellow White Square 1
	DrawSquare( 300 , 455 ,49.5,colors[WHITE]);
	DrawSquare( 300 , 505 ,49.5,colors[WHITE]);
	DrawSquare( 300 , 555 ,49.5,colors[WHITE]);
	DrawSquare( 300 , 605 ,49.5,colors[GRAY]);
	DrawSquare( 300 , 655 ,49.5,colors[WHITE]);
	DrawSquare( 300 , 705 ,49.5,colors[WHITE]);
	
	// Yellow White Square 2
	DrawSquare( 353 , 455 ,49.5,colors[ORANGE]);
	DrawSquare( 353 , 505 ,49.5,colors[ORANGE]);
	DrawSquare( 353 , 555 ,49.5,colors[ORANGE]);
	DrawSquare( 353 , 605 ,49.5,colors[ORANGE]);
	DrawSquare( 353 , 655 ,49.5,colors[ORANGE]);
	DrawSquare( 353 , 705 ,49.5,colors[WHITE]);
	
	// Yellow White Square 3
	DrawSquare( 406 , 455 ,49.5,colors[WHITE]);
	DrawSquare( 406 , 505 ,49.5,colors[WHITE]);
	DrawSquare( 406 , 555 ,49.5,colors[WHITE]);
	DrawSquare( 406 , 605 ,49.5,colors[WHITE]);
	DrawSquare( 406 , 655 ,49.5,colors[ORANGE]);
	DrawSquare( 406 , 705 ,49.5,colors[WHITE]);
	
	
	
	 
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)


	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	//DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );	
	
	DrawCircle(150,150,120,colors[WHITE]);
	DrawCircle(150,605,120,colors[WHITE]);
	DrawCircle(605,150,120,colors[WHITE]);
	DrawCircle(605,605,120,colors[WHITE]);
	//DrawCircle(70,670,10,colors[RED]);
	//DrawCircle(90,670,10,colors[RED]);

	// Draw Circle Red
	DrawCircle(100,100,30,colors[RED]);
	DrawCircle(100,200,30,colors[RED]);
	DrawCircle(200,100,30,colors[RED]);
	DrawCircle(200,200,30,colors[RED]);
	
	// Draw Token Red
	DrawCircle(100,100,20,colors[MAROON]);
	DrawCircle(100,200,20,colors[MAROON]);
	DrawCircle(200,100,20,colors[MAROON]);
	DrawCircle(200,200,20,colors[MAROON]);
	
	// Draw Circle Green
	DrawCircle(555,100,30,colors[GREEN]);
	DrawCircle(555,200,30,colors[GREEN]);
	DrawCircle(655,100,30,colors[GREEN]);
	DrawCircle(655,200,30,colors[GREEN]);
	
	// Draw Token Green
	DrawCircle(555,100,20,colors[LAWN_GREEN]);
	DrawCircle(555,200,20,colors[LAWN_GREEN]);
	DrawCircle(655,100,20,colors[LAWN_GREEN]);
	DrawCircle(655,200,20,colors[LAWN_GREEN]);
	
	// Draw Circle Blue
	DrawCircle(100,555,30,colors[BLUE]);
	DrawCircle(200,555,30,colors[BLUE]);
	DrawCircle(100,655,30,colors[BLUE]);
	DrawCircle(200,655,30,colors[BLUE]);
	
	// Draw Token Blue
	DrawCircle(100,555,20,colors[MIDNIGHT_BLUE]);
	DrawCircle(200,555,20,colors[MIDNIGHT_BLUE]);
	DrawCircle(100,655,20,colors[MIDNIGHT_BLUE]);
	DrawCircle(200,655,20,colors[MIDNIGHT_BLUE]);
	
	// Draw Circle Yellow
	DrawCircle(555,555,30,colors[ORANGE]);
	DrawCircle(555,655,30,colors[ORANGE]);
	DrawCircle(655,555,30,colors[ORANGE]);
	DrawCircle(655,655,30,colors[ORANGE]);
	
	// Draw Token Yellow
	DrawCircle(555,555,20,colors[DARK_ORANGE]);
	DrawCircle(555,655,20,colors[DARK_ORANGE]);
	DrawCircle(655,555,20,colors[DARK_ORANGE]);
	DrawCircle(655,655,20,colors[DARK_ORANGE]);
	
	
	
	 
	
	
}

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}


/*
 * Main Canvas drawing function.
 * */
//Board *b;
void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	
	
	if (val == 0)
	DrawString( 0, 750, "WELCOME TO LUDO", colors[WHITE]); 
	DrawString( 0, 650, "How many players are going to play the game?", colors[WHITE]); 
	DrawString( 0, 400, " 2", colors[WHITE]); 
	DrawString( 0, 350, " 3", colors[WHITE]); 
	DrawString( 0, 300, " 4", colors[WHITE]); 
	
	if (val == 1){	
	ludoboard();
	}
	
	if (tt == 's'){	
	dice();
	tt = 'd';
	}
	
	glutSwapBuffers(); // do not modify this line..

}


/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {

	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {

	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {

	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	
	if (key == 27/* Escape key ASCII*/) {
		
		exit(1); // exit the program when escape key is pressed.
	}
	
	 if (key == 32 ) {
		
		tt = 's'; // Roll the dice when Spacebar is pressed.
	}
	

	if (key == 'a' || key == 'A') //Key for placing the bomb
			{
		//do something if b is pressed
		val =1;

	}
	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000.0, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	//cout << x << " " << y << endl;
	//glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	// glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
 /* void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{

	}
	glutPostRedisplay(); 
} */



/* void move {
	int x;
	if (x = 6)
	
	int array[x][y];
	
	for 
	
} 	


/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {


	//b = new Board(60, 60); // create a new board object to use in the Display Function ...

	int width = 1020, height = 840; // i have set my window size to be 800 x 600
	//b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("PF Project"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	
	
	
	// Asking No. of players who will play the game
	int players;
	string player1, player2, player3, player4;
	
	do {
	
	cout << "How many players are going to play the game? (2-4) ";
	cin >> players;
	
	switch (players) {
	
	case 1:
	cout << "Less than 2 players cannot play the game" << endl;
	break;
	
	case 2: // Asking for names of 2 players
	
	cout << "Enter name of player 1: ";
	cin >> player1;
	cout << "Enter name of player 2: ";
	cin >> player2;
	break;
	
	case 3: // Asking for names of 3 players
	
	cout << "Enter name of player 1: ";
	cin >> player1;
	cout << "Enter name of player 2: ";
	cin >> player2;
	cout << "Enter name of player 3: ";
	cin >> player3;
	break;
	
	case 4: // Asking for names of 4 players
	
	cout << "Enter name of player 1: ";
	cin >> player1;
	cout << "Enter name of player 2: ";
	cin >> player2;
	cout << "Enter name of player 3: ";
	cin >> player3;
	cout << "Enter name of player 4: ";
	cin >> player4;
	break;
	
	default:
	cout << "ENTER VALID NO. OF PLAYERS!!" << endl;
	break;}
	
	} 
	
	while (players > 4 || players < 2);
	
	int colors, select1, select2, select3, select4; // declaration for colors selection for each player in the game
	string player1_color,player2_color,player3_color,player4_color;
	
	cout << "How do you want to assign colors?" << endl;
	cout << "1. Assign randomly" << endl;
	cout << "2. Select yourself" << endl;
	
	cin >> colors;
	
	switch (colors) {
	
	case 1:
	srand (time(NULL));
	
	if (players == 2) {
	
	select1 = rand() % 4 + 1;
	
	do {
	select2 = rand() % 4 + 1;}
	while (select2 == select1);
	
	if (select1 == 1) {
	player1_color = "RED";
	cout << player1 << " has been assigned " << player1_color << endl;}
	else if (select1 == 2){
	player1_color = "BLUE";
	cout << player1 << " has been assigned " << player1_color << endl;}
	else if (select1 == 3){
	player1_color = "YELLOW";
	cout << player1 << " has been assigned " << player1_color << endl;}
	else if (select1 == 4){
	player1_color = "GREEN";
	cout << player1 << " has been assigned " << player1_color << endl;}
	
	if (select2 == 1){
	player2_color = "RED";
	cout << player2 << " has been assigned " << player2_color << endl;}
	else if (select2 == 2){
	player2_color = "BLUE";
	cout << player2 << " has been assigned " << player2_color << endl;}
	else if (select2 == 3){
	player2_color = "YELLOW";
	cout << player2 << " has been assigned " << player2_color << endl;}
	else if (select2 == 4){
	player2_color = "GREEN";
	cout << player2 << " has been assigned " << player2_color << endl;}}
	
	if (players == 3) {
	
	select1 = rand() % 4 + 1;
	
	do {
	select2 = rand() % 4 + 1;}
	while (select2 == select1);
	
	do {
	select3 = rand() % 4 + 1;}
	while (select3 == select1 || select3 == select2);
	
	if (select1 == 1) {
	player1_color = "RED";
	cout << player1 << " has been assigned " << player1_color << endl;}
	else if (select1 == 2){
	player1_color = "BLUE";
	cout << player1 << " has been assigned " << player1_color << endl;}
	else if (select1 == 3){
	player1_color = "YELLOW";
	cout << player1 << " has been assigned " << player1_color << endl;}
	else if (select1 == 4){
	player1_color = "GREEN";
	cout << player1 << " has been assigned " << player1_color << endl;}
	
	if (select2 == 1){
	player2_color = "RED";
	cout << player2 << " has been assigned " << player2_color << endl;}
	else if (select2 == 2){
	player2_color = "BLUE";
	cout << player2 << " has been assigned " << player2_color << endl;}
	else if (select2 == 3){
	player2_color = "YELLOW";
	cout << player2 << " has been assigned " << player2_color << endl;}
	else if (select2 == 4){
	player2_color = "GREEN";
	cout << player2 << " has been assigned " << player2_color << endl;}
	
	if (select3 == 1){
	player3_color = "RED";
	cout << player3 << " has been assigned " << player3_color << endl;}
	else if (select3 == 2){
	player3_color = "BLUE";
	cout << player3 << " has been assigned " << player3_color << endl;}
	else if (select3 == 3){
	player3_color = "YELLOW";
	cout << player3 << " has been assigned " << player3_color << endl;}
	else if (select3 == 4){
	player3_color = "GREEN";
	cout << player3 << " has been assigned " << player3_color << endl;}}
	
	if (players == 4) {
	
	select1 = rand() % 4 + 1;
	
	do {
	select2 = rand() % 4 + 1;}
	while (select2 == select1);
	
	do {
	select3 = rand() % 4 + 1;}
	while (select3 == select1 || select3 == select2);
	
	do {
	select4 = rand() % 4 + 1;}
	while (select4 == select1 || select4 == select2 || select4 == select3);
	
	if (select1 == 1) {
	player1_color = "RED";
	cout << player1 << " has been assigned " << player1_color << endl;}
	else if (select1 == 2){
	player1_color = "BLUE";
	cout << player1 << " has been assigned " << player1_color << endl;}
	else if (select1 == 3){
	player1_color = "YELLOW";
	cout << player1 << " has been assigned " << player1_color << endl;}
	else if (select1 == 4){
	player1_color = "GREEN";
	cout << player1 << " has been assigned " << player1_color << endl;}
	
	if (select2 == 1){
	player2_color = "RED";
	cout << player2 << " has been assigned " << player2_color << endl;}
	else if (select2 == 2){
	player2_color = "BLUE";
	cout << player2 << " has been assigned " << player2_color << endl;}
	else if (select2 == 3){
	player2_color = "YELLOW";
	cout << player2 << " has been assigned " << player2_color << endl;}
	else if (select2 == 4){
	player2_color = "GREEN";
	cout << player2 << " has been assigned " << player2_color << endl;}
	
	if (select3 == 1){
	player3_color = "RED";
	cout << player3 << " has been assigned " << player3_color << endl;}
	else if (select3 == 2){
	player3_color = "BLUE";
	cout << player3 << " has been assigned " << player3_color << endl;}
	else if (select3 == 3){
	player3_color = "YELLOW";
	cout << player3 << " has been assigned " << player3_color << endl;}
	else if (select3 == 4){
	player3_color = "GREEN";
	cout << player3 << " has been assigned " << player3_color << endl;}
	
	if (select4 == 1){
	player4_color = "RED";
	cout << player4 << " has been assigned " << player4_color << endl;}
	else if (select4 == 2){
	player4_color = "BLUE";
	cout << player4 << " has been assigned " << player4_color << endl;}
	else if (select4 == 3){
	player4_color = "YELLOW";
	cout << player4 << " has been assigned " << player4_color << endl;}
	else if (select4 == 4){
	player4_color = "GREEN";
	cout << player4 << " has been assigned " << player4_color << endl;}
	
	}
	
	break;
	
	
	
	case 2: // Players picking color for themselves
	if (players == 2) {
	cout << "Choose color for player 1" << endl;
	cout << "1. RED \n2. BLUE \n3. YELLOW \n4. GREEN" << endl;
	cin >> select1;
	
	do {
	cout << "Choose color for player 2" << endl;
	cout << "1. RED \n2. BLUE \n3. YELLOW \n4. GREEN" << endl;
	cin >> select2;
	
	if (select2 ==  select1 || select2 < 1 || select2 > 4)
	cout << "This color is already selected by another player or invalid option" << endl; // Check if color is already picked by another player or not
	
	} while (select2 == select1 || select2 < 1 || select2 > 4); // Loop Until Valid option
	
	if (select1 == 1) {  
	player1_color = "RED";
	cout << player1 << " has been assigned " << player1_color << endl;}  // Display the colors that has been choosed
	else if (select1 == 2){
	player1_color = "BLUE";
	cout << player1 << " has been assigned " << player1_color << endl;}
	else if (select1 == 3){
	player1_color = "YELLOW";
	cout << player1 << " has been assigned " << player1_color << endl;}
	else if (select1 == 4){
	player1_color = "GREEN";
	cout << player1 << " has been assigned " << player1_color << endl;}
	
	if (select2 == 1){
	player2_color = "RED";
	cout << player2 << " has been assigned " << player2_color << endl;}
	else if (select2 == 2){
	player2_color = "BLUE";
	cout << player2 << " has been assigned " << player2_color << endl;}
	else if (select2 == 3){
	player2_color = "YELLOW";
	cout << player2 << " has been assigned " << player2_color << endl;}
	else if (select2 == 4){
	player2_color = "GREEN";
	cout << player2 << " has been assigned " << player2_color << endl;} } 
	
	
	
	else if (players == 3) {
	cout << "Choose color for player 1" << endl;
	cout << "1. RED \n2. BLUE \n3. YELLOW \n4. GREEN" << endl;
	cin >> select1;
	
	do {
	cout << "Choose color for player 2" << endl;
	cout << "1. RED \n2. BLUE \n3. YELLOW \n4. GREEN" << endl;
	cin >> select2;
	
	if (select2 ==  select1 || select2 < 1 || select2 > 4)
	cout << "This color is already selected by another player or invalid option" << endl;
	} while (select2 == select1 || select2 < 1 || select2 > 4);
	
	do {
	cout << "Choose color for player 3" << endl;
	cout << "1. RED \n2. BLUE \n3. YELLOW \n4. GREEN" << endl;
	cin >> select3;
	
	if (select3 == select1 || select3 == select2 || select3 < 1 || select3 > 4)
	cout << "This color is already selected by another player or invalid option" << endl;}
	while (select3 == select1 || select3 == select2 || select3 < 1 || select3 > 4); 
	
		if (select1 == 1) {
	player1_color = "RED";
	cout << player1 << " has been assigned " << player1_color << endl;}
	else if (select1 == 2){
	player1_color = "BLUE";
	cout << player1 << " has been assigned " << player1_color << endl;}
	else if (select1 == 3){
	player1_color = "YELLOW";
	cout << player1 << " has been assigned " << player1_color << endl;}
	else if (select1 == 4){
	player1_color = "GREEN";
	cout << player1 << " has been assigned " << player1_color << endl;}
	
	if (select2 == 1){
	player2_color = "RED";
	cout << player2 << " has been assigned " << player2_color << endl;}
	else if (select2 == 2){
	player2_color = "BLUE";
	cout << player2 << " has been assigned " << player2_color << endl;}
	else if (select2 == 3){
	player2_color = "YELLOW";
	cout << player2 << " has been assigned " << player2_color << endl;}
	else if (select2 == 4){
	player2_color = "GREEN";
	cout << player2 << " has been assigned " << player2_color << endl;}
	
	if (select3 == 1){
	player3_color = "RED";
	cout << player3 << " has been assigned " << player3_color << endl;}
	else if (select3 == 2){
	player3_color = "BLUE";
	cout << player3 << " has been assigned " << player3_color << endl;}
	else if (select3 == 3){
	player3_color = "YELLOW";
	cout << player3 << " has been assigned " << player3_color << endl;}
	else if (select3 == 4){
	player3_color = "GREEN";
	cout << player3 << " has been assigned " << player3_color << endl;}
	
	}
	
	
	
	else if (players == 4) {
	cout << "Choose color for player 1" << endl;
	cout << "1. RED \n2. BLUE \n3. YELLOW \n4. GREEN" << endl;
	cin >> select1;
	
	do {
	cout << "Choose color for player 2" << endl;
	cout << "1. RED \n2. BLUE \n3. YELLOW \n4. GREEN" << endl;
	cin >> select2;
	
	if (select2 ==  select1 || select2 < 1 || select2 > 4)
	cout << "This color is already selected by another player or invalid option" << endl;
	} while (select2 == select1 || select2 < 1 || select2 > 4);
	
	do {
	cout << "Choose color for player 3" << endl;
	cout << "1. RED \n2. BLUE \n3. YELLOW \n4. GREEN" << endl;
	cin >> select3;
	
	if (select3 == select1 || select3 == select2 || select3 < 1 || select3 > 4)
	cout << "This color is already selected by another player or invalid option" << endl;}
	while (select3 == select1 || select3 == select2 || select3 < 1 || select3 > 4);
	
	do {
	cout << "Choose color for player 4" << endl;
	cout << "1. RED \n2. BLUE \n3. YELLOW \n4. GREEN" << endl;
	cin >> select4;
	
	if (select4 == select1 || select4 == select2 || select4 == select3 || select4 < 1 || select4 > 4)
	cout << "This color is already selected by another player or invalid option" << endl;}
	while (select4 == select1 || select4 == select2 || select4 == select3 || select4 < 1 || select4 > 4 );
	
		if (select1 == 1) {
	player1_color = "RED";
	cout << player1 << " has been assigned " << player1_color << endl;}
	else if (select1 == 2){
	player1_color = "BLUE";
	cout << player1 << " has been assigned " << player1_color << endl;}
	else if (select1 == 3){
	player1_color = "YELLOW";
	cout << player1 << " has been assigned " << player1_color << endl;}
	else if (select1 == 4){
	player1_color = "GREEN";
	cout << player1 << " has been assigned " << player1_color << endl;}
	
	if (select2 == 1){
	player2_color = "RED";
	cout << player2 << " has been assigned " << player2_color << endl;}
	else if (select2 == 2){
	player2_color = "BLUE";
	cout << player2 << " has been assigned " << player2_color << endl;}
	else if (select2 == 3){
	player2_color = "YELLOW";
	cout << player2 << " has been assigned " << player2_color << endl;}
	else if (select2 == 4){
	player2_color = "GREEN";
	cout << player2 << " has been assigned " << player2_color << endl;}
	
	if (select3 == 1){
	player3_color = "RED";
	cout << player3 << " has been assigned " << player3_color << endl;}
	else if (select3 == 2){
	player3_color = "BLUE";
	cout << player3 << " has been assigned " << player3_color << endl;}
	else if (select3 == 3){
	player3_color = "YELLOW";
	cout << player3 << " has been assigned " << player3_color << endl;}
	else if (select3 == 4){
	player3_color = "GREEN";
	cout << player3 << " has been assigned " << player3_color << endl;}
	
	if (select4 == 1){
	player4_color = "RED";
	cout << player4 << " has been assigned " << player4_color << endl;}
	else if (select4 == 2){
	player4_color = "BLUE";
	cout << player4 << " has been assigned " << player4_color << endl;}
	else if (select4 == 3){
	player4_color = "YELLOW";
	cout << player4 << " has been assigned " << player4_color << endl;}
	else if (select4 == 4){
	player4_color = "GREEN";
	cout << player4 << " has been assigned " << player4_color << endl;}
	
	}} 
	
	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	// glutMouseFunc(MouseClicked);
	// glutPassiveMotionFunc(MouseMoved); // Mouse
	// glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
