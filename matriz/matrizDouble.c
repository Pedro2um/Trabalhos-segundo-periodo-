/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "matrizDouble.h"

/* ---------------------------------------------------------------------------*
 * -------------------------CHAMADA FUNÇÕES VTBL------------------------------*
 * ---------------------------------------------------------------------------*/

static  matriz_pt   copia               (matriz_t const * const  mat);   
static  matriz_pt   atribui             (matriz_t const * const  mat1,
                                         matriz_t       *        mat2);    
static  matriz_pt   soma                (matriz_t const * const  mat1,
                                         matriz_t const * const  mat2,
                                         matriz_t       *        resp);
static  matriz_pt   subtrai             (matriz_t const * const  mat1,
                                         matriz_t const * const  mat2,
                                         matriz_t       *        resp);
static  matriz_pt   multiplica          (matriz_t const * const  mat1,
                                         matriz_t const * const  mat2,
                                         matriz_t       *        resp);
static  matriz_pt   multiplicaEscalar   (matriz_t       * const  mat1,
                                         double escalar);
static  matriz_pt   ac_soma             (matriz_t       *        mat1,
                                         matriz_t const * const  mat2);
static  matriz_pt   ac_subtracao        (matriz_t       *        mat1,
                                         matriz_t const * const  mat2);
static  matriz_pt   ac_multiplicacao    (matriz_t       *        mat1,
                                         matriz_t const * const  mat2);
static  int         compara             (matriz_t const * const  mat1,
                                         matriz_t const * const  mat2);
static  void        imprime             (matriz_t const * const  mat);
static  void        destroi             (matriz_t       *        mat);

/* ---------------------------------------------------------------------------*
 * -----------------------CHAMADA FUNÇÕES INTERFACE---------------------------*
 * ---------------------------------------------------------------------------*/ 

static  matrizDoub_pt   Copia               (matrizDoub_t const * const  mat);

static  matrizDoub_pt   Atribui             (matrizDoub_t const * const  mat1,
                                             matrizDoub_t       *        mat2);    

static  matrizDoub_pt   Soma                (matrizDoub_t const * const  mat1,
                                             matrizDoub_t const * const  mat2,
                                             matrizDoub_t       *        resp);

static  matrizDoub_pt   Subtrai             (matrizDoub_t const * const  mat1,
                                             matrizDoub_t const * const  mat2,
                                             matrizDoub_t       *        resp);

static  matrizDoub_pt   Multiplica          (matrizDoub_t const * const  mat1,
                                             matrizDoub_t const * const  mat2,
                                             matrizDoub_t       *        resp);

static  matrizDoub_pt   MultiplicaEscalar   (matrizDoub_t       * const  mat1,
                                             double escalar);

static  matrizDoub_pt   Ac_soma             (matrizDoub_t       *        mat1,
                                             matrizDoub_t const * const  mat2);

static  matrizDoub_pt   Ac_subtracao        (matrizDoub_t       *        mat1,
                                             matrizDoub_t const * const  mat2);

static  matrizDoub_pt   Ac_multiplicacao    (matrizDoub_t       *        mat1,
                                             matrizDoub_t const * const  mat2);

static  int             Compara             (matrizDoub_t const * const  mat1,
                                             matrizDoub_t const * const  mat2);

static  void            Imprime             (matrizDoub_t const * const  mat);

static  void            Destroi             (matrizDoub_t       *        mat);

static  matrizDoub_pt   Transposta          (matrizDoub_t       *        mat);

static  matrizDoub_pt   Transposta_2D       (matrizDoub_t       *        mat);

static  matrizDoub_pt   Reverse_Horizontal  (matrizDoub_t       * const  mat);

static  matrizDoub_pt   Reverse_Vertical    (matrizDoub_t       * const  mat);

static  matrizDoub_pt   DefineLinhas        (matrizDoub_t       *        mat,
                                             unsigned int linha);

