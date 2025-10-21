#include "student.h"

  Student::Student()
  // construtor vazio (hash) para alocar espaço na memória
  {
      ra = -1;
      name = " ";
  }

  Student::Student(int r, string n)
  // construtor aluno(ra, nome)
  {
      ra = r;
      name = n;
  }

  int Student::getRa()
  {
      return ra;
  }

  string Student::getName()
  {
      return name;
  }
