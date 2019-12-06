#include <cstdio>

using namespace std;

int main()
{
    FILE *fin = fopen ("a.in","r");
    FILE *fout = fopen ("a.out","w");
    int x,i;
    long long sol = 0;
    for (i=1;i<=100;i++){
        fscanf (fin,"%d",&x);
        x = x/3 - 2;
        while (x>0){
            sol = sol + x;
            x = x/3 - 2;
        }
    }
    fprintf (fout,"%lld",sol);

    return 0;
}

