#include "queue.h"
#include "stack.h"
#include <iostream>
using namespace std;

/*
Programa para verificação se uma string é um palíndromo.

Pilha é uma estrutura útil para garantir alinhamento de componentes em 
processos.
Por exemplo, na chamada de funções na execução de programas, analise de
sintaxe de linguagem de programação.

Fila é uma estrutura útil principalmente quando precisamos garantir que 
processos acessarão recursos compartilhados de uma maneira justa.
Por exemplo, no envio de documentos para impressão, troca de mensagens entre 
processos em um Sistema Operacional.

Aqui iremos verificar uma string se ela é um palíndromo, ou seja, se ela lida da 
esquerda para a direita é igual se lida da direita para a esquerda (ler de 
frente para trás deve ser igual ler de trás ara frente).

Ex. palíndromo: ovo, 12321

Assim, o programa irá percorrer a string e cada caractere será armazenado numa 
pilha e numa fila. Se ao desempilhar (a string sai de trás para frente) e 
desenfileirar (a string sai de frente para trás), ao final os caracteres 
forem todos correspondentes (iguais), então a string é um palíndromo.
*/

int main() {
  bool palindrome = true;  // inicializamos como palíndromo (verdadeiro)
  
  // cada informação será um caractere
  char character;  // caractere para percorrer a string
  char stackChar;  // caractere para desempilhamento
  char queueChar;  // caractere para desenfileiramento
  
  Stack stack;  // estrutura de pilha para armazenar a string
  Queue queue;  // estrutura de fila
  cout << "Adicione uma string." << endl;
  cin.get(character);
  // enquanto caractere for diferente de enter ou uma quebra de linha
  while (character != '\n') {
    stack.push(character);     // guardamos o caractere na pilha
    queue.enqueue(character);  // inserimos o caractere na fila
    cin.get(character);        // para todo caractere
  }
  // após armazenar a string como pilha e fila
  // enquanto for um palíndromo e a fila não for vazia (apenas checando a fila
  // porque ela e a pilha terão o mesmo tamanho)
  while (palindrome && !queue.isEmpty()) { 
    stackChar = stack.pop();      // desempilhamos o caractere do topo
    queueChar = queue.dequeue();  // desenfilairamos o caractere do início
    if (stackChar != queueChar)   // se os caracteres não forem iguais
	    palindrome = false;         // então não é um palíndromo
  }
  // portanto, ao final de percorrer as estruturas
  if (palindrome)  // se for palíndromo, continua sendo
    // informa na saída padrão
    cout << "String é Palindrome" << endl;
  else  // caso contrário, informa que não é palíndromo
    cout << "String não é palindrome" << endl;
  return 0;
}
