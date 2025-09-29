#include <iostream>
#include "01-pessoa/pessoa.h"
#include "02-carro/carro.h"

using namespace std;

int main(){
    Pessoa p1; 
    Carro car1;

    p1.setNome("Carlos");
    p1.setSexo('M');
    p1.setIdade(20);
    p1.setHab(true);
    p1.imprimir();

    Pessoa p2, p3;
    p2.preencher();
    p2.imprimir();

    p3.copiar(p2);
    p3.imprimir();

    car1.setModelo("Golf");
    car1.setAno(2016);
    car1.setCor("Preto");

    cout << endl;
    cout << p1.getNome() << " ";
    car1.dirigir(p1.podeDirigir());

    cout << p2.getNome() << " ";
    car1.dirigir(p2.podeDirigir());

    return 0;
}
