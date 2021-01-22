/** 
 * 
 * @author Sinan Urgun G171210015 
 * @since 21.04.2020
 * <p>  
 *  Rasgele kisi ureten sinif ve konrol islemini toplu olarak burada yapilmaktadir
 * </p>  
 */
#include "RastgeleKisi.h"

RastgeleKisi _RastgeleKisi()
{
	RastgeleKisi rastgeleKisi;
	rastgeleKisi=(RastgeleKisi)malloc(sizeof(struct RASTGELEKISI));
	rastgeleKisi->kisi=_Kisi();
	rastgeleKisi->Random_Kisi=&_RandomKisi;
	rastgeleKisi->Dosya_Yazdir=&_DosyayaYazdir;
	rastgeleKisi->Kontrol=&_Kontrol;
	rastgeleKisi->Yok_Et=&_YokEt;
	return rastgeleKisi;
}
void _RandomKisi(RastgeleKisi rk)//kisi sıifinda kalitim alarak kisi olusturur
{
	rk->kisi->KisiOlustur(rk->kisi);
}

void _DosyayaYazdir(RastgeleKisi rastgeleKisi,char* dosyaAdi)//Uretilen kisileri belirli bir yazim formatinda dosyaya yazdirmaktadir
{
	
	FILE *dosya = fopen(dosyaAdi, "a");
	if (dosya== NULL)
	{
		printf("Dosya bulunamadi!\n");
		return;
	}
//Kalitim kullanarak kisi, telefon, imei, tc siniflarindaki fonksiyonlari cagirdik.
	char *kimlikNo=rastgeleKisi->kisi->TcNo->Tc_Yazdir(rastgeleKisi->kisi->TcNo);
	char *AdSoyad=rastgeleKisi->kisi->AdYazdir(rastgeleKisi->kisi);
	int yas=rastgeleKisi->kisi->YasYazdir(rastgeleKisi->kisi);
	char *TelefonNo=rastgeleKisi->kisi->telefon->Telefon_Yazdir(rastgeleKisi->kisi->telefon);
	char *IMEIno=rastgeleKisi->kisi->telefon->IMEINumarasi->IMEINo_Yazdir(rastgeleKisi->kisi->telefon->IMEINumarasi);
	
	if(kimlikNo!=NULL && AdSoyad!=NULL && TelefonNo!=NULL && IMEIno!=NULL)
	fprintf(dosya,"%s %s %d %s (%s)\n",kimlikNo,AdSoyad,yas,TelefonNo,IMEIno);
	else
	{
		printf("Sistemde hata olusdu");
	}
	fclose(dosya);
}

void _Kontrol(RastgeleKisi rk,char* dosyaAdi) //Tc ve Imei no kontrolu yapan fonksiyon
{
	 
//Kalitim kullanarak tc ve imei siniflarindaki kontrol fonksiyonlarini burada cagiri
//Dosyayi okuyup kontrol yapmaktadir
        int sayac =0;  
	int gecerliTcNo=0;
	int gecersizTcNo=0;
	
	int gecelriImeiNo=0;
	int gecersizImeiNo=0;
	
	char str[150];
	FILE *dosya=fopen(dosyaAdi,"r");
	if(dosya==NULL)
	{
		printf("Kontrol edilecek dosya bulunmadi!\n");
		return;
	}
	while(!feof(dosya))
	{
		if(fgets(str,150,dosya)!=NULL)
		{
			int validKimlik=rk->kisi->TcNo->Tc_Kontrol(str);
			int validIMEI=rk->kisi->telefon->IMEINumarasi->IMEINo_Kontrol(str);
			
			if(validKimlik==1)
				gecerliTcNo++;
			
			else if(validKimlik==0)
				gecersizTcNo++;
			
			if(validIMEI==1)
				gecelriImeiNo++;
			
			else if(validIMEI==0)
				gecersizImeiNo++;
			
			sayac++;
		}
	}
	if(sayac<=0)
	{
		printf("Dosya bos!\n");
	}
	else
	{
		printf("\nTCKimlik\nGecerli : %d\nGecersiz : %d\n\nIMEINO\nGecerli : %d\nGecersiz : %d\n\n",gecerliTcNo,gecersizTcNo,gecelriImeiNo,gecersizImeiNo);
	}
	fclose(dosya);
	

}

void _YokEt(RastgeleKisi rk)
{
	if(rk==NULL)return;
	rk->kisi->KisiYokEt(rk->kisi);
	free(rk);
}




