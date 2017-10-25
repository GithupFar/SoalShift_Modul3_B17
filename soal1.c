#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
char *name;
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
	detail stock[] ={{"MP4A1",0},{"PM2-V1",0},{"SPR-3",0},{"SS2-V5",0},{"SPG1-V3",0},{"MINE",0}};
	printf("---Welcome to Khawari Shop---\n");

}

