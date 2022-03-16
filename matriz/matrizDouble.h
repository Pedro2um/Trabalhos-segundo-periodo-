/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   matrizDouble.h
 * Author: eduarda
 *
 * Created on 13 de março de 2022, 08:41
 */

#ifndef MATRIZDOUBLE_H
#define MATRIZDOUBLE_H

#define LINHA 0
#define COLUNA 1
#include "matriz.h"

struct matrizDouble;
struct matrizDouble_Interface;

typedef struct matrizDouble   matrizDoub_t;
typedef struct matrizDouble * matrizDoub_pt;

struct matrizDouble{
    struct matriz super;
    struct matrizDouble_Interface const * Metodo;
    unsigned int tamanho[2];
    double ** valor;
};

/*                                                                            *
 * ---------------------------------------------------------------------------*
 *                                                                            */

matrizDoub_pt   ConstroiMatriz          (unsigned int linha, unsigned int coluna);
matrizDoub_pt   ConstroiMatrizNula      (unsigned int linha, unsigned int coluna);
matrizDoub_pt   ConstroiMatrizUnitaria  (unsigned int linha, unsigned int coluna);
matrizDoub_pt   ConstroiMatrizIdentidade(unsigned int linha, unsigned int coluna);

/*                                                                            *
 * ---------------------------------------------------------------------------*
 *                                                                            */

struct matrizDouble_Interface{
    
    matrizDoub_pt 	(*copia)            (matrizDoub_t const * const mat);
    
    matrizDoub_pt 	(*atribui)          (matrizDoub_t const * const  mat1,
                                             matrizDoub_t       * const  mat2);
    
    matrizDoub_pt 	(*soma)             (matrizDoub_t const * const  mat1,
                                             matrizDoub_t const * const  mat2,
                                             matrizDoub_t       *        resp);

    matrizDoub_pt 	(*subtrai)          (matrizDoub_t const * const  mat1,
                                             matrizDoub_t const * const  mat2,
                                             matrizDoub_t       * const  resp);

    matrizDoub_pt 	(*multiplica)       (matrizDoub_t const * const  mat1,
                                             matrizDoub_t const * const  mat2,
                                             matrizDoub_t       * const  resp);
    
    matrizDoub_pt 	(*multiplicaEscalar)(matrizDoub_t       * const  mat,
                                             double escalar);
    
    matrizDoub_pt 	(*ac_soma)          (matrizDoub_t       * const  mat1,
                                             matrizDoub_t const * const  mat2);

    matrizDoub_pt 	(*ac_subtracao)     (matrizDoub_t       * const  mat1,
                                             matrizDoub_t const * const  mat2);
    
    matrizDoub_pt 	(*ac_multiplicacao) (matrizDoub_t       * const  mat1,
                                             matrizDoub_t const * const  mat2);
    
    int                 (*compara)          (matrizDoub_t const * const  mat1,
                                             matrizDoub_t const * const  mat2);
    
    void                (*imprime)          (matrizDoub_t const * const  mat);

    void                (*destroi)          (matrizDoub_t       *        mat);

    matrizDoub_pt       (*transposta)       (matrizDoub_t       *        mat);
    
    matrizDoub_pt       (*transposta_2D)    (matrizDoub_t       *        mat);
    
    matrizDoub_pt       (*reverse_horizontal)(matrizDoub_t      * const  mat);

    matrizDoub_pt       (*reverse_vertical) (matrizDoub_t       * const  mat);
    
    matrizDoub_pt       (*defineLinhas)     (matrizDoub_t       *   const mat,
                                             unsigned int linha);
    
    matrizDoub_pt       (*defineColunas)    (matrizDoub_t    *   const mat,
                                             unsigned int coluna);
    
    matrizDoub_pt       (*redimensiona)     (matrizDoub_t    *   const mat,
                                             unsigned int linha,
                                             unsigned int coluna);
    
    matrizDoub_pt       (*adicionaLinha)    (matrizDoub_t       * const  mat);
    
    matrizDoub_pt       (*adicionaColuna)   (matrizDoub_t       * const  mat);
    
    int                 (*comparaDimensoes) (matrizDoub_t const * const  mat1,
                                             matrizDoub_t const * const  mat2);
    
    int                 (*obtemLinhas)      (matrizDoub_t const *   const mat);
    
    int                 (*obtemColunas)     (matrizDoub_t const *   const mat);
};


#endif /* MATRIZDOUBLE_H */