static  matrizDoub_pt   DefineColunas       (matrizDoub_t       *        mat,
                                             unsigned int coluna);

static  matrizDoub_pt   Redimensiona        (matrizDoub_t       *        mat,
                                             unsigned int linha,
                                             unsigned int coluna);

static  matrizDoub_pt   AdicionaLinha       (matrizDoub_t       * const  mat);

static  matrizDoub_pt   AdicionaColuna      (matrizDoub_t       * const  mat);

static  int             ComparaDimensoes    (matrizDoub_t const * const  mat1,
                                             matrizDoub_t const * const  mat2);

static  int             ObtemLinhas         (matrizDoub_t const *   const mat);

static  int             ObtemColunas        (matrizDoub_t const *   const mat);

/* ---------------------------------------------------------------------------*
 * ----------------------IMPLEMENTAÇÃO FUNÇÕES GLOBAIS------------------------*
 * ---------------------------------------------------------------------------*/

matrizDoub_pt   ConstroiMatriz          (unsigned int linha, unsigned int coluna){
    
    matrizDoub_pt mat = (matrizDoub_t *)malloc(sizeof(matrizDoub_t));
    if(mat == NULL){
        printf("ERRO AO ALOCAR MEMÓRIA EM 'ConstroiMatriz'");
        exit(1);
    }
    
    mat = Redimensiona(mat, linha, coluna);
    
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
    mat->super.metodo = &vtbl;
    
    static struct matrizDouble_Interface inter = {
        &Copia,
        &Atribui,
        &Soma,
        &Subtrai,
        &Multiplica,
        &MultiplicaEscalar,
        &Ac_soma,
        &Ac_subtracao,
        &Ac_multiplicacao,
        &Compara,
        &Imprime,
        &Destroi,
        &Transposta,
        &Transposta_2D,
        &Reverse_Horizontal,
        &Reverse_Vertical,
        &DefineLinhas,
        &DefineColunas,
        &Redimensiona,
        &AdicionaLinha,
        &AdicionaColuna,
        &ComparaDimensoes,
        &ObtemLinhas,
        &ObtemColunas
    };
    mat->Metodo = &inter;
    
    return mat;
}

matrizDoub_pt   ConstroiMatrizNula      (unsigned int linha, unsigned int coluna){
    
    matrizDoub_pt mat;
    mat = ConstroiMatriz(linha, coluna);
    
    for(int i = 0; i < mat->tamanho[LINHA]; i++){
        for(int j = 0; j < mat->tamanho[COLUNA]; j++){
            mat->valor[i][j] = 0;
        }
    }
    
    return mat;
}

matrizDoub_pt   ConstroiMatrizUnitaria  (unsigned int linha, unsigned int coluna){
        
    matrizDoub_pt mat;
    mat = ConstroiMatriz(linha, coluna);
    
    for(int i = 0; i < mat->tamanho[LINHA]; i++){
        for(int j = 0; j < mat->tamanho[COLUNA]; j++){
            mat->valor[i][j] = 1;
        }
    }
    
    return mat;
}

matrizDoub_pt   ConstroiMatrizIdentidade(unsigned int linha, unsigned int coluna){
    
    if(linha != coluna){
        printf("O NÚMERO DE LINHAS PRECISA SER IGUAL AO NÚMERO DE COLUNAS!!!\n");
        return NULL;
    }
    
    matrizDoub_pt mat;
    mat = ConstroiMatriz(linha, coluna);
    
    for(int i = 0; i < mat->tamanho[LINHA]; i++){
        for(int j = 0; j < mat->tamanho[COLUNA]; j++){
            
            if(i == j) mat->valor[i][j] = 1;
            else mat->valor[i][j] = 0;
        }
    }
    
    return mat;
}

/* ---------------------------------------------------------------------------*
 * ---------------------IMPLEMENTAÇÃO FUNÇÕES ESTÁTICAS-----------------------*
 * ---------------------------------------------------------------------------*/

