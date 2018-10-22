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

        // Sobrecarga de Operador [].
		int* operator[](int const y) {
            return &matriz[0][y];

		}
		
	// Sobrecarga de Operador +.
	// Sobrecarga para adição de matrizes.
		Matrix operator+(const Matrix &objeto){
			
			
			if(linhas!=objeto.linhas || colunas!=objeto.colunas){
			
			 cout<<"Numero de linhas e colunas devem ser iguais!"<<endl;
			}else {
			Matrix novoObjeto(linhas,colunas);
				for (int i=0; i < linhas; i++){
					for (int j=0; j < colunas; j++){
						novoObjeto.matriz[i][j]=matriz[i][j]+objeto.matriz[i][j];
					}
				}
			return novoObjeto;
		}
		}
	
	
	// Sobrecarga de Operador -.
	// Sobrecarga para subtração de matrizes.
	
	Matrix operator-(const Matrix &objeto){
			Matrix novoObjeto(linhas,colunas);
			
			if(linhas!=objeto.linhas || colunas!=objeto.colunas){
				cout<<"Numero de linhas e colunas devem ser iguais!"<<endl;
			}
				for (int i=0; i < linhas; i++){
					for (int j=0; j < colunas; j++){
						novoObjeto.matriz[i][j]=matriz[i][j]-objeto.matriz[i][j];
					}
				}
				return novoObjeto;
			}
			
	
		//Sobrecarga de Operador *.
		//Sobrecarga para multiplicação de matrizes.
		Matrix operator*(const Matrix &objeto){
			
			int linhas1 = linhas;
			int colunas1 = colunas;
			
			int linhas2 = objeto.linhas;
			int colunas2 = objeto.colunas;
			
			if (colunas1 != linhas2){
				
			 cout<<"Numero de colunas da matriz 1 e linhas da matriz 2 devem ser iguais!"<<endl;
			 
			}
				
				Matrix novoObjeto(linhas1, colunas2);
			    novoObjeto.zero_matrix();
				
					for(int i=0; i < linhas1; i++){
						for (int j=0; j < colunas2; j++){
							for (int k=0; k < colunas1; k++){
								novoObjeto.matriz[i][j] += matriz[i][k] * objeto.matriz[k][j];
							}
						}
					}
				
				return novoObjeto;
		    }
			
			
		
		
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
		// Sobrecarga de Operador =.
		Matrix & operator=(const Matrix &obj){
		    colunas=obj.colunas;
            linhas=obj.linhas;

            alocarEspacoMatriz(linhas, colunas);

            for (int i=0; i < colunas; i++){
                for (int j=0; j < linhas; j++){
                    matriz[i][j] = obj.matriz[i][j];
                }
            }

            return *this;
		}

		// Construtor.
		Matrix(int lin, int col) {
            colunas=col;
            linhas=lin;

            bool alocou = alocarEspacoMatriz(lin, col);
            if(!alocou) cout << "Erro ao alocar espaço para a matriz." << endl;
		}

        // Construtor de cópia.
        // Recebe o endereço de um outro objeto do tipo Matrix.
		Matrix(const Matrix &outroObjeto){
		    colunas = outroObjeto.colunas;
            linhas = outroObjeto.linhas;

            bool alocou = alocarEspacoMatriz(linhas, colunas);
            if(!alocou) cout << "Erro ao alocar espaço para a matriz." << endl;

            for (int i=0; i < linhas; i++){
                for (int j=0; j < colunas; j++){
                    matriz[i][j] = outroObjeto.matriz[i][j];
                }
            }
		}
		
	
        // Destrutor. ~
		~Matrix(void){
			for (int i=0; i < linhas; i++) {
				delete[] matriz[i];
			}
			delete[] matriz;
		}

		// Função para alocar espaço.
		bool alocarEspacoMatriz(int lin, int col) {
            // ALOCANDO A MATRIZ.
            matriz = new int* [col];
            for (int i=0; i < col; i++) {
                matriz[i] = new int[lin];
            }
            return true;
		}

        // Função para preencher uma matriz de dados.
		void preencherMatriz() {
            cout << endl << "Informe os valores desejados para a Matriz!!" << endl << endl;

            for(int i=0; i < linhas; i++){
                for(int j=0; j < colunas; j++){
                    cout << "Matriz Lin[" << i << "] Col[" << j << "] = ";
                    cin >> matriz[i][j];
                }
            }
        }

        // Função para IMPRIMIR uma matriz de dados.
        void imprimirMatriz() {
            cout << endl << "Imprimindo a Matriz!!" << endl << endl;

            for(int i=0; i < linhas; i++){
                for(int j=0; j < colunas; j++){
                    cout << "Matriz Lin[" << i << "] Col[" << j << "] = " << matriz[i][j] << endl;
                }
            }
        }
        	//Função para que todos os valores da matriz sejam iguais a zero.
	     void zero_matrix(){
			for(int i=0; i < linhas; i++){
				for(int j=0; j < colunas; j++){
					matriz[i][j] = 0;
				}
			}
		}
        
  
};



