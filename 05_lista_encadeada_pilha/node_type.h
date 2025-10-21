typedef char ItemType;  // ItemType é um apelido para char

/*
 Estrutura de nó usada para guardar a informação e o endereço do próximo
 elemento.
*/
struct NodeType
/* struct é uma palavra reservada do C
  Resumidamente, vamos interpretar como uma estrutura que nos permite 
  unir diferentes tipos de dados, isto é, numa mesma região de memória
  vamos colocar um ItemType junto com um ponteiro NodeType

  Poderíamos usar uma classe também, mas para diminuir o código não foi usada
*/
{
  ItemType info;   // informação
  NodeType* next;  // ponteiro
};

/*
Com essa estrutura é possível iniciar o encadeamento, basta armazenarmos um 
ponteiro que irá apontar para o início da estrutura. 

Como todas as operações ocorrem no topo da pilha, conseguiremos efetuar em 
tempo contante. 

Para inserir já temos um ponteiro apontando para o topo e para remover já temos 
um ponteiro apontando para onde temos que remover.
*/

