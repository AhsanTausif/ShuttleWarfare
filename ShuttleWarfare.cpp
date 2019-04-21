# include "iGraphics.h"
int image[100];
int i,n[100];
int cursorMX,cursorMY;
int dragMX,dragMY;
int clickMX,clickMY;
/*
	function iDraw() is called again and again by the system.
*/


void iDraw()
{
	//place your drawing codes here
	iClear();
	//:::::::::::::::::::::::::::::::::::::::::::::::::: MAIN MENU::::::::::::::::::::::::::::::::::::::
	iShowImage(0,0,1350,690,image[0]);
	iShowImage(100,500,1100,100,image[1]);
	iShowImage(100,410,300,60,image[2]);
	if(n[2])
	{
		iShowImage(100,410,300,60,image[3]);
	}
	iShowImage(100,350,300,60,image[4]);
	if(n[4])
	{
		iShowImage(100,350,300,60,image[5]);
	}
	iShowImage(100,290,300,60,image[6]);
	if(n[6])
	{
		iShowImage(100,290,300,60,image[7]);
	}
	iShowImage(100,230,300,60,image[8]);
	if(n[8])
	{
		iShowImage(100,230,300,60,image[9]);
	}
	iShowImage(100,170,300,60,image[10]);
	if(n[10])
	{
		iShowImage(100,170,300,60,image[11]);
	}
	//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

void iPassiveMouse(int mx, int my)
{
	//place your codes here
	cursorMX=mx;
	cursorMY=my;

	//::::::::::::::::::::::::::::::::::HIGHLIGHTING FUNCTIONS::::::::::::::::::::::::::::::::::::
	if(cursorMX>=100 && cursorMX<=400 && cursorMY>=410 && cursorMY<=470)
	{n[2]=1;}
	else
	{n[2]=0;}

	if(cursorMX>=100 && cursorMX<=400 && cursorMY>=350 && cursorMY<=410)
	{n[4]=1;}
	else
	{n[4]=0;}

	if(cursorMX>=100 && cursorMX<=400 && cursorMY>=290 && cursorMY<=350)
	{n[6]=1;}
	else
	{n[6]=0;}

	if(cursorMX>=100 && cursorMX<=400 && cursorMY>=230 && cursorMY<=290)
	{n[8]=1;}
	else
	{n[8]=0;}

	if(cursorMX>=100 && cursorMX<=400 && cursorMY>=170 && cursorMY<=230)
	{n[10]=1;}
	else
	{n[10]=0;}
	//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

}


/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	clickMX=mx;
	clickMY=my;

	if(button == GLUT_LEFT_BUTTON && state == GLUT_UP && clickMX>=100 && clickMX<=400 && clickMY>=170 && clickMY<=230)
	{
		exit(0);
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	
	//place your codes for other keys here
}

int main()
{
	iInitialize(1350,690,"ShuttleWarfare");

	//:::::::::::::::::::::::::::::::::::::::::::::LOADING IMAGES OF MAINMENU::::::::::::::::::::::::::::::::::::::::::::::
	image[0]=iLoadImage("images\\MainMenu.jpg");
	image[1]=iLoadImage("images\\ShuttleWarfare.png");
	image[2]=iLoadImage("images\\StartGame.png");
	image[3]=iLoadImage("images\\StartGameH.png");
	image[4]=iLoadImage("images\\HighScores.png");
	image[5]=iLoadImage("images\\HighScoresH.png");
	image[6]=iLoadImage("images\\Instructions.png");
	image[7]=iLoadImage("images\\InstructionsH.png");
	image[8]=iLoadImage("images\\About.png");
	image[9]=iLoadImage("images\\AboutH.png");
	image[10]=iLoadImage("images\\Exit.png");
	image[11]=iLoadImage("images\\ExitH.png");
	//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

	iStart();
	return 0;
}

