#include <iostream>

using namespace std;

// troca os valores de duas variáveis dentro da função
void troca_por_valor(int a, int b){
  int temp;
  temp = a;
  a = b;
  b = temp;
}

int main(){

  int a = 2, b = 3;

  cout << "Antes: a = "<< a <<" b = " << b << endl;

  // passando por valor o conteúdo das variáveis a e b
  // ao chamar a função troca_por_valor
  troca_por_valor(a, b);

  cout << "Depois: a = " << a << " b = " << b << endl; 
  
  return 0;
}
