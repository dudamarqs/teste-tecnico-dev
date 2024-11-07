# Sistema de Gerenciamento de Produtos

Este é um programa em C para gerenciamento de produtos, permitindo cadastrar, listar, atualizar e remover produtos de um estoque. O projeto é estruturado em torno de um array de estruturas `Produto` e inclui um menu interativo para manipulação dos dados.

## Descrição

O programa é um sistema simples de gerenciamento de estoque onde o usuário pode:

- **Cadastrar** novos produtos.
- **Listar** todos os produtos cadastrados.
- **Atualizar** as informações de um produto existente.
- **Remover** produtos do estoque, ajustando o array para evitar espaços vazios ao deslocar os produtos subsequentes e decrementando o contador de produtos.

## Pré-requisitos

Para executar este programa, você precisará de:

- **Compilador C++**: Um compilador que suporte o padrão C++. Recomenda-se o GCC (GNU Compiler Collection) ou qualquer outro compilador compatível com C++.
- **Sistema Operacional**: À princípio, o código foi desenvolvido para Windows devido ao uso da função `getch()`. No entanto, após algumas adaptações, o código se tornou compatível para Linux e MacOS também.

## Estrutura dos Arquivos

O projeto é composto por dois arquivos principais:

- `sistema-gerenciamento.c`: Contém as implementações de todas as funções do sistema, como `cadastrar_produto`, `listar_produtos`, `alterar_informacoes_produto` e `remover_produto`.
- `main.c`: Contém a função `main`, que chama a função `menu()` para iniciar o sistema.

## Compilação e Execução

Para compilar o programa, use o seguinte comando no terminal:

```bash
gcc sistema-gerenciamento.c main.c -o sistema-gerenciamento
```

Esse comando compila ambos os arquivos e gera um executável chamado `sistema-gerenciamento`. Para executar o programa, utilize o comando:

```bash
./sistema-gerenciamento
```

## Estrutura do Código

O código é composto por várias funções principais no arquivo `sistema-gerenciamento.c`:

- **`cadastrar_produto()`**: Permite ao usuário cadastrar novos produtos no estoque.
- **`listar_produtos()`**: Lista todos os produtos cadastrados.
- **`alterar_informacoes_produto()`**: Atualiza as informações de um produto existente.
- **`remover_produto()`**: Remove um produto do estoque, deslocando os produtos subsequentes para evitar espaços vazios e ajustando o contador de produtos.
- **`menu()`**: Exibe o menu principal e lida com a interação do usuário.

### Fluxo Geral do Programa

1. O usuário é apresentado ao menu principal.
2. Com base na opção escolhida, o sistema chama a função apropriada.
3. Cada função interage com o usuário para realizar operações específicas no array `produtos`.
4. O sistema continua até que o usuário escolha a opção de sair.