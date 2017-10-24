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

int main()
{
	memset (mine,0,sizeof (mine));
	
	return 0;
}
