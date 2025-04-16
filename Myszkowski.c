#include <stdio.h>
#include <string.h>
#include <ctype.h>

void toLowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        if (isupper(str[i]))
            str[i] = tolower(str[i]);
    }
}

void getOrder(char *key, int *order) {
    int len = strlen(key), used[100] = {0};
    char sorted[100];
    strcpy(sorted, key);

    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (sorted[i] > sorted[j]) {
                char tmp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = tmp;
            }
        }
    }

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (!used[j] && key[i] == sorted[j]) {
                order[i] = j;
                used[j] = 1;
                break;
            }
        }
    }
}

void encryptMyszkowski(char *msg, char *key) {
    int msgLen = strlen(msg), keyLen = strlen(key);
    int rows = (msgLen + keyLen - 1) / keyLen;
    char matrix[rows][keyLen];
    char result[500] = "";
    int order[100];

    getOrder(key, order);
    memset(matrix, 'x', sizeof(matrix));

    int idx = 0;
    for (int r = 0; r < rows && idx < msgLen; r++) {
        for (int c = 0; c < keyLen && idx < msgLen; c++) {
            matrix[r][c] = msg[idx++];
        }
    }

    for (int step = 0; step < keyLen; step++) {
        for (int col = 0; col < keyLen; col++) {
            if (order[col] == step) {
                for (int row = 0; row < rows; row++) {
                    strncat(result, &matrix[row][col], 1);
                }
            }
        }
    }

    printf("Encrypted message: %s\n", result);
}

void decryptMyszkowski(char *msg, char *key) {
    int msgLen = strlen(msg), keyLen = strlen(key);
    int rows = (msgLen + keyLen - 1) / keyLen;
    char matrix[rows][keyLen];
    char result[500] = "";
    int order[100];

    getOrder(key, order);
    memset(matrix, 'x', sizeof(matrix));

    int pos = 0;
    for (int step = 0; step < keyLen; step++) {
        for (int col = 0; col < keyLen; col++) {
            if (order[col] == step) {
                for (int row = 0; row < rows; row++) {
                    if (pos < msgLen)
                        matrix[row][col] = msg[pos++];
                }
            }
        }
    }

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < keyLen; col++) {
            strncat(result, &matrix[row][col], 1);
        }
    }

    printf("Decrypted message: %s\n", result);
}

int main() {
    char message[100], key[100];
    int choice;

    printf("Myszkowski Cipher\n");
    printf("1. Encrypt\n2. Decrypt\nSelect option: ");
    scanf("%d", &choice);

    printf("Enter message: ");
    scanf("%s", message);
    printf("Enter key: ");
    scanf("%s", key);

    toLowercase(message);
    toLowercase(key);

    if (choice == 1)
        encryptMyszkowski(message, key);
    else if (choice == 2)
        decryptMyszkowski(message, key);
    else
        printf("Invalid choice.\n");

    return 0;
}
