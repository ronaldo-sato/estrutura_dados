#include "aluno.h"

/* Declaração da classe Hash - Abstração dos dados */

class Hash
{
public:
  Hash(int max_items = 100); // construtor
  ~Hash();                   // destrutor
  bool isFull() const;       // se está cheio
  int getLength() const;     // informa o tamanho

  void retrieveItem(Aluno &aluno, bool &found); // obter um aluno
  void insertItem(Aluno aluno);                 // inserir um aluno
  void deleteItem(Aluno aluno);                 // remover um aluno
  void print();                                 // imprimir a tabela
private:
  int getHash(Aluno aluno); // obter a chave de um aluno
  int max_items;            // tamanho máximo da estrutura
  int length;               // número de elementos (que estão) na estrutura
  Aluno *structure;         // vetor de alunos
};
