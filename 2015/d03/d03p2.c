#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int x,y;
    int count;
    struct Node* next;
};

//not a great solution O(n^2), but can't think of anything else
int main()
{
    FILE* input_file;
    int house_count = 0;
    char current_char;
    int curr_x_s = 0; //santa
    int curr_y_s = 0;
    int curr_x_r = 0; //robo-santa
    int curr_y_r = 0;
    struct Node* head = malloc(sizeof(struct Node));
    struct Node* tail;
    int char_counter = 0; // % 2 == 1 -- santa; % 2 == 0 -- robo-santa

    head->next = malloc(sizeof(struct Node));
    tail = head->next;
    tail->next = NULL;
    tail->x = 0;
    tail->y = 0;
    house_count = 1; //include the starting house

    input_file = fopen("d03input.txt", "r");

    while((current_char = fgetc(input_file)) != EOF)
    {
        int curr_x = 0;
        int curr_y = 0;
        
        char_counter++;
        if(char_counter % 2 == 1)
        {
            curr_x = curr_x_s;
            curr_y = curr_y_s;
        }
        else
        {
            curr_x = curr_x_r;
            curr_y = curr_y_r; 
        }
        
        if(current_char == '^') curr_y++;
        else if(current_char == 'v') curr_y--;
        else if(current_char == '>') curr_x++;
        else if(current_char == '<') curr_x--;

        if(char_counter % 2 == 1)
        {
            curr_x_s = curr_x;
            curr_y_s = curr_y;
        }
        else
        {
            curr_x_r = curr_x;
            curr_y_r = curr_y;
        }

        struct Node* curr_node = head->next;
        _Bool isFound = 0;
        while(curr_node != NULL){
            if(curr_node->x == curr_x && curr_node->y == curr_y)
            {
                curr_node->count++;
                isFound = 1;
                break;
            }
            curr_node = curr_node->next;
        }
        if(isFound) continue;
        tail->next = malloc(sizeof(struct Node));
        tail = tail->next;
        tail->next = NULL;
        tail->x = curr_x;
        tail->y = curr_y;
        house_count++;
    }

    printf("%d", house_count);

    fclose(input_file);
    return 0;
}

