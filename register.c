#include <stdio.h>

int main(){
    char writer[50] = "NOTGEH#root";

    // Membuat file binary di dalam folder database untuk mengisi data username dan password
    FILE *fp;
    fp = fopen("database/login.bin","wb");

    // Mengisi username dan password ke dalam file binary
    fwrite(writer, sizeof(char), sizeof(writer)/sizeof(char), fp);
    fclose(fp);

    return 0;
}