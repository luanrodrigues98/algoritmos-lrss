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
Matrix::Matrix(const Matrix &outroObjeto){

    colunas = outroObjeto.colunas;
    linhas = outroObjeto.linhas;

    alocarEspacoMatriz(linhas, colunas);

    for (int i=0; i < linhas; i++){
        for (int j=0; j < colunas; j++){
            matriz[i][j] = outroObjeto.matriz[i][j];
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
            matriz[i][j] = obj.matriz[i][j];
        }
    }

    return *this;
}


int Matrix::getLinhas(){
    return linhas;
}

int Matrix::getColunas(){
    return colunas;
}

//Exclui as funções setLinhas e setColunas, pois não estavam sendo utilizadas.

int* Matrix::operator[](int const y) { 
    return &matriz[0][y];

}


