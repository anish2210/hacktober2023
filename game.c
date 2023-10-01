//simple game in c
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int number,nguess,guess;
    srand(time(0));
    number=rand()%100+1;
    printf("\n WELCOME TO THE NUMBER GUESSING GAME");
    printf("\n Lets start the game");
    nguess=1;
    do
    {
        printf("\n Guess an number between 1 to 100:");
        scanf("%d",&guess);
        if (guess<number)

        {
        printf("\n You have guessed the number lower ..Try again");
        }
        else if (guess>number)
        {
           printf("\n You have guessed the number higher ..Try again");
        }
        else{
            printf("\n Congratulations..You have guessed the right number in %d attempts",nguess);

        }
        nguess++;
        
        

    } while (guess!=number);
    printf("\n Thanks for playing the game");
    return 0;
  
}