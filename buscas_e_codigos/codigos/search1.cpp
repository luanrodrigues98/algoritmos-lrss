#include<iostream>
#include <vector>
#include<random>
#include "gtest/gtest.h"





using namespace std;

void printArray(vector<int>&vetor)
{
    for (int i = 0; i < vetor.size(); ++i)
        std::cout << vetor[i] << std::endl;
}


int separa_vec(vector<int> &vetor,int inicio, int fim){
    int aux;
    int cont = inicio;

    for(int i=inicio+1 ; i<=fim ; i++){

        if( vetor[i] < vetor[inicio] ){
            cont++;
            aux=vetor[i];
            vetor[i]=vetor[cont];
            vetor[cont]=aux;
        }
    }

    aux=vetor[inicio];
    vetor[inicio]=vetor[cont];
    vetor[cont]=aux;

    return cont;
}

void quick_sort(vector<int> &vetor,int inicio, int fim){
    int pos;
    if(inicio < fim){
        pos = separa_vec(vetor,inicio,fim);
        quick_sort(vetor,inicio,pos-1);
        quick_sort(vetor,pos+1,fim);
    }
}

bool Is_ordered(vector<int>&vetor){
for(int i = 0; i < (vetor.size() - 1);i++){
  for(int j =(i +1); j < vetor.size(); j++){
    if(vetor[i] <= vetor[j])
    return true;

  }
}
return false;

}

int* busca_binaria(vector<int> &vetor, int value, int &count){
count = 0;
int inicio = 0;
int fim = (vetor.size() - 1);
if (vetor[inicio] == value){
 count++;
return &vetor[inicio];
}else if(vetor[fim] == value){
 count++;
return &vetor[fim];
}


while (inicio <= fim){
int meio = (inicio + fim) / 2;
if (value < vetor[meio]){
 count++;
fim = meio - 1;
}
else if (value > vetor[meio]){
 count++;
inicio = meio + 1;

}else{
   count++;
return &vetor[meio];

}
}

return NULL;
}


 int* busca_ingenua(vector<int> &vetor, int* inicio, int* fim, int value, int&count){
count = 0;

 if(value == *inicio){
 return inicio;
    count++;
  }else if(value == *fim){
 return fim;
  }
 for(inicio; inicio < fim; inicio++){
    if(value == *inicio){
       return inicio;
     }
    count++;
   }
  return NULL;

  }
// Inicio dos testes.


// Main para testes de ponteiros.
// int main(){

  // vector<int> vec = {2,4,35,25,3,32,12,40,26,21};

  // int count;
 // int *end = &vec[vec.size()-1];
 // int *begin = &vec[0];
 // int *ponteiro;


// ponteiro = busca_ingenua(vec,begin, end, 12, count);
// cout<<"Endereco ponteiro = "<< ponteiro<<endl;
 // cout<<"Valor ponteiro = "<< *ponteiro<<endl;
// }

// Main para simulações.
#include "tests.h"
   int main(int argc, char **argv){
  random_device rd;
  mt19937 gen(rd());



  for( int vec_size = 1000; vec_size < 10000; vec_size+=1000){
  vector<int> random;

  uniform_int_distribution<> dis(0,vec_size);

   for(int amostra = 0; amostra < 1; amostra++){


    for(int n = 0; n < vec_size; n++){
    random.push_back(dis(gen));
    }
  int count;
  int *end = &random[vec_size];
  int *begin = &random[0];
  //quick_sort(random, 0, vec_size);
   //if(Is_ordered(random) == true){
      busca_ingenua(random, begin, end, dis(gen), count);
  cout << vec_size<<" "<<count<<endl;

  //}
   }
    }
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
 }
