#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> //��Ʈ��
//���� ���� 
// �Է��� ����ڷκ���, �������� ���, �л�, ���� �׷���, ǥ�� ����� ���, �л�, ǥ������ 

double Sum(double data[], int n);
double Mean(double data[], int n);
double Var(double data[], int n);
double Sigma(double data[], int n);

int main(void){
	int n=0;
	int i, j;
	double mom_dat[1000]={0}; //������ ������ �� �� ����
	double dat[100]= {0}; 
	double dat_mean[100] = {0};
	double sum= 0.0; //������ ���� s
	double mean= 0.0;
	double var= 0.0;
	double sigma = 0.0;
	int index=0;
	FILE* data = fopen("�������ڷ��ڵ��ڷ�-1-3.csv", "r");
	
	srand(time(NULL));
	if(data==NULL){
		printf("������ ���� ���߽��ϴ�.\n");
		return 1;
	}
	
	for(i=0;i<1000;i++){
		fscanf(data, "%lf", &mom_dat[i]);
		fseek(data, 8, SEEK_CUR);
	}
	
	mean = Mean(mom_dat, 1000);
	var = Var(mom_dat, 1000);
	sigma = sqrt(var);
	printf("�������� ��� | �������� �л� | �������� ǥ������\n");
	printf("%13.4lf %15.4lf %19.4lf\n\n", mean, var, sigma);
	
	printf("�� ���� �ڷḦ �����Ͻðڽ��ϱ�?\n");
	scanf("%d", &n);
	printf("\n");	
	
	for(j=0;j<100;j++){
		for(i=0;i<n;i++){
			index = rand()%1000;
			dat[i] = mom_dat[index];
		}
		dat_mean[j] = Mean(dat, n);
	}
	
	mean = Mean(dat_mean, 100);
	var = Var(dat_mean, 100);
	sigma = Sigma(dat_mean, 100);
	printf("ǥ������� ��� | ǥ������� �л� | ǥ������� ǥ������\n");
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
		//printf("%lf - %lf = %lf %lf\n", data[i], mean, data[i]-mean, pow((data[i]-mean), 2.0));
		sum += (data[i]-mean)*(data[i]-mean);
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
	sum = sum / (double)(n-1);
	return sqrt(sum);
}
