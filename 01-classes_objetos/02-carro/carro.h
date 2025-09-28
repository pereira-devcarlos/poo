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
        
        // Métodos set's do Carro
        void setModelo(string modelo);
        void setAno(int ano);
        void setCor(string cor);
        
        // Métodos get's do Carro
        string getModelo();
        int getAno();
        string getCor();
};