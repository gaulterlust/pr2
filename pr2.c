#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int lcm_of_array(int arr[], int size) {
    int result = arr[0];
    for (int i = 1; i < size; i++) {
        result = lcm(result, arr[i]);
    }
    return result;
}

int main() {
    int p;
    printf("Введіть кількість чисел: ");
    scanf("%d", &p);
    
    if (p < 2 || p > 20) {
        printf("Кількість чисел повинна бути від 2 до 20\n");
        return 1;
    }

    int numbers[p];
    printf("Введіть числа: ");
    for (int i = 0; i < p; i++) {
        scanf("%d", &numbers[i]);
    }

    int result = lcm_of_array(numbers, p);
    printf("Найменше спільне кратне: %d\n", result);

    return 0;
}