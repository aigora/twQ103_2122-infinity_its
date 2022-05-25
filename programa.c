#include<stdio.h>
//#include<cstdlib>
//#include<ctime> VER SI ES NECESARIO PONERLAS 
#include<string.h>
#define TAM_MAX 50
#include<windows.h>
#define color SetConsoleTextAttribute

void Banner (){
	HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
	printf ("Bienvenido a Infinity_ITS, esperamos que pases un gran rato y disfrutes del juego\n");
	printf("\n");
    printf( "      (.)");color(hConsole, 6); printf("<            >");color(hConsole, 7);printf("(.)\n");
    color (hConsole, 7); 
    printf("      ||                || \n");
    printf("      ||   "); color(hConsole, 11); printf(" INFINITY "); color(hConsole, 7); printf("   ||\n");
    printf(" _ _ _||   "); color (hConsole, 1); printf(" ********  "); color(hConsole, 7); printf("  ||_ _ _ \n");
    printf("(_ _ _ _)               (_ _ _ _)\n");
    color(hConsole, 6); printf("   |_  |_               _|  _|\n"); color(hConsole, 7);
	return; 
}

char menu (){
	char opcion1; 
		do {
		fflush(stdin); 
		printf("\n");
		printf("Que desea hacer?\n"); 
		printf("A- Ver las reglas del juego\n");  
		printf("B- Iniciar el juego\n");  
		scanf("%c", & opcion1); 
		switch (opcion1){
			case 'A': 
			case 'a': 
			fflush(stdin); 
			printf("El primer jugador registrado comienza tirando el dado, despues avanza el numero de casillas indicado por el dado. Si el jugador cae en una casilla con oca, le saldra una pregunta que debe responder. Si acierta la pregunta permanece en la casilla de oca, si por el contrario falla la pregunta, retrocede hasta donde se encontraba anteriormente. Si el jugador cae en una casilla en donde no hay una oca, permanece en esa casilla. El primer jugador en llegar a la casilla final gana el juego y este mismo finaliza.\n");
			break; 
		}
	} 
	while (opcion1!='B' && opcion1!='b'); //VER COMO HACER PARA QUE CON b NOS SALGA TAMBIEN 
	return opcion1; 
}

struct TJugador {
	char avatar[50];  
};
struct TCuestiones{
	char pregunta[50]; 
	char respuesta[50]; 
};
void tablero(int tam){
	
	int fila,columna;
     int matriz[tam][tam];
	
	printf("\n");
	printf("E: Entrada al tablero\n");
	printf("O: casilla de oca\n");
	printf("F: casilla final\n");
	printf("La forma de moverse por el tablero es como la de un gusanito,\n");
	printf("subiendo y bajando por las columnas hasta llegar al final\n");
	printf("\n");
	

	for (columna=1;columna<=tam;columna++){
			printf("    ");
			printf("%d",columna);
			printf(" ");
    }
    printf("\n");
    
	for (columna=1;columna<=tam;columna++){
    	if(columna == 1){
    		printf("     ___ ");
		}else{
			printf(" ___ ");
        }
    }

	for(fila=1;fila<=tam;fila++) {
         printf("\n");
         for(columna=1;columna<=tam+1;columna++) {
         	if(columna==1){
         		printf("   %d",fila);
             }else if(columna == 2 && fila == 1){
             	printf("|_E_|");
             }else if(columna == tam+1 && fila == 1){
             	printf("|_F_|");
			 }else if(columna % 2 == 0 && fila % 2 != 0){
			 	printf("|_O_|");
			 }else if(columna % 2 != 0 && fila % 2 == 0){
			 	printf("|_O_|");
			 }else if(columna % 2 != 0 && fila % 2 == 0){
			 	printf("|_O_|");
			 }else if(columna == 2){
			 	printf("|___|");
			 }else{
			 	printf("|___|");
			 }
		}
    }
    printf("\n");
}

int Dado (int x){
	int i; 
	int dado; 
	printf("Pulse '0' para lanzar el dado\n"); 
	scanf("%d", &x); 
	if (x==0){
			srand (time(0)); 
		for (i=0; i<7; i++){
			dado= 1+ (rand ()%6); 
		}
	}
	return dado; 
}

