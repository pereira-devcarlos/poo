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

// Retorna o nome da pessoa
string Pessoa::getNome() {
    return nome;
}

// Retorna a idade da pessoa
int Pessoa::getIdade() {
    return idade;
}  

// Verifica se a pessoa pode dirigir (idade >= 18)
bool Pessoa::podeDirigir(){
    return idade >= 18;
}

int main(){
    // Construindo um objeto da classe Pessoa
    Pessoa p1;

    // Testando os métodos da classe Pessoa
    p1.setNome("Joao");
    p1.setIdade(20);
    cout << "Nome: " << p1.getNome() << endl;
    cout << "Idade: " << p1.getIdade() << endl;
    cout << "Pode dirigir? " << (p1.podeDirigir() ? "Sim" : "Nao") << endl;

    return 0;
}