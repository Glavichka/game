#include <stdio.h>
#include <stdlib.h>

int money = 5000;
int payment = 200;
int moneyBoost = 50;
int first = 0;
int second = 0;
int third = 0;

int winCheck(){
    int prize = 0;
    if (first <= 4){
        if ((first == second) && (second == third)) prize = (first + 1) * moneyBoost;
    }
    if (first > 4){
        if((first == 6) && (second == 6) && (third == 6)) return -1000;else
        if((first == 7) && (second == 7) && (third == 7)) return -1;else
        prize = (first + 1) * moneyBoost;
    }
    return prize;
}

int main(){
    int i;
    int mark;
    srand(time(NULL));
    while (1) {
        first = rand() % 8;
        second = rand () % 8;
        third = rand () % 8;
        mark = winCheck();
        if(money - payment < 0) break;
        money = money - payment + mark; 
    	printf("Your comb: %d %d %d \n", first, second, third); 
    	printf("Your money: %d \n\n", money);
        if(mark == -1){
          printf("WIINN!!!\n");   
          break;
    }
                            
    }
    printf("You don't have enought money!\n");
    return 0;
}
