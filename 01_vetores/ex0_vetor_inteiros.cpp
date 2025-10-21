#include <iostream>

int main() {
  // declarando e inicializando os 3 primeiros elementos
  // como não fornecemos os outros valores, eles são iniciados com zero
  int c[10] = {14, 0, 13};
  
  c[5] = 30; // atribuindo ao elemento de posição 5 o valor de 30
  c[7] = 40;
  c[8] = 50;

  // Iterando sobre os elementos do vetor usando laço de repetição for
  // para imprimir os elementos na tela:
  for (int i = 0; i < 10; i++) {
    std::cout << "c[" << i << "] = " << c[i] << "\n";
  }

  return 0;
}
