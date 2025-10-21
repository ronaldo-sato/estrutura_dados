#include <iostream>

// Alocação dinâmica de memória é um mecanismo de alocação e desalocação 
// de memória por meio de ponteiros no tempo de execução do programa

// Vantagens:
// 1 - Não é necessário definir o tamanho da memória a ser utilizada
// 2 - Possibilidade de aumentar e diminuir o tamanho da memória utilizada 
// em tempo de execução

// Os operadores "new" e "delete" efetuam a alocação e desalocação de memória,
// respectivamente. Via de regra, toda vez que a memória for alocada será 
// necessário desalocar para que não ocorra vazamento de memória

// Variáveis alocadas dinamicamente residem em local de memória diferente 
// das que foram alocadas estaticamente 

// Exemplo: alocando memória dinamicamente para armazenar um inteiro:

// int* intPointer; // declarando o ponteiro do tipo int
// intPointer = new int; // inicializando o ponteiro, que aponta uma nova região
// de memória que cabe um inteiro 

// OBS: uma variável alocada dinamicamente com new, como feito acima, não possui
// nome; essa variável precisa ser acessada indiretamente pelo ponteiro 
// retornado por new; então não existe uma variável cujo valor está nessa região
// de memória alocada, o que existe é um ponteiro que aponta para essa região 
// de memória, cujo valor pode ser acessado por meio desse ponteiro

// Para acessar indiretamente o conteúdo do ponteiro, utilizamos o operador "*",
// que retorna o conteúdo da variável localizada em determinado endereço:

// Sintaxe:
// Para obter o conteúdo que está localizado no endereço apontado por 
// intPointer:

// Declarando a variável que irá armazenar o conteúdo do ponteiro:

// int anotherInt;

// anotherInt recebe o valor da região de memória que está sendo apontada por 
// intPointer:

// anotherInt = *intPointer;

// OBS: anotherInt está associado a alguma outra região de memória, isto é, não 
// estará associado a região de memória do ponteiro, o que acontece é que o 
// valor associado ao ponteiro será duplicado a essa outra região de memória 
// associada a anotherInt

// Para alterar o conteúdo que está localizado no endereço apontado por 
// intPointer, por exemplo alterar para 25, fazemos:

// *intPointer = 25;

// Por definição, um ponteiro com valor zero aponta para vazio e para não 
// confundir com o inteiro zero, é conveniente usar a constante NULL do pacote
// cstddef:

// #include <cstddef>
// bool* truth =  NULL;
// float* money = NULL;

// Vamos observar a memória após algumas operações:

// Declarando um ponteiro chamado truth que aponta para um booleano:
// bool* truth = new bool;
// Atribuindo o valor true para o espaço de memória que esse ponteiro aponta:
// *truth = true;

// Declarando um ponteiro chamado money que aponta para um float:
// float* money = new float;
// Atribunindo o valor 34.31 para o espaçode memória que money aponta:
// *money = 34.31;

// Inicializando um ponteiro float que não possui conteúdo:
// float* myMoney = new float;

// Lembrando que para obter o valor que o ponteiro aponta fazemos *variável,
// onde variável é o nome da variável

// Conforme o tipo do ponteiro, podemos aplicar as respectivas operações a esse 
// tipo no ponteiro, então, por exemplo:

// Podemos incrementar o ponteiro para inteiros:
// *intPointer++;

// Cuidados com Ponteiros - atribuições completamente diferentes:

// Conteúdo da região de memória apontado por money é copiado para a região de 
// memória apontada por myMoney:

// *myMoney = *money;

// myMoney passa a apontar para a mesma região de memória apontada por money:

// myMoney = money;

// Ao criar o ponteiro myMoney, um espaço de memória foi alocado na sua 
// inicialização, e ao fazer com que myMoney aponte para o memso local de 
// memória de money, isso proporciona vazamento de memória, já que o local de 
// memória apontado por myMoney foi perdido.

// Assim, para que o vazamento de memória não ocorra, precisamos primeiro 
// desalocar o espaço de memória inicialmente alocado com o operador delete:

// delete myMoney; // delete apenas libera a região que o ponteiro aponta
// myMoney = money; // delete não inutiliza myMoney

int main() {
  int num_elem;
  std::cout << "Digite o tamanho do vetor: ";
  std::cin >> num_elem;

  // alocando dinâmicamente um espaço de memória ao inicializar um ponteiro "c"
  // (vetores são ponteiros, que aponta para uma região de memória de tamanho 
  // suficiente para alocar num_elem elementos inteiros contíguos, isto é, 
  // cria um vetor para armazenar num_elem inteiros consecutivos)
  // ao inicializar a  variável c recebe o endereço de memória do 1o elemento 
  // do vetor
  int* c = new int[num_elem];

  // OBS: tudo que for alocado com new, precisará ser desalocado com delete

  // armazenar em cada posição do vetor o valor índice*2 
  for (int i = 0; i < num_elem; i++) {
    c[i] = 2*i;
  }

  // imprimir os elementos do vetor
  for (int i = 0; i < num_elem; i++) {
    std::cout << "c[" << i << "] = " << c[i] << "\n";
  }

  delete [] c; // desalocando o espaço de memória do vetor

  return 0;
}
