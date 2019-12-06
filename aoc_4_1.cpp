#include <cstdio>

using namespace std;
int check (int x){
    int  ok , curr , ant , egl = 1 , stop = 0,ok2;

    ok2 = ok = 0;

    while (x){
        curr = x % 10;
        if (ok){
            if (curr == ant)
                egl++;
            else {
                if (egl == 2)
                    ok2 = 1;
                egl = 1;
            }
            if (curr > ant)
                stop = 1;
        }
        ok = 1;
        ant = curr;
        x/=10;
    }
    if (egl == 2)
        ok2 = 1;
    /*while (x){
        curr = x % 10;
        if (ok){
            if (curr == ant)
                egl = 1;
            if (curr > ant)
                stop = 1;
        }
        ok = 1;
        ant = curr;
        x/=10;
    }*/

    if (stop || !ok2)
        return 0;
    return 1;

}
int main()
{
    FILE *fin = fopen ("a.in","r");
    FILE *fout = fopen ("a.out","w");
    int a , b , i , sol;
    fscanf (fin,"%d%d",&a,&b);
    sol = 0;
    for (i=a;i<=b;i++){
        sol = sol + check(i);
    }
    fprintf (fout,"%d",sol);
    return 0;
}

