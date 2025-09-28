#include <iostream>
#include <string>
#include <stdexcept>

/**
 * Exemplo de Templates em C++
 * Demonstra templates de classe e função
 */

// Template de classe - Container genérico
template<typename T, size_t Tamanho = 10>
class Container {
private:
    T dados[Tamanho];
    size_t tamanhoAtual;

public:
    Container() : tamanhoAtual(0) {
        std::cout << "Container criado com capacidade: " << Tamanho << "\n";
    }
    
    // Adicionar elemento
    void adicionar(const T& item) {
        if (tamanhoAtual >= Tamanho) {
            throw std::overflow_error("Container cheio!");
        }
        dados[tamanhoAtual++] = item;
    }
    
    // Obter elemento por índice
    T& obter(size_t indice) {
        if (indice >= tamanhoAtual) {
            throw std::out_of_range("Índice inválido!");
        }
        return dados[indice];
    }
    
    const T& obter(size_t indice) const {
        if (indice >= tamanhoAtual) {
            throw std::out_of_range("Índice inválido!");
        }
        return dados[indice];
    }
    
    // Operador [] para acesso similar a array
    T& operator[](size_t indice) {
        return obter(indice);
    }
    
    const T& operator[](size_t indice) const {
        return obter(indice);
    }
    
    // Métodos de informação
    size_t tamanho() const { return tamanhoAtual; }
    size_t capacidade() const { return Tamanho; }
    bool vazio() const { return tamanhoAtual == 0; }
    bool cheio() const { return tamanhoAtual >= Tamanho; }
    
    // Método para exibir todos os elementos
    void mostrar() const {
        std::cout << "Container [" << tamanhoAtual << "/" << Tamanho << "]: ";
        for (size_t i = 0; i < tamanhoAtual; i++) {
            std::cout << dados[i];
            if (i < tamanhoAtual - 1) std::cout << ", ";
        }
        std::cout << "\n";
    }
};

// Template de função - encontrar máximo
template<typename T>
T encontrarMaximo(const T& a, const T& b) {
    return (a > b) ? a : b;
}

// Template de função com múltiplos parâmetros
template<typename T>
T encontrarMaximo(const T& a, const T& b, const T& c) {
    return encontrarMaximo(encontrarMaximo(a, b), c);
}

// Especialização de template para strings
template<>
std::string encontrarMaximo<std::string>(const std::string& a, const std::string& b) {
    std::cout << "Usando especialização para strings\n";
    return (a.length() > b.length()) ? a : b;
}

// Template de classe especializada
template<typename T>
class Calculadora {
public:
    static T somar(const T& a, const T& b) {
        return a + b;
    }
    
    static T multiplicar(const T& a, const T& b) {
        return a * b;
    }
};

// Especialização para strings
template<>
class Calculadora<std::string> {
public:
    static std::string somar(const std::string& a, const std::string& b) {
        return a + " + " + b;
    }
    
    static std::string multiplicar(const std::string& a, const std::string& b) {
        return a + " * " + b;
    }
};

int main() {
    std::cout << "=== Exemplo de Templates ===\n\n";
    
    // Container de inteiros
    std::cout << "--- Container de inteiros ---\n";
    Container<int, 5> containerInt;
    
    for (int i = 1; i <= 4; i++) {
        containerInt.adicionar(i * 10);
    }
    containerInt.mostrar();
    
    std::cout << "Elemento no índice 2: " << containerInt[2] << "\n";
    std::cout << "Tamanho: " << containerInt.tamanho() << "\n\n";
    
    // Container de strings
    std::cout << "--- Container de strings ---\n";
    Container<std::string, 3> containerStr;
    containerStr.adicionar("C++");
    containerStr.adicionar("Java");
    containerStr.adicionar("Python");
    containerStr.mostrar();
    
    // Testando template de função
    std::cout << "--- Templates de função ---\n";
    std::cout << "Máximo entre 10 e 20: " << encontrarMaximo(10, 20) << "\n";
    std::cout << "Máximo entre 3.14 e 2.71: " << encontrarMaximo(3.14, 2.71) << "\n";
    std::cout << "Máximo entre 5, 8, 3: " << encontrarMaximo(5, 8, 3) << "\n";
    
    // Especialização para strings
    std::cout << "Máximo entre 'C++' e 'Java': " 
              << encontrarMaximo(std::string("C++"), std::string("Java")) << "\n\n";
    
    // Calculadora template
    std::cout << "--- Calculadora template ---\n";
    std::cout << "Soma de inteiros: " << Calculadora<int>::somar(5, 3) << "\n";
    std::cout << "Multiplicação de doubles: " 
              << Calculadora<double>::multiplicar(2.5, 4.0) << "\n";
    std::cout << "Soma de strings: " 
              << Calculadora<std::string>::somar("Hello", "World") << "\n";
    
    // Testando exceções
    std::cout << "\n--- Testando tratamento de erros ---\n";
    try {
        containerInt.adicionar(50);
        containerInt.adicionar(60); // Deve causar exceção
    } catch (const std::overflow_error& e) {
        std::cout << "Erro capturado: " << e.what() << "\n";
    }
    
    return 0;
}