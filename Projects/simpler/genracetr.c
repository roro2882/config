#include <stdio.h>
#include <math.h>

double f(double x){
	return 0.5*(1+cos(x*M_PI));
}
int main(){
	int width=100;
	int height=100;
	int widthtrack=10;
	int racetrack[width][height];
	for(int i=0; i<width;i++){
		for(int j=0;j<height;j++){
			if(((double) j)/width< f(((double) i)/height)+0.3 && ((double) j)/width> f(((double) i)/height))
			printf("x");
			else printf("o");
		}
	printf("\n");}
	return 0;
}
