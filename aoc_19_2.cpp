#include <cstdio>
#include <iostream>
#include <map>
#define DIM 423
using namespace std;
map <long long , long long> v , w;
int a[110][110];
int di[]={0,0,99,99};
int dj[]={0,99,0,99};
long long check (long long y){

    long long i,x , sgn , p , d, t, t1 , t2 , cod , base , nr , sol = 0 , xv,yv;
    w = v;
    printf ("%lld ",y);
    long long maxs = 0;
    for (x=0;x<10000;x++){
        sol = 0;
        for (int dir=0;dir<4;dir++){
            yv = di[dir] + y;
            xv = dj[dir] + x;
            w = v;
            base = 0;
            nr = 0;
            i = 0;
            ///2171927479
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
                        if (!nr){
                            if (p == 0)
                                w[w[i+1]] = xv;
                            else w[w[i+1] + base] = xv;
                        }
                        else if (nr == 1) {
                            if (p == 0)
                                w[w[i+1]] = yv;
                            else w[w[i+1] + base] = yv;
                        }
                        nr++;
                        i+=2;
                    }
                    else if (cod == 4){
                        p = w[i] / 100 % 10;
                        if (p == 0)
                            sol += w[w[i+1]];
                        else if (p == 1)
                            sol += w[i+1];
                        else
                            sol += w[w[i+1] + base];
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
        }
        maxs = max(maxs , sol);
        if (sol == 4)
            return x;
    }
    printf ("%lld\n",maxs);
    return -1;

}
int main()
{
    FILE *fin = fopen ("a.in","r");
    FILE *fout = fopen ("a.out","w");
    long long i,x,y , sgn , p , d, t, t1 , t2 , cod , base , nr , st , dr , mid ;
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
    st = 0;
    dr = 10000;
    while (st <= dr){
        mid = (st + dr)/2;
        x = check(mid);
        if (x!=-1)
            dr = mid - 1;
        else st = mid + 1;
    }
    ///7831528
    ///7761515
    x = check(st);
    fprintf (fout,"%lld",x*10000 + st);
    return 0;
}

