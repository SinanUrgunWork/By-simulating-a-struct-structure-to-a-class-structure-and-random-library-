/** 
 * 
 * @author Sinan Urgun G171210015 
 * @since 21.04.2020
 * <p>  
 *  Rastgele kisi ureten sinif
 * </p>  
 */
#ifndef RASTGELEKISI_H
#define RASTGELEKISI_H
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "Kisi.h"
//Degiskenler tanimlandi
//Fonksiyon gostericilerden yararlanildi.
struct RASTGELEKISI
{
	Kisi kisi;
	void(*Random_Kisi)(struct RASTGELEKISI*);
	void(*Dosya_Yazdir)(struct RASTGELEKISI*,char*);
	void(*Kontrol)(struct RASTGELEKISI*,char*);
	void(*Yok_Et)(struct RASTGELEKISI*);
};
typedef struct RASTGELEKISI* RastgeleKisi;
//Fonksiyonlar tanimlandi
RastgeleKisi _RastgeleKisi();
void _RandomKisi(RastgeleKisi);
void _DosyayaYazdir(RastgeleKisi,char*);
void _Kontrol(RastgeleKisi,char*);
void _YokEt(RastgeleKisi);

#endif
