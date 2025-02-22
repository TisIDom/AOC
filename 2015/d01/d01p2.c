#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* input_file;
    char curr_char;
    int height = 0;
    int pos = 0;

    input_file = fopen("d01input.txt", "r");
    if(input_file == NULL)
    {
        printf("Error opening file..");
        return 1;
    }

    while((curr_char = fgetc(input_file)) != EOF)
    {
        pos += 1;
        if(curr_char == '(')
        {
            height += 1;
        }
        else if(curr_char == ')')
        {
            height -= 1;
            if(height == -1)
            {
                break;
            }
        }
        else{
            printf("Err, found %c", curr_char);
            return 1;
        }
    }

    printf("%d", pos);

    fclose(input_file);

    return 0;
}
