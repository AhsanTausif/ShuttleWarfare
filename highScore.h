#ifndef HIGHSCORE_H_INCLUDED
#define HIGHSCORE_H_INCLUDED
#include"Variables.h"

void HSshow()
{
		iSetColor(0,0,0);
		if(n[5])
		{
			for(i=0;i<5;i++)
			{
				iText(515,440-85*i,name[i],GLUT_BITMAP_TIMES_ROMAN_24);
				iText(1020,440-85*i,stringHS[i],GLUT_BITMAP_TIMES_ROMAN_24);
			}
		}
}





#endif // HIGHSCORE_H_INCLUDED
