#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <iomanip>

/**
 * Exemplo prático integrando todos os conceitos de POO
 * Sistema de gerenciamento de funcionários
 */

// Classe base abstrata
class Funcionario {
protected:
    std::string nome;
    int id;
    double salarioBase;

public:
    Funcionario(const std::string& n, int i, double s) 
        : nome(n), id(i), salarioBase(s) {}
    
    virtual ~Funcionario() = default;
    
    // Método virtual puro - cada tipo de funcionário calcula diferente
    virtual double calcularSalario() const = 0;
    
    // Método virtual com implementação padrão
    virtual void mostrarInfo() const {
        std::cout << "ID: " << id << ", Nome: " << nome 
                  << ", Salário: R$ " << std::fixed << std::setprecision(2) 
                  << calcularSalario() << "\n";
    }
    
    // Getters
    std::string getNome() const { return nome; }
    int getId() const { return id; }
    double getSalarioBase() const { return salarioBase; }
};

// Funcionário CLT
class FuncionarioCLT : public Funcionario {
private:
    double horasExtras;
    double valorHoraExtra;

public:
    FuncionarioCLT(const std::string& n, int i, double s, double he = 0, double vhe = 25.0)
        : Funcionario(n, i, s), horasExtras(he), valorHoraExtra(vhe) {}
    
    double calcularSalario() const override {
        return salarioBase + (horasExtras * valorHoraExtra);
    }
    
    void mostrarInfo() const override {
        std::cout << "[CLT] ";
        Funcionario::mostrarInfo();
        if (horasExtras > 0) {
            std::cout << "    Horas extras: " << horasExtras 
                      << " (R$ " << std::fixed << std::setprecision(2) 
                      << horasExtras * valorHoraExtra << ")\n";
        }
    }
    
    void adicionarHorasExtras(double horas) {
        horasExtras += horas;
    }
};

// Funcionário terceirizado
class Terceirizado : public Funcionario {
private:
    double horasTrabalhadas;
    double valorPorHora;

public:
    Terceirizado(const std::string& n, int i, double vph, double ht = 0)
        : Funcionario(n, i, 0), horasTrabalhadas(ht), valorPorHora(vph) {
        // Para terceirizados, salarioBase não é usado diretamente
    }
    
    double calcularSalario() const override {
        return horasTrabalhadas * valorPorHora;
    }
    
    void mostrarInfo() const override {
        std::cout << "[TERCEIRIZADO] ";
        std::cout << "ID: " << id << ", Nome: " << nome 
                  << ", Salário: R$ " << std::fixed << std::setprecision(2) 
                  << calcularSalario() << "\n";
        std::cout << "    Horas: " << horasTrabalhadas 
                  << " x R$ " << valorPorHora << "/hora\n";
    }
    
    void registrarHoras(double horas) {
        horasTrabalhadas += horas;
    }
};

// Gerente (herança de FuncionarioCLT)
class Gerente : public FuncionarioCLT {
private:
    double bonus;
    std::vector<std::shared_ptr<Funcionario>> equipe;

public:
    Gerente(const std::string& n, int i, double s, double b = 0)
        : FuncionarioCLT(n, i, s), bonus(b) {}
    
    double calcularSalario() const override {
        return FuncionarioCLT::calcularSalario() + bonus;
    }
    
    void mostrarInfo() const override {
        std::cout << "[GERENTE] ";
        std::cout << "ID: " << id << ", Nome: " << nome 
                  << ", Salário: R$ " << std::fixed << std::setprecision(2) 
                  << calcularSalario() << "\n";
        if (bonus > 0) {
            std::cout << "    Bônus: R$ " << bonus << "\n";
        }
        std::cout << "    Equipe: " << equipe.size() << " funcionários\n";
    }
    
    void adicionarFuncionario(std::shared_ptr<Funcionario> func) {
        equipe.push_back(func);
    }
    
    void setBónus(double b) { bonus = b; }
    
    double calcularFolhaPagamentoEquipe() const {
        double total = 0;
        for (const auto& func : equipe) {
            total += func->calcularSalario();
        }
        return total;
    }
};

// Template para gerenciar coleção de funcionários
template<typename T>
class GerenciadorFuncionarios {
private:
    std::vector<std::shared_ptr<T>> funcionarios;

public:
    void adicionar(std::shared_ptr<T> funcionario) {
        funcionarios.push_back(funcionario);
    }
    
    void listarTodos() const {
        std::cout << "\n=== Lista de Funcionários ===\n";
        for (const auto& func : funcionarios) {
            func->mostrarInfo();
            std::cout << "\n";
        }
    }
    
    double calcularFolhaTotal() const {
        double total = 0;
        for (const auto& func : funcionarios) {
            total += func->calcularSalario();
        }
        return total;
    }
    
    size_t getTotalFuncionarios() const {
        return funcionarios.size();
    }
    
    std::shared_ptr<T> buscarPorId(int id) const {
        for (const auto& func : funcionarios) {
            if (func->getId() == id) {
                return func;
            }
        }
        return nullptr;
    }
};

int main() {
    std::cout << "=== Sistema de Gerenciamento de Funcionários ===\n";
    
    // Criando funcionários de diferentes tipos
    auto func1 = std::make_shared<FuncionarioCLT>("João Silva", 1001, 3000.0, 10.0);
    auto func2 = std::make_shared<FuncionarioCLT>("Maria Santos", 1002, 3500.0, 5.0);
    auto func3 = std::make_shared<Terceirizado>("Pedro Costa", 2001, 30.0, 160.0);
    auto gerente = std::make_shared<Gerente>("Ana Paula", 3001, 8000.0, 2000.0);
    
    // Gerente adiciona funcionários à sua equipe
    gerente->adicionarFuncionario(func1);
    gerente->adicionarFuncionario(func2);
    gerente->adicionarFuncionario(func3);
    
    // Usando o template para gerenciar todos os funcionários
    GerenciadorFuncionarios<Funcionario> rh;
    rh.adicionar(func1);
    rh.adicionar(func2);
    rh.adicionar(func3);
    rh.adicionar(gerente);
    
    // Exibindo informações
    rh.listarTodos();
    
    std::cout << "=== Resumo Financeiro ===\n";
    std::cout << "Total de funcionários: " << rh.getTotalFuncionarios() << "\n";
    std::cout << "Folha de pagamento total: R$ " 
              << std::fixed << std::setprecision(2) 
              << rh.calcularFolhaTotal() << "\n";
    
    std::cout << "Folha da equipe do gerente: R$ " 
              << gerente->calcularFolhaPagamentoEquipe() << "\n";
    
    // Demonstrando polimorfismo
    std::cout << "\n=== Demonstração de Polimorfismo ===\n";
    std::vector<std::shared_ptr<Funcionario>> todos = {func1, func2, func3, gerente};
    
    for (const auto& funcionario : todos) {
        std::cout << funcionario->getNome() << " ganha R$ " 
                  << funcionario->calcularSalario() << "\n";
    }
    
    // Buscando funcionário por ID
    std::cout << "\n=== Busca por ID ===\n";
    auto encontrado = rh.buscarPorId(1002);
    if (encontrado) {
        std::cout << "Funcionário encontrado: " << encontrado->getNome() << "\n";
    }
    
    return 0;
}