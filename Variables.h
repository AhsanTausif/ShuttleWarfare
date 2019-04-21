#ifndef VARIABLES_H_INCLUDED
#define VARIABLES_H_INCLUDED
#include "Enemy.h"

int image[100];
int i,j,n[100];
int cursorMX,cursorMY;
int dragMX,dragMY;
int clickMX,clickMY;
int bgMX[]={0,0},bgMY[]={0,690};
int score,len;
char showScore[20]="0",inputStr1[20],inputStr2[20];

int HS[100],temp;
char name[100][20],stringHS[100][20],tempC[20];

EO E[50];

int dx=650,dy=50;
int Bdx[10000],Bdy[10000];
#endif // VARIABLES_H_INCLUDED