int main(){
	setlocale(LC_ALL, "Portuguese");
    
	int codigo;
    int row, col;
    int row2,col2;
    
	cout << "Forneca no numeros de linhas, da matriz 1: ";
    cin >> row;

    cout << "Forneca no numeros de colunas, da matriz 1: ";
    cin >> col;

	Matrix mat(row, col);
    cout << "Tamanho Matriz: Linhas " << mat.getLinhas() << " e Colunas " << mat.getColunas() << "!!!" << endl;

	mat.preencherMatriz();
	//------------------------------------Matriz 2--------------------------------------------------------------
	
    cout << "Forneca no numeros de linhas, da matriz 2: ";
    cin >> row2;

    cout << "Forneca no numeros de colunas, da matriz 2: ";
    cin >> col2;
    
   	Matrix mat_2(row2, col2);

	cout << "Tamanho Matriz 2: Linhas " << mat_2.getLinhas() << " e Colunas " << mat_2.getColunas() << "!!!" << endl;
    
	mat_2.preencherMatriz();
	
    cout<<"=============== Menu opções ==============="<<endl;

    cout<<"Digite o codigo desejado para realizar cada operaçao com as matrizes"<<endl;

    do{
    	cout<<"1- Para imprimir a matriz utilizando o construtor de cópia."<<endl;
    	cout<<"2- Para somar duas matrizes."<<endl;
    	cout<<"3- Para subtrair de duas matrizes."<<endl;
    	cout<<"4- Para multiplicar duas matrizes."<<endl;
    	cout<<"5- Para igualar uma matriz a outra."<<endl;
		cout<<"6- Para sair do programa."<<endl;
    	cin >> codigo;
	}while (codigo != 1 && codigo != 2 && codigo != 3 && codigo != 4 && codigo != 5 && codigo != 6 && codigo != 7 && codigo != 8);
	
	if (codigo==1){
	cout << "Imprimindo novo objeto criado pelo construtor de copia." << endl << endl;
	
	Matrix A(mat);
	A[0][0] = 190;
	A.imprimirMatriz();

	cout << "Imprimindo novo objeto criado pelo construtor de copia." << endl << endl;
	
	Matrix B = mat;
	B[0][0] = 50;
	B.imprimirMatriz();

	cout << "Imprimindo NOVAMENTE A MATRIZ INICIAL." << endl << endl;
	mat.imprimirMatriz();
	}else if(codigo==2){
		
		Matrix soma_da_matriz(row,col);
		
		soma_da_matriz = mat + mat_2;
		cout<<"A soma das matrizes 1 e 2 é:"<<endl <<soma_da_matriz<<endl;
	}else if(codigo==3){
		
		Matrix subtracao_da_matriz(row,col);
		
		subtracao_da_matriz = mat - mat_2;
		cout<<"A diferença da matriz 1 com 2:"<<endl <<subtracao_da_matriz<<endl;
	}else if(codigo==4){
		
		Matrix multiplicacao_da_matriz(row,col);
		
		multiplicacao_da_matriz = mat*mat_2;
		cout<<"A matriz 1 multiplicada pela 2 é:"<<endl <<multiplicacao_da_matriz<<endl;
	}else if(codigo==5){
		
		mat = mat_2;
		
		cout<<"A matriz 1 igualada a matriz 2 é:"<<endl << mat <<endl;
	}else {
		
		exit(0);
		
	}
	
}


