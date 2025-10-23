#include <stdio.h>

void bispo(int n){
    /* 
        Movimenta o bispo 5 casas na diagonal para direita/cima.
        Contando com a posição atual da peça.
        O movimento do bispo foi feito andando uma casa para direita e depois uma casa para cima.
        Terminando com 5 casas na diagonal.
    */
   
    if(n > 0){
        for (int y = 0; y < 1; y++)
        {
            //Imprime o movimento para direita e para cima, até que o valor de x chegue a 5.
            printf("Mover para cima\n");
            for (int x = 0; x < 1; x++)
            {
                printf("Mover para direita\n");
            }
            
        }

        bispo(n-1);
    }
}

void torre(int n){
    /* 
        Movimenta a torre 5 casas para cima.
        Contando com a posição atual da peça.
    */

    if(n > 0){
        //Imprime o movimento para cima, até que o contador chegue a 5.
        printf("Mover para cima\n");
        torre(n-1);
    }
    
    
    
    
}

void rainha(int n){
    /* 
        Movimenta a rainha 8 casas para a esquerda, saindo do lado direito do tabuleiro para o esquerdo.
        Contando com a posição atual da peça.
    */
    if(n > 0){
        //Imprime o movimento para esquerda, até que o contador chegue a 8.
        printf("Mover para esquerda\n");
        rainha(n-1);
    } 
    
}

void cavalo(){
    int cont = 0;
    for(int i = 0; i < 1; i++){
        while (cont<2)
        {
         printf("Mover para baixo\n");
         printf("\n"); 
         cont++;
        }
        printf("Mover para esquerda\n");
    }
}

int main() {
    int opcao = 10;
    
    //Enquanto a opção for diferente de 0, o programa pergunta qual peça deseja mover.
    while (opcao != 0)
{
    printf("Escolha a peça que deseja mover: \n");
    printf("1 - Bispo\n");
    printf("2 - Torre\n");
    printf("3 - Rainha\n");
    printf("4 - Cavalo\n");
    printf("0 - Sair\n");
    scanf("%d", &opcao);

    //Chama a função referente a peça escolhida.
    switch (opcao) {
        case 1:
            bispo(5);
            break;
        case 2:
            torre(5);
            break;
        case 3:
            rainha(8);
            break;
        case 4:
            cavalo();
            break;
        case 0:
            break;
        default:
            printf("Opção inválida\n");
            break;
    }
}      
    
    return 0;
}
