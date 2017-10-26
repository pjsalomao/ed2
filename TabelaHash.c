/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "TabelaHash.h"

struct hash
{
    int qtd, TABLE_SIZE;
    struct aluno ** itens;
};

Hash
* criaHash (int TABLE_SIZE)
{
    Hash * ha = (Hash *) malloc (sizeof(Hash)); //aloca espaço de mamória para a tabela hash
    if (ha != NULL)
    {
        ha->TABLE_SIZE = TABLE_SIZE;
        ha->itens = (struct aluno **) malloc (TABLE_SIZE * sizeof(struct aluno *)); //aloca espaco para a tabela de itens
        if (ha->itens == NULL)
        {
            free(ha);
            return NULL;
        }
        ha->qtd = 0;
        
        int i;
        for (i=0; i< TABLE_SIZE; i ++) //define como NULL cada posicao da tabela
            ha->itens[i] = NULL;
        
        return ha;
    }
    
    else return NULL;
        
}

void
destroiHash (Hash * ha)
{
    if (ha != NULL)
    {
        int i;
        for (i=0; i<ha->TABLE_SIZE; i++) //percorre a tabela liberando memoria de cada espaco
           free(ha->itens[i]);
        
        free(ha->itens);
        free(ha);
    }
}

// funçoes de hashing

//metodo da divisao
//chave: parte dos dados a serm guardados
int
chaveDivisao (int chave, int TABLE_SIZE)
{
    //utiliza o resto da divisao entre o valor inteiro que representa o elemento(chave) pelo TABLE_SIZE
    //a operacao de E bit a bit (&) com o valor 0x7FFFFFFF elimina o bit de sinal eliminando possibilidade de overflow
    return (chave & 0x7FFFFFFF) % TABLE_SIZE;
}


int
chaveMultiplicacao (int chave, int TABLE_SIZE)
{
    //constante fracionaria A, 0 < A < 1 que multiplica o valor da chave que representa o elemento
    //a posicao é calculada através da multiplicacao da parte fracionara resultante com o TABLE_SIZE
    float A = 0.618033;
    float valor = A * chave;
    valor = valor - (int)valor; //resultante fracionario
    return (int)(valor * TABLE_SIZE);
    
}

int
chaveDobra (int chave, int TABLE_SIZE)
{
    int num_bits = 10; // a cada 10 bits se realiza a dobra
    int parte1 = chave >> num_bits; //percorre a chave  para a direita ate num_bits posicoes
    int parte2 = chave & (TABLE_SIZE-1); // faz operacao de E bit a bit ate o tamanho da tabela -1
    return (parte1 ^ parte2); //a posicao é gerada através da operacao de ou exclusivo entre as duas partes
}