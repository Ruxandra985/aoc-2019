#include <cstdio>
#include <algorithm>
#define DIML 43
#define DIMC 43
#define FIND 200
using namespace std;
char a[DIML+10][DIMC+10];
pair <int,int> p[DIML * DIMC];
int f[DIML * DIMC];
int  n, m;
int cmmdc (int x , int y){
    int r;
    while (y){
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}
int modul (int x){
    if ( x >= 0 )
        return x;
    return -x;
}
int calcul (int x , int y){
    int i , j , sol , dl , dc , l , c , gcd;
    sol = 0;
    for (i=1;i<=n ; i++){
        for (j=1;j<=m;j++){
            if (a[i][j] == '#' && (i!=x || j !=y)){

                dl = i - x;
                dc = j - y;

                gcd = cmmdc ( dl , dc );

                dl/= modul(gcd);
                dc/=modul (gcd);

                l = x + dl;
                c = y + dc;

                while ( l>0 && c>0 && l <= n && c <= m){

                    if (a[l][c] == '#')
                        break;

                    l+= dl;
                    c+= dc;
                }

                if ( l == i && c == j )
                    sol++;

            }
        }
    }
    return sol;

}
int cadran (pair <int,int> a){
    if (a.first>=0 && a.second>=0)
        return 1;
    if (a.first<=0 && a.second>=0)
        return 4;
    if (a.first<0 && a.second<=0)
        return 3;
    return 2;
}
int diferit (int curr , int j){
    if (cadran(p[curr]) != cadran (p[j]))
        return 1;
    return modul(p[curr].second * p[j].first ) != modul(p[curr].first * p[j].second );
}
int cmp (pair <int,int> a,pair <int,int> b){ /// return 1 = ordinea buna
    int ca=cadran (a),cb=cadran(b);
    if (ca!=cb)
        return ca<=cb;

    if (ca ==1){ /// unghiuri sub 90
        if (a.second * b.first != b.second * a.first)
            return a.second * b.first > b.second * a.first;
        /// ELSE
        return (a.second * a.second + a.first * a.first) <= (b.second * b.second + b.first * b.first);
    }
    else if (ca==2) { /// unghiuri de 90 +
         if (modul(a.second * b.first) != modul(b.second * a.first))
            return modul(a.second * b.first) < modul(b.second * a.first);
        /// ELSE
        return (a.second * a.second + a.first * a.first) <= (b.second * b.second + b.first * b.first);
    }
    else if (ca==3){
        if (modul(a.second * b.first) != modul(b.second * a.first))
            return modul(a.second * b.first) > modul(b.second * a.first);
        /// ELSE
        return (a.second * a.second + a.first * a.first) <= (b.second * b.second + b.first * b.first);
    }
    else {
        if (modul(a.second * b.first) != modul(b.second * a.first))
            return modul(a.second * b.first) < modul(b.second * a.first);
        /// ELSE
        return (a.second * a.second + a.first * a.first) <= (b.second * b.second + b.first * b.first);
    }

}
int ajutor (int x , int y){

    int elem , i , j , curr;
    elem = 0;
    for (i=1;i<=n;i++){
        for (j=1;j<=m;j++){
            if (a[i][j] == '#' && (i!=x || j != y)){
                /*elem++;
                if ( i <= x )
                    p[elem].first = x - i;
                else p[elem].first =*/
                if (i == 1 && j == 10)
                    printf ("a");
                p[++elem] = make_pair( j - y , x - i);
            }
        }
    }
    sort (p + 1 , p + elem + 1 , cmp); /// sortarea naspa

    curr = 1;

    for (i=1;i<FIND;i++){
        f[curr] = 1;
        //printf ("%d %d\n" , -p[curr].second + x , p[curr].first + y);
        for (j = curr + 1 ; ; j = j % elem + 1){
            if (!f[j] && diferit(curr , j))
                break;
        }
        curr = j;
    }

    return (p[curr].first + y-1) * 100 + -p[curr].second + x-1;
}
int main()
{
    FILE *fin = fopen ("a.in","r");
    FILE *fout = fopen ("a.out","w");
    int i , j , sol , isol , jsol;
    n = DIML;
    m = DIMC;
    for (i=1;i<=n;i++){
        for (j=1;j<=m;j++){
            a[i][j] = fgetc (fin);

        }
        fgetc (fin);
    }
    sol = 0;
    isol = jsol = 0;
    for (i=1;i<=n;i++){
        for (j=1;j<=m;j++){
            if (a[i][j] == '#'){
                if (sol <= calcul ( i , j )){
                    sol = calcul ( i , j );
                    isol = i;
                    jsol = j;
                }
            }
        }
    }
    fprintf (fout,"%d\n" , sol);
    //fprintf (fout,"%d" , ajutor (isol , jsol));

    return 0;
}

