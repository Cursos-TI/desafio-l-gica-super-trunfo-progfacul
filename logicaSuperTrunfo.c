#include <stdio.h>
#include <string.h>

struct Carta {
    char estado[50];
    char codigo[20];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
};

void cadastrarCarta(struct Carta *carta, int numero) {
    printf("\n--- Cadastro da Carta %d ---\n", numero);
    printf("Estado: ");
    scanf(" %[^\n]", carta->estado);

    printf("Código da Carta: ");
    scanf(" %[^\n]", carta->codigo);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta->nome);

    printf("População: ");
    scanf("%d", &carta->populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta->area);

    printf("PIB (em milhões): ");
    scanf("%f", &carta->pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    if (carta->area > 0)
        carta->densidade = carta->populacao / carta->area;
    else
        carta->densidade = 0;
}

void exibirCarta(struct Carta carta, int numero) {
    printf("\n--- Carta %d ---\n", numero);
    printf("Cidade: %s (%s)\n", carta.nome, carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: R$ %.2f milhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidade);
}

void comparar(struct Carta c1, struct Carta c2, int opcao) {
    printf("\n--- Comparando Cartas ---\n");
    
    if (opcao == 1) {
        if (c1.populacao > c2.populacao)
            printf("🏆 Vencedora: %s (População maior)\n", c1.nome);
        else if (c2.populacao > c1.populacao)
            printf("🏆 Vencedora: %s (População maior)\n", c2.nome);
        else
            printf("Empate na População!\n");

    } else if (opcao == 2) {
        if (c1.area > c2.area)
            printf("🏆 Vencedora: %s (Área maior)\n", c1.nome);
        else if (c2.area > c1.area)
            printf("🏆 Vencedora: %s (Área maior)\n", c2.nome);
        else
            printf("Empate na Área!\n");

    } else if (opcao == 3) {
        if (c1.pib > c2.pib)
            printf("🏆 Vencedora: %s (PIB maior)\n", c1.nome);
        else if (c2.pib > c1.pib)
            printf("🏆 Vencedora: %s (PIB maior)\n", c2.nome);
        else
            printf("Empate no PIB!\n");

    } else if (opcao == 4) {
        if (c1.pontosTuristicos > c2.pontosTuristicos)
            printf("🏆 Vencedora: %s (Mais Pontos Turísticos)\n", c1.nome);
        else if (c2.pontosTuristicos > c1.pontosTuristicos)
            printf("🏆 Vencedora: %s (Mais Pontos Turísticos)\n", c2.nome);
        else
            printf("Empate nos Pontos Turísticos!\n");

    } else if (opcao == 5) {
        if (c1.densidade < c2.densidade)
            printf("🏆 Vencedora: %s (Menor Densidade Populacional)\n", c1.nome);
        else if (c2.densidade < c1.densidade)
            printf("🏆 Vencedora: %s (Menor Densidade Populacional)\n", c2.nome);
        else
            printf("Empate na Densidade!\n");
    } else {
        printf("Opção inválida!\n");
    }
}

int main() {
    struct Carta carta1, carta2;
    int opcao;

    printf("🃏 Cadastro de Cartas de Cidades\n");
    cadastrarCarta(&carta1, 1);
    cadastrarCarta(&carta2, 2);

    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    printf("\nEscolha o atributo para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional (menor vence)\n");
    printf("Digite sua opção: ");
    scanf("%d", &opcao);

    comparar(carta1, carta2, opcao);

    return 0;
}
