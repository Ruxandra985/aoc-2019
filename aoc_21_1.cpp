#include <cstdio>
#include <map>
#include <string>
#define DIM 2049
using namespace std;
map <long long , long long> v , w;
char a[110][110];
//string mve = "NOT A T\nOR T J\nNOT B T\nOR T J\nNOT C T\nOR T J\nAND D J\nNOT H T\nNOT T T\nOR E T\nAND T J\nRUN\n";
string mve = "NOT A T\nOR T J\nNOT B T\nOR T J\nNOT C T\nOR T J\nAND D J\nWALK\n";
int main()
{
    FILE *fin = fopen ("a.in","r");
    FILE *fout = fopen ("a.out","w");
    long long i,x,y , sgn , p , d, t, t1 , t2 , cod , base , lin , col,lmax = 0 , cmax = 0;
    char c;
    long long nrr;
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
    w = v;
    base = 0;
    i = 0;
    lin = 1;
    col = 1;
    int ou = 0;
    int poz = 0;
    ///2171927479
    for (;;){
        //printf ("%d\n",i);
        if (w[i] == 99){
            break;
        }
        cod = w[i] % 100;
        //printf ("%lld ",cod);
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
            else if (p == 1)
                t1 = w[i+1];
            else
                t1 = w[w[i+1] + base];

            if (d == 0)
                t2 = w[w[i+2]];
            else if (d == 1)
                t2 = w[i+2];
            else t2 = w[w[i+2] + base];


            if (cod == 1){
                if (t == 0)
                    w[w[i+3]] = t1 + t2;
                else w[w[i+3] + base] = t1 + t2;
            }
            else {
                if (t == 0)
                    w[w[i+3]] = t1 * t2;
                else w[w[i+3] + base] = t1 * t2;
            }
            i+=4;
        }
        else { /// cod 3 sau 4
            if (cod == 3){
                //printf ("input\n");
                p = w[i] / 100 % 10;
                if (p == 0){
                    w[w[i+1]] = mve[poz];
                }
                else{
                    w[w[i+1] + base] = mve[poz];
                }
                poz++;
                i+=2;
            }
            else if (cod == 4){
                p = w[i] / 100 % 10;
                ou++;
                if (p == 0)
                    nrr = w[w[i+1]];
                else if (p == 1)
                    nrr = w[i+1];
                else
                    nrr = w[w[i+1] + base];
                if (nrr <= 128)
                    fputc (char(nrr),fout);
                else printf ("%lld\n",nrr);

                i+=2;
            }
            else if (cod == 9){
                p = w[i] / 100 % 10;
                if (p == 0)
                    base += w[w[i+1]];
                else if (p == 1)
                    base += w[i+1];
                else base += w[w[i+1] + base];
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
                else if (p == 1)
                    t1 = w[i+1];
                else
                    t1 = w[w[i+1] + base];

                if (d == 0)
                    t2 = w[w[i+2]];
                else if (d == 1)
                    t2 = w[i+2];
                else t2 = w[w[i+2] + base];

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
                    if (t == 0)
                        w[w[i+3]] = (t1 < t2);
                    else w[w[i+3] + base] = (t1 < t2);
                    i+=4;
                }
                else if (cod == 8){
                    if (t == 0)
                        w[w[i+3]] = (t1 == t2);
                    else w[w[i+3] + base] = (t1 == t2);
                    i+=4;
                }

            }
        }
    }
    /*printf ("%d\n",ou);
    printf ("%lld %lld\n",lmax,cmax);*/
    return 0;
}

