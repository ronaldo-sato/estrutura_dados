#include <iostream>
#include <cstddef>
#include <iostream>

using namespace std;

  arvoreBinariadeBusca::arvoreBinariadeBusca()
  // construtor
  {
      raiz = NULL; // raiz null ao criar o objeto
  }

  arvoreBinariadeBusca::~arvoreBinariadeBusca()
  // destrutor (chama função deletarArvore)
  {

  }

  void arvoreBinariadeBusca::deletarArvore(No* noAtual)
  {

  }

  No* arvoreBinariadeBusca::obterRaiz()
  // obter ponteiro para o nó raiz
  {
      return raiz;
  }

  bool arvoreBinariadeBusca::estaVazio()
  {
      return (raiz == NULL); // se a raiz for null é vazia
  }

  bool arvoreBinariadeBusca::estaCheio()
  {
      try{
          // cria um nó temporário
          No* temp = new No;
          // se conseguiu criar não está cheio, então deletamos
          delete temp;
          return false;
      } catch(bad_alloc exception){
          return true;
      }
  }

  void arvoreBinariadeBusca::inserir(Aluno aluno)
  // para iserir um elemento é preciso verificar se a raiz é null (árvore 
  // vazia)
  // se for vazia, o primeiro elemento a ser inserido será a raiz
  // se não for vazia, a partir da raiz, para cada nó fazemos a verificação se
  // o elemento a ser inserido é maior que o nó, se ele for maior vai para a 
  // direita, se for menor, vai para a esquerda, até encontrar um lugar vazio
  {
      if (estaCheio()){
          cout << "A arvore esta cheia!\n";
          cout << "Não foi possível inserir o elemento.\n";
      } else{ // se tem espaço, primeiro criar um nó para o aluno
          No* noNovo = new No;
          // cada nó guarda três informações
          noNovo->aluno = aluno; // o valor
          noNovo->filhoDireita = NULL; // ponteiro para direita
          noNovo->filhoEsquerda = NULL; // ponteiro para esquerda
          // verificar que posição o novo elemento irá ficar (qual ponteiro
          // irá apontar para ele)
          if (raiz == NULL){ // se a árvore está vazia
              raiz = noNovo; // raiz aponta para novo elemento
          } else{ // verificar, em que "lado" o elemento novo irá ficar na árvore
              // criando um temporário que percorre a estrutura
              No* temp = raiz; // percorremos a partir da raiz
              while (temp != NULL){ // é inserido quando tiver espaço
                  // se o elemento que queremos inserir for menor que do nó,
                  // ele vai para esquerda
                  if (aluno.obterRa() < temp->aluno.obterRa()){
                      // se à esquerda for vazio, fica nessa posição
                      if (temp->filhoEsquerda == NULL){
                          temp->filhoEsquerda = noNovo;
                          break; // achou a posição, alocou (para o laço)
                      } else{ // se não for vazio
                          // atualiza o temporário, ele aponta para o da esquerda
                          temp = temp->filhoEsquerda; // para comparar agora com o da esquerda
                      }
                  } else{ // se for maior, ele vai para direita
                      // se à direita for vazio, fica nessa posição
                      if (temp->filhoDireita == NULL){
                          temp->filhoDireita = noNovo;
                          break; // achou a posição, alocou (para o laço)
                      } else{ // se não for vazio
                          // atualiza o temporário, ele aponta para o da direita
                          temp = temp->filhoDireita; // para comparar agora com o da direita
                  }
              }
          }

      }

  }
  
  void arvoreBinariadeBusca::remover(Aluno aluno)
  // para remover um aluno, a ideia é percorrer os nós até encontrar o 
  // elemento que queremos remover (quando não encontra, não removemos)
  // no entanto, na remoção precimos atualizar os ponteiros associados 
  // (pai e filhos), mantendo a estrutura de árvore binária;
  // assim, há alguns casos:
  // (1) Nó Folha - quando não tem filho: primeiro buscamos o elemento na
  // estrutura; e quando o elemento é um nó folha, como ele não tem filhos, 
  // os ponteiros da esquerda e da direita são nulos, mas como o pai dele 
  // aponta para ele, dependendo da posição que ele estiver (à direita ou 
  // esquerda), o respectivo ponteiro do pai também precisa ser atualizado 
  // como nulo, pois senão com a remoção esse espaço de memória fica 
  // desalocado, mas ainda com um ponteiro apontando para o local de memória
  // (2) Nó com apenas 1 filho: buscamos o elemento; e quando o elemento 
  // encontrado tem somente 1 filho, ou seja, quando um dos ponteiros 
  // associados ao filho da esquerda ou direita for nulo, como o elemento 
  // aponta para um filho, o ponteiro do pai que apontava para o elemento 
  // removido precisa ser atualizado para apontar para o filho do elemento 
  // removido
  // (3) Nó com 2 filhos: buscamos o elemento; e quando o elemento encontrado 
  // tem dois filhos, ou seja, quando os dois ponteiros não são nulos, 
  // no entanto, para manter a estrutura de árvore binária de busca, 
  // precisamos buscar o sucessor dele para ocupar o lugar do elemente a ser 
  // removido e, há duas formas de se manter a estrutura, é escolhendo o menor
  // elemento à direita (quando um elemento à esquerda, não tiver filho à 
  // esquerda, i.e., tiver ponteiro à esquerda nulo) ou o maior elemento à 
  // esquerda (quando um elemento à direita tiver ponteiro à direita nulo - 
  // não há mais elemento à direita), então esse elemento sucessor irá ocupar 
  // o lugar do que será deletado e se o sucessor não tem filho, somente 
  // atualizamos o ponteiro de filho à esquerda do nó sucessor como nulo, 
  // mas se o sucessor tiver um filho, caímos no caso (2), então o pai do 
  // sucessor precisa apontar o filho do sucessor
  // para realizar a remoção, será precisa chamar 3 métodos, o de buscar 
  // (busca) o elemento, o de remover (removerBusca) o elemento e o de 
  // encontrar o sucessor (caso 3; obterSucessor)
  {
      removerBusca(aluno, raiz);
  }

  void arvoreBinariadeBusca::removerBusca(Aluno aluno, No*& noAtual)
  // recursivamente, é feita a comparação do RA do aluno com o RA do nó atual
  // (noAtual é um ponteiro para o nó atual)
  {
      // se o elemento que buscamos for menor que o nó atual, 
      // vamos para a esquerda
      if (aluno.obterRa() < noAtual->aluno.obterRa()){
          removerBusca(aluno, noAtual->filhoEsquerda);
      // senão, vamos para a direita
      } else if (aluno.obterRa() > noAtual->aluno.obterRa()){
          removerBusca(aluno, noAtual->filhoDireita);
      // se for igual, deletamos o nó atual
      } else{
          deletarNo(noAtual); // este noAtual que vamos precisar verificar o caso
      }
  }

  void arvoreBinariadeBusca::deletarNo(No*& noAtual)
  // noAtual é um ponteiro para o nó atual que queremos deletar
  {
      No* temp = noAtual; // temp é o ponteiro para o nó que será removido
      // se o filho à esquerda for vazio (pode ou não ter filho à direita)
      if (noAtual->filhoEsquerda == NULL){
          // fazemos nó atual apontar para o filho à direita
          noAtual = noAtual->filhoDireita;
          delete temp;  // e deletamos temp
          /* OBS: não importa se tem filho à direita, se for nó folha sem filho 
          à direita (vazio), então noAtual (nó pai) irá apontar para vazio */
        // senão se o filho à direita for vazio
      } else if (noAtual->filhoDireita == NULL){
        // fazemos nó atual apontar para o filho à esquerda
        noAtual = noAtual->filhoEsquerda;
        delete temp;  // e deletamos temp
        /* não importa se não tem filhos, no caso do nó folha (sem filhos), 
        se ele não tem filho à esquerda, entra no primeiro if, e mesmo se 
        o filho à direita for vazio o nó pai (noAtual) irá apontar para vazio.
        No caso se o nó tiver um filho, e for filho à direita então cai no 
        primeiro if e se tiver filho à esquerda cai no segundo if, e em ambos 
        os casos mesmo sendo vazios o filho à esquerda ou à direita 
        respectivamente, o nó pai irá apontar para vazio. */
        // senão se tiver dois filhos (nenhum dos dois filhos é vazio)
      } else {
        /* alunoSucessor vai por referência, então o que for alterado em 
        obterSucessor será alterado aqui. Essa função irá buscar o sucessor 
        e o aluno que estiver no sucessor vai ir para alunoSucessor, então no 
        retorno da função alunoSucessor vai ser o valor que iremos trocar */
        obterSucessor(alunoSucessor)
      }

  }

  void arvoreBinariadeBusca::obterSucessor(Aluno& alunoSucessor, No* temp)
  {

  }

  void arvoreBinariadeBusca::buscar(Aluno& aluno, bool& busca)
  // por referência, se encontrar atualiza busca e aluno
  // a busca é feita percorrendo a esttrutura a partir da raiz, onde se o 
  // valor procurado for maior que o nó, vamos para direita (comparar com 
  // filhos da direita), senão vamos para a esquerda (comparar com filhos da 
  // esquerda)
  // a busca termina quando o valor é encontrado ou quando chegamos em um NULL 
  {
      // garantir que busca é false, mas se encontrar vira true   
      busca = false;
      // ponteiro para o nó para percorrer
      No* noAtual = raiz; // (raiz na verdade é um ponteiro que aponta o 1o nó)
      // percorremos a estrutura da árvore até chegar em algum nulo
      while (noAtual != NULL){
          // se o aluno que a gente procura for menor que o nó atual
          if (aluno.obterRa() < noAtual->aluno.obterRa()){
              // percorremos à esquerda
              noAtual = noAtual->filhoEsquerda;
          // porém se for maior
          } else if(aluno.obterRa() > noAtual->aluno.obterRa()){
              // percorremos à direita
              noAtual = noAtual->filhoDireita;
          // se não encontrou um menor ou maior, é porque é igual
          } else{ // então atualizamos busca 
              busca = true; // foi encontrado
              aluno = noAtual->aluno; // agora aluno também tem a informação do nome
              break; // se encontrar paramos
          }
      }
  }

  void arvoreBinariadeBusca::imprimirPreOrdem(No* noAtual)
  {


  }

  void arvoreBinariadeBusca::imprimirEmOrdem(No* noAtual)
  {

  }

  void arvoreBinariadeBusca::imprimirPosOrdem(No* noAtual)
  {

  }
