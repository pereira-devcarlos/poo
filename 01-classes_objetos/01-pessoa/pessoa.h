#pragma once
#include <string>

using namespace std;

class Pessoa {
private:
    string nome;
    char sexo;
    int idade;
    bool usaOculos;
public:
    Pessoa();
    int getIdade();
    void setIdade(int idade);
    bool podeDirigir();
};