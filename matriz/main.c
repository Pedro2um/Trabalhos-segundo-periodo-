/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: eduarda
 *
 * Created on 13 de março de 2022, 08:39
 */

#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include "matrizDouble.h"

/*
 *  
    Ciencia da Computacao
    Pedro Igor Gomes de Morais.
    Eduarda Pylro Magesk.
    
 */

// Prezado Saulo, por fins práticos 
// não mostraremos todas as funções.
// O programa não contêm apenas estas funções,
// estão aqui demonstradas as funções obrigatórias e
// extras que você sugeriu.
// Espero que goste do trabalho, pois foi feito com bastante dedicaçao.
// Desejamos melhoras para a saúde do seu pai.

int main(int argc, char** argv) {
    
	matrizDoub_pt mat1 = ConstroiMatriz(2, 2);
	mat1->Metodo->redimensiona(mat1,3,3);

	int cnt = 1;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			mat1->valor[i][j] = cnt++;
		}
	}

	printf("MAT1:\n");
	if(mat1 != NULL) mat1->Metodo->imprime(mat1);
	printf("\n");
	
	printf("MAT2:\n");
	matrizDoub_pt mat2 = ConstroiMatrizNula(3, 3);
	if(mat2 != NULL) mat2->Metodo->imprime(mat2);
	printf("\n");
	
	printf("MAT3:\n");
	matrizDoub_pt mat3 = ConstroiMatrizUnitaria(3, 3);
	if(mat3 != NULL) mat3->Metodo->imprime(mat3);
	printf("\n");
	
	printf("MAT4:\n");
	matrizDoub_pt mat4 = ConstroiMatrizIdentidade(3, 3);
	if(mat4 != NULL) mat4->Metodo->imprime(mat4);
	printf("\n");
	
	printf("MAT1 * MAT3 E GUARDA EM MAT2:\n");
	mat1 = mat1->Metodo->soma(mat1, mat3, mat2);
	if(mat2 != NULL) mat2->Metodo->imprime(mat2);
	printf("\n");
	
	double x = 18.9;
	printf("MAT1 * ESCALAR %f, E ATRIBUI MAT1 A MAT2:\n", x);
	mat1 = mat1->Metodo->multiplicaEscalar(mat1, x);
	if(mat2 != NULL) mat2->Metodo->imprime(mat2);
	printf("\n");

	printf("MAT1 * MAT4(identidade) %f, E GUARDA EM MAT2:\n", x);
	mat2 = mat1->Metodo->multiplica(mat1, mat4, mat2);
	if(mat2 != NULL) mat2->Metodo->imprime(mat1);
	printf("\n");

	printf("ADICIONA LINHA A MAT1:\n");
	mat1 = mat1->Metodo->adicionaLinha(mat1);
	if(mat1 != NULL) mat1->Metodo->imprime(mat1);
	printf("\n");

	printf("ADICIONA COLUNA A MAT1:\n");
	if(mat1 != NULL) mat1 = mat1->Metodo->adicionaColuna(mat1);
	mat1->Metodo->imprime(mat1);
	printf("\n");
	     
	printf("TRANSPOSTA DA MAT1:\n");
	mat1 = mat1->Metodo->transposta(mat1);
	if(mat1 != NULL) mat1->Metodo->imprime(mat1);
	printf("\n");
	
	printf("TRANSPOSTA DA MAT1 EM RELACAO A SEGUNDA DIAGONAL(apos ter feito a transposta):\n");
	mat1 = mat1->Metodo->transposta_2D(mat1);
	if(mat1 != NULL) mat1->Metodo->imprime(mat1);
	printf("\n");
	
	printf("INVERTE ORDEM DAS LINHAS DA MAT1:\n");
	mat1 = mat1->Metodo->reverse_horizontal(mat1);
	if(mat1 != NULL) mat1->Metodo->imprime(mat1);
	printf("\n");
	
	printf("INVERTE ORDEM DAS COLUNAS DA MAT1:\n");
	mat1 = mat1->Metodo->reverse_vertical(mat1);
	if(mat1 != NULL) mat1->Metodo->imprime(mat1);
	printf("\n");
	
	
	if(mat1 != NULL) mat1->Metodo->destroi(mat1);
	if(mat2 != NULL) mat2->Metodo->destroi(mat2);
	if(mat3 != NULL) mat3->Metodo->destroi(mat3);
	if(mat4 != NULL) mat4->Metodo->destroi(mat4);
	return (EXIT_SUCCESS);
}

