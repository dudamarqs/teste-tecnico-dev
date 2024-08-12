#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define NUM_PRODUTOS 3  // Defina o número de produtos

// Define a estrutura dos produtos.
typedef struct {
    char nome[50];
    int quantidade;
    float preco;
    char categoria[50];
} Produto;

Produto produtos[NUM_PRODUTOS] = {{"", 0, 0.0, ""}}; // Define como cada elemento do array será inicializado (char, int, float, char).

// Prototipagem das funções
void cadastrar_produtos(Produto produtos[]);
void listar_produtos(Produto produtos[]);
void alterar_informacoes_produto(Produto produtos[]);
void remover_produto(Produto produtos[]);
void menu();

// Função para cadastrar novos produtos
void cadastrar_produtos(Produto produtos[]) {
    for (int i = 0; i < NUM_PRODUTOS; i++) {
        printf("Nome do produto: ");
        fflush(stdin);  // Limpa o buffer de entrada (apenas no Windows)
        fgets(produtos[i].nome, sizeof(produtos[i].nome), stdin);
        strtok(produtos[i].nome, "\n"); // Remove o caractere de nova linha

        printf("Quantidade em estoque: ");
        scanf("%d", &produtos[i].quantidade);
        printf("Preco unitario: R$ ");
        scanf("%f", &produtos[i].preco);
        
        printf("Categoria: ");
        fflush(stdin);  // Limpa o buffer de entrada
        fgets(produtos[i].categoria, sizeof(produtos[i].categoria), stdin);
        strtok(produtos[i].categoria, "\n"); // Remove o caractere de nova linha
        
        printf("Produto cadastrado com sucesso!\n");
        getchar(); // Limpa o buffer após a leitura de números
    }
}

// Função para listar produtos
void listar_produtos(Produto produtos[]) {
    printf("--------------------------------------------------------------\n");
    printf("| %-20s | %-10s | %-12s | %-20s \n", "NOME", "QUANTIDADE", "PRECO UNIT.", "CATEGORIA");
    printf("--------------------------------------------------------------\n");
    for (int i = 0; i < NUM_PRODUTOS; i++) {
        // Verifica se o produto foi cadastrado
        if (strlen(produtos[i].nome) > 0) {
            printf("| %-20s | %-10d | R$ %-9.2f | %-20s \n", produtos[i].nome, produtos[i].quantidade, produtos[i].preco, produtos[i].categoria);
        }
    }
    printf("--------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para voltar ao menu.");
    getch(); // Aguarda entrada do usuário
}

// Função para atualizar as informações de um determinado produto.
void alterar_informacoes_produto(Produto produtos[]) {
    char nomeProduto[50];
    int produtoEncontrado = 0;

    // Recebe o nome do produto que será atualizado.
    printf("Informe o nome do produto que será atualizado: ");
    fflush(stdin);  // Limpa o buffer do teclado.
    fgets(nomeProduto, sizeof(nomeProduto), stdin); // Entrada de dados sem desconsiderar os espaços.
    strtok(nomeProduto, "\n"); // Remove o caractere de nova linha

    for (int i = 0; i < NUM_PRODUTOS; i++){
        if (strcmp(produtos[i].nome, nomeProduto) == 0) {
            produtoEncontrado = 1; // Recebe '1' quando o produto é encontrado.

            // Recebe as novas informações do produto.
            printf("\n-> Produto encontrado. Digite as novas informacoes do produto:");
            printf("\nNome do produto: ");
            fflush(stdin);
            fgets(produtos[i].nome, sizeof(produtos[i].nome), stdin);
            strtok(produtos[i].nome, "\n");

            printf("Quantidade em estoque: ");
            scanf("%d", &produtos[i].quantidade);
            printf("Preco unitario: R$ ");
            scanf("%f", &produtos[i].preco);
            
            printf("Categoria: ");
            fflush(stdin);
            fgets(produtos[i].categoria, sizeof(produtos[i].categoria), stdin);
            strtok(produtos[i].categoria, "\n");

            printf("\n\nAs informacoes do produto foram atualizadas com sucesso!\n");
            break;
            getch();
            system("cls");
            menu();
        }
    }

    // Caso o produto não tenha sido encontrado, o sistema retorna para o menu de opções.
    if (produtoEncontrado == 0) {
        printf("Produto não cadastrado. Aperte qualquer tecla para voltar ao menu.");
        getch();
        system("cls");
        menu();
    }
}

// Função para remover um produto.
void remover_produto(Produto produtos[]) {
    char nomeProduto[50];
    int produtoEncontrado = 0;

    printf("Informe o nome do produto que deseja remover: ");
    fflush(stdin); // Limpa o buffer de entrada
    fgets(nomeProduto, sizeof(nomeProduto), stdin);
    strtok(nomeProduto, "\n"); // Remove o caractere de nova linha

    for (int i = 0; i < NUM_PRODUTOS; i++) {
        if (strcmp(produtos[i].nome, nomeProduto) == 0) {
            produtoEncontrado = 1; // Marca o produto como encontrado

            // "Remove" o produto limpando as informações
            strcpy(produtos[i].nome, "");
            produtos[i].quantidade = 0;
            produtos[i].preco = 0.0;
            strcpy(produtos[i].categoria, "");

            printf("Produto removido com sucesso!\n");
            break;
        }
    }

    if (produtoEncontrado == 0) {
        printf("\nProduto não encontrado.");
    }
    printf("\nPressione qualquer tecla para voltar ao menu.");
    getch();
}

// Função do menu principal.
void menu() {
    int opcao;

    do {
        system("cls");  // Limpa a tela a cada nova opção do menu.
        printf("==== MENU DE OPCOES ====");
        printf("\n[1] Cadastrar novo produto");
        printf("\n[2] Listar produtos cadastrados");
        printf("\n[3] Atualizar informacoes de um produto");
        printf("\n[4] Remover um produto do estoque");
        printf("\n[5] Sair do programa");

        printf("\n\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                system("cls");
                printf("==== CADASTRAR PRODUTOS ====\n");
                cadastrar_produtos(produtos);
                break;
            case 2:
                system("cls");
                printf("==== LISTAR PRODUTOS ====\n");
                listar_produtos(produtos);
                break;
            case 3:
                system("cls");
                printf("==== ALTERAR INFORMACOES ====\n");
                alterar_informacoes_produto(produtos);
                break;
            case 4:
                system("cls");
                printf("==== REMOVER PRODUTO ====\n");
                remover_produto(produtos);
                break;
            case 5:
                system("cls");
                printf("\nSaindo do programa...");
                printf("\nVolte sempre!");
                break;
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
                getch(); // Aguarda entrada do usuário.
        }
    } while (opcao != 0);
}

int main() {
    menu(); // Chama o menu principal.
    return 0;
}
