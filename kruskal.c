#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define qVert 6
#define qAresta 20
#define nullAresta -99

int mAdj[qVert][qVert];

struct Aresta{
	int vEmergente;
	int vIncidente;
	float peso;
}aresta[qAresta], agm[qVert-1];

//funções
void inicializar();
void inicializarAresta();
void imprimirListaAresta();
void imprimirMatriz();
void transformarArestaEmMatriz();
void transformarMatrizEmAresta();
void bicolor();
void coloracao();
void removeDuplicatasDeAresta();
int verificarSeEhGrafo();
void imprimirAgm();
int verificarCiclos(int vE, int vI);
void buscarMenoresPesos();

void main(void){	
	inicializarAresta();
	imprimirListaAresta();
	transformarArestaEmMatriz();
	imprimirMatriz();
	removeDuplicatasDeAresta();	
	imprimirMatriz();
	imprimirListaAresta();
	buscarMenoresPesos();
	imprimirAgm();
}

void inicializarAresta(){
	setlocale(LC_ALL,"Portuguese");
	
	int i;
	for(i=0; i < qVert -1; i++){
		agm[i].vEmergente = nullAresta;
		agm[i].vIncidente = nullAresta;
		agm[i].peso = nullAresta;
	}
	
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

void imprimirListaAresta(){
	int i;

	for(i = 0; i < qAresta; i++){
		printf("\t%d  ==>  %d\t%.f\n",aresta[i].vEmergente,aresta[i].vIncidente,aresta[i].peso);
	}
}

void transformarArestaEmMatriz(){
	// a partir da lista de aresta gera-se a matriz de incidencia
	int i, j;
	for(i = 0; i < qVert;i++)
		for(j = 0; j < qVert;j++)
			mAdj[i][j] = nullAresta;

	for(i = 0; i < qAresta;i++){
		mAdj[aresta[i].vEmergente][aresta[i].vIncidente] = aresta[i].peso;
	}
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

int verificarSeEhGrafo(){
	int ehGrafo = 0;
	int i, j;
	for(i = 0; i < qVert; i++){
		for(j = 0; j < qVert; j++){
			if(mAdj[i][j] == mAdj[j][i]) ehGrafo = 1;
			else{
				ehGrafo = 0;
				i = qVert;
				break;
			}
		}
	}
	return ehGrafo;
}

void removeDuplicatasDeAresta(){
	if(verificarSeEhGrafo()){
		printf("É grafo");		
		int i, j;
		for(i = 0;i < qVert;i++){
			for(j = 0; j < qVert;j++){
				if(j < i) mAdj[i][j] = nullAresta;
			}
		}		
		for(i = 0;i < qAresta; i++){
			aresta[i].vEmergente = nullAresta;
			aresta[i].vIncidente = nullAresta;
			aresta[i].peso = nullAresta;
		} 		
		transformarMatrizEmAresta();		
	}else{
		printf("É Digrafo");
	}
}

void transformarMatrizEmAresta(){
	// a partir da matriz de incidencia gera-se a lista de aresta
	int i, j, k = 0;
	for(i = 0; i < qVert;i++){
		for(j = 0; j < qVert;j++){
			if(mAdj[i][j] != nullAresta){
				aresta[k].vEmergente = i;
				aresta[k].vIncidente = j;
				aresta[k].peso = mAdj[i][j];
				k++;
			}
		}
	}
}

void buscarMenoresPesos(){
	int i,k, posicao, menorPeso;
	for(k = 0; k < qVert-1;k++){
		menorPeso = 99999;				
		for(i = 0; i < qAresta; i++){
			if(aresta[i].peso < menorPeso && 
					aresta[i].vEmergente != nullAresta){
				posicao = i;
				menorPeso = aresta[i].peso; 
			}	
		}
		if(verificarCiclos(aresta[posicao].vEmergente, aresta[posicao].vIncidente)){
			agm[k].vEmergente = aresta[posicao].vEmergente;
			agm[k].vIncidente = aresta[posicao].vIncidente;
			agm[k].peso = aresta[posicao].peso;
		}else{
			k--;
		}
		aresta[posicao].vEmergente = nullAresta;
		aresta[posicao].vIncidente = nullAresta;
		aresta[posicao].peso = nullAresta;
	}
}

void imprimirAgm(){
	int i;
	
	for(i = 0;i < qVert-1; i++){
		printf("\t%d <==> %d\t%.f\n",agm[i].vEmergente,agm[i].vIncidente,
		agm[i].peso);
	}
}

int verificarCiclos(int vE, int vI){
	int nTemCiclos = 1, i, j;
	for(i = 0;i < qVert-1; i++){
		if(agm[i].vEmergente == vE){
			printf("\nEncontrou No Emergente");
			vE= agm[i].vIncidente;
			agm[i].vIncidente = nullAresta;
			agm[i].vEmergente = nullAresta;
		}else{
			if(agm[i].vIncidente == vE){
				printf("\nEncontrou No Incidente");
				vE= agm[i].vEmergente;
				agm[i].vIncidente = nullAresta;
				agm[i].vEmergente = nullAresta;				
			}
		}
		// incompleto falta demais verificações do caminho
	}	
	return nTemCiclos;
}
