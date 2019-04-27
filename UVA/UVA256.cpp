#include<bits/stdc++.h>

using namespace std;

int orig[] = {0, 1, 2, 3, 4, 5};
int up[] = {1, 5, 2, 3, 0, 4};
int ri[] = {0, 2, 4, 1, 3, 5};
int cr[] = {3, 1, 0, 5, 4, 2};
int
main() {
	string line;
	FILE *pFile = fopen("out.txt", "w");
	while (cin >> line) {
		string orig = line.substr(0, 6);
		string quer = line.substr(6, 6);
		// horizontal
		string rotated = orig;
		bool ans = false;
		for (int i = 0; i < 4 && !ans; i++) {
			// vertical
//			printf("Rotating the cube horizontally for the %d-th time\n", i + 1);
			string temp = rotated;
//			printf("Before rotating:\n%s\n", temp.c_str());
//			printf("After rotating:\n");
			bool similar = true;
			for (int j = 0; j < 6; j++) {
				rotated[j] = temp[ri[j]];
//				printf("%c ", rotated[j]);
				if (rotated[j] != quer[j]) similar = false;
			}
//			printf("\n");
			if (similar) ans = true;
			for (int j = 0; j < 4; j++) {
//				printf("Rotating the cube vertically for the %d-th time\n", j + 1);
				temp = rotated;
//				printf("Before rotating:\n%s\n", temp.c_str());
//				printf("After rotating:\n");
				similar = true;
				for (int k = 0; k < 6; k++) {
					rotated[k] = temp[up[k]];
//					printf("%c ", rotated[k]);
					if (rotated[k] != quer[k]) similar = false;

				}
				if (similar) ans = true;
				for (int k = 0; k < 4; k++) {
					temp = rotated;
					similar = true;
					for (int l = 0; l < 6; l++) {
						rotated[l] = temp[cr[l]];
						if (rotated[l] != quer[l]) similar = false;
					}
					if (similar) ans = true;
				}
			}
		}
		printf("%s\n", ans ? "TRUE" : "FALSE");
		fprintf(pFile, "%s\n", ans ? "TRUE" : "FALSE");
	}		
	fclose(pFile);
	return 0;
}
