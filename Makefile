# Makefile para projetos de POO em C++

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g
TARGET_DIR = bin
SRC_DIRS = 01-conceitos-fundamentais 02-pilares-poo 03-conceitos-avancados exemplos-praticos

# Criar diretório bin se não existir
$(TARGET_DIR):
	mkdir -p $(TARGET_DIR)

# Compilar um arquivo específico
# Uso: make compile FILE=caminho/para/arquivo.cpp
compile: $(TARGET_DIR)
	$(CXX) $(CXXFLAGS) -o $(TARGET_DIR)/$(basename $(notdir $(FILE))) $(FILE)

# Compilar todos os arquivos .cpp encontrados
all: $(TARGET_DIR)
	find . -name "*.cpp" -exec $(CXX) $(CXXFLAGS) -o $(TARGET_DIR)/{} {} \;

# Limpar arquivos compilados
clean:
	rm -rf $(TARGET_DIR)

# Executar um programa compilado
# Uso: make run PROG=nome_do_programa
run:
	./$(TARGET_DIR)/$(PROG)

.PHONY: compile all clean run