#include <string>
#include <ctime>
#include <iostream>
#include <omp.h>
#include <cmath>

using namespace std;

#define maximum 1000
#define N 25
//Deaclaring some constants to be use when prototyping...
const int ROWS = N*N*N;
const int COLS = 4 * N*N;
//Prototyping some of my functions to allow for flexibility...
bool problem[ROWS][COLS] = { { 0 } };
bool SOLVED = false;
void TRACE(int Sudoku[][N]);
void PRINT(int Sudoku[][N]);
//Here are my global variables/constants...
const int SxS = N*N;
const int SQRT = sqrt((double)N);

//Setting up my run-time timer...
clock_t timer, timer2;

//Declaring my class
class  EVALUATE{
public:
	EVALUATE *up;
	EVALUATE *down;
	EVALUATE *head;
	EVALUATE *left;
	EVALUATE *right;
	int size;		
	int rREF[4];	
};

class EVALUATE Head;
class EVALUATE* hEV = &Head;
class EVALUATE* solution[maximum];
class EVALUATE* true_val[maximum];
//Prototyping Functions for the "Exact-Cover Problem" implementation... 
void UNHIDE(EVALUATE* col);
void HIDE(EVALUATE* col);


//DLX FUNCTION****
//The below Function ,am using it to build my linked-list...
 #pragma omp parallel for reduction(+:total)
void BLL(bool problem[ROWS][COLS]) {
	EVALUATE* header = new EVALUATE;
	header->left = header;
	header->right = header;
	header->down = header;
	header->up = header;
	header->size = -1;
	header->head = header;
	EVALUATE* temp = header;
	for (int i = 0; i < COLS; i++) {
		EVALUATE* nEV = new EVALUATE;
		nEV->size = 0;
		nEV->up = nEV;
		nEV->down = nEV;
		nEV->head = nEV;
		nEV->right = header;
		nEV->left = temp;
		temp->right = nEV;
		temp = nEV;
	}

	int ID[5] = { 0,1,1,1,1 };
	
	for (int i = 0; i < ROWS; i++) {
		EVALUATE* top = header->right;
		EVALUATE* prev = NULL;

		if (i != 0 && i%SxS == 0) {
			ID[0] -= N - 1;
			ID[1]++;
			ID[2] -= N - 1;
			ID[3]++;
		}
		else if (i!= 0 && i%N == 0) {
			ID[0] -= N - 1;
			ID[2]++;
		}
		else {
			ID[0]++;
		}

		for (int j = 0; j < COLS; j++, top = top->right) {
			if (problem[i][j]) {
				EVALUATE* nEV = new EVALUATE;
				nEV->rREF[0] = ID[0];
				nEV->rREF[1] = ID[1];
				nEV->rREF[2] = ID[2];
				if (prev == NULL) {
					prev = nEV;
					prev->right = nEV;
				}
				nEV->left = prev;
				nEV->right = prev->right;
				nEV->right->left = nEV;
				prev->right = nEV;
				nEV->head = top;
				nEV->down = top;
				nEV->up = top->up;
				top->up->down = nEV;
				top->size++;
				top->up = nEV;
				if (top->down == top)
					top->down = nEV;
				prev = nEV;
			}
		}
	}

	hEV = header;
}

//The function below am using it to search thorugh my Binary Linked-list...
 #pragma omp parallel for reduction(+:total)
void SEARCH(int NUM) {
	if (hEV->right == hEV) {
		int Grid[N][N] = { {0} };
		TRACE(Grid);
		PRINT(Grid);
		std::cin.get(); 
		SOLVED = true;
		return;
	}

	
	EVALUATE* Col = hEV->right;
	for (EVALUATE* temp = Col->right; temp != hEV; temp = temp->right)
		if (temp->size < Col->size)
			Col = temp;

	HIDE(Col);

	for (EVALUATE* temp = Col->down; temp != Col; temp = temp->down) {
		solution[NUM] = temp;
		for (EVALUATE* branch = temp->right; branch != temp; branch = branch->right) {
			HIDE(branch->head);
		}

		SEARCH(NUM + 1);

		temp = solution[NUM];
		solution[NUM] = NULL;
		Col = temp->head;
		for (EVALUATE* branch = temp->left; branch != temp; branch = branch->left) {
			UNHIDE(branch->head);
		}
	}

	UNHIDE(Col);
}

//Iuse the following function to build a sparse-matrix,and check few constraints
 #pragma omp parallel for reduction(+:total)
