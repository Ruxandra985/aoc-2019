#include <cstdio>
#include <map>
using namespace std;
map <int,int> mp;
int a[10000][10][10] , b[10000][10][10];
//int a[10][10] , b[10][10];
int di[]={0,0,-1,1};
int dj[]={-1,1,0,0};
int sum_vec (int dim , int ic ,int j){
    int sum , d , iv , jv , i;
    sum = 0;
    for (d=0;d<4;d++){
        iv = ic + di[d];
        jv = j + dj[d];
        if (iv == 3 && jv == 3){
            if (d == 0){ /// 3 3 e in stanga
                for (i=1;i<=5;i++)
                    sum = sum + a[dim+1][i][5];
            }
            else if (d == 1){ /// 3 3 e in dreapta
                for (i=1;i<=5;i++)
                    sum = sum + a[dim+1][i][1];
            }
            else if (d == 2){ /// 3 3 e in sus
                for (i=1;i<=5;i++)
                    sum = sum + a[dim+1][5][i];
            }
            else if (d == 3){ /// 3 3 e in jos
                for (i=1;i<=5;i++)
                    sum = sum + a[dim+1][1][i];
            }
        }
        else if (iv == 0){
            sum = sum + a[dim-1][2][3];
        }
        else if (jv == 0){
            sum = sum + a[dim-1][3][2];
        }
        else if (iv == 6){
            sum = sum + a[dim-1][4][3];
        }
        else if (jv == 6){
            sum = sum + a[dim-1][3][4];
        }
        else {
            sum += a[dim][iv][jv];
        }
    }
    return sum;

}
int main()
{
    FILE *fin = fopen ("a.in","r");
    FILE *fout = fopen ("a.out","w");
    int n , m , i , j , cod , dim , dimant , nr,sum ,pas;
    char c;
    n = m = 5;
    cod = 0;
    for (i=1;i<=n;i++){
        for (j=1;j<=m;j++){
            c = fgetc (fin);
            if (c == '#'){
                a[5000][i][j] = 1;
                cod = cod + ( 1 << (5 * (i-1) + j - 1));
            }
        }
        c = fgetc (fin);
    }
    mp[cod] = 1;
    dimant = 10000;
    nr = 1;
    for (pas = 1 ; pas<=200 ; pas++){
        for (dim = dimant - 1 ; dim > nr ; dim--){
            for (i=1;i<=n;i++){
                for (j=1;j<=m;j++){
                    if (i == 3 && j == 3){
                        b[dim][i][j] = 0;
                        continue;
                    }
                    if (a[dim][i][j] == 1 && sum_vec(dim , i , j) != 1)
                        b[dim][i][j] = 0;
                    else if (a[dim][i][j] == 0 && sum_vec(dim , i , j) > 0 &&
                             sum_vec(dim , i , j) <= 2)
                                b[dim][i][j] = 1;
                    else b[dim][i][j] = a[dim][i][j];
                }
            }
        }
        cod = 0;
        sum = 0;
        for (dim = dimant - 1 ; dim > nr ; dim--){
            for (i=1;i<=n;i++){
                for (j=1;j<=m;j++){
                    a[dim][i][j] = b[dim][i][j];
                    sum += a[dim][i][j];
                }

            }
        }
        /*fprintf (fout,"\n");*/

        dimant--;
        nr++;
    }
    /*for (dim = 5000 - 5 ; dim <= 5000 + 5 ; dim++){
        for (i=1;i<=n;i++){
            for (j=1;j<=m;j++){
                if (a[dim][i][j])
                fprintf (fout,"#");
                else fprintf (fout,".");
            }
            fprintf (fout,"\n");
        }
        fprintf (fout,"\n");
    }*/
    fprintf (fout,"%d",sum);
    return 0;
}

