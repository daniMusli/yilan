#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

char yilan= 'X'; // yilan tahtada X isaretiyle gosterecegiz
char yeme = '*'; // yeme tahtada * isaretiyle gosterecegiz
int  tahta[12][12]; // bizden istenildigi gibi tahta 12x12 iki boyutlu dizide tuttuk
char hareketKarekteri; // kullancinin girecegi w a s d 
int satirCounter = 0 ;// satirlarin sayaci kullanci w veya s girdigindi yilanin yeri kontrol etmek icin kullanilir
int sutunCounter = 0; // sutunlarin sayaci kullanci a veya d girdigindi yilanin yeri kontrol etmek icin kullanilir
int yemeXkordinator; // yemenin birinci kordinat icin tahta[yemeXkordinator][] rastgele uretilen sayi
int yemeYkordinator; // yemenin ikinci kordinat icin tahta[][yemeYkordinator] rastgele uretilen sayi
char tekrar; // kullanci tekrar oynamak isterse 
void yilanOyunu();// tahtanin elemanlari bilirtmek icin kullandigimiz fonksiyon
void tahtayiCiz();// tahtanin cizmek icin kullandigimiz fonksiyon

int main(int argc, char *argv[]) {
// oyun her zaman tekrar edebilicigi sekilde programin tumu bir sonsuz dngude tuttuk program sonlamak icin exit komutu kullandik 
	while(1)
	{
	clock_t begin = clock(); // oyunun basladigi anda zaman hesaplar
	satirCounter=0; // her oyun basladiginda yilan yeri tahta[1][2] 
    sutunCounter=0;//her oyun basladiginda yilan yeri tahta[1][2] 
	system("cls");// ekrani temizle
	
	int hak =3; // kullancin 3 tane duvara carpi hakki var
	srand(time(NULL)); // oyunun her calistiginda yeme farkli bir yer gozuksun
	yemeXkordinator = 2+rand() % 9; // 2 ile 10 arasi bir rastegel sayi uretsin
	yemeYkordinator = 2+rand() % 9; //2 ile 10 arasi bir rastegel sayi uretsin mesela yeme 6x6 de ise tahta[6][6]
    yilanOyunu();
    tahtayiCiz();
    while(1)
    {
    hareketKarekteri=getchar();// kullancinin istedigi yilanin hareketi al
    // w a s d q durumlari kontrol etmek
	if(hareketKarekteri=='s' || hareketKarekteri=='S')
	{
	tahta[1+satirCounter][2+sutunCounter]='.';
	satirCounter++;	
	tahta[1+satirCounter][2+sutunCounter]= yilan;
	system("cls");
	tahtayiCiz();
	
    }
    else if(hareketKarekteri=='a' || hareketKarekteri=='A')
    {
     tahta[1+satirCounter][2+sutunCounter]='.';
	 sutunCounter--;	
	 tahta[1+satirCounter][2+sutunCounter]= yilan;
     system("cls");
	 tahtayiCiz(); 
	}
    else if(hareketKarekteri=='w' || hareketKarekteri=='W')
    {
	tahta[1+satirCounter][2+sutunCounter]='.';
	satirCounter--;	
	tahta[1+satirCounter][2+sutunCounter]= yilan;
	system("cls");
	tahtayiCiz(); 
	}
    else if(hareketKarekteri=='d' || hareketKarekteri=='D')
    {
     tahta[1+satirCounter][2+sutunCounter]='.';
	 sutunCounter++;	
	 tahta[1+satirCounter][2+sutunCounter]= yilan;
     system("cls");
	 tahtayiCiz(); 
	 
	}
	else if(hareketKarekteri=='q' || hareketKarekteri=='Q')
	{
		printf("q tusuna bastiniz oyun sonlanir....");
		exit(0);
		
	}
   // eger yilanin ve yemenin kordinat ayni olursa 
	if(((1+satirCounter)==yemeXkordinator)&&((2+sutunCounter)==yemeYkordinator))
	{
		printf("Tebrikler Kazandiniz !!!");
		printf("\nTekrar oynamak istiyor musunuz(evet ise e tusuna basiniz hayir ise h):");
        scanf(" %c",&tekrar);
	    if(tekrar=='e'|| tekrar=='E')
	     break;
	    else if(tekrar == 'h' || tekrar=='H'){
	    	printf("oyun sonlanir......");
	    	 exit(0);
		}
	  
	}
	if(sutunCounter==9)// eger sagdaki duvari carpmissa 
	{
	hak--; 
	
	tahta[1+satirCounter][2+sutunCounter]='|';
	tahta[1+satirCounter][2+sutunCounter-1]='X';
	sutunCounter--;
	system("cls");
	tahtayiCiz();
	}
	if(satirCounter==10)// eger alttaki duvari carpmissa
	{
	hak--;
	tahta[1+satirCounter][2+sutunCounter]='-';
	tahta[1+satirCounter-1][2+sutunCounter]='X';
	satirCounter--;	
	system("cls");
	tahtayiCiz();
	}
	if(sutunCounter==-2)// eger usteki duvari carpmissa
	{
	hak--;
	tahta[1+satirCounter][2+sutunCounter]='|';
	tahta[1+satirCounter][2+sutunCounter+1]='X';
	sutunCounter++;
	system("cls");
	tahtayiCiz();
	}
	if(satirCounter==-1)// eger soldaki duvari carpmissa
	{
	hak--;
	tahta[1+satirCounter][2+sutunCounter]='-';
	tahta[1+satirCounter+1][2+sutunCounter]='X';
	satirCounter++;
	system("cls");
	tahtayiCiz();
	}		
	if(hak==0)// eger kullancinin haklari birmisse
	{
    	printf("\nuc hakkiniz tamamladiniz");
		printf("\nTekrar oynamak istiyor musunuz(evet ise e tusuna basiniz hayir ise h):");
        scanf(" %c",&tekrar);
	    if(tekrar=='e'|| tekrar=='E')
	     break;
	    else if(tekrar == 'h' || tekrar=='H'){
	    	printf("oyun sonlanir......");
	    	 exit(0);
		}
	}	
	clock_t end = clock();	// bu islemler bittikten sonra zamani hesaplanir
    float elapsed_secs = (float)(end - begin) / CLOCKS_PER_SEC;// gecen zamani saniye cinsiden hesaplamak icin
    if(elapsed_secs>=12.000000){
    	printf("\nsize verilen surede oyunu tamamlayamadiniz.");
    	exit(0);
	}
    
    
	}

	
	}

	return 0;
}
void yilanOyunu()
{
	
	int i,j;

	
	for(i = 0 ; i<12;i++)
	{
		for(j=0;j<12;j++)
		{
			if(i==0||i==11)
			tahta[i][j]='-';
            else if(j==0 || j==11)
            tahta[i][j]='|';
			else if(i==1 && j==2)
			tahta[i][j]= yilan;
			else if(i==yemeXkordinator && j==yemeYkordinator)
			tahta[i][j]= yeme;	
			else 
			tahta[i][j]='.';
		}
				
		
	}

}
void tahtayiCiz()
{
	printf("yilan Oyununa Hos geldiniz hareket icin wasd tuslarini kullaniniz.\n\n");
	int i,j;
	for(i = 0 ; i<12;i++)
	{
		for(j=0;j<12;j++)
		{	
		printf("%c",tahta[i][j]);
	}
	printf("\n");
	
    }
printf("\n");
}
