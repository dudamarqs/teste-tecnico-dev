#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_PRODUTOS 100 // Define o número máximo de produtos

// Estrutura dos produtos
typedef struct {
    char nome[50];
    int quantidade;
    float preco;
    char categoria[50];
} Produto;

// Declaração do array de produtos e contador de produtos cadastrados
Produto produtos[NUM_PRODUTOS];
int contador_produtos = 0;

// Funções
void limpar_buffer();
void menu();
void cadastrar_produto();
void listar_produtos();
void alterar_informacoes_produto();
void remover_produto();
void ler_string(char *destino, int tamanho, const char *mensagem);
int ler_inteiro(const char *mensagem);
float ler_float(const char *mensagem);
void limpar_tela();


void limpar_tela() {
    printf("\033[H\033[J"); // Move o cursor para o topo e limpa a tela
}

// Função para limpar o buffer de entrada de maneira segura
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função auxiliar para ler strings com segurança
void ler_string(char *destino, int tamanho, const char *mensagem) {
    printf("%s", mensagem);
    fgets(destino, tamanho, stdin);
    strtok(destino, "\n"); // Remove o caractere de nova linha
}

// Função auxiliar para ler inteiros com validação
int ler_inteiro(const char *mensagem) {
    int valor;
    while (1) {
        printf("%s", mensagem);
        if (scanf("%d", &valor) == 1 && valor >= 0) {
            limpar_buffer();
            return valor;
        }
        printf("Entrada invalida. Digite um numero não negativo.\n");
        limpar_buffer();
    }
}

// Função auxiliar para ler floats com validação
float ler_float(const char *mensagem) {
    float valor;
    while (1) {
        printf("%s", mensagem);
        if (scanf("%f", &valor) == 1 && valor >= 0.0) {
            limpar_buffer();
            return valor;
        }
        printf("Entrada inválida. Digite um valor não negativo.\n");
        limpar_buffer();
    }
}

// Função para cadastrar novos produtos
void cadastrar_produto() {
    printf("=== CADASTRAR PRODUTOS ===\n");

    while (1) {
        if (contador_produtos >= NUM_PRODUTOS) {
            printf("Limite de produtos cadastrados atingido.\n");
            return;
        }

        Produto novo_produto;
        ler_string(novo_produto.nome, sizeof(novo_produto.nome), "\nNome do produto: ");
        novo_produto.quantidade = ler_inteiro("Quantidade em estoque: ");
        novo_produto.preco = ler_float("Preco unitario: R$ ");
        ler_string(novo_produto.categoria, sizeof(novo_produto.categoria), "Categoria: ");
        
        produtos[contador_produtos++] = novo_produto;
        printf("\nProduto cadastrado com sucesso!\n");

        char resp;
        printf("Deseja cadastrar outro produto? [s/n] ");
        resp = getchar(); // Aqui você lê a resposta do usuário
        limpar_buffer(); // Limpa o buffer após a leitura

        if (resp == 'n') {
            break; // Se a resposta for 'n', sai do loop
        }
    }
}

// Função para listar produtos cadastrados
void listar_produtos() {
    printf("=== LISTAR PRODUTOS CADASTRADOS ===\n\n");

    printf("-------------------------------------------------------------------\n");
    printf("| %-20s | %-10s | %-12s | %-20s\n", "NOME", "QUANTIDADE", "PRECO UNIT.", "CATEGORIA");
    printf("-------------------------------------------------------------------\n");
    for (int i = 0; i < contador_produtos; i++) {
        printf("| %-20s | %-10d | R$ %-9.2f | %-20s\n", produtos[i].nome, produtos[i].quantidade, produtos[i].preco, produtos[i].categoria);
    }
    printf("-------------------------------------------------------------------\n");
    printf("Pressione Enter para voltar ao menu.");
    getchar(); // Aguarda entrada do usuário
}

// Função para alterar informações de um produto
void alterar_informacoes_produto() {
    char nomeProduto[50];
    int produtoEncontrado = 0;

    printf("=== ATUALIZAR PRODUTO ===\n");
    
    while (1) {
        ler_string(nomeProduto, sizeof(nomeProduto), "\nInforme o nome do produto que sera atualizado: ");
        
        for (int i = 0; i < contador_produtos; i++) {
            if (strcmp(produtos[i].nome, nomeProduto) == 0) {
                produtoEncontrado = 1;
                
                // Atualiza informações
                printf("\n-> Produto encontrado. Digite as novas informacoes do produto:\n");
                ler_string(produtos[i].nome, sizeof(produtos[i].nome), "Nome do produto: ");
                produtos[i].quantidade = ler_inteiro("Quantidade em estoque: ");
                produtos[i].preco = ler_float("Preco unitario: R$ ");
                ler_string(produtos[i].categoria, sizeof(produtos[i].categoria), "Categoria: ");
                
                printf("\nAs informacoes do produto foram atualizadas com sucesso!\n");
                
                char resp;
                printf("Deseja atualizar outro produto? [s/n] ");
                resp = getchar(); // Aqui você lê a resposta do usuário
                limpar_buffer(); // Limpa o buffer após a leitura
                
                if (resp == 'n') {
                    return; // Se a resposta for 'n', sai da função
                }
                produtoEncontrado = 0; // Reseta a flag para permitir nova busca
                break; // Sai do loop para buscar outro produto
            }
        }

        if (!produtoEncontrado) {
            printf("Produto nao cadastrado.\n");
        }
    }
}

// Função para remover um produto
void remover_produto() {
    char nomeProduto[50];
    int produtoEncontrado = 0;

    printf("=== REMOVER PRODUTO ===\n\n");
    
    while (1) {
        ler_string(nomeProduto, sizeof(nomeProduto), "Informe o nome do produto que deseja remover (ou 'x' para voltar ao Menu): ");

        
        for (int i = 0; i < contador_produtos; i++) {
            if (strcmp(produtos[i].nome, nomeProduto) == 0) {
                produtoEncontrado = 1;

                // "Remove" o produto deslocando os produtos restantes
                for (int j = i; j < contador_produtos - 1; j++) {
                    produtos[j] = produtos[j + 1];
                }
                contador_produtos--;
                printf("Produto removido com sucesso!\n");
                
                char resp;
                printf("Deseja remover outro produto? [s/n] ");
                resp = getchar(); // Aqui você lê a resposta do usuário
                limpar_buffer(); // Limpa o buffer após a leitura
                
                if (resp == 'n') {
                    return; // Se a resposta for 'n', sai da função
                }
                produtoEncontrado = 0; // Reseta a flag para permitir nova busca
                break; // Sai do loop para buscar outro produto
            }
        }

        if (!produtoEncontrado) {
            printf("Produto não encontrado.\n");
        }
    }
}

// Função do menu principal
void menu() {
    int opcao;

    do {
        limpar_tela();
        printf("\n==== MENU DE OPCOES ====\n");
        printf("[1] Cadastrar novo produto\n");
        printf("[2] Listar produtos cadastrados\n");
        printf("[3] Atualizar informacoes de um produto\n");
        printf("[4] Remover um produto do estoque\n");
        printf("[5] Sair do programa\n");
        printf("\nEscolha uma opcao: ");
        
        opcao = ler_inteiro("");

        switch (opcao) {
            case 1:
                limpar_tela();
                cadastrar_produto();
                break;
            case 2:
                limpar_tela();
                listar_produtos();
                break;
            case 3:
                limpar_tela();
                alterar_informacoes_produto();
                break;
            case 4:
                limpar_tela();
                remover_produto();
                break;
            case 5:
                printf("\nSaindo do programa... Volte sempre!\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 5);
}