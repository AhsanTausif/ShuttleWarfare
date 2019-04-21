#ifndef GAMEPLAY_H_INCLUDED
#define GAMEPLAY_H_INCLUDED
#include "Variables.h"


void LoadingScreenTimer(){
	n[13]+=1;
}

void loadMainGame(){//////////////////////////////////////////////////////////////gameplay images

	image[15]=iLoadImage("images\\LoadingImage.jpg");
	image[16]=iLoadImage("images\\movingBackground.jpg");
	image[17]=iLoadImage("images\\userObj.png");
	image[18]=iLoadImage("images\\bullet.png");
	image[20]=iLoadImage("images\\enemy1.png");
	image[21]=iLoadImage("images\\enemy5.png");
	image[22]=iLoadImage("images\\enemy2.png");
	image[23]=iLoadImage("images\\explosion.png");
	image[24]=iLoadImage("images\\background.png");
	image[25]=iLoadImage("images\\bullet2.png");
	image[26]=iLoadImage("images\\background.jpg");
	image[30]=iLoadImage("images\\gameOver.jpg");
}


void showingLoadingScreen()
{
	if(n[13]<5 && n[13]>=1 && n[0]==0 && n[1])
	{
		iShowImage(0,0,1350,690,image[15]);    //loading background
		iSetColor(40,20,255);
		iRectangle(30,30,1300,30);             //
		if(n[13]==2)                           //
		{iFilledRectangle(30,30,450,30);}      //
		if(n[13]==3)                           //loading bars
		{iFilledRectangle(30,30,900,30);}      //
		if(n[13]==4)                           //
		{iFilledRectangle(30,30,1300,30);}     //
	}
}

