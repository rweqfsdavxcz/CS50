#include <cs50.h>
#include <stdio.h>

int main(void)
{
    
    //Let's get some CardNumbers
    long CardNumber = get_long("Number: ");
    
    //determines length of CardNumber
    int size = 0;
    long OCN1 = CardNumber;
    while (OCN1 > 0)
    {
        OCN1 = OCN1 / 10;
        size = size + 1;
    }
    
   //initialize zero array of length "size" 
    int CNarray[size];
    for (int i = 0; i < size; i++)
    {
        CNarray[i] = 0;
    }
    
    //stores each element of CardNumber in array for mathematical access
    long OCN2 = CardNumber;
    for (int i = 1; i < size+1; i++)
    {
        CNarray[size-i] = OCN2 % 10;
        OCN2 = OCN2 / 10;
    }
    
    //Luhn's Algorithm
    int EvenElements[size]; 
    int OddElements[size];
    for (int i = 0; i < size; i++)
    {
        EvenElements[i] = CNarray[i];
        OddElements[i] = CNarray[i];
    }
    for (int i = 1; i < size; i = i + 2)
    {
        EvenElements[i] = 0;
    }
    for (int i = 0; i < size; i = i + 2)
    {
        OddElements[i] = 0;
    }
    
    //if length is even
    if (size % 2 == 0)
    {
        
        for (int i = 0; i < size; i++)
        {
            EvenElements[i] = EvenElements[i]*2;
        }
        int sum = 0;
        for (int i = 0; i < size; i++)
        {
            if (EvenElements[i] / 10 < 1)
            {
                sum = sum + EvenElements[i];
            }
            else
            {
                int d1 = EvenElements[i] % 10;
                EvenElements[i] = EvenElements[i] / 10;
                int d2 = EvenElements[i] % 10;
                sum = sum + d1 + d2;
            }
            sum = sum + OddElements[i];
        }
       //must be divisible by 10
        if (sum % 10 == 0)
        {
            //all even numbered cards have 16 digits
            if (size == 16)
            {
                // Master cards begin with 51, 52, 53, 54, 55
                if (CNarray[0]==5)
                {
                    if (CNarray[1]==1 || CNarray[1]==2 || CNarray[1]==3 || CNarray[1]==4 || CNarray[1]==5)
                    {
                        printf("Master Card\n");
                    }
                }
                //Visa cards begin with 4
                if (CNarray[0]==4)
                {
                    printf("Visa\n");
                }
            }
            else
            {
                printf("Invalid\n");
            }
        }
        else
        {
            printf("Invalid\n");    
        }   
    }
    //if length is odd
    else
    {
        for (int i = 0; i < size; i++)
        {
            OddElements[i] = OddElements[i]*2;
        }
        int sum = 0;
        for (int i = 0; i < size; i++)
        {
            if (OddElements[i] / 10 < 1)
            {
                sum = sum + OddElements[i];
            }
            else
            {
                int d1 = OddElements[i] % 10;
                OddElements[i] = OddElements[i] / 10;
                int d2 = OddElements[i] % 10;
                sum = sum + d1 + d2;
            }
            sum = sum + EvenElements[i];
        }
        //must be divisible by 10
        if (sum % 10 == 0)
        {
            // American Express cards have 15 digits and begin with 34, 37
            if ((size == 15 && CNarray[0] == 3 && CNarray[1] == 4) ||
                (size == 15 && CNarray[0] == 3 && CNarray[1] == 7))
            {
                printf("American Express\n");
            }
            //Visa cards can have 13 digits and begin with 4
            else if (size == 13 && CNarray[0] == 4)
            {
                printf("Visa\n");
            }
            else
            {
                printf("Invalid\n");
            }
        }
        else
        {
            printf("Invalid\n");
        }
    }
}

