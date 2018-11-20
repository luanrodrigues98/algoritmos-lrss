#include <stdlib.h>
#include <iostream>
#include <gtest/gtest.h>
#include "matriz.h"
#include "matriz.cpp"
#include "testes.h"

using namespace std;

void preencherMatriz(Matrix &matriz); //Sugiro por essas funções fora da classe, pois elas são voltadas para o usuário e não para os objetos, sendo assim não precisam ficar lá
void imprimirMatriz(Matrix &matriz);

int main(int argc, char **argv) {
    
    ::testing::InitGoogleTest(&argc, argv);
    Matrix matriz (2,2);
    
    preencherMatriz(matriz);  //mudei a main pois com os testes não precisamos utilizar os overloads aqui, já que ja foram testados.
    imprimirMatriz(matriz);   
    cout << "Aplicando testes para os overloads..." << endl;

    return RUN_ALL_TESTS();

}

// Função para preencher uma matriz de dados.
void preencherMatriz(Matrix &matriz) { 
    cout << endl << "Informe os valores desejados para uma Matriz 2x2!!" << endl << endl;

    for(int i=0; i < matriz.getLinhas(); i++){
        for(int j=0; j < matriz.getColunas(); j++){
            cout << "Matriz Lin[" << i << "] Col[" << j << "] = ";
            cin >> matriz[i][j];
        }
    }
}

// Função para IMPRIMIR uma matriz de dados.
void imprimirMatriz(Matrix &matriz){ 
    cout << endl << "Imprimindo a Matriz!!" << endl << endl;

    for(int i=0; i < matriz.getLinhas(); i++){
        for(int j=0; j < matriz.getColunas(); j++){
            cout << "Matriz Lin[" << i << "] Col[" << j << "] = " << matriz[i][j] << endl;
        }
    }
}
