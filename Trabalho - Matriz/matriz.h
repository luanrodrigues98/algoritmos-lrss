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
		Matrix(const Matrix &outroObjeto);
		~Matrix();

		int getLinhas();
		int getColunas();

		int* operator[] (int x); 
		Matrix& operator=(Matrix &obj);
		bool operator==(Matrix &obj);

		void alocarEspacoMatriz(int lin, int col);
		void desalocaEspaco(int col);
		

};

#endif // Matriz_h

