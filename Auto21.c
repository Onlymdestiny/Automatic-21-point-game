/*****+**-*-***----**--*-***--**----********--******************************
*
*  Lab #: 7
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Program Description: This program auto plays the game 21 points and determine the result of the game base on card drawed 
*
******+**-*-***----**--*-***--**----********--*****************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int draw_card(int*, int*, int, int*, int*, int*);
void printline(int, int, int, int, int); 
void input(void);
int check_drawmore(int, int);
void result(int);

int main(void)
{   
  int total_score; // total scores of dealer
  int amo_card; // amount of cards drawed
  int num_ace; // number of aces count as 11
  int s_suit; // string/name of the suit of the card
  int s_num; // string/name of the number of the card
  int current_card; // current card number

  amo_card = 0;
  num_ace = 0;
  total_score = 0;
  input();
  if(check_drawmore(total_score, amo_card) == 1) //check if need draw 1st card
  {
    total_score += draw_card(&s_suit, &s_num, total_score, &amo_card, &current_card, &num_ace);
    printline(s_suit, s_num, total_score, amo_card, current_card);
  }
  if(check_drawmore(total_score, amo_card) == 1) //check if need draw 2nd card
  {
    total_score += draw_card(&s_suit, &s_num, total_score, &amo_card, &current_card, &num_ace);
    printline(s_suit, s_num, total_score, amo_card, current_card);
  }
  if(check_drawmore(total_score, amo_card) == 1) //check if need draw 3rd card
  {
    total_score += draw_card(&s_suit, &s_num, total_score, &amo_card, &current_card, &num_ace);
    printline(s_suit, s_num, total_score, amo_card, current_card);
  } 
  if(check_drawmore(total_score, amo_card) == 1) //check if need draw 4th card
  {
    total_score += draw_card(&s_suit, &s_num, total_score, &amo_card, &current_card, &num_ace);
    printline(s_suit, s_num, total_score, amo_card, current_card);
  }
  if(check_drawmore(total_score, amo_card) == 1) //check if need draw 5th card
  {
    total_score += draw_card(&s_suit, &s_num, total_score, &amo_card, &current_card, &num_ace);
    printline(s_suit, s_num, total_score, amo_card, current_card);
  }
  result(total_score);

  return 0;
}

/*****+*--*-***----**--***-**--**-*-********--******************************
*
*  Function Information
*
*  Name of Function: check_drawmore
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int score - the current score of hand
*    2. int cards - the amount of cards have drawed
*
*  Function Description: This function checks if the dealer will draw another card
*
******+*--*-***----**--***-**--**-*-********--*****************************/

int check_drawmore(int score, int cards)
{
  int dm_msg; // message of whether its valid to draw another chec
  
  dm_msg = 1;
  dm_msg = score >= 16 ? 0 : dm_msg;
  dm_msg = cards >= 5 ? 0 : dm_msg;

  return dm_msg;
}

/*****+*--*-***----**--***-**--**-*-********--******************************
*
*  Function Information
*
*  Name of Function: draw_card
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int *s_suits - pointer of the suit of current card
*    2. int *s_nums - pointer of the number of current card
*    3. int t_score - the total score of current cards in hand
*    4. int *amo_card - pointer of the amount of card in hand
*    5. int *current_card - current card #
*    6. int *num_ace - the number of aces in hand
*
*  Function Description: This function draws a card and finds the suit and number of it. Then determine the score of it. (score mainly variates on Ace, Jack, Queen King and also the varies on the amount of Aces in hand)
*
******+*--*-***----**--***-**--**-*-********--*****************************/

