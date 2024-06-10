#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

#define V 7
#define qAresta 20
#define nullAresta -99

// como representar em lista de arestas?
struct Aresta{
	int vEmergente;
	int vIncidente;
	float peso;
}aresta[qAresta];

struct Caminho{
	char texto[8*V];
}caminho[V];

int vetorInundacao[V];

float vetorCusto[V];

int mAdj[V][V];

//funções
void inicializar();
void inicializarAresta();
void imprimirListaAresta();
void imprimirMatriz();
void transformarArestaEmMatriz();
void transformarMatrizEmAresta();
void imprimirVetorCusto();
void djikstra(int origem);
void inserirVerticeCam(int verticeOrigem, int verticeDestino);
void imprimirCaminhos();

void imprimirInundacao();
bool estaNoVetor(int vertice);
void inundacao(int vertice);


void main(void){
	inicializar();
	imprimirMatriz();
	transformarMatrizEmAresta();
	imprimirListaAresta();
	imprimirVetorCusto();
	djikstra(4);  // <<<< vertice 0 POSSO TROCAR PARA QUALQUER UM
	imprimirVetorCusto();
	imprimirCaminhos();	
	int i,j;
	for(i=0;i<V;i++){
		inundacao(i);
		printf("\nPara o vertice %d",i);
		imprimirInundacao();				
	}
}

// criar a função de inicialização
void inicializar(){
	setlocale(LC_ALL,"Portuguese");
	
	int i, j;
	for(i = 0; i < V; i++){
		vetorCusto[i] = 8015056586684760100;
	}
	for(i = 0; i < V;i++)
		for(j = 0; j < V;j++)
			mAdj[i][j] = nullAresta;
			
	//vertice 0
	mAdj[0][1] = 1; 
	mAdj[0][2] = 3;
	mAdj[0][3] = 6;
		
	//vertice 1
	mAdj[1][0] = 1;
	mAdj[1][3] = 4; 
	mAdj[1][5] = 9; 
		
	//vertice 2
	mAdj[2][0] = 3;
	mAdj[2][5] = 2; 
	
	//vertice 3
	mAdj[3][0] = 6;
	mAdj[3][1] = 4;
	mAdj[3][4] = 3;
	mAdj[3][5] = 2;
	
	//vertice 4
	mAdj[4][3] = 3;
	mAdj[4][5] = 4; 
	
	//vertice 5
	mAdj[5][1] = 9;
	mAdj[5][2] = 2;
	mAdj[5][3] = 2; 
	mAdj[5][4] = 4;
	mAdj[5][6] = 11;
	
	//vertice 6
	mAdj[6][5] = 11; 	

}

