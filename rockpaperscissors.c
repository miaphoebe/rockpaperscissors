/* Homework 2: rockpaperscissors.c
 * Author: Mia Hoffmann Kamrat
 * A game of rock, paper, scissors. */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){ 
  srand((unsigned) time(NULL));
  int rounds, player_num, comp_num;
  int player_wins = 0, comp_wins = 0;

  // Determines the number of rounds based on user input
  do{
    printf("Enter the number of rounds to play: ");
    scanf("%d", &rounds);

    if(rounds <= 0){
      printf("Invalid number of rounds. Please enter a positive number.\n");
    }
  } while (rounds <= 0);

  // Carries out the rounds requested by the user
  for(int i = 1; i <= rounds; i++){
    // Prints the current score and prompts the user for their choice of
    // rock, paper, or scissors
    printf("Current Score \n");
    printf("Player: %d\nComputer: %d\n\n", player_wins, comp_wins);
    printf("Round %d\n", i);
    printf("Rock = 1, Paper = 2, Scissors = 3\n");
    printf("Enter your choice as an integer (1, 2, or 3): ");
    scanf("%d", &player_num);

    while((player_num < 1) || (player_num > 3)) {
      printf("Invalid choice. Enter an integer between 1 and 3: ");
      scanf("%d", &player_num);
    }
    // Determines the computers choice by randomly selecting an integer
    // between 1-3
    comp_num = (rand()%3)+1;

    // Prints the results of the round
    switch(player_num){
    case 1:
      printf("Rock vs. ");
      break;
    case 2:
      printf("Paper vs. ");
      break;
    case 3:
      printf("Scissors vs. ");
      break;
    }

    switch(comp_num){
    case 1:
      printf("Rock...\n");
      break;
    case 2:
      printf("Paper...\n");
      break;
    case 3:
      printf("Scissors...\n");
      break;
    }
    // Determines the winner of the round
    if(player_num == comp_num)
      printf("It's a tie!\n");
    else if((player_num==1 && comp_num==3) ||
            (player_num==2 && comp_num==1) ||
            (player_num==3 && comp_num==2)){
      printf("You win!\n");
      player_wins++;
    } else {
      printf("Computer wins.\n");
      comp_wins++;
    }
    // Prompts the user to press enter to continue to the next round
    printf("Press enter to continue");
    getchar();
    getchar();
    printf("\n");
  }
  
  // Prints the final score
  printf("Final Score: %d to %d\n", player_wins, comp_wins);
  if(player_wins > comp_wins)
    printf("You Won!!\n");
  else if(comp_wins > player_wins)
    printf("Computer won. Better luck next time!\n");
  else
    printf("It's a tied game!\n");
    
  return 0;
  
}
