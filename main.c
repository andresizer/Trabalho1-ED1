/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

#define MAX 14

int codes[MAX];
int count = 0;

void displayCodes() {
    printf("Códigos na lista:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %d\n", i + 1, codes[i]);
    }
}

int findPosition(int code) {
    for (int i = 0; i < count; i++) {
        if (codes[i] == code) {
            return i;
        }
    }
    return -1; // Código não encontrado
}

void insertCode(int code, int position) {
    int i = count;
    if (count >= MAX) {
        printf("A lista está cheia. Não é possível inserir mais códigos.\n");
        return;
    }

    if (position < 0 || position > count) {
        // Se a posição for inválida, insira na primeira posição livre
        position = count;
    }

    // Desloque os elementos para abrir espaço para o novo código
    for (i; i > position - 1; i--) {
        codes[i + 1] = codes[i];
    }

    codes[position] = code;
    count++;
    printf("Código inserido com sucesso.\n");
}

void removeCode(int position) {
    if (count == 0) {
        printf("A lista está vazia. Não há código para remover.\n");
        return;
    }

    if (position < 0 || position >= count) {
        printf("Posição de remoção inválida.\n");
        return;
    }

    // Desloque os elementos após a posição removida para preencher o espaço vazio
    for (int i = position; i < count - 1; i++) {
        codes[i] = codes[i + 1];
    }

    count--;
    printf("Código removido com sucesso.\n");
}

int main() {
    int choice, code, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Consultar Código\n");
        printf("2. Inserir Código\n");
        printf("3. Remover Código\n");
        printf("4. Quantidade de Elementos\n");
        printf("5. Exibir Códigos\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite o código a ser consultado: ");
                scanf("%d", &code);
                position = findPosition(code);
                if (position != -1) {
                    printf("O código %d está na posição %d.\n", code, position);
                } else {
                    printf("O código %d não foi encontrado na lista.\n", code);
                }
                break;
            case 2:
                printf("Digite o código a ser inserido: ");
                scanf("%d", &code);
                printf("Digite a posição de inserção: ");
                scanf("%d", &position);
                insertCode(code, position);
                break;
            case 3:
                printf("Digite a posição do código a ser removido: ");
                scanf("%d", &position);
                removeCode(position);
                break;
            case 4:
                printf("Quantidade de elementos na lista: %d\n", count);
                break;
            case 5:
                displayCodes();
                break;
            case 6:
                printf("Saindo do programa.\n");
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}

