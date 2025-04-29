#include <stdio.h>
#include <string.h>

int main() {
    int EQUIPOS    = 4;
    int MAX_NOMBRE = 30;

    char nombres[EQUIPOS][MAX_NOMBRE];
    int  golesFavor[EQUIPOS];
    int  golesContra[EQUIPOS];
    int  diferencia[EQUIPOS];
    int  i, valor, valido;

  
    for (i = 0; i < EQUIPOS; i++) {
        do {
            valido = 1;
            printf("Ingrese nombre del equipo %d: ", i + 1);
            fflush(stdin);
           
            if (scanf("%29[^\n]", nombres[i]) != 1) {
                printf("  Nombre invalido. No puede estar vacio.\n");
                valido = 0;
            }
            fflush(stdin);
            if (valido && strlen(nombres[i]) == 0) {
                printf("  Nombre invalido. No puede estar vacio.\n");
                valido = 0;
            }
        } while (!valido);
    }

 
    for (i = 0; i < EQUIPOS; i++) {
     
        do {
            valido = 1;
            printf("Ingrese goles a favor de %s: ", nombres[i]);
            fflush(stdin);
            if (scanf("%d", &valor) != 1) {
                printf("  Entrada invalida. Debe ser un numero entero.\n");
                valido = 0;
            } else if (valor < 0) {
                printf("  Numero invalido. No puede ser negativo.\n");
                valido = 0;
            }
            fflush(stdin);
        } while (!valido);
        golesFavor[i] = valor;

       
        do {
            valido = 1;
            printf("Ingrese goles en contra de %s: ", nombres[i]);
            fflush(stdin);
            if (scanf("%d", &valor) != 1) {
                printf("  Entrada invalida. Debe ser un numero entero.\n");
                valido = 0;
            } else if (valor < 0) {
                printf("  Numero invalido. No puede ser negativo.\n");
                valido = 0;
            }
            fflush(stdin);
        } while (!valido);
        golesContra[i] = valor;
    }

    
    for (i = 0; i < EQUIPOS; i++) {
        diferencia[i] = golesFavor[i] - golesContra[i];
    }

   
    int primero = 0, segundo = 1;
    if (diferencia[1] > diferencia[0]) {
        primero = 1; segundo = 0;
    }
    for (i = 2; i < EQUIPOS; i++) {
        if (diferencia[i] > diferencia[primero]) {
            segundo = primero;
            primero = i;
        } else if (diferencia[i] > diferencia[segundo]) {
            segundo = i;
        }
    }

   
    printf("\n+------------------------------+-------+-------+-------------------+\n");
    printf("| Equipo                       |  GF   |  GC   | Dif. de goles     |\n");
    printf("+------------------------------+-------+-------+-------------------+\n");
    for (i = 0; i < EQUIPOS; i++) {
        printf("| %-28s | %5d | %5d | %17d |\n",
               nombres[i], golesFavor[i], golesContra[i], diferencia[i]);
    }
    printf("+------------------------------+-------+-------+-------------------+\n");

    
    printf("\nFinalistas del cuadrangular:\n");
    printf("  1er lugar: %s (Dif. de goles = %d)\n",
           nombres[primero], diferencia[primero]);
    printf("  2do lugar: %s (Dif. de goles = %d)\n",
           nombres[segundo], diferencia[segundo]);

    return 0;
}
