/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: work
 *
 * Created on 26 de Outubro de 2017, 17:41
 */

#include <stdio.h>
#include <stdlib.h>
#include "TabelaHash.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
   /* int TABLE_SIZE = 2287;
    Hash * ha = criaHash(TABLE_SIZE);
    if ( ha != NULL)
        printf ("Sucesso\n");
    //le arquivo alunos.txt
    FILE * f;
    f = fopen("/Users/work/Dropbox/Ed2/AtividadeED2_05/alunos.txt","r");
    if (f == NULL)
    {
        printf ("\nerro arquivo\n");
        system ("pause");
        exit (1);
    }
    
    struct aluno al;
    //guarda cada linha do arquivo em uma struct aluno que sera inserida na tabela hash	
	while (1)
	{
		fscanf (f, "%d %s %f %f %f",&al.matricula, al.nome, &al.n1, &al.n2, &al.n3);
		if (feof (f))
			break;
		if (insere_hash_semcolisao(ha, al) != 1)
                   printf("%d error \n", al.matricula);
                /*if (verificaOcupacao(ha) == 1)
                {
                    Hash *aux = ha;
                    ha = criaHash(ha->TABLE_SIZE * 2);
                    if ( ha != NULL)
                        printf ("Sucesso\n");
                    ha = aux;
                }
                    
                     
	}
    fclose (f);
    
    //printf ("%d\n", ha->TABLE_SIZE);
    
    struct aluno alu2;
    
    if(buscaHash_semColisao(ha, 2090, &alu2) == 1)
        printf ("%d %s %f %f %f\n", alu2.matricula, alu2.nome, alu2.n1, alu2.n2, alu2.n3);
     */
    
    int M = 4;
    
    Hash * ha = criaHash(M);
    if ( ha != NULL)
        printf ("Sucesso\n");
    struct aluno a1, a2, a3, a4;
    a1.matricula = 2285;a1.nome = "Umbelino"; a1.n1 = 9; a1.n2 = 5; a1.n3 = 8;
    a2.matricula =  1478; a2.nome =  "Urania"; a2.n1 = 27; a2.n2 = 13; a2.n3 = 5;
    a3.matricula =  2060; a3.nome = "Uranio"; a3.n1 = 6; a3.n2 = 1; a3.n3 = 8;
    a4.matricula = 6930; a3.matricula = "Urbalina" ; a4.n1 = 4; a4.n2 = 7; a4.n3 = 9;

    if (insere_hash_semcolisao(ha, a1) != 1)
                   printf("%d error \n", a1.matricula);
    if (verificaOcupacao(ha) == 1) 
    {
        Hash *aux = ha;
                    ha = criaHash(ha->TABLE_SIZE * 2);
                    if ( ha != NULL)
                        printf ("Sucesso\n");
                    ha = aux;
    }
    if (insere_hash_semcolisao(ha, a2) != 1)
                   printf("%d error \n", a2.matricula);
    if (insere_hash_semcolisao(ha, a3) != 1)
                   printf("%d error \n", a3.matricula);
    if (insere_hash_semcolisao(ha, a4) != 1)
                   printf("%d error \n", a4.matricula);
    
    return (EXIT_SUCCESS);
}

