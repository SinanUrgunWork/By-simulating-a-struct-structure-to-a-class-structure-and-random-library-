/** 
 * 
 * @author Sinan Urgun G171210015 
 * 
 * @since 21.04.2020
 * <p>  
 * ImeiNo sinifi 
 * </p>  
 */
#ifndef IMEINO_H
#define IMEINO_H
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"
//Gerekli degisken tanimlamalari yapildi
//Fonksiyon gostericilerden yararlanildi.
struct IMEINO
{
	char* IMEINo;
	void(*IMEINoOlustur)(struct IMEINO*);
	int(*IMEINo_Kontrol)(char*);
	char*(*IMEINo_Yazdir)(struct IMEINO*);
	void(*ImeiYokEt)(struct IMEINO*);
};
typedef struct IMEINO* IMEINo;
//Gerekli fonksiyon tanimlamalari yapildi
IMEINo _IMEINO();
void _IMEINoOlustur(IMEINo);
int _IMEINokontrol(char*);
char* _IMEINoYazdir(IMEINo);
void _ImeiYokEt(IMEINo);

#endif
