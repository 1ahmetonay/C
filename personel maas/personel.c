#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char ad[50];
    char soyad[50];
    char departman[50];
    int izin;
    int deneyim;
    int maas;
    int yeni_maas;
} Calisan;

Calisan yonetici;
//yoneticinin maasini hesaplayip bu maasi yenipersonel.txt ye yazan fonksiyon
void Byonetici(Calisan calisanlar[], int n)
{
    Calisan yonetici = calisanlar[0];//calisan struct'dan yonetici adinda bir değişken oluşturulup calisanlar dizisinin ilk eleamnina verildi
    for(int i = 1; i < n; i++)
    {
        if(calisanlar[i].deneyim > yonetici.deneyim ||
          (calisanlar[i].deneyim == yonetici.deneyim && calisanlar[i].izin < yonetici.izin))
        {
            yonetici = calisanlar[i];
        }
    }
     printf("%d %s %s %s %d %d %d\n",yonetici.id, yonetici.ad, yonetici.soyad,
           yonetici.departman,yonetici.izin,yonetici.deneyim,yonetici.maas);

    yonetici.maas = 10000; // Yöneticinin maasini 10000tl olarak güncelle


    printf("%d %s %s %s %d %d %d\n",yonetici.id, yonetici.ad, yonetici.soyad,
           yonetici.departman,yonetici.izin,yonetici.deneyim,yonetici.maas);

    FILE* yeni_dosya = fopen("yeniPersonel.txt", "r+");
    if (yeni_dosya == NULL)
    {
        printf("Dosya acilamadi.\n");
        return;
    }

    fprintf(yeni_dosya, "%-15d %-15s %-15s %-15s %-15d %-15d %-15d %-15d\n", yonetici.id, yonetici.ad, yonetici.soyad,
            yonetici.departman, yonetici.izin, yonetici.deneyim, yonetici.maas, yonetici.yeni_maas);

    fclose(yeni_dosya);


}

//en yuksek maasi hesaplayan fonksiyon
void en_yuksek_maas(Calisan calisanlar[], int n)
{
    Calisan en_yuksek_maasli = calisanlar[0];
    for(int i = 1; i < n; i++)
    {
        if(calisanlar[i].yeni_maas > en_yuksek_maasli.yeni_maas)
        {
            en_yuksek_maasli = calisanlar[i];
        }
    }
    printf("Adi: %s, Maasi: %d\n", en_yuksek_maasli.ad, en_yuksek_maasli.yeni_maas);
}
//en fazla ek maasi alan kisiyi bulan fonksiyon
void en_fazla_ek_maas(Calisan calisanlar[], int n)
{
    Calisan en_fazla_ek_maasli = calisanlar[0];
    for(int i = 1; i < n; i++)
    {
        if((calisanlar[i].yeni_maas - calisanlar[i].maas) > (en_fazla_ek_maasli.yeni_maas - en_fazla_ek_maasli.maas))
        {
            en_fazla_ek_maasli = calisanlar[i];
        }
    }
    printf("Adi: %s, Departmani: %s\n", en_fazla_ek_maasli.ad, en_fazla_ek_maasli.departman);
}
//en az izin kullanani bulan fonlsiyon
void en_az_izin_kullanan(Calisan calisanlar[], int n)
{
    Calisan en_az_izin_kullanan = calisanlar[0];
    for(int i = 1; i < n; i++)
    {
        if(calisanlar[i].deneyim > 1 && calisanlar[i].izin < en_az_izin_kullanan.izin)
        {
            en_az_izin_kullanan = calisanlar[i];
        }
    }
    printf("Adi: %s, Soyadi: %s\n", en_az_izin_kullanan.ad, en_az_izin_kullanan.soyad);
}
//en fazla calisan departmani bulan fonksiyon
void en_fazla_calisan_departman(Calisan calisanlar[], int n)
{
    int departman_sayilari[50] = {0};
    char departmanlar[50][50];
    int departman_sayisi = 0;

    for(int i = 0; i < n; i++)
    {
        int j;
        for(j = 0; j < departman_sayisi; j++)
        {
            if(strcmp(calisanlar[i].departman, departmanlar[j]) == 0)
            {
                departman_sayilari[j]++;
                break;
            }
        }
        if(j == departman_sayisi)
        {
            strcpy(departmanlar[departman_sayisi], calisanlar[i].departman);
            departman_sayilari[departman_sayisi]++;
            departman_sayisi++;
        }
    }

    int max_index = 0;
    for(int i = 1; i < departman_sayisi; i++)
    {
        if(departman_sayilari[i] > departman_sayilari[max_index])
        {
            max_index = i;
        }
    }
    printf("Departman: %s\n", departmanlar[max_index]);
}

