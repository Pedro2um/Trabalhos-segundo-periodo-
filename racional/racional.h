/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   racional.h
 * Author: eduarda
 *
 * Created on 5 de março de 2022, 10:23
 */

#ifndef RACIONAL_H
#define RACIONAL_H

#include "numero.h"

struct racional;
struct racional_interface;

typedef struct racional   racional_t;
typedef struct racional * racional_pt;

struct racional {
    struct numero super;
    struct racional_interface const * Metodo;
    long int numerador;
    long int denominador;
};

/*                                                                            *
 * ---------------------------------------------------------------------------*
 *                                                                            */

racional_pt constroiRacional (long int num, long int den);
racional_pt zeraRacional     ();
racional_pt unitarioRacional ();

/*                                                                            *
 * ---------------------------------------------------------------------------*
 *                                                                            */

struct racional_interface {
    
    racional_pt     (*copia)            (racional_t const * const rac);

    racional_pt     (*atribui)          (racional_t const * const origem,  
					 racional_t const * const destino);
    
    racional_pt     (*soma)             (racional_t const * const rac1, 
					 racional_t const * const rac2,
                                         racional_t       * const resp);
    
    racional_pt     (*subtrai)          (racional_t const * const rac1, 
					 racional_t const * const rac2,
                                         racional_t       * const resp);
    
    racional_pt     (*multiplica)       (racional_t const * const rac1, 
					 racional_t const * const rac2,
                                         racional_t       * const resp);
    
    racional_pt     (*divide)           (racional_t const * const rac1, 
					 racional_t const * const rac2,
                                         racional_t       * const resp);
    
    racional_pt     (*ac_soma)          (racional_t       * const rac1, 
                                         racional_t const * const rac2);
    
    racional_pt     (*ac_subtracao)     (racional_t       * const rac1, 
                                         racional_t const * const rac2);
    
    racional_pt     (*ac_multiplicacao) (racional_t       * const rac1, 
                                         racional_t const * const rac2);
    
    racional_pt     (*ac_divisao)       (racional_t       * const rac1, 
                                         racional_t const * const rac2);
    
    racional_pt     (*potencia)		(racional_t       * const rac,
                                         int potencia);
    
    int             (*compara)          (racional_t const * const rac1, 
                                         racional_t const * const rac2);
									 									 
    int             (*ehNulo)		(racional_t const * const rac);
    
    long int        (*obtemNumerador)	(racional_t const * const rac);
    
    long int        (*obtemDenominador)	(racional_t const * const rac);
    
    void            (*defineNumerador)	(racional_t       * const rac,
                                         long int  num);
    
    void            (*defineDenominador)(racional_t       * const rac,
                                         long int  den);
    
    long double     (*modulo)		(racional_t const * const rac);
    
    char *          (*imprime)		(racional_t const * const rac);
    
    void            (*destroi)		(racional_t       *       rac);
        
};

#endif /* RACIONAL_H */
