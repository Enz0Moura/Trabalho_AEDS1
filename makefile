# Nome da biblioteca
LIBRARY = libtrabalho.a

# Compilador e flags
CC = gcc
CFLAGS = -Wall -c

# Diretórios de fontes e includes
SRC_DIRS = Aluno ListaAlunos Avaliacao Hashing Presenca SalaDeAula
OBJ_DIR = objs
INCLUDES = $(addprefix -I, $(SRC_DIRS))

# Arquivos fonte e objetos
SOURCES = $(shell find $(SRC_DIRS) -name '*.c')
OBJECTS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SOURCES))

# Alvo padrão
all: $(LIBRARY)

# Regra para criar a biblioteca estática
$(LIBRARY): $(OBJECTS)
	ar rcs $(LIBRARY) $(OBJECTS)

# Regra para compilar arquivos .c em .o, mantendo a estrutura de diretórios
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)  # Cria o diretório para o objeto se necessário
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

# Regra para criar o diretório de objetos se não existir
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Regra para limpar arquivos gerados
clean:
	rm -f $(OBJECTS) $(LIBRARY) programa
	rm -rf $(OBJ_DIR)

# Regra para compilar o programa principal com a biblioteca
programa: main.c $(LIBRARY)
	$(CC) -o programa main.c -L. -ltrabalho $(INCLUDES)
