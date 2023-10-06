#include <stdio.h>
#define MAX 14

int codes[MAX]; // Declara um array para armazenar códigos com tamanho máximo de 14
int count = 0;  // Inicializa a contagem de elementos na lista como zero

// Função para exibir os códigos presentes na lista
void displayCodes() {
    printf("Códigos na lista:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %d\n", i + 1, codes[i]);
    }
}

// Função para encontrar a posição de um código na lista
int findPosition(int code) {
    for (int i = 0; i < count; i++) {
        if (codes[i] == code) {
            return i; // Retorna a posição se o código for encontrado
        }
    }
    return -1; // Retorna -1 se o código não for encontrado
}

// Função para inserir um código em uma determinada posição na lista
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

    // Desloca os elementos para abrir espaço para o novo código
    for (i; i > position - 1; i--) {
        codes[i + 1] = codes[i];
    }

    codes[position] = code;
    count++;
    printf("Código inserido com sucesso.\n");
}

// Função para remover um código de uma determinada posição na lista
void removeCode(int position) {
    if (count == 0) {
        printf("A lista está vazia. Não há código para remover.\n");
        return;
    }

    if (position < 0 || position >= count) {
        printf("Posição de remoção inválida.\n");
        return;
    }

    // Desloca os elementos após a posição removida para preencher o espaço vazio
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
