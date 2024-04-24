
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char nome[50];
    char sobrenome[50];
    char email[100];
    char telefone[15];
};

struct Contact listaContatos[MAX_CONTACTS];
int numContatos = 0;

void adicionarContato(const char *nome, const char *sobrenome, const char *email, const char *telefone) {
    if (numContatos < MAX_CONTACTS) {
        strcpy(listaContatos[numContatos].nome, nome);
        strcpy(listaContatos[numContatos].sobrenome, sobrenome);
        strcpy(listaContatos[numContatos].email, email);
        strcpy(listaContatos[numContatos].telefone, telefone);
        numContatos++;
        printf("Contato adicionado com sucesso!\n");
    } else {
        printf("A lista de contatos está cheia. Não é possível adicionar mais contatos.\n");
    }
}

void mostrarContatos() {
    if (numContatos == 0) {
        printf("A lista de contatos está vazia.\n");
        return;
    }

    printf("Lista de Contatos:\n");
    for (int i = 0; i < numContatos; i++) {
        printf("%d. Nome: %s %s, Email: %s, Telefone: %s\n", i+1, listaContatos[i].nome, listaContatos[i].sobrenome, listaContatos[i].email, listaContatos[i].telefone);
    }
}

void deletarContato(const char *telefone) {
    int i;
    for (i = 0; i < numContatos; i++) {
        if (strcmp(listaContatos[i].telefone, telefone) == 0) {
            // Move os contatos restantes para preencher o espaço
            for (int j = i; j < numContatos - 1; j++) {
                listaContatos[j] = listaContatos[j + 1];
            }
            numContatos--;
            printf("Contato deletado com sucesso!\n");
            return;
        }
    }
    printf("Contato com o telefone %s não encontrado.\n", telefone);
}

// Implementation of the deletar_contato function as per requirement
void deletar_contato() {
    char telefone[15];
    printf("Digite o telefone do contato que deseja excluir: ");
    scanf("%s", telefone);
    deletarContato(telefone);
}

int main() {
    int escolha;
    char nome[50], sobrenome[50], email[100], telefone[15];

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar Contato\n");
        printf("2. Mostrar Contatos\n");
        printf("3. Deletar Contato\n");
        printf("4. Sair\n");
        printf("Escolha: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Nome: ");
                scanf("%s", nome);
                printf("Sobrenome: ");
                scanf("%s", sobrenome);
                printf("Email: ");
                scanf("%s", email);
                printf("Telefone: ");
                scanf("%s", telefone);
                adicionarContato(nome, sobrenome, email, telefone);
                break;
            case 2:
                mostrarContatos();
                break;
            case 3:
                deletar_contato(); 
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Escolha inválida. Por favor, escolha uma opção válida.\n");
        }
    } while (escolha != 4);

    return 0;
}