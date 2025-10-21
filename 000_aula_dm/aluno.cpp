#include "aluno.h"

  Aluno::Aluno()
  // construtor vazio (hash) para alocar espaço na memória
  {
      ra = -1;
      nome = " ";
  }

  Aluno::Aluno(int r, string n)
  // construtor aluno(ra, nome)
  {
      ra = r;
      nome = n;
  }

  int Aluno::obterRa()
  {
      return ra;
  }

  string Aluno::obterNome()
  {
      return nome;
  }
