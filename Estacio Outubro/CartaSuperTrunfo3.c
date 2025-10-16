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

// Função auxiliar para exibir o menu de atributos
void exibirMenu(int atributoBloqueado) {
    printf("\nEscolha um atributo:\n");
    if (atributoBloqueado != 1) printf("1 - População\n");
    if (atributoBloqueado != 2) printf("2 - Área\n");
    if (atributoBloqueado != 3) printf("3 - PIB\n");
    if (atributoBloqueado != 4) printf("4 - Pontos Turísticos\n");
    if (atributoBloqueado != 5) printf("5 - Densidade Demográfica\n");
    printf("Digite sua opção: ");
}

int main() {
    struct Carta carta1 = {"Brasil", 214000000, 8515767.0, 2200000000000.0, 45, 0};
    struct Carta carta2 = {"Argentina", 45380000, 2780400.0, 640000000000.0, 30, 0};

    // Calcula a densidade demográfica
    carta1.densidadeDemografica = carta1.populacao / carta1.area;
    carta2.densidadeDemografica = carta2.populacao / carta2.area;

    int atributo1, atributo2;
    float valor1Carta1, valor1Carta2;
    float valor2Carta1, valor2Carta2;
    float soma1, soma2;

    printf("===== SUPER TRUNFO - NIVEL MESTRE =====\n\n");
    printf("Carta 1: %s\n", carta1.nomePais);
    printf("Carta 2: %s\n", carta2.nomePais);

    // ==========================
    // Escolha do primeiro atributo
    // ==========================
    do {
        exibirMenu(0);
        scanf("%d", &atributo1);

        if (atributo1 < 1 || atributo1 > 5)
            printf("Opção inválida! Escolha entre 1 e 5.\n");

    } while (atributo1 < 1 || atributo1 > 5);

    // ==========================
    // Escolha do segundo atributo (dinâmico)
    // ==========================
    do {
        exibirMenu(atributo1);
        scanf("%d", &atributo2);

        if (atributo2 == atributo1)
            printf("Você já escolheu esse atributo! Escolha outro.\n");
        else if (atributo2 < 1 || atributo2 > 5)
            printf("Opção inválida! Escolha entre 1 e 5.\n");

    } while (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1);

    printf("\n=== COMPARACAO ENTRE %s e %s ===\n\n", carta1.nomePais, carta2.nomePais);

    // ==========================
    // Atributo 1
    // ==========================
    switch (atributo1) {
        case 1:
            printf("Atributo 1: População\n");
            valor1Carta1 = carta1.populacao;
            valor1Carta2 = carta2.populacao;
            break;
        case 2:
            printf("Atributo 1: Área\n");
            valor1Carta1 = carta1.area;
            valor1Carta2 = carta2.area;
            break;
        case 3:
            printf("Atributo 1: PIB\n");
            valor1Carta1 = carta1.pib;
            valor1Carta2 = carta2.pib;
            break;
        case 4:
            printf("Atributo 1: Pontos Turísticos\n");
            valor1Carta1 = carta1.pontosTuristicos;
            valor1Carta2 = carta2.pontosTuristicos;
            break;
        case 5:
            printf("Atributo 1: Densidade Demográfica\n");
            valor1Carta1 = carta1.densidadeDemografica;
            valor1Carta2 = carta2.densidadeDemografica;
            break;
        default:
            valor1Carta1 = valor1Carta2 = 0;
    }

    printf("%s: %.2f\n", carta1.nomePais, valor1Carta1);
    printf("%s: %.2f\n\n", carta2.nomePais, valor1Carta2);

    // ==========================
    // Atributo 2
    // ==========================
    switch (atributo2) {
        case 1:
            printf("Atributo 2: População\n");
            valor2Carta1 = carta1.populacao;
            valor2Carta2 = carta2.populacao;
            break;
        case 2:
            printf("Atributo 2: Área\n");
            valor2Carta1 = carta1.area;
            valor2Carta2 = carta2.area;
            break;
        case 3:
            printf("Atributo 2: PIB\n");
            valor2Carta1 = carta1.pib;
            valor2Carta2 = carta2.pib;
            break;
        case 4:
            printf("Atributo 2: Pontos Turísticos\n");
            valor2Carta1 = carta1.pontosTuristicos;
            valor2Carta2 = carta2.pontosTuristicos;
            break;
        case 5:
            printf("Atributo 2: Densidade Demográfica\n");
            valor2Carta1 = carta1.densidadeDemografica;
            valor2Carta2 = carta2.densidadeDemografica;
            break;
        default:
            valor2Carta1 = valor2Carta2 = 0;
    }

    printf("%s: %.2f\n", carta1.nomePais, valor2Carta1);
    printf("%s: %.2f\n\n", carta2.nomePais, valor2Carta2);

    // ==========================
    // Cálculo das somas (respeitando regra da densidade)
    // ==========================
    float v1Carta1 = (atributo1 == 5) ? (1 / valor1Carta1) : valor1Carta1;
    float v1Carta2 = (atributo1 == 5) ? (1 / valor1Carta2) : valor1Carta2;
    float v2Carta1 = (atributo2 == 5) ? (1 / valor2Carta1) : valor2Carta1;
    float v2Carta2 = (atributo2 == 5) ? (1 / valor2Carta2) : valor2Carta2;

    soma1 = v1Carta1 + v2Carta1;
    soma2 = v1Carta2 + v2Carta2;

    printf("Soma total (%s): %.2f\n", carta1.nomePais, soma1);
    printf("Soma total (%s): %.2f\n", carta2.nomePais, soma2);

    // ==========================
    // Determina o vencedor (usando operador ternário)
    // ==========================
    printf("\n=== RESULTADO FINAL ===\n");

    if (soma1 == soma2) {
        printf("Empate!\n");
    } else {
        const char *vencedor = (soma1 > soma2) ? carta1.nomePais : carta2.nomePais;
        printf("Vencedor: %s 🎉\n", vencedor);
    }

    printf("\n=== FIM DO JOGO ===\n");
    return 0;
}
