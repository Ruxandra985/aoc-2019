#include <bits/stdc++.h>
#define DIML 109
#define DIMC 107
#define MAXL 1000
using namespace std;
int di[]={-1,1,0,0};
int dj[]={0,0,-1,1};
int a[DIML + 10][DIMC + 10] , dp[MAXL + 10][DIML + 10][DIMC + 10];
deque <pair < int , pair <int,int> > > dq;
int main()
{
    FILE *fin = fopen ("a.in","r");
    FILE *fout = fopen ("a.out","w");
    int i , j , d , iv , jv , ic , jc , lvlc , lvlv;
    char c;
    for (i=1;i<=DIML;i++){
        for (j=1;j<=DIMC;j++){
            c=fgetc (fin);
            if (c == '\n')
                break;
           // if (i == 109 && j == 72)
             //   printf ("a");
            if ('A' <= c && c <= 'Z'){
                if (i == 1 || i == 81){
                    a[i+1][j] = (c - 'A');
                }
                else if (i == 2 || i == 82){
                    a[i][j] = (a[i][j] * ('Z' - 'A')) + (c - 'A');
                }
                else if (j == 1 || j == 79){
                    a[i][j+1] = (c - 'A');
                }
                else if (j == 2 || j == 80){
                    a[i][j] = (a[i][j] * ('Z' - 'A')) + (c - 'A');
                }
                else if (j == 28 || j == 106){
                    a[i][j] = (c - 'A');
                }
                else if (j == 29 || j == 107){
                    a[i][j-1] = (a[i][j-1] * ('Z' - 'A')) + (c - 'A');
                }
                else if (i == 108 || i == 28){
                    a[i][j] = c - 'A';
                }
                else if (i == 109 || i == 29){
                    a[i-1][j] = (a[i-1][j] * ('Z' - 'A')) + (c - 'A');
                }
                else printf ("nu am pus %d %d\n" , i , j);
            }
            else if (c == '#' || c == ' ')
                a[i][j] = -2; /// ocupat
            else a[i][j] = -1; /// liber
        }
        if (c != '\n'){
            fgetc (fin);
        }
    }
    dq.push_back(make_pair (1 , make_pair(107,72)));
    dp[1][107][72] = 1;
    while (!dq.empty()){
        lvlc = dq.front().first;
        ic = dq.front().second.first;
        jc = dq.front().second.second;
        dq.pop_front();
        //printf ("%d\n" , lvlc);
        if (ic == 107 && jc == 54 && lvlc == 1){
            printf ("found");
            fprintf (fout,"%d" , dp[lvlc][ic][jc] - 1);
            return 0;
        }
        for (d=0;d<4;d++){
            iv = ic + di[d];
            jv = jc + dj[d];
            if ( a[iv][jv] > -2 ){
                if (a[iv][jv] == -1){ /// e o casuta libera
                    if (!dp[lvlc][iv][jv]){
                        dp[lvlc][iv][jv] = 1 + dp[lvlc][ic][jc];
                        dq.push_back(make_pair(lvlc , make_pair(iv , jv)) );
                    }
                }
                else { /// e portal
                    lvlv = lvlc;

                    if (iv == 2 || iv == 108 || jv == 2 || jv == 106)
                        lvlv--;
                    else lvlv++;

                    for (i=1;i<=DIML;i++){
                        for (j=1;j<=DIMC;j++){
                            if (a[i][j] == a[iv][jv] && (i != iv || j != jv)){
                                iv = i;
                                jv = j;

                                if (a[iv-1][jv] == -1)
                                    iv--;
                                else if (a[iv+1][jv] == -1)
                                    iv++;
                                else if (a[iv][jv-1] == -1)
                                    jv--;
                                else jv++;

                                if (!dp[lvlv][iv][jv] && lvlv > 0 && lvlv <= MAXL){
                                    dp[lvlv][iv][jv] = 1 + dp[lvlc][ic][jc];
                                    dq.push_back(make_pair(lvlv ,make_pair(iv , jv)));
                                }
                                i = DIML + 1;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

