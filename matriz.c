/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "matriz.h"


static  matriz_pt   copia               (matriz_t const * const  mat);   
static  matriz_pt   atribui             (matriz_t const * const  mat1,
                                         matriz_t       * const  mat2);    
static  matriz_pt   soma                (matriz_t const * const  mat1,
                                         matriz_t const * const  mat2,
                                         matriz_t       * const  resp);
static  matriz_pt   subtrai             (matriz_t const * const  mat1,
                                         matriz_t const * const  mat2,
                                         matriz_t       * const  resp);
static  matriz_pt   multiplica          (matriz_t const * const  mat1,
                                         matriz_t const * const  mat2,
                                         matriz_t       * const  resp);
static  matriz_pt   multiplicaEscalar   (matriz_t       * const  mat1,
                                         double escalar);
static  matriz_pt   ac_soma             (matriz_t       * const  mat1,
                                         matriz_t const * const  mat2);
static  matriz_pt   ac_subtracao        (matriz_t       * const  mat1,
                                         matriz_t const * const  mat2);
static  matriz_pt   ac_multiplicacao    (matriz_t       * const  mat1,
                                         matriz_t const * const  mat2);
static  int         compara             (matriz_t const * const  mat1,
                                         matriz_t const * const  mat2);
static  void        imprime             (matriz_t const * const  mat);
static  void        destroi             (matriz_t       *        mat);

/*                                                                            *
 * ----------------------------FUNÇÕES GLOBAIS--------------------------------*
 *                                                                            */

matriz_pt constroiMatriz (){
    
    matriz_pt mat;
    mat = (matriz_t *)malloc(sizeof(matriz_t));
    if(mat == NULL){
        printf("Erro ao alocar memória para a matriz em 'constroiMatriz'");
        exit(1);
    }
    
    static struct matrizVtbl vtbl = {
        &copia,
        &atribui,
        &soma,
        &subtrai,
        &multiplica,
        &multiplicaEscalar,
        &ac_soma,
        &ac_subtracao,
        &ac_multiplicacao,
        &compara,
        &imprime,
        &destroi
    };
    
    mat->metodo = &vtbl;
    
    return mat;
}

void      destroiMatriz  (matriz_t * mat){
    
    if(mat != NULL){
        free(mat);
    }
}

/*                                                                            *
 * --------------------------FUNÇÕES ESTÁTICAS--------------------------------*
 *                                                                            */

static  matriz_pt copia             (matriz_t const * const mat){
    assert(0);
    return NULL;
}   
static  matriz_pt atribui           (matriz_t const * const  mat1,
                                        matriz_t       * const  mat2){
    assert(0);
    return NULL;
}    
static  matriz_pt soma              (matriz_t const * const  mat1,
                                        matriz_t const * const  mat2,
                                        matriz_t       * const  resp){
    assert(0);
    return NULL;
}
static  matriz_pt subtrai           (matriz_t const * const  mat1,
                                        matriz_t const * const  mat2,
                                        matriz_t       * const  resp){
    assert(0);
    return NULL;
}
static  matriz_pt multiplica        (matriz_t const * const  mat1,
                                        matriz_t const * const  mat2,
                                        matriz_t       * const  resp){
    assert(0);
    return NULL;
}
static  matriz_pt multiplicaEscalar (matriz_t       * const  mat1,
                                     double escalar){
    assert(0);
    return NULL;
}
static  matriz_pt ac_soma           (matriz_t       * const  mat1,
                                        matriz_t const * const  mat2){
    assert(0);
    return NULL;
}
static  matriz_pt ac_subtracao      (matriz_t       * const  mat1,
                                        matriz_t const * const  mat2){
    assert(0);
    return NULL;
}
static  matriz_pt ac_multiplicacao  (matriz_t       * const  mat1,
                                        matriz_t const * const  mat2){
    assert(0);
    return NULL;
}
static  int       compara           (matriz_t const * const  mat1,
                                        matriz_t const * const  mat2){
    assert(0);
    return 0;
}
static  void      imprime           (matriz_t const * const  mat){
    assert(0);
}
static  void      destroi           (matriz_t       *        mat){
    assert(0);
}
