#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define Vert 4

int mAdj[Vert][Vert];

// Funções
void inicializar();
void imprimirMatriz();
void bicolor();


void main(void){
	inicializar();
//	imprimirMatriz();
	bicolor();
}

void inicializar(){
	setlocale(LC_ALL, "Portuguese");
	
	//vertice 1
	mAdj[0][0] = 0;
	mAdj[0][1] = 1; 
	mAdj[0][2] = 1; 
	mAdj[0][3] = 0; 
	
	//vertice 2
	mAdj[1][0] = 1;
	mAdj[1][1] = 0; 
	mAdj[1][2] = 0; 
	mAdj[1][3] = 1; 
	
	//vertice 3
	mAdj[2][0] = 1;
	mAdj[2][1] = 0; 
	mAdj[2][2] = 0; 
	mAdj[2][3] = 1; 
	
	//vertice 4
	mAdj[3][0] = 0;
	mAdj[3][1] = 1; 
	mAdj[3][2] = 1; 
	mAdj[3][3] = 0; 
}

void imprimirMatriz(){
	int i, j;
	for(i=0; i<Vert; i++){
		for(j=0; j<Vert; j++){
			printf("%d\t", mAdj[i][j]);
		}
		printf("\n");
	}
}

void bicolor(){
	int i, j;
	int cor[2] = {98,99}; // Defino 2 cores
	
	for(i=0; i<Vert; i++){
		int k = 0;
		mAdj[i][i] = cor[k];
		for(j=0; j<Vert; j++){
			if(mAdj[i][j] == 1){
				if(mAdj[j][j] != 0){
					if(mAdj[j][j] == mAdj[i][i]){
						k++;
						mAdj[i][i] = cor[k];
					}
				}
			}
		}
	}
	imprimirMatriz();
	// ciar a função para verificar se é ciclo ímpar
}
