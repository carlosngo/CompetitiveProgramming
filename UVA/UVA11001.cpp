#include<cmath>
#include<cstdio>
 
using namespace std;
 
int Vt, Vo;
 
int main() {
    for(;;) {
        scanf("%d %d", &Vt, &Vo);
        if(Vt == 0 && Vo == 0) break;
 
        double D = 0, l, max_l = 0;
        int max = 0;
        for(int i = 1;; i++) {
            double V = (double) Vt / i;
            if(V <= Vo) break;
            D = 0.3d * sqrt(V - Vo);
            l = i * D;
            if(l >= max_l) {
                if(fabs(l - max_l) < 1e-12) {
                    max_l = 0;
                    max = 0;
                    break;
                }
                max_l = l;
                max = i;
            }
        }
        printf("%d\n", max);
    }
}