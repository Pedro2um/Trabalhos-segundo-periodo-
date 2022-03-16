/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "racional.h"

/* 
 * As funções que iniciam com letra MINÚSCULA são referentes as funções que pre-
 * encheram a VTBL, enquanto que as que começam com letra MAIÚSCULA fazem parte
 * da interface do tipo racional
 */


/* ---------------------------------------------------------------------------*
 * -------------------------CHAMADA FUNÇÕES VTBL------------------------------*
 * ---------------------------------------------------------------------------*/

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

/* ---------------------------------------------------------------------------*
 * -----------------------CHAMADA FUNÇÕES INTERFACE---------------------------*
 * ---------------------------------------------------------------------------*/                                                                            

static racional_pt      Copia            (racional_t const * const rac);
static racional_pt      Atribui          (racional_t const * const origem,  
                                            racional_t const * const destino);
static racional_pt      Soma             (racional_t const * const rac1, 
                                            racional_t const * const rac2,
                                            racional_t       * const resp);    
static racional_pt      Subtrai          (racional_t const * const rac1, 
                                            racional_t const * const rac2,
                                            racional_t       * const resp);
static racional_pt      Multiplica       (racional_t const * const rac1, 
                                            racional_t const * const rac2,
                                            racional_t       * const resp);
static racional_pt      Divide           (racional_t const * const rac1, 
                                            racional_t const * const rac2,
                                            racional_t       * const resp);
static racional_pt      Ac_soma          (racional_t       * const rac1, 
                                            racional_t const * const rac2);
static racional_pt      Ac_subtracao     (racional_t       * const rac1, 
                                            racional_t const * const rac2);
static racional_pt      Ac_multiplicacao (racional_t       * const rac1, 
                                            racional_t const * const rac2);
static racional_pt      Ac_divisao       (racional_t       * const rac1, 
                                            racional_t const * const rac2);
static racional_pt      Potencia	 (racional_t       * const rac,
                                            int potencia);
static long double      Modulo		 (racional_t const * const rac);
    
static long double      ModuloRaiz       (racional_t const * const rac,
                                          int raiz);
static int              Compara          (racional_t const * const rac1, 
                                            racional_t const * const rac2);								 
static int              EhNulo           (racional_t const * const rac);
static long int         ObtemNumerador   (racional_t const * const rac);
static long int         ObtemDenominador (racional_t const * const rac);
static void             DefineNumerador  (racional_t       * const rac,
                                            long int  num);
static void             DefineDenominador(racional_t       * const rac,
                                            long int  den);
static char *           Imprime          (racional_t const * const rac);
static void             Destroi          (racional_t       *       rac);

/* 
 * A função reduz é uma função estática que tem como função auxiliar as demais
 * funções, e não compor a interface dos números racionais
 */
static void            Reduz            (racional_t       * const rac);

/* ---------------------------------------------------------------------------*
 * ----------------------IMPLEMENTAÇÃO FUNÇÕES GLOBAIS------------------------*
 * ---------------------------------------------------------------------------*/

