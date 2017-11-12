#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> //루트만

double Sum(double data[], int n);
double Mean(double data[], int n);
double Var(double data[], int n);
double Sigma(double data[], int n); //표본평균의 표준편차를 구하기 위한 루트 

int main(void){
	int n=0;
	int i, j;
	double mom_dat[1000]={0}; //모집단 가져올 때 쓸 변수
	double dat[1000]= {0}; //n개를 임의추출해서 넣을 배열 
	double dat_mean[100] = {0}; // 표본평균의 평균 
	double sum= 0.0; //모집단과 표본평균의 총합
	double mean= 0.0; // 모집단과 표본평균의 평균 
	double var= 0.0; //모집단과 표본평균의 분산 
	double sigma = 0.0; //모집단과 표본평균의 표준편차 
	int index=0; // 랜덤함수를 돌려서 나온 인덱스값 저장 
	FILE* data = fopen("모집단자료코딩자료-1-3.csv", "r");
	
	srand(time(NULL));
	if(data==NULL){
		printf("파일을 열지 못했습니다.\n");
		return 1;
	}
	
	for(i=0;i<1000;i++){
		fscanf(data, "%lf", &mom_dat[i]); //1000개의 모집단 불러오기 
		fseek(data, 8, SEEK_CUR);
	}
	
	mean = Mean(mom_dat, 1000);
	var = Var(mom_dat, 1000);
	sigma = sqrt(var);
	printf("모집단의 평균 | 모집단의 분산 | 모집단의 표준편자\n");
	printf("%13lf %15lf %19lf\n\n", mean, var, sigma);
	
	printf("몇 개의 자료를 추출하시겠습니까?  ");
	scanf("%d", &n);
	printf("\n");	
	
	for(j=0;j<100;j++){
		for(i=0;i<n;i++){
			index = rand()%999;
			dat[i] = mom_dat[index];
		}
		dat_mean[j] = Mean(dat, n);
	}
	
	mean = Mean(dat_mean, 100);
	var = Var(dat_mean, 100);
	sigma = Sigma(dat_mean, 100);
	printf("표본평균의 평균 | 표본평균의 분산 | 표본평균의 표준편차\n");
	printf("%15lf %17lf %21lf\n", mean, var, sigma);
	
	fclose(data);
	return 0;
}
double Sum(double data[], int n){
	double sum = 0.0;
	int i;
	
	for(i=0;i<n;i++)
		sum += data[i];
		
	return sum;
}
double Mean(double data[], int n){
	return (Sum(data, n)/n);
}
double Var(double data[], int n){
	int i;
	double sum ;
	double mean = Mean(data, n);
	
	for(i=0;i<n;i++){
		//printf("%9lf - %9lf = %9lf %9lf\n", data[i], mean, data[i]-mean, pow((data[i]-mean), 2.0));
		sum += (data[i]-mean)*(data[i]-mean);
		//printf("%lf\n", sum); 
	}

	sum = sum / (double)n;
	return sum;
}
double Sigma(double data[], int n){
	int i;
	double sum ;
	double mean = Mean(data, n);
	
	for(i=0;i<n;i++){
		sum += (data[i]-mean)*(data[i]-mean);  
	}
	sum = sum / (double)(n-1); //n-1로 나누어야 더 정확한 값이 나옴 
	return sqrt(sum);
}
