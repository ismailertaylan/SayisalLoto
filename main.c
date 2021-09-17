#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); //Random sayi olustururken her seferinde farkli sayi gelmesi icin
    int kolonsayisi;
    printf("Kolon sayisi gir (1-10):\n");
    scanf("%d",&kolonsayisi); //kullanicidan kolon sayisini aliyoruz
    while(kolonsayisi<1 || kolonsayisi>10)
    {
        //Kullanici kolon sayisini (1-10) araliginda girmedigi surece tekrar soruyoruz
        printf("Kolon sayisi gir (1-10):\n");
        scanf("%d",&kolonsayisi);
    }
    int kolon[kolonsayisi][6]; //kolonlarimizi tutan 2 boyutlu dizi
    int i,j;
    for(i=0; i<kolonsayisi; i++) //kolonlarin icini doldurmaya baslayacagimiz dongu
    {

bastan:
        for(j=0; j<6; j++)
        {
            kolon[i][j]=random49();
            //once kolonlara rastgele sayilar atiyoruz, bunu random49 fonksiyonu ile yapiyoruz.
        }


        while(kolon[i][0]==kolon[i][1] || kolon[i][0]==kolon[i][2] || kolon[i][0]==kolon[i][3] || kolon[i][0]==kolon[i][4] || kolon[i][0]==kolon[i][5] ||
                kolon[i][1]==kolon[i][2] || kolon[i][1]==kolon[i][3] ||kolon[i][1]==kolon[i][4] || kolon[i][1]==kolon[i][5] || kolon[i][2]==kolon[i][3] ||
                kolon[i][2]==kolon[i][4] || kolon[i][2]==kolon[i][5] || kolon[i][3]==kolon[i][4] || kolon[i][3]==kolon[i][5] || kolon[i][4]==kolon[i][5])
        {
            //MADDE 2'deki her sayi birbirinden farkli olmali kosulunu saglayacak while yapisi ile
            //eger herhangi 2 sayi cakisirsa kolon yeniden dolduruluyor
            for(j=0; j<6; j++)
            {

                kolon[i][j]=random49();
            }

        }


        int ciftkontrol=0;
        for(j=0; j<6; j++)
        {
            //MADDE 3'deki min 2-max 4 cift olacak kurali icin sayilardan cift olanlari sayiyoruz

            if(kolon[i][j]%2==0)
                ciftkontrol++;
        }
        if(ciftkontrol<2 || ciftkontrol>4)
        {
            //eger cift sayi 2den kucuk veya 4den fazlaysa "goto" yapisi ile for dongusunun basina gonderip
            //ilgili kolonu yeniden olusturuyoruz
            goto bastan;
        }


        int tekbaskontrol=0;
        for(j=0; j<6; j++)
        {
            //MADDE 3'deki max 2 sayi tekbas olacak kurali icin sayilardan tekbas olanlari sayiyoruz
            if(kolon[i][j]<10)
                tekbaskontrol++;
        }
        if(tekbaskontrol>2)
        {
            //eger tekbas sayi 2den fazlaysa "goto" yapisi ile for dongusunun basina gonderip
            //ilgili kolonu yeniden olusturuyoruz
            goto bastan;
        }


        int a,b,gecici;
        for (a = 0 ; a < 6 - 1; a++)
        {
            for (b = 0 ; b < 6 - a - 1; b++)
            {
                if (kolon[i][b] > kolon[i][b+1])
                {
                    //BUBBLE SORT yontemi ile ilgili kolonu kucukten buyuge siraliyoruz boylece hem madde6
                    //hem de madde4deki ardisiklik kurali icin isimiz kolaylasiyor
                    gecici       = kolon[i][b];
                    kolon[i][b]   = kolon[i][b+1];
                    kolon[i][b+1] = gecici;
                }
            }
        }
        int ardisikkontrol=0;
        for(a=0; a<5; a++)
        {
            for(b=a+1; b<6; b++)
            {
                //MADDE 4'deki max 2 sayi ardisik olacak kurali icin sayilardan ardisik olanlari sayiyoruz
                if(kolon[i][a]+1==kolon[i][b])
                    ardisikkontrol++;
            }
        }
        if(ardisikkontrol>2)
        {
            //eger ardisik sayi 2den fazlaysa "goto" yapisi ile for dongusunun basina gonderip
            //ilgili kolonu yeniden olusturuyoruz
            goto bastan;
        }
    }
    for(i=0; i<kolonsayisi; i++)
    {
        //hali hazirda kucukten buyuge siralanmis kolonlarimizi konsola yazdiriyoruz
        printf("KOLON %d:\n",(i+1));
        printf("%d %d %d %d %d %d\n",kolon[i][0],kolon[i][1],kolon[i][2],kolon[i][3],kolon[i][4],kolon[i][5]);
    }

    FILE *fp;
    fp = fopen("test.txt", "w+");
    //dosya islemlerini aciyoruz


    for(i=0; i<kolonsayisi; i++ )
    {
        //konsola yazdirma isleminin aynisini txt dosyasi icin yapiyoruz
        fprintf(fp,"KOLON %d:\n",(i+1));
        fprintf(fp,"%d %d %d %d %d %d\n",kolon[i][0],kolon[i][1],kolon[i][2],kolon[i][3],kolon[i][4],kolon[i][5]);
    }
    fclose(fp);
    //dosya islemlerini kapatiyoruz
    return 0;
}

int random49()
{
    //1-49 araliginda rastgele sayi olusturup bunu donduren fonksiyon
    return rand()%49+1;
}
