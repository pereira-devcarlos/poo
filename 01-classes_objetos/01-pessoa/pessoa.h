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
        // Métodos construtores
        Pessoa();
        Pessoa(const Pessoa& copiar);

        // Métodos set's
        void setNome(const string& nome);
        void setSexo(char sexo);
        void setIdade(int idade);
        void setHab(bool habilitacao);

        // Métodos get's
        string getNome();
        char getSexo();
        int getIdade();
        bool podeDirigir();

        // Outros métodos
        void imprimir();
};