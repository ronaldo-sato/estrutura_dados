#include "hash.h"
#include <iostream>
using namespace std;

Hash::Hash(int max)
{
  /* Construtor */
  length = 0;                       // número de elementos que existem na estrutura
  max_items = max;                  // número máximo de elementos que podem ter na estrutura
  structure = new Aluno[max_items]; // aloca um espaço de memória dinamicamente
}

Hash::~Hash()
{
  /* Destrutor */
  delete[] structure; // desaloca a memória
}

bool Hash::isFull() const
{
  // Informa se a estrutura está cheia
  return (length == max_items);
}

int Hash::getLength() const
{
  // Informa o tamanho da estrutura
  return length;
}

void Hash::retrieveItem(Aluno &aluno, bool &found)
{
  /* Recebe um (objeto) aluno por referência, porque quem chama esta função passa
  somente o RA do aluno, e ao encontrá-lo, obtemos a informação do nome e assim
  lá onde teve a chamada essa informação estará disponível.
  Recebe também a variável de controle se achou ou não o aluno, também por
  referência, porque lá onde teve a chamada essa condição será usada para imprimir
  ou não a informação */
  int location = getHash(aluno);    // obtém a posição do aluno na tabela Hash
  Aluno aux = structure[location];  // armazena provisoriamente as informações do aluno
  if (aluno.getRa() != aux.getRa()) // se os RAs forem diferentes
  {
    found = false; // aluno não encontrado (assumindo que não há colisões)
  }
  else // caso contrário
  {
    found = true; // aluno foi encontrado
    aluno = aux;  // atualizamos as informações do aluno com o obtido na estrutura de dados
  }
}

void Hash::insertItem(Aluno aluno)
{
  /* Recebe um aluno por parâmetro
     (assumindo que não há colisões, pois senão este código não funcionará)*/
  int location = getHash(aluno); // obtém a posição do aluno na tabela Hash, através do RA
  structure[location] = aluno;   // insere o aluno na respectiva posição
  length++;                      // incrementa um elemento na estrutura (assumindo: não há colisões)
}

void Hash::deleteItem(Aluno aluno)
{
  int location = getHash(aluno); // obtém a posição do aluno na tabela Hash, através do RA
  structure[location] = Aluno(); // nessa respectiva posição, atribui um aluno vazio (RA=-1)
  length--;                      // decrementa um elemento na estrutura (assumindo: não há colisões)
}

void Hash::print()
{
  // Percorre todos os elementos da estrutura
  for (int i = 0; i < max_items; i++)
  {
    // Imprime RA e nome de todos os elementos (se houver algum vazio, também imprime)
    cout << i << ":" << structure[i].getRa() << ", " << structure[i].getNome() << endl;
  }
}

// Função Hash
int Hash::getHash(Aluno aluno)
{
  // Estamos assumindo nenhuma colisão.
  return aluno.getRa() % max_items;
}