racional_pt constroiRacional (long int num, long int den){
    
    racional_pt rac = malloc(sizeof(racional_t));
    
    if(den == 0){
        printf("ERRO! O denominador não pode assumir o valor ZERO!");
        exit(1);
    }
    else if((num * den < 0 && den < 0) || (num * den > 0 && den < 0)){
        num = labs(num);
        den = labs(den);
        num *= -1;
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
    rac->super.metodo = &vtbl;
    
    static struct racional_interface inter = {
        &Copia,
        &Atribui,
        &Soma,
        &Subtrai,
        &Multiplica,
        &Divide,
        &Ac_soma,
        &Ac_subtracao,
        &Ac_multiplicacao,
        &Ac_divisao,
        &Potencia,
        &Compara,
        &EhNulo,
        &ObtemNumerador,
        &ObtemDenominador,
        &DefineNumerador,
        &DefineDenominador,
        &Modulo,
        //&ModuloRaiz,
        &Imprime,
        &Destroi
    };
    rac->Metodo = &inter;
    
    rac->numerador = num;
    rac->denominador = den;
    
    Reduz(rac);
    
    return rac;
}

racional_pt zeraRacional     (){
    
    racional_pt rac;
    rac = constroiRacional(0, 1);
    return rac;
}

racional_pt unitarioRacional (){
    
    racional_pt rac;
    rac = constroiRacional(1, 1);
    return rac;
}

/* ---------------------------------------------------------------------------*
 * ---------------------IMPLEMENTAÇÃO FUNÇÕES ESTÁTICAS-----------------------*
 * ---------------------------------------------------------------------------*/

static numero_pt            copia           (numero_t const * const num){
    
    assert(num != NULL);
    numero_pt numNovo;
    numNovo = (numero_pt)constroiRacional(ObtemNumerador((racional_pt)num),
                                          ObtemDenominador((racional_pt)num));
    return numNovo;
}

static inline racional_pt   Copia           (racional_t const * const rac){
    return ((racional_pt)copia((numero_pt) rac));
}

/*---------------------------------------------------------------------------*/

static numero_pt            atribui         (numero_t const * const  num1,
                                             numero_t       * const  num2){
    assert(num1 != NULL);
    assert(num2 != NULL);
    ((racional_pt)num2)->numerador = ((racional_pt)num1)->numerador;
    ((racional_pt)num2)->denominador = ((racional_pt)num1)->denominador;
    
    return num2;
}    

static inline racional_pt   Atribui         (racional_t const * const origem,  
                                             racional_t const * const destino){
    return ((racional_pt)atribui((numero_pt)origem, (numero_pt)destino));
}

/*---------------------------------------------------------------------------*/

static numero_pt            soma            (numero_t const * const  num1,
                                             numero_t const * const  num2,
                                             numero_t       * const  resp){
   assert(num1 != NULL);
   assert(num2 != NULL);
   assert(resp != NULL);

   racional_pt numero1 = (racional_pt)num1;
   racional_pt numero2 = (racional_pt)num2;
   
   long int num, den;
   
   den = numero1->denominador * numero2->denominador;
   num = ((den / numero1->denominador) * numero1->numerador) +
         ((den / numero2->denominador) * numero2->numerador);
   
   DefineNumerador  ((racional_pt)resp, num);
   DefineDenominador((racional_pt)resp, den);
   Reduz((racional_pt)resp);
   
   return resp;
}


static inline racional_pt   Soma            (racional_t const * const rac1, 
                                             racional_t const * const rac2,
                                             racional_t       * const resp){
    return((racional_pt)soma((numero_pt)rac1, (numero_pt)rac2, (numero_pt)resp));
}

/*---------------------------------------------------------------------------*/

static numero_pt            subtrai         (numero_t const * const  num1,
                                             numero_t const * const  num2,
                                             numero_t       * const  resp){
    assert(num1 != NULL);
    assert(num2 != NULL);
    assert(resp != NULL);

    racional_pt numero1 = (racional_pt)num1;
    racional_pt numero2 = (racional_pt)num2;
   
    long int num, den;
   
    den = numero1->denominador * numero2->denominador;
    num = ((den / numero1->denominador) * numero1->numerador) -
          ((den / numero2->denominador) * numero2->numerador);
   
    DefineNumerador  ((racional_pt)resp, num);
    DefineDenominador((racional_pt)resp, den);
    Reduz((racional_pt)resp);
   
    return resp;

}

static inline racional_pt   Subtrai         (racional_t const * const rac1, 
                                             racional_t const * const rac2,
                                             racional_t       * const resp){
    return((racional_pt)subtrai((numero_pt)rac1, 
                                (numero_pt)rac2, (numero_pt)resp));
}

/*---------------------------------------------------------------------------*/

static numero_pt            multiplica      (numero_t const * const  num1,
                                             numero_t const * const  num2,
                                             numero_t       * const  resp){
    assert(num1 != NULL);
    assert(num2 != NULL);
    assert(resp != NULL);

    racional_pt numero1 = (racional_pt)num1;
    racional_pt numero2 = (racional_pt)num2;
   
    long int num, den;
   
    den = numero1->denominador * numero2->denominador;
    num = numero1->numerador   * numero2->numerador;
   
    DefineNumerador  ((racional_pt)resp, num);
    DefineDenominador((racional_pt)resp, den);
    Reduz((racional_pt)resp);
   
    return resp;
}
static inline racional_pt   Multiplica      (racional_t const * const rac1, 
                                             racional_t const * const rac2,
                                             racional_t       * const resp){
    return((racional_pt)multiplica((numero_pt)rac1, 
                                   (numero_pt)rac2, (numero_pt)resp));
}

/*---------------------------------------------------------------------------*/

static numero_pt            divide          (numero_t const * const  num1,
                                             numero_t const * const  num2,
                                             numero_t       * const  resp){
    assert(num1 != NULL);
    assert(num2 != NULL);
    assert(resp != NULL);

    racional_pt numero1 = (racional_pt)num1;
    racional_pt numero2 = (racional_pt)num2;
   
    long int num, den;
   
    den = numero1->denominador * numero2->numerador;
    num = numero1->numerador   * numero2->denominador;
   
    DefineNumerador  ((racional_pt)resp, num);
    DefineDenominador((racional_pt)resp, den);
    Reduz((racional_pt)resp);
   
    return resp;
}


static inline racional_pt   Divide          (racional_t const * const rac1, 
                                             racional_t const * const rac2,
                                             racional_t       * const resp){
    return((racional_pt)divide((numero_pt)rac1, 
                               (numero_pt)rac2, (numero_pt)resp));
}

/*---------------------------------------------------------------------------*/

static numero_pt            ac_soma         (numero_t       * const  num1,
                                             numero_t const * const  num2){
   assert(num1 != NULL);
   assert(num2 != NULL);

   racional_pt numero1 = (racional_pt)num1;
   racional_pt numero2 = (racional_pt)num2;
   
   long int num, den;
   
   den = numero1->denominador * numero2->denominador;
   num = ((den / numero1->denominador) * numero1->numerador) +
         ((den / numero2->denominador) * numero2->numerador);
   
   DefineNumerador  ((racional_pt)num1, num);
   DefineDenominador((racional_pt)num1, den);
   Reduz((racional_pt)num1);
   
   return num1;
}


static inline racional_pt   Ac_soma         (racional_t       * const rac1, 
                                             racional_t const * const rac2){
    return((racional_pt)ac_soma((numero_pt)rac1, (numero_pt)rac2));
}

/*---------------------------------------------------------------------------*/

static numero_pt            ac_subtracao    (numero_t       * const  num1,
                                             numero_t const * const  num2){
   assert(num1 != NULL);
   assert(num2 != NULL);

   racional_pt numero1 = (racional_pt)num1;
   racional_pt numero2 = (racional_pt)num2;
   
   long int num, den;
   
   den = numero1->denominador * numero2->denominador;
   num = ((den / numero1->denominador) * numero1->numerador) -
         ((den / numero2->denominador) * numero2->numerador);
   
   DefineNumerador  ((racional_pt)num1, num);
   DefineDenominador((racional_pt)num1, den);
   Reduz((racional_pt)num1);
   
   return num1;
}


static inline racional_pt   Ac_subtracao    (racional_t       * const rac1, 
                                             racional_t const * const rac2){
    return((racional_pt)ac_subtracao((numero_pt)rac1, (numero_pt)rac2));
}

/*---------------------------------------------------------------------------*/

static numero_pt            ac_multiplicacao(numero_t       * const  num1,
                                             numero_t const * const  num2){
   assert(num1 != NULL);
   assert(num2 != NULL);

   racional_pt numero1 = (racional_pt)num1;
   racional_pt numero2 = (racional_pt)num2;
   
   long int num, den;
   
   den = numero1->denominador * numero2->denominador;
   num = numero1->numerador   * numero2->numerador;
   
   DefineNumerador  ((racional_pt)num1, num);
   DefineDenominador((racional_pt)num1, den);
   Reduz((racional_pt)num1);
   
   return num1;
}


static inline racional_pt   Ac_multiplicacao(racional_t       * const rac1, 
                                             racional_t const * const rac2){
    return((racional_pt)ac_multiplicacao((numero_pt)rac1, (numero_pt)rac2));
}

/*---------------------------------------------------------------------------*/

static numero_pt            ac_divisao      (numero_t       * const  num1,
                                             numero_t const * const  num2){
   assert(num1 != NULL);
   assert(num2 != NULL);

   racional_pt numero1 = (racional_pt)num1;
   racional_pt numero2 = (racional_pt)num2;
   
   long int num, den;
   
   den = numero1->denominador * numero2->numerador;
   num = numero1->numerador   * numero2->denominador;
   
   DefineNumerador  ((racional_pt)num1, num);
   DefineDenominador((racional_pt)num1, den);
   Reduz((racional_pt)num1);
   
   return num1;
}


static inline racional_pt   Ac_divisao      (racional_t       * const rac1, 
                                             racional_t const * const rac2){
    return((racional_pt)ac_divisao((numero_pt)rac1, (numero_pt)rac2));
}

/*---------------------------------------------------------------------------*/

static int                  compara         (numero_t const * const  num1,
                                             numero_t const * const  num2){
    long double r1, r2;
    
    r1 = ((racional_pt)num1)->numerador / ((racional_pt)num1)->denominador;
    r2 = ((racional_pt)num2)->numerador / ((racional_pt)num2)->denominador;
    
    //if(((racional_pt)num1)->numerador == ((racional_pt)num2)->numerador &&
    //   ((racional_pt)num1)->denominador == ((racional_pt)num2)->denominador)
    
    if(r1 == r2)
        return 0;
    else if(r1 > r2)
        return 1;
    else 
        return -1;
}

static inline int           Compara         (racional_t const * const rac1, 
                                             racional_t const * const rac2){
    return(compara((numero_pt)rac1, (numero_pt)rac2));
}

/*---------------------------------------------------------------------------*/

static char *               imprime         (numero_t const * const  num){
    
    static char numRacional[50];
    numRacional[0] = '\n';
    if(labs(((racional_pt)num)->numerador) == labs(((racional_pt)num)->denominador))
        sprintf(numRacional,"%ld", ((racional_pt)num)->numerador);
    else
        sprintf(numRacional,"%ld/%ld", ((racional_pt)num)->numerador,
                                         ((racional_pt)num)->denominador);
    //printf("[%s]\n", numRacional);
    return numRacional;
}

static inline char *        Imprime         (racional_t const * const rac){
    return (imprime((numero_pt)rac));
}

/*---------------------------------------------------------------------------*/

static void                 destroi         (numero_t       *       num){
    
    if((racional_pt)num != NULL){
        free((racional_pt)num);
    }
}

static inline void          Destroi         (racional_t     *       rac){
    return (destroi((numero_pt)rac));
}

/*---------------------------------------------------------------------------*/
static racional_pt          Potencia        (racional_t       * const rac,
                                             int potencia){
    
    assert(rac != NULL);
    rac->numerador   = pow(rac->numerador, potencia);
    rac->denominador = pow(rac->denominador, potencia);
    
    return rac;
}

static long double          Modulo          (racional_t const * const rac){
    
    assert(rac != NULL);
    
    long double r;
    r = (long double)rac->numerador / rac->denominador;
    
    return r;
}
    
/*static long double          ModuloRaiz      (racional_t const * const rac,
                                             int raiz){
    
    assert(rac != NULL);
    
    long double r, num, den;
    num = pow(rac->numerador, ((float)1/raiz));
    den = pow(rac->denominador, ((float)1/raiz));
    r = num / den;
    return r;
}*/

static void                 Reduz           (racional_t       * const rac){
    
    int sinal;
    
    if ((rac->numerador * rac->denominador) < 0)
        sinal = -1 ;
    else
        sinal = + 1;
	
    long int a, b, MDC;
	
    if (rac->numerador > rac->denominador){
	a =  labs (rac->numerador);
	b =  labs (rac->denominador); 
    }
    else{
	a = labs(rac->denominador);
	b = labs(rac->numerador);
    }
    
    while (b != 0){
	MDC = b;
	b = a % b;
	a = MDC;
    }
    rac->numerador   = labs(rac->numerador)  / a * sinal;
    rac->denominador = labs(rac->denominador)/ a;
}

static inline int           EhNulo          (racional_t const * const rac){
    return (!rac->numerador);
}

static inline long int      ObtemNumerador  (racional_t const * const rac){
    return rac->numerador;
}

static inline long int      ObtemDenominador(racional_t const * const rac){
    return rac->denominador;
}

static void inline          DefineNumerador (racional_t       * const rac,
                                             long int  num){
    rac->numerador = num;
}

static void                 DefineDenominador(racional_t       * const rac,
                                              long int  den){
    if(!den){
        printf("ERRO! O denominador não pode assumir o valor ZERO!");
        exit(1);
    }
    rac->denominador = den;
}
