#ifndef ENEMYFUNCTIONS_H_INCLUDED
#define ENEMYFUNCTIONS_H_INCLUDED
#include"Variables.h"

void coOrdinateOfSet(){
	
	for(i=0;i<4;i++)																				//
	{																								//
		E[i].Edx=200+300*i;E[i].Edy=800;E[i].EDir=1;//////////////////////////////////////////////////level 1 x,y set
																									//	
		E[i+4].Edx=200+300*i;E[i+4].Edy=800;E[i+4].EDir=3;////////////////////////////////////////////level 2 row 1 x,y set
																									//
		if(i<3){																					//
			E[i+8].Edx=300+300*i;E[i+8].Edy=800;E[i+8].EDir=3;////////////////////////////////////////level 2 row 2 x,y set
		}																							//
	}																								//


	for(i=0;i<5;i++)																				//
	{																								//
		E[i+11].Edx=200+200*i;E[i+11].Edy=800;E[i+11].EDir=5;/////////////////////////////////////////level 3 row 1 x,y set
																									//
		if(i<4){																					//
			E[i+16].Edx=300+200*i;E[i+16].Edy=800;E[i+16].EDir=5;/////////////////////////////////////level 3 row 2 x,y set
		}																							//
	}																								//
	E[20].Edx=100;E[20].Edy=900;E[20].EDir=10;E[21].Edx=1200;E[21].Edy=900;E[21].EDir=10;/////////////level 3 row 3 x,y set
	
}


void EnemyDirection()
{
	for(i=0;i<4;i++){											//
	if(E[i].Edy==480){											//
	E[i].Edx+=E[i].EDir;										//
	if(E[i].Edx>(300+300*i) || E[i].Edx<(100+300*i))            //side movement of enemy obj level 1
	{E[i].EDir=-E[i].EDir;}										//
	}															//
	}															//

	for(i=0;i<4;i++){											//
	if(E[i+4].Edy==520 && n[90]>=4){							//
	E[i+4].Edx+=E[i+4].EDir;									//
	if(E[i+4].Edx>(300+300*i) || E[i+4].Edx<(100+300*i))        //side movement of enemy obj level 2 row 1
	{E[i+4].EDir=-E[i+4].EDir;}									//
	}															//

	if(i<3){
	if(E[i+8].Edy==440 && n[90]>=4){							//
	E[i+8].Edx+=E[i+8].EDir;									//
	if(E[i+8].Edx>(400+300*i) || E[i+4].Edx<(200+300*i))        //
	{E[i+8].EDir=-E[i+8].EDir;}									//side movement of enemy obj level 2 row 2
	}															//
	}															//
	}															//

	for(i=0;i<5;i++){											//
	if(E[i+11].Edy==520 && n[90]>=11){							//
	E[i+11].Edx+=E[i+11].EDir;									//
	if(E[i+11].Edx>(300+200*i) || E[i+11].Edx<(100+200*i))      //side movement of enemy obj level 3 row 1
	{E[i+11].EDir=-E[i+11].EDir;}								//
	}															//

	if(i<4){
	if(E[i+16].Edy==440 && n[90]>=11){							//
	E[i+16].Edx+=E[i+16].EDir;									//
	if(E[i+16].Edx>(400+200*i) || E[i+16].Edx<(200+200*i))      //
	{E[i+16].EDir=-E[i+16].EDir;}								//side movement of enemy obj level 3 row 2
	}															//
	}															//

	if(i<2){
	if(E[i+20].Edy==360 && n[90]>=11){							//
	E[i+20].Edx+=E[i+20].EDir;									//
	if(E[i+20].Edx>1250 || E[i+20].Edx<50)						//
	{E[i+20].EDir=-E[i+20].EDir;}								//side movement of enemy obj level 3 row 3
	}															//
	}															//
																//
	}															//

}

void EnemyBullet(){															
	for(i=0;i<4;i++){											//
	E[i].Ex=E[i].Edx+40;E[i].Ey=E[i].Edy-7;						//enemy bullet coordinate set
																//
	E[i+4].Ex=E[i+4].Edx+40;E[i+4].Ey=E[i+4].Edy-7;				//
	if(i<3)														//
	{E[i+8].Ex=E[i+8].Edx+40;E[i+8].Ey=E[i+8].Edy-7;}			//
	}															//


	for(i=0;i<5;i++){											//
	E[i+11].Ex=E[i+11].Edx+40;E[i+11].Ey=E[i+11].Edy-7;			//enemy bullet coordinate set
	if(i<4)														//
	{E[i+16].Ex=E[i+16].Edx+40;E[i+16].Ey=E[i+16].Edy-7;}		//
	if(i<2)														//
	{E[i+20].Ex=E[i+20].Edx+40;E[i+20].Ey=E[i+20].Edy-7;}		//
	}
}


#endif // ENEMYFUNCTIONS_H_INCLUDED
