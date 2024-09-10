# Relatório Sistema de Controle Sala de Aula

**Pedro Henrique Farias Silveira, Enzo Alcantara Moura**  
September 2024  

## Introdução

O relatório a seguir documenta a implementação e o funcionamento de um sistema para controle de uma sala de aula com no máximo 100 (cem) alunos. Serão descritos detalhadamente a seguir os Tipos Abstratos de Dados (TADs) criados, bem como as funções implementadas para manipulá-los.

## Estrutura do Sistema

### TAD: Aluno

O tipo abstrato aluno faz o papel de um nó em uma estrutura no formato de lista encadeada, onde cada nó dessa lista representa um aluno específico e armazena informações essenciais a respeito dele, tais como:

- `char name` - Vetor de caracteres de tamanho MAXTAM (100) que contém o nome completo do aluno.
- `int mat` - Valor inteiro único que identifica o aluno, utilizado para representar a matrícula.
- `char curso[MAXTAM]` - String que armazena o curso do aluno.
- `int anoEntrada` - Armazena o ano em que o aluno entrou.
- `Aluno *prox` - Referência para o próximo aluno da lista.
- `int somaNotas` - Armazena a soma de todas as notas do aluno.

### TAD: ListaAlunos

O TAD ListaAluno é a estrutura da lista encadeada de alunos. Responsável por armazenar:

- `Aluno *cabeca` - Ponteiro para o nó do tipo aluno que representa o começo da lista (primeiro aluno).
- `Aluno *fim` - Ponteiro para o último nó do tipo aluno inserido na lista.

### TAD: Dia

Estrutura de lista encadeada que guarda informações sobre uma aula e a presença dos alunos.

- `int dia` - O dia em que a aula ocorreu.
- `Presenca *cabeca` - Ponteiro para o primeiro nó da lista encadeada dia.

### TAD: Presenca

É o nó da lista encadeada Dia.

- `Aluno *aluno` - Ponteiro para o aluno ao qual essa presença se refere.
- `bool foi` - Armazena 1 se o aluno estava presente e 0 se estava ausente.
- `struct presenca *prox` - Ponteiro para a próxima presença do dia.

### TAD: NotaAluno

O tipo abstrato NotaAluno armazena as informações sobre as notas atribuídas ao aluno.

- `int nota` - Um valor do tipo `float` que representa a nota obtida pelo aluno.
- `Aluno *aluno` - Referência para o aluno associado a essa nota.

### TAD: Avaliacao

O TAD Avaliação faz o papel de um nó de uma estrutura no formato de lista encadeada, onde cada nó armazena informações a respeito de uma prova realizada.

- `char nome[MAXLEN]` - Vetor de caracteres que armazena o nome da avaliação (MAXLEN é definido como 100).
- `float valortotal` - Valor do tipo `float` que representa o valor total da avaliação.
- `NotaAluno notas[MAXLEN]` - Um vetor do tipo abstrato NotaAluno, contendo as notas de cada aluno para essa avaliação.
- `struct avaliacao *prox` - Referência para a próxima avaliação na lista.

### TAD: ListaAvaliacoes

ListaAvaliacoes é a estrutura da lista encadeada de avaliações. Responsável por armazenar:

- `Avaliacao *cabeca` - Referência à primeira avaliação da lista.

### TAD: SalaDeAula

Estrutura utilizada para representar uma sala de aula (turma) e armazenar os alunos, as avaliações e as aulas.

- `TabelaHashAluno *alunos` - Tabela hash onde são armazenados os alunos.
- `ListaAvaliacoes *avaliacoes` - Lista encadeada com todas as avaliações cadastradas.
- `Aulas aulas` - Tipo Aulas é um vetor de ponteiros para Dia, logo aulas armazena todas as aulas (presenças) cadastradas.

### TabelaHashAluno

Tabela Hash utilizada para armazenar os alunos cadastrados, possibilitando um acesso e uma inserção com complexidade O(1). O tratamento de colisões implementado foi o encadeamento externo.

