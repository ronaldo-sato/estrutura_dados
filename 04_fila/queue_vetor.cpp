#include "queue.h"
#include <iostream>
using namespace std;

/*
Iremos implementar a estrutura de fila como vetor circular.
Como cada elemento irá entrar ao final da fila e será retirado do início da
fila, isso, se pensado como uma estrutura reta não permite reaproveitar o 
espaço do vetor, já que a cada remoção geraria espaço livre que ficaria sem 
função e o início do vetor caminharia para o fim do vetor. No entando, pensando 
em uma estrutura circular, utilizando o módulo (o índice "real" pode ser obtido 
com o resto da divisão pelo tamanho do vetor), podemos reaproveitar esses 
espaços que ficam livres. Assim a fila só fica cheia, se o vetor todo estiver 
ocupado.
*/

// Função Construtora
Queue::Queue()
{
  front = 0; // Posição do primeiro elemento na fila
  back  = 0; // Posição do "último" elemento na fila
  // Implementando a fila como vetor:
  structure = new ItemType[MAX_ITEMS]; // Alocando memória para o vetor
}

// Função Destrutora
Queue::~Queue()
{
  // Deleta a estrutura do vetor:
  delete [] structure; // tudo que é alocado com new,
                       // precisa ser desalocado com delete
}


bool Queue::isEmpty() const
{
  // Está vazio se o início e o fim são a mesma posição:
  return (front == back);
}

bool Queue::isFull() const
{
  // Está cheio se a diferença entre o fim e o início é o tamanho máximo:
  return (back - front == MAX_ITEMS);
}

// Adicionar um novo item ao final da fila
void Queue::enqueue(ItemType item)
{
  // Se não estiver cheia, podemos colocar um novo item:
  if (!isFull()){
    // Implementação circular:
    structure[back % MAX_ITEMS] = item; // insere item ao final
    back++;
  } else { // caso contrário, se estiver cheia, lançamos um erro:
    throw "Queue is already full!";
  }
}

// Remover um elemento do início da fila
ItemType Queue::dequeue()
{
 // Se não estiver vazia é possível retirar um elemento:
  if (!isEmpty()){
    front++; // primeiro incrementamos a posição de front
    return structure[(front-1) % MAX_ITEMS]; // retornamos o elemento anterior
  } else {
    throw "Queue is empty!";
  }
}

void Queue::print() const
{
  cout << "Fila = ";
  // Como a Fila é um vetor, iteramos sobre o vetor:
  for (int i = front; i < back; i++) {
    cout << structure[i % MAX_ITEMS];
  }
  cout << endl;
}
