#include <bits/stdc++.h>
#define OP 100
using namespace std;
long long n = 119315717514047;
long long times = 101741582076661;
pair <int,long long> tip[110];
long long xm[100] , ym[100] , aux[100];

long long inmult (long long x , long long y){

    long long i , j , t;

    memset (xm , 0 , sizeof(xm));
    memset (ym , 0 , sizeof(ym));
    memset (aux , 0 , sizeof(aux));

    xm[0] = 0;
    while (x){
        xm[++xm[0]] = x % 10;
        x/=10;
    }
    if (xm[0] == 0)
        xm[0] = 1;

    ym[0] = 0;
    while (y){
        ym[++ym[0]] = y % 10;
        y/=10;
    }
    if (ym[0] == 0)
        ym[0] = 1;

    aux[0] = xm[0] + ym[0] - 1;
    for (i=1;i<=xm[0];i++){
        for (j=1;j<=ym[0];j++)
            aux[i + j - 1] += xm[i] * ym[j];
    }
    t = 0;
    for (i=1;i<=aux[0];i++){
        aux[i] += t;
        t = aux[i] / 10;
        aux[i]%= 10;
    }

    while (t){
        aux[++aux[0]] = t % 10;
        t/=10;
    }

    /// acum faci aux % n
    t = 0;
    for (i = aux[0] ; i ; i--){
        t = 10 * t + aux[i];
        aux[i] /= n;
        t %= n;
    }

    while (!aux[aux[0]] && aux[0] > 1)
        aux[0]--;

    return t;

}


long long ridput (long long x , long long y){
    long long sol = 1;
    while (y){

        if (y % 2)
            sol = inmult (sol , x);

        x = inmult (x , x);

        y/=2;
    }

    return sol;
}

long long f (long long poz){ /// pe ce pozitie ajunge cardul x
    int t;

    /// la inceput ma aflu pe pozitia poz
    for (t = 1 ; t <= OP ; t++){
        if (tip[t].first == 1){ /// deal new stack
            poz = n - poz - 1;
        }
        else if (tip[t].first == 2){ /// cut
            if (tip[t].second > 0){ /// iei de la inc , muti la sf
                if (poz < tip[t].second)
                    poz = (n - tip[t].second + poz) % n;
                else poz =  ( poz - tip[t].second ) % n;
            }
            else { /// iei de la sf, pui la inc
                if (n-1 - poz + 1 <= -tip[t].second){ /// se muta
                    poz = ( -tip[t].second - n + poz ) % n;
                }
                else poz = ( poz - tip[t].second ) % n;
            }
        }
        else { /// deal with increment
            poz = (poz * tip[t].second) % n;
        }
    }
    return poz;
}
int main()
{
    FILE *fin = fopen ("a.in","r");
    FILE *fout = fopen ("a.out","w");
    int i , x , st , dr , y , poz;
    long long a , b , a2, b2;
    for (int t=1;t<=OP;t++){
        fscanf (fin,"%d",&x);
        tip[t].first = x;
        if (x == 1){

        }
        else if (x == 0){ /// deal w increment
            fscanf (fin,"%d",&y);
            tip[t].second = y;
        }
        else { /// cut
            fscanf (fin,"%d",&y);
            tip[t].second = y;
        }
    }
    b = f(0);
    a = f(1); /// a * 1 + b
    a = ((a - b) % n + n)%n;
    /// fucntia devine ax + b
    /// de times ori , devine a ^ times * x + b * (a ^ times - 1) / (a - 1)
    a2 = ridput ( a , times );
    b2 = inmult ( inmult (a2 - 1 , ridput(a - 1 , n - 2)) , b);
    /// f de times ori e a2 * x + b2
    /// mai ramane sa gasesc inversa
    fprintf (fout,"%lld" , inmult ( ((2020 - b2) % n + n)%n , ridput(a2 , n - 2) ) );
    return 0;
}

