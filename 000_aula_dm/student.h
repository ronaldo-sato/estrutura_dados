#include <iostream>

using namespace std;

class Student{
  private:
  int ra;   // número do estudante
  string name; // nome do estudante

  public:
  Student();                // construtor vazio (hash) para alocar espaço na memória
  Student(int r, string n); // construtor aluno (ra, nome)
  int getRa();              // devolver RA do aluno
  string getName();         // devolver o nome do aluno
};