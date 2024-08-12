# Sistema de Gerenciamento de Produtos

Este é um programa em C++ para gerenciamento de produtos, permitindo cadastrar, listar, atualizar e remover produtos de um estoque. O projeto é estruturado em torno de um array de estruturas `Produto`, e inclui um menu interativo para manipulação dos dados.

## Descrição

O programa é um sistema simples de gerenciamento de estoque onde o usuário pode:

- **Cadastrar** novos produtos.
- **Listar** todos os produtos cadastrados.
- **Atualizar** as informações de um produto existente.
- **Remover** produtos do estoque.

## Pré-requisitos

Para executar este programa, você precisará de:

- **Compilador C++**: Um compilador que suporte o padrão C++. Recomenda-se o GCC (GNU Compiler Collection) ou qualquer outro compilador compatível com C++.
- **Sistema Operacional**: O código foi desenvolvido para Windows, devido ao uso da função `getch()`. Se você estiver em outro sistema operacional, você pode precisar adaptar a função de captura de entrada.

## Execução

Para executar o programa, compile o código-fonte usando o compilador de sua escolha e execute o arquivo gerado.

O nome do arquivo fonte é `sistema-gerenciamento.cpp`. Após a compilação, execute o programa gerado para interagir com o sistema.

O programa exibirá um menu com as seguintes opções:

1. Cadastrar novo produto
2. Listar produtos cadastrados
3. Atualizar informações de um produto
4. Remover um produto do estoque
0. Sair do programa

Digite o número da opção desejada e pressione Enter para interagir com o sistema.

## Estrutura do Código

O código é composto por várias funções principais:

- **`cadastrar_produtos(Produto produtos[])`**: Permite ao usuário cadastrar novos produtos no estoque.
- **`listar_produtos(Produto produtos[])`**: Lista todos os produtos cadastrados.
- **`alterar_informacoes_produto(Produto produtos[])`**: Atualiza as informações de um produto existente.
- **`remover_produto(Produto produtos[])`**: Remove um produto do estoque.
- **`menu()`**: Exibe o menu principal e lida com a interação do usuário.

## Observações

- **Limpeza do Buffer**: O programa usa `fflush(stdin)` para limpar o buffer de entrada. Essa prática é específica para alguns compiladores e sistemas operacionais. Em sistemas Unix/Linux, você pode precisar usar outras abordagens para limpar o buffer.
- **Uso do `getch()`**: A função `getch()` é usada para capturar a entrada do usuário de forma silenciosa (sem precisar pressionar Enter). Ela é específica para Windows e pode precisar de substituição em outros sistemas operacionais.

## Contribuição

Se você deseja contribuir para este projeto, siga estas etapas:

1. Faça um fork do repositório.
2. Crie uma nova branch para sua modificação.
3. Faça suas alterações e adicione testes, se necessário.
4. Envie um pull request com uma descrição clara das alterações.

---

Para mais informações ou dúvidas, sinta-se à vontade para abrir uma issue ou entrar em contato com o autor.
