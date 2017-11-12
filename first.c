#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> //��Ʈ��

double Sum(double data[], int n);
double Mean(double data[], int n);
double Var(double data[], int n);
double Sigma(double data[], int n); //ǥ������� ǥ�������� ���ϱ� ���� ��Ʈ 

int main(void){
	int n=0;
	int i, j;
	double mom_dat[1000]={0}; //������ ������ �� �� ����
	double dat[1000]= {0}; //n���� ���������ؼ� ���� �迭 
	double dat_mean[100] = {0}; // ǥ������� ��� 
	double sum= 0.0; //�����ܰ� ǥ������� ����
	double mean= 0.0; // �����ܰ� ǥ������� ��� 
	double var= 0.0; //�����ܰ� ǥ������� �л� 
	double sigma = 0.0; //�����ܰ� ǥ������� ǥ������ 
	int index=0; // �����Լ��� ������ ���� �ε����� ���� 
	FILE* data = fopen("�������ڷ��ڵ��ڷ�-1-3.csv", "r");
	
	srand(time(NULL));
	if(data==NULL){
		printf("������ ���� ���߽��ϴ�.\n");
		return 1;
	}
	
	for(i=0;i<1000;i++){
		fscanf(data, "%lf", &mom_dat[i]); //1000���� ������ �ҷ����� 
		fseek(data, 8, SEEK_CUR);
	}
	
	mean = Mean(mom_dat, 1000);
	var = Var(mom_dat, 1000);
	sigma = sqrt(var);
	printf("�������� ��� | �������� �л� | �������� ǥ������\n");
	printf("%13lf %15lf %19lf\n\n", mean, var, sigma);
	
	printf("�� ���� �ڷḦ �����Ͻðڽ��ϱ�?  ");
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
	sum = sum / (double)(n-1); //n-1�� ������� �� ��Ȯ�� ���� ���� 
	return sqrt(sum);
}
