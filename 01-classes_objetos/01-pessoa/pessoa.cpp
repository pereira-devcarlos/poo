#include <iostream>
#include "pessoa.h"

using namespace std;

// Implementação dos métodos da classe Pessoa
// Construtor padrão da classe Pessoa
Pessoa::Pessoa() {
    nome = "Sem nome";
    sexo = 'M';
    idade = 0;
    usaOculos = false;
}

// Define o nome da pessoa
void Pessoa::setNome(const string& nome){
    this->nome = nome;
}

// Define a idade da pessoa com validação
void Pessoa::setIdade(int idade){
    if(idade >= 0 && idade <= 100){
        this->idade = idade;
    } else {
        cout << "Idade inválida!" << endl;
    }
}

int main(){
    Pessoa p1;
    p1.setNome("João");
    p1.setIdade(20);

    return 0;
}