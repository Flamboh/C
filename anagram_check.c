#include<stdio.h>
#include<string.h>
int main() {
 int counter1[] = {0,0,0,0};
 int counter2[] = {0,0,0,0};

 char s1[] = "dcba";
 char s2[] = "abcd";

  for(int i = 0; i < strlen(s1); i++) {
    switch(s1[i]) {
      case 'a':
        ++counter1[0];
        break;
      case 'b':
        ++counter1[1];
        break;
      case 'c':
        ++counter1[2];
        break;
      case 'd':
        ++counter1[3];
        break;
    }
  }
  for(int j = 0; j < strlen(s2); j++) {
    switch(s2[j]) {
      case 'a':
        ++counter2[0];
        break;
      case 'b':
        ++counter2[1];
        break;
      case 'c':
        ++counter2[2];
        break;
      case 'd':
        ++counter2[3];
        break;
    }
  }

  int flag = 0;
  for(int k = 0; k < 4; k++) {
    if(counter1[k] != counter2[k])
      flag = 1;
  }
  if(flag != 1)
    printf("Anagram");
  else
    printf("Not Anagram");
}