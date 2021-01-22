/** 
 * 
 * @author Sinan Urgun G171210015 
 * 
 * @since 21.04.2020
 * <p>  
 *  Kisi sinifi tasarimi
 * </p>  
 */
#ifndef KISI_H
#define KISI_H

#include "KimlikNo.h"
#include "Telefon.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"
//Degisken tanimlamalari yapildi
//Fonksiyon gostericilerden yararlanildi.
struct KISI
{
	KimlikNo TcNo;
	char* AdSoyad;
	int Yas;
	Telefon telefon;
	void (*KisiOlustur)(struct KISI*);
	void(*RandomAdSoyad)(struct KISI*);
	void(*RandomYas)(struct KISI*);
	char*(*AdYazdir)(struct KISI*);
	int(*YasYazdir)(struct KISI*);
	void(*KisiYokEt)(struct KISI*);
};
typedef struct KISI* Kisi;
//Fonksiyonlar tanimlandi.
Kisi _Kisi();
void _KisiOlustur(Kisi);
void _RandomAdSoyad(Kisi);
void _RandomYas(Kisi);
char* _AdYazdir(Kisi);
int _YasYazdir(Kisi);
void _KisiYokEt(Kisi);

#endif
