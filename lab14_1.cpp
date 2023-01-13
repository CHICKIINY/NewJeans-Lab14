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

void stat(const double A[],int N,double B[])
{
    double AM = 0;
    for(int i = 0; i < N;i++)
    {
       AM += A[i];
       B[0] = AM/N;

    }
    double SD = 0;
    for(int i = 0; i < N;i++)
    {
        SD += pow(A[i],2);
        B[1] = sqrt((SD/N)-pow(B[0],2));
    }
    double GM = 1;
    for(int i = 0; i < N;i++)
    {
        GM *= A[i];
        B[2] = pow(GM,1.0/N);
    }
    double HM = 0;
    for(int i = 0; i < N;i++)
    {
        HM += 1/A[i];
        B[3] = N/HM;
    }
    double max = A[0];
    for(int i = 0; i < N;i++)
    {
        if(max < A[i])
        {
            max = A[i];
            B[4] = max;
        }
    }
    double min = A[0];
    for(int i = 0; i < N;i++)
    {
        if(min > A[i])
        {
            min = A[i];
            B[5] = min;
        }
    }

}