#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
char name[10];
int qty;
}detail;

int search(detail *no1,detail *no2)
{
	int valid;
	valid = strcmp(no1->name, no2->name);

	return valid;
}

int main ()
{
	detail stock[] ={{"MP4A1",10},{"PM2-V1",20},{"SPR-3",1},{"SS2-V5",5},{"SPG1-V3",30},{"MINE",0}};
	detail input;
	int a,b;
	while (1)
{
	printf("---Welcome to Khawari Shop---\n");
	printf("Choose your account\n");
	printf("1.Admin\n");
	printf("2.costumer\n");
	scanf ("%d",&a);
	if (a==1)//  data admin
	{
		while (1)
		{
		printf ("\n\n--Menu--\n");
		printf ("1. tambah Stock\n");
		printf ("2. lihat stock\n");
		printf ("3. LOG OUT\n");
		scanf ("%d",&b);
			if (b==1)//input data
			{
				int i;
				scanf("%s %d", input.name , &input.qty);
				//printf("%s %d", input.name, input.qty);
				for(i=0;i<=5;i++)
				{
					if (search(&input,&stock[i])==0)
					{
						stock[i].qty=stock[i].qty+input.qty;
						
						printf("%s %d\n",stock[i].name,stock[i].qty);
						break;
					}
				}
			}
			else if (b==2)//input data
			{
				int i;
				for(i=0;i<=5;i++)
				{
					if (stock[i].qty>0)
					{
						printf("%s %d\n",stock[i].name,stock[i].qty);
					}
				}
			}
			else if (b==3)
			{
				break;
			}
			else 
			{
				printf ("please inputnya tidak ada di atas");
			}
		}
	}
	else if (a==2)// data pelanggan
	{	
		while (1)
		{
		printf ("\n\n--Welcome--\n");
        printf ("1. Beli Senjata\n");
        printf ("2. lihat stock\n");
        printf ("3. LOG OUT\n");
        scanf ("%d",&b);
			if (b==1)//input data
			{
				int i;
				scanf("%s %d", input.name , &input.qty);
				//printf("%s %d", input.name, input.qty);
				for(i=0;i<=5;i++)
				{
					if (search(&input,&stock[i])==0)
					{
						if(stock[i].qty==0)
						{
							printf("maaf stock habis");
						}
						else if (stock[i].qty-input.qty<0)
						{
							printf("Maaf Anda membeli barang lebih banyak dari stock yang tersedia");
						}
						else
						{
						stock[i].qty=stock[i].qty-input.qty;
						printf("Terimakasih Anda membeli %s sebanyak %d\n",input.name,input.qty);
						}
						
						break;
					}
				}
			}
			else if (b==2)//input data
			{
				int i;
				for(i=0;i<=5;i++)
				{
					if (stock[i].qty>0)
					{
						printf("%s %d\n",stock[i].name,stock[i].qty);
					}
				}
			}
			else if (b==3)
			{
				break;
			}
			else 
			{
				printf ("please inputnya tidak ada di atas");
			}
    	}
        
	}
};
}

