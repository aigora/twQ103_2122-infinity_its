#include<stdio.h>
#include <cstdlib>
#include<ctime>
int DadoMediano (int x){
	int i; 
	int dado; 
	printf("Pulse '0' para lanzar el dado\n"); 
	scanf("%d", &x); 
	if (x==0){
			srand (time(0)); 
		for (i=0; i<7; i++){
			dado= 1+ (rand ()%5); 
		}
	}
	return dado; 
}