int draw_card(int *s_suit, int *s_nums, int t_score, int *amo_card, int *current_card, int *num_ace)
{
  int card; // current card #
  int suit; // current card suit
  int num; // current card num
  int score; // score of current card

  card = abs(rand()) % 52; 
  *current_card = card + 1;
  suit = card / 13; // get the suit of the card 
  num = card % 13; // get the num of card
  *s_suit = suit;
  *s_nums = num; 
  if(num > 9) // if card is Jack, Queen, or King
  {
    score = 10;
  }
  else if(num == 0) // the Ace value varies
  {
    score = (t_score <= 10) ? 11 : 1;
  }
  else
  {
    score = num + 1;
  }
  if (score == 11) // if drawed ace, then number of Ace add 1 
  {
    *num_ace = *num_ace + 1;
  }
  if (*num_ace > 0 && (t_score + score) > 21) // if there are multiple Aces in hand, the new Ace drawed will only valued as 1
  {
    score -= 10;
    *num_ace = *num_ace - 1;
  }
  *amo_card = *amo_card + 1;

  return score;
}

/*****+*--*-***----**--***-**--**-*-********--******************************
*
*  Function Information
*
*  Name of Function: printline
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int suit - the suit of current drawed card 
*    2. int num - the numer of current drawed card
*    3. int total_score - the total score of current cards in hand
*    4. int amo_card - the amount of card in hand
*    5. int current_card - the card just drawed
*
*  Function Description: This function print the line currently drawed card
*
******+*--*-***----**--***-**--**-*-********--*****************************/

void printline(int suit, int num, int total_score, int amo_card, int current_card)
{
  switch(amo_card) // This switch check the order of thi card 
  {
    case 1: printf("The first");
      break;
    case 2: printf("The second");
      break;
    case 3: printf("The third");
      break;
    case 4: printf("The fourth");
      break;
    case 5: printf("The fifth");
      break;
  }
  printf(" card is #: %d (", current_card);
  switch(num) // This switch set the number of the card 
  {
    case 0: printf("Ace of "); // If num = 0 then print num as Ace
      break;
    case 1: printf("2 of "); // If num = 1 then print num as 2
      break;
    case 2: printf("3 of "); // If num = 2 then print num as 3
      break;
    case 3: printf("4 of "); // If num = 3 then print num as 4
      break;
    case 4: printf("5 of "); // If num = 4 then print num as 5
      break;
    case 5: printf("6 of "); // If num = 5 then print num as 6
      break;
    case 6: printf("7 of "); // If num = 6 then print num as 7
      break;
    case 7: printf("8 of "); // If num = 7 then print num as 8
      break;
    case 8: printf("9 of "); // If num = 8 then print num as 9
      break;
    case 9: printf("10 of "); // If num = 9 then print num as 10
      break;
    case 10: printf("Jack of "); // If num = 10 then print num as Jack
      break;
    case 11: printf("Queen of "); // If num = 10 then print num as Queen
      break;
    case 12: printf("King of "); // If num = 12 then print num as King
      break;
  }
  switch(suit) // This switch set the suit of the card
  {
    case 0: printf("Clubs) ");
      break;
    case 1: printf("Diamonds) ");
      break;
    case 2: printf("Hearts) ");
      break;
    case 3: printf("Spades) ");
      break;

  }
  printf("Current score: %d\n", total_score);
}

/*****+*--*-***----**--***-**--**-*-********--******************************
*
*  Function Information
*
*  Name of Function: result
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int total_score - the total score of drawed card in hand
*
*  Function Description: This function print the result of the game depend on total score of hand
*
******+*--*-***----**--***-**--**-*-********--*****************************/

void result(int total_score)
{
  printf("\n");
  if (total_score > 21) // if score bigger than 21, then dealer bust
  {
    printf("Dealer busts.\n");
  }
  else if (total_score < 21) // if score smaller than 21, then dealer hold
  {
    printf("Dealer holds.\n");
  }
  else // if score equal to 21, then dealer win
  {
    printf("Dealer wins!\n"); 
  }
}

/*****+*--*-***----**--***-**--**-*-********--******************************
*
*  Function Information
*
*  Name of Function: input
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. None
*
*  Function Description: This function takes in the input of seed and setup use srand()
*
******+*--*-***----**--***-**--**-*-********--*****************************/

void input(void)
{
  int seed; // the seed of the program's input

  printf("Enter the seed value -> ");
  scanf("%d", &seed);
  srand(seed);
  printf("\n");
}
