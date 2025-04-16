#include <stdio.h>
#include <string.h>
#include <ctype.h>

void to_lower_case(char *src) {
    while (*src != '\0') {
        if (isupper(*src)) *src = tolower(*src);
        src++;
    }
}

void railfence_encrypt(char *text, int key, char *ciphertext) {
    int length = strlen(text);
    char rail[key][length];
    
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < length; j++) {
            rail[i][j] = '\n';  
        }
    }

    int row = 0, col = 0, direction = 1;

    for (int i = 0; i < length; i++) {
        rail[row][col++] = text[i];
        row += direction;

        if (row == 0 || row == key - 1) {
            direction = -direction;  
        }
    }

    int index = 0;
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < length; j++) {
            if (rail[i][j] != '\n') {
                ciphertext[index++] = rail[i][j];
            }
        }
    }
    ciphertext[index] = '\0'; 
}

void railfence_decrypt(char *ciphertext, int key, char *plaintext) {
    int length = strlen(ciphertext);
    char rail[key][length];

    for (int i = 0; i < key; i++) {
        for (int j = 0; j < length; j++) {
            rail[i][j] = '\n';  
        }
    }

    int row = 0, col = 0, direction = 1;

    for (int i = 0; i < length; i++) {
        rail[row][col++] = '*'; 
        row += direction;

        if (row == 0 || row == key - 1) {
            direction = -direction;  
        }
    }

    int index = 0;
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < length; j++) {
            if (rail[i][j] == '*' && index < length) {
                rail[i][j] = ciphertext[index++];
            }
        }
    }

    row = 0, col = 0, direction = 1;
    for (int i = 0; i < length; i++) {
        plaintext[i] = rail[row][col++];
        row += direction;

        if (row == 0 || row == key - 1) {
            direction = -direction; 
        }
    }
    plaintext[length] = '\0';  
}

void processText(char *input, int key, int mode) {
    char ciphertext[500], plaintext[500];

    if (mode == 1) {
        railfence_encrypt(input, key, ciphertext);
        printf("Encrypted message: %s\n", ciphertext);
    } else if (mode == 2) {
        railfence_decrypt(input, key, plaintext);
        printf("Decrypted message: %s\n", plaintext);
    } else {
        printf("Invalid choice.\n");
    }
}

int main() {
    char text[500];
    int key, choice;

    printf("Rail Fence Cipher\n");
     printf("1.Encrypt\n2. Decrypt\nSelect option: ");
    scanf("%d", &choice);

    if (choice != 1 && choice != 2) {
        printf("Invalid option.\n");
        return 1;
    }

    printf("Input message: ");
    scanf("%s", text);
    printf("Enter key: ");
    scanf("%d", &key);

    to_lower_case(text);
    processText(text, key, choice);

    return 0;
}
