#include "stack.h"
#include <cstddef> // Para funcionar o NULL
#include <new>

#include <iostream>
using namespace std;

/* CONSTRUTOR
Implementação de Pilha como lista encadeada (structure é um ponteiro que
sempre aponta para o topo).
Não é preciso alocar memória no construtor, como na implementação 
sequencial, pois só iremos alocar memória quando precisarmos inserir um
elemento, portanto basta ele ficar apontando para nulo (topo aponta para nulo). 
Ou seja, quando instanciado aponta para lugar nenhum (nulo).
*/
Stack::Stack(){
  structure = NULL;  // utilizaremos (nulo) como critério de parada
}

/* DESTRUTOR
Nesta implementação como lista encadeada, é preciso desalocar tudo que as 
inserções alocarem e o que não for desalocado pelas remoções.
Na implementação sequencial, o destrutor apenas desalocava o que o construtor
alocou, porque a estrutura foi alocada previamente.
Entretanto, aqui é alocado a cada nova inserção.
Assim, agora nesta implementação (como pilha encadeada) é preciso percorrer 
do início até o topo (structure que aponta para nulo) e desalocar tudo que foi 
alocado.
Para isso, é preciso salvar o nó que será desalocado (tempPtr), depois fazer 
com que o início aponte para o nó seguinte, e então desalocar o nó temporário 
(tempPtr).
*/
Stack::~Stack(){
  NodeType* tempPtr;  // ponteiro temporário (para guardar o nó a ser deletado)
  // Equanto não chegar no topo, percorrer a estrutura até encontrar vazio 
  // (topo)
  while (structure != NULL) {
    tempPtr = structure;  // guardar o nó que será desalocado
    structure = structure -> next;  // fazer com que o início aponte para o 
                                    // próximo
    /*
    Como structure é um ponteiro (NodeType) para a acessar o próximo, é preciso 
    usar a sintaxe de seta (->)
    */
    delete tempPtr;  // então deletamos o nó percorrido
  }
}

// Verifica se a pilha está vazia
bool Stack::isEmpty() const {
  // Se o ponteiro inicial aponta para nulo é porque está vazia
  return (structure == NULL);
}

/*
Verifica se a pilha está cheia.
Um nó só pode ser alocado enquanto houver espaço na memória.
Portanto, aqui simplesmente verificamos se há memória disponível para alocar 
um novo elemento, tentando alocar um nó.
*/
bool Stack::isFull() const {
  NodeType* location;
  try {
    // tentamos alocar uma nova região de memória
    location = new NodeType;
    delete location;  // conseguindo deleta o que foi alocado
    return false;     // então informa que não está cheio
  } catch(std::bad_alloc exception){  // não conseguindo alocar haverá erro  
    return true;      // e então informa que está cheio
  }  
}

/*
Insere um elemento no topo da pilha.
Para adicionar um novo elemento no topo (structure é um ponteiro que sempre
aponta para o topo), isso será possível se houver espaço na memória.
Assim, alocamos um novo nó e fazemos com que ele aponte para o topo da pilha.
O nó antigo topo, precisa apontar para esse novo nó adicionado, assim o ponteiro
structure deverá apontar para o novo nó.
 */
void Stack::push(ItemType item){  // recebe a informação que será armazenada
  if (!isFull()){
    NodeType* location;
    location = new NodeType;  // alocando um novo nó
    location -> info = item;  // armazenando a informação no respectivo campo do novo nó
    location -> next = structure;  // o novo nó deve apontar para o topo da pilha
    structure = location;    // antigo topo aponta para o novo nó
  } else {  // se estiver cheio lançamos um erro informando
    throw "Stack is already full!";
  }
}

/*
Devolve o objeto que está no topo da pilha (structure é o topo). 
É possível se a estrutura não estiver vazia.
Assim, criamos um ponteiro temporário para armazenar a informação do topo que
será retornada.
O nó anterior precisa apontar para o topo da pilha. E assim podemos desalocar
a memória do elemento que era o topo da pilha.
 */
ItemType Stack::pop(){
  // se a pilha não for vazia
  if (!isEmpty()) {
    NodeType* tempPtr;
    tempPtr=structure;              // nó temporário aponta para o topo
    ItemType item=structure->info;  // guardando a informação que será retornada
    structure=structure->next;      // aponta para o topo
    delete tempPtr;                 // desaloca o elemento do topo
    return item;                    // retorna a informação
  } else {                          // se for vazio
    throw "Stack is empty!";        // lançamos um erro informando
  }
}

/*
Imprimir a pilha na saída padrão.
Criamos um temporário para armazenar e apontar elemento a elementeo ao percorrer
a pilha a partir do início.
*/
void Stack::print() const {
  NodeType* tempPtr = structure;
  while (tempPtr != NULL) {     // enquanto temporário não for vazio (topo)
    cout << tempPtr -> info;    // passamos a informação para a saída padrão
    tempPtr = tempPtr -> next;  // temporário aponta para o próximo elemento
  }
  cout << endl;
}

