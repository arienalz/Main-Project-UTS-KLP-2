#include <stdio.h>

int main (){
    FILE *file;
    file = fopen("file.txt", "w");
    
    fprintf(file, "admin admin123 admin\nuser user123 user\n");
    fclose(file);
    return 0;
}