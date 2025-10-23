#include <iostream>
#include "aluno.h";

struct No{
  // cada nó precisa guardar 3 informações:
  Aluno aluno; // o objeto aluno, criamos usando a classe Aluno
  // e ponteiros para os nós filhos da esquerda e direita
  No* filhoEsquerda;
  No* filhoDireita;
};

class arvoreBinariadeBusca{ // BST - Binary Search Tree
  private:
  No* raiz; // ponteiro que aponta para a raiz da árvore
  public:
  arvoreBinariadeBusca();  // construtor
  ~arvoreBinariadeBusca(); // destrutor (chama função deletarArvore)
  void deletarArvore(No* noAtual);
  No* obterRaiz(); // obter ponteiro para o nó raiz
  bool estaVazio();
  bool estaCheio();
  void inserir(Aluno aluno);
  void remover(Aluno aluno);  // chama a função removerBusca
  void removerBusca(Aluno aluno, No*& noAtual);  // (função recursiva até encontrar o nó:) chama a função deletarNo
  void deletarNo(No*& noAtual);  // chama a função obterSucessor
  void obterSucessor(Aluno& alunoSucessor, No* temp);
  void buscar(Alluno& aluno, bool& busca); // por referência, se encontrar atualiza busca e aluno
  void imprimirPreOrdem(No* noAtual);
  void imprimirEmOrdem(No* noAtual);
  void imprimirPosOrdem(No* noAtual);
};
