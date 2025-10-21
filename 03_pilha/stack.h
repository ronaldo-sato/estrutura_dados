#include "item_type.h"

// Limitar o tamanho da Pilha:
const int MAX_ITEMS = 100; // Tamanho máximo da pilha

class Stack {
  public:
    Stack();   // Construtor (para instanciar um objeto)
    ~Stack();  // Destrutor (para desalocar memória)
    bool isEmpty() const;  // Verificar se a pilha está vazia (const para não 
                           // alterar nenhum dos atributos privados)
    bool isFull() const;   // Verificar se a pilha está cheia
    void print() const;    // Para imprimir a pilha
    
    void push(ItemType);  // Adiciona um elemento (tipo ItemType) na pilha
    ItemType pop();       // Remove um elemento (tipo ItemType) da pilha
  private:
    int length;           // Tamanho da pilha
    ItemType* structure;  // Estrutura (implementado como vetor): 
                          // ponteiro para ItemType
};
