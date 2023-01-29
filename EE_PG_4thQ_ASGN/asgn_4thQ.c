/*

*/

#include <stdio.h>
#include <math.h>

#define GNUPLOT "gnuplot -persist"

//積分したい関数 f(x) = route{1-x^2}
double f(double x){
	return sqrt(1-x*x);
}

int main(void){
	double n; //分割数
	double delta;
	double value = 0.0; //計算結果の積分値(区間全体の面積)
	int i,j;

    FILE *fp,*gnuplot;
    char *fname = "pi.csv";
    char *str = "delta,pi()\n";
    fp = fopen(fname,"w");

    if(fp == NULL){
        printf("ファイルは開けません。\n");
        return -1;
    }

    fputs(fp,str);
	puts("\nCalc_PI <Tbl><FileIO>\n\n");
	printf("分割数: "); scanf("%lf",&n);
	delta = 1/n;
	for(j=0; j<n; j++){
        for(i=0; i<n; i++){
            //i番目の短冊の左下X値
            double x = i * delta;
            value += (f(x)+f(x-1)) * delta / 2;
        }
        //最終的な積分結果をコンソール,ファイルに出力する
        printf("pi = %lf (delta : %lf\n",value*4,n);
        fprintf(fp,"%d,%lf\n",j,value*4);
    }

    printf("\nファイルへの出力が完了しました.\n\n");
    
    printf("gnuplotへの出力を開始します。\n");

    gnuplot = popen(GNUPLOT,"w");
    fprintf(gnuplot,"set xrange [1:100]");
    fprintf(gnuplot,"set datafile separator ','");
    fprintf(gnuplot,"set terminal png");
    fprintf(gnuplot,"set output 'pi.png'");
    fprintf(gnuplot,"plot 'pi.csv' using 1:2");
    pclose(gnuplot);

    printf("出力完了。\n");

	return 0;
}