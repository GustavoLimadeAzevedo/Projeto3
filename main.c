//Branch 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTATOS 255

struct Contato {
  char nome[50];
  char sobrenome[50];
  char email[100];
  char telefone[15];
};

struct Contato listaContatos[MAX_CONTATOS];
int numContatos = 0;

void adicionarContato() {
  if (numContatos < MAX_CONTATOS) {
    struct Contato novoContato;

    printf("Nome: ");
    scanf("%s", novoContato.nome);

    printf("Sobrenome: ");
    scanf("%s", novoContato.sobrenome);

    printf("Email: ");
    scanf("%s", novoContato.email);

    printf("Telefone: ");
    scanf("%s", novoContato.telefone);

    listaContatos[numContatos++] = novoContato;
    printf("Contato adicionado com sucesso!\n");
  } else {
    printf("A lista de contatos está cheia!\n");
  }
}

void listarContatos() {
  printf("\nListagem de contatos:\n\n");
  for (int i = 0; i < numContatos; ++i) {
    printf("Nome: %s %s\n", listaContatos[i].nome, listaContatos[i].sobrenome);
    printf("Email: %s\n", listaContatos[i].email);
    printf("Telefone: %s\n\n", listaContatos[i].telefone);
  }
}

// Menu de opções.....
int main() {
    int opcao;

    do {
        // Menu de opções
        printf("\nMenu:\n");
        printf("1. Adicionar contato\n");
        printf("2. Listar contatos\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarContato();
                break;
            case 2:
                listarContatos();
                break;
            case 3:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 3);

    return 0;
}




struct contats {
    char nome[50];
    char sobrenome[50];
    char email[100];
    char telefone[15];
};

// Declaração de variáveis globais
struct Contato listaContatos[MAX_CONTATOS];
int numcont = 0;

// Função para adicionar um novo contato à lista
void adicionarContats() {
    if (numContatos < MAX_CONTATOS) {
        struct Contato novoContato;

        printf("Nome: ");
        scanf("%s", novoContato.nome);

        printf("Sobrenome: ");
        scanf("%s", novoContato.sobrenome);

        printf("Email: ");
        scanf("%s", novoContato.email);

        printf("Telefone: ");
        scanf("%s", novoContato.telefone);

        // Adicionando o novo contato à lista e incrementando o número de contatos
        listaContatos[numContatos++] = novoContato;
        printf("Contato adicionado com sucesso!\n");
    } else {
        printf("A lista de contatos está cheia!\n");
    }
}

// Função para listar todos os contatos armazenados
void listarContats() {
    printf("\nListagem de contatos:\n\n");
    for (int i = 0; i < numContatos; ++i) {
        printf("Nome: %s %s\n", listaContatos[i].nome, listaContatos[i].sobrenome);
        printf("Email: %s\n", listaContatos[i].email);
        printf("Telefone: %s\n\n", listaContatos[i].telefone);
    }
}




