/*

*/

#include <stdio.h>
#include <math.h>

#define GNUPLOT "gnuplot -persist"

//�ϕ��������֐� f(x) = route{1-x^2}
double f(double x){
	return sqrt(1-x*x);
}

int main(void){
	double n; //������
	double delta;
	double value = 0.0; //�v�Z���ʂ̐ϕ��l(��ԑS�̖̂ʐ�)
	int i,j;

    FILE *fp,*gnuplot;
    char *fname = "pi.csv";
    char *str = "delta,pi()\n";
    fp = fopen(fname,"w");

    if(fp == NULL){
        printf("�t�@�C���͊J���܂���B\n");
        return -1;
    }

    fputs(fp,str);
	puts("\nCalc_PI <Tbl><FileIO>\n\n");
	printf("������: "); scanf("%lf",&n);
	delta = 1/n;
	for(j=0; j<n; j++){
        for(i=0; i<n; i++){
            //i�Ԗڂ̒Z���̍���X�l
            double x = i * delta;
            value += (f(x)+f(x-1)) * delta / 2;
        }
        //�ŏI�I�Ȑϕ����ʂ��R���\�[��,�t�@�C���ɏo�͂���
        printf("pi = %lf (delta : %lf\n",value*4,n);
        fprintf(fp,"%d,%lf\n",j,value*4);
    }

    printf("\n�t�@�C���ւ̏o�͂��������܂���.\n\n");
    
    printf("gnuplot�ւ̏o�͂��J�n���܂��B\n");

    gnuplot = popen(GNUPLOT,"w");
    fprintf(gnuplot,"set xrange [1:100]");
    fprintf(gnuplot,"set datafile separator ','");
    fprintf(gnuplot,"set terminal png");
    fprintf(gnuplot,"set output 'pi.png'");
    fprintf(gnuplot,"plot 'pi.csv' using 1:2");
    pclose(gnuplot);

    printf("�o�͊����B\n");

	return 0;
}