/** 
 * 
 * @author Sinan Urgun G171210015 
 * 
 * @since 21.04.2020
 * <p>  
 *  TcKimlikNo sinifi tasarimi
 * </p>  
 */
#ifndef KIMLIKNO_H
#define KIMLIKNO_H
#include "stdlib.h"
#include "stdio.h"
#include "time.h"
//Degisken tanimlamalari yapildi
//Fonksiyon gostericilerden yararlanildi.
struct KIMLIKNO
{
	char* TcNo;
	void(*TcNoOlustur)(struct KIMLIKNO*);
	int (*Tc_Kontrol)(char*);
	char* (*Tc_Yazdir)(struct KIMLIKNO*);
	void (*TcYokEt)(struct KIMLIKNO*);
};
typedef struct KIMLIKNO* KimlikNo;
//Fonksiyon tanimlamalari yapildi.
KimlikNo _Kimlik();
void _TcNoOlustur(KimlikNo);
int _TcKontrol(char*);
char* _TcYazdir(KimlikNo);
void _TcYokEt(KimlikNo);
#endif
