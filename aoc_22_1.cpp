#include <bits/stdc++.h>
#define OP 100
using namespace std;
int aux[20010] , v[20010];
int main()
{
    FILE *fin = fopen ("a.in","r");
    FILE *fout = fopen ("a.out","w");
    int i , x , st , dr , y , poz;
    for (i=1;i<=10007;i++)
        v[i] = i-1;
    for (int t = OP ; t ; t--){
        fscanf (fin,"%d",&x);
        if (x == 1){
            st = 1;
            dr = 10007;
            while (st < dr){
                swap(v[st] , v[dr]);
                st++;
                dr--;
            }
        }
        else if (x == 0){ /// deal w increment
            fscanf (fin,"%d",&y);
            poz = 0;
            for (i=1;i<=10007;i++){
                aux[poz+1] = v[i];
                poz = (poz + y)%10007;
            }
            for (i=1;i<=10007;i++){
                v[i] = aux[i];
            }
        }
        else { /// cut
            fscanf (fin,"%d",&y);
            if (y > 0){ /// iei y de la inceput si la pui la sf
                for (i=1;i<=y;i++)
                    aux[i] = v[i];
                for (i = y+1; i<=10007;i++)
                    v[i-y] = v[i];
                for (i= 10007 - y + 1 ; i<= 10007;i++)
                    v[i] = aux[i - 10007 + y];
            }
            else { /// iei y de la sf si la pui la inc
                y = -y;;
                for (i=10007 - y + 1;i<=10007;i++)
                    aux[i] = v[i];
                for (i = 10007; i - y > 0;i--)
                    v[i] = v[i - y];
                for (i= 1 ; i<= y;i++)
                    v[i] = aux[i + 10007 - y];
            }
        }
    }
    for (i=1;i<=10007;i++){
        if (v[i] == 2019)
            fprintf (fout,"%d",i-1);
    }
    return 0;
}

