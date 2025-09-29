#include <iostream>
#include "pessoa.h"

using namespace std;

/** Métodos a fazer 
 * * * * * * * * * * * 
 * Construtor de cópia (feita)
 * Imprimir            (feita)
 * Copiar
 * Preencher           (feita)
 */

// Implementação dos métodos da classe Pessoa
// Construtor padrão da classe Pessoa
Pessoa::Pessoa() {
    nome = "Sem nome";
    sexo = 'M';
    idade = 0;
    habilitacao = false;
}

// Construtor de cópia da classe Pessoa
Pessoa::Pessoa(const Pessoa& copiar){
    this->nome = copiar.nome;
    this->sexo = copiar.sexo;
    this->idade = copiar.idade;
    this->habilitacao = copiar.habilitacao;
}

// Preenche os dados da pessoa
void Pessoa::preencher(){
    string nome;
    char sexo;
    int idade;
    bool habilitacao;

    cout << "\nPreencha os dados da pessoa:" << endl;
    cout << "Nome: ";
    cin >> nome;
    setNome(nome);

    cout << "Sexo (M/F): ";
    cin >> sexo;
    sexo = toupper(sexo);
    setSexo(sexo);

    cout << "Idade: ";
    cin >> idade;
    setIdade(idade);

    cout << "Habilitacao (1 - sim / 0 - nao): ";
    cin >> habilitacao;
    setHab(habilitacao);
}

// Define o nome da pessoa
void Pessoa::setNome(const string& nome){
    this->nome = nome;
}

void Pessoa::setSexo(char sexo){
    this->sexo = sexo;
}

// Define a idade da pessoa com validação
void Pessoa::setIdade(int idade){
    if(idade >= 0 && idade <= 100){
        this->idade = idade;
    } else {
        cout << "Idade inválida!" << endl;
    }
}

void Pessoa::setHab(bool habilitacao){
    this->habilitacao = habilitacao;
}

// Retorna o nome da pessoa
string Pessoa::getNome() {
    return nome;
}

char Pessoa::getSexo() {
    return sexo;
}

// Retorna a idade da pessoa
int Pessoa::getIdade() {
    return idade;
}  

// Verifica se a pessoa pode dirigir (idade >= 18)
bool Pessoa::podeDirigir(){
    return habilitacao;
}

void Pessoa::imprimir(){
    cout << "\nNome: " << getNome() << endl;
    cout << "Sexo: " << getSexo() << endl;
    cout << "Idade: " << getIdade() << endl;
    cout << "Habilitacao: " << podeDirigir() << endl;
}