int DadoMediano (int x){ //Es un dado con 5 n�meros m�ximo
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

int DadoDiminuto (int x){ //Es un dado de m�ximo 4 n�meros 
	int i; 
	int dado; 
	printf("Pulse '0' para lanzar el dado\n"); 
	scanf("%d", &x); 
	if (x==0){
			srand (time(0)); 
		for (i=0; i<7; i++){
			dado= 1+ (rand ()%4); 
		}
	}
	return dado;
}

void Literatura (){
	struct TCuestiones cuestion[TAM_MAX];
    	FILE *fichero;
    	FILE*fichero2; 
    	int i, contador;
    	fichero = fopen("PREGUNTAS literatura y arte.txt", "r");
        if (fichero == NULL) {
            printf("Error de lectura\n");
            return 0;
        }
        fichero2= fopen ("RESPUESTAS literatura y arte.txt", "r"); 
        if (fichero2== NULL){
        	printf("Error de lectura\n"); 
        	return 0; 
		}
        i=0;
        contador=0;
        while (fscanf(fichero, "%s ", cuestion[i].pregunta) != EOF) {
                printf("%s \n", cuestion[i].pregunta);
                i++;
                contador++;
        } 
		while (fscanf(fichero2, "%s ",cuestion[i].respuesta) != EOF) {
                printf("%s \n", cuestion[i].respuesta);
                i++;
                contador++;
        }
        fclose(fichero);
        fclose (fichero2); 
}

void Entretenimiento(){
	struct TCuestiones cuestion[TAM_MAX];
   	 	FILE *fichero;
   	 	FILE*fichero2; 
   		 int i, contador;
    	fichero = fopen("PREGUNTAS entretenimiento.txt", "r");
		if (fichero == NULL) {
            printf("Error de lectura\n");
            return 0;
        }
        fichero2= fopen ("RESPUESTAS entretenimiento.txt", "r"); 
        if (fichero2== NULL){
        	printf("Error de lectura\n");
            return 0;
		}
        i=0;
        contador=0;
        while (fscanf(fichero, "%s ", cuestion[i].pregunta) != EOF) {
                printf("%s \n", cuestion[i].pregunta);
                i++;
                contador++;
        }
        while (fscanf(fichero2, "%s ",cuestion[i].respuesta) != EOF) {
                printf("%s\n", cuestion[i].respuesta);
                i++;
                contador++;
        }
        fclose(fichero);
        fclose(fichero2);
}

void Geografia(){
	struct TCuestiones cuestion[TAM_MAX];
    	FILE *fichero;
    	FILE*fichero2; 
    	int i, contador;
		fichero = fopen("PREGUNTAS geografia e historia.txt", "r");
		if (fichero == NULL) {
                printf("Error de lectura\n");
                return 0;
        }
        fichero2=fopen("RESPUESTAS geografia e historia.txt", "r"); 
        if(fichero2==NULL){
        	printf("Error de lectura\n");
                return 0;
		}
        i=0;
        contador=0;
        while (fscanf(fichero, "%s", cuestion[i].pregunta) != EOF) {
                printf("%s\n", cuestion[i].pregunta);
                i++;
                contador++;
        }
        while (fscanf(fichero2, "%s", cuestion[i].respuesta) != EOF) {
                printf("%s\n", cuestion[i].respuesta);
                i++;
                contador++;
        }
        fclose(fichero);
        fclose(fichero2); 
}
    
int main (){
	struct TJugador jugadores[TAM_MAX]; 
	int i, n_jugadores,x, dado_elegido, suma1=0,suma2=0, turno; //n_jugadores se refiere al n�mero de jugadores
	char opcion1, jugador_elegido[50], jugador_no_elegido[50], tema_elegido[50]; 
	Banner(); 
	opcion1= menu();
	printf ("Desea jugar en pareja o solo?\n"); 
	printf (" Pulse 1 si jugara solo\n"); 
	printf (" Pulse 2 si jugara en pareja\n"); 
	scanf ("%d", &n_jugadores); 
	
	for (i=0; i<n_jugadores; i++){
		printf("Nombre del jugador %d:\n",i+1); 
		scanf("%s", jugadores[i].avatar); 
	} 
	 //ahora vamos a ver que jugador empieza en caso de que sean dos jugadores
	int num, numero[1]; 
	if (n_jugadores==2){
	do{
		printf("\n"); 
		for (i=0; i<2; i++){
			numero[i]= Dado(num);
			printf("El resultado del dado es %d\n", numero[i]); 
		}
		if (numero[0]==numero[1]){
			printf("Ambos habeis obtenido el mismo numero, volved a lanzar el dado\n"); 
		}
	}while (numero[0]==numero[1]); 	
		
		if(numero[0]>numero[1]){ // imprimimos quien empieza segun el numero sorteo anteriormente
			printf("%s saco el dado mas alto, por lo tanto, es el que empieza a jugar\n", jugadores[0].avatar);
			strcpy(jugador_elegido, jugadores[0].avatar);
			strcpy(jugador_no_elegido, jugadores[1].avatar); 
		} else if (numero[1]>numero[0]){
			printf("%s saco el dado mas alto, por lo tanto, es el que empieza a jugar\n", jugadores[1].avatar);
			strcpy(jugador_elegido, jugadores[1].avatar); 
			strcpy(jugador_no_elegido, jugadores[0].avatar);
		}
	}
	printf("\n"); 
	printf("El juego va a iniciar. PREPARATE PARA AVERIGUAR COMO DE LIST@ ERES!\n");
	
	char tamano; 
	do{
		fflush(stdin); 
		printf("Como de grande quiere el tablero?\n"); 
		printf(" D- Diminuto (16 casillas)\n");  
		printf(" N- Normalito (25 casillas)\n");  
	    printf(" G- Grandote (36 casillas)\n"); 
		scanf("%c", &tamano);
		
	    if(tamano !='D' && tamano !='d' && tamano !='N' && tamano !='n' && tamano !='G' && tamano !='g'){
			printf("Esa opcion no es valida!! Vuelve a intentarlo!!\n");
			scanf("%c", & tamano);
		}	
		
	}while(tamano !='D' && tamano !='d' && tamano !='N' && tamano !='n' && tamano !='G' && tamano !='g');
	
	printf("\n"); 
	
	char tema;
	do{
		fflush(stdin); 
		printf("Que tematica deseas para las preguntas del juego?\n"); 
		printf(" E- Entretenimiento\n");  
		printf(" A- Arte y literatura\n");  
	    printf(" G- Geografia e historia\n"); 
		scanf("%c", &tema);
		
	    if(tema !='E' && tema !='e' && tema !='A' && tema !='a' && tema !='G' && tema !='g'){
			printf("Esa opcion no es valida!! Vuelve a intentarlo!!\n");
			scanf("%c", & tema);
		}		
	}while(tema !='E' && tema !='e' && tema !='A' && tema !='a' && tema !='G' && tema !='g');

    if(tamano == 'D' || tamano == 'd'){
    	tablero(4);
	}if(tamano == 'N' || tamano == 'n'){
    	tablero(5);
	}if(tamano == 'G' || tamano == 'g'){
    	tablero(6);  
    }
    if (tema== 'A'||tema=='a'){
    	tema_elegido== Literatura; 
	}
	if (tema=='E'|| tema =='e'){
		tema_elegido==Entretenimiento; 
	}
	if (tema=='G'|| tema =='g'){
		tema_elegido==Geografia; 
	}
	printf("\n"); 
	 
	if(tamano == 'D' || tamano == 'd'){
    	dado_elegido= DadoDiminuto(x); 
	}if(tamano == 'N' || tamano == 'n'){
    	dado_elegido= DadoMediano(x); 
	}if(tamano == 'G' || tamano == 'g'){
    	dado_elegido=Dado(x);  
	printf("\n"); 
	
	if (jugador_elegido){
		turno=0; 
	} if (jugador_no_elegido){
		turno=1; 
	}
	if(turno==0){
        printf("Turno jugador %s\n", jugador_elegido);
        printf("El resultado del dado: %d\n",dado_elegido);
        suma1+=dado_elegido; 
        printf("Posicion %s -[%d]\n",suma1);
        if(tamano=='D'|| tamano=='d'){
			if (tablero[1][3]==0|| tablero[2][2]==0||tablero[2][4]==0||tablero[3][1]==0||tablero[3][3]==0||tablero[4][2]==0||tablero[4][4]==0){
		printf("Jugador %c--> Has caido en la oca, acierta la siguiente pregunta para continuar avanzando", jugadores[0]avatar);}
		//hay que poner la funcion de las preguntas y respuestas
		}
		if(tamano=='M'|| tamano=='m'){
			if (tablero[1][3]==0|| tablero[1][5]==0||tablero[2][2]==0||tablero[2][4]==0||tablero[3][1]==0||tablero[3][3]==0||tablero[3][4]==0||tablero[4][2]==0||tablero[4][4]==0||tablero[5][3]==0||tablero[5][5]==0){
			printf("Jugador %c--> Has caido en la oca, acierta la siguiente pregunta para continuar avanzando", jugadores[0].avatar);
			//hay que poner la funcion de las preguntas y respuestas 
			}
		}
		if(tamano=='G'|| tamano=='g'){
			if (tablero[1][3]==0||tablero[1][5]==0||tablero[2][2]==0||tablero[2][4]==0||tablero[2][6]==0||tablero[3][1]==0||tablero[3][3]==0||tablero[3][5]==0||tablero[4][2]==0||tablero[4][4]==0||tablero[4][6]==0||tablero[5][1]==0||tablero[5][3]==0||tablero[5][5]==0||tablero[6][2]==0||tablero[6][4]==0||tablero[6][6]==0){
			printf("Jugador %c--> Has caido en la oca, acierta la siguiente pregunta para continuar avanzando", jugadores[0].avatar); 
			//hay que poner la funcion de las preguntas y respuestas 
		}
		}
		else if(turno==1){
        printf("Turno jugador %s\n", jugador_no_elegido);
        printf("El resultado del dado: %d\n",dado_elegido);
    	suma2+=dado_elegido; 
    	printf("Posicion %s-[%d]\n",suma2);
   		}
   		if(tamano=='D'|| tamano=='d'){
			if (tablero[1][3]==1|| tablero[2][2]==1||tablero[2][4]==1||tablero[3][1]==1||tablero[3][3]==1||tablero[4][2]==1||tablero[4][4]==1){
		printf("Jugador %c--> Has caido en la oca, acierta la siguiente pregunta para continuar avanzando", jugadores[0]avatar);}
		//hay que poner la funcion de las preguntas y respuestas
		}
		if(tamano=='M'|| tamano=='m'){
			if (tablero[1][3]==1|| tablero[1][5]==1||tablero[2][2]==1||tablero[2][4]==1||tablero[3][1]==1||tablero[3][3]==1||tablero[3][4]==1||tablero[4][2]==1||tablero[4][4]==1||tablero[5][3]==1||tablero[5][5]==1){
			printf("Jugador %c--> Has caido en la oca, acierta la siguiente pregunta para continuar avanzando", jugadores[0].avatar);
			//hay que poner la funcion de las preguntas y respuestas 
			}
		}
		if(tamano=='G'|| tamano=='g'){
			if (tablero[1][3]==1||tablero[1][5]==1||tablero[2][2]==1||tablero[2][4]==1||tablero[2][6]==1||tablero[3][1]==1||tablero[3][3]==1||tablero[3][5]==1||tablero[4][2]==1||tablero[4][4]==1||tablero[4][6]==1||tablero[5][1]==1||tablero[5][3]==1||tablero[5][5]==1||tablero[6][2]==1||tablero[6][4]==1||tablero[6][6]==1){
			printf("Jugador %c--> Has caido en la oca, acierta la siguiente pregunta para continuar avanzando", jugadores[0].avatar); 
			//hay que poner la funcion de las preguntas y respuestas 
		}
	}
	return 0;  
}
