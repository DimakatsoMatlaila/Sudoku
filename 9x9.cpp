#include <bits/stdc++.h>
#include <omp.h>
#include<iostream>
using namespace std;
//const int size = 9;
#define size 9
//Prototyping Functions 
int BOXEV(int i, int j);
void POSSIBLE(int problem[size][size]);
bool VALIDATION(int i, int j, int number);
void PRINT(int problem[size][size]);
bool SOLVE(int problem[size][size], int i, int j);
//Prototyping ends here...

int BOXEV(int i, int j) {
    return i / 3 * 3 + j / 3;
}
int problem[size][size];
int row[size], col[size], box[size];
bool val = false;


bool SOLVE(int problem[size][size], int i, int j) {
    if (!val)
        val = true,
        POSSIBLE(problem);
    if (i == size - 1 && j == size)
        return true;
    if (j == size)
        j = 0,
        ++i;
    if (problem[i][j])
        return SOLVE(problem, i, j + 1);
   // #pragma omp taskloop firstprivate(problem)
   
    int nr = 1;
        if (VALIDATION(i, j, nr)) {
            problem[i][j] = nr;
            row[i] |= 1 << nr;
            col[j] |= 1 << nr;
            box[BOXEV(i, j)] |= 1 << nr;
            if (SOLVE(problem, i, j + 1))
                return true;
            row[i] &= ~(1 << nr);
            col[j] &= ~(1 << nr);
            box[BOXEV(i, j)] &= ~(1 << nr);
        }
        problem[i][j] = 0;

        nr = 2;
        if (VALIDATION(i, j, nr)) {
            problem[i][j] = nr;
            row[i] |= 1 << nr;
            col[j] |= 1 << nr;
            box[BOXEV(i, j)] |= 1 << nr;
            if (SOLVE(problem, i, j + 1))
                return true;
            row[i] &= ~(1 << nr);
            col[j] &= ~(1 << nr);
            box[BOXEV(i, j)] &= ~(1 << nr);
        }
        problem[i][j] = 0;

        nr = 3;
        if (VALIDATION(i, j, nr)) {
            problem[i][j] = nr;
            row[i] |= 1 << nr;
            col[j] |= 1 << nr;
            box[BOXEV(i, j)] |= 1 << nr;
            if (SOLVE(problem, i, j + 1))
                return true;
            row[i] &= ~(1 << nr);
            col[j] &= ~(1 << nr);
            box[BOXEV(i, j)] &= ~(1 << nr);
        }
        problem[i][j] = 0;
        nr = 4;
        if (VALIDATION(i, j, nr)) {
            problem[i][j] = nr;
            row[i] |= 1 << nr;
            col[j] |= 1 << nr;
            box[BOXEV(i, j)] |= 1 << nr;
            if (SOLVE(problem, i, j + 1))
                return true;
            row[i] &= ~(1 << nr);
            col[j] &= ~(1 << nr);
            box[BOXEV(i, j)] &= ~(1 << nr);
        }
        problem[i][j] = 0;
        nr = 5;
        if (VALIDATION(i, j, nr)) {
            problem[i][j] = nr;
            row[i] |= 1 << nr;
            col[j] |= 1 << nr;
            box[BOXEV(i, j)] |= 1 << nr;
            if (SOLVE(problem, i, j + 1))
                return true;
            row[i] &= ~(1 << nr);
            col[j] &= ~(1 << nr);
            box[BOXEV(i, j)] &= ~(1 << nr);
        }
        problem[i][j] = 0;
        nr = 6;
        if (VALIDATION(i, j, nr)) {
            problem[i][j] = nr;
            row[i] |= 1 << nr;
            col[j] |= 1 << nr;
            box[BOXEV(i, j)] |= 1 << nr;
            if (SOLVE(problem, i, j + 1))
                return true;
            row[i] &= ~(1 << nr);
            col[j] &= ~(1 << nr);
            box[BOXEV(i, j)] &= ~(1 << nr);
        }
        problem[i][j] = 0;
        nr = 7;
        if (VALIDATION(i, j, nr)) {
            problem[i][j] = nr;
            row[i] |= 1 << nr;
            col[j] |= 1 << nr;
            box[BOXEV(i, j)] |= 1 << nr;
            if (SOLVE(problem, i, j + 1))
                return true;
            row[i] &= ~(1 << nr);
            col[j] &= ~(1 << nr);
            box[BOXEV(i, j)] &= ~(1 << nr);
        }
        problem[i][j] = 0;

        nr = 8;
        if (VALIDATION(i, j, nr)) {
            problem[i][j] = nr;
            row[i] |= 1 << nr;
            col[j] |= 1 << nr;
            box[BOXEV(i, j)] |= 1 << nr;
            if (SOLVE(problem, i, j + 1))
                return true;
            row[i] &= ~(1 << nr);
            col[j] &= ~(1 << nr);
            box[BOXEV(i, j)] &= ~(1 << nr);
        }
        problem[i][j] = 0;
        nr = 9;
        if (VALIDATION(i, j, nr)) {
            problem[i][j] = nr;
            row[i] |= 1 << nr;
            col[j] |= 1 << nr;
            box[BOXEV(i, j)] |= 1 << nr;
            if (SOLVE(problem, i, j + 1))
                return true;
            row[i] &= ~(1 << nr);
            col[j] &= ~(1 << nr);
            box[BOXEV(i, j)] &= ~(1 << nr);
        }
        problem[i][j] = 0;
    return false;
}
 
