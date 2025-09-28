#include <iostream>
#include "carro.h"

using namespace std;

int main() {
    Carro car1;

    // Testando os métodos set's da classe carro
    car1.setModelo("Gol Bola");
    car1.setAno(2010);
    car1.setCor("Preto");

    // Testando os métodos get's da classe carro
    cout << "\nModelo: " << car1.getModelo();
    cout << "\nAno: " << car1.getAno();
    cout << "\nCor: " << car1.getCor() << endl; 

    return 0;
}