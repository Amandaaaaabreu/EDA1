#include <stdio.h>

typedef long Element;
#define less(A,B) (A < B)
#define exchange(A,B){Element temp = A; A = B; B = temp;}
#define compareAndExchange(A,B) {if (less(B,A)) exchange(A,B);}

void insertionSort(Element *array, int left, int right) {
    compareAndExchange(array[left], array[right]);
    for (int i = left+2; i <= right; i++) {
        int currentIndex = i;
        Element currentValue = array[currentIndex];
        while (less(currentValue, array[currentIndex-1])) {
            array[currentIndex] = array[currentIndex-1];
            currentIndex--;
        }
        array[currentIndex] = currentValue;
    }
}

int main() {
    int n;
    Element vehiclePlates[102], plateNumber;
    int operationType, count = 0;
    while (scanf("%d %ld", &operationType, &plateNumber) == 2) {
        if (operationType == 1) { // Adding a plate number
            if (count < 101) {
                vehiclePlates[count++] = plateNumber;
                insertionSort(vehiclePlates, 0, count-1);
            } else {
                if (less(plateNumber, vehiclePlates[100])) {
                    exchange(plateNumber, vehiclePlates[100]);
                    insertionSort(vehiclePlates, 0, 100);
                }
            }
        } else { 
            int numOutput = plateNumber;
            for (int j = 0; j < numOutput; j++)
                printf("%ld ", vehiclePlates[j]);
            printf("\n");
        }
    }
    for(int i = 0; i<5000;i++); 
    for(int i=0; i<n;i++);

    return 0;
}