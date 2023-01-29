/*

分割方法： 台形分割
*/

#include <stdio.h>
#include <math.h>

#define delta_in 100 //分割数をマクロによって定義 今回は100までと指示する。

//積分したい関数 f(x) = \route{1-x^2}
double f(double x){
	return sqrt(1-(x*x));
}

int main(void){
	double delta; 
	double value = 0.0; //計算結果の積分値(区間全体の面積)
	int i,j;

    FILE *fp; //出力ファイルを開くためのファイルポインタを宣言
    char *fname = "pi_tbl.csv"; //出力ファイル名を指示するポインタ変数
    char *str = "delta,pi\n"; //出力するcsvファイルのタイトル行
    fp = fopen(fname,"w"); //出力ファイルをfopenにより開く

    //もし出力ファイルが何らかの起因により正常に開けず，ファイルポインタがNullとなっている場合に，エラーを出力しプログラムを終了させる。
    if(fp == NULL){
        printf("ファイルは開けません。\n");
        return -1;
    }
    fprintf(fp,"%s",str); //タイトル行を出力する。

    //円周率を計算するプログラム
    printf("\nCalcPI <TBL><FileIO>\n");
    printf("分割数設定: %d\n\n",delta_in);
    printf("file '%s' に書き込みを開始します。\n",fname);
    for(int k=0;k<32;k++){
        printf("-");
    }
    printf("\n");
    //分割数が1~delta_in(マクロで宣言した数)までのパターンでそれぞれ円周率を計算しファイルに出力
    for(i=1;i<=delta_in;i++){
        //一応i(int)をdoubleにキャストしている ※必要かはわからない
        delta = 1.0/(double)i;
        value = 0.0;
        // value => 台形分割の手法で単位円の面積の1/4を計算する
        for(j=0;j<i;j++){
            value += (f(delta*j)+f(delta*(j+1)))*delta/2;
        }
        //計算結果を4倍し，単位円の面積を求める => 円周率となる
        value = 4*value;
        fprintf(fp,"%d,%lf\n",i,value);
        printf("|分割数: %3d | 台形=> %lf |\n",i,value);
    }
    for(int k=0;k<32;k++){
        printf("-");
    }
    printf("\n\nファイルへの出力が完了しました.\n\n");

	return 0; //正常終了
}