#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    FILE* input_file;
    char *str = (char *)malloc(80*sizeof(char));
    int ans = 0;

    input_file = fopen("d02input.txt", "r");
    if(input_file == NULL)
    {
        printf("Error opening file..");
        return 1;
    }
    
    while(fgets(str,80,input_file) != NULL)
    {
        int l = 0;
        int w = 0;
        int h = 0;

        while(*str)
        {
            if(isdigit(*str))
            {
                int val = (int)strtol(str,&str,10);
                if(l == 0)
                {
                    l = val;
                    continue;
                }
                else if(w == 0)
                {
                    w = val;
                    continue;
                }
                else
                {
                    h = val;
                    continue;
                }
            }
            else
            {
                str++;
            }
        }

        int ribbon_length = l * w * h;
        int smallest = 0;
        int second_smallest = 0;
        if(l <= w && l <= h)
        {
            smallest = l;
            second_smallest = (w <= h) ? w : h;
        }
        else if(w <= l && w <= h)
        {
            smallest = w;
            second_smallest = (l <= h) ? l : h;
        }
        else
        {
            smallest = h;
            second_smallest = (l <= w) ? l : w;
        }

        ribbon_length += (2 * smallest + 2 * second_smallest);

        ans += ribbon_length;
    }

    printf("%d", ans);

    fclose(input_file);

    return 0;
}
