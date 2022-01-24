// ===============================================
//                 LU Decomposition 
// ===============================================

#include <stdio.h>

void PrintMatrix(double A[5][5]);
void PrintVector(double v[5]);
void InitializeMatrix(double A[5][5]);
void InitializeVector(double v[5]);


int main() {
    
    double a[5][5],l[5][5],u[5][5];
    double x[5],y[5],b[5];
    double sum,r;
    
    InitializeMatrix(a);
    InitializeMatrix(l);
    InitializeMatrix(u);
    InitializeVector(x);
    InitializeVector(y);
    InitializeVector(b);
    
    
    a[0][0] = 1.0;  a[0][1] = 1.0; a[0][2] = -2.0;a[0][3] = 1.0;a[0][4] = 4.0;
    a[1][0] = -1.0;  a[1][1] = -6.0; a[1][2] = -1.0;a[1][3] = 2.0;a[1][4] = 2.0;
    a[2][0] = 1.0;  a[2][1] = 4.0; a[2][2] = 6.0 ;a[2][3] = -8.0;a[2][4] = 2.0;
    a[3][0] = 6.0;  a[3][1] = 2.0; a[3][2] = -2.0 ;a[3][3] = 4.0;a[3][4] = 1.0;
    a[4][0] = 4.0;  a[4][1] = 4.0; a[4][2] = 1.0 ;a[4][3] = -6.0;a[4][4] = -2.0;
    
    b[0] = 6.0;  b[1] = -4.0; b[2] = -14.0;b[3] = 49.0;b[4] = -20.0;
    
    printf("=== A ===\n");
    PrintMatrix(a);
    printf("=== b ===\n");
    PrintVector(b);
    
 
    for(int k = 0;k <= 3;k++){
        for(int i = k+1;i <= 4;i++){
            r = a[i][k]/a[k][k];
            a[i][k] = r;//------>L
            for(int j = k+1;j <= 4;j++){
                a[i][j] = a[i][j] - r*a[k][j];
            }
        }
    }
    
    printf("=== A (Gaussian Elimination --> L & U )===\n");
    PrintMatrix(a);
    
    for(int i = 0; i < 5;i++){
        for(int j = 0; j < 5 ;j++){
            if(i == j)
                l[i][j] = 1.0;
            else if(i > j)
              l[i][j] = a[i][j]; 
        }
    }
    printf("=== L ===\n");      
    PrintMatrix(l);
    
    
     for(int i = 0; i < 5;i++){
        for(int j = 0; j < 5 ;j++){
           if(j >= i)
              u[i][j] = a[i][j]; 
        }
    }
    printf("=== U ===\n");   
    PrintMatrix(u);
    
    //============== Ly = b =====
    printf("=== Solve Ly = b  ===\n");    
    printf("=== L ===\n");      
    PrintMatrix(l);
    
    printf("=== b ===\n");
    PrintVector(b);
    
    printf("=== y ===\n");
    PrintVector(y);
    
    for(int i = 0; i < 5;i++){
        sum = 0.0;
        for(int j = 0; j <= i-1;j++){
            sum += l[i][j]*y[j];
        }
        y[i] = (b[i]-sum)/l[i][i];
    }
    
    printf("=== y (result) ===\n");   
    PrintVector(y);
    
//============== Ux = y ===== 
    printf("=== Solve Ux = y  ===\n");    
    printf("=== U ===\n");      
    PrintMatrix(u);
    
    printf("=== y ===\n");
    PrintVector(y);
    
    printf("=== x ===\n");
    PrintVector(x);
    
    for(int i = 4; i >= 0;i--){
        sum = 0.0;
        for(int j = i+1; j <= 4;j++){
            sum += u[i][j]*x[j];
        }
        x[i] = (y[i]-sum)/u[i][i];
        
    }

    printf("=== x (result) ===\n");  
    PrintVector(x);
    return 0;
}

void PrintMatrix(double A[5][5]){
    for(int i = 0; i < 5;i++){
        for(int j = 0; j < 5;j++){
          printf("%3.2f ",A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void PrintVector(double v[5]){
    for(int i = 0; i < 5;i++){
         printf("%3.2f ",v[i]);
    }
    printf("\n");
    printf("\n");
}


void InitializeMatrix(double A[5][5]){
    for(int i = 0; i < 5;i++){
        for(int j = 0; j < 5;j++){
          A[i][j] = 0.0;
        }
    }
}

void InitializeVector(double v[5]){
    for(int i = 0; i < 5;i++){
          v[i] = 0.0;
    }
}
