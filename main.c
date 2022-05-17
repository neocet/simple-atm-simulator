#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <dos.h>



void clear(int seconds){
    /* Fungsi untuk menghapus output console
       dan menjeda program selama durasi waktu
       tertentu serta memberi semcam header pada
       output console
    */

    sleep(seconds);         // Menjeda program
    system("cls");          // Menghapus isi console

    // Output header
    printf("|@===============================================@|\n");
    printf("|                   NOTGEH BANK                   |\n");
    printf("|@===============================================@|\n");
}



void printc(char *str){
    /* Fungsi yang akan memformat output yang akan
       ditampilkan pada console sehingga menjadi
       seperti format centered pada Microsoft Word
    */

    // Deklarasi variabel
    int width = 50;
    int len = strlen(str);     // Mengambil panjang string

    if (len >= width) {
        printf(str);
    }
    else {
        int spacing = (width - len) - ((width - len) / 2);
        printf("\n%*s%s", spacing, "", str);        // Memberikan spasi sesuai dengan panjang string
  }
}



char *getpin(int header, char *pin){
    /* Fungsi untuk mengambil input PIN dari user*/

    // Deklarasi variabel
    char temp;
    int p;

    if (header == 1){
        printc("Masukkan PIN");
    }
    printf("\n\n\n                      "); // Pengganti printc() karena tidak bisa digunakan pada kasus ini

    // Looping untuk mengisi PIN
    for (p = 0; p < 6; p++){
        temp = getch();                     // Mengambil single character
        if(temp != '\r'){
            if (temp == '\b'){              // Memberi kemampuan untuk menghapus PIN yang telah diketik
                p -= 2;
                printf("\b \b");
            } else {
                pin[p] = temp;
                printf("*");                // Menampilkan "*" agar PIN tersembunyi
            }
        }
    }
    return pin;
}



char *data_reader(char *mode, char *string){
    /* Fungsi untuk mengambil data dari file binary */

    // Deklarasi variabel
    int i = 0;
    char reader[55];

    // Mengakses file binary
    FILE *fp;
    if ((fp = fopen("credential.bin", "rb")) == NULL ){     // Membuat file binary jika belum ada
        fp = fopen("credential.bin", "wb");
        char writer[] = "000000#24000000";
        fwrite(writer, sizeof(char), sizeof(writer) / sizeof(char), fp);
        fclose(fp);
    }

    // Mengambil data dari file binary
    fp = fopen("credential.bin", "rb");
    fread(reader, sizeof(char), sizeof(reader)/ sizeof(char), fp);
    fclose(fp);

    // Mengolah data yang telah diambil
    char *temp[3];
    temp[0] = strtok(reader,"#");
    while (temp[i++] != NULL){
        temp[i] = strtok(NULL,"#");
    }

    // Menetukan data yang akan dikembalikan oleh fungsi
    int opt = strcmp(mode, "pin");
    if (opt == 0){
        strcpy(string,temp[0]);
        return string;
    }
    else {
        strcpy(string, temp[1]);
        return string;
    }
}



int authenticate(int header, char *c_pin){
    /* Fungsi untuk mengambil input PIN dan
       mengautentikasi input PIN dari user,
       mengembalikan nilai 1 apabila 3x salah
       dan mengembalikan nilai 0 agar bisa
       lanjut ke program utama
    */

    // Deklarasi variabel
    int trial = 3, i = 0, comp;

    // Memberi kesempatan 3x untuk menginput PIN
    for (i = 0; i <= 4; i++){
        if (trial != 0){
            char *pin = getpin(header, pin);

            // Membandingkan PIN yang benar dengan input user
            comp = strcmp(pin, c_pin);
            if (comp != 0){
                clear(0);
                printc("PIN SALAH >:v");
                clear(2);
                trial--;
            } else {
                clear(0);
                break;
            }

        } else {    // Keluar dari fungsi (Kesempatan sudah habis)
            clear(0);
            printc("GET LOST THIEF!");
            return 1;
        }
    }
    return 0;
}



void depo(char *pin, char *bal){
    // Code goes here
}



void wede(char *pin, char *bal){
    // Code goes here
}



void get_bal(char *bal){
   void get_bal(char *bal){
  /* Fungsi yang akan menampilkan jumlah saldo kepada user */

  printc("Saldo Anda:");
  printf("\n");

  // Menampilkan saldo dengan format centered
  char sign[55] = "Rp";
  strcat(sign, bal);
  printc(sign);
  clear(2);
}



void ubah_pin(char *pin, char *bal){
    // Code goes here
}



int display_menu(char *pin, char *bal){
    // Deklarasi variabel
    char i = '\b';
    
    // Menampilkan menu utama
    clear(0);    
    printf("\n(1) Setor Tunai                       Cek Saldo (3)\n");
    printf("\n(2) Tarik Tunai                        Ubah Pin (4)\n");

    // Mengambil menu pilihan user
    while (i == '\b'){
        i = getch();
    }

    clear(0);
    printc("Silahkan menunggu");
    clear(2);

    // Menjalankan fungsi sesuai dengan pilihan user
    switch (i){
        case '1':
            depo(pin, bal);
            break;
        case '2':
            wede(pin, bal);
            break;
        case '3':
            get_bal(bal);
            break;
        case '4':
            ubah_pin(pin, bal);
            break;
        default:        // Kembali ke menu utama
            clear(0);
            printc("INVALID OPTION");
            clear(1);
            display_menu(pin, bal);
    }

    clear(0);
    printc("Transaksi lagi? (y/n)");

    // Mengambil pilihan user
    do {
        i = getch();
    } while (i == '\b');
    
    if (i == 'y'){
        return 1;
    } else {
        return 0;
    }
}



int main(){
    // Mengambil PIN dan deklarasi saldo
    char c_pin[6], bal[12];
    strcpy(c_pin, data_reader("pin", c_pin));

    // Input dan validasi PIN
    clear(0);
    int status = authenticate(1, c_pin);
    if (status == 1){
        return EXIT_SUCCESS;
    }

    // Looping ke menu utama sesuai dengan permintaan user
    int loop = 1;
    while (loop == 1){
        // Mengambil PIN dan saldo dari file binary
        strcpy(c_pin, data_reader("pin", c_pin));
        strcpy(bal, data_reader("bal", bal));

        loop = display_menu(c_pin, bal);
        if (loop == 1){
            clear(0);
            strcpy(c_pin, data_reader("pin", c_pin));   // Refresh PIN setelah melakukan transaksi
            status = authenticate(1, c_pin);            // Autentikasi user
            if (status == 1){
                return EXIT_SUCCESS;
            }
        } else {
            // Exit message
            clear(0);
            printc("Thank you for using our services (/>//</)");
            printf("\n\n");
        }
    }
}
