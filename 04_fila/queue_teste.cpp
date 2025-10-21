#include "queue.h"
#include <iostream>

using namespace std;

// Programa para adicionar caracteres em um vetor (Fila)

int main() {
  char character;
  Queue queue;
  char queueChar;
  cout << "Adicione uma String." << endl;
  cin.get(character);
  // Para cada caractere da string, se o caractere não for uma quebra de linha
  while (character != '\n' and !queue.isFull()) // enquanto não for "enter"
    {
      // Removemos um elemento
      queue.enqueue(character);
      cin.get(character);
    }
  // Para remover, enquanto a fila não estiver vazia 
  while (!queue.isEmpty())
    {
      // Removemos um  elemento
      queueChar = queue.dequeue();
      // E jogamos na saída padrão
      cout << queueChar;
    }
  cout << endl;
}
