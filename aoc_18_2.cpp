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
int f[10],nrlit[10];
pair <int,int> pozmic[50] , pozmare[50];
int di[]={0,0,-1,1};
int dj[]={-1,1,0,0};
int region (int i , int j){
    if (i<=41){
        if (j<=41)
            return 1;
        return 2;
    }
    else {
        if (j<=41)
            return 3;
        return 4;
    }

}
int main()
{
    FILE *fin = fopen ("a.in","r");
    FILE *fout = fopen ("a.out","w");
    int i , j , ic , jc , iv , jv , d , n , m , stare , news , poz;
    int  is , js , key , door;
    pair <int , pair <int,int> >  curr , aux;
    char c;
    n = DIML;
    m = DIMC;
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
                nrlit[region(i,j)] = nrlit[region(i,j)] + (1 << (c - 'a'));
                pozmic[c-'a'] = make_pair(i,j);
            }
            else {
                a[i][j] = -2 - ( c - 'A');
                pozmare[c-'A'] = make_pair(i,j);
            }
        }
        fgetc (fin);
    }

    /// dp[i][j][stare] = nr min de pasi sa ajungi in i j cu starea stare
    /// 41 , 41
    is = 41;
    js = 41;
    curr.first = 0;
    curr.second.first = is-1;
    curr.second.second = js-1;
    dp[curr] = 1;

    dq.push_back(curr);


    curr.first = 0;
    curr.second.first = is-1;
    curr.second.second = js+1;
    dp[curr] = 1;

    dq.push_back(curr);


    curr.first = 0;
    curr.second.first = is+1;
    curr.second.second = js-1;
    dp[curr] = 1;

    dq.push_back(curr);

    curr.first = 0;
    curr.second.first = is+1;
    curr.second.second = js+1;
    dp[curr] = 1;

    dq.push_back(curr);
    int sol = 0;

    while (!dq.empty()){
        curr = dq.front();
        ic = dq.front().second.first;
        jc = dq.front().second.second;
        //if (region(ic,jc) == 1)
           // printf ("%d\n",dq.front().first);
        //printf ("%d %d %d\n" , ic , jc , dq.front().first);
        dq.pop_front();

        if (curr.first == nrlit[region(ic,jc)]){
            if (!f[region(ic,jc)])
                sol+=dp[curr]-1;
            f[region(ic,jc)] = 1;
            //printf ("a");
            continue;
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
                else if (a[iv][jv] > 0){ /// gasesti o cheie
                    key = a[iv][jv] - 1;
                    aux.first = (curr.first | (1 << key));
                    if (!dp[aux]){ /// starea nu se schimba
                        dp[aux] = 1 + dp[curr];
                        dq.push_back(aux);
                    }
                }
                else {
                    door = -a[iv][jv] - 2;
                    if (region(iv,jv) == region(pozmic[door].first , pozmic[door].second )){
                        if ((aux.first & (1 << door) )!= 0 && !dp[aux] ){ /// conditie
                            dp[aux] = 1 + dp[curr];
                            dq.push_back(aux);
                            /// in sine , starea nu se schimba
                        }
                    }
                    else {
                        dp[aux] = 1 + dp[curr];
                        dq.push_back(aux);
                    }
                }
            }
        }

    }
    fprintf (fout,"%d",sol);
    return 0;
}

