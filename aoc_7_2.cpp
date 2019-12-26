#include <cstdio>
#include <iostream>
#define DIM 502
using namespace std;
unsigned long long v[1010],w[10][1010] , perm[10] , poz_curr[10] , first[10];
unsigned long long  sol = 0;

unsigned long long solve(){
    unsigned long long prev_output , i , x ,  p , d, t, t1 , t2 , cod,aux,curr;
    unsigned long long solc = 0;
    prev_output = 0;
    if (perm[1] == 4 && perm[2] == 3 && perm[3] == 2 && perm[4] == 1 && perm[5] == 0)
        printf ("a");

    for (i=0;i<=DIM;i++){
        w[1][i] = w[2][i] = w[3][i] = w[4][i] = w[5][i] = v[i];
    }
    first[1] = first[2] = first[3] = first[4] = first[5] = 0;
    poz_curr[1] = poz_curr[2] = poz_curr[3] = poz_curr[4] = poz_curr[5] = 0;
    for (x = 1 ; x <= 10000; x++){

        for (i=poz_curr[(x-1) % 5 + 1];i<=DIM;){
            //prunsigned long longf ("%d ",i);
            curr = (x-1) % 5 + 1;
            if (w[curr][i] == 99){
                if (x % 5 == 0)
                    return prev_output;
                break;
            }
            cod = w[curr][i] % 100;
            if ( cod <= 2 ){
                w[curr][i]/=100;
                p = w[curr][i] % 10;
                w[curr][i]/=10;
                d = w[curr][i] % 10;
                w[curr][i]/=10;
                t = w[curr][i] % 10;

                w[curr][i] = v[i];

                /// stii ca p e 0 mereu

                if (p == 0)
                    t1 = w[curr][w[curr][i+1]];
                else t1 = w[curr][i+1];

                if (d == 0)
                    t2 = w[curr][w[curr][i+2]];
                else t2 = w[curr][i+2];


                if (cod == 1)
                    w[curr][w[curr][i+3]] = t1 + t2;
                else w[curr][w[curr][i+3]] = t1 * t2;
                i+=4;
            }
            else { /// cod 3 sau 4
                if (cod == 3){
                    if (first[curr] == 0)
                        w[curr][w[curr][i+1]] = perm[(x-1)%5 + 1] + 5;
                    else w[curr][w[curr][i+1]] = prev_output;
                    first[curr] = 1;
                    i+=2;
                }
                else if (cod == 4){
                    if (w[curr][i] / 100 % 10 == 0)
                        aux = w[curr][w[curr][i+1]];
                    else aux = w[curr][i+1];
                    i+=2;
                    poz_curr[(x-1)%5 + 1] = i;
                    break;
                }
                else {
                    w[curr][i]/=100;
                    p = w[curr][i] % 10;
                    w[curr][i]/=10;
                    d = w[curr][i] % 10;
                    w[curr][i]/=10;
                    t = w[curr][i] % 10;

                    w[curr][i] = v[i];

                    /// stii ca p e 0 mereu

                    if (p == 0)
                        t1 = w[curr][w[curr][i+1]];
                    else t1 = w[curr][i+1];

                    if (d == 0)
                        t2 = w[curr][w[curr][i+2]];
                    else t2 = w[curr][i+2];

                    if (cod == 5){
                        if (t1 != 0)
                            i = t2;
                        else i += 3;
                    }
                    else if (cod == 6){
                        if (t1 == 0)
                            i = t2;
                        else i += 3;
                    }
                    else if (cod == 7){
                        w[curr][w[curr][i+3]] = (t1 < t2);
                        i+=4;
                    }
                    else {
                        w[curr][w[curr][i+3]] = (t1 == t2);
                        i+=4;
                    }

                }
            }
        }
        if (aux == 0 && x % 5 == 0){
            printf ("a");
            break;
        }
        prev_output = aux;

    }
    return prev_output;
}
void back (unsigned long long poz){
    unsigned long long i , j;
    //printf ("%d ",poz);
    if (poz == 6){

        sol = max (sol , solve());
        //printf ("a");

        return;
    }
    for (i = 0; i < 5; i++){
        for (j = poz-1 ; j ; j --){
            if (perm[j] == i)
                break;
        }
        if (j == 0){
            perm[poz] = i;
            back(poz+1);
        }
    }
}
int main()
{
    FILE *fin = fopen ("a.in","r");
    FILE *fout = fopen ("a.out","w");
    unsigned long long i,x,y , sgn ;
    char c;
    for (i=0;i<=DIM;i++){
        c = fgetc (fin);
        sgn = 1;
        while ('0' > c || c > '9'){
            if (c == '-'){
                sgn = -1;
            }
            c = fgetc (fin);
        }
        while ('0' <= c && c <= '9'){
            v[i] = v[i] * 10 + c - '0';
            c = fgetc (fin);
        }
        v[i] *= sgn;
       // printf ("%d ",v[i]);
    }
    back (1);

    fprintf (fout,"%llu",sol);
    return 0;
}


