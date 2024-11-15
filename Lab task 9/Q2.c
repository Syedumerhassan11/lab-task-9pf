#include <stdio.h>
#include <string.h>

int main() {
    char storedUsername[] = "admin";  
    char storedPassword[] = "1234";   
    char enteredUsername[30];         
    char enteredPassword[30];         
    printf("Enter your username: ");
    scanf("%s", enteredUsername);
     printf("Enter your password: ");
    scanf("%s", enteredPassword);
    if (strcmp(enteredUsername, storedUsername) == 0 && strcmp(enteredPassword, storedPassword) == 0) {
        printf("Access granted\n");
    } else {
        printf("Access denied\n");
    }

    return 0;
}