int main() {
    int problem[size][size];
    //#pragma omp taskloop firstprivate(problem)
    int i, j;
            //i=0
            cin >> problem[0][0];
            cin >> problem[0][1];
            cin >> problem[0][2];
            cin >> problem[0][3];
            cin >> problem[0][4];
            cin >> problem[0][5];
            cin >> problem[0][6];
            cin >> problem[0][7];
            cin >> problem[0][8];

            i = 1;
            cin >> problem[i][0];
            cin >> problem[i][1];
            cin >> problem[i][2];
            cin >> problem[i][3];
            cin >> problem[i][4];
            cin >> problem[i][5];
            cin >> problem[i][6];
            cin >> problem[i][7];
            cin >> problem[i][8];

            i = 2;
            cin >> problem[i][0];
            cin >> problem[i][1];
            cin >> problem[i][2];
            cin >> problem[i][3];
            cin >> problem[i][4];
            cin >> problem[i][5];
            cin >> problem[i][6];
            cin >> problem[i][7];
            cin >> problem[i][8];

            i = 3;
            cin >> problem[i][0];
            cin >> problem[i][1];
            cin >> problem[i][2];
            cin >> problem[i][3];
            cin >> problem[i][4];
            cin >> problem[i][5];
            cin >> problem[i][6];
            cin >> problem[i][7];
            cin >> problem[i][8];

            i = 4;
            cin >> problem[i][0];
            cin >> problem[i][1];
            cin >> problem[i][2];
            cin >> problem[i][3];
            cin >> problem[i][4];
            cin >> problem[i][5];
            cin >> problem[i][6];
            cin >> problem[i][7];
            cin >> problem[i][8];

            i = 5;
            cin >> problem[i][0];
            cin >> problem[i][1];
            cin >> problem[i][2];
            cin >> problem[i][3];
            cin >> problem[i][4];
            cin >> problem[i][5];
            cin >> problem[i][6];
            cin >> problem[i][7];
            cin >> problem[i][8];

            i = 6;
            cin >> problem[i][0];
            cin >> problem[i][1];
            cin >> problem[i][2];
            cin >> problem[i][3];
            cin >> problem[i][4];
            cin >> problem[i][5];
            cin >> problem[i][6];
            cin >> problem[i][7];
            cin >> problem[i][8];

            i = 7;
            cin >> problem[i][0];
            cin >> problem[i][1];
            cin >> problem[i][2];
            cin >> problem[i][3];
            cin >> problem[i][4];
            cin >> problem[i][5];
            cin >> problem[i][6];
            cin >> problem[i][7];
            cin >> problem[i][8];

            i = 8;
            cin >> problem[i][0];
            cin >> problem[i][1];
            cin >> problem[i][2];
            cin >> problem[i][3];
            cin >> problem[i][4];
            cin >> problem[i][5];
            cin >> problem[i][6];
            cin >> problem[i][7];
            cin >> problem[i][8];
        
    
    if (SOLVE(problem, 0, 0)) {
        PRINT(problem);
    }
    else {
        cout << "No Solution" << endl;
    }
    return 0;
}



