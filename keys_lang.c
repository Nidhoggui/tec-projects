#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int even_or_odd(char *string)
{
    return (strlen(string) % 2 == 0) ? 1 : 0;
}

int counter(char *string)
{
    if (even_or_odd(string) == 0) return -1;

    int i;
    int counter = 0;

    for (i = 0; string[i] != '\0'; i++)
    {
        if(string[i] == '{') counter++;
        else if(string[i] == '}') counter -= 1;
        else return -1;
    }

    return counter;
}

int main() 
{    
    char input[MAX_LEN];

    printf("Input: \n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    int key = counter(input);

    //printf("%d\n", key);

    if (key == 0) printf("The string '%s' was recognized by the automaton\n", input);
    else printf("The string '%s' wasn't recognized by the automaton\n", input);

    return 0;
}