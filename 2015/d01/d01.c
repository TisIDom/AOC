#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* input_file;
    char curr_char;
    int height = 0;

    input_file = fopen("d01input.txt", "r");
    if(input_file == NULL)
    {
        printf("Error opening file..");
        return 1;
    }

    while((curr_char = fgetc(input_file)) != EOF)
    {
        if(curr_char == '(') height++;
        else if(curr_char == ')') height--;
        else{
            printf("Err, found %c", curr_char);
            return 1;
        }
    }

    printf("%d", height);

    fclose(input_file);

    return 0;
}
