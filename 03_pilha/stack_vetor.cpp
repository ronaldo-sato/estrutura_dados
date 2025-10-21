#include "stack.h"
#include <iostream>
using namespace std;

// Função Construtora
// Implementação sequencial, como vetor
Stack::Stack()
{
  length = 0; // Marca o topo da pilha
  // Implementando a pilha como vetor:
  structure = new ItemType[MAX_ITEMS]; // Alocando memória para o vetor
  // Inserção e remoção ocorrem em tempo constantes
}

// Função Destrutora
Stack::~Stack()
{
  // Deleta a estrutura do vetor:
  delete [] structure; // tudo que é alocado com new,
                       // precisa ser desalocado com delete
}

// Função que verifica se está vazio
bool  Stack::isEmpty() const
{
  // Está vazio se length é zero:
  return (length == 0);
}

// Função que verifica se está cheio
bool Stack::isFull() const
{
  // Está cheio se length atingiu o tamanho máximo:
  return (length == MAX_ITEMS);
}

// Função para adicionar um novo item
void Stack::push(ItemType item)
{
  // Se não estiver cheio, podemos colocar um novo item:
  if (!isFull()){
    structure[length] = item; // insere item no topo
    // O topo da pilha depende do número de elementos na pilha:
    length++;
  } else { // caso contrário, se estiver cheia, lançamos um erro:
    throw "Stack is already full!";
  }
}

// Função para remover o elemento do topo
ItemType Stack::pop()
{
  // Se não estiver vazio é possível retirar um elemento:
  if (!isEmpty()){
    ItemType aux = structure[length - 1]; // pega o elemento no topo da pilha
    length--;
    return aux; // retorna o elemento do topo
  } else {
    throw "Stack is empty!";
  }
}

// Função que imprime a Pilha (estrutura sequencial)
void Stack::print() const
{
  cout << "Pilha = ";
  // Como a Pilha é um vetor, iteramos sobre o vetor:
  for (int i = 0; i < length; i++) {
    cout << structure[i];
  }
  cout << endl;
}
