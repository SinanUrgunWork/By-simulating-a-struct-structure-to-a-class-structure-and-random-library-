/** 
 * 
 * @author Sinan Urgun G171210015 
 * 
 * @since 21.04.2020
 * <p>  
 *  Telefon sinifi tasarimi
 * </p>  
 */
#ifndef TELEFON_H
#define TELEFON_H
#include "IMEINo.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
//Degikenler tanimlandi
//Fonksiyon gostericilerden yararlanildi.
struct TELEFON
{
	char* telefonNumarasi;
	IMEINo IMEINumarasi;
	void(*TelefonOlustur)(struct TELEFON*);
	char*(*Telefon_Yazdir)(struct TELEFON*);
	void (*TelefonYokEt)(struct TELEFON*);
};

typedef struct TELEFON* Telefon;
//Fonksiyonlar tanimlandi.
Telefon _Telefon();
void _TelefonOlustur(Telefon);
char* _TelefonYazdir(Telefon);
void _TelefonYokEt(Telefon);


#endif
