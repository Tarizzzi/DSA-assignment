#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice, N, i, j, temp, key;
    int *arr;

    printf("Enter the size of the array: ");
    scanf("%d", &N);

    arr = (int*) malloc(N * sizeof(int));

    printf("Enter %d integers:\n", N);
    for (i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Display the elements\n");
        printf("2. Sort the elements in ascending order\n");
        printf("3. Search for an element using linear search\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("The elements are:\n");
                for (i = 0; i < N; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 2:
                for (i = 0; i < N - 1; i++) {
                    for (j = i + 1; j < N; j++) {
                        if (arr[i] > arr[j]) {
                            temp = arr[i];
                            arr[i] = arr[j];
                            arr[j] = temp;
                        }
                    }
                }
                printf("The elements are sorted in ascending order.\n");
                break;

            case 3:
                printf("Enter the element to search: ");
                scanf("%d", &key);

                for (i = 0; i < N; i++) {
                    if (arr[i] == key) {
                        printf("Element found at index %d.\n", i);
                        break;
                    }
                }

                if (i == N) {
                    printf("Element not found.\n");
                }
                break;

            case 4:
                printf("Exiting the program.\n");
                free(arr);
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
