#include <stdio.h>
#include <string.h>
int p1, p2, stat, minetot;
int mine [5][5]; //4x4 >> mulai dari 0,1,2,3

void isiranjau(int num)
{
	int i,j;
	if (num % 4 == 0){
		i = (num/4)-1;
		j = (num%4)-1;
	}
	else{
		i = num/4;
		j = num%4;
	}
	
	mine [i][j] = 1; //diisi ranjau
	minetot++;
}

void taruhranjau(){
	int n,noranjau;
	printf("How many naruh ranjau? ");
	scanf("%d",&n);	
	for (int i=0;i<n;i++){
		scanf("%d",&noranjau);
		isiranjau (noranjau);
	}
}

void tebakranjau(int player){
	int i,j ,score = 0, ans;
	for (int x=1;x<=4;x++) //harus nebak sebanyak 4 kali
	{
		scanf("%d",&ans);
		if (ans % 4 == 0){
			i = (ans/4)-1;
			j = (ans%4)-1;
		}
		else{
			i = ans/4;
			j = ans%4;
		}
	
		if (mine[i][j]){	//kalau kena ranjau, lawannya +poin
			printf("DUAR KENA RANJAU");
			if (player==1) p2++;
			else if (player==2) p1++;
		}
	}
}

int main()
{
	memset (mine,0,sizeof (mine));
	p1 = 0; p2 = 0;
	while (1)
	{
		printf("p1 taruh\n");
		taruhranjau();
		printf("p2 tebak\n");
		tebakranjau(2);
		if (p1>10 || p2>10 || minetot>=16) break;		
		
		printf("p2 taruh\n");
		taruhranjau();
		printf("p1 tebak\n");
		tebakranjau(1);
		if (p1>10 || p2>10 || minetot>=16) break;		
	}
	return 0;
}