void BSM(bool problem[ROWS][COLS]) {
	int j = 0, counter = 0;
	for (int i = 0; i < ROWS; i++) { 
		problem[i][j] = 1;
		counter++;
		if (counter >= N) {
			j++;
			counter = 0;
		}
	}
	int x = 0;
	counter = 1;
	for (j = SxS; j < 2 * SxS; j++) {
		for (int i = x; i < counter*SxS; i += N)
			problem[i][j] = 1;

		if ((j + 1) % N == 0) {
			x = counter*SxS;
			counter++;
		}
		else
			x++;
	}
	j = 2 * SxS;
	for (int i = 0; i < ROWS; i++)
	{
		problem[i][j] = 1;
		j++;
		if (j >= 3 * SxS)
			j = 2 * SxS;
	}
	x = 0;
	for (j = 3 * SxS; j < COLS; j++) {

		for (int l = 0; l < SQRT; l++) {
			for (int k = 0; k<SQRT; k++)
				problem[x + l*N + k*SxS][j] = 1;
		}

		int temp = j + 1 - 3 * SxS;

		if (temp % (int)(SQRT * N) == 0)
			x += (SQRT - 1)*SxS + (SQRT - 1)*N + 1;
		else if (temp % N == 0)
			x += N*(SQRT - 1) + 1;
		else
			x++;
	}
}


 #pragma omp parallel for reduction(+:total)
void TRANSLTL(int Puzzle[][N]) {
	int index = 0;
	for(int i = 0 ; i<N; i++ )
		for(int j = 0 ; j<N; j++)
			if (Puzzle[i][j] > 0) {
				EVALUATE* Col = NULL;
				EVALUATE* temp = NULL;
				for (Col = hEV->right; Col != hEV; Col = Col->right) {
					for (temp = Col->down; temp != Col; temp = temp->down)
						if (temp->rREF[0] == Puzzle[i][j] && (temp->rREF[1] - 1) == i && (temp->rREF[2] - 1) == j)
							goto ExitLoops;
				}
ExitLoops:		HIDE(Col);
				true_val[index] = temp;
				index++;
				for (EVALUATE* branch = temp->right; branch != temp; branch = branch->right) {
					HIDE(branch->head);
				}

			}

}
 #pragma omp parallel for reduction(+:total)
void TRACE(int Sudoku[][N]) {
	for (int i = 0; solution[i] != NULL; i++) {
			Sudoku[solution[i]->rREF[1]-1][solution[i]->rREF[2]-1] = solution[i]->rREF[0];
	}
	for (int i = 0; true_val[i] != NULL; i++) {
		Sudoku[true_val[i]->rREF[1] - 1][true_val[i]->rREF[2] - 1] = true_val[i]->rREF[0];
	}
}
 #pragma omp parallel for reduction(+:total)
void PRINT(int problem[][N]){
	int counter = 1;
	int add = 0;
	for (int i = 0; i<N; i++){
		for (int j = 0; j<N; j++){
			if (problem[i][j] == 0)
				cout << ". ";
			else{
			if(problem[i][j]>=10){
				cout << char( problem[i][j]+55);
				}
				else{cout<<problem[i][j];}
				if(j<24){cout<<" ";}
				}
		}
		cout<<endl;
	}
}
//Now implementing the MOST IMPORTANT!! Function,SOLVE
 #pragma omp parallel for reduction(+:total)
void SOLVE(int Sudoku[][N]) {
	BSM(problem);
	BLL(problem);
	TRANSLTL(Sudoku);
	SEARCH(0);
	if (!SOLVED)
		cout << "No Solution" << std::endl;
	SOLVED = false;
}
//The following two function,For the EXACT-COVER Problem approacch,They handle all the computations in linear amount of time(O(n))
 #pragma omp parallel for reduction(+:total)
void HIDE(EVALUATE* col) {
	col->left->right = col->right;
	col->right->left = col->left;
	for (EVALUATE* branch = col->down; branch != col; branch = branch->down) {
		for (EVALUATE* temp = branch->right; temp != branch; temp = temp->right) {
			temp->down->up = temp->up;
			temp->up->down = temp->down;
			temp->head->size--;
		}
	}
}
 #pragma omp parallel for reduction(+:total)
void UNHIDE(EVALUATE* col) {
	for (EVALUATE* branch = col->up; branch != col; branch = branch->up) {
		for (EVALUATE* temp = branch->left; temp != branch; temp = temp->left) {
			temp->head->size++;
			temp->down->up = temp;
			temp->up->down = temp;
		}
	}
	col->left->right = col;
	col->right->left = col;
}

//Finally we have the main function to allow us to receive the input from the marker/user...;)
 #pragma omp parallel for reduction(+:total)
int main(){	
//--------------------------------------------------------------------------------------------------------------------------------------------------//
int problem[25][25];char elem;
    //#pragma omp taskloop firstprivate(problem)
    for(int i=0;i<25;++i){
    	for(int j=0;j<25;++j){
    		cin>>elem;
    		if(int(elem)<58){problem[i][j]=elem-48;}
    		else{problem[i][j]=elem-55;}
    	}
    }
	SOLVE(problem);
	cin.get();
	return 0;
}

