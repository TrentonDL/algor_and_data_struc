#include <stdio.h>
#include <string.h>

void print_arr(int * arr[], int * N, int * P){
    for(int i=0;i<N;i++){
        for(int j=0;j<P;j++){
            printf("%3d", arr[i][j]);
        }
    }
}

void print_arr_c(char * arr[], int * N, int * P){
    for(int i=0;i<N;i++){
        for(int j=0;j<P;j++){
            printf("%3c", arr[i][j]);
        }
    }
}

int LCS_Length(char * string1, char * string2, int * N, int * P){
    int b[N+1][P+1] = {};
    int c[N+1][P+1] = {};

    for(int i=0; i<N; i++)
        c[i][0] = 0;
    for(int j=0; j<P; j++)
        c[0][j] = 0;

    for(int i=1; i<N; i++){
        for(int j=1; j<P; j++){
            if(string1[i-1] == string2[j-1]){
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = "/";
            }
            else if(c[i-1][j] >= c[i][j-1]){
                c[i][j] = c[i-1][j];
                b[i][j] = "^";
            }
            else{
                c[i][j] = c[i][j-1];
                b[i][j] = "<";
            }
        }
    }

    print_arr(&c, *N, *P);
    print_arr_c(&b, *N, *P);
}

int main(){
    char string1[] = "TRAY";
    int N = strlen(string1);
    char string2[] = "STORM";
    int P = strlen(string2);

    int lcs = LCS_Length(string1, string2, &N, &P);


}