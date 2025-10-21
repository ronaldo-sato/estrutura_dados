#include "node_type.h"

/* Mesma classe que em pilha encadeada */

class Stack
{
  public:
    Stack();  // Construtor       
    ~Stack(); // Destrutor
    bool isEmpty() const;
    bool isFull() const;
    void print() const;

    void push(ItemType);
    ItemType pop();  
  private:
    NodeType* structure;
};
