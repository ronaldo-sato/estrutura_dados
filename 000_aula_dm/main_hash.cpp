#include <iostream>
#include "hash.h"

using namespace std;

int main(){
  cout << "Gerador de Hash (sem colisoes):\n";
  int length_array, max;
  cout << "Digite o tamanho da Hash:\n";
  cin >> length_array;
  cout << "Digite o numero maximo de elementos:\n";
  cin >> max;
  cout << "O fator de carga e: " << (float)max / (float)length_array << endl;
  Hash hashStudent(length_array, max);
  int option;
  int ra;
  string name;
  bool found;

  do{
      cout << "Digite 0 para parar o programa!\n";
      cout << "Digite 1 para inserir um elemento!\n";
      cout << "Digite 2 para remover um elemento!\n";
      cout << "Digite 3 para buscar um elemento!\n";
      cout << "Digite 4 para imprimir a Hash!\n";
      cin >> option;

      if (option == 1){
          cout << "Qual o RA do aluno?\n";
          cin >> ra;
          cout << "Qual o nome do aluno?\n";
          cin >> name;
          Student student( ra, name); // cria objeto aluno
          hashStudent.inserir(student); // insere no vetor hash
      } else if (option == 2 ){
          cout << "Qual o RA do aluno a ser removido?\n";
          cin >> ra;
          Student student(ra, " "); // criar objeto aluno sem nome
          hashStudent.remove(student);
      } else if (option == 3){
          cout << "Qual o RA do aluno a ser buscado?\n";
          cin >> ra;
          Student student(ra, " "); // criar objeto aluno sem nome
          hashStudent.search(student, found);
          if (found){ // booleano
              cout << "Aluno encontrado:\n";
              cout << "RA: " << student.getRa() << " ";
              cout << "Nome: " << student.getName() << endl;
          } else{
              cout << "Aluno nao encontrado!\n";
          }
      } else if (option == 4){
          hashStudent.print();
      }
  } while(option != 0);

  return 0;
}