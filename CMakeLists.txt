cmake_minimum_required(VERSION 3.10)

project(Trabalho)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

set(SRC_DIRS utils Aluno ListaAlunos Hashing Avaliacao Sorting Presenca SalaDeAula)

include_directories(${SRC_DIRS})

file(GLOB SOURCES ${SRC_DIRS}/*.c)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/objs)


add_library(trabalho STATIC ${SOURCES})


add_executable(programa main.c
        utils/utils.c
        ListaAlunos/listaalunos.c
        Hashing/hashing.c
        Avaliacao/avaliacao.c
        Sorting/sorting.c
        Presenca/presenca.c
        SalaDeAula/saladeaula.c
)


target_link_libraries(programa trabalho)
