#include <bits/stdc++.h>
#define DIM 1727
using namespace std;
int sol,YOU;
vector <int> v[3000000];
int f[3000000];
void dfs (int nod , int niv){
    int i , vecin;
    f[nod] = 1;
    if (nod == YOU){
        sol = niv;
    }
    for (i=0;i<v[nod].size();i++){
        vecin = v[nod][i];
        if (!f[vecin])
            dfs(vecin , niv + 1);
    }

}
int main()
{
    FILE *fin = fopen ("a.in","r");
    FILE *fout = fopen ("a.out","w");
    int pcom , pyou,psan,nrcom,nryou,nrsan,COM,SAN,i,j,k,nr,a,b;
    char c;
    pcom = 1063;
    pyou = 938;
    psan = 956;
    nrsan = 1;
    nrcom = 0;
    nryou = 1;
    for (i=1;i<=DIM;i++){

        for (j=0;j<=1;j++){
            nr = 0;
            for (k=0;k<3;k++){
                c = fgetc(fin);
                nr = nr * 128 + (int)c;
            }
            if (i == pcom && j == nrcom)
                COM = nr;
            if (i == pyou && j == nryou)
                YOU = nr;
            if (i == psan && j == nrsan)
                SAN = nr;
            if (j == 0)
                a = nr;
            else b = nr;
            fgetc(fin);
        }

        v[a].push_back(b);
        v[b].push_back(a);

    }
    dfs(SAN , 0);
    fprintf (fout,"%d",sol-2);
    return 0;
}
