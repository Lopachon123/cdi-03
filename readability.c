#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 4096

int read_file(char* text, char* filename);

int main(int argc, char* argv[]) {

    if (argc != 2) {
        printf("Uso: ./readability file\n");
        return 1;
    }

    char text[MAX];

    if (read_file(text, argv[1])) {
        printf("Archivo no encontrado\n");
        return 1;
    }

    int i = 0;
    float oraciones = 0;
    float palabras = 1;
    float letras = 0;

    while (text[i] != '\0') {

        if (text[i] == '.') {
            oraciones++;
        }

        if (text[i] == ' ') {
            palabras++;
        }

        if (isalpha(text[i])) {
            letras++;
        }
        i++;
    }


    palabras = letras * 100 / palabras;
    oraciones = oraciones * 100 / palabras;

    float grades = 0.0588 * letras - 0.296 * oraciones - 15.8;

    if (grades > 16) {
        printf(" Grade 16+\n");
    }
    else if (grades < 1) {
        printf("Below Grade 1\n");
    }
    else {
        printf("Grade %d\n", (int)grades);
    }

    return 0;
}



int read_file(char* text, char* filename) {

    FILE* fp;
    char c;
    char full_name[30];

    sprintf(full_name, "texts/%s.txt", filename);
    fp = fopen(full_name, "r");

    if (!fp) {
        return 1;
    }

    do {
        c = getc(fp);
        *text = c;
        text++;
    } while (c != EOF);

    text--;
    *text = '\0';


    return 0;
}


v
