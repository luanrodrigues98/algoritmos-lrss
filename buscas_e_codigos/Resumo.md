               **CUSTO COMPUTACIONAL**


**Introdução**:

Para a criação ou utilização de um algoritmo é importante determinar seu desempenho. Cada um é projetado de uma maneira específica e deve executar uma função. Para isso o mesmo utiliza uma quantidade de memória e gasta um tempo determinado, como a busca por algo no Google.

A solução de um problema requer diferentes algoritmos, por isso, como abordado anteriormente, é necessario fazer uma análise para avaliar diversos conceitos.

**Qual sua importância?**

A demanda por buscas mais rápidas, atualmente, é cada vez maior, por isso existe a necessidade de algoritmos mais eficientes. O usuário quer resultado satisfatório, a partir de menos tempo, ou seja, eficácia e velocidade. Portanto,  é imprescindível desenvolver algoritmos que atendam às necessidades dessa época e que não exijam um enorme poder de processamento.

**O Tempo de execução:**

O tempo que um algoritmo leva para ser executado é algo de extrema importância para certas áreas nas quais eles serão aplicados, como controle de tráfego aéreo, cirurgias, etc. Por isso, o conhecimento da complexidade desses algoritmos é de grande relevância. Os melhores  levam  dois milissegundos e os piores cinco em média. Além disso,  o tempo de execução pode ser mascarado por um processador de ótima qualidade.

**Memória:**

A quantidade de memória que um algoritmo vai consumir irá variar de acordo com as operações realizadas por ele, como por exemplo alocação de memória para um vetor. Quanto maior a quantidade de memória alocada, maior será o custo do algoritmo.

**O Custo:**

O custo de utilização de um algoritmo pode ser medido por sua execução em um computador, verificando o número de interações para solucionar um determinado problema.

O custo será dado pela relação **custo = tempo de execução + quantidade de memória gasta no processo**. Existem duas maneiras de realizar a análise do custo de um algoritmo, são elas: análise empírica e matemática.

**Análise Empírica:**

Avalia a complexidade de um algoritmo a partir da execução do mesmo quando implementado, ou seja, ele é analisado por sua execução. O algoritmo é comparado com outro(s) a fim de verificar seu desempenho. Além disso, tal análise permite testá-lo em uma série de diferentes computadores e linguagens, considerando custos não aparentes, como a memória alocada.

**Análise Matemática:**

É um estudo formal realizado por trás da ideia de um algoritmo, ou seja, é saber como funciona o algoritmo implementado. É uma forma mais simplificada a qual busca mostrar somente os custos dominantes do algoritmo. A medição do tempo gasto, assim como a memória utilizada são feitas de maneira independente do hardware ou da linguagem ao qual foi implementado.  


**Quick Sort:**

O quick sort é um algoritmo de ordenação rápida, o qual utiliza uma estrategia de divisão e conquista por meio de um procedimento recursivo.

O vetor é particionado em dois subvetores não vazios, tais que os elementos à esquerda do vetor são menores do que os da direita. Para que aconteça o particionamento do vetor, é necessaria a escolha de um índice chamado de pivô. Tal  índice pode ser definido como sendo o início, fim ou meio do vetor. A conquista ocorre com o ordenamento dos dois subvetores gerados por meio de chamadas recursivas do quick sort.
O pior caso para esse algoritmo ocorre na forma de **teta(n²)** e no melhor **teta(nlogn)**.

**Busca Ingênua:**

O algoritmo de busca ingênua pode ser executado em um vetor ordenado ou não. Em um não ordenado, o mesmo será executado comparando posição por posição do vetor até que o valor seja encontrado ou até o final do vetor. Caso o valor seja encontrado, o algoritmo retornará o ponteiro para a posição do vetor ao qual o número se encontra, caso contrário, o ponteiro será nulo.

**Busca Binária:**

O algoritmo de busca binária só pode ser executado em vetor ordenado. Nele o vetor é dividido ao meio e o número do meio é comparado com o valor buscado. Caso eles sejam iguais, a busca termina, caso contrário, se o número procurado é menor que o valor do meio, a busca será realizada no vetor à esquerda; se ele for maior, a busca será realizada no vetor à direita. Tal processo de divisão é realizado por várias vezes até que o vetor fique com apenas um elemento ou o valor seja encontrado.
O consumo da busca binária é proporcional a **nlogn**.

**Trabalho:**

Foram realizados as implementações dos algoritmos de busca binária e ingênua. Nesse trabalho, para concepção do ordenamento necessário à busca, foi feita a implementação do algoritmo Quick Sort. Também realizados testes para avaliar a função de ordenação e do retorno dos ponteiros.

O método de busca binária recebe como parâmetros: o vetor, o valor buscado e um contador. O contador tem a funcionalidade de retornar o número de interações realizadas para encontrar o valor. A função retorna o ponteiro para a posição do vetor onde se encontra o número, caso seja válido, se não se direciona ao ponteiro nulo.

A função de busca ingênua recebe como parâmetros: o vetor, um ponteiro para o início e fim, o valor buscado e um contador. O contador possui a mesma função citada anteriormente, porém com a adição dos ponteiros para o início e fim, sendo possível, assim, determinar onde o vetor começa e termina. A função possui o mesmo tipo de retorno da busca binária.

Houve simulações para avaliação dos custo dos algoritmos.
O algoritmo de busca ingênua gera uma reta conforme o esperado. Para a confecção dos gráficos foi utilizado o programa GnuPlot e o script  para o fit da reta o qual está disponível em [script](algoritmos-lrss/buscas_e_codigos/graficos/script_ingenua.gnu), assim como o gráfico[1] gerado por ela.

O algoritmo de busca binária descreveu uma função logarítmica de acordo com seu gráfico[2]. Para seu fit foi utilizado o seguinte [script](algoritmos-lrss/buscas_e_codigos/graficos/script_binaria.gnu).

**Gráficos:**

[1]-
[![Gráfico busca ingênua](https://raw.githubusercontent.com/luanrodrigues98/algoritmos-lrss/master/buscas_e_codigos/graficos/GraficoBuscaIngenua.png)](algoritmos-lrss/buscas_e_codigos/graficos/GraficoBuscaIngenua.png)

[2]-
[![Gráfico busca binária](https://raw.githubusercontent.com/luanrodrigues98/algoritmos-lrss/master/buscas_e_codigos/graficos/GraficoBuscaBinaria.png)](algoritmos-lrss/buscas_e_codigos/graficos/GraficoBuscaBinaria.png)

**Referência Bibliográficas:**

[1]- Estruturas de Dados: algoritmos, análise da complexidade e implementações em JAVA e C/C++ por Ana Fernanda Gomes Ascencio & Graziela Santos de Araújo.
