#include <cstdio>

using namespace std;
int v[1010],w[1010];
int main()
{
    FILE *fin = fopen ("a.in","r");
    FILE *fout = fopen ("a.out","w");
    int i,x,y;
    char c;
    for (i=0;i<=140;i++){
        c = fgetc (fin);
        while ('0' > c || c > '9')
            c = fgetc (fin);
        while ('0' <= c && c <= '9'){
            v[i] = v[i] * 10 + c - '0';
            c = fgetc (fin);
        }
    }
    for (x=0;x<99;x++){
        for (y = 0 ; y < 99 ; y ++){
            for (i=0;i<=140;i++){
                w[i] = v[i];
            }
            w[1] = x;
            w[2] = y;
            for (i=0;i<=140;i+=4){
                if (w[i] == 99){
                    break;
                }
                if (w[i] == 1)
                    w[w[i+3]] = w[w[i+1]] + w[w[i+2]];
                else w[w[i+3]] = w[w[i+1]] * w[w[i+2]];
            }
            if (w[0] == 19690720){
                fprintf (fout,"%d" , 100 * x + y);
            }
        }
    }

    //fprintf (fout,"%d",v[0]);
    return 0;
}

