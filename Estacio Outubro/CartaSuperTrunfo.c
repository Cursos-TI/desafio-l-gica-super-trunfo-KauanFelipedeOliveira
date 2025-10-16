#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta do Super Trunfo
struct Carta {
    char estado[3];
    char codigo[5];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int numPontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

int main() {
    // Cadastro das duas cartas
    struct Carta carta1 = {"SP", "A01", "São Paulo", 12300000, 1521.11, 699000000000.0, 50};
    struct Carta carta2 = {"RJ", "A02", "Rio de Janeiro", 6748000, 1200.27, 460000000000.0, 40};

    // Cálculos automáticos
    carta1.densidadePopulacional = carta1.populacao / carta1.area;
    carta2.densidadePopulacional = carta2.populacao / carta2.area;

    carta1.pibPerCapita = carta1.pib / carta1.populacao;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;

    // Escolha do atributo para comparação:
    // 1 - População
    // 2 - Área
    // 3 - PIB
    // 4 - Densidade Populacional
    // 5 - PIB per Capita
    int atributoEscolhido = 1;  // <-- troque aqui o número do atributo para mudar a comparação

    printf("=== COMPARACAO DE CARTAS ===\n");

    switch (atributoEscolhido) {
        case 1: // População
            printf("\nAtributo: População\n");
            printf("%s (%s): %d habitantes\n", carta1.nomeCidade, carta1.estado, carta1.populacao);
            printf("%s (%s): %d habitantes\n", carta2.nomeCidade, carta2.estado, carta2.populacao);

            if (carta1.populacao > carta2.populacao)
                printf("\nResultado: %s venceu!\n", carta1.nomeCidade);
            else if (carta2.populacao > carta1.populacao)
                printf("\nResultado: %s venceu!\n", carta2.nomeCidade);
            else
                printf("\nEmpate!\n");
            break;

        case 2: // Área
            printf("\nAtributo: Área\n");
            printf("%s: %.2f km²\n", carta1.nomeCidade, carta1.area);
            printf("%s: %.2f km²\n", carta2.nomeCidade, carta2.area);

            if (carta1.area > carta2.area)
                printf("\nResultado: %s venceu!\n", carta1.nomeCidade);
            else if (carta2.area > carta1.area)
                printf("\nResultado: %s venceu!\n", carta2.nomeCidade);
            else
                printf("\nEmpate!\n");
            break;

        case 3: // PIB
            printf("\nAtributo: PIB\n");
            printf("%s: R$ %.2f\n", carta1.nomeCidade, carta1.pib);
            printf("%s: R$ %.2f\n", carta2.nomeCidade, carta2.pib);

            if (carta1.pib > carta2.pib)
                printf("\nResultado: %s venceu!\n", carta1.nomeCidade);
            else if (carta2.pib > carta1.pib)
                printf("\nResultado: %s venceu!\n", carta2.nomeCidade);
            else
                printf("\nEmpate!\n");
            break;

        case 4: // Densidade Populacional (menor vence)
            printf("\nAtributo: Densidade Populacional\n");
            printf("%s: %.2f hab/km²\n", carta1.nomeCidade, carta1.densidadePopulacional);
            printf("%s: %.2f hab/km²\n", carta2.nomeCidade, carta2.densidadePopulacional);

            if (carta1.densidadePopulacional < carta2.densidadePopulacional)
                printf("\nResultado: %s venceu!\n", carta1.nomeCidade);
            else if (carta2.densidadePopulacional < carta1.densidadePopulacional)
                printf("\nResultado: %s venceu!\n", carta2.nomeCidade);
            else
                printf("\nEmpate!\n");
            break;

        case 5: // PIB per Capita
            printf("\nAtributo: PIB per Capita\n");
            printf("%s: R$ %.2f\n", carta1.nomeCidade, carta1.pibPerCapita);
            printf("%s: R$ %.2f\n", carta2.nomeCidade, carta2.pibPerCapita);

            if (carta1.pibPerCapita > carta2.pibPerCapita)
                printf("\nResultado: %s venceu!\n", carta1.nomeCidade);
            else if (carta2.pibPerCapita > carta1.pibPerCapita)
                printf("\nResultado: %s venceu!\n", carta2.nomeCidade);
            else
                printf("\nEmpate!\n");
            break;

        default:
            printf("Atributo inválido!\n");
    }

    return 0;
}
