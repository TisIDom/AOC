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
    char curr_char;
    int curr_x_s = 0; //santa
    int curr_y_s = 0;
    int curr_x_r = 0; //robo-santa
    int curr_y_r = 0;
    int char_counter = 0; // % 2 == 0 --> robo-santa; % 2 == 1 --> santa; 

    struct Node* head = malloc(sizeof(struct Node));
    struct Node* new_node = malloc(sizeof(struct Node)); //node for the starting house
    new_node->x = 0;
    new_node->y = 0;
    new_node->count = 1;
    new_node->next = NULL;
    head->next = new_node;
    struct Node* tail = new_node;

    house_count++; //include the starting house

    input_file = fopen("d03input.txt", "r");

    while((curr_char = fgetc(input_file)) != EOF)
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
        
        if(curr_char == '^') curr_y++;
        else if(curr_char == 'v') curr_y--;
        else if(curr_char == '>') curr_x++;
        else if(curr_char == '<') curr_x--;

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
        _Bool is_found = 0;
        
        while(curr_node != NULL){
            if(curr_node->x == curr_x && curr_node->y == curr_y)
            {
                curr_node->count++;
                is_found = 1;
                break;
            }
            curr_node = curr_node->next;
        }

        if(is_found) continue;

        struct Node* new_node = malloc(sizeof(struct Node));
        new_node->x = curr_x;
        new_node->y = curr_y;
        new_node->count = 1;
        new_node->next = NULL;
        tail->next = new_node;
        tail = tail->next;

        house_count++; //include the new house (at the new_node position)
    }

    printf("%d", house_count);

    fclose(input_file);
    return 0;
}

