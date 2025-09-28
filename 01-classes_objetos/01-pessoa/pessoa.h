#pragma once
#include <string>

using namespace std;

// Definição da classe Pessoa
class Pessoa {
    // Atributos(variáveis) da classe Pessoa
    private:
        string nome;
        char sexo;
        int idade;

    // Métodos(funções) da classe Pessoa
    public:
        Pessoa();
        void setNome(const string& nome);
        void setIdade(int idade);
        string getNome();
        int getIdade();
        bool podeDirigir();
};