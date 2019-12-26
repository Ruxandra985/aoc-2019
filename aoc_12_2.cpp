#include <cstdio>
#include <map>
#include <iostream>
using namespace std;
long long x[5],y[5],z[5],vx[5],vy[5],vz[5];
map <pair < pair <pair <long long , long long> ,pair <long long , long long> >
 ,pair <pair <long long , long long> ,pair <long long , long long> > >  , long long> mx,my,mz;
long long m (long long x){
    if (x < 0)
        return -x;
    return x;

}
long long cmmdc (long long a , long long b){
    long long r;
    while (b){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
long long cmmmc (long long a , long long b){
    return a * b / cmmdc(a , b);
}
int main()
{
    FILE *fin = fopen ("a.in","r");
    FILE *fout = fopen ("a.out","w");
    long long i , j , step , n , sol , nx, ny , nz;
    pair < pair <pair <long long , long long> ,pair <long long , long long> >
 ,pair <pair <long long , long long> ,pair <long long , long long> > > aux;
    n = 4;
    for (i=1;i<=n;i++){
        fscanf (fin,"%lld%lld%lld",&x[i],&y[i] , &z[i]);
    }
    for (step = 0 ; ; step++){
        aux.first = make_pair ( make_pair(x[1] , x[2]) , make_pair(x[3] , x[4]) );
        aux.second = make_pair ( make_pair(vx[1] , vx[2]) , make_pair(vx[3] , vx[4]) );
        if (mx[aux]){
            nx = step;
            break;
        }
        mx[aux] = 1;
        for (i=1;i<=n;i++){
            for (j=i+1;j<=n;j++){
                if (x[i] < x[j]){
                    vx[i]++;
                    vx[j]--;
                }
                else if (x[i] > x[j]){
                    vx[i]--;
                    vx[j]++;
                }
            }
        }
        for (i=1;i<=n;i++)
            x[i]+=vx[i];
    }

    for (step = 0 ; ; step++){
        aux.first = make_pair ( make_pair(y[1] , y[2]) , make_pair(y[3] , y[4]) );
        aux.second = make_pair ( make_pair(vy[1] , vy[2]) , make_pair(vy[3] , vy[4]) );
        if (my[aux]){
            ny = step;
            break;
        }
        my[aux] = 1;
        for (i=1;i<=n;i++){
            for (j=i+1;j<=n;j++){
                if (y[i] < y[j]){
                    vy[i]++;
                    vy[j]--;
                }
                else if (y[i] > y[j]){
                    vy[i]--;
                    vy[j]++;
                }
            }
        }
        for (i=1;i<=n;i++)
            y[i]+=vy[i];
    }

    for (step = 0 ; ; step++){
        aux.first = make_pair ( make_pair(z[1] , z[2]) , make_pair(z[3] , z[4]) );
        aux.second = make_pair ( make_pair(vz[1] , vz[2]) , make_pair(vz[3] , vz[4]) );
        if (mz[aux]){
            nz = step;
            break;
        }
        mz[aux] = 1;
        for (i=1;i<=n;i++){
            for (j=i+1;j<=n;j++){
                if (z[i] < z[j]){
                    vz[i]++;
                    vz[j]--;
                }
                else if (z[i] > z[j]){
                    vz[i]--;
                    vz[j]++;
                }
            }
        }
        for (i=1;i<=n;i++)
            z[i]+=vz[i];
    }


    fprintf (fout,"%lld" , cmmmc (cmmmc(nx , ny) , nz));
    /*for (step = 1; step <= 1000 ; step++){
        for (i=1;i<=n;i++){
            for (j=i+1;j<=n;j++){
                if (x[i] < x[j]){
                    vx[i]++;
                    vx[j]--;
                }
                else if (x[i] > x[j]){
                    vx[i]--;
                    vx[j]++;
                }


                if (y[i] < y[j]){
                    vy[i]++;
                    vy[j]--;
                }
                else if (y[i] > y[j]){
                    vy[i]--;
                    vy[j]++;
                }


                if (z[i] < z[j]){
                    vz[i]++;
                    vz[j]--;
                }
                else if (z[i] > z[j]){
                    vz[i]--;
                    vz[j]++;
                }
            }
        }

        for (i=1;i<=n;i++){
            x[i]+=vx[i];
            y[i]+=vy[i];
            z[i]+=vz[i];
            //printf ("%d %d %d %d %d %d\n",x[i] , y[i] , z[i] , vx[i] , vy[i] , vz[i]);
        }

        /// asa arata dupa i+1 steps

    }
    sol = 0;
    for (i=1;i<=n;i++){
        sol = sol + (m(x[i]) + m(y[i]) + m(z[i])) * (m(vx[i]) + m(vy[i]) + m(vz[i]));
    }
    fprintf (fout,"%lld\n",sol);*/

    return 0;
}

