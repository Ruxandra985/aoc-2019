#include <cstdio>
#include <iostream>
using namespace std;
int a[20000][20000];
int modulo (int x){
    if (x  < 0)
        return - x;
    return x;
}
int main()
{
    FILE *fin = fopen ("a.in","r");
    FILE *fout = fopen ("a.out","w");
    int ii , jj , sol , dir , nr , i , ok , step;
    char c;
    c = fgetc(fin);
    ii = 10000;
    jj = 10000;
    a[10000][10000] = 1;
    step = 1;
    sol = 2000000000;
    nr = 0;
    ok = 0;
    while (c != '\n'){
        if (c == 'R')
            dir = 1;
        else if (c == 'L')
            dir = 2;
        else if (c == 'U')
            dir = 3;
        else if (c == 'D')
            dir = 4;
        else if ('0' <= c && c <= '9'){
            nr = nr * 10 + c - '0';
        }
        else if (c == ','){
            /*if (!ok)
                nr++;
            ok = 1;*/
            //printf ("%d ",nr);
            for (i=1;i<=nr;i++){
                if (dir == 1)
                    jj++;
                else if (dir == 2)
                    jj--;
                else if (dir == 3)
                    ii--;
                else ii++;
                step ++;
                if (!a[ii][jj])
                    a[ii][jj] = step;
                //printf ("%d %d\n" , ii-10000 , jj-10000);

            }
            nr = 0;
        }
        c = fgetc (fin);
    }
    if (dir == 1)
                    jj++;
                else if (dir == 2)
                    jj--;
                else if (dir == 3)
                    ii--;
                else ii++;
                a[ii][jj]++;
    //printf ("%d %d\n" , ii-10000 , jj-10000);
    c = fgetc(fin);
    ii = 10000;
    jj = 10000;
    step = 1;
    sol = 2000000000;
    nr = 0;
    ok = 0;
    while (c != '\n'){
        if (c == 'R')
            dir = 1;
        else if (c == 'L')
            dir = 2;
        else if (c == 'U')
            dir = 3;
        else if (c == 'D')
            dir = 4;
        else if ('0' <= c && c <= '9'){
            nr = nr * 10 + c - '0';
        }
        else if (c == ','){
            /*if (!ok)
                nr++;
            ok = 1;*/
            for (i=1;i<=nr;i++){
                if (dir == 1)
                    jj++;
                else if (dir == 2)
                    jj--;
                else if (dir == 3)
                    ii--;
                else ii++;
                step++;
                if (a[ii][jj] && (ii != 10000 || jj != 10000)){
                    sol = min ( sol , a[ii][jj] + step - 2 );
                }

            }
            nr = 0;
        }
        c = fgetc (fin);
    }
    if (dir == 1)
                    jj++;
                else if (dir == 2)
                    jj--;
                else if (dir == 3)
                    ii--;
                else ii++;
                if (a[ii][jj] == 1 && (ii != 10000 || jj != 10000)){
                    sol = min ( sol , a[ii][jj] + step - 2 );
                }

    fprintf (fout,"%d",sol);
    return 0;
}

