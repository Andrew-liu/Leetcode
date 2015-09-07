#include <iostream>
#include <string>
using namespace std;

char* formatString(char *sourceString) {
    char* pstr = sourceString;
    char* pnew = sourceString;
    while(*pstr == ' ') {
        pstr++;
    }
    while(*pstr != '\0') {
        *pnew = *pstr;
        pnew++;
        pstr++;
    }
    pstr--;
    while(*pstr == ' ') {
        pstr--;
    }
    *(++pstr) = '\0';
    return sourceString;
}

void RemoveSpaces(char* source)
{
  char* i = source;
  char* j = source;
  while(*j != 0)
  {
    *i = *j++;
    if(*i != ' ')
      i++;
  }
  *i = 0;
}

int main() {
    cout << "Hello, World!" << endl;
    char str[100] = "  i love andrew   ";
    printf("%s\n", str);
    char* new_str = formatString(str);
    cout << new_str << endl;
    return 0;
}
