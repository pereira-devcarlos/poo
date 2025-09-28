# Classes e Objetos

Este diretório contém exemplos básicos de como definir e usar classes em C++.

## Conceitos Abordados

### pessoa.cpp
- **Definição de classe**: Como declarar uma classe com atributos e métodos
- **Construtores**: Construtor padrão e construtor com parâmetros
- **Destrutores**: Limpeza automática de recursos
- **Encapsulamento básico**: Atributos privados com métodos públicos de acesso
- **Getters e Setters**: Métodos para acessar e modificar atributos privados
- **Validação**: Como adicionar validação nos setters

## Como compilar e executar

```bash
# Usando o Makefile do projeto
make compile FILE=01-conceitos-fundamentais/classes-objetos/pessoa.cpp

# Executar
make run PROG=pessoa

# Ou compilação manual
g++ -std=c++17 -Wall -Wextra -o pessoa pessoa.cpp
./pessoa
```

## Saída Esperada

```
=== Exemplo de Classes e Objetos ===

Construtor padrão chamado
Construtor parametrizado chamado para: Carlos

--- Estado inicial ---
Nome: , Idade: 0 anos
Nome: Carlos, Idade: 25 anos

--- Modificando pessoa1 ---
Nome: Ana, Idade: 30 anos

--- Testando validação ---
Idade não pode ser negativa!

--- Fim do programa ---
Destrutor chamado para: Ana
Destrutor chamado para: Carlos
```

## Exercícios Sugeridos

1. Adicione um atributo `email` à classe `Pessoa`
2. Implemente validação para o email
3. Crie um método `aniversario()` que incrementa a idade
4. Adicione um construtor de cópia