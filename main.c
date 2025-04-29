#include <stdio.h>
#include <string.h>

int main() {
    char equipos[4][30];
    int golesFavor[4] = {0};
    int golesContra[4] = {0};
    int diferencia[4] = {0};
    int puntos[4] = {0};
    int indices[4];
    int i, j;

    // Lectura de nombres de los equipos
    for (i = 0; i < 4; i++) {
        printf("Introduce nombre del equipo %d: ", i + 1);
        scanf("%29s", equipos[i]);
        fflush(stdin);  // limpia buffer de entrada
    }

    // Calculo de resultados de los 6 partidos
    for (i = 0; i < 3; i++) {
        for (j = i + 1; j < 4; j++) {
            int g1, g2;
            // Goles equipo i
            do {
                printf("\nPartido: %s vs %s\n", equipos[i], equipos[j]);
                printf("  Goles de %s: ", equipos[i]);
                if (scanf("%d", &g1) != 1 || g1 < 0) {
                    printf("    Error: introduce un numero valido >= 0.\n");
                    fflush(stdin);
                } else break;
            } while (1);
            fflush(stdin);
            // Goles equipo j
            do {
                printf("  Goles de %s: ", equipos[j]);
                if (scanf("%d", &g2) != 1 || g2 < 0) {
                    printf("    Error: introduce un numero valido >= 0.\n");
                    fflush(stdin);
                } else break;
            } while (1);
            fflush(stdin);

            // Actualiza goles a favor y en contra
            golesFavor[i] += g1;
            golesContra[i] += g2;
            golesFavor[j] += g2;
            golesContra[j] += g1;

            // Asigna puntos segun resultado
            if (g1 > g2) {
                puntos[i] += 3;
            } else if (g2 > g1) {
                puntos[j] += 3;
            } else {
                puntos[i] += 1;
                puntos[j] += 1;
            }
        }
    }

    // Calcula diferencia de goles e inicializa indices
    for (i = 0; i < 4; i++) {
        diferencia[i] = golesFavor[i] - golesContra[i];
        indices[i] = i;
    }

    // Ordena equipos por puntos y diferencia de goles (metodo burbuja)
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3 - i; j++) {
            int a = indices[j];
            int b = indices[j + 1];
            if (puntos[a] < puntos[b] ||
                (puntos[a] == puntos[b] && diferencia[a] < diferencia[b])) {
                int temp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp;
            }
        }
    }

    // Imprime tabla de posiciones
    printf("\nTabla de posiciones:\n");
    printf("Equipo\t\tPuntos\tGF\tGC\tGD\n");
    for (i = 0; i < 4; i++) {
        int idx = indices[i];
        printf("%-10s\t%3d\t%3d\t%3d\t%3d\n", equipos[idx], puntos[idx], golesFavor[idx], golesContra[idx], diferencia[idx]);
    }

    // Finalistas
    printf("\nFinalistas:\n");
    printf("1. %s\n", equipos[indices[0]]);
    printf("2. %s\n", equipos[indices[1]]);

    return 0;
}

