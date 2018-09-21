#include <stdlib.h>
#include <iostream>

using namespace std;
class Matrix{

	private:
		int colunas;
		int linhas;
		int **matriz;

	public:
		int getLinhas() { return linhas; }
		int getColunas() { return colunas; }
		int setLinhas(int l) { linhas = l; }
		int setColunas(int c) { colunas = c; }
		
        // Sobrecarga de Operador.
		int* operator[](int const y) {
            return &matriz[0][y];
		}
        
		// Construtor.
		Matrix(int lin, int col) {
            colunas=col;
            linhas=lin;
			
            // ALOCANDO A MATRIZ.
            matriz = new int* [col];
            for (unsigned i=0; i < col; i++) {
                matriz[i] = new int[lin];
            }
		}
        
        // Destrutor. ~
		~Matrix(void){
			for (unsigned i=0; i < linhas; i++) {
				delete[] matriz[i];
			}
			delete[] matriz;
		}
		
        // Função para preencher uma matriz de dados.
		void preencherMatriz() {
            cout << endl << "Informe os valores desejados para a Matriz!!" << endl << endl;

            for(unsigned i=0; i < linhas; i++){
                for(unsigned j=0; j < colunas; j++){
                    cout << "Matriz Lin[" << i << "] Col[" << j << "] = ";
                    cin >> matriz[i][j];
                }
            }
        }
        
        // Função para IMPRIMIR uma matriz de dados.
        void imprimirMatriz() {
            cout << endl << "Imprimindo a Matriz!!" << endl << endl; // endl = \n end of line

            for(unsigned i=0; i < linhas; i++){
                for(unsigned j=0; j < colunas; j++){
                    cout << "Matriz Lin[" << i << "] Col[" << j << "] = " << matriz[i][j] << endl;
                }
            }
        }
};



int main(){

	int row, col;

    cout << "Forneca no numeros de linhas: ";
    cin >> row;

    cout << "Forneca no numeros de colunas: ";
    cin >> col;

	Matrix mat(row, col);

	cout << "Tamanho Matriz: Linhas " << mat.getLinhas() << " e Colunas " << mat.getColunas() << "!!!" << endl;

	mat.preencherMatriz();
	mat.imprimirMatriz();

}
