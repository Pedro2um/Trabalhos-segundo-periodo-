/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   numero.h
 * Author: eduarda
 *
 * Created on 5 de março de 2022, 10:23
 */

#ifndef NUMERO_H
#define NUMERO_H

struct numero;
struct numeroVtbl;

typedef struct numero   numero_t;
typedef struct numero * numero_pt;

struct numero {
    struct numeroVtbl const * metodo; //posso mudar para onde aponta mas não posso mudar o que está sendo apontado
};

/*                                                                            *
 * ---------------------------------------------------------------------------*
 *                                                                            */

numero_pt constroiNumero ();
void      destroiNumero  (numero_pt num);

/*                                                                            *
 * ---------------------------------------------------------------------------*
 *                                                                            */

struct numeroVtbl{
    /* optei por deixar na Vtbl apenas as funções que psão mais úteis na 
     * hora de generalizar os números. Funções de soma, multiplicação etc 
     * são inúteis quando os tipos númericos tem sua própria interface e 
     * só funcionam se os números envolvidos forem do mesmo tipo
     */
    numero_pt 	(*copia)                (numero_t const * const num);
    
    numero_pt 	(*atribui)              (numero_t const * const  num1,
                                         numero_t       * const  num2);
    
    numero_pt 	(*soma)                 (numero_t const * const  num1,
                                         numero_t const * const  num2,
                                         numero_t       * const  resp);

    numero_pt 	(*subtrai)              (numero_t const * const  num1,
                                         numero_t const * const  num2,
                                         numero_t       * const  resp);

    numero_pt 	(*multiplica)           (numero_t const * const  num1,
                                         numero_t const * const  num2,
                                         numero_t       * const  resp);
    
    numero_pt 	(*divide)               (numero_t const * const  num1,
                                         numero_t const * const  num2,
                                         numero_t       * const  resp);
    
    numero_pt 	(*ac_soma)              (numero_t       * const  num1,
                                         numero_t const * const  num2);

    numero_pt 	(*ac_subtracao)         (numero_t       * const  num1,
                                         numero_t const * const  num2);
    
    numero_pt 	(*ac_multiplicacao)	(numero_t       * const  num1,
                                         numero_t const * const  num2);
    
    numero_pt 	(*ac_divisao)           (numero_t       * const  num1,
                                         numero_t const * const  num2);
    
    int         (*compara)              (numero_t const * const  num1,
                                         numero_t const * const  num2);
    
    
    char *      (*imprime)              (numero_t const * const  num);

    void        (*destroi)              (numero_t       *        num);
};

/*                                                                            *
 * ---------------------------------------------------------------------------*
 *                                                                            */

static inline   
numero_pt       Num_copia               (numero_t const * const me) {
    return (  me->metodo->copia(me));
}

static inline 
numero_pt       Num_atribui             (numero_t const * const  me,
					 numero_t       * const  outro){
    return (me->metodo->atribui(me, outro));
}

static inline 
numero_pt       Num_soma                (numero_t const * const  me,
					 numero_t const * const  outro,
					 numero_t       * const res){
    return (me->metodo->soma(me, outro, res));
}

static inline 
numero_pt       Num_subtrai             (numero_t const * const  me,
					 numero_t const * const  outro,
					 numero_t       * const res){
    return (me->metodo->subtrai(me, outro, res));
}

static inline
numero_pt       Num_multiplica          (numero_t const * const  me,
					 numero_t const * const  outro,
					 numero_t       * const res){
    return (me->metodo->multiplica(me, outro, res));
}

static inline 
numero_pt       Num_divide              (numero_t const * const  me,
					 numero_t const * const  outro,
					 numero_t       * const res){
    return (me->metodo->divide(me, outro, res));
}

static inline 
numero_pt       Num_ac_soma             (numero_t       * const  me,
					 numero_t const * const outro){
    return (me->metodo->ac_soma(me, outro));
}

static inline
numero_pt       Num_ac_subtracao        (numero_t       * const  me,
					 numero_t const * const outro){
 return (me->metodo->ac_subtracao(me, outro));
}

static inline 
numero_pt       Num_ac_multiplicacao    (numero_t       * const  me,
					 numero_t const * const outro){
 return (me->metodo->ac_multiplicacao(me, outro));
}

static inline 
numero_pt       Num_ac_divisao          (numero_t        * const  me,
					 numero_t const * const outro){
 return (me->metodo->ac_divisao(me, outro));
}

static inline 
int             Num_compara             (numero_t const * const  me,
                                         numero_t const * const  outro){
    return (me->metodo->compara(me, outro));
}

static inline 
char *          Num_imprime             (numero_t const * const  me){
    return (me->metodo->imprime)(me);
}

static inline 
void            Num_destroi             (numero_t  *   me){
    return(me->metodo->destroi)(me);
}

#endif /* NUMERO_H */

