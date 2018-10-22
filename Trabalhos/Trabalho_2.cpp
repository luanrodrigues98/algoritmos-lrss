#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>
using namespace std;

double quadratic(double x, vector<double> param){
	return x*x*param[0]+x*param[1]+param[2];
 
}
double linear(double x, vector<double>param){
	return x*param[0]+param[1];
	
}


double integral(double (*func)(double, vector<double>), vector<double> parametros, vector<double> intervalos){
	
	double n_ret=(intervalos[1]-intervalos[0])/intervalos[2];
	double areab=0.0;
	double area=(func(intervalos[0],parametros)+func(intervalos[1],parametros))/2;
	for (unsigned i=1; i<intervalos[2];i++){
	area+=func(intervalos[0]+i*n_ret,parametros);
	}
	areab=area*n_ret;
	
	return areab;
	
	}

int main (){
	vector<double>param1;
	vector<double>param3;
	vector<double>intervalos1;
	param3.push_back(1);
	param3.push_back(5);
	param1.push_back(1);
	param1.push_back(2);
	param1.push_back(3);
	intervalos1.push_back(1);
    intervalos1.push_back(5);
    intervalos1.push_back(7);
    cout << "A area da funcao quadratica e:"<< endl;
	cout << integral(quadratic,param1,intervalos1) << endl;
	cout << "A area da funcao linear e:" << endl;
	cout << integral(quadratic,param3,intervalos1) << endl;
	
}