static  
matrizDoub_pt   Copia               (matrizDoub_t const * const  mat){
    return ((matrizDoub_pt)copia((matriz_pt)mat));
}

static  
matriz_pt       copia               (matriz_t const * const  mat){
    
    matrizDoub_pt new;
	 
    new = ConstroiMatriz( ((matrizDoub_pt)mat)->tamanho[LINHA], ((matrizDoub_pt)mat)->tamanho[COLUNA]   );
	 
    for(int i = 0; i < new->tamanho[LINHA]; i++){	 
	for(int j = 0; j < new->tamanho[COLUNA]; j++){	
            new->valor[i][j] = ((matrizDoub_pt)mat)->valor[i][j];
	}
    }
	 	
    return (matriz_pt)new;
}

/*----------------------------------------------------------------------------*/

static  
matrizDoub_pt   Atribui             (matrizDoub_t const * const  mat1,
                                     matrizDoub_t       *        mat2){
    return ((matrizDoub_pt)atribui((matriz_pt)mat1, (matriz_pt)mat2));
}

static  
matriz_pt       atribui             (matriz_t const * const  mat1,
                                     matriz_t       *        mat2){
        
    mat2 = (matriz_pt)Redimensiona((matrizDoub_pt)mat2, 
                                  ((matrizDoub_pt)mat1)->tamanho[LINHA], 
                                  ((matrizDoub_pt)mat1)->tamanho[COLUNA]);            
        				                      
    for(int i = 0; i < ((matrizDoub_pt)mat2)->tamanho[LINHA]; i++){
 	for(int j = 0; j < ((matrizDoub_pt)mat2)->tamanho[COLUNA]; j++){
            ((matrizDoub_pt)mat2)->valor[i][j] = ((matrizDoub_pt)mat1)->valor[i][j];
	}
    }
                                     
    return mat2;              
}

/*----------------------------------------------------------------------------*/

static  
matrizDoub_pt   Soma                (matrizDoub_t const * const  mat1,
                                     matrizDoub_t const * const  mat2,
                                     matrizDoub_t       *        resp){                                         
    return ((matrizDoub_pt)soma((matriz_pt)mat1, (matriz_pt)mat2, (matriz_pt)resp));
	
}

static  
matriz_pt       soma                (matriz_t const * const  mat1,
                                     matriz_t const * const  mat2,
                                     matriz_t       *        resp){
        
    // ComparaDimensoes
    // 1 iguais 
    // 0 se e somente, tanto as linhas como as colunas são distintas
    // -1 caso linha_mat_1 == linha coluna_mat_2
        
    if(ComparaDimensoes((matrizDoub_pt)mat1, (matrizDoub_pt)mat2) <= 0 ){
    	printf("MATRIZES INCOMPATIVEIS!!!\n");
    	return NULL;
    }
    resp = (matriz_pt)Redimensiona((matrizDoub_pt)resp, 
                                  ((matrizDoub_pt)mat1)->tamanho[LINHA], 
                                  ((matrizDoub_pt)mat1)->tamanho[COLUNA]); 
    
    for(int i = 0; i < ((matrizDoub_pt)resp)->tamanho[LINHA]; i++){    
        for(int j = 0; j < ((matrizDoub_pt)resp)->tamanho[COLUNA]; j++){	
            ((matrizDoub_pt)resp)->valor[i][j] = 
            ((matrizDoub_pt)mat1)->valor[i][j] + 
            ((matrizDoub_pt)mat2)->valor[i][j];	
        }    	
    }
        
    return resp;
}

/*----------------------------------------------------------------------------*/

static  
matrizDoub_pt   Subtrai                (matrizDoub_t const * const  mat1,
                                        matrizDoub_t const * const  mat2,
                                        matrizDoub_t       *        resp){
    
    return ((matrizDoub_pt)soma((matriz_pt)mat1, (matriz_pt)mat2, (matriz_pt)resp));	
}

