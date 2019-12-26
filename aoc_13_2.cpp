#include <cstdio>
#include <map>
#define DIM 2719
using namespace std;
map <long long , long long> v , w;
map <pair <long long , long long> , long long> a;
int main()
{
    FILE *fin = fopen ("a.in","r");
    FILE *fout = fopen ("a.out","w");
    long long i,x,y , sgn , p , d, t, t1 , t2 , cod , base , nrr , sol , ou ;
    long long lp , cp , lb , cb , dir;
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
    v[0] = 2;
    w = v;
    base = 0;
    i = 0;
    ou = 0;
    sol = 0;
    for (;;){
        //printf ("%d ",i);
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
                //w[w[i+1]] = 1;
                p = w[i] / 100 % 10;
                if (cb  == cp)
                    dir = 0;
                else if (cb < cp){
                    dir = -1;
                    cp--;
                }
                else{
                    dir = 1;
                    cp++;
                }
                //printf ("%lld %lld\n%lld %lld\n\n" , lb , cb,lp,cp);
                if (p == 0)
                    w[w[i+1]] = dir;
                else w[w[i+1] + base] = dir;
                i+=2;
            }
            else if (cod == 4){
                p = w[i] / 100 % 10;
                ou++;
                if (p == 0){
                    //fprintf(fout,"%lld ", w[w[i+1]]);
                    nrr = w[w[i+1]];
                }
                else if (p == 1){
                    //fprintf (fout,"%lld ", w[i+1]);
                    nrr = w[i+1];
                }
                else{
                    //fprintf (fout,"%lld ",w[w[i+1] + base]);
                    nrr = w[w[i+1] + base];
                }
                if (ou % 3 == 0){
                    sol++;
                    if (x != -1){
                        if (nrr == 4){

                            lb = y;
                            cb = x;
                        }
                        if (nrr == 3){
                            lp = y;
                            cp = x;
                        }
                        a[make_pair(x,y)] = nrr;
                    }
                    else printf ("%lld\n",nrr);
                }
                else if (ou%3 == 1)
                    x = nrr;
                else y = nrr;
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

    for (i=0;i<=26;i++){
        for (int j=0;j<=40;j++){
            fprintf (fout,"%lld",a[make_pair(j,i)]);
        }
        fprintf (fout,"\n");
    }
    return 0;
}

