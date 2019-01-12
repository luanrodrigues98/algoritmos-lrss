set grid
set title "Busca Binária"
set xlabel "X - Tamanho do Vetor"
set ylabel "Y - Iterações"
f(x) = a*log(b*x) + c
fit f(x) "busca_binaria.txt" using 1:2 via a,b,c
plot "busca_binaria.txt", f(x)
