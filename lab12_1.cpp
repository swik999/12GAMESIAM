#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[], int N, double B[]){
	double sum = 0;
	for (int i = 0; i < N;i++){
		sum += A[i];
	}
	B[0] = sum/N;
	
	double SD,D;
	for (int i = 0; i < N;i++){
		D += pow(A[i] - B[0], 2);
	}
	SD = sqrt(D/N);
	B[1] = SD;
	
	double s = 1.0;
	for(int i = 0; i < N ;i++){
		s *= A[i];
	}
	double GM;
	GM = pow(s,(1.0/N));
	B[2] = GM;
	
	double ss = 0;
	for(int i = 0; i < N ;i++){
		ss = ss+(1/A[i]);
	}
	double HM;
	HM = N * pow(ss,-1);
	B[3] = HM;
	
	double MAX = A[0],MIN = A[0];
	for(int i = 1; i < N; i++){
		if(A[i] > MAX) MAX = A[i];
		if(A[i] < MIN) MIN = A[i];
	}
	B[4]=MAX;
	B[5]=MIN;
}