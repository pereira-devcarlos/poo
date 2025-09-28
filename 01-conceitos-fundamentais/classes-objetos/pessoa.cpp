#include <iostream>
#include <string>

/**
 * Exemplo básico de classe em C++
 * Demonstra a definição de uma classe simples com atributos e métodos
 */
class Pessoa {
private:
    std::string nome;
    int idade;

public:
    // Construtor padrão
    Pessoa() : nome(""), idade(0) {
        std::cout << "Construtor padrão chamado\n";
    }
    
    // Construtor com parâmetros
    Pessoa(const std::string& n, int i) : nome(n), idade(i) {
        std::cout << "Construtor parametrizado chamado para: " << nome << "\n";
    }
    
    // Destrutor
    ~Pessoa() {
        std::cout << "Destrutor chamado para: " << nome << "\n";
    }
    
    // Métodos públicos (getters)
    std::string getNome() const {
        return nome;
    }
    
    int getIdade() const {
        return idade;
    }
    
    // Métodos públicos (setters)
    void setNome(const std::string& n) {
        nome = n;
    }
    
    void setIdade(int i) {
        if (i >= 0) {
            idade = i;
        } else {
            std::cout << "Idade não pode ser negativa!\n";
        }
    }
    
    // Método para exibir informações
    void mostrarInfo() const {
        std::cout << "Nome: " << nome << ", Idade: " << idade << " anos\n";
    }
};

int main() {
    std::cout << "=== Exemplo de Classes e Objetos ===\n\n";
    
    // Criando objetos usando diferentes construtores
    Pessoa pessoa1; // Construtor padrão
    Pessoa pessoa2("Carlos", 25); // Construtor parametrizado
    
    std::cout << "\n--- Estado inicial ---\n";
    pessoa1.mostrarInfo();
    pessoa2.mostrarInfo();
    
    // Modificando atributos usando setters
    std::cout << "\n--- Modificando pessoa1 ---\n";
    pessoa1.setNome("Ana");
    pessoa1.setIdade(30);
    pessoa1.mostrarInfo();
    
    // Testando validação
    std::cout << "\n--- Testando validação ---\n";
    pessoa1.setIdade(-5); // Deve mostrar erro
    
    std::cout << "\n--- Fim do programa ---\n";
    return 0;
    // Destrutores são chamados automaticamente aqui
}