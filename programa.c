#include<stdio.h>
#define TAM_MAX 50
#include<windows.h>
#define color SetConsoleTextAttribute

void Banner (){
	HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
	printf ("Bienvenido a Infinity_ITS, esperamos que pases un gran rato y disfrutes del juego\n");
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

int main (){
	struct TJugador jugadores[TAM_MAX];
	int i, n_jugadores; //n_jugadores se refiere al número de jugadores
	char opcion1;
	Banner();
	opcion1= menu();
	printf ("Inserte el numero de jugadores\n");
	scanf ("%d", &n_jugadores);

	for (i=0; i<n_jugadores; i++){
		printf("Nombre del jugador %d:\n",i+1);
		scanf("%s", jugadores[i].avatar);
	}

	printf("El juego va a iniciar. PREPARATE PARA AVERIGUAR COMO DE LIST@ ERES!\n");

	char tamano;
	do{
		fflush(stdin);
		printf("Como de grande quiere el tablero?\n");
		printf("D- Diminuto (16 casillas)\n");
		printf("N- Normalito (25 casillas)\n");
	    printf("G- Grandote (36 casillas)\n");
		scanf("%c", &tamano);

	    if(tamano !='D' && tamano !='d' && tamano !='N' && tamano !='n' && tamano !='G' && tamano !='g'){
			printf("Esa opcion no es valida!! Vuelve a intentarlo!!\n");
			scanf("%c", & tamano);
		}

	}while(tamano !='D' && tamano !='d' && tamano !='N' && tamano !='n' && tamano !='G' && tamano !='g');

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



    //Posible fichero:
    struct Tcuestiones cuestion[TAM_MAX];
    FILE *fichero;
    int i, contador;


    fichero = fopen("Fichero literatura y arte.txt", "r");

        if (fichero == NULL) {
                printf("Error de lectura\n");
                return 0;
        }
        i=0;
        contador=0;
        while (fscanf(fichero, "%s %s ", cuestion[i].pregunta, cuestion[i].respuesta) != EOF) {
                printf("%s %s\n", cuestion[i].pregunta, cuestion[i].respuesta);
                i++;
                contador++;
        }
        fclose(fichero);

	return 0;
}


