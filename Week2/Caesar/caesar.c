#include <cs50.h>
#include <stdio.h>
#include <string.h>
// Access to atoi() function which changes string 1 to int 1.
// Casting did not work here for me.
#include <stdlib.h>

int main(int argc, string argv[])
{
    //check to see if too many/few arguments were used
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        exit(0);
    }
    //using new command to convert an entire string to an int
    int key = atoi(argv[1]);
    
    //checks to see if non-numbers were used (key == 0 if there were)
    if (key == 0)
    {
        printf("Usage: ./caesar key\n");
        exit(0);
    }
    //enter phrase to apply cipher
    string ptext_string = get_string("Plain text:  ");
    int size = strlen(ptext_string);
    
    //convert to array
    int ptext_array[size];
    
    //initialize cipher string and int arrays
    int ctext_array[size];
    char ctext_string[size];
    
    //important ascii characters for toroidal boundaries
    int ascii_Z = (int) 'Z';
    int ascii_a = (int) 'a';
    int ascii_z = (int) 'z';

    //convert to array of numbers
    for (int i = 0; i < size; i++)
    {
        ptext_array[i] = (int) ptext_string[i];
        //to be edited soon
        ctext_array[i] = (int) ptext_string[i];
    }
    
    //applies cipher shift
    for (int i = 0; i < size; i++)
    {
        if (ptext_array[i] > 64)
        {
            ctext_array[i] = ptext_array[i] + key;    
        }
        
        //subtract 26 from ascii number if shift overshoots the correct part of the alphabet
        //(fake modulo operator)
        if ((ctext_array[i] > ascii_Z && ctext_array[i] < ascii_a) ||
             ctext_array[i] > ascii_z)
        {
            ctext_array[i] = ctext_array[i]-26;
        }
    }
    
    //convert ascii ints to chars
    for (int i = 0; i < size; i++)
    {
        ctext_string[i] = (char) ctext_array[i];
    }
    
    //print cipher text
    printf("Cipher text: ");
    for (int i = 0; i < size; i++)
    {
        printf("%c",ctext_string[i]);
    }
    printf("\n");
}
