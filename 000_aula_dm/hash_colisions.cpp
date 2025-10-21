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
  // insere um aluno (com colisão - teste linear)
  // a partir da função hash (entrada aluno), 
  // busca o local (disponível) onde inserir o aluno
  // Teste linear: envolve a busca da próxima posição vazia disponível na
  // tabela, posteriormente verifica-se sequencialmente cada índice 
  // subsequente até encontrar um espaço vazio.
  {
      if (isfull()){
          cout << "A tabela Hash esta cheia|\n";
          cout << "(Atingiu o numero maximo de elementos.)";
          cout << "O elemento nao pode ser inserido.";
      } else {
          int local = funcHash(student);
          // percorre o vetor hash, enquanto a posição estiver ocupada
          while (struct_[local].getRa() > 0){
              local = (local+1) % max_positions;
          }
      }
      // será inserido na próxima livre, se vazio (-1) ou disponível (-2)
      struct[local] = student;
      n_itens++; // incrementa contador de itens
  }

  void Hash::remove(Student student)
  // remove um aluno (com colisões - teste linear)
  // através da função hash, buscar um elemento
  {
      int local = funcHash(student);
      bool test = false;
      // percorre o vetor hash, enquanto não for encontrado
      // um espaço vazio ou o próprio elemento
      while (struct_[local] != -1){
          // se achar o elemento, ele é removido (posição fica disponível)
          if (struct_[local].getRa() == aluno.getRa()){
              cout << "Elemento removido!\n";
              struct_[local] = Student(-2, " "); // disponível
              n_itens--; // decremento no contador de itens
              test = true;
              break;
          }
          local = (local+1) % max_positions;
      }
      // se não encontrar o elemento teste continua falso, 
      // então o "não teste" é verdadeiro
      if (!test){
          cout << "Elemento nao encontrado.\n";
          cout << "Nenhum elemento removido!\n";
      }
  }

  void Hash::search(Student& student, bool& found)
  // busca um aluno (com colisões)
  // passado por referência porque aqui altera o conteúdo:
  // se o aluno for encontrado atualiza found e student 
  // (busca pelo RA, apenas RA foi passado)
  {
      int local = funcHash(student);
      found = false;
      // percorre vetor hash enquanto o ra não for vazio
      while (struct_[local] != -1){
          // se ra for igual ao buscado, encontrado
          if (struc_[local].getRa() == student.getRa()){
              found = true;
              student = struct_[local]; // além do RA agora temos o nome tb
              break;
          }
          local = (local+1) % max_positions;
      }
  }

  void Hash::print()
  // imprime a tabela hash
  {
      cout << "Tabela Hash:\n";
      // percorre o vetor hash
      for (int i = 0; i < max_positions; i++){
          // se houver elemento (positivo), imprime RA e nome
          if (struct_[i] > 0){
                cout << i << ": " << struct_[i].getRa();
                cout << " " << struct_[i].getName() << endl;
          }
      }
  }
