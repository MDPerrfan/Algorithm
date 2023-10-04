#include <stdio.h>
#define max 10

int arr[max];

void merge(int low, int mid, int high) {
    int temp[max];
    int i = low;
    int k = low;
    int j = mid + 1;

    while ((i <= mid) && (j <= high)) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= high) {
        temp[k++] = arr[j++];
    }

    for (i = low; i <= high; i++) {
        arr[i] = temp[i];
    }
}

void merge_sort(int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        merge_sort(low, mid);
        merge_sort(mid + 1, high);
        merge(low, mid, high);
    }
}

int main() {
    int i, n;
    printf("Enter the number of elements:");
    scanf("%d", &n);

    if (n > max) {
        printf("Array size exceeds the maximum limit (%d)\n", max);
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    merge_sort(0, n - 1);

    printf("Sorted Array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
