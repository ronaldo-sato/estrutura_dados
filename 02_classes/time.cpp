/*
Implementação da classe Time

Modela uma instância de tempo e uma instância dessa classe tem três atributros: 
hora, minuto e segundo.
*/

#include <iostream>  // Para usar a função padrão de saída std::cout

#include "time.h"    // Para incluir a classe Time (declarada no .h)

/*
  Como a inclusão da classe é a partir de um arquivo que não faz parte do 
próprio C++, a inclusão é feita usando aspas, porém acima, como a inclusão de 
iostream é uma biblioteca do próprio C++, o include é feita utilizando os
colchetes angulares <>.
*/

using namespace std; // Para escrever cout ao invés de std::cout

/* 
Getters
*/

/*
  OBS: Abaixo, na implementação dos métodos, note que há o operador "::" entre
o nome da classe e o nome do método pertencente a essa classe. Esse operador 
indica a resolução do escopo, então indica que é um método da classe Time.
*/

/*
  Note que a declaração do primeiro método "get" inicia dizendo o tipo do 
retorno do método (no caso um inteiro), depois temos a resolução do escopo 
"Time::" seguido do nome do método "getHour()" (como é um método delimita os 
argumentos com parênteses, no caso não recebe nenhum como entrada, então vazio),
e como esse método não irá alterar a hora, ou alterar o valor da hora não será 
permitido, têm-se a palavra reservada "const" antes do bloco do método em si, 
ou seja, isso garante que se for tentado modificar o valor, isso não será feito.
*/

int Time::getHour() const {
  return hour; // Apenas retorna o valor do atributo hour
}

int Time::getMinute() const {
  return minute; // retorna o valor de minute
}

int Time::getSecond() const {
  return second; // retorna o valor de second
}

/*
  Nos métodos "set", o método da classe está recebendo como parâmetro uma
variável com o mesmo nome do atributo da classe. Esse fato faz com que o
atributo fique "escondido", já que dentro do método quando usarmos a variável 
"hour", estaremos nos referindo ao parâmetro e não ao atributo da classe.

  Assim, para contornar esse problema, usamos a palavra reservada "this", 
que significa "o objeto atual". Portanto:

this->hour, this->minute e this->second se referem aos atributos da classe (do 
objeto atual), e 

hour, minute e second se referem aos parâmetros dos métodos abaixo.
*/

/*
  Setters
*/
void Time::setHour(int hour) {
  this->hour = hour; // a hora recebida como parâmetro será armazenada no 
                     // atributo de mesmo nome da instância atual
}

void Time::setMinute(int minute) {
  this->minute = minute; // armazena o parâmetro minute no atributo minute
}

void Time::setSecond(int second){
  this->second = second; // armazena o parâmetro second no atributo second
}

void Time::print() const { // imprime no formato hh:mm:ss
  cout << hour << ":" << minute << ":" << second << endl;
}

void Time::nextSecond() {
  second += 1;        // adiciona um segundo
  if (second >= 60) { // como temos 60 segundos, se chegar nesse valor
    second = 0;       // zeramos os segundos
    minute += 1;      // e atualizamos os minutos, adicionando um minuto
  }
  if (minute >= 60) { // como temos 60 minutos, se chegar nesse valor
    minute = 0;       // zeramos os minutos
    hour += 1;        // e adicionamos uma hora
  }
  if (hour >= 24) {   // como temos 24 horas (não estamos lidando com os dias)
    hour = 0;         // zeramos as horas (dia seguinte)
  }
}

/*
Deixei o construtor para o fim para você conhecer uma sintaxe
alternativa para inicialização de atributos. Colocamos uma lista de
inicialização após a declaração dos parâmetros. Para separar os
parâmetros da lista de inicialização, usamos ":". A lista possui a
sintaxe:

atributo1(parâmetroA), atributo2(parâmetroB), ..., atributoN(parâmetroM).
*/

Time::Time(int h, int m, int s) : hour(h), minute(m), second(s) {
  /*
  O corpo do método executa após as inicializações. Neste caso, ele
  está vazio porque as inicialiações eram tudo o que queríamos
  fazer.
  */  
}
