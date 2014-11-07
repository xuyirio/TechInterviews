#include <string.h>
#include <iostream>

bool DigitIncrement(char* c) {
  if (*c == '9') {
    *c = '0';
    return true;
  } else {
    *c = *c + 1;
    return false;
  }
}

void f(char input[], char result[]) {
  int l = strlen(input);
  bool next = true;
  for (int i = l - 1; i >= 0 && next; i--) {
    next = DigitIncrement(&input[i]);
  }

  int i = 0, j = 0;
  if (next) {
    result[0] = '1';
    i = 1;
  }
  for (; j < l; i++, j++) {
    result[i] = input[j];
  }
}

int main(int argc, char** argv) {
  InitGoogle(argv[0], &argc, &argv, true);

  char input[] = "99";
  char result[10];
  f(input, result);

  for (int i = 0; i < strlen(result); i++) {
    cout << result[i];
  }
  cout << endl;
}