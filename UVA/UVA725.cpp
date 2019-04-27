#include <bits/stdc++.h>

using namespace std;

// READING INPUT
#define SCD(t) fscanf(stdin, "%d",&t)
#define SCLD(t) fscanf(stdin, "%ld",&t)
#define SCLLD(t) fscanf(stdin, "%lld",&t)
#define SCC(t) fscanf(stdin, "%c",&t)
#define SCS(t) fscanf(stdin, "%s",t)
#define SCF(t) fscanf(stdin, "%f",&t)
#define SCLF(t) fscanf(stdin, "%lf",&t)
// CHECKING BOUNDS
#define IN(i,l,r) (l<i&&i<r) 
#define LINR(i,l,r) (l<=i&&i<=r)
#define LIN(i,l,r) (l<=i&&i<r)
#define INR(i,l,r) (l<i&&i<=r)
// LOOPS
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define WHILEZ int T; SCD(T); while(T--) 
// MISC
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define by(T, x) [](const T& a, const T& b) { return a.x < b.x; }
#define PB push_back
#define INF 1000000000

typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;

// Offset Arrays
const int fx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int fxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	FILE *pFile = fopen("out.txt","w");
    vi num;
    vi denom;
    string ans[81] = {"",
                      "",
                      "13458 / 06729 = 2\n13584 / 06792 = 2\n13854 / 06927 = 2\n14538 / 07269 = 2\n14586 / 07293 = 2\n14658 / 07329 = 2\n15384 / 07692 = 2\n15846 / 07923 = 2\n15864 / 07932 = 2\n18534 / 09267 = 2\n18546 / 09273 = 2\n18654 / 09327 = 2\n26970 / 13485 = 2\n27096 / 13548 = 2\n27690 / 13845 = 2\n29076 / 14538 = 2\n29370 / 14685 = 2\n29670 / 14835 = 2\n29706 / 14853 = 2\n29730 / 14865 = 2\n30972 / 15486 = 2\n32970 / 16485 = 2\n37092 / 18546 = 2\n37290 / 18645 = 2\n41358 / 20679 = 2\n41538 / 20769 = 2\n41586 / 20793 = 2\n46158 / 23079 = 2\n53418 / 26709 = 2\n53814 / 26907 = 2\n54138 / 27069 = 2\n54186 / 27093 = 2\n54618 / 27309 = 2\n58134 / 29067 = 2\n58146 / 29073 = 2\n58614 / 29307 = 2\n61458 / 30729 = 2\n61584 / 30792 = 2\n61854 / 30927 = 2\n62970 / 31485 = 2\n64158 / 32079 = 2\n65418 / 32709 = 2\n65814 / 32907 = 2\n69702 / 34851 = 2\n70296 / 35148 = 2\n70962 / 35481 = 2\n76290 / 38145 = 2\n76902 / 38451 = 2\n90276 / 45138 = 2\n90372 / 45186 = 2\n90762 / 45381 = 2\n92370 / 46185 = 2\n93702 / 46851 = 2\n96270 / 48135 = 2\n96702 / 48351 = 2\n97026 / 48513 = 2\n97032 / 48516 = 2\n97062 / 48531 = 2\n97230 / 48615 = 2\n97302 / 48651 = 2\n",
"17469 / 05823 = 3\n17496 / 05832 = 3\n50382 / 16794 = 3\n53082 / 17694 = 3\n61749 / 20583 = 3\n69174 / 23058 = 3\n91746 / 30582 = 3\n96174 / 32058 = 3\n",
"15768 / 03942 = 4\n17568 / 04392 = 4\n23184 / 05796 = 4\n31824 / 07956 = 4\n60948 / 15237 = 4\n68940 / 17235 = 4\n69408 / 17352 = 4\n81576 / 20394 = 4\n81756 / 20439 = 4\n86940 / 21735 = 4\n94068 / 23517 = 4\n94860 / 23715 = 4\n",
"13485 / 02697 = 5\n13845 / 02769 = 5\n14685 / 02937 = 5\n14835 / 02967 = 5\n14865 / 02973 = 5\n16485 / 03297 = 5\n18645 / 03729 = 5\n31485 / 06297 = 5\n38145 / 07629 = 5\n46185 / 09237 = 5\n48135 / 09627 = 5\n48615 / 09723 = 5\n67290 / 13458 = 5\n67920 / 13584 = 5\n69270 / 13854 = 5\n72690 / 14538 = 5\n72930 / 14586 = 5\n73290 / 14658 = 5\n76920 / 15384 = 5\n79230 / 15846 = 5\n79320 / 15864 = 5\n92670 / 18534 = 5\n92730 / 18546 = 5\n93270 / 18654 = 5\n",
"17658 / 02943 = 6\n27918 / 04653 = 6\n34182 / 05697 = 6\n",
"16758 / 02394 = 7\n18459 / 02637 = 7\n31689 / 04527 = 7\n36918 / 05274 = 7\n37926 / 05418 = 7\n41832 / 05976 = 7\n53298 / 07614 = 7\n98532 / 14076 = 7\n",
"25496 / 03187 = 8\n36712 / 04589 = 8\n36728 / 04591 = 8\n37512 / 04689 = 8\n37528 / 04691 = 8\n38152 / 04769 = 8\n41896 / 05237 = 8\n42968 / 05371 = 8\n46312 / 05789 = 8\n46328 / 05791 = 8\n46712 / 05839 = 8\n47136 / 05892 = 8\n47328 / 05916 = 8\n47368 / 05921 = 8\n51832 / 06479 = 8\n53928 / 06741 = 8\n54312 / 06789 = 8\n54328 / 06791 = 8\n54712 / 06839 = 8\n56984 / 07123 = 8\n58496 / 07312 = 8\n58912 / 07364 = 8\n59328 / 07416 = 8\n59368 / 07421 = 8\n63152 / 07894 = 8\n63528 / 07941 = 8\n65392 / 08174 = 8\n65432 / 08179 = 8\n67152 / 08394 = 8\n67352 / 08419 = 8\n67512 / 08439 = 8\n71456 / 08932 = 8\n71536 / 08942 = 8\n71624 / 08953 = 8\n71632 / 08954 = 8\n73248 / 09156 = 8\n73264 / 09158 = 8\n73456 / 09182 = 8\n74528 / 09316 = 8\n74568 / 09321 = 8\n74816 / 09352 = 8\n75328 / 09416 = 8\n75368 / 09421 = 8\n76184 / 09523 = 8\n76248 / 09531 = 8\n76328 / 09541 = 8\n83672 / 10459 = 8\n83752 / 10469 = 8\n84296 / 10537 = 8\n84632 / 10579 = 8\n84736 / 10592 = 8\n85392 / 10674 = 8\n85432 / 10679 = 8\n85936 / 10742 = 8\n86352 / 10794 = 8\n87456 / 10932 = 8\n87536 / 10942 = 8\n87624 / 10953 = 8\n87632 / 10954 = 8\n96584 / 12073 = 8\n98456 / 12307 = 8\n98760 / 12345 = 8\n",
"57429 / 06381 = 9\n58239 / 06471 = 9\n75249 / 08361 = 9\n95742 / 10638 = 9\n95823 / 10647 = 9\n97524 / 10836 = 9\n",
"There are no solutions for 10.\n",
"There are no solutions for 11.\n",
"45792 / 03816 = 12\n73548 / 06129 = 12\n89532 / 07461 = 12\n91584 / 07632 = 12\n",
"67392 / 05184 = 13\n81549 / 06273 = 13\n94653 / 07281 = 13\n",
"25746 / 01839 = 14\n27384 / 01956 = 14\n41538 / 02967 = 14\n46158 / 03297 = 14\n51492 / 03678 = 14\n54768 / 03912 = 14\n61572 / 04398 = 14\n65982 / 04713 = 14\n",
"27945 / 01863 = 15\n92745 / 06183 = 15\n",
"45936 / 02871 = 16\n73296 / 04581 = 16\n98352 / 06147 = 16\n",
"26843 / 01579 = 17\n28543 / 01679 = 17\n29546 / 01738 = 17\n36958 / 02174 = 17\n45713 / 02689 = 17\n45781 / 02693 = 17\n54689 / 03217 = 17\n59126 / 03478 = 17\n64957 / 03821 = 17\n65297 / 03841 = 17\n67184 / 03952 = 17\n67218 / 03954 = 17\n76823 / 04519 = 17\n76891 / 04523 = 17\n78132 / 04596 = 17\n78523 / 04619 = 17\n78591 / 04623 = 17\n81532 / 04796 = 17\n83572 / 04916 = 17\n83657 / 04921 = 17\n89437 / 05261 = 17\n89471 / 05263 = 17\n89641 / 05273 = 17\n91426 / 05378 = 17\n92837 / 05461 = 17\n92871 / 05463 = 17\n93126 / 05478 = 17\n",
"28674 / 01593 = 18\n",
"51984 / 02736 = 19\n81567 / 04293 = 19\n",
"There are no solutions for 20.\n",
"There are no solutions for 21.\n",
"51678 / 02349 = 22\n",
"36294 / 01578 = 23\n81627 / 03549 = 23\n81972 / 03564 = 23\n",
"39528 / 01647 = 24\n46872 / 01953 = 24\n",
"There are no solutions for 25.\n",
"42978 / 01653 = 26\n56498 / 02173 = 26\n61854 / 02379 = 26\n67314 / 02589 = 26\n67418 / 02593 = 26\n76518 / 02943 = 26\n82654 / 03179 = 26\n89726 / 03451 = 26\n92846 / 03571 = 26\n",
"39852 / 01476 = 27\n49572 / 01836 = 27\n69741 / 02583 = 27\n96714 / 03582 = 27\n",
"75348 / 02691 = 28\n",
"37584 / 01296 = 29\n73689 / 02541 = 29\n",
"There are no solutions for 30.\n",
"There are no solutions for 31.\n",
"75168 / 02349 = 32\n",
"There are no solutions for 33.\n",
"There are no solutions for 34.\n",
"48265 / 01379 = 35\n63945 / 01827 = 35\n64295 / 01837 = 35\n74865 / 02139 = 35\n93485 / 02671 = 35\n",
"There are no solutions for 36.\n",
"65934 / 01782 = 37\n",
"65892 / 01734 = 38\n74328 / 01956 = 38\n",
"There are no solutions for 39.\n",
"There are no solutions for 40.\n",
"There are no solutions for 41.\n",
"There are no solutions for 42.\n",
"93654 / 02178 = 43\n",
"58476 / 01329 = 44\n59268 / 01347 = 44\n67892 / 01543 = 44\n69432 / 01578 = 44\n95348 / 02167 = 44\n",
"There are no solutions for 45.\n",
"58374 / 01269 = 46\n",
"There are no solutions for 47.\n",
"There are no solutions for 48.\n",
"There are no solutions for 49.\n",
"There are no solutions for 50.\n",
"There are no solutions for 51.\n",
"95472 / 01836 = 52\n",
"65879 / 01243 = 53\n75896 / 01432 = 53\n84376 / 01592 = 53\n92538 / 01746 = 53\n",
"There are no solutions for 54.\n",
"There are no solutions for 55.\n",
"There are no solutions for 56.\n",
"There are no solutions for 57.\n",
"There are no solutions for 58.\n",
"73986 / 01254 = 59\n",
"There are no solutions for 60.\n",
"There are no solutions for 61.\n",
"79546 / 01283 = 62\n94736 / 01528 = 62\n",
"There are no solutions for 63.\n",
"There are no solutions for 64.\n",
"There are no solutions for 65.\n",
"83754 / 01269 = 66\n",
"There are no solutions for 67.\n",
"98736 / 01452 = 68\n",
"There are no solutions for 69.\n",
"There are no solutions for 70.\n",
"There are no solutions for 71.\n",
"There are no solutions for 72.\n",
"There are no solutions for 73.\n",
"There are no solutions for 74.\n",
"There are no solutions for 75.\n",
"There are no solutions for 76.\n",
"There are no solutions for 77.\n",
"There are no solutions for 78.\n",
"There are no solutions for 79.\n",
"There are no solutions for 80.\n"
};

    // int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // do {
    //     int numerator = 0;
    //     for (int i = 0; i < 5; i++) {
    //         numerator = numerator * 10 + arr[i];
    //     }
    //     num.PB(numerator);
    //     int denominator = 0;
    //     for (int i = 5; i < 10; i++) {
    //         denominator = denominator * 10 + arr[i];
    //     }
    //     denom.PB(denominator);
    // } while (next_permutation(arr, arr + 10));
    // int n;
    // int ctr = 0;
    // for (int n = 2; n <= 79; n++) {
    // // while (SCD(n), n != 0) {
    //     // if (ctr) {
    //     //     fprintf(stdout, "\n");
    //     //     fprintf(pFile, "\n");
    //     // }
    //     string s = "\"";
    //     bool found = false;
    //     for (int i = 0; i < num.size(); i++) {
    //         if (num[i] >= denom[i] && num[i] % denom[i] == 0) {
    //             if (num[i] / denom[i] == n) {
    //                 found = true;
    //                 char bla[100];
    //                 if (denom[i] < 10000) sprintf(bla, "%d / 0%d = %d\\n", num[i], denom[i], n);
    //                 else sprintf(bla, "%d / %d = %d\\n", num[i], denom[i], n);
    //                 s += string(bla);
    //             }
    //         }
    //     }
    //     if (!found) {
    //         char bla[100];
    //         sprintf(bla, "There are no solutions for %d.\\n", n);
    //         s += string(bla);
    //     }
    //     ctr++;
    //     s += "\",";
    //     fprintf(pFile, "%s\n", s.c_str());
    // }
    int n;
    int ctr = 0;
    while (SCD(n), n != 0) {
        if (ctr) {
            fprintf(stdout, "\n");
            fprintf(pFile, "\n");
        }
        fprintf(stdout, "%s", ans[n].c_str());
        fprintf(pFile, "%s", ans[n].c_str());
        ctr++;
    }
	fclose(pFile);
	return 0;
}