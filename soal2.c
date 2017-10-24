#include<stdio.h>
#include<pthread.h>

int i,j;
void factorial(int a)
{
    int hasil=1;
    for(i=1;i<=a;i++){
        hasil=i*hasil;
    }
    printf("Hasil %d! = %d\n",a,hasil);
}

/*int main(){
    return 0;
}*/
