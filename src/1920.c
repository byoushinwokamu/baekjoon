#include <stdio.h>

void _qSort(int *arr, int left, int right) {
    int pivot = arr[left];
    int i = left + 1, j = right; // each is left/right cursor
    int t;                       // temp value for swap
    if (i >= j)
        return;
    while (i < j) {
        while (i < right && pivot > arr[i])
            i++;
        while (j > left && pivot < arr[j])
            j--;
        if (i < j) {
            t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }
    arr[left] = arr[j];
    arr[j] = pivot;

    _qSort(arr, left, j - 1);
    _qSort(arr, j + 1, right);
} // _qSort

void quickSort(int *arr, int len) { _qSort(arr, 0, len - 1); }

int main() {
    int n;
    int a[100001];
    int m;
    int b[100001];
    int i, j;
    int temp;
    int lb, rb;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    quickSort(a, n);
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }

    for (i = 0; i < m; i++) {
        lb = 0;
        rb = n - 1;
        while (1) {
            temp = (lb + rb) / 2;
            if (rb < lb) {
                printf("0\n");
                break;
            }
            if (a[temp] == b[i]) {
                printf("1\n");
                break;
            } else if (a[temp] > b[i])
                rb = temp - 1;
            else
                lb = temp + 1;
        }
    }

    return 0;
}