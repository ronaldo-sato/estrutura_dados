
#ifndef NODETYPE_H   // Inclua esse bloco apenas se TIME_H não estiver definido
#define NODETYPE_H   // Na primeira inclusão, define TIME_H para que este
		                 // bloco não seja incluído mais de uma vez.

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

Inserções ocorrem no final da fila e remoções ocorrem no início da fila. 

Para inserir já temos um ponteiro apontando para o final (rear) e para remover
já temos um ponteiro apontando para o início (front).

Assim conseguiremos efetuar inserções e remoções em tempo contante. Ou seja,
independem do número de elementos na estrutura.
*/

#endif
