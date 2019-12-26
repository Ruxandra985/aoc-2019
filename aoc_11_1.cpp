#include <cstdio>
#include <map>
#define DIM 623
using namespace std;
map <long long , long long> w;
map <pair <long long , long long> , int> a , f;
int di[]={-1,0,1,0};
int dj[]={0,1,0,-1};
int main()
{
    FILE *fin = fopen ("a.in","r");
    FILE *fout = fopen ("a.out","w");
    long long i,x,y , sgn , p , d, t, t1 , t2 , cod , base , cpy;
    long long idk , sol , ic , jc , dc , val;
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
            w[i] = w[i] * 10 + c - '0';
            c = fgetc (fin);
        }
        w[i] *= sgn;
        //printf ("%d ",i);
    }
    base = 0;
    i = 0;
    ///14
    dc = 0;
    ic = jc = 0;
    a[make_pair(0,0)] = 0;
    val = 0;
    sol = 0;
    for (;;){
        //printf ("%d ",i);
        if (w[i] == 99){
            break;
        }
        cod = w[i] % 100;
        //printf ("%lld ",cod);
        if ( cod <= 2 ){

            cpy = w[i];

            w[i]/=100;
            p = w[i] % 10;
            w[i]/=10;
            d = w[i] % 10;
            w[i]/=10;
            t = w[i] % 10;

            w[i] = cpy;

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
                if (p == 0)
                    w[w[i+1]] = a[make_pair(ic , jc)];
                else w[w[i+1] + base] = a[make_pair(ic , jc)];
                i+=2;
            }
            else if (cod == 4){
                p = w[i] / 100 % 10;
                if (p == 0)
                    idk =  w[w[i+1]];
                else if (p == 1)
                    idk = w[i+1];
                else
                    idk = w[w[i+1] + base];

                if (val == 0){ /// pictez acum
                    if (f[make_pair(ic , jc)] == 0)
                        sol++;
                    f[make_pair(ic , jc)] = 1;
                    a[make_pair(ic , jc)] = idk;
                    val = 1;
                }
                else {
                    if (idk == 0){
                        dc--;
                        if (dc < 0)
                            dc = 3;

                    }
                    else {
                        dc ++;
                        if (dc == 4)
                            dc = 0;
                    }
                    ic += di[dc];
                    jc += dj[dc];
                    //fprintf (fout ,"%lld %lld\n" , ic , jc);
                    val = 0;
                }
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

                cpy = w[i];

                w[i]/=100;
                p = w[i] % 10;
                w[i]/=10;
                d = w[i] % 10;
                w[i]/=10;
                t = w[i] % 10;

                w[i] = cpy;

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
    /*for (i=0;i<=50;i++){
        for (int j=0;j<=7;j++){
            if (a[make_pair(j,i)])
                fprintf (fout,"#");
            fprintf (fout," ");
            //fprintf (fout,"%lld",a[make_pair(i,j)]);
        }
        fprintf (fout,"\n");
    }*/
    fprintf (fout,"%lld",sol);
    return 0;
}

