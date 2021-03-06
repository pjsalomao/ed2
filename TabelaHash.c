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

int
insere_hash_semcolisao (Hash *ha, struct aluno al)
{
    // primeiro verifica se a tabela hash nao é vazia ou esta cheia
    if (ha == NULL || ha->qtd == ha->TABLE_SIZE)
        return 0;
    
    //define qual campo é a chave
    int chave = al.matricula;
    
    //chama funcao de hash apra calcular a posicao
    //sera usado chave divisao
    int pos = chaveDivisao (chave, ha->TABLE_SIZE);
    
    struct aluno * novo = (struct aluno*) malloc (sizeof(struct aluno));
    if (novo == NULL)
        return 0;
    *novo = al;
    
    ha->itens[pos] = novo;
    ha->qtd++;
    
    
    return 1;
    
}

int
buscaHash_semColisao (Hash *ha, int mat, struct aluno * al)
{
    //verifica se a tabela nao esta vazia
    if (ha == NULL)
        return 0;
    
    //encontra a posicao da chave
    int pos = chaveDivisao (mat, ha->TABLE_SIZE);
    
    *al = *ha->itens[pos];
    
    return 1;
}

int
verificaOcupacao (Hash * ha)
{
    int i, qnull=0;
    
    
    for (i=0; i<ha->TABLE_SIZE; i++)
    {
        if (ha->itens[i] == NULL)
        qnull++;    
    }
    
    if (((qnull * ha->TABLE_SIZE)/100) >= 0.75)
        return 1;
    else return 0;
}