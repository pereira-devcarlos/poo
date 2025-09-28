# Herança

Este diretório contém exemplos de herança em C++, um dos pilares fundamentais da POO.

## Conceitos Abordados

### heranca_basica.cpp
- **Classe Base (Animal)**: Define comportamentos e atributos comuns
- **Classes Derivadas (Cachorro, Gato)**: Herdam da classe base e adicionam comportamentos específicos
- **Especificador protected**: Permite acesso por classes derivadas
- **Métodos virtuais**: Permitem sobrescrita e polimorfismo
- **Destrutor virtual**: Garante destruição correta em hierarquias
- **Override**: Palavra-chave moderna para sobrescrita explícita
- **Polimorfismo básico**: Uso de ponteiros da classe base

## Como compilar e executar

```bash
# Usando o Makefile
make compile FILE=02-pilares-poo/heranca/heranca_basica.cpp
make run PROG=heranca_basica

# Ou compilação manual
g++ -std=c++17 -Wall -Wextra -o heranca_basica heranca_basica.cpp
./heranca_basica
```

## Saída Esperada

```
=== Exemplo de Herança ===

--- Criando animais ---
Construtor Animal chamado para: Rex
Construtor Cachorro chamado para: Rex
Construtor Animal chamado para: Mimi
Construtor Gato chamado para: Mimi

--- Informações básicas ---
Nome: Rex, Idade: 3 anos
Raça: Golden Retriever
Nome: Mimi, Idade: 2 anos

--- Comportamentos ---
Rex late: Au au!
Rex corre feliz!
Rex busca a bola!
Mimi mia: Miau!
Mimi caminha silenciosamente
Mimi escala a árvore!

--- Polimorfismo com ponteiros ---
Animal 1:
Nome: Rex, Idade: 3 anos
Rex late: Au au!
Rex corre feliz!

Animal 2:
Nome: Mimi, Idade: 2 anos
Mimi mia: Miau!
Mimi caminha silenciosamente

--- Fim do programa ---
Destrutor Cachorro chamado para: Rex
Destrutor Animal chamado para: Rex
Destrutor Gato chamado para: Mimi
Destrutor Animal chamado para: Mimi
```

## Exercícios Sugeridos

1. Adicione uma classe `Passaro` que herde de `Animal`
2. Implemente um método `voar()` específico para pássaros
3. Crie uma hierarquia mais profunda (ex: `Canario` herdando de `Passaro`)
4. Experimente com herança múltipla