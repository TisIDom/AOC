#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

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
                /*!l checks if it's 0*/
                if(!l) l = val;
                else if(!w) w = val;
                else h = val;
            }
            else str++;
        }
        int side1 = l*w;
        int side2 = l*h;
        int side3 = w*h;
        int total_area = 2 * side1 + 2 * side2 + 2 * side3;
        ans += total_area;
        ans += fmin(side1, fmin(side2,side3));
    }

    printf("%d", ans);

    fclose(input_file);

    return 0;
}
