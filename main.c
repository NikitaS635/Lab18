#include <stdio.h>
#include "C:\Users\User2\CLionProjects\untitled\libs\data_structures\string\string_.h"
#include <windows.h>
#include <assert.h>
#include <stdlib.h>
void test1()
{
    char S[] = "ten tenet";
    removePalindromes(S);
    removeNonLetters(S);
    assert(strcmp(S, "ten") == 0 );
    printf("тест пройден");
}
int main() {
    SetConsoleOutputCP(CP_UTF8);
    test1();
    return 0;
}


