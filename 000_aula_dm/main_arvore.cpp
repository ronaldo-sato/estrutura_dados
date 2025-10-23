#include <iostream>
// #include <string>
#include "arvore_binaria.h"

using namespace std;

int main(){

  arvoreBinariadeBusca arvoreAlunos;  // objeto vazio
  int opcao, ra, imprimir;
  string nome;
  bool busca = false;

  // usando do-while(enquanto diferente de zero: parar)
  do{
      cout << "Digite 0 para parar o programa!\n";
      cout << "Digite 1 para inserir um elemento!\n";
      cout << "Digite 2 para remover um elemento!\n";
      cout << "Digite 3 para buscar um elemento!\n";
      cout << "Digite 4 para imprimir a Arvore!\n";
      cin >> opcao;

      if (opcao == 1){
          cout << "Qual o nome do aluno?\n";
          cin >> nome;
          cout << "Qual o RA do aluno?\n";
          cin >> ra;
          Aluno aluno(ra, nome);  // cria objeto aluno
          arvoreAlunos.inserir(aluno);  // insere no vetor hash
          if (arvoreAlunos.estaCheio()){
            cout << "A Arvore esta cheia!\n";
            cout << "Nao foi possivel inserir o elemento!\n";
          } else{
            arvoreAlunos.inserir(aluno);
          }
      } else if (opcao == 2 ){
          cout << "Qual o RA do aluno a ser removido?\n";
          cin >> ra;
          Aluno aluno(ra, " ");  // criar objeto aluno sem nome
          arvoreAlunos.remover(aluno);
      } else if (opcao == 3){
          cout << "Qual o RA do aluno a ser buscado?\n";
          cin >> ra;
          Aluno aluno(ra, " ");  // criar objeto aluno sem nome
          arvoreAlunos.search(aluno, busca);
          if (busca){ // booleano
              cout << "Aluno encontrado:\n";
              cout << "RA: " << aluno.obterRa() << " ";
              cout << "Nome: " << aluno.obterNome() << endl;
          } else{
              cout << "Aluno nao encontrado!\n";
          }
      } else if (opcao == 4){
          cout << "Digite 1 para imprimir em pre ordem!\n";
          cout << "Digite 2 para imprimir em ordem!\n";
          cout << "Digite 3 para imprimir em pos ordem!\n";
          cin >> imprimir;
          if (imprimir == 1){
            cout << "Impressao Pre Ordem: ";
            arvoreAlunos.imprimirPreOrdem(arvoreAlunos.obterRaiz());
          } else if(imprimir == 2){
                cout << "Impressao Em Ordem: ";
                arvoreAlunos.imprimirEmOrdem(arvoreAlunos.obterRaiz());
          } else {
                cout << "Impressao Pos Ordem: ";
                arvoreAlunos.imprimirPosOrdem(arvoreAlunos.obterRaiz());
          }
      }
  } while(opcao != 0);

  return 0;
}