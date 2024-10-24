#include <stdio.h>
#include <stdlib.h>

void Historico(int *sumaX, int *sumaO, int ganadorX, int ganadorO) {

    if (ganadorX == 1) {
        (*sumaX)++;
    }
    if (ganadorO == 1) {
        (*sumaO)++;
    }

    printf("La cantidad de veces que X ha ganado es: %d\n", *sumaX);
    printf("La cantidad de veces que O ha ganado es: %d\n", *sumaO);


}

int Ganador(char tablero[3][3], int *ganadorX, int *ganadorO) {

    int i, j;

    for (i = 0; i < 3; i++) {
        if (tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2] && tablero[i][0] != '\0') {
            if (tablero[i][0] == 'X') {
                printf("Jugador X ha ganado\n");
                *ganadorX = 1;
            } else if (tablero[i][0] == 'O') {
                printf("Jugador O ha ganado\n");
                *ganadorO = 1;
            }
        }
    }

    for (j = 0; j < 3; j++) {
        if (tablero[0][j] == tablero[1][j] && tablero[1][j] == tablero[2][j] && tablero[0][j] != '\0') {
            if (tablero[0][j] == 'X') {
                printf("Jugador X ha ganado\n");
                *ganadorX = 1;
            } else if (tablero[0][j] == 'O') {
                printf("Jugador O ha ganado\n");
                *ganadorO = 1;
            }
        }
    }

    if (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2] && tablero[0][0] != '\0') {
        if (tablero[0][0] == 'X') {
            printf("Jugador X ha ganado\n");
            *ganadorX = 1;
        } else if (tablero[0][0] == 'O') {
            printf("Jugador O ha ganado\n");
            *ganadorO = 1;
        }
    }

    if (tablero[2][0] == tablero[1][1] && tablero[1][1] == tablero[0][2] && tablero[2][0] != '\0') {
        if (tablero[2][0] == 'X') {
            printf("Jugador X ha ganado\n");
            *ganadorX = 1;
        } else if (tablero[2][0] == 'O') {
            printf("Jugador O ha ganado\n");
            *ganadorO = 1;
        }
    }
}

int limpiar(char tablero[3][3]) {

    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {

            tablero[i][j] = '\0';
        }
    }
    return 0;
}

int imprimir(char tablero[3][3]){

    int i, j;

    for ( i = 0; i < 3; i++) {
        for ( j = 0; j < 3; j++){

            printf("[ %c ]",tablero[i][j]);
            
        }

        printf("\n");

    }

    return 0;

}

int modificarX(char tablero[3][3],int fila,int columna){

    if (tablero[fila][columna] == '\0') {

    tablero[fila][columna] = 'X';

    }else {

    printf("Esa posicion ya esta ocupada!\n");

}

    return 0;

}

int modificarO(char tablero[3][3],int fila,int columna){

    if (tablero[fila][columna] == '\0') {

        tablero[fila][columna] = 'O';

    }else {

        printf("Esa posicion ya esta ocupada!\n");

    }

}

int main() {
    int Tablero[3][3];
    int fila,columna,opcion, ganadorX, ganadorO;
    int turno = 0;
    int historicoX[10],historicoO[10];
    int sumaX = 0, sumaO = 0;

    do {
        printf("1.-Limpiar tablero\n");
        printf("2.-Jugar\n");
        printf("3. Historico\n");
        printf("4. Salir\n");
        printf("Que operacion quieres hacer? ");
        scanf("%d", &opcion);



        switch (opcion) {

            case 1:

            limpiar(Tablero);
            imprimir(Tablero);

            turno = 0;
            ganadorX = 0;
            ganadorO = 0;

            break;

            case 2:

            turno = 0;
            ganadorX = 0;
            ganadorO = 0;

                do {

                    ganadorO = 0;
                    ganadorX = 0;

                    printf("Jugador X\n");

                    printf("Ingresa la coordenada 1: ");
                    scanf("%d",&fila);
                    printf("Ingresa la coordenada 2: ");
                    scanf("%d",&columna);

                    modificarX(Tablero,fila,columna);

                    imprimir(Tablero);

                    Ganador(Tablero, &ganadorX, &ganadorO);

                    if (ganadorX == 1 || ganadorO == 1) {
                        break;
                    }

                    printf("Jugador O\n");

                    printf("Ingresa la coordenada 1: ");
                    scanf("%d",&fila);
                    printf("Ingresa la coordenada 2: ");
                    scanf("%d",&columna);

                    modificarO(Tablero,fila,columna);
                    imprimir(Tablero);

                    Ganador(Tablero, &ganadorX,&ganadorO);

                    turno++;

                    if (turno == 8 && ganadorX == 0 && ganadorO == 0) {

                        printf("Empate!\n");

                        break;
                    }

                } while (ganadorX != 1 && ganadorO != 1);

            break;

            case 3:

            printf("Historico:\n");

            Historico(&sumaX, &sumaO, ganadorX, ganadorO);

            break;

            default:

            printf("Opcion no valida!\n");

            break;

        }

    } while (opcion != 4);

    return 0;
}