#include<stdio.h>
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

    if (tam==5){
    	for(fila=1;fila<=tam;fila++) {
         printf("\n");
         for(columna=1;columna<=tam+1;columna++) {
         	if(columna==1){
         		printf("   %d",fila);
             }else if(columna == 2 && fila == tam){
             	printf("|_E_|");
             }else if(columna == tam+1 && fila == 1){
             	printf("|_F_|");
			 }else if(columna % 2 == 0 && fila % 2 != 0){
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
	}else{
		for(fila=1;fila<=tam;fila++) {
         printf("\n");
         for(columna=1;columna<=tam+1;columna++) {
         	if(columna==1){
         		printf("   %d",fila);
             }else if(columna == 2 && fila == tam){
             	printf("|_E_|");
             }else if(columna == tam+1 && fila == tam){
             	printf("|_F_|");
			 }else if(columna % 2 == 0 && fila % 2 != 0){
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
	}
    
    int valor=1;
	printf("\n\n");
	printf("Tablero de posiciones:\n");
	printf("\n");
	for(columna=1;columna<=tam;columna++){
		if(columna % 2==0){
			for(fila=1;fila<=tam;fila++){
				matriz[fila][columna]=valor;
				valor++;
			}
		}else{
			for(fila=tam;fila>=1;fila--){
				matriz[fila][columna]=valor;
				valor++;
			}
		}
	}
	
	for(fila=1;fila<=tam;fila++){
		for(columna=1;columna<=tam;columna++){
			printf("   %d ",matriz[fila][columna]);
		}
		printf("\n");
	}
    printf("\n");
}

int Dado (int x){
	int i; 
	int dado;
	
	do{
		printf("Pulse '0' para lanzar el dado\n"); 
	    scanf("%d", &x);
	    
	    if(x!=0){
	    	printf("Ese valor no es valido\n");
		}
	}while(x!=0);
	 
	if (x==0){
			srand (time(0)); 
		for (i=0; i<7; i++){
			dado= 1+ (rand ()%6); 
		}
	}
	return dado; 
}

int DadoMediano (int x){ //Es un dado con 5 números máximo
	int i; 
	int dado; 
	
	do{
		printf("Pulse '0' para lanzar el dado\n"); 
	    scanf("%d", &x);
	    
	    if(x!=0){
	    	printf("Ese valor no es valido\n");
		}
	}while(x!=0);
	
	if (x==0){
			srand (time(0)); 
		for (i=0; i<7; i++){
			dado= 1+ (rand ()%5); 
		}
	}
	return dado; 
}

int DadoDiminuto (int x){ //Es un dado de máximo 4 números 
	int i; 
	int dado;
	
	do{
		printf("Pulse '0' para lanzar el dado\n"); 
	    scanf("%d", &x);
		
		if(x != 0){
			printf("Ese valor no es valido\n");
		} 
	}while(x!=0); 
	
	if (x==0){
			srand (time(0)); 
		for (i=0; i<7; i++){
			dado= 1+ (rand ()%4); 
		}
	}
	return dado;
}

struct TRespuesta{
	char respuesta[100];
};

int pregunta(char tema, int suma){
	
	FILE *entrada;
	FILE *respuesta;
    int c, c1, x, i, j;
    char texto[150], solucion[100];
    struct TRespuesta resp[150];
    
    printf("***ADVERTENCIA***\n");
    printf("Cuando escriba su respuesta si quiere poner espacio ponga barra baja '_',\n"); 
	printf("escriba los numeros con letra y todo en minuscula y sin tildes, GRACIAS!!! \n");
	printf("\n");
	
	if(tema == 'G' || tema == 'g'){
		         	  
		entrada=fopen("PREGUNTAS_geografia_e_historia.txt", "r");
	        if (entrada == NULL) {
                 printf("Error de lectura\n");
                 exit(1); 
           }
           
        respuesta=fopen("RESPUESTAS_geografia_e_historia.txt", "r");
	        if (respuesta == NULL) {
                 printf("Error de lectura\n");
                 exit(1); 
           }
                        
        do{
        	printf("Introduce un numero del 1 al 24\n"); 
	        scanf("%d", &x);
	        
	        if(x<=0 || x>=25){
	        	printf("Ese valor no es valido\n");
			}
			
		}while(x<=0 || x>=25);

        while (fgets(texto,150,entrada)) {
        	if(++i==x){
     		    printf("%s",texto);
     		}	
		}
        
        i=1;
        while (fscanf(respuesta, "%s", resp[i].respuesta) != EOF) {
        	if(i == x){
        	     resp[i].respuesta == resp[x].respuesta;
			}
			i++;               
        }
        
        scanf("%s",solucion);
        
        if(strcmp(solucion,resp[x].respuesta) == 0){
        	printf("ENHORABUENA!! has acetardo!! tu puntucion permanece como %d :)\n", suma);
		}else{
			suma = suma - 3;
			printf("Lo sentimos, has fallado, restrocedes tres casillas, ahora su puntuacion es %d :(\n",suma);
		}
        
        fclose(entrada);
	    fclose(respuesta);
	                    
	}
	if(tema == 'A' || tema == 'a'){
		         	  
		entrada=fopen("PREGUNTAS_literatura_y_arte.txt", "r");
	        if (entrada == NULL) {
                 printf("Error de lectura\n");
                 exit(1); 
            }
        
        respuesta=fopen("RESPUESTAS_literatura_y_arte.txt", "r");
	        if (respuesta == NULL) {
                 printf("Error de lectura\n");
                 exit(1); 
           }
                        
        do{
        	printf("Introduce un numero del 1 al 24\n"); 
	        scanf("%d", &x);
	        
	        if(x<=0 || x>=25){
	        	printf("Ese valor no es valido\n");
			}
			
		}while(x<=0 || x>=25);
		

        while (fgets(texto,150,entrada)) {
     	     if(++i==x){
     		     printf("%s",texto);
		        }
        }
        
        i=1;
        while (fscanf(respuesta, "%s", resp[i].respuesta) != EOF) {
        	if(i == x){
        	     resp[i].respuesta == resp[x].respuesta;
			}
			i++;               
        }
        
        scanf("%s",solucion);
        
        if(strcmp(solucion,resp[x].respuesta) == 0){
        	printf("ENHORABUENA!! has acetardo!! tu puntucion permanece como %d :)\n", suma);
		}else{
			suma = suma - 3;
			printf("Lo sentimos, has fallado, restrocedes tres casillas, ahora su puntuacion es %d :(\n",suma);
		}
		
        fclose(entrada);
	    fclose(respuesta);
	                    
	}
	if(tema == 'E' || tema == 'e'){
		         	  
		entrada=fopen("PREGUNTAS_entretenimiento.txt", "r");
	        if (entrada == NULL) {
                 printf("Error de lectura\n");
                 exit(1); 
            }
        
        respuesta=fopen("RESPUESTAS_entretenimiento.txt", "r");
	        if (respuesta == NULL) {
                 printf("Error de lectura\n");
                 exit(1); 
           }
                        
       do{
        	printf("Introduce un numero del 1 al 24\n"); 
	        scanf("%d", &x);
	        
	        if(x<=0 || x>=25){
	        	printf("Ese valor no es valido\n");
			}
			
		}while(x<=0 || x>=25);

        while (fgets(texto,150,entrada)) {
     	     if(++i==x){
     		     printf("%s",texto);
		        }
        }
        
        i=1;
        while (fscanf(respuesta, "%s", resp[i].respuesta) != EOF) {
        	if(i == x){
        	     resp[i].respuesta == resp[x].respuesta;
			}
			i++;               
        }
        
        scanf("%s",solucion);
        
        if(strcmp(solucion,resp[x].respuesta) == 0){
        	printf("ENHORABUENA!! has acetardo!! tu puntucion permanece como %d :)\n", suma);
		}else{
			suma = suma - 3;
			printf("Lo sentimos, has fallado, restrocedes tres casillas, ahora su puntuacion es %d :(\n",suma);
		}
		
        fclose(entrada);
	    fclose(respuesta);
	    
	}
	return suma;
}
    
int main (void){
	struct TJugador jugadores[TAM_MAX]; 
	int i, n_jugadores,x, dado_elegido, suma1=0,suma2=0, turno, tam, num; //n_jugadores se refiere al número de jugadores
	char opcion1, jugador_elegido[50], jugador_no_elegido[50], tema_elegido[50], ganador[50]; 
	int fila, columna, matriz[100][100];
	Banner(); 
	opcion1= menu();
	
	do{
		printf ("Desea jugar en pareja o solo?\n"); 
	    printf (" Pulse 1 si jugara solo\n"); 
	    printf (" Pulse 2 si jugara en pareja\n"); 
	    scanf ("%d", &n_jugadores); 
	    
	    if(n_jugadores != 1 && n_jugadores !=2){
	    	printf("Ese numero no es valido, introduce uno de los indicados.\n");
		}
		
	}while(n_jugadores != 1 && n_jugadores !=2);
	 
	
	for (i=0; i<n_jugadores; i++){
		printf("Nombre del jugador %d:\n",i+1); 
		scanf("%s", jugadores[i].avatar); 
	} 
	 //ahora vamos a ver que jugador empieza en caso de que sean dos jugadores
	int numero[1]; 
	if (n_jugadores==2){
	do{
		printf("\n"); 
		printf("Ahora cada jugador lanzara el dado y el que obtenga\n");
		printf("el mayor numero sera el primero en empezar la partida.\n");
		for (i=0; i<2; i++){
			printf("--> Lanza el dado %s\n",jugadores[i].avatar);
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
	}else{
	    strcpy(jugador_elegido, jugadores[0].avatar);	
	}
	printf("\n"); 
	printf("El juego va a iniciar. PREPARATE PARA AVERIGUAR COMO DE LIST@ ERES!\n");
	printf("\n");
	
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
	
	if(n_jugadores == 2){
		
	
	do{	 //Realizamos el bucle para que el turno de los jugadores vaya cambiando alo largo del juego
	    printf("\n");	
		printf("--> Turno de %s\n",jugador_elegido);
		//Dependiendo del tamaño del tablero, hay distintos dados con más o menos números 
		if(tamano == 'D' || tamano == 'd'){
    	     dado_elegido= DadoDiminuto(x);
    	     tam=16;
	    }
		if(tamano == 'N' || tamano == 'n'){
    	     dado_elegido= DadoMediano(x); 
    	     tam=25;
	    }
		if(tamano == 'G' || tamano == 'g'){ 
		     dado_elegido=Dado(x);
		     tam=36; 
        }
		
	    suma1 = suma1 + dado_elegido;
	    printf("El resultado del dado es %d y lleva una suma de puntos %d\n", dado_elegido,suma1);
	    //Lo utilizamos para ver cuando el jugador 1 ha caido en la oca
	    if(tamano=='D'|| tamano=='d'){
			 if (suma1==2|| suma1==4||suma1==6||suma1==8||suma1==10||suma1==12||suma1==14){
		         printf("%s--> Has caido en la oca, acierta la siguiente pregunta para continuar avanzando\n\n", jugadores[0].avatar);
				 suma1=pregunta(tema,suma1);
		    }        
		}
		if(tamano=='N'|| tamano=='n'){
			 if (suma1==3|| suma1==5||suma1==7||suma1==9||suma1==11||suma1==13||suma1==15||suma1==17||suma1==19||suma1==21||suma1==23){
			     printf("%s--> Has caido en la oca, acierta la siguiente pregunta para continuar avanzando\n\n", jugadores[0].avatar);
			     suma1=pregunta(tema,suma1);
			     }
		}
		if(tamano=='G'|| tamano=='g'){
			if (suma1==2||suma1==4||suma1==6||suma1==8||suma1==10|| suma1==12||suma1==14||suma1==16||suma1==18||suma1==20||suma1==22||suma1==24||suma1==26||suma1==28||suma1==30||suma1==32||suma1==34){
			     printf("%s--> Has caido en la oca, acierta la siguiente pregunta para continuar avanzando\n\n", jugadores[0].avatar);
			     suma1=pregunta(tema,suma1);
		    }
		}
	    //Tenemos que ver si la suma de los jugadores es igual o mayor al tamaño del tablero para ver quien ha ganado
	    if(suma1>=tam){
	    	strcpy(ganador,jugador_elegido);
	    	printf("Enhorabuena!!! %s has llegado al final, eres el ganad@r\n",ganador);
	    	break;
		}else if(suma2>=tam){
			strcpy(ganador,jugador_no_elegido);
			printf("Enhorabuena!!! %s has llegado al final, eres el ganad@r\n",ganador);
			break;
		}
		
		printf("\n");
		printf("--> Turno de %s\n",jugador_no_elegido);
		//Dependiendo del tamaño del tablero, hay distintos dados con más o menos números 
		if(tamano == 'D' || tamano == 'd'){
    	     dado_elegido= DadoDiminuto(x);
    	     tam=16;
	    }if(tamano == 'N' || tamano == 'n'){
    	     dado_elegido= DadoMediano(x); 
    	     tam=25;
	     }if(tamano == 'G' || tamano == 'g'){ 
		     dado_elegido=Dado(x);
		     tam=36; 
         }
		
		suma2 = suma2 + dado_elegido;
	    printf("El resultado del dado es %d y lleva una suma de puntos %d\n", dado_elegido,suma2); 
	    //Lo utilizamos para ver cuando el jugador 2 ha caido en la oca
	    if(tamano=='D'|| tamano=='d'){
			 if (suma2==2|| suma2==4||suma2==6||suma2==8||suma2==10||suma2==12||suma2==14){
		         printf("%s--> Has caido en la oca, acierta la siguiente pregunta para continuar avanzando\n\n", jugadores[1].avatar);
		         suma2=pregunta(tema,suma2);
		        }
		}
		if(tamano=='N'|| tamano=='n'){
			 if (suma2==3|| suma2==5||suma2==7||suma2==9||suma2==11||suma2==13||suma2==15||suma2==17||suma2==19||suma2==21||suma2==23){
			     printf("%s--> Has caido en la oca, acierta la siguiente pregunta para continuar avanzando\n\n", jugadores[1].avatar);
			     suma2=pregunta(tema,suma2);
			    }
		}
		if(tamano=='G'|| tamano=='g'){
			 if (suma2==2||suma2==4||suma2==6||suma2==8||suma2==10|| suma2==12||suma2==14||suma2==16||suma2==18||suma2==20||suma2==22||suma2==24||suma2==26||suma2==28||suma2==30||suma2==32||suma2==34){
			     printf("%s--> Has caido en la oca, acierta la siguiente pregunta para continuar avanzando\n\n", jugadores[1].avatar); 
			     suma2=pregunta(tema,suma2); 
		    }
	    }
	    //Tenemos que ver si la suma de los jugadores es igual o mayor al tamaño del tablero para ver quien ha ganado 
	    if(suma1>=tam){
	    	strcpy(ganador,jugador_elegido);
	    	printf("Enhorabuena!!! %s has llegado al final, eres el ganad@r\n",ganador);
	    	break;
		}else if(suma2>=tam){
			strcpy(ganador,jugador_no_elegido);
			printf("Enhorabuena!!! %s has llegado al final, eres el ganad@r\n",ganador);
			break;
		}
		
	}while(suma1<=tam && suma2<=tam);
	
    }else if(n_jugadores == 1){
    	
	
	do{ 
		printf("\n"); 	
		printf("--> Turno de %s\n",jugadores[0].avatar);
		//Dependiendo del tamaño del tablero, hay distintos dados con más o menos números 
		if(tamano == 'D' || tamano == 'd'){
    	     dado_elegido= DadoDiminuto(x);
    	     tam=16;
	    }
		if(tamano == 'N' || tamano == 'n'){
    	     dado_elegido= DadoMediano(x); 
    	     tam=25;
	    }
		if(tamano == 'G' || tamano == 'g'){ 
		     dado_elegido=Dado(x);
		     tam=36; 
        }
         

	    suma1 = suma1 + dado_elegido;
	    printf("El resultado del dado es %d y lleva una suma de puntos %d\n", dado_elegido,suma1);
	    //Lo utilizamos para ver cuando el jugador ha caido en la oca
	    if(tamano=='D'|| tamano=='d'){
			 if (suma1==2|| suma1==4||suma1==6||suma1==8||suma1==10||suma1==12||suma1==14){
		         printf("%s--> Has caido en la oca, acierta la siguiente pregunta para continuar avanzando\n\n", jugadores[0].avatar);
		         suma1=pregunta(tema,suma1);
		    }        
		}
		if(tamano=='N'|| tamano=='n'){
			 if (suma1==3|| suma1==5||suma1==7||suma1==9||suma1==11||suma1==13||suma1==15||suma1==17||suma1==19||suma1==21||suma1==23){
			     printf("%s--> Has caido en la oca, acierta la siguiente pregunta para continuar avanzando\n\n", jugadores[0].avatar);
			     suma1=pregunta(tema,suma1);
			}
		}
		if(tamano=='G'|| tamano=='g'){
			if (suma1==2||suma1==4||suma1==6||suma1==8||suma1==10|| suma1==12||suma1==14||suma1==16||suma1==18||suma1==20||suma1==22||suma1==24||suma1==26||suma1==28||suma1==30||suma1==32||suma1==34){
			     printf("%s--> Has caido en la oca, acierta la siguiente pregunta para continuar avanzando\n\n", jugadores[0].avatar);
			     suma1=pregunta(tema,suma1);
		    }
		}
		
		//Tenemos que ver si la suma del  jugador es igual o mayor al tamaño del tablero para ver si ha ganado 
	    if(suma1>=tam){
	    	strcpy(ganador,jugadores[0].avatar);
	    	printf("Enhorabuena!!! %s has llegado al final, eres el ganad@r\n", ganador);
	    	break;
		}
		
	}while(suma1<=tam); 
	
    }
	
	
	
	return 0;  
}

