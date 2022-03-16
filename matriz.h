/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   matriz.h
 * Author: eduarda
 *
 * Created on 13 de março de 2022, 08:41
 */

#ifndef MATRIZ_H
#define MATRIZ_H

struct matriz;
struct matrizVtbl;

typedef struct matriz   matriz_t;
typedef struct matriz * matriz_pt;

struct matriz{
    struct matrizVtbl const * metodo;
};

/*                                                                            *
 * ---------------------------------------------------------------------------*
 *                                                                            */

matriz_pt       constroiMatriz  ();
void            destroiMatriz   (matriz_t         *         mat);

/*                                                                            *
 * ---------------------------------------------------------------------------*
 *                                                                            */

struct matrizVtbl{
    
    matriz_pt 	(*copia)                (matriz_t const * const mat);
    
    matriz_pt 	(*atribui)              (matriz_t const * const  mat1,
                                         matriz_t       * const  mat2);
    
    matriz_pt 	(*soma)                 (matriz_t const * const  mat1,
                                         matriz_t const * const  mat2,
                                         matriz_t       * const  resp);

    matriz_pt 	(*subtrai)              (matriz_t const * const  mat1,
                                         matriz_t const * const  mat2,
                                         matriz_t       * const  resp);

    matriz_pt 	(*multiplica)           (matriz_t const * const  mat1,
                                         matriz_t const * const  mat2,
                                         matriz_t       * const  resp);
    
    matriz_pt 	(*multiplicaEscalar)    (matriz_t       * const  mat,
                                         double escalar);
    
    matriz_pt 	(*ac_soma)              (matriz_t       * const  mat1,
                                         matriz_t const * const  mat2);

    matriz_pt 	(*ac_subtracao)         (matriz_t       * const  mat1,
                                         matriz_t const * const  mat2);
    
    matriz_pt 	(*ac_multiplicacao)	(matriz_t       * const  mat1,
                                         matriz_t const * const  mat2);
    
    int         (*compara)              (matriz_t const * const  mat1,
                                         matriz_t const * const  mat2);
    
    void        (*imprime)              (matriz_t const * const  mat);

    void        (*destroi)              (matriz_t       *        mat);    
};

/*                                                                            *
 * ---------------------------------------------------------------------------*
 *                                                                            */

static inline   
matriz_pt       Mat_copia               (matriz_t const * const me) {
    return (  me->metodo->copia(me));
}

static inline 
matriz_pt       Mat_atribui             (matriz_t const * const  me,
					 matriz_t       * const  outro){
    return (me->metodo->atribui(me, outro));
}

static inline 
matriz_pt       Mat_soma                (matriz_t const * const  me,
					 matriz_t const * const  outro,
					 matriz_t       * const res){
    return (me->metodo->soma(me, outro, res));
}

static inline 
matriz_pt       Mat_subtrai             (matriz_t const * const  me,
					 matriz_t const * const  outro,
					 matriz_t       * const res){
    return (me->metodo->subtrai(me, outro, res));
}

static inline
matriz_pt       Mat_multiplica          (matriz_t const * const  me,
					 matriz_t const * const  outro,
					 matriz_t       * const res){
    return (me->metodo->multiplica(me, outro, res));
}

static inline
matriz_pt       Mat_multiplicaEscalar   (matriz_t       * const  me,
					 double escalar){
    return (me->metodo->multiplicaEscalar(me, escalar));
}

static inline 
matriz_pt       Mat_ac_soma             (matriz_t       * const  me,
					 matriz_t const * const outro){
    return (me->metodo->ac_soma(me, outro));
}

static inline
matriz_pt       Mat_ac_subtracao        (matriz_t       * const  me,
					 matriz_t const * const outro){
    return (me->metodo->ac_subtracao(me, outro));
}

static inline 
matriz_pt       Mat_ac_multiplicacao    (matriz_t       * const  me,
					 matriz_t const * const outro){
    return (me->metodo->ac_multiplicacao(me, outro));
}

static inline 
int             Mat_compara             (matriz_t const * const  me,
                                         matriz_t const * const  outro){
    return (me->metodo->compara(me, outro));
}

static inline 
void            Mat_imprime             (matriz_t const * const  me){
    return (me->metodo->imprime)(me);
}

static inline 
void            Mat_destroi             (matriz_t       *        me){
    return(me->metodo->destroi)(me);
}

#endif /* MATRIZ_H */

