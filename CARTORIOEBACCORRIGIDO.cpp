#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int registro() {
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40]; 

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);
    strcpy(arquivo, cpf);

    FILE *file = fopen(arquivo, "w");
    if (file == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return 1;
    }
    fprintf(file, "%s,", cpf);
    fclose(file);

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);
    file = fopen(arquivo, "a");
    fprintf(file, "%s,", nome);
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);
    file = fopen(arquivo, "a");
    fprintf(file, "%s,", sobrenome);
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);
    file = fopen(arquivo, "a");
    fprintf(file, "%s", cargo);
    fclose(file);

    printf("Usu�rio cadastrado com sucesso!\n");
    system("pause");
    return 0;
}

int consulta() {
    setlocale(LC_ALL, "Portuguese");

    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file = fopen(cpf, "r");
    if (file == NULL) {
        printf("N�o foi poss�vel localizar o arquivo.\n");
    } else {
        printf("\nEssas s�o as informa��es do usu�rio:\n");
        while (fgets(conteudo, sizeof(conteudo), file) != NULL) {
            printf("%s\n", conteudo);
        }
        fclose(file);
    }

    system("pause");
    return 0;
}

int deletar() {
    char cpf[40];

    printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf);

    if (remove(cpf) == 0) {
        printf("Usu�rio deletado com sucesso!\n");
    } else {
        printf("O usu�rio n�o se encontra no sistema!\n");
    }

    system("pause");
    return 0;
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int opcao = 0;

    while (1) {
        system("cls");
        printf("### Cart�rio da EBAC ###\n\n");
        printf("Escolha a op��o desejada do menu:\n");
        printf("\t1 - Registrar Nomes\n");
        printf("\t2 - Consultar Nomes\n");
        printf("\t3 - Deletar Nomes\n");
        
        printf("Op��o: ");
        scanf("%d", &opcao);
        system("cls");

        switch (opcao) {
            case 1:
                registro();
                break;
            case 2:
                consulta();
                break;
            case 3:
                deletar();
                break;
           
            default:
                printf("Essa op��o n�o est� dispon�vel!\n");
                system("pause");
                break;
        }
    }
}

