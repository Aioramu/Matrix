#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <time.h>

int main()
    {
    srand(time(NULL));
    int m = rand()%5+3;
    int n = rand()%7+3;
    int i = 0;
    int j = 0;
    int min = 20000;
    int indmin [2];
    printf ("%i \n", n);
    printf ("%i \n", m);
    int Array [n] [m];
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            Array [i] [j] = rand()%10+1;
            printf ("%3.0i ", Array [i][j]);
        }
        printf ("\n");
    }
    printf ("\n \n \n");
    for (i = 0; i < m; i++){
        int v = Array [0][i];
        Array [0][i] = Array[n-1][i];
        Array [n-1][i] = v;
    for (i = 0; i < m/2; i++){
        int v1 =Array [0][i];
        Array [0][i] = Array [0][m - i - 1];
        Array [0][m - i - 1] = v1;
        int v2 = Array [n - 1][i];
        Array [n - 1][i] = Array [n - 1][m - i - 1];
        Array [n - 1][m - 1 - i] = v2;
    }
    printf ("\n \n \n");
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++)
            printf("%3.0i ", Array [i][j]);
        printf ("\n");
    }
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            if (min > Array [i][j]){
                min = Array [i][j];
                indmin [0] = i;
                indmin [1] = j;
            }
        }
    }
    printf ("\n \n \n");
    int masmen [n-1][m-1];
    for (i = 0; i < n-1; i++){
        for (j = 0; j < m-1; j++){
            if (i < indmin[0] && j < indmin[1])
                masmen [i][j] =Array [i][j];
            if (i >= indmin [0] && j < indmin [1])
                masmen[i][j] = Array [i+1][j];
            if (i >= indmin [0] && j >= indmin [1])
                masmen [i][j] = Array [i+1][j+1];
            if (i < indmin [0] && j >= indmin [1])
                masmen [i][j] = Array [i][j+1];
        }
    }
    printf ("\n \n \n");
    for (i = 0; i < n-1; i++){
        for (j = 0; j < m-1; j++)
            printf ("%3.0i ", masmen [i][j]);
        printf ("\n");
    }
    printf ("\n\n\nPlease enter the amount of pillars (0<x<10)\n");
    int p = getch();
    p = p - '0';
    if (p > 9 || p < 0){
        printf ("Wrong argument. Please restart the program.\n");
        return 1;
    }
    printf ("%i \n", p);
    printf ("\nNow please enter the data in correct format\n");
    printf ("Enter '1' if you want to know the format.\nEnter '2' if you want to start entering the matrix.\n");
    int a;
    int k = 0;
    int l = 0;
    int ruchArr [m-1][p];
    a = getch();
    printf ("\n \n \n");
    switch (a) {
        case '1':
            printf ("You must enter a series of numbers separated by a space.\nSymbol ',' will indicate the end of the line.\n");
            printf ("Symbol '.' will indicate the end of input.\nThere must be no negative numbers or zeros.\n");
            printf ("\nNow please start entering the matrix in correct format.\n");
            break;
        case '2':
            break;
        default:
            printf ("Wrong argument.\nPlease restart the program.\n");
            return 1;
    }
    printf ("\nIn the matrix should be %i rows and %i columns.\n", m-1, p);
    for (i = 0; i < m - 1; i++){
        for (j = 0; j < p; j++){
            while ( ( a = getch() ) != ' '){
                if (a == ',' || a == '.')
                    break;
                k = k*10 + a - '0';
            }
            ruchArr [i][j] = k;
            k = 0;
            printf ("%3.0i  ", ruchArr[i][j]);
        }
        printf ("\n");
    }
    k = 0;
    l = 0;
    int h = 0;
    int endofmatrix [m-1][p];
    printf ("\n%1.0i\n%1.0i\n%1.0i\n\n", n-1, m-1, p);
    for (h = 0; h < n-1; h++){
        for (k = 0; k < p; k++){
            for (i = 0; i < m-1; i++){
                l = l + masmen[h][i]*ruchArr[i][k];
            }
            endofmatrix [h][k] = l;
            l = 0;
            printf ("%3.0i  ", endofmatrix[h][k]);
        
        }
        printf ("\n");
    }
    printf ("\nLol,that code is working\n");
    return -1;
}
}

