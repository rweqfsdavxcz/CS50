#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //ask user for the height of the pyramid
    int height = get_int("Height: ");
    
    //continue to request correct input if outside assignment's limitations
    while (height < 1 || height > 8)
    {
        height = get_int("Please choose a height between 1 and 8: ");
    }

    //loop through height times
    for (int i = 0; i < height; i++)
    {
        //beginning spaces to offset left side
        for (int k = 0; k < height - i + 1; k++)
        {
            printf(" ");
        }
        
        //left wall
        for (int j = 0; j < i+1; j++)
        {
            printf("#");
        }

        //space
        printf(" ");
        
        
        //right wall
        for (int j = 0; j < i+1; j++)
        {
            printf("#");
        }
        
        //newline
        printf("\n");
    }
}
