#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>

 // Aþaðýdaki kod yapýsýnda Kiþinin ad soyad ve yaþ bilgileri tutulmuþtur.

//Kiþi yapýsýný tutan düðüm yapýsý
struct lab{
    //char firstName[19];
    //char secondName[19];
    int x;
    int y;
    struct lab *next;
};

//Yýðýna en son eklenen elemaný top deðerinde tutacaðýz.
struct lab* top = NULL;

//Genel deðiþkenler
struct lab* temp;
//char personName[19];
//char personSecondName[19];
int labx;
int laby;


//verilen parametrelere baðlý düðüm oluþturan fonksiyon, geriye node dönüþü yapýyor
struct lab* kordinat(int x,int y)
{
    struct lab* newPerson = (struct lab*)malloc(sizeof(struct lab));
    //strcpy(newPerson->firstName, name);
    //strcpy(newPerson->secondName, sirName);
    newPerson->x = x;
    newPerson->y=y;
    newPerson->next = top;
    return newPerson;

}


// Klasik Stack veri yapýsýna eleman ekleme iþlemi
// Buradaki yapý aklýnýzý karýþtýrýr diye ek açýklama yapýyorum
// 4 => 5 => 7 => top(8)
// Her yeni eklenen düðümün next deðeri top elemanýný gösterir
// Daha sonra top deðeri yeni eleman olacak þekilde güncellenir.
void pushNode(int x,int y)
{
    struct lab* newFirst = kordinat(x,y);
    newFirst->next = top;
    top = newFirst;

}

//Klasik pop iþlemi, yýðýndan eleman çýkartan(düðüm) fonksiyon
void popNode()
{
    if(top == NULL)
    {
        printf("\n ici bos\n");
    }
    else
    {
        temp = top->next;
        free(top);
        top = temp;
    }
}

//Baðlý listeyi ekrana basan fonksiyon
void printList()

{
    int i = 1;

    if(top == NULL)
    {
        printf("\n Yol yoktur ...\n");
    }
    else
    {
            temp = top;
            while(temp->next != NULL)
            {

                printf("%d-) %d %d\n", i,  temp->x,temp->y);
                temp = temp->next;
                i++;
            }
             printf("%d-) %d %d\n", i,  temp->x,temp->y);

    }

}

//Yýðýnýn en son eklenen elemanýný geri döndüren fonksiyon
struct lab* peek()
{
     if(top == NULL)
    {

        return 0;
    }
    else
    {
        return top;
    }
}

//Main fonksiyonunda genel olarak menü bulunuyor, ek açýklama yapmýyorum.
int main()
{


      srand(time(NULL));
      int i,j,n;
      printf("Matrisin boyutunu giriniz:");
      scanf("%d",&n);
      int labirent[n][n];

      for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            labirent[i][j]=0+rand()%2;
        }
      }
      for(i=0;i<n;i++){
        for(j=0;j<n;j++){
                printf("%d  ",labirent[i][j]);
        }
        printf("\n");
      }

                    printf("Baslangic ve cikis koordinatlarinin girilebilecegi degerler:\n");
                    int sayac=0;
                    for (i=0;i<n;i++)
                        for (j=0;j<n;j++)
                        {
                            if (labirent[i][j]==1)
                            {
                                sayac++;
                                printf("\t[%d][%d]\t",i,j);
                                if (sayac%3==0)
                                    printf("\n");
                            }

                        }
                    printf("\n");
                    int a,b;
                    int c,d;

                    do
                    {
                        printf("baslangic kordinatlarini giriniz");
                        scanf("%d%d",&a,&b);
                        printf("bitis kordinatlarini giriniz");
                        scanf("%d%d",&c,&d);
                        if (labirent[a][b]==1 && labirent[c][d]==1 && (a<=n-1) && (b<=n-1) && (c<=n-1) && (d<=n-1))
                            break;

                    }while(1);
                    yol(n,labirent,a,b,c,d);




    return 0;
}

void yol(int n, int labirent[][n],int a,int b,int c, int d){
struct lab* topElement;
pushNode(a,b);
/*
        int i,j;
                    for (i=0;i<=2;i++)
                    {


                        for (j=0;j<=2;j++)
                        {

                                printf("%d",labirent[i][j]);
                        }
                        printf("\n");
                        }
                        */
    while(a!=c || b!=d)
    {

        if(b!=n-1 && labirent[a][b+1]==1)
            {
            pushNode(a,b+1);



            labirent[a][b]=0;


            b++;
            }
       else if(a!=n-1 && labirent[a+1][b]==1)
            {

            pushNode(a+1,b);
            labirent[a][b]=0;


            a++;
            }
       else if(b!=0 && labirent[a][b-1]==1)
            {
           pushNode(a,b-1);
           labirent[a][b]=0;


           b--;
            }
       else if(a!=0 && labirent[a-1][b]==1)
            {
            pushNode(a-1,b);
            labirent[a][b]=0;


            a--;
            }
        else
            {
            labirent[a][b]=0;
            popNode();
            topElement= peek();
                if(topElement)
                {
                    a=topElement->x;
                    b=topElement->y;
                }

            if (top==NULL)
                break;
            }

    }
printf("Gidilen Koordinatlar:\n");
printList();
printf("Labirent uzerinde bulunan yol:\n");
yolmatris(n);

}

void yolmatris(n)
{
    int i,j;
   int matris[n][n];
     for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            matris[i][j]=0;
        }
      }


    if (top!= NULL)
    {
            temp = top;
            while(temp->next != NULL)
            {
                matris[temp->x][temp->y]=1;
                temp = temp->next;

            }

             matris[temp->x][temp->y]=1;

    }
       for(i=0;i<n;i++){
        for(j=0;j<n;j++){
                printf("%d  ",matris[i][j]);
        }
        printf("\n");
      }

}
