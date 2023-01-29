#include <stdio.h>
#include <math.h>

//絶対値を返す関数
double my_abs(double num){
	if(num<0)
		return num*-1;
	else
		return num;
}

//判別式
int eq_cond(double a,double b,double c){
	double ans = b*b-4*a*c;
	/*2つの異なる実数解を持つ - 0, 虚数解を持つ(解なし) - 1, 重解を持つ - 2 を返す*/
	switch((int)(ans/my_abs(ans))){
	case 1:
		return 0;
		break;
	case -1:
		return 1;
		break;
	default:
		return 2;
	}
}

//解の公式(正)
double eq_ans_pos(double a,double b,double c){
	return ((-1*b+sqrt(b*b-4*a*c))/(2*a));
}

//解の公式(負)
double eq_ans_neg(double a,double b,double c){
	return ((-1*b-sqrt(b*b-4*a*c))/(2*a));
}

//main関数
int main(void){
	//2次方程式の係数を変数a,b,cに代入する
	double a,b,c;
	printf("2次方程式の解を求めます。\n");
	printf("(y=ax^2+bx+c)\n");
	printf("2乗の係数(a): "); scanf("%lf",&a);
	printf("1乗の係数(b): "); scanf("%lf",&b);
	printf("定数項(c): "); scanf("%lf",&c);

	//判別式の値によって表示を変える
	//case 1 - 解なし(虚数解を持つ場合) case 0 - 2つの実数解を持つ場合 case 2 - 重解を持つ場合
	switch(eq_cond(a,b,c)){
	case 1:
		printf("\n解なし");
		break;
	case 0:
		printf("\nx=%.3lf,%.3lf\n",eq_ans_pos(a,b,c),eq_ans_neg(a,b,c));
		break;
	default:
		printf("\nx=%.3lf(重解)\n",eq_ans_pos(a,b,c));
	}
	return 0;
}