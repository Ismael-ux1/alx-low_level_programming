#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PASSWORD_LENGTH 10
#define VALID_CHARACTERS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*"

int main() {
    char password[PASSWORD_LENGTH + 1]; // Extra space for null terminator
    int i, j, valid;

    srand(time(NULL)); // Initialize random seed

    while (1) { // Loop until a valid password is generated
        for (i = 0; i < PASSWORD_LENGTH; i++) {
            j = rand() % strlen(VALID_CHARACTERS); // Get random index
            password[i] = VALID_CHARACTERS[j]; // Add character to password
        }
        password[PASSWORD_LENGTH] = '\0'; // Add null terminator

        valid = 1;
        for (i = 0; i < PASSWORD_LENGTH; i++) {
            if (password[i] < 33 || password[i] > 126) { // Check if character is outside valid range
                valid = 0;
                break;
            }
        }

        if (valid) { // If password is valid, output it and exit
            printf("Valid password: %s\n", password);
            break;
        }
    }

    return 0;
}

