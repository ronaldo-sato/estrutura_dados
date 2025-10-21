#include "student.h"

class Hash{
  private:
  // apenas a própria classe hash chama a função hash
  // função hash transforma a chave em valor inteiro (posição de entrada)
  // recebe como entrada o objeto da classe Student e devolve a posição
  // (cada chave é um aluno)
  int funcHash(Student student);
  // fator de carga (máximo de itens / máximo de posições):
  int max_itens;     // máximo de itens (número máximo de elememtos)
  int max_positions; // máximo de posições (tamanho máximo do vetor)
  int n_itens;       // número de itens no vetor, inserção +1, remoção -1
  Student* struct_;  // vetor hash, que contém elementos da classe Student

  public:
  Hash(int length_array, int max); // função construtora
  ~Hash(); // função destrutora
  bool isfull(); // verificar se vetor está cheio
  bool getLength(); // retorna o tamanho atual do vetor
  void insert(Student student); // insere um aluno
  void remove(Student student); // remove um aluno
  void search(Student& student, bool& found); // procura um aluno
  void print(); // imprime a tabela hash
};
