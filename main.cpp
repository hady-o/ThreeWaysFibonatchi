#include <stdio.h>
/*
------------  Recurrence Way -----------
 => Advantage
    - easy to implement and understand

 => DisAdvantage
    - exponential time complexity. O(2^n)
    - redundant computation can make memory leak
 */
int recursionFib(int num){
    if(num == 0 || num == 1 || num == 2)
        return num;
    return recursionFib(num-3)+ recursionFib(num-2);
}
/*
 ------------  Iteration Way -----------
 => Advantage
    1- linear time complexity: O(n)
    2- constant space complexity: O(1)
        since we only need to store the last two Fibonacci numbers

 => DisAdvantage
    - it may not be as easy to understand and implement
 */
int loopFib(int num){
    if(num >= 0 && num < 3)
        return num;
    int nMin3 = 0;
    int nMin2 = 1;
    int nMin1 = 2;
    int result;
    for (int i = 3; i <=num ; ++i) {

        result = nMin3 + nMin2;
        nMin3=nMin2;
        nMin2 = nMin1;
        nMin1 = result;
    }
    return result;
}
/*
 ------------  memoization Way -----------
 => Advantage
    1- linear time complexity: O(n)
    2- Easy to implement
    3- avoid redundant computation

 => DisAdvantage
    - consume more memory
 */
int memoizedFib(int n,int memo[]) {
    if (n == 0 || n == 1 || n == 2) {
        memo[n] = n;
        return n;
    }
    if (memo[n] != -1) {
        return memo[n];
    } else {
        memo[n] = memoizedFib(n-3,memo) + memoizedFib(n-2,memo);
        return memo[n];
    }
}


// so that the efficient way is iteration method
void run(int memo[]){
    printf("-------------- Welcome ----------- \n");
    printf("Please select the way you want to use: \n\n");
    printf("1- For Recurrence way. \n");
    printf("2- For Iterative way. \n");
    printf("3- For Dynamic programming way. \n");
    printf("Please enter your choice: ");
    int choice;
    scanf("%d", &choice);
    printf("Please enter the number you want to compute: ");
    int n;
    scanf("%d", &n);
    switch (choice) {
        case 1:
            printf("\nresult from recurrence way is:%d \n",recursionFib(n));
            break;
        case 2:
            printf("\nresult from iteration way is:%d \n",loopFib(n));
            break;
        case 3:
            printf("\nresult from dynamic programming way is: %d \n",memoizedFib(n,memo));
            break;
        default:
            printf("\nPlease select a valid choice. \n");
            run(memo);
    }
}

int main() {
    int memo[100];
    for (int i = 0; i < 100; i++) {
        memo[i] = -1;
    }
    run(memo);
    return 0;
}
