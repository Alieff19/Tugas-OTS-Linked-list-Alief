#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Kontak {
    char nama[50];
    char nomor[20];
    struct Kontak* next;
};

struct Kontak* head = NULL;

void tambahKontak(char nama[], char nomor[]) {
    struct Kontak* kontakBaru = (struct Kontak*)malloc(sizeof(struct Kontak));
    strcpy(kontakBaru->nama, nama);
    strcpy(kontakBaru->nomor, nomor);
    kontakBaru->next = head;
    head = kontakBaru;
}

void cariKontak(char nama[]) {
    struct Kontak* temp = head;
    while(temp != NULL) {
        if(strcmp(temp->nama, nama) == 0) {
            printf("Data ditemukan!\n");
            printf("\nNama: %s\nNomor Telepon: %s\n", temp->nama, temp->nomor);
            return;
        }
        temp = temp->next;
    }
    printf("Kontak tidak ditemukan\n");
}

void cetakKontak() {
    struct Kontak* temp = head;
    while(temp != NULL) {
        printf("Nama: %s\nNomor Telepon: %s\n", temp->nama, temp->nomor);
        temp = temp->next;
    }
}

int main() {
    int pilihan;
    char nama[50];
    char nomor[20];
    while(1) {
        printf("1. Tambah Kontak\n2. Cari Kontak\n3. Cetak Daftar Kontak\n4. Keluar\n");
        printf("Pilih Menu: ");
        scanf("%d", &pilihan);
        switch(pilihan) {
            case 1:
                printf("Nama: ");
                scanf("%s", nama);
                printf("Nomor Telepon: ");
                scanf("%s", nomor);
                tambahKontak(nama, nomor);
                printf("Kontak Berhasil Ditambahkan.\n");
                break;
            case 2:
                printf("Nama: ");
                scanf("%s", nama);
                cariKontak(nama);
                break;
            case 3:
                printf("Daftar Kontak Telepon:\n");
                cetakKontak();
                break;
            case 4:
                exit(0);
            default:
                printf("Pilihan tidak valid\n");
        }
    }
    return 0;
}