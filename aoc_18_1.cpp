#include <cstdio>
#include <map>
#include <algorithm>
#include <deque>
#define DIML 81
#define DIMC 81
using namespace std;
int a[DIML + 10][DIMC + 10];
map < pair <int ,pair < int,int  > > ,int> dp;
deque < pair <int ,pair < int,int  > > > dq;
int di[]={0,0,-1,1};
int dj[]={-1,1,0,0};
int main()
{
    FILE *fin = fopen ("a.in","r");
    FILE *fout = fopen ("a.out","w");
    int i , j , ic , jc , iv , jv , d , n , m , stare , news , nrlit , poz;
    int  is , js , key , door;
    pair <int , pair <int,int> >  curr , aux;
    char c;
    n = DIML;
    m = DIMC;
    nrlit = 0;
    for (i=1;i<=n;i++){
        for (j=1;j<=m;j++){
            c=fgetc (fin);
            if (c=='#')
                a[i][j] = -1; /// blocat
            else if (c == '@'){
                is = i;
                js = j;
                a[i][j] = 0; /// liber
            }
            else if (c == '.')
                a[i][j] = 0;
            else if ('a'<=c && c<='z'){
                a[i][j] = 1 + c - 'a';
                nrlit++;
            }
            else a[i][j] = -2 - ( c - 'A');
        }
        fgetc (fin);
    }

    /// dp[i][j][stare] = nr min de pasi sa ajungi in i j cu starea stare
    /// 41 , 41
    is = 41;
    js = 41;
    curr.first = 0;
    curr.second.first = is;
    curr.second.second = js;
    dp[curr] = 1;

    dq.push_back(curr);

    while (!dq.empty()){
        curr = dq.front();
        ic = dq.front().second.first;
        jc = dq.front().second.second;
        //printf ("%d %d %d\n" , ic , jc , stare);
        dq.pop_front();

        if (curr.first == (1 << nrlit) - 1){
            fprintf (fout,"%d" , dp[curr] - 1);
            return 0;
        }
        for (d=0;d<4;d++){
            iv = ic + di[d];
            jv = jc + dj[d];
            aux.second = make_pair(iv,jv);
            aux.first = curr.first;
            if (iv && jv && iv <= n && jv <= m){
                if (a[iv][jv] == -1)
                    continue; /// nu poti aici
                else if (a[iv][jv] == 0){
                    if (!dp[aux]){ /// starea nu se schimba
                        dp[aux] = 1 + dp[curr];
                        dq.push_back(aux);
                    }
                }
                else if (a[iv][jv] > 0){
                    key = a[iv][jv] - 1;
                    aux.first = (curr.first | (1 << key));
                    if (!dp[aux]){ /// starea nu se schimba
                        dp[aux] = 1 + dp[curr];
                        dq.push_back(aux);
                    }
                }
                else {
                    door = -a[iv][jv] - 2;
                    if ((aux.first & (1 << door) )!= 0 && !dp[aux] ){ /// conditie
                        dp[aux] = 1 + dp[curr];
                        dq.push_back(aux);
                        /// in sine , starea nu se schimba
                    }
                }
            }
        }

    }

    return 0;
}

