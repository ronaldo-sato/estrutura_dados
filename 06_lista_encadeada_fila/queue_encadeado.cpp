#include <cstddef>         // Para NULL.
#include <new>             // Para bad_alloc.
#include "queue.h"  
#include <iostream>
using namespace std;

/* CONSTRUTOR
Implementação de Fila como lista encadeada (front e rear são ponteiros para 
o início e final da filha respectivamente).
Basta inicializar os ponteiros da frente e de trás da fila como nulos.
Sendo nulos usaremos isso como condição de parada dos laços.
*/
Queue::Queue()
{
  front = NULL;
  rear = NULL; 
}

/* DESTRUTOR
Nesta implementação como lista encadeada, é preciso desalocar tudo que as 
inserções alocarem e o que não for desalocado pelas remoções.
Na implementação sequencial, o destrutor apenas desalocava o que o construtor
alocou, porque a estrutura foi alocada previamente.
Entretanto, aqui é alocado dinamicamente a cada nova inserção.
Assim, agora nesta implementação (como fila encadeada) é preciso percorrer 
do início até o fim (rear aponta para nulo) e desalocar tudo que foi alocado.
Para isso, é preciso salvar o nó que será desalocado (tempPtr), depois fazer 
com que o início aponte para o nó seguinte, e então desalocar o nó temporário 
(tempPtr).
*/
Queue::~Queue()
{
  NodeType* tempPtr;  // ponteiro temporário (para guardar o nó a ser deletado)
  // Enquanto o primeiro elemento não for vazio (front aponta para o primeiro
  // elemento)
  while (front != NULL) {
      tempPtr = front;      // guardamos o primeiro elemento
      front = front->next;  // a frente da fila aponta para o próximo 
      delete tempPtr;       // então deletamos o primeiro elemento
    }
    /* Ao final do laço font aponta para nulo, mas rear continua apontando para 
    uma região de memória que já foi desalocada (para não haver nenhum erro, 
    caso o usuário queira reutilizar essa estrutura, é preciso desalocar, 
    caso contrário para não haver vazamento de memória) */
  rear = NULL;  // depois de remover todos os elementos a parte de trás também
                // é atualizada como nulo
}


/* Verifica se a fila está cheia 
Um nó só pode ser alocado enquanto houver espaço na memória.
Assim, aqui verificamos se há memória disponível para alocar um novo elemento,
tentando alocar um nó.
*/
bool Queue::isFull() const {
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

/* Verifica se a Fila está vazia */
bool Queue::isEmpty() const {
  // se o ponteiro inicial aponta para nulo é porque está vazia
  return (front == NULL);
}

/*
Insere um elemento no final da fila.
Para adicionar um novo elemento ao final */
void Queue::enqueue(ItemType newItem){  // recebe a informação que será armazenada
  // só será possível adicionar um novo elemento se houver espaço na memória
  if (!isFull()) {
    NodeType* newNode;
    newNode = new NodeType;   // alocando um novo nó
    newNode->info = newItem;  // armazenando a informação no respectivo campo do novo nó
    newNode->next = NULL;     // o novo nó (fim da fila) aponta para nulo
    // se o fim da fila for nulo, é porque não há elementos
    if (rear == NULL)
      front = newNode;  // então front aponta para esse primeiro elemento
    // caso contrário, se rear aponta para alguém (há elementos),
    // atualizamos o ponteiro do fim
    else
      rear->next = newNode;  // último elemento aponta para novo último elemento
    // ponteiro do fim da fila aponta para o último elemento, independentemente
    // se a fila está vazia ou não
    rear = newNode;  // rear aponta para o último elemento
  } else {  // se estiver cheio lançamos um erro informando
    throw "Queue is already full!";           
  }
}

/*
Retorna e remove o primeiro elemento da fila.
É possível se a fila não estiver vazia. 
Assim, criamos um ponteiro temporário para armazenar a informação */
ItemType Queue::dequeue(){
  // se a fila não for vazia
  if (!isEmpty()) {
    NodeType* tempPtr;
    tempPtr = front;              // nó temporário recebe o primeiro elemento
    ItemType item = front->info;  // guardando a informação que será retornada
    front = front->next;          // elemento seguinte agora será o primeiro
    // se o primeiro elemento for vazio (era o último elemento)
    if (front == NULL)            // chegamos ao final da fila (ficou vazia)
      rear = NULL;                // ponteiro do fim aponta para vazio
    delete tempPtr;               // desalocamos o primeiro elemento
    return item;                  // retorna a 
  } else {                        // se for vazio
    throw "Queue is empty!";      // lançamos um erro informando
  }    
}

/* Imprimir a fila na saída padrão
Criamos um temporário para armazenar e apontar elemento a elemento ao percorrer
a fila a partir do início.
 */
void Queue::print() const {
  NodeType* tempPtr = front;
  while (tempPtr != NULL) {     // enquanto temporário não for vazio (fim)
    cout << tempPtr->info;      // passamos a informação para a saída padrão
    tempPtr = tempPtr->next;    // temporário aponta para o próximo elemento
  }
  cout << endl;
}
