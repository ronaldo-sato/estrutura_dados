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
    deletarArvore(raiz);  // para deletar a árvore começamos pela raiz
  }

  void arvoreBinariadeBusca::deletarArvore(No* noAtual)
  /* Para deletar a estrutura toda usamos o percurso pós-ordem, então 
  vamos deletando os nós das folhas para a raiz, recursivamente. */
  {
    /* recursivamente, vamos percorrendo os nós a partir da raiz, até encontrar
    vazio, seguindo a ordem de primeiro ir para a esquerda e depois para a
    direita, encontrando vazio deletamos o nó */ 
    if (noAtual != NULL){
        deletarArvore(noAtual->filhoEsquerda);
        deletarArvore(noAtual->filhoDireita);
        delete noAtual;
    }
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
  // (onde será inserido)
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
  // como nulo, pois senão com a remoção, esse espaço de memória do nó removido
  // fica desalocado, mas ainda com um ponteiro apontando para esse local de
  // memória
  // (2) Nó com apenas 1 filho: buscamos o elemento; e quando o elemento 
  // encontrado tem somente 1 filho, ou seja, quando um dos ponteiros 
  // associados ao filho da esquerda ou direita for nulo, como o elemento 
  // aponta para um filho, o ponteiro do pai que apontava para o elemento 
  // removido precisa ser atualizado para apontar para o filho do elemento 
  // removido
  // (3) Nó com 2 filhos: buscamos o elemento; e quando o elemento encontrado 
  // tem dois filhos, ou seja, quando os dois ponteiros não são nulos, mas
  // para manter a estrutura de árvore binária de busca, precisamos buscar o 
  // sucessor que irá ocupar o lugar do elemento que será removido e, há duas 
  // formas de se manter a estrutura, é escolhendo o menor elemento à direita 
  // (quando um elemento à esquerda, não tiver filho à esquerda, i.e., tiver 
  // ponteiro à esquerda nulo) ou o maior elemento à esquerda (quando um 
  // elemento à direita tiver ponteiro à direita nulo - não há mais elemento 
  // à direita), então esse elemento sucessor irá ocupar o lugar do que será 
  // deletado e se o sucessor não tem filho, somente atualizamos o ponteiro 
  // de filho à esquerda do nó atual como nulo, mas se o sucessor tiver um 
  // filho, caímos no caso (2), então o pai do sucessor precisa apontar o 
  // filho do sucessor
  //
  // dessa forma, para realizar a remoção, será precisa chamar 3 métodos, 
  // o de buscar (busca) um elemento, o de remover (removerBusca) o elemento e
  // o de encontrar o sucessor (caso 3; obterSucessor)
  /*
  EXEMPLOS:
  
  Suponha a estrutura:                 12
                                10             14
                                    11     13      18
                                             15  17

  Caso 1: Remover 11 -> Buscar 11 (à partir da raiz, se for maior vamos para 
  à direita, se for menor, para à esquerda; então o 11 é menor que o 12, vamos
  para à esquerda, é maior que o 10, vamos para à direita, encontramos o 11) -> 
  Deletar 11 (deletar o nó, para deletar e manter a estrutura o ponteiro do pai
  desse elemento que será deletado precisa ser atualizado, e como o elemento 
  a ser deletado é um nó folha, o ponteiro do pai precisa apontar para vazio, 
  senão o ponteiro continuará apontando para um espaço de memória que foi 
  desalocado).

  Caso 2: Remover 10 -> Buscar 10 (à partir da raiz, 10 é menor que 12, vamos 
  para à esquerda, encontramos o 10) -> Deletar 10 (como esse elemento tem 
  um filho à direita, para manter a estrutura é necessário que o ponteiro do 
  pai aponte para o filho do elemento que será removido, então fazer com que o 
  filho à esquerda do 12 seja o 11, é como se estivéssemos substituindo o 10 
  pelo 11, substituímnos só o valor, para ao final deletar o nó do 10).

  Caso 3: 
  
  (cai no caso 1) Remover 14 -> Buscar 14 (14 é maior que 12, vamos 
  para a direita, encontramos o 14) -> Buscar Sucessor (há duas formas de 
  encontrar o sucessor, mantendo a estrutura: uma é o menor elemento à direita 
  e outra é o maior elemento à esquerda; vamos escolher o menor à direita, 
  então o primeiro passo damos para a direita e depois todos os outros passos 
  possíveis para a esquerda, até encontrar o vazio, então ele é o menor 
  elemento, encontrado o sucessor 17, substituímos o 14 pelo 17 - só o valor, 
  os ponteiros serão os mesmos; como o sucessor não tem filho à direita, se 
  tivesse à esquerda ele não era o sucessor, a gente continuaria indo para a 
  esquerda, mas não tendo filho é preciso atualizar o ponteiro para o sucessor
  com vazio) -> Deletar antigo 17 (encontrado o sucessor e atualizado o nó pai, 
  deletamos o sucessor).
  
  (cai no caso 2) Remover o 12 -> Buscar 12 (ele já é a raiz, então vamos 
  deletar a raiz) -> Buscar Sucessor (seguindo o menor à direita, damos um passo
  à direita e todos os próximos à esquerda, encontramos o sucessor 13, então 
  substituímos o 12 pelo 13, apenas o valor, e como o sucessor tem filho à 
  direita o 15, precisamos atualizar o ponteiro do pai do sucessor para o 
  endereço do filho do sucessor) -> Deletar 12 (só então, deletamos o sucessor).
  */
  {
      // a partir da raiz, iremos buscar pelo aluno para removê-lo
      removerBusca(aluno, raiz);
  }

  void arvoreBinariadeBusca::removerBusca(Aluno aluno, No*& noAtual)
  /* recursivamente, faz a busca de quem será removido (aluno) e para isso
    precisamos de ponteiro de busca (o ponteiro que aponta pro elemento que
    será removido, por isso passamos o ponteiro como referência para a função,
    porque quando encontrar o elemento que será removido, esse ponteiro sendo
    por referência já vai ser o ponteiro (do pai) que aponta para o elemento
    a ser removido); então, esse ponteiro de busca que iremos chamar de 
    nó atual, ao encontrar o elemento, já teremos condições de como fazer
    o(s) devido(s) apontamento(s) do pai do elemento para os filhos (filho à
    esquerda, à direita ou null), do elemento que será removido */
  // esta é uma função recursiva, na qual vamos percorrer a estrutura à partir
  // da raiz, comparando o RA do aluno com o RA do nó atual (CUIDADO: noAtual
  // é um ponteiro para o nó atual, o elemento que será removido)
  {
      // se o elemento que buscamos for menor que o nó atual, 
      // vamos para a esquerda
      if (aluno.obterRa() < noAtual->aluno.obterRa()){
          removerBusca(aluno, noAtual->filhoEsquerda);
      // senão, se for maior, vamos para a direita
      } else if (aluno.obterRa() > noAtual->aluno.obterRa()){
          removerBusca(aluno, noAtual->filhoDireita);
      // se for igual, iremos deletar o nó atual (quando encontrarmos o nó que
      // será removido, noAtual é o ponteiro para o elemento que será removido)
      } else{
          deletarNo(noAtual); // então, este noAtual que iremos precisar
                              // verificar os casos (descritos em remover)
      }
  }

  void arvoreBinariadeBusca::deletarNo(No*& noAtual)
  // noAtual é um ponteiro para o nó atual que queremos deletar 
  {
      No* temp = noAtual; // temp é o ponteiro para o nó que será removido 
                          // (para saber quem iremos deletar após as atualizações)
      // se o filho à esquerda for vazio (pode ou não ter filho à direita)
      if (noAtual->filhoEsquerda == NULL){
        // fazemos nó atual apontar para o filho à direita
        noAtual = noAtual->filhoDireita;
        delete temp;  // e deletamos temp (o nó que queríamos remover)
        /* OBS: não importa se tem filho à direita, porque se for nó folha 
        sem filho à direita (vazio), então noAtual (nó pai) irá apontar para
        vazio */
        // senão, se o filho à direita for vazio
      } else if (noAtual->filhoDireita == NULL){
        // fazemos nó atual apontar para o filho à esquerda
        noAtual = noAtual->filhoEsquerda;
        delete temp;  // e deletamos temp
        /* não importa se não tem filhos, no caso do nó folha (sem filhos), 
        se ele não tem filho à esquerda, entra no primeiro if, e mesmo se 
        o filho à direita for vazio o nó pai (noAtual) irá apontar para vazio.
        No caso do nó tiver um filho, e for filho à direita então cai no 
        primeiro if e se tiver filho à esquerda cai no segundo if, e em ambos 
        os casos mesmo sendo vazios (o filho à esquerda ou à direita, 
        respectivamente) o nó pai irá apontar para vazio. */
        // senão, se nenhum dos filhos for vazio, ou seja, se tiver dois 
        // filhos, precisamos obter o sucessor até encontrar vazio
    } else {
        // objeto vazio apenas para guardar a informação do sucessor
        Aluno alunoSucessor;
        /* em obterSucessor, o alunoSucessor vai por referência, então o que
        for alterado em obterSucessor será alterado aqui. obterSucessor irá 
        buscar o sucessor e o aluno que estiver no sucessor vai ir para 
        alunoSucessor, então no retorno da função, alunoSucessor vai ser o 
        valor que iremos trocar (o valor que vai para o nó atual) */
        /* assim, vamos instanciar um alunoSucessor para receber o valor que
        iremos remover (após atribuir no nó que iremos "remover"); perceba 
        que queremos deletar um nó, mas para manter a estrutura, precisamos 
        deslocar o sucessor para o atual, e no fundo depois removemos o 
        sucessor */
        obterSucessor(alunoSucessor, noAtual);
        /* Obtendo o aluno sucessor, o nó atual está apontando para quem 
        queremos "remover", então trocamos o valor dele pelo sucessor dele */ 
        noAtual->aluno = alunoSucessor;
        /* e então para deletar o sucessor, chamamos remover busca a partir 
        do filho à direita do nó atual, já que agora como o valor do nó atual
        já está atualizado com o valor do sucessor, basta buscarmos o sucessor
        a partir do filho à direita do nó atual, que iremos encontrar e deletar
        o sucessor */
        removerBusca(alunoSucessor, noAtual->filhoDireita);
        /* OBS: removerBusca é a função recursiva que irá encontrar um nó, 
        encontrando ela chama esta função aqui deletarNo, mas como o sucessor
        ou tem nenhum filho ou tem um filho não entrará neste else de caso tenha
        dois filhos (o sucessor nunca vai ter dois filhos, senão continuaríamos
        a busca pois a condição de ser sucessor é ter encontrado um vazio) */
      }

  }

  void arvoreBinariadeBusca::obterSucessor(Aluno& alunoSucessor, No* temp)
  /* Aqui iremos obter o sucessor do nó atual, seguindo a premissa do menor
     elemento à direita, para manter a estrutura de árvore binária */
  {
    /* o nó temp vai receber o nó atual, então para seguir a premissa, 
    primeiro damos o passo para à direita */
    temp = temp->filhoDireita;
    // depois vamos tudo que for possível para à esquerda, até encontrar vazio
    while (temp->filhoEsquerda != NULL) {
        temp = temp->filhoEsquerda;  // encontrando vazio, temp é o sucessor
    }
    /* Então como temp é o sucessor, atribuímos o valor aluno de temp no
    alunoSucessor, que veio por referência, assim, quando voltar para 
    a função deletarNo será exatamente o aluno que está no sucessor
    */
    alunoSucessor = temp->aluno;
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

  /* As funções a seguir imprimir"AlgumaCoisa", são sobre percursos. E percurso
  é percorrer todos os nós da árvore. A diferença entre essas funções é em como 
  percorrer a árvore, ou em que ordem vamos percorrer a estrutura. Há outras 
  formas, mas aqui será implementado as 3 formas principais.

  Como em nossa estrutura cada nó será uma informação de RA de um aluno, a 
  cada visita de um nó iremos imprimir / informar esse RA.

  Como exemplo, vamos usar a seguinte estrutura:

                     4
               1           6
                  3     5     7
                2 
  */
  void arvoreBinariadeBusca::imprimirPreOrdem(No* noAtual)
  /* Esta função é recursiva, a cada visita de um nó iremos imprimir 
  o valor e em seguida seguir sempre a ordem de primeiro visitar o filho 
  à esquerda, depois visitar o filho à direita.

  Suponha a seguinte estrutura:

                     4
               1           6
                  3     5     7
                2 

  Seguindo a estrutura acima, a partir da raiz, chegamos no primeiro nó e 
  imprimimos o 4, primeiro o filho da esquerda do 4, é o 1, imprimimos ele, 
  depois filho da esquerda do 1, que é vazio, e então filho da direita do 1, 
  que é o 3, imprimimos ele, depois filho da esquerda do 3, é o 2, imprimimos 
  ele, filho da esquerda do 2 é vazio e filho da direita também, então voltamos 
  ao último na visitado, que é o filho da direita do 3, que é vazio, o último 
  não visitado é o filho da direita do 4, que é o 6, imprimimos ele, depois 
  filho da esquerda do 6, é o 5, imprimimos ele, depois filho da esquerda do 5
  é vazio e filho da direita também, ficou faltando visitar o filho da direita
  do 6, temos o 7, imprimimos ele, como ele não tem filhos, como não tem mais 
  nenhum elemento não visitado, paramos. 

  Então aqui é impresso: 4, 1, 3, 2, 6, 5, 7
  */
  {
    // recursivamente, vamos chamar os elementos na ordem a seguir até
    // encontrar vazio
    if (noAtual != NULL){
        /* percorremos a estrutura sempre nessa ordem, ao visitar imprimimos,
        se tem filho à esquerda, visitamos ele (imprimimos ele), quando não tem,
        seguindo essa ordem, chamamos o filho à direita, não tendo, chamamos o
        último elemento não visitado */
        
        // visita noAtual;  // Como a visita é antes, é chamada de pré-ordem
        cout << noAtual->aluno.obterNome() << ": ";
        cout << noAtual->aluno.obterRa() << endl;

        imprimirPreOrdem(noAtual->filhoEsquerda);
        imprimirPreOrdem(noAtual->filhoDireita);
        /* Então aqui cada elemento é impresso antes dos filhos */
    }

  }

  void arvoreBinariadeBusca::imprimirEmOrdem(No* noAtual)
  /* Aqui a recursão segue a ordem de primeiro chamar o filho à esquerda, 
  depois visitar o nó e por último chamar o filho à direita.  

  Suponha a seguinte estrutura:

                     4
               1           6
                  3     5     7
                2 

  Seguindo a estrutura acima, a partir da raiz, chegamos no primeiro nó o
  elemento 4, primeiro o filho da esquerda do 4, é o 1, em seguida filho da 
  esquerda do 1, não tem, então imprimimos o 1, depois filho da direita do 1,
  é o 3, em seguida filho da esquerda do 3 é o 2, que não tem filho à esquerda,
  então imprimimos o 2, depois filho à direita do 2, também não tem filho, o 
  último não visitado é o filho à direita do 3, também não tem, depois o último
  não visitado é o 4, imprimimos ele, depois o último não visitado é o filho à
  direita do 4, que é o 6, chamamos o filho à esquerda do 6, é o 5, chamamos o
  filho à esquerda do 5, não tem, imprimimos o 5, depois chamamos o filho à 
  direita do 5, também não tem, o último não visitado é o 6, imprimimos ele, 
  depois o último não visitado é o filho à direita do 6, que é o 7, ele não tem
  filho à esquerda, então imprimimos o 7, depois filho à direita do 7, também
  não tem, e como não tem mais nenhum elemento não visitado, paramos.

  Então aqui é impresso: 1, 2, 3, 4, 5, 6, 7
  */
  {
    // recursivamente, vamos chamar os elementos na ordem a seguir até
    // encontrar vazio
    if (noAtual != NULL){
        /* percorremos a estrutura sempre nessa ordem, ao chegar em um nó, 
        chamamos o filho à esquerda, se não tiver, visitamos o nó (imprimimos
        ele), depois chamamos o filho à direita, se não tiver, chamamos o 
        último elemento não visitado */
        // aqui seguindo essa ordem, cada elemento será impresso depois que 
        // imprimir o filho da esquerda
        imprimirEmOrdem(noAtual->filhoEsquerda);

        // visita noAtual;  // Como a visita é no meio, é chamada de em ordem
        cout << noAtual->aluno.obterNome() << ": ";
        cout << noAtual->aluno.obterRa() << endl;

        imprimirEmOrdem(noAtual->filhoDireita);
        /* Então aqui primeiro imprime o menor (filho à esquerda), depois o 
        elemento e por último o maior (filho à direita), por isso, já que é uma
        árvore binária de busca, fica ordenado */
    }
  }

  void arvoreBinariadeBusca::imprimirPosOrdem(No* noAtual)
  /* Aqui a recursão segue a ordem de primeiro chamar o filho à esquerda, 
  depois chamar filho à direita e por último visitar o nó (imprimir).  

  Suponha a seguinte estrutura:

                     4
               1           6
                  3     5     7
                2 

  Seguindo a estrutura acima, a partir da raiz, chegamos no primeiro nó o
  elemento 4, primeiro o filho da esquerda do 4, é o 1, em seguida filho da 
  esquerda do 1, não tem, então filho da direita do 1, é o 3, seguimos filho
  da esquerda do 3, é o 2, então filho da esquerda do 2, não tem, filho da 
  direita do 2, também não tem, então imprimimos o 2, o último não visitado 
  é o filho da direita do 3, que não tem, então imprimimos o 3, depois o 
  último não visitado é o 1, então imprimimos ele, depois o último não visitado 
  é o filho à direita do 4, que é o 6, então filho da esquerda do 6, é o 5, 
  filho da esquerda do 5, não tem, filho da direita do 5, também não tem, 
  então imprimimos o 5, depois o último não visitado é o filho à direita do 6,
  que é o 7, este não tem filho à esquerda e nem filho à direita, então 
  imprimimos o 7, depois o último não visitado é 6, imprimimos ele, e por 
  último faltou visitar o 4, então imprimimos ele, e como não tem mais ninguém 
  para ser visitado, paramos.

  Então aqui é impresso: 2, 3, 1, 5, 7, 6, 4
  */
  {
    // recursivamente, vamos chamar os elementos na ordem a seguir até
    // encontrar vazio
    if (noAtual != NULL){
        imprimirPosOrdem(noAtual->filhoEsquerda);
        imprimirPosOrdem(noAtual->filhoDireita);

        // visita noAtual;  // Como a visita é depois, é chamada de pós-ordem
        cout << noAtual->aluno.obterNome() << ": ";
        cout << noAtual->aluno.obterRa() << endl;

        /* Então aqui cada elemento é impresso depois dos filhos */
    }
  }
