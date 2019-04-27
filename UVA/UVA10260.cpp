#include<bits/stdc++.h>

using namespace std;

int
main() {
	FILE * pFile = fopen("out.txt", "w");
	string input;
	while (cin >> input) {
		string output = "";
		for (int i = 0; i < input.length(); i++) {
			char ch = input[i];
			if (i == 0) {
				switch (ch) {
					case 'B':
					case 'F':
					case 'P':
					case 'V':
							output += "1";
						
						break;
					case 'C':
					case 'G':
					case 'J':
					case 'K':
					case 'Q':
					case 'S':
					case 'X':
					case 'Z':
								output += "2";
						break;
					case 'D':
					case 'T':
								output += "3";
						break;
						
					case 'L':
								output += "4";
						
						break;
					case 'M':
					case 'N':
								output += "5";
						
						break;
					case 'R':
								output += "6";
						break;
					default:
						output += " ";
				}
			
			}
			else {
				switch (ch) {
					case 'B':
					case 'F':
					case 'P':
					case 'V':
						if (output[output.length() - 1] != '1')
							output += "1";
						
						break;
					case 'C':
					case 'G':
					case 'J':
					case 'K':
					case 'Q':
					case 'S':
					case 'X':
					case 'Z':
						if (output[output.length() - 1] != '2')
								output += "2";
						break;
					case 'D':
					case 'T':
						if (output[output.length() - 1] != '3')
								output += "3";
						break;
						
					case 'L':
						if (output[output.length() - 1] != '4')
								output += "4";
						
						break;
					case 'M':
					case 'N':
						if (output[output.length() - 1] != '5')
								output += "5";
						break;
					case 'R':
						if (output[output.length() - 1] != '6')
								output += "6";
						break;
					default:
						output += " ";
				}
			}
		}
		for (int i = 0; i < output.length(); i++) {
			if (output[i] != ' ') {
				printf("%c", output[i]);
				fprintf(pFile, "%c", output[i]);
			}
		}
		printf("\n");
		fprintf(pFile, "\n");			
	}
	fclose(pFile);
	return 0;
}