void POSSIBLE(int problem[size][size]) {
    int i,j;
            //For i=0
            i = 0; j = 0;
            row[i] |= 1 << problem[i][j],
            col[j] |= 1 << problem[i][j],
            box[BOXEV(i, j)] |= 1 << problem[i][j];

            j = 1;
            row[i] |= 1 << problem[i][j],
                col[j] |= 1 << problem[i][j],
                box[BOXEV(i, j)] |= 1 << problem[i][j];

            j = 2;
            row[i] |= 1 << problem[i][j],
                col[j] |= 1 << problem[i][j],
                box[BOXEV(i, j)] |= 1 << problem[i][j];

                j = 3;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];
                j = 4;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];
                j = 5;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];
                j = 6;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];
                j = 7;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];

                j = 8;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];

                //for i=1
                i = 1;
             j = 0;
            row[i] |= 1 << problem[i][j],
                col[j] |= 1 << problem[i][j],
                box[BOXEV(i, j)] |= 1 << problem[i][j];

            j = 1;
            row[i] |= 1 << problem[i][j],
                col[j] |= 1 << problem[i][j],
                box[BOXEV(i, j)] |= 1 << problem[i][j];

            j = 2;
            row[i] |= 1 << problem[i][j],
                col[j] |= 1 << problem[i][j],
                box[BOXEV(i, j)] |= 1 << problem[i][j];

                j = 3;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];
                j = 4;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];
                j = 5;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];
                j = 6;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];
                j = 7;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];

                j = 8;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];
                //For i=2
                i = 2;
                j = 0;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];

                j = 1;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];

                j = 2;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];

                j = 3;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];
                j = 4;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];
                j = 5;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];
                j = 6;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];
                j = 7;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];

                j = 8;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];

                //For i=3;

                i = 3;
                j = 0;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];

                j = 1;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];

                j = 2;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];

                j = 3;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];
                j = 4;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];
                j = 5;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];
                j = 6;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];
                j = 7;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];

                j = 8;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];
                //For i=4
                i = 4;
                j = 0;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];

                j = 1;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];

                j = 2;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];

                j = 3;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];
                j = 4;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];
                j = 5;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];
                j = 6;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];
                j = 7;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];

                j = 8;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];

                //For i=5
                i = 5;
                j = 0;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];

                j = 1;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];

                j = 2;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];

                j = 3;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];
                j = 4;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];
                j = 5;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];
                j = 6;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];
                j = 7;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];

                j = 8;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];

                //For i=6
                i = 6;
                j = 0;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];

                j = 1;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];

                j = 2;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];

                j = 3;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];
                j = 4;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];
                j = 5;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];
                j = 6;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];
                j = 7;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];

                j = 8;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];

                //For i=7
                i = 7;
                j = 0;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];

                j = 1;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];

                j = 2;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];

                j = 3;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];
                j = 4;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];
                j = 5;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];
                j = 6;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];
                j = 7;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];

                j = 8;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];

                //For i = 8
                i = 8;
                j = 0;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];

                j = 1;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];

                j = 2;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];

                j = 3;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];
                j = 4;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];
                j = 5;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];
                j = 6;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];
                j = 7;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];

                j = 8;
                row[i] |= 1 << problem[i][j],
                    col[j] |= 1 << problem[i][j],
                    box[BOXEV(i, j)] |= 1 << problem[i][j];

}

bool VALIDATION(int i, int j, int number) {
    return !((row[i] >> number) & 1)
        && !((col[j] >> number) & 1)
        && !((box[BOXEV(i, j)] >> number) & 1);
}
void PRINT(int problem[size][size]) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << problem[i][j];
            if (j < 8) {
                cout << " ";
            }
        }
        cout << endl;
    }
}
