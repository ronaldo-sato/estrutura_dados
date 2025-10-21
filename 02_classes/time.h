/*
  O arquivo .h é para a declaração da classe. Aqui veremos como se define uma 
classe. Porém, as primeiras linhas de código deste arquivo servem para evitar 
que múltiplas definições da classe Time ocorram. Isso poderia ocorrer se você 
der include de dois pacotes que dão include em "time.h". E isso geraria erro em 
tempo de compilação. Então, definir uma classe poderia ser feita sem esse 
cuidado, mas fica suscetível a erro quando a complexidade aumenta.
*/

/* Para garantir que isso não ocorra, utilizamos a diretiva #ifndef, que diz 
que se "algo" não está definido entramos no bloco delimitado a partir dessa 
diretiva até a diretiva de seu fechamento, #endif.
*/

#ifndef TIME_H // Se TIME_H não está definido, inclui o bloco aberto pelo ifndef

/* Note que dentro deste bloco temos a declaração da classe. Portanto, somente 
se TIME_H não tiver sido definido, que a classe será definida, ou seja, se não 
estiver definido entra no bloco delimitado por #ifndef até #endif. Assim, se a 
classe já estiver sido definida nem entra neste bloco (nem passa aqui).
*/

/* Entrando, logo abaixo temos a diretiva define TIME_H, que diz para definir 
TIME_H:
*/

#define TIME_H // Assim, na primeira inclusão, define TIME_H para que este bloco
               // não seja incluído mais de uma vez.

/* A seguir temos a definição da classe em si, e se não fosse usado a diretiva 
#ifndef, somente esse bloco seria sufuciente para declaração da classe, pois 
ela não utiliza nenhuma outra função de outra biblioteca.
*/

class Time { // Declaração da classe Time
  private:  // Seção Privada
    // Membros privados
    int hour;     // 0 - 23
    int minute;   // 0 - 59
    int second;   // 0 - 59
  public:   // Seção Pública
    // Construtor (inicializa os atributos ao instanciar um objeto)
    // Note que o construtor recebe três argumentos inteiros, cujos valores são
    // pré-definidos (default), portanto se nenhum valor for passado, 
    // ao instanciar um objeto utiliza esses valores: 
    Time(int hour = 0, int minute = 0, int second = 0);
    // Métodos "get" e "set" para gerenciar os atributos:
    int getHour() const;   
    void setHour(int hour);   
    int getMinute() const; 
    void setMinute(int minute); 
    int getSecond() const; 
    void setSecond(int second);
    // Método "print" para imprimir uma instância de tempo 
    // (no formato hh:mm:ss):
    void print() const;
    // Método que adiciona um segundo:
    void nextSecond();  
}; // uma classe sempre termina com ponto-e-vírgula no fim

#endif  // Final do bloco "#ifndef", portanto garante que a classe não seja 
        // incluída 2 vezes.
