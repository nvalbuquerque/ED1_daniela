# Sistema de Biblioteca Universitária

## Grupo
- Daniela Tamy Yuki  
- Laura Klemba Cordeiro  
- Nathalia Lyra Albuquerque  

---

# Relatório de Implementação da Lista Dinâmica de Livros

## 1. Qual estrutura foi implementada?
- Foi implementada uma **Lista Linear Dinâmica**  
- Cada elemento (nó) contém um livro e um ponteiro para o próximo nó.  
- A lista não possui tamanho fixo, permitindo inserir qualquer quantidade de livros durante a execução.

---

## 2. Quais funcionalidades foram concluídas com sucesso?
- Inicialização da lista 
- Cadastro de livros 
- Busca de livro por isbn
- Registro de empréstimo de livro pelo isbn
- Regitro de devolução do livro pelo isbn 
- Medição do tempo de execução de cada operação.

---

## 3. O que foi mais fácil e o que foi mais difícil?
**Mais fácil:**  
- Criar a estrutura básica da lista e cadastrar livros.  
- Inicializar campos de cada livro e inserir na lista.

**Mais difícil:**  
- Garantir que a busca e o empréstimo funcionassem corretamente 
- Medir o tempo de execução de forma precisa 
- Gerenciar memória
- Comparação de string

---

## 4. Em quais situações sua estrutura se destacaria?
- Quando o número de livros não é conhecido previamente
- Inserções e remoções frequentes
- Sistemas que precisam de uma estrutura flexível, sem limite de tamanho fixo.

---

## 5. Qual foi o desempenho observado com 50, 500 e 5.000 livros?
- **50 livros:** operações quase instantâneas (milissegundos).  
- **500 livros:** operações rápidas, mas a busca começa a demorar um pouco, pois percorre a lista sequencialmente.  
- **5.000 livros (estimativa):** busca e empréstimo perceptivelmente mais lentos, tempo cresce proporcionalmente ao número de elementos

---

## 6. Quais operações foram mais custosas na sua estrutura?
- **Busca por ISBN**  
- **Empréstimo de livro**  

Ambas são operações lineares, pois podem percorrer toda a lista até encontrar o elemento.  
O cadastro é rápido, pois adiciona elementos no início ou fim da lista.

---

## 7. Aplicabilidade em Sistemas Reais
- **Sim**, se for em um contexto de:
  - Pequenas bibliotecas ou sistemas com poucos livros → a lista dinâmica funciona bem.  


---

## 8. Resultados de Tempo de Operações (Exemplo)
| Nº de livros | Cadastro (s) | Busca último livro (s) | Empréstimo último livro (s) |
|--------------|--------------|-----------------------|-----------------------------|
| 5            | 0.000001     | 0.000000              | 0.000001                    |
| 50           | 0.000010     | 0.000005              | 0.000006                    |
| 500          | 0.000120     | 0.000070              | 0.000080                    |

> Valores são aproximados e dependem da máquina e compilador utilizados.

---

**Conclusão:**  
A lista dinâmica é eficiente para pequenas quantidades de dados e situações com inserções e remoções frequentes, mas apresenta limitações para buscas em grandes volumes de informações.
