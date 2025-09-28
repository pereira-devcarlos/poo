#include <iostream>
#include <string.h>
#include "carro.h"

using namespace std;

Carro::Carro() {
    modelo = "Sem modelo";
    ano = 0;
    cor = "Sem cor";
}

void Carro::setModelo(string modelo){
    this->modelo = modelo;
}

string Carro::getModelo(){
    return modelo;
}

int main() {
    Carro car1;
    car1.setModelo("Gol Bola");
    cout << "\nModelo: " << car1.getModelo();

    return 0;
}
