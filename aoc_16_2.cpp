#include <cstdio>
#include <iostream>
using namespace std;
int v[10000000] , w[10000000] , x[6];
int sp[10000000];
int main()
{
    FILE *fin = fopen ("a.in","r");
    FILE *fout = fopen ("a.out","w");
    int n , step , poz , j , i ,ok;
    char c;
    long long sum;
    c=fgetc(fin);
    n=0;
    while ('0'<=c && c <='9'){
        v[++n] = c-'0';
        c = fgetc (fin);
    }
    for (i=2;i<=10000;i++){
        for (j=1;j<=n;j++){
            v[(i-1) * n + j] = v[j];
        }
    }
    n*=10000;
    for (i=1;i<=n;i++)
        sp[i] = sp[i-1] + v[i];
    x[1] = 0;
    x[2] = 1;
    x[3] = 0;
    x[4] = -1;
    for (step=1;step<=100;step++){
        //printf ("%d ",step);
        for (i=1;i<=n;i++){ /// inmultirea nr i , fiecare se repeta de i / i-1 ori
            sum = 0;
            ok = 1;
            poz = 1;

            sum = sum + x[poz] * (sp[min(n,1+i-1-1)] - sp[1-1]);
            poz = poz % 4 + 1;

            j= 1 + (i-1);

            for (;j<=n;j=j+i){ /// calcul pt al j lea coeficient
                sum = sum + x[poz] * (sp[min(n,j+i-1)] - sp[j-1]);
                poz = poz % 4 + 1;

            }
            if (sum < 0)
                sum = -sum;
            w[i] = sum % 10;

        }
        for (i=1;i<=n;i++){
            v[i] = w[i];
            sp[i] = v[i] + sp[i-1];
        }
    }
    int start = 5979351;
    //int start = 0;
    for (i=start + 1;i<=start + 8;i++){
        fprintf (fout,"%d",v[i]);
    }
    return 0;
}

