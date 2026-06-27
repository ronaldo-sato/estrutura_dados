#include <iostream>
using namespace std;

/* Declaração de uma classe Aluno
para organizar os alunos de uma instituição conforme o número do aluno (RA)
e buscar o aluno (informações - aqui no caso será apenas o nome) através desse
número */

class Aluno
{
private:
  int ra;           // RA
  std::string nome; // nome
public:
  Aluno();                         // construtor vazio (para alocação dinâmica)
  Aluno(int ra, std::string nome); // construtor especificando um aluno
  string getNome() const;          // obter o nome
  int getRa() const;               // obter o RA
};
