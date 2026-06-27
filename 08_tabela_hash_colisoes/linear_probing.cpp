#include "hash.h"
#include <iostream>
using namespace std;

Hash::Hash(int max)
{
  length = 0;
  max_items = max;
  structure = new Aluno[max_items];
}

Hash::~Hash()
{
  delete[] structure;
}

bool Hash::isFull() const
{
  return (length == max_items);
}

int Hash::getLength() const
{
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
  int startLoc = getHash(aluno); // a posição retornada pela função hash é apenas o início da busca
  bool moreToSearch = true;      // se continua a busca ou não
  int location = startLoc;       // a busca será iterada sobre location
  do
  { // enquanto houver posição para procurar, será feita a busca
    // condição para parar a busca
    if (structure[location].getRa() == aluno.getRa() || // se o RA é encontrado ou
        structure[location].getRa() == -1)              // é encontrada um posição vazia (-1)
      moreToSearch = false;                             // assim não é preciso buscar
    else                                                // senão
      location = (location + 1) % max_items;            // iremos buscar na próxima posição
  } while (location != startLoc && moreToSearch); // então, a busca é feita enquanto não
  // encontrar o RA ou uma posição vazia e, se a posição não for a do início, ou seja,
  // até completar a volta (se voltar pro começo para)

  // Ao sair do laço, se o RA da posição for igual ao RA buscado
  found = (structure[location].getRa() == aluno.getRa());
  if (found)
  {                              // se o aluno foi encontrado
    aluno = structure[location]; // a informação estará disponível onde teve a chamada da função
  }
}

void Hash::insertItem(Aluno aluno)
{
  /* Recebe o aluno por parâmetro
     A ideia é inserir esse aluno na primeira posição não ocupada, ou seja,
     seja uma posição vazia (-1) ou disponível (-2) */
  int location;
  location = getHash(aluno);
  while (structure[location].getRa() > 0)
    location = (location + 1) % max_items;
  // Ao encontrar uma posição não ocupada
  structure[location] = aluno; // insere o aluno nessa posição (aqui estamos assumindo um vetor
  // que não faltará posições, ele não ficará cheio, ou seja, o usuário alocou espaço suficiente)
  length++;
}

void Hash::deleteItem(Aluno aluno)
{
  /* Aqui a ideia é a mesma que retrieveItem, será feita a busca até encontrar a
  posição do RA procurado ou uma posição vazia, isso é feito enquanto não se chegar
  na posição inicial */
  int startLoc = getHash(aluno);
  bool moreToSearch = true;
  int location = startLoc;
  do
  {
    if (structure[location].getRa() == aluno.getRa() ||
        structure[location].getRa() == -1)
      moreToSearch = false;
    else
      location = (location + 1) % max_items;
  } while (location != startLoc && moreToSearch);

  // Ao parar a busca, se o RA da posição for a do aluno procurado
  if (structure[location].getRa() == aluno.getRa())
  {
    structure[location] = Aluno(-2, ""); // essa posição fica como disponível (-2), ou seja,
    // dessa forma, numa eventual busca isso permite que a busca seja feita para todos os elementos
    length--; // decrementa um elemento na estrutura
  }
}

void Hash::print()
{
  for (int i = 0; i < max_items; i++)
  {
    cout << i << ":" << structure[i].getRa() << ", " << structure[i].getNome() << endl;
  }
}

int Hash::getHash(Aluno aluno)
{
  return aluno.getRa() % max_items;
}
