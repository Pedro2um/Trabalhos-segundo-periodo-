/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: eduarda
 *
 * Created on 5 de março de 2022, 10:22
 */

#include <stdio.h>
#include <stdlib.h>
#include "racional.h"
/*
 * 
 */
int main(int argc, char** argv) {
    
    racional_pt n1   = constroiRacional(-9, 7);
    racional_pt n2   = constroiRacional(4, 5);
    racional_pt resp = zeraRacional();
    
    //printf("N1 = %s e N2 = %s\n", n1->Metodo->imprime(n1), n2->Metodo->imprime(n2));
    
    printf("N1 = %s\n", n1->Metodo->imprime(n1));
    printf("N2 = %s\n", n2->Metodo->imprime(n2));
    
    n1->Metodo->soma(n1, n2, resp);
    printf("\nN1 + N2 = %s\n", n1->Metodo->imprime(resp));
    
    n1->Metodo->subtrai(n1, n2, resp);
    printf("N1 - N2 = %s\n", n1->Metodo->imprime(resp));
    
    n1->Metodo->multiplica(n1, n2, resp);
    printf("N1 * N2 = %s\n", n1->Metodo->imprime(resp));
    
    n1->Metodo->divide(n1, n2, resp);
    printf("N1 / N2 = %s\n", n1->Metodo->imprime(resp));
    
    n1->Metodo->ac_soma(n1, n2);
    printf("\nApós ser somado com N2, N1 = %s\n", n1->Metodo->imprime(n1));
    
    n1->Metodo->ac_subtracao(n1, n2);
    printf("Após ser subtraido com N2, N1 = %s\n", n1->Metodo->imprime(n1));
    
    n1->Metodo->ac_multiplicacao(n1, n2);
    printf("Após ser multiplicado com N2, N1 = %s\n", n1->Metodo->imprime(n1));
    
    n1->Metodo->ac_divisao(n1, n2);
    printf("Após ser dividido com N2, N1 = %s\n", n1->Metodo->imprime(n1));
    
    printf("\nO modulo de N1(%s) é %.2Lf\n", n1->Metodo->imprime(n1),
                                           n1->Metodo->modulo(n1));
    
    /*printf("\nA raiz quadrada de N1(%s) é %.2Lf\n", n1->Metodo->imprime(n1),
                                                  n1->Metodo->moduloRaiz(n1, 2));
    
    printf("A raiz cubica de N1(%s) é %.2Lf\n", n1->Metodo->imprime(n1),
                                                n1->Metodo->moduloRaiz(n1, 3));
    */
    
    printf("\nN1 = %s\n", n1->Metodo->imprime(n1));
    n1->Metodo->potencia(n1, 2);
    printf("N1 ao quadrado é %s\n", n1->Metodo->imprime(n1));
    
    printf("\nN1 = %s\n", n1->Metodo->imprime(n1));
    n1->Metodo->defineNumerador(n1, 15);
    printf("(Mudando numerador) N1 = %s\n", n1->Metodo->imprime(n1));
    n2->Metodo->defineDenominador(n1, 9);
    printf("(Mudando denominador) N1 = %s\n", n1->Metodo->imprime(n1));
    
    printf("\nN1 = %s\n", n1->Metodo->imprime(n1));
    printf("N2 = %s\n", n2->Metodo->imprime(n2));
    
    if(n1->Metodo->compara(n1, n2) == 0)
        printf("N1 é igual a N2\n");
    else if(n1->Metodo->compara(n1, n2) > 0)
        printf("N1 é maior que N2\n");
    else if(n1->Metodo->compara(n1, n2) < 0)
        printf("N1 é menor que N2\n");
    
    
    return (EXIT_SUCCESS);
}

