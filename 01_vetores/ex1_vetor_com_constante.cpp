#include <iostream>

// Especificando uma constante para o tamanho do vetor:

const int NUM_ELEM = 10;

int main() {

  // Declarando um vetor para inteiros de tamanho NUM_ELEM
  // Quando inicializamos o vetor na verdade a variável c guarda o endereço 
  // do primeiro byte do primeiro elemento
  int c[NUM_ELEM];

  // Iterando sobre os elementos do vetor para inicializá-lo com laço de 
  // repetição for:

  for (int i = 0; i < NUM_ELEM; i++) {
    c[i] = 2*i; // valor de cada elemento será o dobro de seu índice
  }

  for (int i = 0; i < NUM_ELEM; i++) {
    std::cout << "c[" << i << "] = " << c[i] << "\n";
  }

  return 0;
}
