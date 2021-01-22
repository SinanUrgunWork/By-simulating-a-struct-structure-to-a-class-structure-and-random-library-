/** 
 * 
 * @author Sinan Urgun G171210015 
 * 
 * @since 21.04.2020
 * <p>  
 *  Rastgele telefon ureten sinif
 * </p>  
 */
#include "Telefon.h"
Telefon _Telefon()
{
	Telefon telefon;
	telefon=(Telefon)malloc(sizeof(struct TELEFON));
	telefon->telefonNumarasi=malloc(sizeof(char)*11);
	telefon->TelefonOlustur=&_TelefonOlustur;
	telefon->Telefon_Yazdir=&_TelefonYazdir;
	telefon->IMEINumarasi=_IMEINO();
	telefon->TelefonYokEt=&_TelefonYokEt;
	return telefon;
	
}


void _TelefonOlustur(Telefon t)//Random telefon no atanacak
{
	
	int tel[11];//11 haneli tc dizisi
       //telefon operetaorleri
	int operatorler[]={540,541,542,543,544,545,546,547,548,549,505,506,507,551,552,553,554,555,556,557,558,559,530,532,533,534,535,536,537,538,539};
	int optr=operatorler[rand()%31];
	
	tel[0]=0;//ilk 0 ile baslar
	//gsm icinde random secicek
	tel[1]=optr/100;
	tel[2]=(optr/10)%10;
	tel[3]=optr%10;
	for(int i=4;i<11;i++)//diger sayilari random atama
		tel[i]=rand()%10;
		
	for(int i=0;i<11;i++)
		t->telefonNumarasi[i]=tel[i]+'0';
	
	t->telefonNumarasi[11]='\0';
	t->IMEINumarasi->IMEINoOlustur(t->IMEINumarasi);//Kalitimla Imei no olusturma
}

char* _TelefonYazdir(Telefon t)//Telefon no yazdirma
{
	return t->telefonNumarasi;
}

void _TelefonYokEt(Telefon t)
{
	if(t==NULL)return;
	t->IMEINumarasi->ImeiYokEt(t->IMEINumarasi);
	free(t->telefonNumarasi);
	free(t);
}
