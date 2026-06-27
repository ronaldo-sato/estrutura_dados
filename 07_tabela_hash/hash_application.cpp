#include <iostream>
#include "hash.h"

using namespace std;

int main()
{
  Hash alunosHash(10); // vetor de 10 elementos
  // 7 RAs e 3 com colisão (terminando com 4)
  int ras[7] = {
      12704, 31300, 1234,
      49001, 52202, 65606,
      91234};
  string nomes[7] = {
      "Pedro", "Raul", "Paulo",
      "Carlos", "Lucas", "Maria",
      "Samanta"};

  // Iterando sobre todos esses RAs e Nomes para inserir na tabela Hash
  for (int i = 0; i < 7; i++)
  {
    Aluno aluno = Aluno(ras[i], nomes[i]);
    alunosHash.insertItem(aluno);
  }
  alunosHash.print();
  cout << "------------------------------" << endl;

  // Procurar pelo aluno com o RA (12704) da primeira colisão
  // Esse aluno é Pedro, que é substituído por Paulo ao colidir,
  // que por conseguinte é substituído por Samanta
  Aluno aluno(12704, "");
  bool found = false;
  alunosHash.retrieveItem(aluno, found);
  cout << aluno.getNome() << " -> " << found << endl;
  // Portanto RA 12704 não é encontrado

  cout << "------------------------------" << endl;

  // Tentaremos remover, esse mesmo aluno 12704
  // Lembrando que ao colidir o elemento é substituído, então,
  // Paulo que havia colidido com Pedro, também é substituído
  // pela Samanta. Ou seja, como não é feito nenhuma verificação
  // a Samanta (RA=91234), será apagada, porque aluno(12704, "")
  // é a posição
  alunosHash.deleteItem(aluno);
  alunosHash.print();
  cout << "Fim" << endl;
}
