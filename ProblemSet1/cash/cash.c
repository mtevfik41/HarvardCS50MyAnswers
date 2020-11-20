#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
    //variables
    
    float giris; //input
    
    int quarter = 25; // quarter value 
    int quartercounter; // counter for how many need quarter
    int dime = 10; // dime value
    int dimecounter; // counter for how many need dime
    int nickel = 5; // nickel value
    int nickelcounter; // counter for how many need nickel
    int penny = 1; // penny value
    int pennycounter; // counter for how many need penny
    
    int total; // counter for total coins
    
    do
    {
        giris = get_float("Change Owed: ");
    }
    while (giris < 0);
    
    //converter from dollars to cents
    
    int cents = round(giris * 100);
    
    
    //total divided by coin
    
    quartercounter = floor(cents / quarter);
    
    //turn remainder into the new total
    
    cents = cents % quarter;
    
    //total divided by coin
    
    dimecounter = floor(cents / dime);
    
    //turn remainder into the new total
    
    cents = cents % dime;
    
    //total divided by coin
    
    nickelcounter = floor(cents / nickel);
    
    //turn remainder into the new total
    
    cents = cents % nickel;
    
    //new total
    pennycounter = cents;
    
    // total coins
    total = quartercounter + dimecounter + nickelcounter + pennycounter;
    
    // printing total coins
    printf("%i\n", total);
    
}