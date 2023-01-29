/*

�������@�F ��`����
*/

#include <stdio.h>
#include <math.h>

#define delta_in 100 //���������}�N���ɂ���Ē�` �����100�܂łƎw������B

//�ϕ��������֐� f(x) = \route{1-x^2}
double f(double x){
	return sqrt(1-(x*x));
}

int main(void){
	double delta; 
	double value = 0.0; //�v�Z���ʂ̐ϕ��l(��ԑS�̖̂ʐ�)
	int i,j;

    FILE *fp; //�o�̓t�@�C�����J�����߂̃t�@�C���|�C���^��錾
    char *fname = "pi_tbl.csv"; //�o�̓t�@�C�������w������|�C���^�ϐ�
    char *str = "delta,pi\n"; //�o�͂���csv�t�@�C���̃^�C�g���s
    fp = fopen(fname,"w"); //�o�̓t�@�C����fopen�ɂ��J��

    //�����o�̓t�@�C�������炩�̋N���ɂ�萳��ɊJ�����C�t�@�C���|�C���^��Null�ƂȂ��Ă���ꍇ�ɁC�G���[���o�͂��v���O�������I��������B
    if(fp == NULL){
        printf("�t�@�C���͊J���܂���B\n");
        return -1;
    }
    fprintf(fp,"%s",str); //�^�C�g���s���o�͂���B

    //�~�������v�Z����v���O����
    printf("\nCalcPI <TBL><FileIO>\n");
    printf("�������ݒ�: %d\n\n",delta_in);
    printf("file '%s' �ɏ������݂��J�n���܂��B\n",fname);
    for(int k=0;k<32;k++){
        printf("-");
    }
    printf("\n");
    //��������1~delta_in(�}�N���Ő錾������)�܂ł̃p�^�[���ł��ꂼ��~�������v�Z���t�@�C���ɏo��
    for(i=1;i<=delta_in;i++){
        //�ꉞi(int)��double�ɃL���X�g���Ă��� ���K�v���͂킩��Ȃ�
        delta = 1.0/(double)i;
        value = 0.0;
        // value => ��`�����̎�@�ŒP�ʉ~�̖ʐς�1/4���v�Z����
        for(j=0;j<i;j++){
            value += (f(delta*j)+f(delta*(j+1)))*delta/2;
        }
        //�v�Z���ʂ�4�{���C�P�ʉ~�̖ʐς����߂� => �~�����ƂȂ�
        value = 4*value;
        fprintf(fp,"%d,%lf\n",i,value);
        printf("|������: %3d | ��`=> %lf |\n",i,value);
    }
    for(int k=0;k<32;k++){
        printf("-");
    }
    printf("\n\n�t�@�C���ւ̏o�͂��������܂���.\n\n");

	return 0; //����I��
}