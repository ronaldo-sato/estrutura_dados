#include <iostream>

using namespace std;

// Ponteiro é uma variável cujo conteúdo é um endereço de memória

// Assim, se x é um ponteiro para y, dizemos que x aponta para y

// Sintaxe ponteiros (declaração):

// tipo* nome; // ou
// tipo *nome; // onde:

// tipo se refere para qual tipo de dados o ponteiro estará apontando
// e nome é o nome da variável, cujo conteúdo será indefinido (como ainda não 
// foi inicializada)

// Os endereços podem ser a localização na memória de uma variável ou função
// (na verdade, a variável em si já é um ponteiro)

// Esse endereço é a localização do primeiro byte ocupado (na memória) por 
// ela (variável ou função)

// Conhecer o endereço de uma variável permite criar estruturas mais complexas

// Por exemplo, listas encadeadas são implementadas com um item conhecendo o 
// endereço do item seguinte (um nó guardando duas informações, ele armazena 
// um valor e aponta pro item seguinte, que está em outra região de memória),
// permitindo o encadeamento 

// A possibilidade de trabalhar diretamente com a memória permite criar 
// programas mais eficientes

// Acima, vimos como declarar o ponteiro e há duas formas de se obter o 
// endereço de memória: de forma estática (em tempo de compilação) ou de 
// forma dinâmica (em tempo de execução)

// As funções abaixo são formas de se passar ponteiros para uma função (cujo 
// indica as formas)

void valor_alocando_memoria(int* p)
// Recebe p que é um ponteiro para int (passamos para a função um ponteiro, 
// mas ele chega na função como cópia), portanto as alterações que ocorrerem 
// a esse ponteiro, ocorrem localmente apenas e não tem reflexo fora da função
{
  // Fazendo o ponteiro p apontar para uma outra região de memória (também 
  // para int)
  p = new int;

  // Nessa nova região de memória definida acima, armazenamos o valor 7
  *p = 7;
}

void valor_modificando_memoria(int* p)
// Recebe um ponteiro para int p (passamos para a função um ponteiro, que chega
// como cópia, mas estamos alterando o conteúdo desse endereço, portanto isso 
// tem reflexo fora da função)
{
  // Nessa posição que o ponteiro aponta, armazenamos o valor 8, assim como 
  // estamos mexendo direto nesse endereço de memória, isso terá reflexo fora da 
  // função
  *p = 8;
}

void referencia(int*& p)
// Passamos o ponteiro p, mas por referência (&), portanto as alterações que 
// ocorrerem aqui na função terá reflexo fora da função
{
  // Assim como na fução valor_alocando_memoria, fazemos o ponteiro 
  // apontar para uma nova região de memória, mas como o ponteiro foi passado
  // por referência, alterações que ocorrem no ponteiro irá ter reflexos fora da
  // função (irá apontar para uma nova região de memória fora da função)
  p = new int;

  // Nessa nova região de memória definida acima, armazenamos o valor 9,
  // portanto fora da função, esse ponteiro p também estará armazenando o 
  // valor 9 já que foi passado por referência
  *p = 9;
}

// ATENÇÃO: Quando passamos um ponteiro concedemos acesso a respectiva região de 
// memória, porque quando passamos um ponteiro, passamos o endereço de memória, 
// permitindo que o conteúdo seja alterado

int main()
// Experimento de ponteiros com funções.
{
  int a  = 1;
  int b  = 2;
  int c  = 3;

  // Operador &: obter o endereço de memória de uma variável
  // Declarando e inicializando os ponteiros
  int* p1 = &a; // ponteiro tipo int que aponta para o local de memória de a
  int* p2 = &b; // ponteiro para o local de memória de b
  int* p3 = &c; // ponteiro para o local de memória de c

  // Ver o endereço dos ponteiros antes:
  cout << "Antes: " <<  p1 << " " <<  p2 << " " <<  p3 << endl;
  // Ver o valor apontado pelos ponteiros antes:
  cout << "Antes: " << *p1 << " " << *p2 << " " << *p3 << endl;
  cout << endl; // só para separar antes de depois
  
  valor_alocando_memoria(p1); 
  valor_modificando_memoria(p2);
  referencia(p3);  

  // Ver o endereço dos ponteiros depois:
  cout << "Depois: "<<  p1 <<" "<<  p2 <<" "<<  p3 << endl;
  // Ver o valor apontado pelos ponteiros depois:
  cout << "Depois: "<< *p1 <<" "<< *p2 <<" "<< *p3 << endl;
  // Ver o valor das variáveis depois:
  cout << "Depois: "<< a <<" "<< b <<" "<< c << endl;
  // Para saber se algum ponteiro deixou de apontar para uma variável que 
  // apontava antes

  // Resultado:

  // O primeiro ponteiro continua apontando para a mesma região de memória (para
  // "a"; a primeira função apenas mudou o apontamento internamente), e como não
  // foi tentado acessar a região de memória para alterar o valor, o valor é o 
  // mesmo (1).

  // No segundo como não mudamos o apontamento do endereço nada aconteceu 
  // (continua apontando para "b"), mas o valor mudou, porque apesar de receber 
  // o endereço por valor, foi alterado na região de memória o valor (antes 2, 
  // depois 8).

  // No terceiro, o ponteiro aponta para regiões de memória diferentes, foi 
  // recebido uma região de memória (por referência, ele apontava para c), mas 
  // foi alterada para outra e foi trocado o conteúdo desse endereço (antes e, 
  // depois 9); note que c continua associado a região de memória anterior (3). 

  // Conclusões do experimento:

  // Como as variáveis usadas nos vetores são ponteiros, a função sabe o
  // endereço onde os elementos estão armazenados;

  // Nesse caso, as modificações dentro da função naquele endereço de memória 
  // surtirão efeito também fora da função;

  // Em outras palavras, quem invoca a função passando um vetor concede acesso 
  // direto aos dados e a permissão de modificá-los;

  // Não dar essa permissão implicaria em copiar o vetor para outro lugar de na 
  // memória.

  return 0;
}
