#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	srand(time(NULL));
	int score1=0;
	int score2=0;
	int cartas_j1=0,cartas_j2=0,intento=0,r1,r2,valor,puntos_j1=0,puntos_j2=0,as,cartas,p=0,b=0,v;
	char cartas_p[52]={2,3,4,5,6,7,8,9,10,'J','Q','K','A',2,3,4,5,6,7,8,9,10,'J','Q','K','A',2,3,4,5,6,7,8,9,10,'J','Q','K','A',2,3,4,5,6,7,8,9,10,'J','Q','K','A'};
	printf("\t\tBienvenido al BlackJack\n\n");
	printf("En todo momento presiona la tecla 1 para acertar o de lo contrario la tecla 0\n\n");
	system("pause");
	system("cls");
	printf("\n\n\tTurno de Jugador 1\n");
	do{
		cartas_j1=0;
		cartas_j2=0;
		intento=0;
		r1;
		r2;
		puntos_j1=0;
		puntos_j2=0;
		p=0;
		b=0;
		
		system("cls");
		do{
			if(intento==0){
				cartas_j1=cartas_j1+2;
				cartas=2;
			}
			if(intento==1){
				cartas_j1=cartas_j1+1;
				cartas=1;
			}
			intento=1;
			for(int i=0;i<cartas;i++){
				valor=1+rand()%(52-1);
				while(cartas_p[valor]=='x'){
					valor=1+rand()%(52-1);
				}
				if(cartas_p[valor]=='A'||cartas_p[valor]=='Q'||cartas_p[valor]=='K'||cartas_p[valor]=='J'){
					if(cartas_p[valor]=='A'){
						printf("\nEsta es tu carta: %c",cartas_p[valor]);
						printf("\nQuieres darle valor de 1 al As? ");
						scanf("%c",&as);
						if(as==1){
						puntos_j1=puntos_j1+1;
						}else{
						puntos_j1=puntos_j1+11;
						}
			    	}else{
					puntos_j1=puntos_j1+10;
					printf("\nEsta es tu carta: %c",cartas_p[valor]);
			   		}
				}else{
					puntos_j1=puntos_j1+cartas_p[valor];
					printf("\nEsta es tu carta: %i",cartas_p[valor]);
				}
				cartas_p[valor]='x';
			}
			printf("\nLlegaste a %i\n",puntos_j1);
			if(puntos_j1>21){
				printf("\nTe has pasado de 21...:(");
				p=1;
				break;
			}
			printf("\nQuieres otra carta?\n");
			scanf("%i",&r1);
			system("pause");
		}while(r1==1); 
		system("pause");
		system("cls");
		printf("\n\n\tTurno de la computadora\n");
		intento=0;
		do{
			if(intento==0){
				cartas_j2=cartas_j2+2;
				cartas=2;
			}
			if(intento==1){
				cartas_j2=cartas_j2+1;
				cartas=1;
			}
			for(int i=0;i<cartas;i++){
				valor=1+rand()%(52-1);
				while(cartas_p[valor]=='x'){
					valor=1+rand()%(52-1);
				}
				if(cartas_p[valor]=='A'||cartas_p[valor]=='Q'||cartas_p[valor]=='K'||cartas_p[valor]=='J'){
					if(cartas_p[valor]=='A'){
						printf("\nCarta de la computadora: %c",cartas_p[valor]);
						if(intento==0){
						puntos_j2=puntos_j2+11;
						}else{
					    	puntos_j2=puntos_j2+1;
						}
				    }else{
						puntos_j2=puntos_j2+10;
			 			printf("\nCarta de la computadora: %c",cartas_p[valor]);
					}
				}else{
					puntos_j2=puntos_j2+cartas_p[valor];
					printf("\nCarta de la computadora: %i",cartas_p[valor]);
				}
				cartas_p[valor]='x';
			}
					printf("\nLa computadora llego a %i\n",puntos_j2);
			        if(intento==0 && puntos_j2<=18){
			        	r2=1;
					}
					if(intento==0 && puntos_j2>18){
						printf("La computadora se quedo en %i ",puntos_j2);
						if(puntos_j2>21){
							b=1;
						}
					    r2=0;	
					}
					if(cartas_j2>=3 && puntos_j2<=18){
						r2=1;
					}
					if(cartas_j2>=3 && puntos_j2>18){
						printf("La computadora se quedo en %i ",puntos_j2);
						if(puntos_j2>21){
							b=1;
						}
						r2=0;
					}
					intento=1;
					
		}while(r2==1);
		if(p==1){
			if(puntos_j1>puntos_j2){
				printf("\t\t\n\nPERDISTE esta ronda\n\n");
				score2=score2+1;
			}
			if(puntos_j1<puntos_j2){
				printf("\t\t\nGANASTE esta ronda\n");
				score1=score1+1;
			}
		}
		if(p==0){
			if(b==1){
				printf("\t\t\nGANASTE esta ronda\n");
				score1=score1+1;
			}else if(puntos_j1>puntos_j2){
				printf("\t\t\nGANASTE esta ronda\n");
				score1=score1+1;
			}else 
				printf("\t\t\n\nPERDISTE esta ronda\n\n");
				score2=score2+1;
		}
		printf("\n\nJugador 1: %d                   Computadora: %d\n\n",score1,score2);
		printf("Quieres jugar otra vez? ");
		scanf("%i",&v);
	}while(v==1);
	
}
