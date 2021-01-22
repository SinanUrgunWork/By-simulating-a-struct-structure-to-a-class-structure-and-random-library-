/** 
 * 
 * @author Sinan Urgun G171210015 
 * 
 * @since 21.04.2020
 * <p>  
 *  Random Tc kimlik numarasi ureten ve sorgulayan sinif.
 * </p>  
 */
#include "KimlikNo.h"

KimlikNo _Kimlik()
{
	KimlikNo kimlik;
	kimlik=(KimlikNo)malloc(sizeof(struct KIMLIKNO));
	kimlik->TcNo=malloc(sizeof(int)*11);
	kimlik->TcNoOlustur=&_TcNoOlustur;
	kimlik->Tc_Kontrol=&_TcKontrol;
	kimlik->Tc_Yazdir=&_TcYazdir;
	kimlik->TcYokEt=&_TcYokEt;
	return kimlik;
}



void _TcNoOlustur(KimlikNo tc)//Random tc no ureten fonksiyon
{
	int TcNumarasi[11];//Tc icin dizi
	int tek=0;
	int cift=0;
	
	int onuncu,onbirinici;
	
	TcNumarasi[0]=(1+rand()%9);//0dan farkli 9a kadar random sayı veriri.
	for(int i=1;i<9;i++)
		TcNumarasi[i]=rand()%9;
	
      //Son iki rakam konrol bitleridir.
	
	int i;
	for(i=0;i<9;i+=2)
		tek+=TcNumarasi[i];
	for(i=1;i<8;i+=2)
		cift+=TcNumarasi[i];
	onuncu=((tek*7)-cift)%10; //10. sayiyi bulma
	TcNumarasi[9]=onuncu;
	
	
	
	int sayi=0;
	for(i=0;i<10;i++)
		sayi+=TcNumarasi[i];
	
	onbirinici=sayi%10;
	TcNumarasi[10]=onbirinici;//11. sayıyı bulma
	
	for(int i=0;i<11;i++)
		tc->TcNo[i]=TcNumarasi[i]+'0';
	
}
int _TcKontrol(char* dizi) //tc kontrol fonksiyonu
{
	int TcNumarasi[11];//Tc icin dizi
	
	for(int i=0;i<11;i++) //Dizi boyutu 11 olmali
		TcNumarasi[i]=dizi[i]-'0';
	
	int tek=0;
	int cift=0;
	char onuncu,onbirinici;
//Kontol bitlerinin kontrolu yapilir.
//Tek isndililerin 7 ile çarpimindan cifleri çıkarirsak ve bunun 10 uzerinden modunu alirsak 10. sayiyi verir bize.
	int i;
	for(i=0;i<9;i+=2)
		tek+=TcNumarasi[i];
	for(i=1;i<8;i+=2)
		cift+=TcNumarasi[i];
	onuncu=(((tek*7)-cift)%10)+'0';
	
	
	int sayi=0;
	for(i=0;i<10;i++)
	{
		sayi+=TcNumarasi[i];
	}
	onbirinici=(sayi%10)+'0';
	
	return dizi[9]==onuncu && dizi[10]==onbirinici?1:0;
}
char* _TcYazdir(KimlikNo tc)//Tc yazdirma fonksiyonu
{
	return tc->TcNo;
}
void _TcYokEt(KimlikNo kimlik)
{
	if(kimlik==NULL)return;
	free(kimlik->TcNo);
	free(kimlik);
}
