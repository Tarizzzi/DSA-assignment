#include <stdio.h>

void create_Array(int a[], int n) {
    int i;
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

void display_Array(int a[], int n) {
    int i;
    printf("The elements of array:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
}

int search_Element(int a[], int key, int index, int n) {
    if (index >= n)
        return -1; // element not found

    if (a[index] == key)
        return index; // element found

    return search_Element(a, key, index + 1, n); // recursive call with next index
}

int main() {
    int a[100], n, key, index;
    printf("Enter the number of elements:");
    scanf("%d", &n);
    create_Array(a, n);
    display_Array(a, n);
    printf("\nEnter the element to be searched:");
    scanf("%d", &key);
    index = search_Element(a, key, 0, n);
    if (index != -1)
        printf("The element %d is found at %d index.", key, index);
    else
        printf("Element not found.");
    return 0;
}
