#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define V 5
#define qAresta 20
#define nullAresta 0

// como representar em lista de arestas?
struct Aresta{
	int vEmergente;
	int vIncidente;
	float peso;
}aresta[qAresta];

struct Caminho{
	char texto[8*V];
}caminho[V];





float vetorCusto[V];

int mAdj[V][V];

//funções
void inicializar();
void inicializarAresta();
void imprimirListaAresta();
void imprimirMatriz();
void transformarMatrizEmAresta();
void imprimirCaminhos();
void caixeiro(int vInicio);
void combinacoes(int vetor[], int n, int combinacao[], 
		int posicao, int k, int utilizados[]);
void calcularPesos();
void buscarMenorRota();
void imprimirCaixeiro();


void main(void){	

	inicializar();
	imprimirMatriz();
	transformarMatrizEmAresta();
	imprimirListaAresta();
	caixeiro(3);
	imprimirCaixeiro();
	buscarMenorRota();	


}

// criar a função de inicialização
void inicializar(){
	setlocale(LC_ALL,"Portuguese");
	
	int i, j;
	for(i = 0; i < V; i++)
		vetorCusto[i] = 8015056586684760100;

	for(i = 0; i < V;i++)
		for(j = 0; j < V;j++)
			mAdj[i][j] = nullAresta;
			
	//vertice 0
	mAdj[0][1] = 2; 
	mAdj[0][2] = 1;
	mAdj[0][3] = 12;
	mAdj[0][4] = 3;
		
	//vertice 1
	mAdj[1][0] = 2; 
	mAdj[1][2] = 3;
	mAdj[1][3] = 6;
	mAdj[1][4] = 4;
		
	//vertice 2
	mAdj[2][0] = 1; 
	mAdj[2][1] = 3;
	mAdj[2][3] = 1;
	mAdj[2][4] = 5;
	
	//vertice 3
	mAdj[3][0] = 12; 
	mAdj[3][1] = 6;
	mAdj[3][2] = 1;
	mAdj[3][4] = 15;
	
	//vertice 4
	mAdj[4][0] = 3; 
	mAdj[4][1] = 4;
	mAdj[4][2] = 5;
	mAdj[4][3] = 15;
}
// criar a função de impressão da matriz
void imprimirMatriz(){
	int i,j;
	for(i=0;i<30;i++) printf("=");
	printf("\n           Matriz          \n");
	for(i=0;i<30;i++) printf("-");
	printf("\n");
	for(i=0;i < V;i++){
		for(j=0;j< V;j++){
			printf("%d\t",mAdj[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<30;i++) printf("=");
	printf("\n");
}

void imprimirListaAresta(){
	int i;
	for(i=0;i<30;i++) printf("=");
	printf("\n     Lista de aresta          \n");
	for(i=0;i<30;i++) printf("-");
	printf("\n");
	for(i = 0; i < qAresta; i++){
		printf("\t%d  ==>  %d\t%.f\n",aresta[i].vEmergente,aresta[i].vIncidente,aresta[i].peso);
	}
	for(i=0;i<30;i++) printf("=");
	printf("\n");
}

void transformarMatrizEmAresta(){
	// a partir da matriz de incidencia gera-se a lista de aresta
	int i, j, k = 0;
	for(i = 0; i < V;i++){
		for(j = 0; j < V;j++){
			if(mAdj[i][j] != nullAresta){
				aresta[k].vEmergente = i;
				aresta[k].vIncidente = j;
				aresta[k].peso = mAdj[i][j];
				k++;
			}
		}
	}
}

void imprimirCaminhos(){
	int i, j;
	printf("\n\n--------------- Vetor Caminhos com Custo ------------------\n");
	for(i=0;i < V;i++){
		printf("Custo = %.f\t%s\n",vetorCusto[i],caminho[i].texto);
	}
	printf("\n--------------------------------------------------------\n");
}

void caixeiro(int vInicio){

}

void combinacoes(int vetor[], int n, int combinacao[], 
		int posicao, int k, int utilizados[]) {
	
		
}

void calcularPesos(){
	
}

void buscarMenorRota(){
	
}

void imprimirCaixeiro(){
	printf("\n\n======================= Caixeiro Viajante =========================\n");
	
	
	
	
	
	
	printf("\n\n===================================================================\n");	
}

