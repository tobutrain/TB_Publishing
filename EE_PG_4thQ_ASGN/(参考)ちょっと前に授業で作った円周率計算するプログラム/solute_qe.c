#include <stdio.h>
#include <math.h>

//��Βl��Ԃ��֐�
double my_abs(double num){
	if(num<0)
		return num*-1;
	else
		return num;
}

//���ʎ�
int eq_cond(double a,double b,double c){
	double ans = b*b-4*a*c;
	/*2�̈قȂ������������ - 0, ������������(���Ȃ�) - 1, �d�������� - 2 ��Ԃ�*/
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

//���̌���(��)
double eq_ans_pos(double a,double b,double c){
	return ((-1*b+sqrt(b*b-4*a*c))/(2*a));
}

//���̌���(��)
double eq_ans_neg(double a,double b,double c){
	return ((-1*b-sqrt(b*b-4*a*c))/(2*a));
}

//main�֐�
int main(void){
	//2���������̌W����ϐ�a,b,c�ɑ������
	double a,b,c;
	printf("2���������̉������߂܂��B\n");
	printf("(y=ax^2+bx+c)\n");
	printf("2��̌W��(a): "); scanf("%lf",&a);
	printf("1��̌W��(b): "); scanf("%lf",&b);
	printf("�萔��(c): "); scanf("%lf",&c);

	//���ʎ��̒l�ɂ���ĕ\����ς���
	//case 1 - ���Ȃ�(�����������ꍇ) case 0 - 2�̎����������ꍇ case 2 - �d�������ꍇ
	switch(eq_cond(a,b,c)){
	case 1:
		printf("\n���Ȃ�");
		break;
	case 0:
		printf("\nx=%.3lf,%.3lf\n",eq_ans_pos(a,b,c),eq_ans_neg(a,b,c));
		break;
	default:
		printf("\nx=%.3lf(�d��)\n",eq_ans_pos(a,b,c));
	}
	return 0;
}