void BGnUserObj(){

	if(n[13]>=5 && n[0]==0 && n[1])
	{
		//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::LEVEL 1 :::::::::::::::::::
		if(n[90]>=0 && n[90]<4 && n[25]>0){
		iShowImage(bgMX[0],bgMY[0]-=1,1350,690,image[16]);								//
		iShowImage(bgMX[1],bgMY[1]-=1,1350,690,image[16]);								//
		if(bgMY[1]==0)																	//moving background 1
		{bgMY[0]=0;bgMY[1]=690;}														//


		iSetColor(0,0,0);
		iFilledRectangle(0,660,110,30);
		iSetColor(255,255,255);
		iText(8,670,"LEVEL 1",GLUT_BITMAP_TIMES_ROMAN_24);/////////////////////////////////////////////Level Text

		iSetColor(0,0,0);
		iFilledRectangle(1100,660,260,30);
		iSetColor(255,255,255);
		iText(1110,670,"SCORE:",GLUT_BITMAP_TIMES_ROMAN_24);//////////////////////////////////////Score Text
		iText(1290,670,showScore,GLUT_BITMAP_TIMES_ROMAN_24);//////////////shjowing score

		iSetColor(0,0,0);
		iFilledRectangle(990,0,370,30);
		iSetColor(255,255,255);
		iText(995,8,"HP",GLUT_BITMAP_TIMES_ROMAN_24);/////////////////////////////////////////////////Health Bars & Text
		iSetColor(220,20,20);
		iRectangle(1040,10,300,10);
		iFilledRectangle(1040,10,25*n[25],10);

	

			
		if(n[25]>0){
			iShowImage(dx,dy,100,100,image[17]);//////////////////////////////////////////////////////////////////// userObj
			
			                                                                                        
			for(j=1;j<=n[15];j++){                                                            //										
				iShowImage(Bdx[j],Bdy[j],15,40,image[18]);									  //user bullet
				Bdy[j]+=5;																	  //
			}

		}
		for(i=0;i<4;i++)
		{
			if((E[i].Ex>=dx && E[i].Ex<=dx+100 && E[i].Ey>=dy && E[i].Ey<=dy+100) && n[25]>0)							//  
			{n[25]-=1;dx=650,dy=50;}																					//checking user collision
			else if(dx>=E[i].Edx && dx<=E[i].Edx+60 && dy>=E[i].Edy && dy<=E[i].Edy+70 && n[25]>0)						//with bullet
			{n[25]-=1;dx=650,dy=50;}																					//&
			else if(dx+60>=E[i].Edx && dx+60<=E[i].Edx+60 && dy>=E[i].Edy && dy<=E[i].Edy+70 && n[25]>0)				//enemy obj
			{n[25]-=1;dx=650,dy=50;}																					//
			else if(dx>=E[i].Edx && dx<=E[i].Edx+60 && dy+70>=E[i].Edy && dy+70<=E[i].Edy+70 && n[25]>0)				//
			{n[25]-=1;dx=650,dy=50;}																					//	
			else if(dx+60>=E[i].Edx && dx+60<=E[i].Edx+60 && dy+70>=E[i].Edy && dy+70<=E[i].Edy+70 && n[25]>0)			//
			{n[25]-=1;dx=650,dy=50;}																					//

		}

		for(i=0;i<4;i++){
		if(n[30+i]==0)
		{	
			iShowImage(E[i].Edx,E[i].Edy,100,100,image[20]);				//enemy obj
			iShowImage(E[i].Ex,E[i].Ey,25,45,image[25]);					//enemy bullet
			E[i].Ey-=3;														//changing enemy bullet axis
		}

		if(n[30+i]>=-10 && n[30+i]<=-1)
		{																	 //
			iShowImage(E[i].Edx,E[i].Edy,100,100,image[23]);			     //enemy explosion
			n[30+i]--;														 //
		}
		if(E[i].Edy>480)													 //
		{E[i].Edy-=1;}														 //last position of enemy obj


		if(n[30+i]==-10 && n[90]<4){										//
			n[90]+=1;														//next level trigger
		}																	//

		}

		if(n[15])																											  //
		{																													  //
			for(j=1;j<=n[15];j++){																							  //
					for(i=0;i<4;i++){																						  //
					if(Bdx[j]>=E[i].Edx && Bdx[j]<=E[i].Edx+100 && Bdy[j]>=E[i].Edy && Bdy[j]<=E[i].Edy+100 && n[30+i]==0)    //checking enemy
						{n[30+i]=-1;E[i].Ex=-10;E[i].Ey=-10;score+=100;_itoa(score,showScore,10);}							  //collision with
					}																										  //user bullet
			}																												  //
		}																													  //







		}
		//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::       LEVEL 2          ::::::::::::::::
		if(n[90]>=4 && n[90]<11 && n[25]>0){
		iShowImage(bgMX[0],bgMY[0]-=1,1350,690,image[24]);			//
		iShowImage(bgMX[1],bgMY[1]-=1,1350,690,image[24]);			//
		if(bgMY[1]==0)												//moving background 2
		{bgMY[0]=0;bgMY[1]=690;}                                    //




		
		iSetColor(0,0,0);
		iFilledRectangle(0,660,110,30);
		iSetColor(255,255,255);
		iText(8,670,"LEVEL 2",GLUT_BITMAP_TIMES_ROMAN_24);///////////////////////////////////////////Level 2 Text

		iSetColor(0,0,0);
		iFilledRectangle(1100,660,260,30);
		iSetColor(255,255,255);
		iText(1110,670,"SCORE:",GLUT_BITMAP_TIMES_ROMAN_24);////////////////////////////////////Score Text
		iText(1290,670,showScore,GLUT_BITMAP_TIMES_ROMAN_24);////////////////////show scoring

		iSetColor(0,0,0);
		iFilledRectangle(990,0,370,30);
		iSetColor(255,255,255);
		iText(995,8,"HP",GLUT_BITMAP_TIMES_ROMAN_24);////////////////////////////////////////////////Health Bars & Text
		iSetColor(220,20,20);
		iRectangle(1040,10,300,10);
		iFilledRectangle(1040,10,25*n[25],10);



		if(n[25]>0){
			iShowImage(dx,dy,100,100,image[17]);////////////////////////////////////////////// userObj
			
			                                                                                        
			for(j=1;j<=n[15];j++){                                                                  //										
				iShowImage(Bdx[j],Bdy[j],15,40,image[18]);											//user bullet
				Bdy[j]+=3;																			//
			}

		}
			for(i=0;i<7;i++)
		{
			if((E[i+4].Ex>=dx && E[i+4].Ex<=dx+100 && E[i+4].Ey>=dy && E[i+4].Ey<=dy+100) && n[25]>0)							//  
			{n[25]-=2;dx=650,dy=50;}																							//checking user collision
			else if(dx>=E[i+4].Edx && dx<=E[i+4].Edx+60 && dy>=E[i+4].Edy && dy<=E[i+4].Edy+70 && n[25]>0)						//with bullet
			{n[25]-=2;dx=650,dy=50;}																							//&
			else if(dx+60>=E[i+4].Edx && dx+60<=E[i+4].Edx+60 && dy>=E[i+4].Edy && dy<=E[i+4].Edy+70 && n[25]>0)				//enemy obj
			{n[25]-=2;dx=650,dy=50;}																							//
			else if(dx>=E[i+4].Edx && dx<=E[i+4].Edx+60 && dy+70>=E[i+4].Edy && dy+70<=E[i+4].Edy+70 && n[25]>0)				//
			{n[25]-=2;dx=650,dy=50;}																							//	
			else if(dx+60>=E[i+4].Edx && dx+60<=E[i+4].Edx+60 && dy+70>=E[i+4].Edy && dy+70<=E[i+4].Edy+70 && n[25]>0)			//
			{n[25]-=2;dx=650,dy=50;}																							//
		}

		for(i=0;i<7;i++){
		if(n[34+i]==0)
		{	
			iShowImage(E[i+4].Edx,E[i+4].Edy,100,100,image[21]);				//enemy obj
			iShowImage(E[i+4].Ex,E[i+4].Ey,25,45,image[25]);					//enemy bullet
			E[i+4].Ey-=4;														//changing enemy bullet axis
		}

		if(n[34+i]>=-10 && n[34+i]<=-1)
		{																		 //
			iShowImage(E[i+4].Edx,E[i+4].Edy,100,100,image[23]);			     //enemy explosion
			n[34+i]--;															 //
		}


		if(E[i+4].Edy>520 && i<4)															 //
		{E[i+4].Edy-=1;}						 											 //last position of enemy obj
		if(E[i+4].Edy>440 && i>=4 && i<7)													 //
		{E[i+4].Edy-=1;}																	 //

		if(n[34+i]==-10 && n[90]>=4 && n[90]<11){														//
			n[90]+=1;																					//next level trigger
		}																								//

		}

		if(n[15])																											  //
		{																													  //
			for(j=1;j<=n[15];j++){																							  //
					for(i=0;i<7;i++){																						  //
					if(Bdx[j]>=E[i+4].Edx && Bdx[j]<=E[i+4].Edx+100 && Bdy[j]>=E[i+4].Edy && Bdy[j]<=E[i+4].Edy+100 && n[34+i]==0)//checking enemy 
						{n[34+i]=-1;E[i+4].Ex=-10;E[i+4].Ey=-10;score+=100;_itoa(score,showScore,10);}						  //collision with 
					}																										  //user bullet
			}																												  //
		}																													  //


		}


		//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::       LEVEL 3          ::::::::::::::::
		if(n[90]>=11 && n[90]<22 && n[25]>0){
		iShowImage(bgMX[0],bgMY[0]-=1,1350,690,image[26]);			//
		iShowImage(bgMX[1],bgMY[1]-=1,1350,690,image[26]);			//
		if(bgMY[1]==0)												//moving background 2
		{bgMY[0]=0;bgMY[1]=690;}                                    //




		
		iSetColor(0,0,0);
		iFilledRectangle(0,660,110,30);
		iSetColor(255,255,255);
		iText(8,670,"LEVEL 3",GLUT_BITMAP_TIMES_ROMAN_24);//////////////////////////////////////////Level 3

		iSetColor(0,0,0);
		iFilledRectangle(1100,660,260,30);
		iSetColor(255,255,255);
		iText(1110,670,"SCORE:",GLUT_BITMAP_TIMES_ROMAN_24);///////////////////////////////////Score Text
		iText(1290,670,showScore,GLUT_BITMAP_TIMES_ROMAN_24);/////////////showing score

		iSetColor(0,0,0);
		iFilledRectangle(990,0,370,30);
		iSetColor(255,255,255);
		iText(995,8,"HP",GLUT_BITMAP_TIMES_ROMAN_24);///////////////////////////////////////////////Health Bars & Text
		iSetColor(220,20,20);
		iRectangle(1040,10,300,10);
		iFilledRectangle(1040,10,25*n[25],10);



		if(n[25]>0){
			iShowImage(dx,dy,100,100,image[17]);////////////////////////////////////////////// userObj
			
			                                                                                        
			for(j=1;j<=n[15];j++){                                                                  //										
				iShowImage(Bdx[j],Bdy[j],15,40,image[18]);											//user bullet
				Bdy[j]+=5;																			//
			}

		}
		for(i=0;i<11;i++)
		{
			if((E[i+11].Ex>=dx && E[i+11].Ex<=dx+100 && E[i+11].Ey>=dy && E[i+11].Ey<=dy+100) && n[25]>0)						//  
			{n[25]-=3;dx=650,dy=50;}																							//checking user collision
			else if(dx>=E[i+11].Edx && dx<=E[i+11].Edx+60 && dy>=E[i+11].Edy && dy<=E[i+11].Edy+70 && n[25]>0)					//with bullet
			{n[25]-=3;dx=650,dy=50;}																							//&
			else if(dx+60>=E[i+11].Edx && dx+60<=E[i+11].Edx+60 && dy>=E[i+11].Edy && dy<=E[i+11].Edy+70 && n[25]>0)			//enemy obj
			{n[25]-=3;dx=650,dy=50;}																							//
			else if(dx>=E[i+11].Edx && dx<=E[i+11].Edx+60 && dy+70>=E[i+11].Edy && dy+70<=E[i+11].Edy+70 && n[25]>0)			//
			{n[25]-=3;dx=650,dy=50;}																							//	
			else if(dx+60>=E[i+11].Edx && dx+60<=E[i+11].Edx+60 && dy+70>=E[i+11].Edy && dy+70<=E[i+11].Edy+70 && n[25]>0)		//
			{n[25]-=3;dx=650,dy=50;}																							//
		}

		for(i=0;i<11;i++){
		if(n[41+i]==0)
		{	
			iShowImage(E[i+11].Edx,E[i+11].Edy,100,100,image[22]);				//enemy obj
			iShowImage(E[i+11].Ex,E[i+11].Ey,25,45,image[25]);					//enemy bullet
			E[i+11].Ey-=5;														//changing enemy bullet axis
		}

		if(n[41+i]>=-10 && n[41+i]<=-1)
		{																		 //
			iShowImage(E[i+11].Edx,E[i+11].Edy,100,100,image[23]);			     //enemy explosion
			n[41+i]--;															//
		}


		if(E[i+11].Edy>520 && i<5)															 //
		{E[i+11].Edy-=1;}						 											 //last position of enemy obj
		if(E[i+11].Edy>440 && i>=5 && i<9)													 //
		{E[i+11].Edy-=1;}																	 //
		if(E[i+11].Edy>360 && i>=9 && i<11)													 //
		{E[i+11].Edy-=1;}

		if(n[41+i]==-10 && n[90]>=11){														//
			n[90]+=1;																		//next level trigger
		}																					//

		}

		if(n[15])																														//
		{																																//
			for(j=1;j<=n[15];j++){																										//
				for(i=0;i<11;i++){																										//
					if(Bdx[j]>=E[i+11].Edx && Bdx[j]<=E[i+11].Edx+100 && Bdy[j]>=E[i+11].Edy && Bdy[j]<=E[i+11].Edy+100 && n[41+i]==0)	//checking enemy 
						{																												//collision with 
							n[41+i]=-1;E[i+11].Ex=-10;E[i+11].Ey=-10;score+=100;_itoa(score,showScore,10);								//user bullet
						}																												//
					}																													//
			}																															//
		}																																//


		}


		//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Game Over & High Score
		if(n[25]<=0 || n[90]==22)
		{
			iShowImage(0,0,1360,690,image[30]);///////////////////////////////////////////////Game Over Background
			iSetColor(255,255,255);
			iText(470,180,"Enter Name:",GLUT_BITMAP_TIMES_ROMAN_24);//////////////////////////Enter Name Text
			iFilledRectangle(610,173,300,30);
			iSetColor(0,0,0);
			iText(620,180,inputStr1,GLUT_BITMAP_TIMES_ROMAN_24);
		}

	}
}

void fireBullet(int key){

	if(key=='x' || key=='X')														//
	{																				//
		n[15]+=1;																	//
		if(n[15]==10001)															//
		{n[15]=1;}																	//bullet co-ordinate set
		Bdx[n[15]]=dx+43;Bdy[n[15]]=dy+100;											//
	}																				//
}																					//

void controlObj(int key){

	if(key == GLUT_KEY_UP && dy<=590 && dy>=0)										//
	{																				//
			dy+=15;																	//user object up direction
			if(dy>590)																//
				dy=590;																//
	}
	
	if(key == GLUT_KEY_DOWN && dy<=590 && dy>=0)									//
	{																				//
			dy-=15;																	//user object down direction
			if(dy<0)																//
				dy=0;																//
	}
	
	if(key == GLUT_KEY_LEFT && dx<=1250 && dx>=0)									//
	{																				//
			dx-=15;																	//user object left direction
			if(dx<0)																//
				dx=0;																//
	}
	
	if(key == GLUT_KEY_RIGHT && dx<=1250 && dx>=0)									//
	{																				//
			dx+=15;																	//user object right direction
			if(dx>1250)																//
				dx=1250;															//
	}
}


#endif // GAMEPLAY_H_INCLUDED
