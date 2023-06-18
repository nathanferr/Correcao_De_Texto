/*
1º Trabalho Prático de Linguagem de Programação - Correção de Texto
Fatec - ADS - Matutino
---------------------------------------------------
Autores:
 * Gustavo Liros Silva dos Santos RA: 1430482021029
 * Matheus Delfino Costa Silva    RA: 1430482021001
 * Nathan Rosa Ferreira           RA: 1430482021018
---------------------------------------------------
 * trab1funcaomain.c
 * Contém a função principal que irá utilizar as funções implementadas 
 * em trab1.c incluindo o arquivo de cabeçalho trab1.h.
 * Usando makefile para a solução do 1º trabalho prático.
 */


#include <stdio.h>
#include <string.h>

/* Inclui o arquivo de cabeçalho trab1.h que contém os protótipos das funções,
 * implementados no trab1.c, que serão utilizadas. */
#include "trab1.h"  


int main(){
    
    /* São declaradas duas variáveis do tipo inteiro: "n" para guardar
     * os números de casos informados pelo usuário e "posicao" para
     * guardar o retorno da função find_comma_or_dot */
    int n, posicao;

    printf("Informe quantos casos serao realizados (1 ate 10): ");         // Solicita ao usuário que informe a quantidade de 
    scanf("%d", &n);                                                       // casos que serão realizados.

    while(n < 1 || n > 10){                                                // Enquanto não for informado um número de 1 até 10
        printf("\nERRO!! O numero de casos deve ser de 1 ate 10.");        // será impresso uma mensagem de erro e uma mensagem
        printf("\nInforme quantos casos serao realizados (1 ate 10): ");   // solicitando novamente ao usuário a quantia de casos.
        scanf("%d", &n);
    }
    getchar();  // Pegar o '\n' (enter) do buffer deixado pelo scanf para evitar erros.

    char str[n][1001]; // É declarado uma matriz de caracteres de n linhas (informadas) e até 1001 caracteres.
        
    /* É utilizado um laço for para preencher todas as strings. Utiliza-se o
     * fgets para guardar a string, limitando até 1000 caracteres, logo apos
     * substitui o '\n' (enter), guardado pelo fgets, pelo caractere '\0'.
     * Utilizando a função strlen da bliblioteca string.h para saber o 
     * tamanho da string. */
    for(int i = 0; i < n; i++){                                 
        printf("Informe a %d.a frase: ", i + 1);                    
        fgets(str[i], 1000, stdin);
        str[i][strlen(str[i]) - 1] = '\0';  

        while(strcmp(str[i], "") == 0){                                    // Compara a string informada pelo usuário com uma string vazia, usando
            printf("\nERRO!! Nao foi informado nenhuma frase.\n");         // uma função da biblioteca string.h. E enquanto elas forem iguais, 
            printf("Informe a %d.a frase: ", i + 1);                       // será impresso uma mensagem de erro e uma mensagem para que seja
            fgets(str[i], 1000, stdin);                                    // informada uma frase válida (não vazia).
            str[i][strlen(str[i]) - 1] = '\0';
        }
    }            

    for(int i = 0; i < n ; i++){                                           // Laço para percorrer as string e aplicar as funções. Assim toda vez  
        posicao = 0;                                                       // que iniciar uma string nova, é atribuído 0 à "posicao" para iniciar
                                                                           // pela posição zero da string.
        while(posicao != -1){                                              // Enquanto a "posicao" for diferente de -1, significa que a função
            posicao = find_comma_or_dot(str[i], posicao);                  // find_comma_or_dot achou uma vírgula ou um ponto, então a função 
            if(posicao != -1){                                             // retorna a posição achada para "posicao". Verifica se realmente 
                remove_blank(str[i], posicao);                             // foi encontrada e a função remove_blank altera por referência
            }                                                              // a string passada.
        }
    }
    
    puts("<-----------------------------FRASES----------------------------------->");
    for(int i = 0; i < n; i++){
        printf("%d.a frase: %s\n", i + 1, str[i]);                         // Será impresso todas as n strings corrigidas.
    }
    puts("<---------------------------------------------------------------------->");

    return 0;
}