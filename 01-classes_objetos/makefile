# Compila os subprojetos e execulta o programa principal
# Usar no windows com PowerShell

# Define o shell para PowerShell
SHELL = powershell.exe

all: programa

programa:
# Cria a pasta build se não existir
	@if (!(Test-Path build)) { mkdir build }

# Compila os arquivos fonte e gera o executável
	@g++ .\main.cpp .\01-pessoa\pessoa.cpp .\02-carro\carro.cpp -o .\build\programa.exe

# Executa o programa
	@.\build\programa.exe


########################################
##   Se estiver no linux, use bash	  ##
########################################

# SHELL = /bin/bash

# Usar no linux com bash
# Cria a pasta build se não existir
#	mkdir -p build

# Compila os arquivos fonte e gera o executável
#	g++ main.cpp 01-pessoa/pessoa.cpp 02-carro/carro.cpp -o build/programa

# Executa o programa
#	./build/programa