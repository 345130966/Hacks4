/**
*
* Author: Yifan Liu
*
* This program compute a saving account grouth over a specified
* number of years given rate of return and inflation, initial balance, and monthly contribution amount.
* It produces a monthly report.
*
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

  if(argc != 6) {
    printf("Error: You need to provide initial balance, monthly contribution amount, rate of return and inflation, and number of years\n");
    exit(1);
  }
double initialBalance = atof(argv[1]);
double monthlyContributionAmount = atof(argv[2]);
double rateOfReturn = atof(argv[3]);
double rateOfInflation = atof(argv[4]);
int years = atoi(argv[5]);

double currentBalance = initialBalance;
double totalInterestEarned, totalNestEgg;
double yearlyContributionAmount = monthlyContributionAmount * 12;
if(yearlyContributionAmount >= 18500) {
  printf("Illegal: monthly contributions exceed $18,500 annual limit\n");
  exit(0);
} else{

printf("Month Interest Balance\n");

for(int i=1; i<=years * 12; i++) {

  double monthlyInterestRate = (((1 + rateOfReturn)/(1 + rateOfInflation)) - 1)/12;
  double monthInterest = currentBalance * monthlyInterestRate;
  monthInterest = round(monthInterest * 100) / 100;

  currentBalance = currentBalance + monthInterest + monthlyContributionAmount;
  totalInterestEarned += monthInterest;
  totalNestEgg = initialBalance + totalInterestEarned + monthlyContributionAmount * years * 12;

  printf("%3d $%10.2f $%10.2f\n", i, monthInterest, currentBalance);
}
}
  printf("Total Interest Earned: $%10.2f\n", totalInterestEarned);
  printf("Total Nest Egg: $%10.2f\n", totalNestEgg);

  return 0;
}
