#include <iostream>

using namespace std;

class Aluno{
  private:
  int ra;
  std::string nome;

  public:
  Aluno();                 // construtor vazio para alocar espaço na memória
  Aluno(int r, string n);  // construtor aluno (ra, nome)
  int obterRa();           // devolver RA do aluno
  std::string obterNome(); // devolver o nome do aluno
};
