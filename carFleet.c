// Problem: Given a target distance and cars’ positions & speeds, compute the number of car fleets reaching the destination.
// Sort cars by position in descending order and calculate time to reach target.

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int position;
    int speed;
} Car;

// Sort by position in descending order
int compare(const void *a, const void *b) {
    Car *carA = (Car *)a;
    Car *carB = (Car *)b;

    return carB->position - carA->position;
}

int carFleet(int target, int position[], int speed[], int n) {

    Car cars[n];

    // Store position and speed together
    for (int i = 0; i < n; i++) {
        cars[i].position = position[i];
        cars[i].speed = speed[i];
    }

    // Closest to target comes first
    qsort(cars, n, sizeof(Car), compare);

    int fleets = 0;
    double lastTime = 0.0;

    // Move from closest car to farthest car
    for (int i = 0; i < n; i++) {

        // Time needed to reach target
        double time = (double)(target - cars[i].position)
                      / cars[i].speed;

        // If this car takes longer, it cannot catch
        // the fleet in front of it
        if (time > lastTime) {
            fleets++;
            lastTime = time;
        }

        // Otherwise, it joins the fleet ahead
    }

    return fleets;
}

int main() {

    int target = 12;

    int position[] = {10, 8, 0, 5, 3};
    int speed[]    = {2, 4, 1, 1, 3};

    int n = 5;

    int result = carFleet(target, position, speed, n);

    printf("Number of car fleets: %d\n", result);

    return 0;
}