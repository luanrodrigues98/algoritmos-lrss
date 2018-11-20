#ifndef Matrix_h
#define Matrix_h
#include <iostream>

using namespace std;

class Matrix{

	private:
		int colunas;
		int linhas;
		int **matriz;

	public:

		Matrix(int lin, int col);
		Matrix(Matrix &outroObjeto);
		~Matrix();

		int getLinhas();
		int getColunas();

		int* operator[] (int x); 
		Matrix& operator=(Matrix &obj);
		bool operator==(Matrix &obj);
        Matrix operator+(Matrix &objeto);
        Matrix operator-(Matrix &objeto);
        Matrix operator*(Matrix &objeto);
		void alocarEspacoMatriz(int lin, int col);
		void desalocaEspaco(int col);
		
			// Sobrecarga de Operador <<.
		
	 friend ostream & operator<<(ostream &os, Matrix &objetoMatrix){
			for (int i=0; i < objetoMatrix.getLinhas(); i++ ){
				for (int j=0; j < objetoMatrix.getColunas(); j++){
				    cout << objetoMatrix.matriz[i][j] << " ";
				}
				cout << endl;
			}
			return os;
		}
		
		//Sobrecarga de Operador >>.
		
	 friend istream& operator>>(istream &is, Matrix &objetoMatrix){
			for (int i=0; i < objetoMatrix.getLinhas(); i++){
				for (int j=0; j < objetoMatrix.getColunas(); j++){
				cin	>> objetoMatrix.matriz[i][j];
				}
			}
			return is;
		}
		
		 
		

};

#endif // Matriz_h

