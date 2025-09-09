#include <stdio.h>

// estrutura para guardar os dados da carta
struct Carta {
    char estado[50];
    char codigo[5];
    char nome[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
    float pibPerCapita;
    float superPoder;
};

// função para calcular densidade, pib per capita e super poder
void calcular(struct Carta *c) {
    c->densidade = c->populacao / c->area;
    c->pibPerCapita = (c->pib * 1000000000.0) / c->populacao;
    c->superPoder = (float)c->populacao + c->area + c->pib +
                    c->pontosTuristicos + c->pibPerCapita +
                    (1.0 / c->densidade);
}

// quem ganha quando maior é melhor
int maiorGanha(float a, float b) {
    if (a > b) return 1;
    else return 0;
}

// quem ganha quando menor é melhor
int menorGanha(float a, float b) {
    if (a < b) return 1;
    else return 0;
}

int main() {
    struct Carta c1, c2;

    // entrada da carta 1
    printf("Carta 1:\n");
    printf("Estado: ");
    scanf(" %[^\n]", c1.estado);
    printf("Codigo: ");
    scanf(" %s", c1.codigo);
    printf("Nome: ");
    scanf(" %[^\n]", c1.nome);
    printf("Populacao: ");
    scanf("%lu", &c1.populacao);
    printf("Area: ");
    scanf("%f", &c1.area);
    printf("PIB (em bilhoes): ");
    scanf("%f", &c1.pib);
    printf("Pontos turisticos: ");
    scanf("%d", &c1.pontosTuristicos);

    // entrada da carta 2
    printf("\nCarta 2:\n");
    scanf(" %[^\n]", c2.estado);
    printf("Codigo: ");
    scanf(" %s", c2.codigo);
    printf("Nome: ");
    scanf(" %[^\n]", c2.nome);
    printf("Populacao: ");
    scanf("%lu", &c2.populacao);
    printf("Area: ");
    scanf("%f", &c2.area);
    printf("PIB (em bilhoes): ");
    scanf("%f", &c2.pib);
    printf("Pontos turisticos: ");
    scanf("%d", &c2.pontosTuristicos);

    // calcular coisas
    calcular(&c1);
    calcular(&c2);

    // comparacoes
    printf("\nComparacao de Cartas:\n");
    printf("Populacao: Carta 1 venceu (%d)\n", maiorGanha((float)c1.populacao, (float)c2.populacao));
    printf("Area: Carta 1 venceu (%d)\n", maiorGanha(c1.area, c2.area));
    printf("PIB: Carta 1 venceu (%d)\n", maiorGanha(c1.pib, c2.pib));
    printf("Pontos Turisticos: Carta 1 venceu (%d)\n", maiorGanha((float)c1.pontosTuristicos, (float)c2.pontosTuristicos));
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", menorGanha(c1.densidade, c2.densidade));
    printf("PIB per Capita: Carta 1 venceu (%d)\n", maiorGanha(c1.pibPerCapita, c2.pibPerCapita));
    printf("Super Poder: Carta 1 venceu (%d)\n", maiorGanha(c1.superPoder, c2.superPoder));

    return 0;
}
