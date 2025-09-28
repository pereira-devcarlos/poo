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

void Carro::dirigir(bool habilitacao){
    if (habilitacao){
        cout << "pode digirir esse " << this->getModelo() << endl;
    } else {
        cout << "nao pode dirigir, pois nao possui habilitacao!" << endl;
    }
}