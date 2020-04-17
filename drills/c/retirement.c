#include <stdio.h>
#include <stdlib.h>

struct retirement_s {
    int months;
    double contribution;
    double rate_of_return;
};
typedef struct retirement_s retire_info;

double updateBalance(double startBalance, retire_info assumptions){
    double endBalance=startBalance;
    endBalance+=startBalance*assumptions.rate_of_return/12.0;
    endBalance+=assumptions.contribution;
    return endBalance;
}

void printBalance(int age, double bal){
    printf("Age %3d month %2d you have $%.2lf\n",age/12,age%12,bal);
}

void retirement(int startAge, double initial, retire_info working, retire_info retired){
    printBalance(startAge, initial);
    //Working
    double balance = initial;
    int age=startAge;
    for(int m=0; m<working.months; ++m){
        printBalance(age,balance);
        ++age;
        balance = updateBalance(balance, working);
    }
    //Retired
    for(int m=0; m<retired.months; ++m){
        printBalance(age,balance);
        ++age;
        balance = updateBalance(balance, retired);
    }
}

int main(void){
    retire_info work;
    work.months = 489;
    work.contribution = 1000;
    work.rate_of_return = .045;
    retire_info retire;
    retire.months = 384;
    retire.contribution = -4000;
    retire.rate_of_return = 0.01;
    retirement(327,21345,work,retire);
}