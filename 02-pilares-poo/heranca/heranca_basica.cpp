#include <iostream>
#include <string>

/**
 * Exemplo de Herança em C++
 * Demonstra como criar classes base e derivadas
 */

// Classe base (superclasse)
class Animal {
protected:
    std::string nome;
    int idade;

public:
    // Construtor da classe base
    Animal(const std::string& n, int i) : nome(n), idade(i) {
        std::cout << "Construtor Animal chamado para: " << nome << "\n";
    }
    
    // Destrutor virtual (importante para herança)
    virtual ~Animal() {
        std::cout << "Destrutor Animal chamado para: " << nome << "\n";
    }
    
    // Métodos virtuais (podem ser sobrescritos)
    virtual void emitirSom() const {
        std::cout << nome << " faz algum som\n";
    }
    
    virtual void mover() const {
        std::cout << nome << " se move\n";
    }
    
    // Método não virtual
    void mostrarInfo() const {
        std::cout << "Nome: " << nome << ", Idade: " << idade << " anos\n";
    }
    
    // Getters
    std::string getNome() const { return nome; }
    int getIdade() const { return idade; }
};

// Classe derivada (subclasse)
class Cachorro : public Animal {
private:
    std::string raca;

public:
    // Construtor da classe derivada
    Cachorro(const std::string& n, int i, const std::string& r) 
        : Animal(n, i), raca(r) {
        std::cout << "Construtor Cachorro chamado para: " << nome << "\n";
    }
    
    // Destrutor
    ~Cachorro() {
        std::cout << "Destrutor Cachorro chamado para: " << nome << "\n";
    }
    
    // Sobrescrevendo métodos virtuais
    void emitirSom() const override {
        std::cout << nome << " late: Au au!\n";
    }
    
    void mover() const override {
        std::cout << nome << " corre feliz!\n";
    }
    
    // Método específico da classe derivada
    void buscarObjeto() const {
        std::cout << nome << " busca a bola!\n";
    }
    
    // Getter específico
    std::string getRaca() const { return raca; }
};

// Outra classe derivada
class Gato : public Animal {
public:
    Gato(const std::string& n, int i) : Animal(n, i) {
        std::cout << "Construtor Gato chamado para: " << nome << "\n";
    }
    
    ~Gato() {
        std::cout << "Destrutor Gato chamado para: " << nome << "\n";
    }
    
    void emitirSom() const override {
        std::cout << nome << " mia: Miau!\n";
    }
    
    void mover() const override {
        std::cout << nome << " caminha silenciosamente\n";
    }
    
    void escalar() const {
        std::cout << nome << " escala a árvore!\n";
    }
};

int main() {
    std::cout << "=== Exemplo de Herança ===\n\n";
    
    // Criando objetos das classes derivadas
    std::cout << "--- Criando animais ---\n";
    Cachorro dog("Rex", 3, "Golden Retriever");
    Gato cat("Mimi", 2);
    
    std::cout << "\n--- Informações básicas ---\n";
    dog.mostrarInfo();
    std::cout << "Raça: " << dog.getRaca() << "\n";
    cat.mostrarInfo();
    
    std::cout << "\n--- Comportamentos ---\n";
    dog.emitirSom();
    dog.mover();
    dog.buscarObjeto();
    
    cat.emitirSom();
    cat.mover();
    cat.escalar();
    
    std::cout << "\n--- Polimorfismo com ponteiros ---\n";
    Animal* animais[] = {&dog, &cat};
    
    for (int i = 0; i < 2; i++) {
        std::cout << "Animal " << (i+1) << ":\n";
        animais[i]->mostrarInfo();
        animais[i]->emitirSom();
        animais[i]->mover();
        std::cout << "\n";
    }
    
    std::cout << "--- Fim do programa ---\n";
    return 0;
}