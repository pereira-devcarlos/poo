#include <iostream>
#include "pessoa.h"

using namespace std;

int main() {
    Pessoa pessoa1; // Cria um objeto da classe Pessoa

    // Define o nome e a idade da pessoa
    pessoa1.setNome("Ana");
    pessoa1.setIdade(20);

    // Exibe o nome e a idade da pessoa
    cout << "Nome: " << pessoa1.getNome() << endl;
    cout << "Idade: " << pessoa1.getIdade() << endl;

    // Verifica se a pessoa pode dirigir
    if(pessoa1.podeDirigir()){
        cout << pessoa1.getNome() << " pode dirigir." << endl;
    } else {
        cout << pessoa1.getNome() << " não pode dirigir." << endl;
    }

    return 0;
}