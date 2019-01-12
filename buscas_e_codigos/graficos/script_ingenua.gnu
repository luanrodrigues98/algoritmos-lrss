set grid
set title "Busca Ingênua"
set xlabel "X - Tamanho do Vetor"
set ylabel "Y - Iterações"
g(x) = a + b*x
fit g(x) "busca_ingenua.txt" using 1:2 via a,b
plot "busca_ingenua.txt", g(x)
