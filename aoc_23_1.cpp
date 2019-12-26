#include <cstdio>
#include <deque>
#include <algorithm>
#include <map>
#include <string>
#define DIM 2218
using namespace std;
map <long long , long long> v , w[50];
long long poz[50] , base[50] , nrinpt[50] , time[50] , which[50] , outpt[50];
deque <pair <long long,long long> > h[50];
deque <long long> curr[50];
char a[110][110];
int main()
{
    FILE *fin = fopen ("a.in","r");
    FILE *fout = fopen ("a.out","w");
    long long i , sgn , p , d, t, t1 , t2 , cod;
    char c;
    long long nrr , nr , aux ,x , y , z , antx , anty , keepx , keepy;
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
        //printf ("%lld ",i);
    }
    for (i=0;i<=49;i++){
        w[i] = v;
        curr[i][0] = 1;
    }
    for (;;){
        for (nr=0;nr<=49;nr++){
            //nr = 0;
            i = poz[nr];
            while (true){
                //if (nr == 0)
                  //  printf ("%lld ",i);
                if (nr == 49)
                if (w[nr][i] == 99){
                    break;
                }
                cod = w[nr][i] % 100;
                //printf ("%lld ",cod);
                if ( cod <= 2 ){
                    aux = w[nr][i];
                    w[nr][i]/=100;
                    p = w[nr][i] % 10;
                    w[nr][i]/=10;
                    d = w[nr][i] % 10;
                    w[nr][i]/=10;
                    t = w[nr][i] % 10;

                    w[nr][i] = aux;

                    /// stii ca p e 0 mereu

                    if (p == 0)
                        t1 = w[nr][w[nr][i+1]];
                    else if (p == 1)
                        t1 = w[nr][i+1];
                    else
                        t1 = w[nr][w[nr][i+1] + base[nr]];

                    if (d == 0)
                        t2 = w[nr][w[nr][i+2]];
                    else if (d == 1)
                        t2 = w[nr][i+2];
                    else t2 = w[nr][w[nr][i+2] + base[nr]];


                    if (cod == 1){
                        if (t == 0)
                            w[nr][w[nr][i+3]] = t1 + t2;
                        else w[nr][w[nr][i+3] + base[nr]] = t1 + t2;
                    }
                    else {
                        if (t == 0)
                            w[nr][w[nr][i+3]] = t1 * t2;
                        else w[nr][w[nr][i+3] + base[nr]] = t1 * t2;
                    }
                    i+=4;
                }
                else { /// cod 3 sau 4
                    if (cod == 3){
                        //printf ("input\n");
                        p = w[nr][i] / 100 % 10;
                        if (p == 0){
                            if (nrinpt[nr] == 0)
                                w[nr][w[nr][i+1]] = nr;
                            else if (nrinpt[nr] == 1)
                                w[nr][w[nr][i+1]] = -1;
                            else {
                                if (h[nr].empty()){
                                    break;
                                }
                                else {
                                    if (which[nr] == 0)
                                        w[nr][w[nr][i+1]] = h[nr].front().first; /// X
                                    else {
                                        w[nr][w[nr][i+1]] = h[nr].front().second; /// Y
                                        h[nr].pop_front();
                                    }
                                    which[nr] = 1 - which[nr];
                                }
                            }
                        }
                        else{
                            if (nrinpt[nr] == 0)
                                w[nr][w[nr][i+1] + base[nr]] = nr;
                            else if (nrinpt[nr] == 1)
                                w[nr][w[nr][i+1] + base[nr]] = -1;
                            else {
                                //printf ("%lld\n",nr);
                                if (h[nr].empty()){
                                    break;
                                }
                                else {
                                    if (which[nr] == 0)
                                       w[nr][w[nr][i+1] + base[nr]] = h[nr].front().first; /// X
                                    else {
                                        w[nr][w[nr][i+1] + base[nr]] = h[nr].front().second; /// Y
                                        h[nr].pop_front();
                                    }
                                    which[nr] = 1 - which[nr];
                                }
                            }
                        }
                        nrinpt[nr] ++;
                        i+=2;
                    }
                    else if (cod == 4){
                        p = w[nr][i] / 100 % 10;
                        if (p == 0)
                            nrr = w[nr][w[nr][i+1]];
                        else if (p == 1)
                            nrr = w[nr][i+1];
                        else
                            nrr = w[nr][w[nr][i+1] + base[nr]];

                        curr[nr].push_back(nrr);
                        i+=2;
                    }
                    else if (cod == 9){
                        p = w[nr][i] / 100 % 10;
                        if (p == 0)
                            base[nr] += w[nr][w[nr][i+1]];
                        else if (p == 1)
                            base[nr] += w[nr][i+1];
                        else base[nr] += w[nr][w[nr][i+1] + base[nr]];
                        i+=2;
                    }
                    else {
                        aux = w[nr][i];
                        w[nr][i]/=100;
                        p = w[nr][i] % 10;
                        w[nr][i]/=10;
                        d = w[nr][i] % 10;
                        w[nr][i]/=10;
                        t = w[nr][i] % 10;

                        w[nr][i] = aux;

                        /// stii ca p e 0 mereu

                        if (p == 0)
                            t1 = w[nr][w[nr][i+1]];
                        else if (p == 1)
                            t1 = w[nr][i+1];
                        else
                            t1 = w[nr][w[nr][i+1] + base[nr]];

                        if (d == 0)
                            t2 = w[nr][w[nr][i+2]];
                        else if (d == 1)
                            t2 = w[nr][i+2];
                        else t2 = w[nr][w[nr][i+2] + base[nr]];

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
                                w[nr][w[nr][i+3]] = (t1 < t2);
                            else w[nr][w[nr][i+3] + base[nr]] = (t1 < t2);
                            i+=4;
                        }
                        else if (cod == 8){
                            if (t == 0)
                                w[nr][w[nr][i+3]] = (t1 == t2);
                            else w[nr][w[nr][i+3] + base[nr]] = (t1 == t2);
                            i+=4;
                        }

                    }
                }
            }
            poz[nr] = i;
        }
        printf ("a");
        for (nr=0;nr<50;nr++){
            while (!curr[nr].empty()){

                x = curr[nr].front();
                curr[nr].pop_front();
                y = curr[nr].front();
                curr[nr].pop_front();
                z = curr[nr].front();
                curr[nr].pop_front();
                //printf ("%lld %lld %lld\n" ,x,y, z);
                if (x == 255){
                    keepx = y;
                    keepy = z;
                    printf ("%lld\n" , z);
                    return 0;
                }
                else h[x].push_back(make_pair(y , z));
            }
        }

        for (i=0;i<50;i++){
            if (h[i].empty())
                nrinpt[i] = 1; /// o sa pui -1
            else break;
        }

        if (i == 50){ /// toate sunt goale
            nrinpt[0] = 2;
            h[0].push_back(make_pair(keepx , keepy));
            if (keepy == anty ){
                printf ("%lld\n",keepy);
                return 0;
            }
            antx = keepx;
            anty = keepy;
        }

    }
    return 0;
}

