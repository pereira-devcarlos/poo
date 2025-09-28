# Exemplos Práticos

Este diretório contém exemplos práticos que integram múltiplos conceitos de POO em situações reais.

## sistema_funcionarios.cpp

Um sistema completo de gerenciamento de funcionários que demonstra:

### Conceitos Aplicados
- **Classes Abstratas**: `Funcionario` como classe base abstrata
- **Herança**: `FuncionarioCLT`, `Terceirizado`, `Gerente`
- **Polimorfismo**: Diferentes implementações de `calcularSalario()`
- **Encapsulamento**: Atributos privados/protegidos com métodos de acesso
- **Templates**: `GerenciadorFuncionarios<T>` para gerenciar coleções
- **Smart Pointers**: Uso de `std::shared_ptr` para gerenciamento de memória
- **STL**: Uso de `std::vector` e outros containers

### Funcionalidades
- Diferentes tipos de funcionários (CLT, Terceirizado, Gerente)
- Cálculo automático de salários com regras específicas
- Gerenciamento de equipes
- Sistema de busca por ID
- Relatórios financeiros
- Demonstração de polimorfismo em tempo de execução

## Como compilar e executar

```bash
# Usando o Makefile
make compile FILE=exemplos-praticos/sistema_funcionarios.cpp
make run PROG=sistema_funcionarios

# Ou compilação manual
g++ -std=c++17 -Wall -Wextra -o sistema_funcionarios sistema_funcionarios.cpp
./sistema_funcionarios
```

## Estrutura do Sistema

```
Funcionario (abstrata)
├── FuncionarioCLT
│   └── Gerente
└── Terceirizado

GerenciadorFuncionarios<T> (template)
```

## Exercícios Sugeridos

1. **Adicione novos tipos de funcionário**:
   - Estagiário (com salário fixo mensal)
   - Comissionado (salário base + comissão por vendas)

2. **Implemente novos recursos**:
   - Sistema de promoções
   - Histórico de salários
   - Relatórios por departamento

3. **Adicione persistência**:
   - Salvar/carregar dados de arquivo
   - Serialização em JSON

4. **Melhore o sistema**:
   - Interface de usuário interativa
   - Validação de dados de entrada
   - Sistema de logs

## Conceitos Demonstrados em Ação

- **Abstração**: A classe `Funcionario` define a interface comum
- **Encapsulamento**: Dados protegidos com métodos de acesso controlado
- **Herança**: Reutilização de código e especialização de comportamentos
- **Polimorfismo**: Comportamentos diferentes para o mesmo método
- **Templates**: Código genérico reutilizável
- **RAII**: Gerenciamento automático de recursos com smart pointers