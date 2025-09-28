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
        // Construtor (inicializa os atributos)
        Pessoa(){  
            nome = "";
            sexo = '\0';
            idade = 0;
            usaOculos = false;
        }
        
        // Retorna a idade da pessoa
        int getIdade(){
            return idade;
        };

        // Define a idade da pessoa com validação
        void setIdade(int idade){
            if(idade >= 0 && idade <= 100){
                this->idade = idade;
            } else {
                cout << "Idade inválida!" << endl;
            }
        };

        // Verifica se a pessoa pode dirigir (idade >= 18)
        bool podeDirigir(){
            if(idade >= 18){
                return true;
            } else {
                return false;
            }
        };
};

int main(){
    Pessoa p1;
    p1.setIdade(20);
    cout << "Idade: " << p1.getIdade() << endl;
    cout << "Pode dirigir? " << (p1.podeDirigir() ? "Sim" : "Não") << endl;
    
    return 0;
}
