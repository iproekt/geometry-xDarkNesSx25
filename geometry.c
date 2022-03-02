#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 100

int fileCheck()
{
    int lines = 0;
    FILE* file = fopen("input.txt", "r");
    if(file == NULL) //проверка на существование файла
    {
        printf("Input file does not exist!\n");
        return 0;
    }

    while(!feof(file)) //подсчёт кол-ва строк
    {
        if(fgetc(file) == '\n')
        {
            lines++;
        }
    }
    fclose(file);
    return lines;
}

int isCorrect()
{
    char circleStr[] = "circle";
    char triangleStr[] = "triangle";
    // char polygonStr[] = "polygon"; // it's so hard

    FILE* file = fopen("input.txt", "r");
    char *figure;
    char str[SIZE];
    fgets(str, SIZE, file);

    figure = strtok(str, "(");
    if(strcmp(figure, circleStr) == 0)
    {   
        printf("Figure - ");
        puts(figure);
    }
    else if(strcmp(figure, triangleStr) == 0)
    {
        printf("Figure - ");
        puts(figure);
    }
    else
    {
        printf("Figure undefined\nExpected: 'circle' or 'triangle'\n");
    }
    
    return 0;
}

int main()
{
    char str[SIZE];
    int lines = fileCheck();

    FILE* file = fopen("input.txt", "r");
    for(int line = 0; line < lines; line++)
    {
        fgets(str, SIZE, file);
        str[strlen(str) - 1] = '\0';
        
    }
    isCorrect();

    fclose(file);

    return 0;
}