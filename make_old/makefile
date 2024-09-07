LIBRARY = libtrabalho.a

CC = gcc
CFLAGS = -Wall -c

SRC_DIRS = Aluno ListaAlunos Hashing Avaliacao Presenca SalaDeAula
OBJ_DIR = objs
INCLUDES = $(addprefix -I, $(SRC_DIRS))


SOURCES = $(shell find $(SRC_DIRS) -name '*.c')
OBJECTS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SOURCES))


all: $(LIBRARY)


$(LIBRARY): $(OBJECTS)
	ar rcs $(LIBRARY) $(OBJECTS)


$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@


$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)


clean:
	rm -f $(OBJECTS) $(LIBRARY) programa
	rm -rf $(OBJ_DIR)

programa: ../main.c $(LIBRARY)
	$(CC) -o programa main.c -L. -ltrabalho $(INCLUDES)
