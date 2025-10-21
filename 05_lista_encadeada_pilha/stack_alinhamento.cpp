#include "stack.h"
#include <iostream>

using namespace std;

/*
Programa para verificação do alinhamento.

Pilha é uma estrutura útil para garantir alinhamento de componentes em 
processos.
Por exemplo chamada de funções na execução de programas, analise de
sintaxe de linguagem de programação.

Aqui iremos verificar o alinhamento de caracteres de abertura e fechamento de 
parênteses, chaves e colchetes em string.

Assim, o programa irá percorrer uma string e quando houver um caractere de 
abertura irá empilhar.

Quando houver um caractere de fechamento, irá desempilhar o último empilhado e 
verificar se forma um par.

Se não formar, irá informar que a string está mal formada (caracteres não estão
alinhados).

Ao final, se tudo for desempilhado sem sair do laço (caracteres não estão
alinhados) e ela estiver vazia é porque a string está bem alinhada.
 
Se não estiver vazia, é porque mais caracteres de abertura estão presentes na
string, então não é bem formada.
*/

int main() {
  ItemType character;  // cada informação será um caractere
  Stack stack;         // estrutura de pilha
  ItemType stackItem;  // caractere retirado do topo da pilha
  
  cout << "Insira uma string." << endl;
  cin.get(character);  // iremos receber uma string e percorrer cada caractere
  
  bool isMatched = true;

  /* Enquanto a string for bem formada (isMatched é true) e enquanto não chegar
  no fim da string (\n) */
  while (isMatched && character != '\n') {
    // Se for algum caractere de abertura
    if (character == '{' || character== '(' || character==  '['){  
      stack.push(character);  // empilhamos o caractere
    }
    // Se for algum caractere de fechamento
    if(character == '}' || character== ')' || character==  ']'){    
      if (stack.isEmpty()) {  // e a pilha estiver vazia
        isMatched = false;    // não é bem formada
      } else {                // senão
        stackItem = stack.pop();  // desempilhar o caractere do topo
        /* se o caractere do topo (stackItem) for correspondente ao caractere, 
        a string é bem formada */
        isMatched = (
              (character == '}' && stackItem== '{')
              || (character== ')' && stackItem == '(')
              || (character== ']' && stackItem == '[')
              );
      }
    }
    cin.get(character);  // pega o próximo caractere
  }

  /* Ao final, saímos do laço se a string é mal formada, mas se ela for bem 
  formada e estiver vazia, é porque a string é bem formada */
  if (isMatched && stack.isEmpty() ) {
    cout << "Bem formada \n";
  } else {  // caso contrário não é bem formada
    cout << "Mal formada \n";
  }
}

