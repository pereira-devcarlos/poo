#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

/**
 * Exemplo de Polimorfismo em C++
 * Demonstra polimorfismo através de formas geométricas
 */

// Classe abstrata base
class Forma {
protected:
    std::string nome;

public:
    Forma(const std::string& n) : nome(n) {}
    
    // Destrutor virtual
    virtual ~Forma() = default;
    
    // Métodos virtuais puros (classe abstrata)
    virtual double calcularArea() const = 0;
    virtual double calcularPerimetro() const = 0;
    
    // Método virtual com implementação padrão
    virtual void mostrarInfo() const {
        std::cout << "Forma: " << nome << "\n";
        std::cout << "Área: " << calcularArea() << "\n";
        std::cout << "Perímetro: " << calcularPerimetro() << "\n";
    }
    
    std::string getNome() const { return nome; }
};

// Classe derivada - Retângulo
class Retangulo : public Forma {
private:
    double largura, altura;

public:
    Retangulo(double l, double a) 
        : Forma("Retângulo"), largura(l), altura(a) {}
    
    double calcularArea() const override {
        return largura * altura;
    }
    
    double calcularPerimetro() const override {
        return 2 * (largura + altura);
    }
    
    void mostrarInfo() const override {
        std::cout << "=== " << nome << " ===\n";
        std::cout << "Largura: " << largura << ", Altura: " << altura << "\n";
        Forma::mostrarInfo(); // Chama método da classe base
        std::cout << "\n";
    }
};

// Classe derivada - Círculo
class Circulo : public Forma {
private:
    double raio;
    static constexpr double PI = 3.14159265359;

public:
    Circulo(double r) : Forma("Círculo"), raio(r) {}
    
    double calcularArea() const override {
        return PI * raio * raio;
    }
    
    double calcularPerimetro() const override {
        return 2 * PI * raio;
    }
    
    void mostrarInfo() const override {
        std::cout << "=== " << nome << " ===\n";
        std::cout << "Raio: " << raio << "\n";
        Forma::mostrarInfo();
        std::cout << "\n";
    }
};

// Classe derivada - Triângulo
class Triangulo : public Forma {
private:
    double lado1, lado2, lado3;

public:
    Triangulo(double l1, double l2, double l3) 
        : Forma("Triângulo"), lado1(l1), lado2(l2), lado3(l3) {}
    
    double calcularArea() const override {
        // Fórmula de Heron
        double s = calcularPerimetro() / 2.0;
        return std::sqrt(s * (s - lado1) * (s - lado2) * (s - lado3));
    }
    
    double calcularPerimetro() const override {
        return lado1 + lado2 + lado3;
    }
    
    void mostrarInfo() const override {
        std::cout << "=== " << nome << " ===\n";
        std::cout << "Lados: " << lado1 << ", " << lado2 << ", " << lado3 << "\n";
        Forma::mostrarInfo();
        std::cout << "\n";
    }
};

// Função que demonstra polimorfismo
void processarForma(const Forma& forma) {
    std::cout << "Processando " << forma.getNome() << ":\n";
    std::cout << "Área: " << forma.calcularArea() << "\n";
    std::cout << "Perímetro: " << forma.calcularPerimetro() << "\n\n";
}

int main() {
    std::cout << "=== Exemplo de Polimorfismo ===\n\n";
    
    // Criando objetos de diferentes tipos
    Retangulo ret(5.0, 3.0);
    Circulo circ(4.0);
    Triangulo tri(3.0, 4.0, 5.0);
    
    std::cout << "--- Chamando métodos diretamente ---\n";
    ret.mostrarInfo();
    circ.mostrarInfo();
    tri.mostrarInfo();
    
    std::cout << "--- Polimorfismo com referências ---\n";
    processarForma(ret);
    processarForma(circ);
    processarForma(tri);
    
    std::cout << "--- Polimorfismo com vetor de ponteiros ---\n";
    std::vector<std::unique_ptr<Forma>> formas;
    formas.push_back(std::make_unique<Retangulo>(6.0, 4.0));
    formas.push_back(std::make_unique<Circulo>(3.0));
    formas.push_back(std::make_unique<Triangulo>(5.0, 12.0, 13.0));
    
    double areaTotal = 0.0;
    for (const auto& forma : formas) {
        forma->mostrarInfo();
        areaTotal += forma->calcularArea();
    }
    
    std::cout << "Área total de todas as formas: " << areaTotal << "\n";
    
    return 0;
}