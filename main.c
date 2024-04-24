

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTATOS 100

struct Contato {
    char nome[50];
    char sobrenome[50];
    char email[100];
    char telefone[15];
};

struct Contato listaContatos[MAX_CONTATOS];
int numContatos = 0;

void salvarContatos() {
    FILE *arquivo;
    arquivo = fopen("contatos.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fwrite(&numContatos, sizeof(int), 1, arquivo);
    fwrite(listaContatos, sizeof(struct Contato), numContatos, arquivo);

    fclose(arquivo);
    printf("Contatos salvos com sucesso!\n");
}

void carregarContatos() {
    FILE *arquivo;
    arquivo = fopen("contatos.bin", "rb");
    if (arquivo == NULL) {
        printf("Arquivo de contatos não encontrado ou vazio.\n");
        return;
    }

    fread(&numContatos, sizeof(int), 1, arquivo);
    fread(listaContatos, sizeof(struct Contato), numContatos, arquivo);

    fclose(arquivo);
    printf("Contatos carregados com sucesso!\n");
}

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

void deletarContatoMenu() {
    char telefone[15];
    printf("Digite o telefone do contato que deseja excluir: ");
    scanf("%s", telefone);
    deletarContato(telefone);
}

void deletarContatoArquivo(const char *telefone) {
    FILE *arquivoTemp;
    FILE *arquivo;
    arquivo = fopen("contatos.bin", "rb");
    if (arquivo == NULL) {
        printf("Arquivo de contatos não encontrado ou vazio.\n");
        return;
    }

    int numContatosTemp;
    fread(&numContatosTemp, sizeof(int), 1, arquivo);

    struct Contato *contatosTemp = (struct Contato *)malloc(numContatosTemp * sizeof(struct Contato));
    fread(contatosTemp, sizeof(struct Contato), numContatosTemp, arquivo);

    fclose(arquivo);

    int i, j;
    for (i = 0; i < numContatosTemp; i++) {
        if (strcmp(contatosTemp[i].telefone, telefone) == 0) {
            for (j = i; j < numContatosTemp - 1; j++) {
                contatosTemp[j] = contatosTemp[j + 1];
            }
            numContatosTemp--;
            printf("Contato deletado com sucesso!\n");
            break;
        }
    }

    arquivoTemp = fopen("contatos_temp.bin", "wb");
    if (arquivoTemp == NULL) {
        printf("Erro ao abrir o arquivo temporário.\n");
        free(contatosTemp);
        return;
    }

    fwrite(&numContatosTemp, sizeof(int), 1, arquivoTemp);
    fwrite(contatosTemp, sizeof(struct Contato), numContatosTemp, arquivoTemp);

    fclose(arquivoTemp);

    remove("contatos.bin");
    rename("contatos_temp.bin", "contatos.bin");

    free(contatosTemp);
}

void deletarContatoArquivoMenu() {
    char telefone[15];
    printf("Digite o telefone do contato que deseja excluir: ");
    scanf("%s", telefone);
    deletarContatoArquivo(telefone);
}

int main() {
    int opcao;

    do {
        // Menu de opções
        printf("\nMenu:\n");
        printf("1. Adicionar contato\n");
        printf("2. Listar contatos\n");
        printf("3. Salvar contatos\n");
        printf("4. Carregar contatos\n");
        printf("5. Deletar contato\n");
        printf("6. Sair\n");
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
                salvarContatos();
                break;
            case 4:
                carregarContatos();
                break;
            case 5:
                deletarContatoMenu();
                break;
            case 6:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 6);

    return 0;
}