void inicializarAresta(){
	setlocale(LC_ALL,"Portuguese");

	// vertice 0
	aresta[0].vEmergente = 0;
	aresta[0].vIncidente = 1;
	aresta[0].peso = 6;
	
	aresta[1].vEmergente = 0;
	aresta[1].vIncidente = 2;
	aresta[1].peso = 1;
	
	aresta[2].vEmergente = 0;
	aresta[2].vIncidente = 3;
	aresta[2].peso = 5;
	
	//vertice 1
	aresta[3].vEmergente = 1;
	aresta[3].vIncidente = 0;
	aresta[3].peso = 6;
	
	aresta[4].vEmergente = 1;
	aresta[4].vIncidente = 2;
	aresta[4].peso = 2;
	
	aresta[5].vEmergente = 1;
	aresta[5].vIncidente = 4;
	aresta[5].peso = 5;
	
	// vertice 2
	aresta[6].vEmergente = 2;
	aresta[6].vIncidente = 0;
	aresta[6].peso = 1;
		
	aresta[7].vEmergente = 2;
	aresta[7].vIncidente = 1;
	aresta[7].peso = 2;
	
	aresta[8].vEmergente = 2;
	aresta[8].vIncidente = 3;
	aresta[8].peso = 2;
	
	aresta[9].vEmergente = 2;
	aresta[9].vIncidente = 4;
	aresta[9].peso = 6;
	
	aresta[10].vEmergente = 2;
	aresta[10].vIncidente = 5;
	aresta[10].peso = 4;
	
	//vertice 3
	aresta[11].vEmergente = 3;
	aresta[11].vIncidente = 0;
	aresta[11].peso = 5;
	
	aresta[12].vEmergente = 3;
	aresta[12].vIncidente = 2;
	aresta[12].peso = 2;
	
	aresta[13].vEmergente = 3;
	aresta[13].vIncidente = 5;
	aresta[13].peso = 4;
	
	// vertice 4
	aresta[14].vEmergente = 4;
	aresta[14].vIncidente = 1;
	aresta[14].peso = 5;
	
	aresta[15].vEmergente = 4;
	aresta[15].vIncidente = 2;
	aresta[15].peso = 6;
	
	aresta[16].vEmergente = 4;
	aresta[16].vIncidente = 5;
	aresta[16].peso = 3;
	
	//vertice 5
	aresta[17].vEmergente = 5;
	aresta[17].vIncidente = 2;
	aresta[17].peso = 4;
	
	aresta[18].vEmergente = 5;
	aresta[18].vIncidente = 3;
	aresta[18].peso = 4;
	
	aresta[19].vEmergente = 5;
	aresta[19].vIncidente = 4;
	aresta[19].peso = 3;
	 		
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

void transformarArestaEmMatriz(){
	// a partir da lista de aresta gera-se a matriz de incidencia
	int i, j;
	for(i = 0; i < V;i++)
		for(j = 0; j < V;j++)
			mAdj[i][j] = nullAresta;

	for(i = 0; i < qAresta;i++){
		mAdj[aresta[i].vEmergente][aresta[i].vIncidente] = aresta[i].peso;
	}
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

void djikstra(int origem){
	
	char aux[3];  	//o grafo tem qtd max de vértice = 999
	itoa(origem,aux,10); //itoa(numero int, vetor char, radix 10 para decimal)
	strcpy(caminho[origem].texto,aux);
	
	vetorCusto[origem] = 0;
	int i, j, k;
	for(k = 0; k < qAresta; k++)
	for(i = 0; i < V; i++)
		for(j = 0; j < V; j++)
			if(mAdj[i][j] != nullAresta){
				float distOrigem = vetorCusto[i] + mAdj[i][j];
				if(distOrigem < vetorCusto[j]){
					vetorCusto[j] = distOrigem;
					inserirVerticeCam(i,j);
				}
			}		
}

void imprimirVetorCusto(){
	int i;
	printf("\n\n--------- Vetor Custos --------\n");
	for(i = 0; i < V;i++){
		printf("%.f\n",vetorCusto[i]);
	}
	printf("\n\n--------------------------\n");
}

void inserirVerticeCam(int verticeOrigem, int verticeDestino){	
	char aux[3];  					//o grafo tem qtd max de vértice = 999
	itoa(verticeDestino,aux,10); 	//itoa(numero int, vetor char, radix 10 para decimal)
	strcpy(caminho[verticeDestino].texto, caminho[verticeOrigem].texto);
	strcat(caminho[verticeDestino].texto," -> ");
	strcat(caminho[verticeDestino].texto,aux);	
}

void imprimirCaminhos(){
	int i, j;
	printf("\n\n--------------- Vetor Caminhos com Custo ------------------\n");
	for(i=0;i < V;i++){
		printf("Custo = %.f\t%s\n",vetorCusto[i],caminho[i].texto);
	}
	printf("\n--------------------------------------------------------\n");
}

void inundacao(int vertice){
	int i, j, k = 0;
	for(i = 0; i < V;i++) vetorInundacao[i] = nullAresta;
	vetorInundacao[k] = vertice;
	k++;
	for(i = 0; i < V && k < V;i++){
		for(j = 0;j < V;j++){
			if(mAdj[vetorInundacao[i]][j] != nullAresta){
				if(!estaNoVetor(j)){
					vetorInundacao[k] = j;
					k++;
				}
			}
		}
	}
}

bool estaNoVetor(int vertice){
	int i;
	bool esta = false;
	for(i = 0; i < V; i++){
		if(vetorInundacao[i] == vertice){
			esta = true;
			break;
		} 
	}
	return esta;
}

void imprimirInundacao(){
	printf("\n-----------Vetor Inundacao--------------\n");
	int i;
	for(i=0;i < V;i++) printf("%d,  ",vetorInundacao[i]);	
	printf("\n----------------------------------------\n");
}
