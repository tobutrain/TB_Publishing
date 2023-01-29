#include <stdio.h>
#include <math.h>

long double solute_circle(long double x){
    return sqrt(1-(x*x));
}

int main(void){
    long double split,delta,area_4;
    long double area = 0.0;

    printf("•ªŠ„”: "); scanf("%lf",&split);
    delta = 1.0/split;

    for(int i=0; i<split; i++){
        area += (solute_circle((1/split)*i)+solute_circle((1/split)*(i+1)))*(1/split)/2;
    }
    area_4 = area*4;

    printf("‰~ü—¦ƒÎ = %lf",area_4);

    return 0;
}