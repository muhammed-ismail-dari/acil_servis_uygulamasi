#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HASTA 100

typedef struct {
    char ad[60];
    int yas;
    char tc[11];
    char sikayet[100];
    int oncelik;
    int receteNo;
} Hasta;

Hasta hastalar[MAX_HASTA];
int hastaSayisi = 0;

int receteNoUret() {
    static int sayac = 1000;
    return sayac++;
}

void hastaEkle() {
    if (hastaSayisi >= MAX_HASTA) {
        printf("Hasta kapasitesi dolu!\n");
        return;
    }
    printf("Hasta Adi: ");
    scanf("%s", hastalar[hastaSayisi].ad);
    printf("Yas: ");
    scanf("%d", &hastalar[hastaSayisi].yas);
    printf("TC Kimlik No: ");
    scanf("%10s", hastalar[hastaSayisi].tc); 
    while (getchar() != '\n'); 
    printf("Sikayet: ");
	scanf("%s", hastalar[hastaSayisi].sikayet);
    printf("Oncelik (1-5): ");
    scanf("%d", &hastalar[hastaSayisi].oncelik);
    hastalar[hastaSayisi].receteNo = receteNoUret();
    hastaSayisi++;
    printf("Hasta basariyla eklendi!\n");
}

void hastaListele() {
    printf("\nAcil Servis Hasta Listesi:\n");
    for (int i = 0; i < hastaSayisi; i++) {
        printf("Hasta %d: %s, Yas: %d, TC: %s, Sikayet: %s, Oncelik: %d, Recete No: %d\n",
               i + 1, hastalar[i].ad, hastalar[i].yas, hastalar[i].tc, hastalar[i].sikayet,
               hastalar[i].oncelik, hastalar[i].receteNo);
    }
}

int main() {
    int secim;
    while (1) {
        printf("\nHastane Acil Servis Sistemi\n");
        printf("1. Yeni Hasta Ekle\n");
        printf("2. Hasta Listesini Goruntule\n");
        printf("3. Cikis\n");
        printf("Seciminizi yapin: ");
        scanf("%d", &secim);
        
        switch (secim) {
            case 1:
                hastaEkle();
                break;
            case 2:
                hastaListele();
                break;
            case 3:
                exit(0);
            default:
                printf("Gecersiz secim!\n");
        }
    }
    return 0;
}

