/** 
 * 
 * @author Sinan Urgun G171210015 
 * 
 * @since 21.04.2020
 * <p>  
 *  Rastgele ImeiNo uretip bunu kontolunu yapmaktadir.
 * </p>  
 */
#include "IMEINo.h"


IMEINo _IMEINO()
{
	IMEINo imeiNo;
	imeiNo=(IMEINo)malloc(sizeof(struct IMEINO));
	imeiNo->IMEINo=malloc(sizeof(int)*15);
	imeiNo->IMEINoOlustur=&_IMEINoOlustur;
	imeiNo->IMEINo_Kontrol=&_IMEINokontrol;
	imeiNo->IMEINo_Yazdir=&_IMEINoYazdir;
	imeiNo->ImeiYokEt=&_ImeiYokEt;
	return imeiNo;
}



void _IMEINoOlustur(IMEINo imeino)//Imeino ureten fonksiyon
{
	int tek=0;
	int cift=0;
	
	int dizi[15];//IMEINO icin dizi
	
	for(int i=0;i<15;i++)//dizinin 14 elemanini rastgele atama yapmaktayiz.
		dizi[i]=rand()%10;
		
	for(int i=0;i<14;i+=2)//tek indexli sayilarin toplami
		tek+=dizi[i];
		
	for(int i=1;i<14;i+=2)//cift indexli sayilarin Toplami
		cift+=((dizi[i]*2)%10+(dizi[i]*2)/10);
		
	int toplam=tek+cift;
	int kontrolBitleri=toplam;//Toplamlari kontrol bitlerini verir.
	
	while(kontrolBitleri%10!=0)
		kontrolBitleri++;
	
	int sonRakam=kontrolBitleri-toplam;
	
	dizi[14]=sonRakam;
	
	for(int i=0;i<15;i++)
		imeino->IMEINo[i]=dizi[i]+'0';
	
	imeino->IMEINo[15]='\0';
}
int _IMEINokontrol(char* dizi)//ImeiNo yu kontrol eden fonksiyon
{
	int sayac=0;
	int sonKarakter;
	int IMEINODizisi[15];//Imei no icin dizimiz
	
	for(int i=0;i<strlen(dizi);i++)
	{
		if(dizi[i]=='(')
		{
			for(int j=i+1;j<=i+15;j++)
			{
				IMEINODizisi[sayac]=dizi[j]-'0';
				sayac++;
				sonKarakter=j;
			}
			break;
		}
	}
	int tek=0;
	int cift=0;
	
	for(int i=0;i<14;i+=2)//tek indexli sayilarin toplami		
			tek+=IMEINODizisi[i];
		
	for(int i=1;i<14;i+=2)//tek indexli sayilarin toplami
		cift+=((IMEINODizisi[i]*2)%10+(IMEINODizisi[i]*2)/10);
		
	int toplam=tek+cift;
	int kontrolBitleri=toplam;//Toplamlari kontrol bitlerini verir.
	
	while(kontrolBitleri%10!=0)
		kontrolBitleri++;
	
	char sonRakam=(kontrolBitleri-toplam)+'0';
	
	return dizi[sonKarakter]==sonRakam?1:0;
}

char* _IMEINoYazdir(IMEINo imeino)//Imeino yazdirmak icin gerekli
{
	return imeino->IMEINo;
}
void _ImeiYokEt(IMEINo imeino)//Gerekli pointerları silme
{
	if(imeino == NULL) return; 
	free(imeino ->IMEINo);
	free(imeino); 
	
}


