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

    if (criaHash(337) != NULL)
        printf ("Sucesso\n");
    
    Hash * ha = criaHash(337);
    
    destroiHash(ha);
    
    return (EXIT_SUCCESS);
}

