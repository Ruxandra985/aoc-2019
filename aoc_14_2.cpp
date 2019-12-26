#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#define ORE 9179
#define FUEL 90736
#define REACT 61
#define MOD 666013
using namespace std;
FILE *fin = fopen ("a.in","r");
FILE *fout = fopen ("a.out","w");
deque <pair <long long,long long> > dq;
vector <pair <long long,long long> > v[MOD + 30];
map <long long,long long> f , fq;
set <long long> s;
long long q[MOD + 30] , cnt[MOD+30] , need[MOD + 30];
long long x[200] , hsh[200];
long long getnr (){
    long long nr = 0;
    char c;
    c = fgetc (fin);
    while ('0' > c  || c > '9')
        c = fgetc ( fin );
    while ('0' <= c && c <= '9'){
        nr = nr * 10 + c - '0';
        c = fgetc (fin);
    }
    return nr;
}
long long gethsh (){
    long long nr = 0;
    char c;
    c = fgetc (fin);
    while ('A' > c  || c > 'Z')
        c = fgetc ( fin );
    while ('A' <= c && c <= 'Z'){
        nr = nr * ('Z' - 'A') + c - 'A';
        c = fgetc (fin);
    }
    return nr%MOD;
}
int main()
{
    long long i , h1 , h2 , h3 , y , z , h , cant , nr , a , b;
    long long j;
    char c;
    for (i=1;i<=REACT;i++){
        //if (i == 33)
          //  prlong longf ("a");

        c = fgetc (fin);
        j = 0;
        while (c != '='){

            j++;
            x[j] = hsh[j] = 0;

            while ('0' > c  || c > '9')
                c = fgetc ( fin );
            while ('0' <= c && c <= '9'){
                x[j] = x[j] * 10 + c - '0';
                c = fgetc (fin);
            }

            while ('A' > c  || c > 'Z')
                c = fgetc ( fin );
            while ('A' <= c && c <= 'Z'){
                hsh[j] = hsh[j] * ('Z' - 'A') + c - 'A';
                c = fgetc (fin);
            }
            hsh[j]%=MOD;
            f[hsh[j]] = 1;
            cnt[hsh[j]]++;
            s.insert(hsh[j]);
            c = fgetc (fin);

        }

        z = getnr();
        h = gethsh();
        s.insert(h);
        f[h] = 1;
        q[h] = z; /// atat se obt
        for (;j;j--){
            v[h].push_back(make_pair(x[j] , hsh[j]));
        }

    }
    need[FUEL] = 7863863;
    //need[FUEL] = 1;
    int idk = 0;
    while (true){

        /// iit alegi un elem din s
        idk ++;
        //printf ("%d " , idk);
        for (set <long long> :: iterator it = s.begin() ; it!=s.end() ; it++){
            if (cnt[(*it)] == 0){ /// i nu mai contribuie in vreo reactie , e doar produs
                cnt[(*it)] = -1;
                h = (*it);
                s.erase(it);
                break;
            }
        }

        //prlong longf ("%d " , i);

        cant = need[h];

        if (h == ORE){
            fprintf (fout,"%lld",cant);
            return 0;
        }

        nr = cant / q[h];

        if (q[h] * nr < cant)
            nr++;

        for (i=0;i<v[h].size();i++){

            a = v[h][i].first;
            b = v[h][i].second;

            cnt[b]--;
            need[b] += a * nr;


        }

    }
    return 0;
}

