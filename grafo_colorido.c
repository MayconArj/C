#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define qVert 6
#define qAresta 18

int mAdj[qVert][qVert];

struct Aresta{
	int vEmergente;
	int vIncidente;
}aresta[qAresta];

// Funções
void inicializar();
void inicializarListaAresta();
void imprimirMatriz();
void imprimirListaAresta();
void transformarArestaEmMatriz();
void transformarMatrizEmAresta();
void coloracao();


// Main
void main(void){
	inicializar();
	imprimirMatriz();
	printf("\n");
	transformarMatrizEmAresta();
	imprimirListaAresta();
	printf("\n");
	coloracao();
	imprimirMatriz();
}

void inicializar(){
	setlocale(LC_ALL, "Portuguese");
	
	int i, j;
	for(i = 0; i < qVert;i++)
		for(j = 0; j < qVert;j++)
	
	//vertice 1
	mAdj[0][1] = 1; 
	mAdj[0][3] = 1; 
	
	//vertice 2
	mAdj[1][0] = 1;
	mAdj[1][2] = 1; 
	mAdj[1][5] = 1; 
	
	//vertice 3
	mAdj[2][1] = 1;
	mAdj[2][3] = 1; 
	mAdj[2][4] = 1; 
	mAdj[2][5] = 1; 
	
	//vertice 4
	mAdj[3][0] = 1;
	mAdj[3][2] = 1; 
	mAdj[3][4] = 1; 
	
	//vertice 5
	mAdj[4][2] = 1;
	mAdj[4][3] = 1; 
	mAdj[4][5] = 1; 
	
	//vertice 6
	mAdj[5][1] = 1;
	mAdj[5][2] = 1; 
	mAdj[5][4] = 1;
}


void inicializarAresta(){
	setlocale(LC_ALL,"Portuguese");
	
	aresta[0].vEmergente = 1;
	aresta[0].vIncidente = 2;
	
	aresta[1].vEmergente = 1;
	aresta[1].vIncidente = 3;
	
	aresta[2].vEmergente = 1;
	aresta[2].vIncidente = 4;
	
	aresta[3].vEmergente = 2;
	aresta[3].vIncidente = 1;
	
	aresta[4].vEmergente = 2;
	aresta[4].vIncidente = 4;
	
	aresta[5].vEmergente = 3;
	aresta[5].vIncidente = 1;
	
	aresta[6].vEmergente = 3;
	aresta[6].vIncidente = 4;
	
	aresta[7].vEmergente = 4;
	aresta[7].vIncidente = 1;
	
	aresta[8].vEmergente = 4;
	aresta[8].vIncidente = 2;
	
	aresta[9].vEmergente = 4;
	aresta[9].vIncidente = 3;
}

void imprimirMatriz(){
	int i, j;
	
	for(i=0; i<qVert; i++){
		for(j=0; j<qVert; j++){
			printf("%d\t", mAdj[i][j]);
		}
		printf("\n");
	}
}

void imprimirListaAresta(){
	int i;
	
	for(i=0; i<qAresta; i++){
		printf("\t%d ==> %d\n", aresta[i].vEmergente, aresta[i].vIncidente);
	}
}


void transformarArestaEmMatriz(){
	// a partir da lista de aresta gera-se a matriz de incidencia
	int i;
	for(i = 0; i < qAresta;i++){
		mAdj[aresta[i].vEmergente - 1][aresta[i].vIncidente -1] = 1;
	}
}

void transformarMatrizEmAresta(){
	// a partir da matriz de incidencia gera-se a lista de aresta
	int i, j, k = 0;
	for(i = 0; i < qVert;i++){
		for(j = 0; j < qVert;j++){
			if(mAdj[i][j] == 1){
				aresta[k].vEmergente = i+1;
				aresta[k].vIncidente = j+1;
				k++;
			}
		}
	}
}

void coloracao(){
	int i, j, k;
	int cor[qVert];
	
	for(i = 0; i < qVert; i++)
		cor[i] = 100+i;	
	
	printf("\n");
	
	for(i = 0;i < qVert; i++){
		k = 0;
		if(mAdj[i][i] == 0) mAdj[i][i] = cor[k];
		for(j = 0;j < qVert; j++){
			if((mAdj[i][j] == 1)&&(mAdj[j][j] != 0)){
				if(mAdj[j][j] == mAdj[i][i]){
					k = k + 1;
					mAdj[i][i] = cor[k];
					j = 0;
				}
			}
		}
	}
}
