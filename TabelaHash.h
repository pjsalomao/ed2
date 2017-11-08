/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TabelaHash.h
 * Author: work
 *
 * Created on 26 de Outubro de 2017, 17:43
 */

#ifndef TABELAHASH_H
#define TABELAHASH_H

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* TABELAHASH_H */

struct aluno 
{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct hash Hash;

Hash * criaHash (int TABLE_SIZE);

void destroiHash (Hash * ha);

int insere_hash_semcolisao (Hash *ha, struct aluno al);

int buscaHash_semColisao (Hash *ha, int mat, struct aluno * al);

int
verificaOcupacao (Hash * ha);