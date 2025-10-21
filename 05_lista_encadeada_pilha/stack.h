#include "node_type.h"
/*
Quanto a abstração dos dados não iremos alterar nada da interface pública, 
em relação ao que foi implementado como lista linear sequencial. Apenas 
foi alterada a implementação interna. Ao invés de um ponteiro para ItemType
aqui temos uma estrutura de nó, um ponteiro para um NodeType
*/
class Stack  // mesmo nome que na lista linear sequencial
{
  public:
    Stack();  // Construtor (para instanciar um objeto)
    ~Stack(); // Destrutor (para desalocar memória)
    bool isEmpty() const;  // Verificar se a pilha está vazia (const para não 
                           // alterar nenhum dos atributos privados)
    bool isFull() const;   // Verificar se a pilha está cheia 
    void print() const;    // Para imprimir a pilha

    void push(ItemType);  // Adiciona um elemento (tipo ItemType) na pilha
    ItemType pop();       // Remove um elemento (tipo ItemType) da pilha
  private:
    /*
    Como o ponteiro já irá apontar para o topo da pilha (structure), não 
    precisamos de uma variável para saber o tamanho da pilha (topo da pilha)
    */
    NodeType* structure;  // Estrutura (implementado como nó)
                          // ponteiro NodeType para outro nó (NodeType)
    /*
    Na implementação da pilha como lista encadeada, o ponteiro "structure"
    sempre apontará para o elemento no topo e as inserções e remoções 
    ocorrerão em tempo constante   
    */
};
