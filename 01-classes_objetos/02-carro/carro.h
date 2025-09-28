#pragma once
#include <string>

using namespace std;

class Carro {
    private:
        string modelo;
        int ano;
        string cor;

    public:
        // Construtor padrão
        Carro(); 
        
        // Métodos set e get do modelo
        void setModelo(string modelo);
        string getModelo();
};