static  
matriz_pt       subtrai                (matriz_t const * const  mat1,
                                        matriz_t const * const  mat2,
                                        matriz_t       *        resp){
        
    // ComparaDimensoes
    // 1 iguais 
    // 0 se e somente, tanto as linhas como as colunas são distintas
    // -1 caso linha_mat_1 == linha coluna_mat_2
        
    if(ComparaDimensoes((matrizDoub_pt)mat1, (matrizDoub_pt)mat2) <= 0 ){
    	printf("MATRIZES INCOMPATIVEIS!!!\n");
    	return NULL;
    }
    resp = (matriz_pt)Redimensiona((matrizDoub_pt)resp, 
                                  ((matrizDoub_pt)mat1)->tamanho[LINHA], 
                                  ((matrizDoub_pt)mat1)->tamanho[COLUNA]); 
    
    //int i, j;
    for(int i = 0; i < ((matrizDoub_pt)resp)->tamanho[LINHA]; i++){    
        for(int j = 0; j < ((matrizDoub_pt)resp)->tamanho[COLUNA]; j++){	
            ((matrizDoub_pt)resp)->valor[i][j] = 
            ((matrizDoub_pt)mat1)->valor[i][j] - 
            ((matrizDoub_pt)mat2)->valor[i][j];	
        }    	
    }
        
    return resp;
}

/*----------------------------------------------------------------------------*/

static
matrizDoub_pt   Multiplica              (matrizDoub_t const * const  mat1,
                                         matrizDoub_t const * const  mat2,
                                         matrizDoub_t       *        resp){
    
    return (matrizDoub_pt)multiplica((matriz_pt)mat1, (matriz_pt)mat2, 
                                     (matriz_pt)resp);
}

static
matriz_pt       multiplica              (matriz_t const * const  mat1,
                                         matriz_t const * const  mat2,
                                         matriz_t       *        resp){
    
    matrizDoub_pt const matriz1 = (matrizDoub_pt)mat1;
    matrizDoub_pt const matriz2 = (matrizDoub_pt)mat2;
    
    if(mat1 == resp || mat2 == resp){
        printf("ERRO! A MATRIZ 1 OU A MATRIZ 2 NÃO PODEM SER A MESMA QUE A"
               "MATRIZ A SER MODIFICADA\n");
        return NULL;
    }
    else if(!ComparaDimensoes(matriz1, matriz2)){
        printf("NUMERO DE COLUNAS DA MATRIZ 1 != NUMERO LINHAS MATRIZ 2\n");
        return NULL;
    }
    
    resp = (matriz_pt)Redimensiona((matrizDoub_pt)resp, matriz1->tamanho[LINHA], 
                                             matriz2->tamanho[COLUNA]);
    
    for(int i = 0; i < ((matrizDoub_pt)resp)->tamanho[LINHA]; i++){
        for(int j = 0; j < ((matrizDoub_pt)resp)->tamanho[COLUNA]; j++){
            
            ((matrizDoub_pt)resp)->valor[i][j] = 0;
            
            for(int k = 0; k < matriz1->tamanho[COLUNA]; k++){
                                    
                ((matrizDoub_pt)resp)->valor[i][j] += matriz1->valor[i][k] *
                                                      matriz2->valor[k][j];
            }
        }
    }
    
    return resp;
}

/*----------------------------------------------------------------------------*/

static  
matrizDoub_pt   MultiplicaEscalar       (matrizDoub_t       * const  mat1,
                                         double escalar){
    
    return (matrizDoub_pt)multiplicaEscalar((matriz_pt)mat1, escalar);
}

