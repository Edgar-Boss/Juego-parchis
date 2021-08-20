#include <stdio.h>
#include <stdlib.h>

void rellenarady(int ady[17][12])
{

	for(int k=0;k<17;k++)
	{

		for(int j=0;j<12;j++)
			ady[k][j]=0;

	}

		
		ady[0][1]=1;
		ady[1][2]=1;
		ady[2][3]=1;

		ady[4][5]=1;
		ady[5][6]=1;
		ady[6][7]=1;

		ady[8][9]=1;
		ady[9][10]=1;
		ady[10][11]=1;

		ady[0][4]=1;
		ady[1][5]=1;
		ady[2][6]=1;
		ady[3][7]=1;

		ady[4][8]=1;
		ady[5][9]=1;
		ady[6][10]=1;
		ady[7][11]=1;

}




void imprimirtab(int ady[17][12])
{

	int conady=0,conadyv=0;
	for(int k=0;k<3;k++)
	{
		for(int j=0;j<4;j++)
		{	

			
			printf("*");
			
			if(ady[conady][conady+1]==2)
				printf("---");
			else
				printf("   ");

			conady++;
		}
		printf("\n");
	
		for(int j=0;j<4;j++)
		{

			if(ady[conadyv][conadyv+4]==2)
				printf("|   ");
			else
				printf("    ");

			conadyv++;

		}
		printf("\n");


	}

}

int buscacompletos(int ady[17][12])
{
	int c=0;
	for(int k=0;k<7;k++)
	{
		if(k==3)
			k++;

		if((ady[k][k+1]+ady[k+4][k+5]+ady[k][k+4]+ady[k+1][k+5])==8)
		{

			
			c++;
		}	






	}

	return c;



}

int main()
{

	int tablero[4][3]={0,1,2,3,
					   4,5,6,7,
					   8,9,10,11};
	int ady[17][12];
	int cuadro=0;
	rellenarady(ady);
	imprimirtab(ady);

	int elecc[2];
	int jugador=0,maquina=0;
	
////////////////////////////////////////////////////////////////////////////
	while(cuadro < 6)
	{
	printf("Ingrese los puntos a juntar: ");
	scanf("%d",&elecc[0]);
	scanf("%d",&elecc[1]);
	
	bool ban =false;

	ady[elecc[0]][elecc[1]]=2;

	if(cuadro<buscacompletos(ady))
		jugador++;


	cuadro = buscacompletos(ady);

	for(int k=0;k<17;k++)
	{

		for(int j=0;j<12;j++)
		{
			if(ady[k][j] == 1)
			{
				ady[k][j] = 2;	
				ban=true;

				if(cuadro<buscacompletos(ady))
					maquina++;
				break;
			}


		}
		if(ban == true)
			break;

				
	}

	system("clear");
	imprimirtab(ady);
	cuadro = buscacompletos(ady);
	

}
printf("juego terminado\n");
printf("Jugador: %d\nMaquina: %d\n",jugador,maquina);
///////////////////////////////////////////////////////////////////////////////


}