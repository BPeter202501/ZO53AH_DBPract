#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {

    char fajlnev[100];
    char sor[200];
    FILE *fp;
    int c;

    printf("Add meg a fajl nevet: ");
    fgets(fajlnev, 100, stdin);

    fajlnev[strcspn(fajlnev, "\n")] = 0;

    fp = fopen(fajlnev, "w");

    printf("Add meg a szoveget (# jelig):\n");

    while(1)
    {
        fgets(sor, 200, stdin);

        if(sor[0] == '#')
            break;

        fputs(sor, fp);
    }

    fclose(fp);

    fp = fopen(fajlnev, "r");

    printf("\nA fajl tartalma nagybetusen:\n");

    while((c = fgetc(fp)) != EOF)
    {
        putchar(toupper(c));
    }

    fclose(fp);

    return 0;
}