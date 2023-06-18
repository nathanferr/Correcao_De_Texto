/*
1º Trabalho Prático de Linguagem de Programação - Correção de Texto
Fatec - ADS - Matutino
---------------------------------------------------
Autores:
 * Gustavo Liros Silva dos Santos RA: 1430482021029
 * Matheus Delfino Costa Silva    RA: 1430482021001
 * Nathan Rosa Ferreira           RA: 1430482021018
---------------------------------------------------
 * trab1.h
 * Contém os protótipos das funções que devem ser usadas
 * na solução do 1º trabalho prático.
 */


/* Verificar se a biblioteca foi incluida utilizando a constante.
 * E define a constante, caso ela não esteja incluida. */
#ifndef _TRAB1_H  
#define _TRAB1_H  

/* devolve a posição da 1a. ocorrência do caractere . (ponto) ou
 * do caractere , (vírgula) na string s, a partir da posição offset.
 * Caso não haja nenhum . ou , em s, a função devolve -1 */
int find_comma_or_dot(const char * s, int offset);

/* remove o caractere de espaço em branco se ele aparecer antes
 * da posição position em s. Se não houver um caractere de espaço
 *  em branco antes de position, nada é feito. */
void remove_blank(char * s, int position);

#endif  // Finaliza o ifndef.
