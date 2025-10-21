#include <iostream>
# include "hash.h"

using namespace std;

  Hash::funcHash(Student student)
  // função hash
  // devolve a posição:
  // ra % tamanho do vetor
  {
      return (student.getRa() % max_positions)
  }

  Hash::Hash(int length_array, int max)
  // função construtora
  // usuário define tamanho do vetor e tamanho 
  {
      n_itens = 0;
      max_itens = max;
      max_positions = length_array;
      // cria o vetor hash
      struct_ = new Student[length_array];  // estrutura de alunos
  }

  Hash::~Hash()
  // função destrutora
  {
      delete [] struct_; // libera todo o espaço de memória associado
  }

  bool Hash::isfull()
  // verifica se o vetor está cheio
  // cheio se a quantidade de itens no vetor 
  // for igual a quantidade máxima de itens
  {
      return (n_itens == max_itens);
  }

  bool Hash::getLength()
  // retorna o tamanho atual do vetor
  {
      return (n_itens);
  }

  void Hash::insert(Student student)
  // insere um aluno (sem colisão)
  // a partir da função hash (entrada aluno), 
  // busca o local onde inserir o aluno
  {
      int local = funcHash(student);
      struct[local] = student; // sem colisões
      n_itens++; // incrementa o contador de itens
  }

  void Hash::remove(Student student)
  // remove um aluno (sem colisões)
  {
      int local = funcHash(student);
      // se a posição não for vazia, remove
      if (struct_[local].getRa() != -1){
          struct_[local] = Student(-1, " "); // sem colisões
          n_itens--; // decremento no contador de itens
      }
  }

  void Hash::search(Student& student, bool& found)
  // busca um aluno (sem colisões)
  // passado por referência porque aqui altera o conteúdo
  // se o aluno for encontrado, atualiza found e student
  // (busca pelo RA, apenas RA foi passado)
  {
      int local = funcHash(student);
      // cria objeto auxiliar
      Student aux = struct_[local]
      // se os RAs forem diferentes não foi encontrado
      if (student.getRa() != aux.getRa()){
          found = false;
      } else{
          found = true;
          // atualiza aluno (cópia de aux)
          student = aux; // além do RA agora temos o nome tb
      }
  }

  void Hash::print()
  // imprime a tabela hash
  {
      cout << "Tabela Hash:\n";
      // percorre o vetor hash
      for (int i = 0; i < max_positions; i++){
          // se houver elemento (positivo), imprime RA e nome
          if (struct_[i] != -1){
                cout << i << ": " << struct_[i].getRa();
                cout << " " << struct_[i].getName() << endl;
          }
      }

  }
