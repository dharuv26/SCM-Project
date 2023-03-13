#include <stdio.h>
#include <stdlib.h>
#include <time.h> //for random number generator

int main()
{
    int randomNumber =0;
    int guess =0;
    int numberOfGuesses=5;
    time_t t;

    //Initialization of random number generator
    srand((unsigned) time(&t));

    //get the random number
    randomNumber=rand()%21;

    printf("\nThis is a number guessing game.");
    printf("\nI have chosen a number between 0 and 20, which you must guess. \n");
    printf("You have 5 tries to guess the number correctly");

    for(numberOfGuesses=5;numberOfGuesses>0;--numberOfGuesses)
    {
         printf("\nYou have %d tr%s left.",numberOfGuesses, numberOfGuesses==1?"y":"ies");//ternary operator
         printf("\nEnter a guess: ");
         scanf("%d", &guess);

         if (guess==randomNumber)
         {
             printf("\nCongratulations. You guessed it!\n");
             return 0;
         }
         else if (guess<0 || guess>20) //checking for invalid guess
            printf("Enter a valid number between 0 and 20\n");
         else if (randomNumber>guess)
            printf("Sorry, %d is wrong. My number is greater than that.\n", guess);
         else if (randomNumber<guess)
            printf("Sorry, %d is wrong. My number is less than that.\n", guess);
    }
    printf("You failed. The number was %d", randomNumber);
    return 0;
}
