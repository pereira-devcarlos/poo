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
        bool habilitacao;

    // Métodos(funções) da classe Pessoa
    public:
        Pessoa();
        Pessoa(const Pessoa& copiar);
        void setNome(const string& nome);
        void setSexo(char sexo);
        void setIdade(int idade);
        void setHab(bool habilitacao);
        string getNome();
        int getIdade();
        bool podeDirigir();
};