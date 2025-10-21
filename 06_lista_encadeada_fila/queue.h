#include "node_type.h"
/*
Quanto a abstração dos dados não iremos alterar nada da interface pública, 
em relação ao que foi implementado como uma lista linear sequencial. Apenas 
foi alterada a implementação interna. Ao invés de inteiros para indicar a 
posição do início e fim da fila, teremos ponteiros para as respectivas 
posições (ponteiro para um NodeType)
*/
class Queue  // mesmo nome que como lista linear sequencial
{ 
  public:
    Queue(); // Constructor
    ~Queue(); // Destrutor  
    bool isEmpty() const;  // Verificar se a fila está vazia
    bool isFull() const;   // Verificar se a fila está cheia
    void print() const;    // Imprimir a fila

    void enqueue(ItemType);  // Inserir um elemento no final da fila
    ItemType dequeue();      // Remover um elemento do início da fila
  private:
    NodeType* front;  // ponteiro para a parte da frente da fila (onde remover)
    NodeType* rear;   // ponteiro para a parte de trás da fila (onde inserir)
  /*
  Para inserir já temos um ponteiro apontando para o final (rear aponta para o 
  último elemento) e para remover já temos um ponteiro apontando para o início 
  (front aponta para o primeiro elemento).

  Assim conseguiremos efetuar inserções e remoções em tempo contante. Ou seja,
  independem do número de elementos na estrutura.
  */
};
