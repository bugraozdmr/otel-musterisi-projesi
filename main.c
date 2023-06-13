#include <stdio.h>
#include <stdlib.h>


int ikili=0,kh=0;

struct musteriler {
	char isim[20], soyisim[20];
	int kahvalti, aksam, otel, arkadas;
};

void ikiyildiz(struct musteriler a) {
	if (a.otel == 1) ikili++;
}




void kahvalti(struct musteriler a) {
	if (a.kahvalti == 1) kh++;
}

void ucret(struct musteriler a) {
	int o = 0;
	//kahvalti arkada aramasi
	if (a.kahvalti == 1 && a.arkadas == 1) o += 30;
	if (a.kahvalti == 1 && a.arkadas == 0) o += 15;
	//otel hizmeti aramasi
	if (a.otel == 2) o += 100;
	if (a.otel == 1) o += 75;
	//aksam yemegi aramasi
	if (a.aksam == 1) o += 35;
	printf("%s %s isimli musteri %d euro odeyecektir.\n", a.isim, a.soyisim, o);
	
}

void iki_yildiz_bilgiler(struct musteriler a) {
	if (a.otel == 1) {
		int k = 0;		//ucret hesaplayalim
		printf("%s %s", a.isim, a.soyisim);
		if (a.kahvalti == 1) printf(" kahvalti aliyor");
		else printf(" kahvalti almiyor");
		printf("\nodeyecegi ucret:");
		if (a.kahvalti == 1 && a.arkadas == 1) k += 30;
		if (a.kahvalti == 1 && a.arkadas == 0) k += 15;
		
		if (a.aksam == 1) k += 35;

		printf(" %d euro\n", k + 75);	//iki yildiz parasi eklendi
	}
}

//bu kodu anlamak zor

int main(){
	struct musteriler musteri[5];
	int a, b, c, d;
	for (int i = 0; i < 5; i++) {
		printf("%d.musteri\n", i + 1);
		int e = 0;
		printf("isim:"); fgets(musteri[i].isim, sizeof(musteri[i].isim), stdin);
		if (musteri[i].isim[strlen(musteri[i].isim) - 1] == '\n') {		//null terminating
			musteri[i].isim[strlen(musteri[i].isim) - 1] = '\0';
		}
		printf("***************************\n");
		printf("soyisim:"); fgets(musteri[i].soyisim, sizeof(musteri[i].soyisim), stdin);
		if (musteri[i].soyisim[strlen(musteri[i].soyisim) - 1] == '\n') {		//null terminating
			musteri[i].soyisim[strlen(musteri[i].soyisim) - 1] = '\0';
		}
		printf("***************************\n");
		while (e == 0) {
			printf("kahvalti alacak misin? (0/1):"); scanf("%d", &a);
			if (a == 1 || a == 0) {
				musteri[i].kahvalti = a;
				e = 1;
			}
			else printf("0 ya da 1 girin !..\n");
		}e = 0; //yoksa donguler calismaz..
		printf("***************************\n");
		while (e == 0) {
			printf("aksam yemegi alacak misin? (0/1):"); scanf("%d", &b);
			if (b == 1 || b == 0) {
				musteri[i].aksam = b;
				e = 1;
			}
			else printf("0 ya da 1 girin !..\n");
		}e = 0; //yoksa donguler calismaz..
		printf("***************************\n");
		while (e == 0) {
			printf("hangi otel hizmetini almak istiyorsunuz?\n1.\t2 yildizli(75 euro)\n2.\t3 yildizli(100 euro)\n3.\talmak istemiyorum\n(1/2/3):"); scanf("%d", &c);
			if (c == 1 || c == 2 || c == 3) {
				musteri[i].otel = c;
				e = 1;
			}
			else printf("1 ya da 2 ya da 3 girin !..\n");
		}e = 0; //yoksa donguler calismaz..
		printf("***************************\n");
		if (c != 3 && a != 0) {
			while (e == 0) {
				printf("arkadasin var mi ? (0/1):"); scanf("%d", &d);
				if (d == 1 || d == 0) {
					musteri[i].arkadas = d;
					e = 1;
				}
				else printf("0 ya da 1 girin !..\n");
			}
		}
		else musteri[i].arkadas = 0;
		
		getchar();		//yoksa hata alacaktir
		printf("***************************\n");
		ikiyildiz(musteri[i]);		//her seferinde cagrilacak zaten
		kahvalti(musteri[i]);
	}

	
	printf("\n\nkahvalti yapan musteri sayisi:%d\n", kh);
	printf("==================\n");

	
	printf("%d.kisi iki yildizli odada kalmakta\n", ikili);

	for (int i = 0; i < 5; i++) {
		iki_yildiz_bilgiler(musteri[i]);
	}
	printf("==================\n");
	for (int i = 0; i < 5; i++) {
		ucret(musteri[i]);
	}
	printf("==================\n");

}


