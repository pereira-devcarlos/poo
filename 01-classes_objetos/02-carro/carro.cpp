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

void Carro::setAno(int ano){
    if (ano > 1890 && ano <= 2025){
        this->ano = ano;
    } else {
        cout << "\nErro: ano invalido" << endl;
    }
}

int Carro::getAno(){
    return ano;
}

int main() {
    Carro car1;

    // Testando os métodos da classe carro
    car1.setModelo("Gol Bola");
    car1.setAno(2010);
    cout << "\nModelo: " << car1.getModelo();
    cout << "\nAno: " << car1.getAno() << endl;

    return 0;
}
