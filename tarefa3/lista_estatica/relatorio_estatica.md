## Relatório – Estrutura de Lista Estática para Sistema de Biblioteca

### 1. Qual estrutura foi implementada?
Foi implementada uma **lista estática baseada em array**.
---

### 2. Quais funcionalidades foram concluídas com sucesso?
- Inicialização da lista
- Cadastro de livros
- Consulta de livros por ISBN
- Empréstimo de livros
- Devolução de livros
- Listagem de todos os livros cadastrados
- Testes de desempenho com diferentes quantidades de livros (50, 500 e 5.000).

---

### 3. O que foi mais fácil e o que foi mais difícil?
- **Mais fácil:** criar a estrutura e implementar as operações de cadastro e listagem.  
- **Mais difícil:** lidar com as limitações do tamanho fixo da lista e verificar se o livro já está emprestado.

---

### 4. Em quais situações sua estrutura se destacaria?
- Em sistemas onde o número de registros já é pré-definido, onde é necessário consultas rápidas e uma implementação simples.

---

### 5. Qual foi o desempenho observado com 50, 500 e 5.000 livros?
Para os três casos, o tempo variou na escala de milissegundos, mostrando um ótimo desempenho.

| Quantidade de Livros | Tempo Cadastro (s) | Tempo Busca (s) | Tempo Empréstimo (s) |
|-----------------------|---------------------|-----------------|-----------------------|
| 5                     | 0.000000           | 0.000000        | 0.000000              |
| 500                   | 0.000000           | 0.000000        | 0.000000              |
| 5000                  | 0.015000           | 0.000000        | 0.000000              |

---

### 6. Quais operações foram mais custosas na sua estrutura?
- **Consulta de livros por ISBN**, pois é feita de forma sequencial, sendo mais lenta conforme aumenta a quantidade de livros.  
- **Cadastro** quando a lista atinge a capacidade máxima.

---

### 7. Você implementaria essa estrutura em um sistema real? Por quê?
Devido a questão do tamanho fixo, não implementaria em uma biblioteca, visto que esse tipo de sistema tende a variar de tamanho máximo de livros.
