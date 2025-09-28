#include <iostream>
#include "01-pessoa/pessoa.h"
#include "02-carro/carro.h"

using namespace std;

int main(){
    Pessoa p1, p2;
    Carro car1;

    p1.setNome("Carlos");
    p1.setIdade(20);
    p1.setHab(true);

    p2.setNome("Ana");
    p2.setIdade(18);

    car1.setModelo("Golf");
    car1.setAno(2016);
    car1.setCor("Preto");

    cout << p1.getNome() << " ";
    car1.dirigir(p1.podeDirigir());

    cout << p2.getNome() << " ";
    car1.dirigir(p2.podeDirigir());

    return 0;
}
