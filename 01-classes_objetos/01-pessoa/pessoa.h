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
    void setNome(const string& nome);
    void setIdade(int idade);
    string getNome();
    int getIdade();
    bool podeDirigir();
};