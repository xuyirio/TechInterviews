// Given a string, find the longest substring that contains at most
// 2 distinct characters.
// Example: "ababcbcbaaabbdef" 
// has a 2-character substring "baaabb" of length 6 (longest) 
// and a 2-character substring "bcbcb" of lenght 5 (second longest)

#include <stdio.h>$
#include <string>

bool f(char input[], char result[]) {
	int l = strlen(input);
	if (l < 2) return false;

	int sp1 = 0, sp2 = 1;
	while (sp2 < l && input[sp2] == input[sp1]) sp2++;
	if (sp2 == l) {  // only 1 char
		return false;
	}

	char c1, c2;
	int ap1;
	int sl = 1;

	whiel (sp1 < l) {
		c1 = input[sp1];
		c2 = input[sp2++];
		while ((sp2 < l) && (input[sp2] == c1 || input[sp2] == c2)) sp2++;
		if ((sp2 - sp1) > sl) {
			ap1 = sp1;
			sl = sp2 - sp1;
		}
		if (sp2 == l) break;

		sp1 = sp2 - 1;
	}

	int i;
	for (i = 0; i < sl; i++) {
		result[i] = input[ap1 + i];
	}
	result[i] = '\0';

	return true;
}

int main(int argc, char** argv) {
  char input[] = "ababcbcbaaabbdef";
  char result[20];

  if (f(input, result)) {
  	for (int i = 0; i < strlen(result); i++) {
    	cout << result[i];
  	}
  	cout << endl;
  } else {
  	cout << "Invalid input" << endl;
  }
}
