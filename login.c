#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
    // Menampilkan pesan error jika username dan password tidak diberikan
    if (argv[1] == NULL) {
        printf("\nInputan yang anda masukkan tidak sesuai prosedur -_-\n");
        printf("\nGunakan -h atau --help untuk melihat cara menggunakan program ini\n\n");
        return EXIT_FAILURE;
    }
    
    // Memberikan bantuan jika flag -h atau --help diberikan saat menjalankan program
    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0){
        printf("\nGunakan username dan password sebagai argumen dalam menjalankan program\n");
        printf("\nUsage: \"./login <username> <password>\"\n");
        printf("\nExample: \"./login root toor\"\n\n");
        return 0;
    }

    // mengambil username dan password dari argumen
    char user[50], passwd[50];
    strcpy(user, argv[1]);
    strcpy(passwd, argv[2]);

    // Membuka file binary untuk membaca data username dan password
    FILE *fp;
    if ((fp = fopen("database/login.bin", "rb")) == NULL) {   // Memberikan pesan error jika file tidak ditemukan
        printf("\nFile tidak ditemukan >:v\n");
        printf("\nMake sure to compile n' run the register.c program first -,-\n\n");
        return EXIT_FAILURE;
    }
    // Menyimpan data file binary ke dalam variabel
    char reader[55];
    fread(reader,sizeof(char), sizeof(reader)/ sizeof(char),fp);
    fclose(fp);

    // Mengolah data yang telah diambil dari file binary
    char *string[3];
    char username[50], password[50];
    int temp = 0;
    // Memisahkan data username dan password dengan menggunakan string tokenizer
    string[0] = strtok(reader, "#");
    while (string[temp++] != NULL) {
        string[temp] = strtok(NULL, "#");
    }
    strcpy(username,string[0]);
    strcpy(password,string[1]);

    // Membandingkan username dan password yang dimasukkan dengan data yang ada di file binary
    if ((strcmp(user,username) == 0) && (strcmp(passwd,password) == 0)) {   // username dan password cocok
        printf("\nSelamat anda berhasil login (//*/w/*//)\n", 0xCF);
        printf("\nWelcome, %s\n\n", user);
    } else {
        printf("\nSumimasen, Anda gagal login -_-\n\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
