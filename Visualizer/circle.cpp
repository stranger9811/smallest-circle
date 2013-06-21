#include<LEDA/geo/point.h>                                                  
#include<LEDA/geo/circle.h>
#include <stdio.h>
#include<time.h>
leda::point points[100000];
long int check_circle(leda::circle C,int no_of_points)
{
	int i;
	for(i=0;i<=no_of_points;i++)
	{
		if(C.outside(points[i]))
			return 0;                
	}
	return 1;
}
int main()
{
	FILE *fp,*fp_circle,*fp_points;
	clock_t  start,end;
	int i,j,k;
	int input_size;
	leda::circle C,C_j;
	fp=fopen("input.dat","r");
	fp_points=fopen("points.dat","w");
	fp_circle=fopen("circle.dat","w");
	fscanf(fp,"%d",&input_size);
	for(i=0;i<input_size;i++)
	{
		double x,y;
		fscanf(fp," %lf %lf",&x,&y);
		fprintf(fp_points,"%lf\t%lf\n",x,y);
		leda::point p(x,y);
		points[i]=p;
	}
	start=clock();
	leda::point center;
	center=midpoint( points[0], points[1]);
	leda::circle c_2(center,points[0]);
	C=c_2;
	for(i=2;i<input_size;i++)
	{
		if(C.outside(points[i]))
		{
			center=midpoint( points[0], points[i]);
			leda::circle c_1(center,points[0]);
			C_j=c_1;
			for(j=1;j<i;j++)
			{
				if(C_j.outside(points[j]))
				{
					center=midpoint( points[i], points[j]);
					leda::circle c_ij(center,points[i]);
					for(k=0;k<j;k++)
					{
						if(c_ij.outside(points[k]))
						{
							leda::circle c_ijk(points[i],points[j],points[k]);
							c_ij=c_ijk;
						}
					}
					C_j=c_ij;
				}													
			}
			C=C_j;	
		}
	}
	end=clock();
	printf("%d %6.6lf\n",input_size,((double)(end-start)/CLOCKS_PER_SEC));
	center=C.center();
	fprintf(fp_circle,"%lf %lf %lf",center.xcoord(),center.ycoord(),C.radius());
	//printf("(radius,center)=(%lf,(%lf,%lf))\n",C.radius(),center.xcoord(),center.ycoord());
}
