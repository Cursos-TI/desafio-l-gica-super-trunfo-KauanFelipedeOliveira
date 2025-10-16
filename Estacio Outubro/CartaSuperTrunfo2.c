#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta do Super Trunfo
struct Carta {
    char nomePais[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
};

int main() {
    struct Carta carta1 = {"Brasil", 214000000, 8515767.0, 2200000000000.0, 45, 0};
    struct Carta carta2 = {"Argentina", 45380000, 2780400.0, 640000000000.0, 30, 0};

    // Calcula a densidade demográfica
    carta1.densidadeDemografica = carta1.populacao / carta1.area;
    carta2.densidadeDemografica = carta2.populacao / carta2.area;

    int opcao;

    printf("===== SUPER TRUNFO - COMPARACAO DE PAISES =====\n\n");
    printf("Carta 1: %s\n", carta1.nomePais);
    printf("Carta 2: %s\n\n", carta2.nomePais);

    printf("Escolha o atributo para comparacao:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");
    printf("\nDigite a opcao desejada: ");
    scanf("%d", &opcao);

    printf("\n=== RESULTADO ===\n");

    switch (opcao) {
        case 1:
            printf("Atributo: Populacao\n");
            printf("%s: %d habitantes\n", carta1.nomePais, carta1.populacao);
            printf("%s: %d habitantes\n", carta2.nomePais, carta2.populacao);

            if (carta1.populacao > carta2.populacao)
                printf("Vencedor: %s\n", carta1.nomePais);
            else if (carta2.populacao > carta1.populacao)
                printf("Vencedor: %s\n", carta2.nomePais);
            else
                printf("Empate!\n");
            break;

        case 2:
            printf("Atributo: Area\n");
            printf("%s: %.2f km²\n", carta1.nomePais, carta1.area);
            printf("%s: %.2f km²\n", carta2.nomePais, carta2.area);

            if (carta1.area > carta2.area)
                printf("Vencedor: %s\n", carta1.nomePais);
            else if (carta2.area > carta1.area)
                printf("Vencedor: %s\n", carta2.nomePais);
            else
                printf("Empate!\n");
            break;

        case 3:
            printf("Atributo: PIB\n");
            printf("%s: R$ %.2f\n", carta1.nomePais, carta1.pib);
            printf("%s: R$ %.2f\n", carta2.nomePais, carta2.pib);

            if (carta1.pib > carta2.pib)
                printf("Vencedor: %s\n", carta1.nomePais);
            else if (carta2.pib > carta1.pib)
                printf("Vencedor: %s\n", carta2.nomePais);
            else
                printf("Empate!\n");
            break;

        case 4:
            printf("Atributo: Pontos Turisticos\n");
            printf("%s: %d pontos\n", carta1.nomePais, carta1.pontosTuristicos);
            printf("%s: %d pontos\n", carta2.nomePais, carta2.pontosTuristicos);

            if (carta1.pontosTuristicos > carta2.pontosTuristicos)
                printf("Vencedor: %s\n", carta1.nomePais);
            else if (carta2.pontosTuristicos > carta1.pontosTuristicos)
                printf("Vencedor: %s\n", carta2.nomePais);
            else
                printf("Empate!\n");
            break;

        case 5:
            printf("Atributo: Densidade Demografica\n");
            printf("%s: %.6f hab/km²\n", carta1.nomePais, carta1.densidadeDemografica);
            printf("%s: %.6f hab/km²\n", carta2.nomePais, carta2.densidadeDemografica);

            // Regra invertida: menor valor vence
            if (carta1.densidadeDemografica < carta2.densidadeDemografica) {
                printf("Vencedor: %s (menor densidade)\n", carta1.nomePais);
            } else if (carta2.densidadeDemografica < carta1.densidadeDemografica) {
                printf("Vencedor: %s (menor densidade)\n", carta2.nomePais);
            } else {
                printf("Empate!\n");
            }
            break;

        default:
            printf("Opcao invalida! Escolha um numero entre 1 e 5.\n");
            break;
    }

    printf("\n=== Fim da comparacao ===\n");

    return 0;
}
