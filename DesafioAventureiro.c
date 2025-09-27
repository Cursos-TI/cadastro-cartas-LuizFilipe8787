#include <stdio.h>
int main(){
    //carta 01
    char estado[20];
    char codigoC[4];
    char nome[20];
    int população;
    float area;
    float PIB;
    int pturistico;
    
    //carta 02
    char estado2[20];
    char codigoC2[4];
    char nome2[20];
    int população2;
    float area2;
    float PIB2;
    int pturistico2;

    printf("====Seja Bem-Vindo====\n=Cadastre suas cartas=\n\nCarta 01:\n\n");

    //carta 01
    printf("Estado(A-H):");
    scanf(" %c", &estado);
    printf("Codigo da carta:");
    scanf(" %s", codigoC);
    printf("Nome da cidade:");
    scanf(" %s", nome);
    printf("População:");
    scanf(" %i", &população);
    printf("Área(Km²):");
    scanf(" %f", &area);
    printf("PIB:");
    scanf(" %f", &PIB);
    printf("Pontos turisticos:");
    scanf(" %i", &pturistico);
    
    //carta 02
    printf("\n\nCarta 02:\n\n");

    printf("Estado(A-H):");
    scanf(" %c", &estado2);
    printf("Codigo da carta:");
    scanf(" %s", codigoC2);
    printf("Nome da cidade:");
    scanf(" %s", nome2);
    printf("População:");
    scanf(" %i", &população2);
    printf("Área(Km²):");
    scanf(" %f", &area2);
    printf("PIB:");
    scanf(" %f", &PIB2);
    printf("Pontos turisticos:");
    scanf(" %i", &pturistico2);

    //cartas cadastradas
    //carta 01
    printf("\n\n===CARTAS CADASTRADAS===");
   
    printf("\n\n===[Carta 01]===\n");
    printf("Estado: %s\n", estado);
    printf("Codigo da carta: %s\n", codigoC);
    printf("Nome da cidade: %s\n", nome);
    printf("Populacao: %d\n", população);
    printf("Area(km²): %.1f\n", area);
    printf("PIB: %.1f\n", PIB);
    printf("Ponto Turisticos: %d\n", pturistico);

    //carta 02
    printf("\n\n===[Carta 02]===\n");
    printf("Estado: %s\n", estado2);
    printf("Codigo da carta: %s\n", codigoC2);
    printf("Nome da cidade: %s\n", nome2);
    printf("Populacao: %d\n", população2);
    printf("Area(km²): %.1f\n", area2);
    printf("PIB: %.1f\n", PIB2);
    printf("Ponto Turisticos: %d\n", pturistico2);


        int (opcao);
 {
        printf("\nEscolha o atributo para comparação:\n");
        printf("1 - População\n");
        printf("2 - Área\n");
        printf("3 - PIB\n");
        printf("4 - Pontos turísticos\n");
        printf("5 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                // Comparação de população
                if (população > população2) 
                    printf("Cidade 1 (%s) venceu na População!\n", nome);
                else if (população < população2) 
                    printf("Cidade 2 (%s) venceu na População!\n", nome2);
                else 
                    printf("Empate na População!\n");
                break;
            case 2:
                // Comparação de área
                if (area > area2) 
                    printf("Cidade 1 (%s) venceu na Área!\n", nome);
                else if (area < area2) 
                    printf("Cidade 2 (%s) venceu na Área!\n", nome2);
                else 
                    printf("Empate na Área!\n");
                break;
            case 3:
                // Comparação de PIB
                if (PIB > PIB2) 
                    printf("Cidade 1 (%s) venceu no PIB!\n", nome);
                else if (PIB < PIB2) 
                    printf("Cidade 2 (%s) venceu no PIB!\n", nome2);
                else 
                    printf("Empate no PIB!\n");
                break;
            case 4:
                // Comparação de pontos turísticos
                if (pturistico > pturistico2) 
                    printf("Cidade 1 (%s) venceu nos Pontos turísticos!\n", nome);
                else if (pturistico < pturistico2) 
                    printf("Cidade 2 (%s) venceu nos Pontos turísticos!\n", nome2);
                else 
                    printf("Empate nos Pontos turísticos!\n");
                break;
            case 5:
                printf("Saindo do jogo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }







}
