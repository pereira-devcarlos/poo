#include <iostream>
#include "01-pessoa/pessoa.h"
#include "02-carro/carro.h"

using namespace std;

int main(){
    // Criação dos objetos
    Pessoa p1; 
    Carro car1;

    // Preenche os dados de p1
    p1.setNome("Carlos");
    p1.setSexo('M');
    p1.setIdade(20);
    p1.setHab(true);
    
    // Criação de mais objetos
    Pessoa p2, p3;
    p2.preencher();
    
    p3.copiar(p2);
    
    // Imprime os dados das pessoas
    p1.imprimir();
    p2.imprimir();
    p3.imprimir();

    // Preenche os dados do carro
    car1.setModelo("Golf");
    car1.setAno(2016);
    car1.setCor("Preto");

    // Verifica se as pessoas podem dirigir
    cout << endl;
    cout << p1.getNome() << " ";
    car1.dirigir(p1.podeDirigir());

    cout << p2.getNome() << " ";
    car1.dirigir(p2.podeDirigir());

    return 0;
}
