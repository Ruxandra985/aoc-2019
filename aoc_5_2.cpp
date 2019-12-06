#include <cstdio>
#define DIM 677
using namespace std;
int v[1010],w[1010];
int main()
{
    FILE *fin = fopen ("a.in","r");
    FILE *fout = fopen ("a.out","w");
    int i,x,y , sgn , p , d, t, t1 , t2 , cod ;
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
        //printf ("%d ",i);
    }
    for (i=0;i<=DIM;i++){
        w[i] = v[i];
    }
    for (i=0;i<=DIM;){
        //printf ("%d ",i);
        if (w[i] == 99){
            break;
        }
        cod = w[i] % 100;
        if ( cod <= 2 ){
            w[i]/=100;
            p = w[i] % 10;
            w[i]/=10;
            d = w[i] % 10;
            w[i]/=10;
            t = w[i] % 10;

            w[i] = v[i];

            /// stii ca p e 0 mereu

            if (p == 0)
                t1 = w[w[i+1]];
            else t1 = w[i+1];

            if (d == 0)
                t2 = w[w[i+2]];
            else t2 = w[i+2];


            if (cod == 1)
                w[w[i+3]] = t1 + t2;
            else w[w[i+3]] = t1 * t2;
            i+=4;
        }
        else { /// cod 3 sau 4
            if (cod == 3){
                w[w[i+1]] = 5;
                i+=2;
            }
            else if (cod == 4){
                if (w[i] / 100 % 10 == 0)
                    fprintf (fout,"%d ",w[w[i+1]]);
                else fprintf (fout,"%d ",w[i+1]);
                i+=2;
            }
            else {
                w[i]/=100;
                p = w[i] % 10;
                w[i]/=10;
                d = w[i] % 10;
                w[i]/=10;
                t = w[i] % 10;

                w[i] = v[i];

                /// stii ca p e 0 mereu

                if (p == 0)
                    t1 = w[w[i+1]];
                else t1 = w[i+1];

                if (d == 0)
                    t2 = w[w[i+2]];
                else t2 = w[i+2];

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
                    w[w[i+3]] = (t1 < t2);
                    i+=4;
                }
                else {
                    w[w[i+3]] = (t1 == t2);
                    i+=4;
                }

            }
        }
    }

    //fprintf (fout,"%d",v[0]);
    return 0;
}

