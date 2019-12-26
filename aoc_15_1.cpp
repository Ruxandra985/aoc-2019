#include <cstdio>
#include <map>
#include <deque>
#include <algorithm>
#define DIM 1044
using namespace std;
map <long long , long long> v , w;
map <pair <long long , long long > , map <long long , long long> > mp;
map < pair <long long , long long > , long long > viz , viz2;
deque <pair <int,int> > dq;
int di[]={-1,1,0,0};
int dj[]={0,0,-1,1};
int modul (int x){
    if (x > 0)
        return x ;
    return -x;
}

int main()
{
    FILE *fin = fopen ("a.in","r");
    FILE *fout = fopen ("a.out","w");
    long long i , sgn , p , d, t, t1 , t2 , cod , base  , ok,dir,sol = 1;
    long long  ic , jc , out , iv , jv;
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
    w = v;
    base = 0;

    dq.push_back(make_pair(0,0));
    mp[make_pair(0,0)] = w;
    viz[make_pair(0,0)] = 1;

    while (!dq.empty()){
        ic = dq.front().first;
        jc = dq.front().second;
        dq.pop_front();
        //printf ("%lld %lld\n" , ic, jc);



        for (dir=0;dir<4;dir++){
            w = mp[make_pair(ic,jc)];
            /// esti in ic jc in momentul asta
            ///faci o mutare in directia d

            iv = ic + di[dir];
            jv = jc + dj[dir];
            if (viz[make_pair(iv,jv)])
                continue; /// nevermind , am mai fost aici

            /// altfel fie e perete, fie e ceva casuta goala

            viz[make_pair(iv,jv)] = 1 + viz[make_pair(ic,jc)];

            i = 0;
            ok = 0;
            for (;;){
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
                        //printf ("%lld ",w[i+1]);
                        if (!ok){
                            ok = 1;
                            p = w[i] / 100 % 10;
                            if (p == 0)
                                w[w[i+1]] = dir+1;
                            else w[w[i+1] + base] = dir+1;
                        }
                        else break;
                        i+=2;
                    }
                    else if (cod == 4){
                        p = w[i] / 100 % 10;
                        if (p == 0)
                            out =  w[w[i+1]];
                        else if (p == 1)
                            out = w[i+1];
                        else
                            out = w[w[i+1] + base];
                        //printf ("%d\n",out);
                        if (out == 2){
                            printf ("%lld %lld" , iv , jv);
                        }
                        else if (out == 1){
                            /// s a miscat
                            dq.push_back(make_pair(iv,jv));
                            mp[make_pair(iv,jv)] = w;
                        }
                        else {
                            /// s a miscat dar a dat in perete
                            viz[make_pair(iv,jv)] = -1; /// perete

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

    }

    fprintf (fout,"%lld\n",viz[make_pair(14,12)]-1);

    /*dq.push_back(make_pair (14,12));
    viz2[make_pair(14,12)] = 1;
    while (!dq.empty()){
        ic = dq.front().first;
        jc = dq.front().second;
        //fprintf (fout,"%lld %lld\n" , ic , jc);
        dq.pop_front();

        for (dir = 0 ; dir < 4 ; dir++){
            iv = ic + di[dir];
            jv = jc + dj[dir];
            if (viz[make_pair(iv,jv)]>0 && !viz2[make_pair(iv,jv)]){
                viz2[make_pair(iv,jv)] = 1 + viz2[make_pair(ic,jc)];
                dq.push_back(make_pair (iv,jv));
                sol = max ( sol , viz2[make_pair(iv,jv)]);
            }
        }

    }

    fprintf (fout,"%lld\n",sol-1);*/
    return 0;
}

