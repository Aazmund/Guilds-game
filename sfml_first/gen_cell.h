#include <iostream>
#include "ctime"

int arr[4];
int line_arr[4];

int a = 0;
int b = 0;
int c = 0;
int d = 0;

void random_square(){
    while (a == b || a == c || b == c) {
        srand(time(0));
        a = rand() % 4 + 1;
        b = rand() % 4 + 1;
        c = rand() % 4 + 1;
    }
    
    d = 10 - a - b - c;
    
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    arr[3] = d;
}

void random_line(){
    srand(time(0));
    int pos = rand() % 2 + 1;
    switch (pos) {
        case 1:
            line_arr[0] = 1;
            line_arr[1] = 0;
            line_arr[2] = 0;
            line_arr[3] = 0;
            break;
        case 2:
            line_arr[0] = 0;
            line_arr[1] = 0;
            line_arr[2] = 0;
            line_arr[3] = 1;
            break;
    }
}
