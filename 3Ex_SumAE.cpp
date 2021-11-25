#include<iostream>
using namespace std;
int main(){
    int N =10;
    double x[N]={1.1,2.5,-3.1,4.0,6.9},sum=0;
    for(int i=0;i<N;i++){
        sum +=x[i];

    }
    cout<<"sum = "<<sum;
    return 0;
}