# Sistema de Biblioteca Universitária

## Grupo
- Daniela Tamy Yuki  
- Laura Klemba Cordeiro  
- Nathalia Lyra Albuquerque  

---

## Atividade Prática Integradora — Estruturas de Dados I  

### Enunciado da Atividade
Você foi contratado por uma biblioteca universitária para desenvolver um **sistema de gerenciamento de livros**. Seu desafio é implementar esse sistema usando **três diferentes estruturas de dados**:

1. **Lista Estática** – baseada em array com tamanho fixo  
2. **Lista Dinâmica** – baseada em array com realocação dinâmica  
3. **Lista Encadeada** – baseada em alocação individual de nós  

---

### Funcionalidades Obrigatórias
O sistema deve permitir:

- Cadastrar livros (**título, autor, ano, ISBN**)  
- Consultar livros pelo **ISBN**  
- Emprestar livros a usuários  
- Devolver livros  
- Listar todos os livros cadastrados  

---

### Estrutura dos Dados
Cada livro deve conter os seguintes campos:

| Campo           | Tipo      | Tamanho/Formato               |
|-----------------|-----------|-------------------------------|
| Título          | string    | até 100 caracteres           |
| Autor           | string    | até 100 caracteres           |
| Ano de publicação | int      | —                             |
| ISBN            | string    | 13 caracteres                 |
| Status          | enum      | DISPONIVEL ou EMPRESTADO     |
| Nome do usuário | string    | até 100 caracteres           |
| Data do empréstimo | string  | formato DD/MM/AAAA           |

---

### Etapas de Desenvolvimento

#### Etapa 1 — Planejamento
- Leia este documento com atenção  
- Analise os arquivos-base entregues pelo professor (esqueleto de código)  
- Divida as tarefas entre os integrantes  

#### Etapa 2 — Implementação (60 minutos)
- Implemente as funções solicitadas conforme a estrutura de sua equipe  
- Utilize os testes no `main.c` para validar as funcionalidades  
- Evite código duplicado e mantenha os arquivos organizados  
- Comente as funções explicando o que cada uma faz  

#### Etapa 3 — Testes e Comparação
- Teste as funcionalidades com diferentes volumes de dados  
- Verifique o comportamento da estrutura com **5, 50 e 500 livros**  
- Reflita: o desempenho muda com a quantidade de dados?  

#### Etapa 4 — Socialização e Relatório
No final da aula, cada grupo apresentará:

- A estrutura utilizada  
- As dificuldades enfrentadas  
- As vantagens/desvantagens observadas  
- Qual estrutura escolheriam para um sistema real, justificando  

---

### Relatório a ser preenchido pelo grupo
Cada grupo deve responder:

1. Qual estrutura foi implementada?  
2. Quais funcionalidades foram concluídas com sucesso?  
3. O que foi mais fácil e o que foi mais difícil?  
4. Em quais situações sua estrutura se destacaria?  
5. Qual foi o desempenho observado com 50, 500 e 5.000 livros?  
6. Quais operações foram mais custosas na sua estrutura?  
7. Você implementaria essa estrutura em um sistema real? Por quê?  
