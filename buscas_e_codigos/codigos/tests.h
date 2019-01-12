// Testes para verificar a funcionalidade das funções.

//Teste para verificar a funcionalidade do quick_sort.

 TEST(QUICK, ESTA_ORDENADO){
 std::vector<int> vec = {2,4,1,6,8,9,3,5,7,10};
 quick_sort(vec, 0, vec.size());
EXPECT_TRUE(Is_ordered(vec) == true);
}
 TEST(QUICK, NAO_ESTA_ORDENADO){
 std::vector<int> vec = {2,4,1,6,8,9,3,5,7,10};

EXPECT_FALSE(Is_ordered(vec) == false);
}

//Teste para verificar a funcionalidade do retorno da função de busca ingenua quando o valor não é encontrado.

 TEST(BUSCA_INGENUA, NAO_EXISTE){
 int count=0;
 std::vector<int> vec = {2,4,1,6,8,9,3,5,7,10};
 int *end = &vec[vec.size()-1];
 int *begin = &vec[0];
 int *ponteiro = busca_ingenua(vec, begin, end, 25, count);
 EXPECT_TRUE(ponteiro == NULL);
 }

 //Teste para verificar a funcionalidade do retorno da função de busca ingenua quando o valor é encontrado.

 TEST(BUSCA_INGENUA, EXISTE){
 int count=0;
 std::vector<int> vec = {2,4,1,6,8,9,3,5,7,10};
 int *end = &vec[vec.size()-1];
 int *begin = &vec[0];
 int *ponteiro = busca_ingenua(vec, begin, end, 5, count);
 EXPECT_TRUE(*ponteiro == 5);
 }

 //Teste para verificar a funcionalidade do retorno da função de busca ingenua quando o valor está na ultima posição do vetor.

 TEST(BUSCA_INGENUA, ESTA_NO_FIM){
 int count=0;
 std::vector<int> vec = {2,4,1,6,8,9,3,5,7,10};
 int *end = &vec[vec.size()-1];
 int *begin = &vec[0];
 int *ponteiro = busca_ingenua(vec, begin, end, 10, count);
 EXPECT_TRUE(ponteiro == end);
 }

//Teste para verificar a funcionalidade do retorno da função de busca ingenua quando o valor está na primeira posição do vetor.

 TEST(BUSCA_INGENUA, ESTA_NO_INICIO){
 int count=0;
 std::vector<int> vec = {2,4,1,6,8,9,3,5,7,10};
 int *end = &vec[vec.size()-1];
 int *begin = &vec[0];
 int *ponteiro = busca_ingenua(vec, begin, end, 2, count);
 EXPECT_TRUE(ponteiro == begin);
 }

 //Teste para verificar a funcionalidade do retorno da função de busca binaria quando o valor não é encontrado.

 TEST(BUSCA_BINARIA, NAO_EXISTE){
 int count=0;
 std::vector<int> vec = {2,4,1,6,8,9,3,5,7,10};
 quick_sort(vec, 0, vec.size());
 int *ponteiro = busca_binaria(vec, 20, count);
 EXPECT_TRUE(ponteiro == NULL);
 }

 //Teste para verificar a funcionalidade do retorno da função de busca binaria quando o valor está na ultima posição do vetor.

 TEST(BUSCA_BINARIA, ESTA_NO_FIM){
 int count=0;
 std::vector<int> vec = {2,4,1,6,8,9,3,5,7,10};
 quick_sort(vec, 0, vec.size());
 int *ponteiro = busca_binaria(vec, 10, count);
 EXPECT_TRUE(ponteiro == &vec[vec.size()-1]);
 }

 //Teste para verificar a funcionalidade do retorno da função de busca binaria quando o valor está na primeira posição do vetor.

 TEST(BUSCA_BINARIA, ESTA_NO_INICIO){
 int count=0;
 std::vector<int> vec = {2,4,1,6,8,9,3,5,7,10};
 quick_sort(vec, 0, vec.size());
 int *ponteiro = busca_binaria(vec, 1, count);
 EXPECT_TRUE(ponteiro == &vec[0]);
 }

 //Teste para verificar a funcionalidade do retorno da função de busca binaria quando o valor é encontrado.

 TEST(BUSCA_BINARIA, EXISTE){
 int count=0;
 std::vector<int> vec = {2,4,1,6,8,9,3,5,7,10};
quick_sort(vec, 0, vec.size());
 int *ponteiro = busca_binaria(vec, 5, count);
 EXPECT_TRUE(*ponteiro == 5);
 }
