#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int sum_digits(int);
int product_digits(int);
int reverse_digits(int);
int digit_count(int);
bool is_palindrome(int);
bool is_armstrong(int);
int factorial_of_digits(int);

int main() {
    int choice, num;
    bool keep_running = true; // Variable to control loop

    while (keep_running) {
        printf("\n\t\tPLAY WITH DIGITS\n");
        printf("1. Digits Sum\n");
        printf("2. Digits Product\n");
        printf("3. Reverse Digits\n");
        printf("4. Digit Count\n");
        printf("5. Check Palindrome\n");
        printf("6. Check Armstrong Number\n");
        printf("7. Factorial of Digits\n");
        printf("0. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting the program...\n");
            keep_running = false; // Terminate the loop
            continue; // Skip the rest of the loop when exiting
        }

        printf("Enter any number: ");
        scanf("%d", &num);

        switch (choice) {
            case 1:
                printf("Sum of digits: %d\n", sum_digits(num));
                break;
            case 2:
                printf("Product of digits: %d\n", product_digits(num));
                break;
            case 3:
                printf("Reverse of digits: %d\n", reverse_digits(num));
                break;
            case 4:
                printf("Total digits: %d\n", digit_count(num));
                break;
            case 5:
                printf("Is palindrome: %s\n", is_palindrome(num) ? "Yes" : "No");
                break;
            case 6:
                printf("Is Armstrong: %s\n", is_armstrong(num) ? "Yes" : "No");
                break;
            case 7:
                printf("Factorial of digits: %d\n", factorial_of_digits(num));
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}

int sum_digits(int num) {
    int sum = 0;
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int product_digits(int num) {
    if (num == 0) return 0;
    int product = 1;
    while (num != 0) {
        product *= num % 10;
        num /= 10;
    }
    return product;
}

int reverse_digits(int num) {
    int reverse = 0;
    while (num != 0) {
        reverse = reverse * 10 + num % 10;
        num /= 10;
    }
    return reverse;
}

int digit_count(int num) {
    if (num == 0) return 1;
    int count = 0;
    while (num != 0) {
        num /= 10;
        count++;
    }
    return count;
}

bool is_palindrome(int num) {
    return num == reverse_digits(num);
}

bool is_armstrong(int num) {
    int sum = 0, temp = num, count = digit_count(num);
    while (temp != 0) {
        int digit = temp % 10;
        int pow_res = 1;
        for (int i = 0; i < count; i++) {
            pow_res *= digit;
        }
        sum += pow_res;
        temp /= 10;
    }
    return sum == num;
}

int factorial_of_digits(int num) {
    int factorial = 1;
    while (num != 0) {
        int digit = num % 10;
        int fact = 1;
        for (int i = 1; i <= digit; i++) {
            fact *= i;
        }
        factorial *= fact;
        num /= 10;
    }
    return factorial;
}
