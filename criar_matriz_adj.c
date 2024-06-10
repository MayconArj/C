#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Quantidade de vertices
#define Vert 4

int mAdj[Vert][Vert];

int main(void){
	setlocale(LC_ALL, "Portuguese");
	
	// Vertice 1
	mAdj[0][0] = 0;
	mAdj[0][1] = 1;
	mAdj[0][2] = 1;
	mAdj[0][3] = 1;
	
	// Vertice 2
	mAdj[1][0] = 1;
	mAdj[1][1] = 0;
	mAdj[1][2] = 0;
	mAdj[1][3] = 1;
	
	// Vertice 3
	mAdj[2][0] = 1;
	mAdj[2][1] = 0;
	mAdj[2][2] = 0;
	mAdj[2][3] = 1;
	
	// Vertice 4
	mAdj[3][0] = 1;
	mAdj[3][1] = 1;
	mAdj[3][2] = 1;
	mAdj[3][3] = 0;
	
	int i,j;
	
	for(i=0; i<Vert; i++){
		for(j=0; j<Vert; j++){
			printf("%d\t", mAdj[i][j]);
		}
		printf("\n");
	}
}
