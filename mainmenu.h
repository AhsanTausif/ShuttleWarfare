#ifndef MAINMENU_H_INCLUDED
#define MAINMENU_H_INCLUDED
#include"Variables.h"
void loadMainMenuImage()
{
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
	image[12]=iLoadImage("images\\HighScoreBGextra.jpg");
	image[13]=iLoadImage("images\\InstructionBG.jpg");
	image[14]=iLoadImage("images\\AboutBG.jpg");
	image[31]=iLoadImage("images\\backButton.png");
	//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
}

void mainMenuHighlightingFunctions(int cursorMX,int cursorMY)
{

	//::::::::::::::::::::::::::::::::::HIGHLIGHTING FUNCTIONS::::::::::::::::::::::::::::::::::::
	if(cursorMX>=100 && cursorMX<=400 && cursorMY>=410 && cursorMY<=470)///////////////////////////////////start button flags
	{n[2]=1;}
	else
	{n[2]=0;}

	if(cursorMX>=100 && cursorMX<=400 && cursorMY>=350 && cursorMY<=410)///////////////////////////////////high score button flags
	{n[4]=1;}
	else
	{n[4]=0;}

	if(cursorMX>=100 && cursorMX<=400 && cursorMY>=290 && cursorMY<=350)///////////////////////////////////instruction button flags
	{n[6]=1;}
	else
	{n[6]=0;}

	if(cursorMX>=100 && cursorMX<=400 && cursorMY>=230 && cursorMY<=290)///////////////////////////////////about button flags
	{n[8]=1;}
	else
	{n[8]=0;}

	if(cursorMX>=100 && cursorMX<=400 && cursorMY>=170 && cursorMY<=230)//////////////////////////////////exit button flags
	{n[10]=1;}
	else
	{n[10]=0;}
	//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
}

void showMainMenuImage()
{
    	//:::::::::::::::::::::::::::::::::::::::::::::::::: MAIN MENU::::::::::::::::::::::::::::::::::::::

	if(n[0])
	{
	iShowImage(0,0,1350,690,image[0]);													////main menu background pic
	iShowImage(100,500,1100,100,image[1]);												////title pic
	iShowImage(100,410,300,60,image[2]);												////start button
	if(n[2])
	{
		iShowImage(100,410,300,60,image[3]);///////////////////////////////////////////////start button highlighted
	}
	iShowImage(100,350,300,60,image[4]);//////////////////////////////////////////////////high score button
	if(n[4])
	{
		iShowImage(100,350,300,60,image[5]);//////////////////////////////////////////////high score button highlighted
	}
	iShowImage(100,290,300,60,image[6]);//////////////////////////////////////////////////instruction button
	if(n[6])
	{
		iShowImage(100,290,300,60,image[7]);/////////////////////////////////////////////instruction button highlighted
	}
	
	iShowImage(100,230,300,60,image[8]);/////////////////////////////////////////////////about button
	if(n[8])
	{
		iShowImage(100,230,300,60,image[9]);////////////////////////////////////////////about button highlighted
	}
	iShowImage(100,170,300,60,image[10]);////////////////////////////////////////////////exit button
	if(n[10])
	{
		iShowImage(100,170,300,60,image[11]);////////////////////////////////////////////exit button highlighted
	}

	}


	if(n[5])
	{
		iShowImage(0,0,1350,690,image[12]);//////////////////////////////////////////////high score background pic
		iShowImage(10,650,80,30,image[31]);///////////back button
	}
	if(n[7])
	{
		iShowImage(0,0,1350,690,image[13]);//////////////////////////////////////////////instruction background pic
		iShowImage(10,650,80,30,image[31]);///////////back button
	}
	if(n[9])
	{
		iShowImage(0,0,1350,690,image[14]);////////////////////////////////////////////// about background pic
		iShowImage(10,650,80,30,image[31]);///////////back button
	}
	//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
}

void clickFunctionsOfMainMenu(int button, int state, int clickMX, int clickMY)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_UP && clickMX>=100 && clickMX<=400 && clickMY>=410 && clickMY<=470 && n[0])
	{
		n[1]=1;
		n[13]=1;															/////////start button function
		n[0]=0;
	}
	
	if(button == GLUT_LEFT_BUTTON && state == GLUT_UP && clickMX>=100 && clickMX<=400 && clickMY>=350 && clickMY<=410 && n[0])
	{
		n[5]=1;
		n[0]=0;																////////high score button function
	}
	if(button == GLUT_LEFT_BUTTON && state == GLUT_UP && clickMX>=100 && clickMX<=400 && clickMY>=290 && clickMY<=350 && n[0])
	{
		n[7]=1;
		n[0]=0;																/////// instruction button function
	}
	if(button == GLUT_LEFT_BUTTON && state == GLUT_UP && clickMX>=100 && clickMX<=400 && clickMY>=230 && clickMY<=290 && n[0])
	{
		n[9]=1;
		n[0]=0;																//////// about button function
	}
	if(button == GLUT_LEFT_BUTTON && state == GLUT_UP && clickMX>=100 && clickMX<=400 && clickMY>=170 && clickMY<=230 && n[0])
	{
		exit(0);															///////// exit button function
	}
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && !n[0] && n[1]==0 && clickMX>=10 && clickMX<=90 && clickMY>=650 && clickMY<=680)
	{
		n[1]=0;
		n[5]=0;																///////// previous function
		n[7]=0;
		n[9]=0;
		n[0]=1;
	}
}

#endif // MAINMENU_H_INCLUDED
