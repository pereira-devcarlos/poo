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

void Carro::setAno(int ano){
    if (ano > 1890 && ano <= 2025){
        this->ano = ano;
    } else {
        cout << "\nErro: ano invalido" << endl;
    }
}

void Carro::setCor(string cor){
    this->cor = cor;
}

string Carro::getModelo(){
    return modelo;
}

int Carro::getAno(){
    return ano;
}

string Carro::getCor(){
    return cor;
}

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