static  
matriz_pt       multiplicaEscalar       (matriz_t       * const  mat1,
                                         double escalar){
    
    for(int i = 0; i < ((matrizDoub_pt)mat1)->tamanho[LINHA]; i++){
        for(int j =0; j < ((matrizDoub_pt)mat1)->tamanho[COLUNA]; j++){
            ((matrizDoub_pt)mat1)->valor[i][j] *= escalar; 
        }
    }
    return mat1;
}

/*----------------------------------------------------------------------------*/

static  
matrizDoub_pt   Ac_soma                 (matrizDoub_t       *        mat1,
                                         matrizDoub_t const * const  mat2){
    return (matrizDoub_pt)ac_soma((matriz_pt)mat1, (matriz_pt)mat2);
}

static  
matriz_pt       ac_soma                 (matriz_t       *        mat1,
                                         matriz_t const * const  mat2){
    
    mat1 = soma(mat1, mat2, mat1);
    return mat1;
}

/*----------------------------------------------------------------------------*/

static  
matrizDoub_pt   Ac_subtracao            (matrizDoub_t       *        mat1,
                                         matrizDoub_t const * const  mat2){
    return (matrizDoub_pt)ac_subtracao((matriz_pt)mat1, (matriz_pt)mat2);
}

static  
matriz_pt       ac_subtracao            (matriz_t       *        mat1,
                                         matriz_t const * const  mat2){
    
    mat1 = subtrai(mat1, mat2, mat1);
    return mat1;
}

/*----------------------------------------------------------------------------*/

static  
matrizDoub_pt   Ac_multiplicacao        (matrizDoub_t       *        mat1,
                                         matrizDoub_t const * const  mat2){
    return (matrizDoub_pt)ac_multiplicacao((matriz_pt)mat1, (matriz_pt)mat2);
}

static  
matriz_pt       ac_multiplicacao        (matriz_t       *        mat1,
                                         matriz_t const * const  mat2){
    
    matrizDoub_pt const matriz1 = (matrizDoub_pt)mat1;
    matrizDoub_pt const matriz2 = (matrizDoub_pt)mat2;
    
    if(!ComparaDimensoes(matriz1, matriz2)){
        printf("NUMERO DE COLUNAS DA MATRIZ 1 != NUMERO LINHAS MATRIZ 2\n");
        return NULL;
    }
    
    matrizDoub_pt aux = ConstroiMatriz(matriz1->tamanho[LINHA], 
                                       matriz2->tamanho[COLUNA]);
    
    for(int i = 0; i < aux->tamanho[LINHA]; i++){
        for(int j = 0; j < aux->tamanho[COLUNA]; j++){
            
            aux->valor[i][j] = 0;
            
            for(int k = 0; k < aux->tamanho[COLUNA]; k++){   
                
                aux->valor[i][j] += matriz1->valor[i][k] * matriz2->valor[k][j];
            }
        }
    }
    mat1 = atribui((matriz_pt)aux, mat1);
    Destroi(aux);
    
    return mat1;
}

/*----------------------------------------------------------------------------*/

static  
int             Compara                 (matrizDoub_t const * const  mat1,
                                         matrizDoub_t const * const  mat2){
    
    return compara((matriz_pt)mat1, (matriz_pt)mat2);
}

static  
int             compara                 (matriz_t const * const  mat1,
                                         matriz_t const * const  mat2){
    /*
     * A função "compara" retorna 1 se o valor de cada célula for igual em
     * ambas as matrizes, retorna 0 se forem diferentes e retorna -1 se as
     * matrizes forem distintas por terem dimensões diferentes 
     */
    
    if(ComparaDimensoes((matrizDoub_pt)mat1, (matrizDoub_pt)mat2) <= 0)
        return -1;
    else{
        for(int i = 0; i < ((matrizDoub_pt)mat1)->tamanho[LINHA]; i++){
            for(int j = 0; j < ((matrizDoub_pt)mat1)->tamanho[COLUNA]; j++){
                
                if(((matrizDoub_pt)mat1)->valor[i][j] != 
                   ((matrizDoub_pt)mat2)->valor[i][j]) return 0;      
            }
        }
        return 1;
    }
}

