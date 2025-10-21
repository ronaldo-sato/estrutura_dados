#include "stack.h"
#include <iostream>

using namespace std;

// Programa para adicionar caracteres em um vetor (Pilha)

int main() {
  ItemType character;
  Stack stack;
  ItemType stackItem;
  
  cout << "Adicione uma String." << endl;     
  cin.get(character);
  // Para cada caractere da string, se o caractere não for uma quebra de linha
  while (character != '\n') // enquanto não for "enter"
    {
      // Colocamos ele na pilha
      stack.push(character);
      cin.get(character);
    }
  // Para remover, enquanto a pilha não estiver vazia 
  while (!stack.isEmpty())
    {
      // Removemos um elemento
      stackItem = stack.pop();
      // E jogamos na saída padrão
      cout << stackItem;
    }
  
  cout << endl;
}
