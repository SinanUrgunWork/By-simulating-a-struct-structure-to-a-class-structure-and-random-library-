/** 
 * 
 * @author Sinan Urgun G171210015 
 * 
 * @since 21.04.2020
 * <p>  
 *  Kisileri random_isimer.txt dosyasindan belirli bir formatta alan sinif.
 * </p>  
 */
#include "Kisi.h"
Kisi _Kisi()
{
	Kisi kisi;
	kisi=(Kisi)malloc(sizeof(struct KISI));
	kisi->AdSoyad=malloc(sizeof(char)*25);
	kisi->KisiOlustur=&_KisiOlustur;
	kisi->RandomAdSoyad=&_RandomAdSoyad;
	kisi->RandomYas=&_RandomYas;
	kisi->AdYazdir=&_AdYazdir;
	kisi->YasYazdir=&_YasYazdir;
	kisi->KisiYokEt=&_KisiYokEt;
	kisi->TcNo=_Kimlik();
	kisi->telefon=_Telefon();
	return kisi;
}
void _KisiOlustur(Kisi k)
{	k->RandomAdSoyad(k);
	k->RandomYas(k);
	k->TcNo->TcNoOlustur(k->TcNo);
	k->telefon->TelefonOlustur(k->telefon);
}
void _RandomAdSoyad(Kisi k)//Random kisi olusturma fonksiyonu
{
	int randomIsim=rand()%3000;
	FILE *dosya=fopen("random_isimler.txt","r");//random_isimler dosyasini okur ve bunu kisiledeki adsoay degiskenine atar
	int sayac =0;
	char AdSoyad[25];
	while(!feof(dosya))
	{
		fgets(AdSoyad,25,dosya);
		if(sayac==randomIsim)
		{
			AdSoyad[strlen(AdSoyad)-1]='\0';
			strcpy(k->AdSoyad,AdSoyad);
		}
		sayac++;
	}
	fclose(dosya);
}
void _RandomYas(Kisi k)//0 ile 100 arasinda random yas olusturur
{
	k->Yas=1+rand()%100;
}

char* _AdYazdir(Kisi k)//Ad ve soyadi yazdirir
{
	return k->AdSoyad;
}
int _YasYazdir(Kisi k)//Yasi yazdirir
{
	return k->Yas;
}
void _KisiYokEt(Kisi k)
{
	if(k==NULL)return;
	k->TcNo->TcYokEt(k->TcNo);
	k->telefon->TelefonYokEt(k->telefon);
	free(k->AdSoyad);
	free(k);
}


