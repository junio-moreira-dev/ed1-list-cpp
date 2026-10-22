# ED1 — TAD Lista — ArrayList e LinkedList

Implementação do **TAD Lista** em C++ com duas estruturas de dados distintas, ambas seguindo o mesmo contrato:

- **ArrayList:** Lista Sequencial Estática, baseada em array dinâmico com capacidade fixa.
- **LinkedList:** Lista Encadeada Simples, baseada em nós alocados dinamicamente.

O projeto apresenta uma separação entre:

- **Interface abstrata (`List.h`):** define o contrato comum da lista.
- **Implementações (`ArrayList.h` e `LinkedList.h`):** cada uma com sua própria estratégia de armazenamento.
- **Testes:** validam as principais operações disponibilizadas por cada lista.

> Instituto Federal do Triângulo Mineiro — Campus Patrocínio  
> Curso: Tecnologia em Análise e Desenvolvimento de Sistemas — 3º Período  
> Disciplina: Estrutura de Dados I  
> Professor: Júnio Moreira  
> Data: 24/09/2026

---

## 📁 Estrutura do Projeto

```text
ed1-list-cpp/
├── cmake-build-debug/
├── include/
│   ├── ArrayList.h
│   ├── LinkedList.h
│   └── List.h
├── src/
│   ├── ArrayListTest.cpp
│   └── LinkedListTest.cpp
├── .gitignore
├── CMakeLists.txt
├── main.cpp
└── README.md
```

## 🧩 Visão Geral

```text
          ┌───────────────┐
          │   List<T>     │  ← interface abstrata
          └───────┬───────┘
          ┌───────┴────────┐
 ┌────────▼───────┐ ┌──────▼─────────┐
 │ ArrayList<T>   │ │ LinkedList<T>  │
 │ array dinâmico │ │ nós + ponteiros│
 └────────────────┘ └────────────────┘
```

Como as duas classes herdam de `List<T>`, é possível trocar a implementação sem alterar o código que utiliza a lista.

## ⚙️ Operações do TAD

| Operação                | Descrição                                  |
|-------------------------|--------------------------------------------|
| `add(value)`            | Insere um elemento no final                |
| `insert(index, value)`  | Insere um elemento em uma posição          |
| `remove(index)`         | Remove e retorna o elemento da posição     |
| `get(index)`            | Retorna o elemento da posição              |
| `set(index, value)`     | Substitui o elemento da posição            |
| `indexOf(value)`        | Retorna a posição do valor (ou `-1`)       |
| `contains(value)`       | Verifica se o valor existe na lista        |
| `size()`                | Retorna a quantidade de elementos          |
| `isEmpty()`             | Verifica se a lista está vazia             |
| `clear()`               | Remove todos os elementos                  |

Índices inválidos lançam `std::out_of_range`.

## ⏱️ Complexidade

| Operação              | ArrayList                  | LinkedList                       |
|-----------------------|----------------------------|----------------------------------|
| `add`                 | O(1)                       | O(1) (ponteiro `tail`)           |
| `insert`              | O(n) (deslocamento)        | O(1) no início/fim, O(n) no meio |
| `remove`              | O(n) (deslocamento)        | O(1) no início, O(n) nos demais  |
| `get` / `set`         | O(1)                       | O(n)                             |
| `indexOf` / `contains`| O(n)                       | O(n)                             |
| `size` / `isEmpty`    | O(1)                       | O(1)                             |
| `clear`               | O(1) ou O(n)*              | O(n)                             |

\* Depende da implementação: se apenas zera o contador, é O(1).

## 🔄 ArrayList × LinkedList

| Aspecto             | ArrayList                    | LinkedList                    |
|---------------------|------------------------------|-------------------------------|
| Memória             | Bloco contíguo               | Nós dispersos + ponteiros     |
| Acesso por índice   | O(1)                         | O(n)                          |
| Inserção no início  | O(n)                         | O(1)                          |
| Capacidade          | Fixa                         | Cresce dinamicamente          |
| Uso de memória      | Pode haver espaço ocioso     | Overhead de um ponteiro/nó    |

**Quando usar cada uma?**

- **ArrayList:** quando há muitos acessos por índice e a quantidade de elementos é previsível.
- **LinkedList:** quando há muitas inserções/remoções no início e o tamanho varia bastante.

## ▶️ Como compilar e executar

```bash
cmake -S . -B build
cmake --build build
./build/ed1_list_cpp
```

> O nome do executável depende do `project()` definido no `CMakeLists.txt`.

Também é possível abrir a pasta diretamente no **CLion** e executar a configuração padrão.

## 🧪 Testes

Cada implementação possui seu arquivo de testes em `src/`:

- `ArrayListTest.cpp` — valida o `ArrayList` (incluindo o limite de capacidade).
- `LinkedListTest.cpp` — valida o `LinkedList` (inserção, remoção, `tail` e exceções).

O `main.cpp` executa os testes das duas listas.
