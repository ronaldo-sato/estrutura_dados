#include <iostream>

using namespace std;

// troca os valores de duas variáveis por referência, efetivamente troca os 
// valores das variáveis 
void troca_por_referencia(int &a, int &b){
  int temp;
  temp=a;
  a=b;
  b=temp;
}

int main(){

  int a = 2, b = 3;

  cout << "Antes: a = " << a << " b = " << b << endl;

  troca_por_referencia(a, b);

  cout << "Depois: a = " << a << " b = " << b << endl;

  return 0;
}
