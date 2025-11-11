#include <stdio.h> 
#include <stdlib.h>
#include <string.h>


typedef struct {
    char username[50];
    char password[50];
    char role[20];
} Akun;

int main (int argc, char *argv[]) 
{
    if (argc != 3) 
    {
        printf("\nCara pakai: %s <username> <password>\n\n", argv[0]);
        return 1;
    }

    char *input_username = argv[1];
    char *input_password = argv[2];

    FILE *file = fopen("file.txt", "r");
    if (file == NULL) { 
        printf("Tidak dapat membuka file");
        return 1;
    }

    Akun akun;
    int login_success = 0;

    while (fscanf(file, "%s %s %s", akun.username, akun.password, akun.role) != EOF) 
    {
        if (strcmp(input_username, akun.username) == 0 && strcmp(input_password, akun.password) == 0) 
        {
            printf("\nLogin berhasil!\nRole anda adalah: %s\n\n", akun.role);
            login_success = 1;
            break;
        }
    }

    fclose(file);

    if (!login_success) 
    {
        printf("\nLogin gagal! Username atau password salah.\n\n");
    }

    return EXIT_SUCCESS;
}