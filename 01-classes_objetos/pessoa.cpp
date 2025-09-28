#include <iostream>

using namespace std;

// Definição da classe Pessoa
class Pessoa {
    // Atributos da classe (características)
    private: // private: só a própria classe pode acessar
        string nome;
        char sexo;
        int idade;
        bool usaOculos;

    // Métodos da classe (comportamentos)
    public: // public: qualquer um pode acessar
        Pessoa(){  // Construtor (inicializa os atributos)
            nome = "";
            sexo = '\0';
            idade = 0;
            usaOculos = false;
        }
};

int main(){
    Pessoa p1;
    
    return 0;
}
