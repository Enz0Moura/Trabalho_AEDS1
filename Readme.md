# Introdução

Este relatório descreve o funcionamento do sistema desenvolvido para controlar uma sala de aula, lidando com o cálculo de notas e a frequência dos alunos. O sistema foi projetado utilizando tipos abstratos específicos para organizar e gerenciar os dados dos alunos, suas presenças e avaliações.

## **Estrutura do Sistema**

### Tipo Abstrato: Aluno

O tipo abstrato Aluno é no formato de lista encadeada, responsável por armazenar informações essenciais sobre cada aluno, incluindo:

* **Nome**: Nome completo do aluno.
* **Matrícula**: Um valor inteiro único que identifica o aluno.
* **Ponteiro para o Próximo Aluno**: Referência para o próximo aluno na lista encadeada.
* **Ponteiro para o Aluno Anterior**: Referência para o aluno anterior na lista encadeada.
* **Lista de Aulas**: Uma lista do tipo abstrato Aula, representando a presença ou ausência do aluno em cada aula.
* **Ponteiro para NotaAluno**: Uma referência para uma lista do tipo abstrato NotaAluno, que armazena as notas do aluno.

### Tipo Abstrato: ListaAlunos

O tipo abstrato ListaAlunos é a cabeça da lista encadeada de Aluno. Responsável por armazenar:

* **Ponteiro para cabeça**: Indica o inicio da lista encadeada ListaAluno.

### Tipo Abstrato: Aula

O tipo abstrato Aula armazena informações sobre a frequência do aluno em uma aula específica:

* **Dia**: O dia em que a aula ocorreu.
* **Presença**: Um valor booleano que indica se o aluno estava presente (True) ou ausente (False) na aula.

### Tipo Abstrato: NotaAluno

O tipo abstrato NotaAluno armazena informações sobre as notas atribuídas aos alunos:

* **Nota**: Um valor inteiro representando a nota obtida pelo aluno.
* **Ponteiro** para Aluno: Uma referência para o aluno associado a esta nota.

### Tipo Abstrato: Avaliacao

O tipo abstrato Avaliacao é no formato de lista encadeada, responsável por armazenar informações sobre as avaliações realizadas:

* **Nome da Avaliação**: O nome dado à avaliação.
* **Valor Total**: O valor total da avaliação, utilizado para calcular a nota do aluno.
* **Lista de NotaAluno**: Uma lista do tipo abstrato NotaAluno, contendo as notas de cada aluno para essa avaliação.
* **Ponteiro para próxima Avaliacao**: Referência para a próxima avaliacao na lista encadeada.
* **Ponteiro para Avaliacao anterior**: Referência para a avaliacao anterior na lista encadeada.

### Tipo Abstrato: ListaAvaliacoes

O tipo abstrato ListaAvaliacoes é a cabeça da lista encadeada de Avaliacao. Responsável por armazenar:

* **Ponteiro para cabeça**: Indica o inicio da lista encadeada ListaAvaliacoes