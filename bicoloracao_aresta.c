#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

# define qVert 4
# define qAresta 10

int mAdj[qVert][qVert];

struct Aresta{
	int vEmergente;
	int vIncidente;
	//float peso;
}aresta[qAresta];

// Funções
void inicializarAresta();
//void imprimirListaArestas();
void bicolor();

// Main
void main(void){
	inicializarAresta();
//	imprimirListaArestas();
	bicolor();
}

void inicializarAresta(){
	setlocale(LC_ALL,"Portuguese");
	
	//vertice 1
	aresta[0].vEmergente = 1;
	aresta[0].vIncidente = 2;
	
	aresta[1].vEmergente = 1;
	aresta[1].vIncidente = 3;
	
	aresta[2].vEmergente = 1;
	aresta[2].vIncidente = 4;

	//vertice 2
	aresta[3].vEmergente = 2;
	aresta[3].vIncidente = 1;
	
	aresta[4].vEmergente = 2;
	aresta[4].vIncidente = 4;
	
	//vertice 3
	aresta[5].vEmergente = 3;
	aresta[5].vIncidente = 1;
	
	aresta[6].vEmergente = 3;
	aresta[6].vIncidente = 4;
	
	//vertice 4
	aresta[7].vEmergente = 4;
	aresta[7].vIncidente = 1;
	
	aresta[8].vEmergente = 4;
	aresta[8].vIncidente = 2;
	
	aresta[9].vEmergente = 4;
	aresta[9].vIncidente = 3;	
}

void imprimirListaAresta(){
	int i;
	
	for(i=0; i<qAresta; i++){
		printf("\t%d ==> %d\n", aresta[i].vEmergente, aresta[i].vIncidente);
	}
}

void bicolor(){
	int i, j;
	int cor[2] = {98,99}; // Defino 2 cores
	
	for(i=0; i<qVert; i++){
		int k = 0;
		mAdj[i][i] = cor[k];
		for(j=0; j<qVert; j++){
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
	imprimirListaAresta();
	// ciar a função para verificar se é ciclo ímpar
}
