#include "aluno.h"

/* Implementação da classe Aluno */

// Construtor (vazio): usado na alocação dinâmica
Aluno::Aluno(){
  this->ra   = -1;  // indica que a posição está vazia (todos os RAs são > 0)
  this->nome = "";
}

// Construtor especificando um aluno
Aluno::Aluno(int ra, std::string nome){
  this->ra    = ra;
  this->nome  = nome;
}

// Obter o nome
string Aluno::getNome() const {
  return nome;
}

// Obter o RA
int Aluno::getRa() const{
  return ra;
}