- `ListaAlunos *tabela[TABLE_SIZE]` - Estrutura propriamente dita da tabela, um vetor de ponteiros para ListaAlunos.
- `int indices_validos[TABLE_SIZE]` - Vetor utilizado para armazenar quais posições da tabela já estão ocupadas.
- `int contador_indices` - Variável auxiliar para saber quantos índices válidos teremos que percorrer para imprimir toda a tabela.

## Funções

### `void gerar_matricula(Aluno *aluno)`

Recebe um ponteiro para aluno e gera a matrícula do mesmo por meio de uma soma ponderada dos caracteres do nome e do curso multiplicada pelo ano de entrada do aluno.

### `int hash(int matricula)`

Função hash de divisão aplicada à matrícula de um aluno. Escolhida por sua simplicidade e desempenho satisfatório.

### `void insere_tabela_aluno(TabelaHashAluno *tabela, Aluno *aluno)`

Recebe uma tabela de alunos e um ponteiro para aluno, e insere o aluno na tabela, tratando as colisões com encadeamento aberto.

### `Aluno *encontra_aluno(TabelaHashAluno *tabela)`

Solicita ao usuário o nome, o curso e o ano de entrada do aluno que ele deseja encontrar, acessa esse aluno na tabela hash e retorna o ponteiro para ele.

### `void percorrer_tabela(TabelaHashAluno *tabela)`

Percorre a tabela hash, imprimindo as informações de matrícula, nome, curso e ano de entrada de cada aluno.

### `void verificaFaltas(Aluno *aluno)`

Recebe um ponteiro para aluno e verifica se ele atingiu a marca de dez faltas, imprimindo um aviso se for o caso.

### `void addFalta(Aluno *aluno, char c)`

Recebe um ponteiro para aluno e um caractere (presença ou ausência). Se ausente, incrementa a quantidade de faltas do aluno.

### `void cadastraAluno(SalaDeAula *turma)`

Solicita ao usuário as informações do aluno e insere-o na tabela de alunos da turma. Se houverem avaliações ou presenças cadastradas, solicita notas e presenças do aluno.

### `void cadastraAvaliacao(SalaDeAula *turma)`

Solicita o nome da avaliação, valor total e cadastra a nova avaliação na lista. Se houverem alunos cadastrados, solicita a nota de cada um.

### `void realizaChamada(SalaDeAula *turma)`

Solicita a data da aula, a presença dos alunos e insere esse Dia no vetor de dias da turma.

### `void relatorioAlunos(SalaDeAula *turma)`

Solicita ao usuário o campo de ordenação e o algoritmo de ordenação (merge sort ou selection sort). Em seguida, imprime o relatório conforme as preferências do usuário.

### `void relatorioNotas(SalaDeAula *turma)`

Pergunta ao usuário o nome da avaliação para gerar o relatório. Imprime a maior nota, a menor, a nota média e todas as notas dos alunos.

### `void imprimirListasOrdenadas(TabelaHashAluno *tabela, int (*compara)(Aluno *, Aluno *), const char algoritmo)`

Recebe a tabela hash e ordena-a em uma lista auxiliar com o algoritmo de ordenação especificado.

### `main`

A função main implementa um menu que permite ao usuário interagir com o programa, executando as tarefas solicitadas.

## Decisões

Algumas decisões importantes tomadas ao longo do projeto:

- A criação de uma tabela hash de alunos, utilizando a matrícula como chave, calculada a partir de atributos do aluno, foi essencial para a eficiência dos relatórios.
- Utilizamos a soma ponderada dos códigos ASCII do nome do aluno, curso e ano de matrícula para minimizar colisões.
- Presença e avaliações utilizam listas encadeadas simples, visto que o acesso direto não é necessário.
- A estrutura `SalaDeAula` encapsula todas as outras TADs, tornando o projeto mais legível.
- O uso de um vetor auxiliar de índices inseridos na tabela hash melhorou o desempenho do relatório de alunos.
- Hash de divisão foi utilizada por sua simplicidade e desempenho satisfatório.
- Dois algoritmos de ordenação foram implementados: selection sort (O(n²)) e merge sort (O(nlogn)).
