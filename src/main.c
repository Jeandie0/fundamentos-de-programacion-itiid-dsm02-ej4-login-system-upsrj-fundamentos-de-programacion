#include <stdio.h>
#include <string.h>

int main() {
    char username[50];
    char password[50];
    char correctPassword[] = "admin123";
    int attempts = 0;
    int i;

    do {
        printf("Enter username (minimum 5 characters): ");
        if (fgets(username, sizeof(username), stdin) != NULL) {
            username[strcspn(username, "\n")] = 0;
        }

        if (strlen(username) < 5) {
            printf("Invalid username\n");
        }
    } while (strlen(username) < 5);

    int nonSpaceCount = 0;
    for (i = 0; username[i] != '\0'; i++) {
        if (username[i] == ' ') {
            continue; 
        }
        nonSpaceCount++;
    }
    printf("Username has %d non-space characters.\n", nonSpaceCount);

    while (attempts < 3) {
        printf("Enter password: ");
        if (fgets(password, sizeof(password), stdin) != NULL) {
            password[strcspn(password, "\n")] = 0;
        }

        int hasNumber = 0;
        for (i = 0; password[i] != '\0'; i++) {
            if (password[i] >= '0' && password[i] <= '9') {
                hasNumber = 1;
                break; 
            }
        }

        if (!hasNumber) {
            printf("Password must contain at least one number.\n");
            attempts++;
        } else {
            if (strcmp(password, correctPassword) == 0) {
                printf("Access granted.\n");
                break; 
            } else {
                printf("Incorrect password.\n");
                attempts++;
            }
        }

        if (attempts == 3) {
            printf("Account locked.\n");
        }
    }

    return 0;
}