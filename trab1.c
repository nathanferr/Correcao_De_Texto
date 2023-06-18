/*
1º Trabalho Prático de Linguagem de Programação - Correção de Texto
Fatec - ADS - Matutino
---------------------------------------------------
Autores:
 * Gustavo Liros Silva dos Santos RA: 1430482021029
 * Matheus Delfino Costa Silva    RA: 1430482021001
 * Nathan Rosa Ferreira           RA: 1430482021018
---------------------------------------------------
 * trab1.c
 * Contém as implementações das funções que se encontram no arquivo de 
 * cabeçalho trab1.h para solução do 1º trabalho prático. 
 */


/* Devolve a posição da 1a. ocorrência do caractere . (ponto) ou do
 * caractere , (vírgula) na string s, a partir da posição offset.
 * Caso não haja nenhum . ou , em s, a função devolve -1. */
int find_comma_or_dot(const char * s, int offset){

    /* Começando da posição passada pelo parâmetro offset, percorre a string enquanto
     * não achar o último caractere ('\0'). Se a condição proposta no if for falsa,
     * ele soma mais um ao offset para verificar a próxima posição. */
    while(s[offset] != '\0'){
        if(s[offset] == ',' || s[offset] == '.'){   // Verifica se o caractere da string na posição offset
            return offset;                          // é um ponto (.) ou uma vírgula (,). Caso verdadeiro,
        }                                           // retorna a posição (offset).
        offset++;                                   
    }

    return -1;                                      // Retorna -1 caso não encontrar nenhuma vírgula ou ponto.
}

/* Remove o caractere de espaço em branco se ele aparecer antes da
 * posição position em s. Se não houver um caractere de espaço
 * em branco antes de position, nada é feito. */
void remove_blank(char * s, int position){

    /* Verifica se position menos um é um caractere de espaço em branco,
     * isto é, se há espaço em branco na posição antes da vírgula ou do 
     * ponto da string (s), passada por parâmetro.*/
    if(s[position - 1] == ' '){                        
        while(s[position - 1] != '\0'){             // Enquanto position menos um for diferente de '\0', ele
            s[position - 1] = s[position];          // percorre a string somando um a position. Assim removendo 
            position++;                             // o espaço em branco a partir da substituição de position 
        }                                           // menos um pelo seu sucessor (position).
    }
}
