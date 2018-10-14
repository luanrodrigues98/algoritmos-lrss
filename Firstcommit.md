Resumo Sobre Ponteiros:

Ponteiros são variavies especias utilizadas para guardar o endereço de memoria. Um ponteiro pode ter o valor "NULL", função da biblioteca stdlib.h ([1]). Eles são inicializados da seguinte forma "*variavel_qualquer". Ponteiros não devem ser utilizados antes de serem inicializados de alguma forma. Um ponteiro também pode ser utilizado para guardar o endereço de funções, structs e etc.
Existem diversos tipos de ponteiros sejam eles, ponteiros para inteiros (__int *p__), ponteiros para ponteiros para interios (__int **p__), um ponteiro para ponteiro é importante para os casos onde precise apontar para uma matriz([1]). Existem conjunto limitado de operações aritméticas pode ser executado em ponteiros. Um ponteiro pode ser, incrementado (__++__), decrementado (__--__), um inteiro pode ser adicionado a um ponteiro (__+ ou + =__), um inteiro pode ser subtraído de um ponteiro (__- ou - =__) ([2]). A aritmética de ponteiro não tem sentido a menos que seja executada em uma matriz ([2]).
[1]:https://www.ime.usp.br/~pf/algoritmos/aulas/pont.html
[2]:https://www.geeksforgeeks.org/pointers-in-c-and-c-set-1-introduction-arithmetic-and-array/
