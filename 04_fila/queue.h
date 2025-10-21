#include "item_type.h"

// Limitar o tamanho da Fila:
const int MAX_ITEMS = 100;  // Tamanho máximo da fila

class Queue
{
  public :  
    Queue();   // Constructor (para instanciar um objeto)
    ~Queue();  // Destrutor (para desalocar memória)
    bool isEmpty() const;  // Verificar se a fila está vazia (const para não 
                           // alterar nenhum dos atributos privados)
    bool isFull() const;   // Verificar se a fila está cheia
    void print() const;    // Para imprimir a fila

    void enqueue(ItemType);  // Adiciona um elemento (tipo ItemType) na fila 
    ItemType dequeue();      // Remove um elemento (tipo ItemType) da fila
  private:
    int front;  // Para indicar a posição do primeiro elemento na fila
    int back;   // Para indicar a posição do último elemento na fila
    ItemType* structure;  // Estrutura (implementado como vetor):
                          // ponteiro para ItemType
};
