#include <iostream>

// Duas formas (análogas) de se passar um vetor para uma função:

// Sintaxe 1: int b[]
// Sintaxe 2: int* b

// Sintaxe para passar um vetor b para a função:
void modifica_vetor_sintaxe_1(int b[], int num_elem)
// Como passamos o vetor, passamos o endereço, assim modificações dentro da 
// função terão reflexos fora da função, porque ao passar o endereço concedemos
// acesso para que a função vá para eesse endereço e faça alterações
{
  for (int i = 0; i < num_elem; i++){
    b[i] = b[i] * 2;
  }
}

// Sintaxe para passar um vetor b para a função:
void modifica_vetor_sintaxe_2(int* b, int num_elem)
// Como passamos o vetor, passamos o endereço, assim modificações dentro da 
// função terão reflexos fora da função, porque ao passar o endereço concedemos
// acesso para que a função vá para eesse endereço e faça alterações
{
  for (int i = 0; i < num_elem; i++){
    b[i] = b[i] * 2;
  }
}

// Assim, ao passar um vetor como parâmetro para a função, o vetor poderá ser 
// alterado.

// No entanto, se esse não for o intuito, podemos usar a sintaxe "const" quando 
// na declaração do vetor como parâmetro, como abaixo (como acima as duas formas
// são análogas): 

void vetor_const_sintaxe_1(const int* b, int num_elem) 
{
  // Corpo sem alterar os elementos do vetor
}

void vetor_const_sintaxe_2(const int b[], int num_elem) 
{
  // Corpo sem alterar os elementos do vetor
}

// Isso impede que uma função altere o vetor e um erro em tempo de compilação 
// ocorrerá se alguma alteração for feita:

// error: read-only variable is not assignable

const int NUM_ELEM = 10;

int main()
{
  // Alocação Estática
  int c[NUM_ELEM] = {1,2,3,4,5,6,7,8,9,10};

  // Alocação Dinâmica
  int *d = new int[NUM_ELEM];
  for (int i = 0; i < NUM_ELEM; i++){
    d[i] = i + 1;
  }
  
  // Passando para as funções o vetor c (alocado estaticamente) para mostrar 
  // que ambas as sintaxes não interferem em nada, ou seja, as duas funções
  // alteram o vetor e o efeito da modificação dentro da função será observado 
  // fora da função:

  modifica_vetor_sintaxe_1(c, NUM_ELEM);
  modifica_vetor_sintaxe_2(c, NUM_ELEM);

  // Passando para as funções o vetor d (alocado dinamicamente), da mesma forma,
  // as alterações dentro da função são observadas fora:

  modifica_vetor_sintaxe_1(d, NUM_ELEM);
  modifica_vetor_sintaxe_2(d, NUM_ELEM);

  // Portanto, passou um vetor como parâmetro para a função, o vetor poderá ser 
  // alterado.

  // Se esse não for o intuito, podemos usar "const" quando na declaração do 
  // vetor como parâmetro. Isso impede que uma função altere o vetor e um erro 
  // em tempo de compilação ocorrerá se alguma alteração for feita:

  // error: read-only variable is not assignable

  for (int i = 0; i < NUM_ELEM; i++){
    std::cout << i << " : " << c[i] << " , " << d[i] << std::endl;
  }

  return 0;
}