/*----------------------------------------------------------------------------*/

static  
void            Imprime                 (matrizDoub_t const * const  mat){
    
    return imprime((matriz_pt)mat);
}

static  
void            imprime                 (matriz_t const * const  mat){
    
    matrizDoub_pt const matriz = (matrizDoub_pt)mat;
    
    for(int i = 0; i < matriz->tamanho[LINHA]; i++){
        for(int j = 0; j < matriz->tamanho[COLUNA]; j++){
            printf("%2.0lf ", matriz->valor[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/*----------------------------------------------------------------------------*/

static  
void            Destroi                 (matrizDoub_t   *        mat){
    
    return destroi((matriz_pt)mat);
}

static  
void            destroi                 (matriz_t       *        mat){
    
    if((matrizDoub_pt)mat != NULL){
        
        if(((matrizDoub_pt)mat)->valor != NULL){
            
            for(int i = 0; i < ((matrizDoub_pt)mat)->tamanho[LINHA]; i++){
                
                if(((matrizDoub_pt)mat)->valor[i] != NULL){ 
                    
                    free(((matrizDoub_pt)mat)->valor[i]);
                }
            }
            free(((matrizDoub_pt)mat)->valor);
        }
        free((matrizDoub_pt)mat);
    
    }
    
}

/*----------------------------------------------------------------------------*/

static  
matrizDoub_pt   Transposta              (matrizDoub_t       *        mat){

    if(mat->tamanho[LINHA] != mat->tamanho[COLUNA]){
	matrizDoub_pt aux = ConstroiMatriz(mat->tamanho[COLUNA], mat->tamanho[LINHA]);
	for(int i = 0; i < aux->tamanho[LINHA]; i++){
	    for(int j = 0; j < aux->tamanho[COLUNA]; j++){
	        aux->valor[i][j] = mat->valor[j][i];
	    }
	}
    mat = Atribui(aux, mat);
    Destroi(aux);
    }
    else{
	for(int i = 0; i < mat->tamanho[LINHA]; i++){
	    for(int j = 0; j < mat->tamanho[COLUNA]; j++){
	        mat->valor[i][j] = mat->valor[j][i];
	    }
	}
    }
    
    return mat;
}

static  
matrizDoub_pt   Transposta_2D           (matrizDoub_t       *        mat){
    
    mat = Transposta(mat);
    int size = mat->tamanho[COLUNA];
    double temp = 0;
    
    for(int i = 0; i < mat->tamanho[LINHA]; i++){
        for(int j = 0; j < size / 2; j++){
            temp = mat->valor[i][j];
            mat->valor[i][j] = mat->valor[i][size-1-j];
            mat->valor[i][size-1-j] = temp;
        }
    }//Rotação 90° em sentido horário
    
    return mat;
}

static
matrizDoub_pt   Reverse_Horizontal      (matrizDoub_t       * const  mat){
    
    double * aux;
    int i = 0, j = mat->tamanho[LINHA] - 1;
    
    while(i < j){
        aux = mat->valor[i];
        mat->valor[i] = mat->valor[j];
        mat->valor[j] = aux;
        i++;
        j--;
    }
    return mat;
}

static
matrizDoub_pt   Reverse_Vertical        (matrizDoub_t       * const  mat){
    
    int size = mat->tamanho[COLUNA];
    double temp;
    
    for(int i = 0; i < mat->tamanho[LINHA]; i++){
        for(int j = 0; j < size/2; j++){
            temp = mat->valor[i][j];
            mat->valor[i][j] = mat->valor[i][size-1-j];
            mat->valor[i][size-1-j] = temp;
        }
    }
    
    return mat;
}

static  
matrizDoub_pt   DefineLinhas            (matrizDoub_t    *         mat,
                                         unsigned int linha){
    
    mat->tamanho[LINHA] = linha;
    mat->valor = (double **)realloc(mat->valor, linha * sizeof(double *));
    if(mat->valor == NULL){
        printf("MEMÓRIA NÃO ALOCADA EM DefineLinhas\n");
        exit(1);
    }
        
    mat = DefineColunas(mat, mat->tamanho[COLUNA]);
    
    return mat;
}

static
matrizDoub_pt   DefineColunas           (matrizDoub_t    *         mat,
                                         unsigned int coluna){
    
    mat->tamanho[COLUNA] = coluna;
    for(int i = 0; i < mat->tamanho[LINHA]; i++){
        mat->valor[i] = (double *)realloc(mat->valor[i], coluna * sizeof(double));
        if(mat->valor[i] == NULL){
            printf("ERRO AO ALOCAR MEMÓRIA EM 'DefineColunas'");
            exit(1);
        }
    } 
    return mat;
}

static  
matrizDoub_pt   Redimensiona            (matrizDoub_t    *         mat,
                                         unsigned int linha,
                                         unsigned int coluna){
    
    mat->tamanho[LINHA] = linha; //apenas para manter a coerencia da implementação
    mat->tamanho[COLUNA] = coluna;
    mat = DefineLinhas(mat, linha);
    if(mat == NULL){
        printf("ERRO AO UTILIZAR 'Redimensiona'");
        exit(1);
    }
    return mat;
}

static  
matrizDoub_pt   AdicionaLinha           (matrizDoub_t       * const  mat){
    
    mat->tamanho[LINHA] += 1;
    mat->valor = (double **)realloc(mat->valor, mat->tamanho[LINHA] * 
                                                sizeof(double *));
    if(mat->valor == NULL){
        printf("MEMÓRIA NÃO ALOCADA EM 'AdicionaLinhas'1\n");
        exit(1);
    }
    
    mat->valor[mat->tamanho[LINHA]-1] = (double *)realloc(
                                        mat->valor[mat->tamanho[LINHA]-1],
                                        mat->tamanho[COLUNA] * sizeof(double));
    if(mat->valor[mat->tamanho[LINHA] - 1] == NULL){
        printf("MEMÓRIA NÃO ALOCADA EM 'AdicionaLinhas'2\n");
        exit(1);
    }
    
    return mat;
}

static  
matrizDoub_pt   AdicionaColuna          (matrizDoub_t       * const  mat){
    
    mat->tamanho[COLUNA] += 1;
    for(int i = 0; i < mat->tamanho[LINHA]; i++){
        mat->valor[i] = (double *)realloc(mat->valor[i], 
                                          mat->tamanho[COLUNA] * sizeof(double));
        if(mat->valor[i] == NULL){
            printf("ERRO AO ALOCAR MEMÓRIA EM 'AdicionaColunas'");
            exit(1);
        }
    }
    return mat;
}

static  
int             ComparaDimensoes        (matrizDoub_t const * const  mat1,
                                         matrizDoub_t const * const  mat2){
    /*
     * A função "ComparaDimensões" retorna 1 se as matrizes tiverem o mesmo 
     * tamanho, retorna -1 se o número de colunas da primeira for igual ao
     * número de linhas da segunda, ou seja, podem ser multiplicadas, e re-
     * torna 0 se forem distintas de qualquer outra forma
     */
    
    if(mat1->tamanho[LINHA]  == mat2->tamanho[LINHA] &&
       mat1->tamanho[COLUNA] == mat2->tamanho[COLUNA])
        return 1;
    else if(mat1->tamanho[COLUNA]  == mat2->tamanho[LINHA])
        return -1;
    else 
        return 0;
    
}

static  
int             ObtemLinhas             (matrizDoub_t const *   const mat){
    return mat->tamanho[LINHA];
}

static  
int             ObtemColunas            (matrizDoub_t const *   const mat){
    return mat->tamanho[COLUNA];
}
