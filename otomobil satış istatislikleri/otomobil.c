#include <stdio.h>
#include <stdlib.h>

//markanin toplam satisini main fonksiyonundan alip sirali bir sekilde yazdiran fonksiyon
int fonk1(int b[5])
{
	int i;

	for (i = 0; i < 5; i++)
	{
		printf("\n %d. markanin toplam satisi:%d", i + 1, b[i]);
	}
	return 0;
}

//markanin toplam sati ini main fonksiyonundan alip aylik satis miktarini yazdiran fonksiyon
int fonk2(int c[5])
{
	int j;

	for (j = 0; j < 3; j++)
	{
		printf("\n %d. ayda yapilan satis:%d", j + 1, c[j]);
	}
	return 0;
}

//main fonksiyonundan matrisi ay'i ve marka ismini alan belirli firmanin hangi ayda en  ok satis yaptigini bulan fonksiyon
void fonk3(int a[5][3], char* ay[3], char* marka[5])
{
	int max = 0;
	int ay_index = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (a[i][j] > max)
			{
				max = a[i][j];
				ay_index = j;
			}
		}
		printf("\n %d.firma icin en cok satis yapilan ay: %s", i + 1, ay[ay_index]);
		max = 0;
	}
}

//main fonksiyonundan matrisi ay'i ve marka ismini alan belirli ayda hangi firmanin  en  ok satis yaptsgini bulan fonksiyon
void fonk4(int a[5][3], char* ay[3], char* marka[5])
{
	int max = 0, i, j;
	int ay_index = 0;

	for (j = 0; j < 3; j++)
	{
		for (i = 0; i < 5; i++)
		{
			if (a[i][j] > max)
			{
				max = a[i][j];
				ay_index = i;
			}
		}
		printf("\n %d.ay  icin en cok satis yapilan marka: %s", j + 1, marka[ay_index]);
		max = 0;
	}
}

//matrisi alip toplam satis miktarini belirleyen fonksiyon
void fonk5(int a[5][3])
{
	int toplam = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			toplam = toplam + a[i][j];
		}
	}
	printf("\nyapilan toplam satis:%d", toplam);
}

int main()
{

	int a[5][3], sum[5] = { 0 }, toplam[5] = { 0 };
	int i, j;

	char* marka[5] = { "fiat","renault","vw","opel","ford" };
	char* ay[3] = { "ocak","subat","mart" };

	//matrisin degerlerini aliyoruz
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d . firma icin %d. ay satisini giriniz:", i + 1, j + 1);
			scanf("%d", &a[i][j]);
			sum[i] += a[i][j];
			toplam[j] += a[i][j];
		}
	}
	printf("_____________________________________________________________________ \n");

	//matrisin degerlerini formatli bir  ekilde yazdiriyoruz
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf(" %d ", a[i][j]);
		}
		printf("\n");
	}
	printf("_____________________________________________________________________ \n");

	//menu kismi
	printf("\n");
	printf("**************************\n");
	printf("*                        *\n");
	printf("*      QUiZ SORU 1       *\n");
	printf("*                        *\n");
	printf("**************************\n");

	printf("_____________________________________________________________________ \n");
	printf("|1:her marka icin 3 aylik satis toplami.                             |\n");
	printf("|2:her ay icin tum markalarin satis toplamlari.                      |\n");
	printf("|3:her marka icin en cok satisin gerceklestigi ay ve satis miktari.  |\n");
	printf("|4:her ay icin en cok satisin gerceklestigi marka ve satis miktari.  |\n");
	printf("|5:tum marka ve tum aylar icin otomobil satislari  toplami.          |\n");
	printf("|6:cikis.                                                            |\n");
	printf("|____________________________________________________________________|\n");

	//do while d ng s  ile islem se me kisminin devamli sorulmasini sagliyoruz
	int n, k;
	do {
		printf("\nyapilmak istenen islemi secin:");
		scanf("%d", &n);
		//islemleri belirli karakterler ile cagrilamsini sagliyoruz
		switch (n)
		{
		case 1:
			fonk1(sum);
			break;

		case 2:
			fonk2(toplam);
			break;

		case 3:
			fonk3(a, ay, marka);
			break;

		case 4:
			fonk4(a, ay, marka);
			break;

		case 5:
			fonk5(a);
			break;

		case 6:
			exit(0);
			break;
		}
	} while (k != 6);

	return 0;
}