int main()
{
    //menü kismi
	printf("\n");
	printf("                                        **************************\n");
	printf("                                        *                        *\n");
	printf("                                        *     personel sistemi   *\n");
	printf("                                        *                        *\n");
	printf("                                        **************************\n");

	printf("_______________________________________________________________________________________________________________ \n");
	printf("|   1:yonetici secilen calisanin bilgilerini ekrana yaz.                                                        |\n");
	printf("|   2:en yuksek maas alan calisanin adini ve maasini yaz.                                                       |\n");
	printf("|   3:en fazla ek maas alan calisanin adi ve departmanini ekranda goster.                                       |\n");
	printf("|   4:deneyim yili 1'den fazla olan calisanlardan en az izin kullanan calisanin adi ve soyadi ekranda goster.   |\n");
	printf("|   5:calisan sayisi en fazla olan departmani ekrana yaziniz.                                                   |\n");
	printf("|   6:cikis.                                                                                                    |\n");
	printf("|_______________________________________________________________________________________________________________|\n");


    // Dosyayi aç
    FILE*dosya;
    dosya = fopen("personel.txt", "r");

    FILE* yeni_dosya;
    yeni_dosya= fopen("yeniPersonel.txt", "w");

    if (dosya == NULL)
    {
        printf("Dosya acilamadi.\n");
        return;
    }

    Calisan calisanlar[15];

    int i = 0;
//maas hesaplari
    while(fscanf(dosya, "%d %s %s %s %d %d %d", &calisanlar[i].id, calisanlar[i].ad, calisanlar[i].soyad,
                  calisanlar[i].departman, &calisanlar[i].izin, &calisanlar[i].deneyim, &calisanlar[i].maas) != EOF)
    {
        calisanlar[i].yeni_maas = calisanlar[i].maas;
        if(strcasecmp("iletisim", calisanlar[i].departman) == 0)//bu fonksiyon buyuk kucuk harf uyumu aramadan belirtilen metni arar
        {
            calisanlar[i].yeni_maas = calisanlar[i].maas-(calisanlar[i].maas*5)/100;

        }

        if(strcasecmp(calisanlar[i].departman, "Bilisim") == 0 && calisanlar[i].deneyim > 5)
        {
            calisanlar[i].yeni_maas = calisanlar[i].maas +(calisanlar[i].maas*5)/100;

        }

        if(calisanlar[i].deneyim>1 &&  0<calisanlar[i].izin < 30)
        {
            calisanlar[i].yeni_maas = calisanlar[i].yeni_maas+(30 - calisanlar[i].izin) * 100;
        }
        else if(calisanlar[i].izin > 30)
        {
            calisanlar[i].yeni_maas -= (calisanlar[i].izin - 30) * 100;
        }



        if(calisanlar[i].deneyim > 5)
        {
            calisanlar[i].yeni_maas =calisanlar[i].yeni_maas+ 200;
        }

        i++;
    }

     if (yeni_dosya == NULL)
    {
        printf("Dosya acilamadi.\n");
        return 1;
    }
//personel.txt ye bilgileri yazan fonksiyon
    for(int j = -1; j < 15; j++)
    {
        fprintf(yeni_dosya, "%-15d %-15s %-15s %-15s %-15d %-15d %-15d %-15d\n",
        calisanlar[j].id,
        calisanlar[j].ad,
        calisanlar[j].soyad,
        calisanlar[j].departman,
        calisanlar[j].izin,
        calisanlar[j].deneyim,
        calisanlar[j].maas,
        calisanlar[j].yeni_maas);
    }

    fclose(yeni_dosya);
    fclose(dosya);

  int secim;
do{
        printf("\n Bir secenek girin:");
        scanf("%d", &secim);

        switch(secim) {
            case 1:
               Byonetici(calisanlar, i);

                break;
            case 2:
                 en_yuksek_maas(calisanlar, i);
                break;
            case 3:
                en_fazla_ek_maas(calisanlar, i);
                break;
            case 4:
                en_az_izin_kullanan(calisanlar, i);
                break;
            case 5:
                en_fazla_calisan_departman(calisanlar, i);
                break;
            case 6:
                exit(0);
            default:
                printf("aralik disinda deger girdiniz!\n");
                break;

        }
}while(secim!=6);

    return 0;
}
