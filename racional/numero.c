/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "numero.h"

static numero_pt copia             (numero_t const * const num);   
static numero_pt atribui           (numero_t const * const  num1,
                                        numero_t       * const  num2);    
static numero_pt soma              (numero_t const * const  num1,
                                        numero_t const * const  num2,
                                        numero_t       * const  resp);
static numero_pt subtrai           (numero_t const * const  num1,
                                        numero_t const * const  num2,
                                        numero_t       * const  resp);
static numero_pt multiplica        (numero_t const * const  num1,
                                        numero_t const * const  num2,
                                        numero_t       * const  resp);
static numero_pt divide            (numero_t const * const  num1,
                                        numero_t const * const  num2,
                                        numero_t       * const  resp);
static numero_pt ac_soma           (numero_t       * const  num1,
                                        numero_t const * const  num2);
static numero_pt ac_subtracao      (numero_t       * const  num1,
                                        numero_t const * const  num2);
static numero_pt ac_multiplicacao  (numero_t       * const  num1,
                                        numero_t const * const  num2);
static numero_pt ac_divisao        (numero_t       * const  num1,
                                        numero_t const * const  num2);
static int       compara           (numero_t const * const  num1,
                                        numero_t const * const  num2);
static char *    imprime           (numero_t const * const  num);
static void      destroi           (numero_t       *        num);

/*                                                                            *
 * ----------------------------FUNÇÕES GLOBAIS--------------------------------*
 *                                                                            */

numero_pt constroiNumero (){
    
    numero_pt num;
    num = (numero_t *)malloc(sizeof(numero_t));
    
    if(num == NULL){
        printf("Erro ao alocar memória na função 'constroiNumero'");
        exit(1);
    }
    
    static struct numeroVtbl vtbl = {
        &copia,
        &atribui,
        &soma,
        &subtrai,
        &multiplica,
        &divide,
        &ac_soma,
        &ac_subtracao,
        &ac_multiplicacao,
        &ac_divisao,
        &compara,
        &imprime,
        &destroi
    };
    
    num->metodo = &vtbl;
    
    return num;
}

void      destroiNumero  (numero_pt num){
    if(num != NULL){
        free(num);
    }
}

/*                                                                            *
 * --------------------------FUNÇÕES ESTÁTICAS--------------------------------*
 *                                                                            */

static numero_pt copia             (numero_t const * const num){
    assert(0);
    return NULL;
}   
static numero_pt atribui           (numero_t const * const  num1,
                                        numero_t       * const  num2){
    assert(0);
    return NULL;
}    
static numero_pt soma              (numero_t const * const  num1,
                                        numero_t const * const  num2,
                                        numero_t       * const  resp){
    assert(0);
    return NULL;
}
static numero_pt subtrai           (numero_t const * const  num1,
                                        numero_t const * const  num2,
                                        numero_t       * const  resp){
    assert(0);
    return NULL;
}
static numero_pt multiplica        (numero_t const * const  num1,
                                        numero_t const * const  num2,
                                        numero_t       * const  resp){
    assert(0);
    return NULL;
}
static numero_pt divide            (numero_t const * const  num1,
                                        numero_t const * const  num2,
                                        numero_t       * const  resp){
    assert(0);
    return NULL;
}
static numero_pt ac_soma           (numero_t       * const  num1,
                                        numero_t const * const  num2){
    assert(0);
    return NULL;
}
static numero_pt ac_subtracao      (numero_t       * const  num1,
                                        numero_t const * const  num2){
    assert(0);
    return NULL;
}
static numero_pt ac_multiplicacao  (numero_t       * const  num1,
                                        numero_t const * const  num2){
    assert(0);
    return NULL;
}
static numero_pt ac_divisao        (numero_t       * const  num1,
                                        numero_t const * const  num2){
    assert(0);
    return NULL;
}
static int       compara           (numero_t const * const  num1,
                                        numero_t const * const  num2){
    assert(0);
    return 0;
}
static char *    imprime           (numero_t const * const  num){
    assert(0);
    return NULL;
}
static void      destroi           (numero_t       *        num){
    assert(0);
}
