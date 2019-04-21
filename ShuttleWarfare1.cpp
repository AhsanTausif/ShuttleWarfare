#include "iGraphics.h"
#include "Variables.h"
#include "mainmenu.h"
#include "gameplay.h"
#include "enemyFunctions.h"
#include "highScore.h"
/*
	function iDraw() is called again and again by the system.
*/

void appendHighScore()
{
	FILE *fp=fopen("highScoreList.txt","a");

	fprintf(fp,"%s %d\n",inputStr2,score);
	
	fclose(fp);
}

void HSSorting()
{
	FILE *fp=fopen("highScoreList.txt","r");

		for(i=0;i<100;i++)
		{
			fscanf(fp,"%s %d\n",&name[i],&HS[i]);
		}
		fclose(fp);

		for(i=0;i<100;i++)
		{
			for(j=i+1;j<100;j++)
			{
				if(HS[i]<HS[j])
				{
					temp=HS[i];
					HS[i]=HS[j];
					HS[j]=temp;
					strcpy(tempC,name[i]);
					strcpy(name[i],name[j]);
					strcpy(name[j],tempC);
				}
			}
			_itoa_s(HS[i],stringHS[i],10);
		}
}

void inputName(int key)
{
	if(n[25]<=0 || n[90]==22)
	{
		if(key == '\r' )
		{
			strcpy(inputStr2, inputStr1);
			appendHighScore();
			HSSorting();
			for(i = 0; i < len; i++)
				inputStr1[i] = 0;
			len = 0;
			n[25]=12;
			n[0]=1;
			n[1]=0;
			n[90]=0;
			n[15]=0;
			for(i=0;i<22;i++)
			{n[30+i]=0;}
			score=0;
			coOrdinateOfSet();
		}
		else if(key=='\b')
		{
			if(len>0)
			{
				len--;
			}
			inputStr1[len]=0;
		}
		else
		{
			inputStr1[len] = key;
			len++;
		}
	}
}

void iDraw()
{
	//place your drawing codes here
	iClear();

	showMainMenuImage();
	HSshow();
	showingLoadingScreen();
	BGnUserObj();

}

void iMouseMove(int mx, int my)
{
	//place your codes here
}

void iPassiveMouse(int mx, int my)
{
	//place your codes here
	cursorMX=mx;
	cursorMY=my;

	mainMenuHighlightingFunctions(cursorMX,cursorMY);

}

void iMouse(int button, int state, int mx, int my)
{
	clickMX=mx;
	clickMY=my;

	clickFunctionsOfMainMenu(button,state,clickMX,clickMY);

}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	fireBullet(key);

	inputName(key);
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
	controlObj(key);
	

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}

	//place your codes for other keys here
}

int main()
{
	n[0]=1;n[25]=12;
	iInitialize(1350,690,"ShuttleWarfare");


    iSetTimer(300,LoadingScreenTimer);											////////loading screen timer

	loadMainMenuImage();
	loadMainGame();
	
	
	HSSorting();											////////////////////////////Sorts HighScore
	

	iSetTimer(1,EnemyDirection);
	iSetTimer(4000,EnemyBullet);

	coOrdinateOfSet();

 	
	iStart();
	return 0;
}
