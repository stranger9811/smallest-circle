#include<LEDA/geo/point.h>
#include<LEDA/geo/circle.h>
#include<LEDA/internal/std/stdlib.h>
#include<LEDA/internal/PREAMBLE.h>
#include <stdio.h>
leda::point points[100000];
leda::circle C,c_small; 
long int check_circle(int no_of_points)
{
	int flag,i;
	flag=0;
	for(i=0;i<no_of_points;i++)
	{
		if(C.outside(points[i]))
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
		return 1;
	else
		return 0;

}
int main()
{
	FILE *fp,*fp_out,*fp_points;
	fp=fopen("input.dat","r");
	fp_points=fopen("points.dat","w");
	fp_out=fopen("circle.dat","w");
	int input_size,i,j,k,flag;
	double radius,max_radius;
	bool check;
	int max_1,max_2,label;	
	float max_distance,value;
	fscanf(fp,"%d",&input_size);
	int max_index,distance[input_size];
	for(i=0;i<input_size;i++)
	{
		double x,y;
		fscanf(fp," %lf %lf",&x,&y);
		fprintf(fp_points,"%lf\t%lf\n",x,y);
		leda::point p(x,y);
		points[i]=p;
	}

	distance[0]=0;
	for(i=0;i<input_size;i++)
	{
		max_distance=0;
		max_index=0;
		for(j=0;j<i;j++)
		{
			value=points[i].distance( points[j]);
			if(value>max_distance)
			{
				max_distance=value;
				max_index=j;
			}

		}
		distance[i]=max_index;
	}
	printf("\n");
	// Finding Circle consisting farthest points.
	leda::point center;
	center=midpoint( points[0], points[1]);
	leda::circle c1(center,points[0]);
	C=c1;
	for(i=2;i<input_size;i++)
	{
		if(C.outside(points[i]))
		{
			leda::circle temp;
			temp=C;
			leda::point center;
			center=midpoint( points[i], points[distance[i]]);
			leda::circle c1(center,points[i]);
			C=c1;
			if(check_circle(i))
				continue;
			C=temp;
			c_small=C;

			max_radius=100000000;
			for(j=0;j<i;j++)
			{
				for(k=j+1;k<i;k++)
				{
					if(orientation(points[i],points[j],points[k])==0)
						continue;
					leda::circle c2(points[i],points[j],points[k]);
					c1=c2;
					C=c1;
					if(check_circle(i))
					{
						if(C.is_degenerate())
							continue;
						radius=c1.radius();
						if(radius<max_radius)
						{
							max_radius=radius;
							c_small=c1;
						}
					}

				}
			}
			C=c_small;
			center=C.center();
			fprintf(fp_out,"%lf %lf %lf\n",center.xcoord(),center.ycoord(),C.radius());
		}

	}

	center=C.center();
	printf("minimum enclosing circle is c with (radius,center)=(%lf,(%lf,%lf))",C.radius(),center.xcoord(),center.ycoord());
	fprintf(fp_out,"%lf %lf %lf",center.xcoord(),center.ycoord(),C.radius());
}

