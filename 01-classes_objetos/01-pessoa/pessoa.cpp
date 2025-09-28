#include <iostream>
#include "pessoa.h"

using namespace std;

// Implementação dos métodos da classe Pessoa
// Construtor padrão da classe Pessoa
Pessoa::Pessoa() {
    nome = "Sem nome";
    sexo = 'M';
    idade = 0;
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