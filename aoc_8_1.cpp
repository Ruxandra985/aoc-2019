#include <cstdio>
#define DIML 6
#define DIMC 25
#define DIM 15000
using namespace std;
int a[50][50] , b[50][50];
int main()
{
    FILE *fin = fopen ("a.in","r");
    FILE *fout = fopen ("a.out","w");
    int l , c ,x , y , i , mini , sol , nr0 , nr1 , nr2;
    char ch;
    l = 1;
    c = 1;
    for (x=1;x<=DIML;x++)
        for (y=1;y<=DIMC;y++)
            b[x][y] = 2; /// transparent
    mini = 2000000000;
    sol = 0;
    for (i=1;i<=DIM;i++){
        ch = fgetc (fin);
        a[l][c] = ch - '0';
        nr0 = nr1 = nr2 = 0;
        if (l == DIML && c == DIMC){
            //printf ("%d ",i);
            for (x=1;x<=DIML;x++){
                for (y=1;y<=DIMC;y++){
                    if (b[x][y] == 2)
                        b[x][y] = a[x][y];
                    if (a[x][y] == 0)
                        nr0++;
                    else if (a[x][y] == 1)
                        nr1++;
                    else nr2++;
                }
            }
            if (nr0 < mini){
                mini = nr0;
                sol = nr1 * nr2;
            }
        }
        c++;
        if (c == DIMC+1){
            l++;
            c = 1;
        }
        if (l == DIML+1)
            l = 1;
    }
    fprintf (fout,"%d\n",sol);
    /*for (x=1;x<=DIML;x++){
        for (y=1;y<=DIMC;y++){
            if (b[x][y] != 0)
                fprintf (fout,"O");
            else fprintf (fout," ");
        }
        fprintf (fout,"\n");
    }*/
    return 0;
}

