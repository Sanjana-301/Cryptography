#include <stdio.h>
#include <string.h>
#include <ctype.h>

void multiplyMatrix(int key[2][2], char in[3], char out[3]) {
    for (int i = 0; i < 2; i++) {
        int sum = 0;
        for (int j = 0; j < 2; j++) {
            sum += key[i][j] * (in[j] - 'a');
        }
        out[i] = (sum % 26) + 'a';
    }
    out[2] = '\0';
}

int modInverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1;
}

int main() {
    char text[100], result[100] = "";
    int key[2][2], choice;

    printf("Hill Cipher\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the message : ");
    scanf("%s", text);
    
    printf("Enter 4 numbers for the key matrix: ");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            scanf("%d", &key[i][j]);

    int len = strlen(text);
    if (len % 2 != 0) {
        text[len++] = 'x';
        text[len] = '\0';
    }

    if (choice == 1) {
        for (int i = 0; i < len; i += 2) {
            char temp[3] = {text[i], text[i+1], '\0'};
            char enc[3];
            multiplyMatrix(key, temp, enc);
            strcat(result, enc);
        }
        printf("Encrypted message: %s\n", result);
    }

    else if (choice == 2) {
        int det = key[0][0]*key[1][1] - key[0][1]*key[1][0];
        det = (det % 26 + 26) % 26;
        int inv = modInverse(det, 26);

        if (inv == -1) {
            printf("Inverse of determinant doesn't exist. Decryption not possible.\n");
            return 1;
        }

        int invKey[2][2];
        invKey[0][0] = ( key[1][1] * inv) % 26;
        invKey[0][1] = (-key[0][1] * inv + 26) % 26;
        invKey[1][0] = (-key[1][0] * inv + 26) % 26;
        invKey[1][1] = ( key[0][0] * inv) % 26;

        for (int i = 0; i < len; i += 2) {
            char temp[3] = {text[i], text[i+1], '\0'};
            char dec[3];
            multiplyMatrix(invKey, temp, dec);
            strcat(result, dec);
        }
        printf("Decrypted message: %s\n", result);
    }

    else {
        printf("Invalid choice.\n");
        return 1;
    }

    return 0;
}
