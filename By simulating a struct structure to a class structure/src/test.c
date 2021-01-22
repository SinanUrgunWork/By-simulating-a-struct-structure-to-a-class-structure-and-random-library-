/** 
 * 
 * @author Sinan Urgun G171210015 
 * 
 * @since 21.04.2020
 * <p>  
 *  Burada menu islemimiz var ve random kisi olusturup dosyaya yazdiriryoruz.
 * </p>  
 */
#include "RastgeleKisi.h"
#include "unistd.h"
int main()
{
	srand(time(NULL));
	RastgeleKisi randomKisi=_RastgeleKisi();//RastgeleKisi sinifi
	int secim;
	int adet;
	do{     
                //1. secim ile random kisiler olusturulur
		printf("1-Rastgele Kisi Olustur\n2-Dosya Kontrol Et\n3-Cikis\nSecim : ");
		scanf("%d",&secim);
		if(secim==1)
		{
			printf("Kac kisi uretilsin : ");//Kullanicidan kac kisi olusturulacagini aliriz
			scanf("%d",&adet);
			for(int i=0;i<adet;i++)
			{
				randomKisi->Random_Kisi(randomKisi);//Random kisi olusturma
				randomKisi->Dosya_Yazdir(randomKisi,"kisiler.txt");//uretilen kisi dosyaya kayit edilecek
				
			}
		}
		else if(secim==2)
			randomKisi->Kontrol(randomKisi,"kisiler.txt");//Tc ve imei kontrol
		else if(secim!=3)
			printf("Hatasli secim!\n");
	}while(secim!=3);
	randomKisi->Yok_Et(randomKisi);//Gereklipointerları yok etme
	return 0;
}
