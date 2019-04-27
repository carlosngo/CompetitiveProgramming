#include <stdio.h>

int
main() {
    int n, r, e;
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &n, &r, &e);
        
        int noAdv = r - e;
        if (n < noAdv) printf("advertise\n");
        else if (n > noAdv) printf("do not advertise\n");
        else printf("does not matter\n");
    }
}