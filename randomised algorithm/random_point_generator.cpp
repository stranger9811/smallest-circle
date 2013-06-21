#include <ctime>//For seeding random generator
#include <cstdlib>
#include <iostream>
#include<stdio.h>
using namespace std;
int main()
{
	FILE *fp;
	fp = fopen("input.dat","w");
	int i = 0,numbers,j;
	printf("enter number of coordinates\n");
	scanf("%d",&numbers);
	fprintf(fp,"%d\n",numbers);
	srand((unsigned)time(0));//Seed the random number for not having the same sequence everytime depending on time
	for(int a = 0; a < numbers;a++)
	{
		i = rand() %10000-5000;
		j=rand() % 10000-5000;
		 fprintf(fp,"%d %d\n",i,j);

	}
}
