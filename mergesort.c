// ITBNM-2211-0101

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int id;
    char city[50];
} Package;

void merge(Package packets[], int left, int mid, int right) {
    int i, j, k;
    int left_size = mid - left + 1;
    int right_size = right - mid;


    Package left_array[left_size], right_array[right_size];

   
    for (i = 0; i < left_size; i++)
        left_array[i] = packets[left + i];
    for (j = 0; j < right_size; j++)
        right_array[j] = packets[mid + 1 + j];

 
    i = 0; 
    j = 0; 
    k = left; 
    while (i < left_size && j < right_size) {
        if (strcmp(left_array[i].city, right_array[j].city) <= 0) {
            packets[k] = left_array[i];
            i++;
        } else {
            packets[k] = right_array[j];
            j++;
        }
        k++;
    }


    while (i < left_size) {
        packets[k] = left_array[i];
        i++;
        k++;
    }

 
    while (j < right_size) {
        packets[k] = right_array[j];
        j++;
        k++;
    }
}


void mergeSort(Package packets[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

      
        mergeSort(packets, left, mid);
        mergeSort(packets, mid + 1, right);

       
        merge(packets, left, mid, right);
    }
}


void printpackets(Package packets[], int size) {
    for (int i = 0; i < size; i++)
        printf("Package ID: %d,\t Destination City: %s\n", packets[i].id, packets[i].city);
}

int main() {
    srand(time(NULL));

    int num_packets = 5; 
    Package packets[num_packets];

    
    for (int i = 0; i < num_packets; i++) {
        packets[i].id = i + 1;
        sprintf(packets[i].city, "City%d", rand() % 5 + 1);
    }

   
    printf("Unsorted packets:\n");
    printpackets(packets, num_packets);

    mergeSort(packets, 0, num_packets - 1);

   printf("\nSorted packets:\n");
    printpackets(packets, num_packets);

    return 0;
}
