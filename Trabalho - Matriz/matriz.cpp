#include <iostream>
#include "matriz.h"

using namespace std;

// Função para desalocar espaço.
void Matrix::desalocaEspaco(int col){
    for (int i = 0; i < col; i++){
        delete[] matriz[i];
    }
    delete[] matriz;
}

// Função para alocar espaço.

void Matrix::alocarEspacoMatriz(int lin, int col) { //sugiro que essa função seja void, a própria criação do objeto já é um teste para essa função
    // ALOCANDO A MATRIZ.
    matriz = new int* [col];
    for (int i=0; i < col; i++) {
        matriz[i] = new int[lin];
    }
}

// Construtor.
Matrix::Matrix(int lin, int col) {

    colunas=col;
    linhas=lin;
    
    alocarEspacoMatriz(lin, col);

}

// Construtor de cópia.
// Recebe o endereço de um outro objeto do tipo Matrix.
Matrix::Matrix(Matrix &outroObjeto){

    colunas = outroObjeto.colunas;
    linhas = outroObjeto.linhas;

    alocarEspacoMatriz(linhas, colunas);

    for (int i=0; i < linhas; i++){
        for (int j=0; j < colunas; j++){
            matriz[i][j] = outroObjeto[i][j];
        }
    }
}

// Destrutor. ~
Matrix::~Matrix(){
    desalocaEspaco(colunas); //função criada chamada no destrutor
}

Matrix& Matrix::operator=(Matrix &obj){

    
    desalocaEspaco(colunas); //Acho viável criar uma função para liberar a memória antes de alocar novamente, voce pode chamá-la no destrutor também
    colunas = obj.colunas;
    linhas = obj.linhas;
    alocarEspacoMatriz(linhas, colunas);

    for (int i=0; i < colunas; i++){
        for (int j=0; j < linhas; j++){
            matriz[i][j] = obj[i][j];
        }
    }

    return *this;
}

bool Matrix::operator==(Matrix &obj){ //permite verificar se uma matriz e igual a outra
	
	if ((linhas != obj.linhas) || (colunas != obj.colunas)){	
		return false;
	}else{
		for(int i = 0; i < linhas; i++){
			for(int j = 0; j < colunas; j++){
				if ((matriz[i][j] != obj[i][j])){
					return false;
				}
			}
		}
	}	
	return true;
}

int Matrix::getLinhas(){
    return linhas;
}

int Matrix::getColunas(){
    return colunas;
}

//Exclui as funções setLinhas e setColunas, pois não estavam sendo utilizadas.

int* Matrix::operator[] (int x) { //permite acesso direto aos valores da matriz
    return matriz[x];

}


/*/ O overload dos colchetes que estava sendo utilizado estava dando problema em obter o número de linhas e colunas de alguns objetos no momento
    em que era usado para atribuir valores, em alguns estava acessando o número de linhas/colunas incorretamente, dando problema na memória 
    por este motivo troquei a sintaxe dele para o de cima.                                              
}/*/

