#include <iostream>

using namespace std; // para não precisar usar std:: quando usar qualquer padrão
// traz todos os nomes do namespace padrão para o escopo do programa 

int main() {
  int number1;
  int counter = 0;
  int amount  = 0;

  while (counter < 10) {

    cout << "Digite um número (" << counter << ")" << endl;
    cin >> number1;

    if (number1 < 5) {
      amount++;
    }
    counter++;
  }

  cout << "Quantidade de Números Menores que 5: [" << amount <<  "]" << endl;

  return 0;
}
