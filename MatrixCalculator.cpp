//
//  Project5 Part-2
//
//  Created by Madhav Chhura, Steven Sairafian on 2/2/14.
//  Copyright (c) 2014 Madhav Chhura. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int **AllocateDynamicArray(int nRows, int nCols);
void addition(int**& matrixA, int**& matrixB, int rows, int cols);
void subtraction(int** matr1, int** matr2, int rows, int cols);
void multiplication(int** matr1, int** matr2, int rows, int cols, int rows2, int cols2);

int main()
{
	//make default value 1 so program will run. Could also be do-while.
	int userInput = 1;
	while (userInput > 0){

		int rowsA = 0,colA = 0,
			rowsB = 0, colB = 0;

		int** matrixA = 0;
		int** matrixB = 0;

		cout << "********************** Welcome to Matrix Calculator ***********************\n";
		cout << "Here you can perform Addition, Subtraction, and Multiplication on Matrices.\n\n";

		cout << "To enter the size and values of the matrx type: 1\n"
			"To read the size and values of the matrix from a file type: 2\n"
			<< "To exit the program, enter a negative number.\n";


		cin >> userInput; //Check if user is entering data or reading it from a file.

		if (userInput == 1) //Entering Data
		{
			//Get user input for size of Matrix A.
			cout << "Matrix A: Enter the size of rows and columns: ";
			cin >> rowsA >> colA;

			//Create a new 2D Array for Matrix A.
			matrixA = AllocateDynamicArray(rowsA, colA);


			//Get the values of the Matrix A.
			cout << "Enter the values of the matrix A: \n";
			for (int i = 0; i < rowsA; i++)
			{
				for (int j = 0; j < colA; j++)
					cin >> matrixA[i][j];
			}


			//Get user input for size of Matrix B.
			cout << "Matrix B: Enter the size of rows and columns: ";
			cin >> rowsB >> colB;

			//Create a new 2D Array for Matrix B.
			matrixB = AllocateDynamicArray(rowsB, colB);

			//Get the values of the Matrix A.
			cout << "Enter the values of the matrix B: \n";
			for (int i = 0; i < rowsB; i++)
			{
				for (int j = 0; j < colB; j++)
					cin >> matrixB[i][j];
			}

		}

		else if (userInput == 2) //Reading it from a File.
		{
			string a, b;

			//Get the name of the file that contains size of Matrix A.
			cout << "Enter the name of the file that contains the dimensions of matrix A, followed by the values:  ";
			cin >> a;


			ifstream file1(a); //New file variable.

			if (file1.is_open()) //Open the file.
			{
				//Read Data
				file1 >> rowsA;
				file1 >> colA;
				//Create a new 2D Array for Matrix A.
				matrixA = AllocateDynamicArray(rowsA, colA);
				for (int i = 0; i < rowsA; ++i){
					for (int j = 0; j < colA; ++j){
						file1 >> matrixA[i][j];
					}
				}
				file1.close();
			}

			else
			{
				cout << "Unable to open file";
				return 0;
			}

			//Get the name of the file that contains size of Matrix B.
			cout << "Enter the name of the file that contains the dimensions of matrix B, followed by the values:  ";
			cin >> b;

			ifstream file2(b); //New file variable.

			if (file2.is_open()) //Open the file.
			{
				//Read Data
				file2 >> rowsB;
				file2 >> colB;
				//Create a new 2D Array for Matrix B.
				matrixB = AllocateDynamicArray(rowsB, colB);
				for (int i = 0; i < rowsB; ++i){
					for (int j = 0; j < colB; ++j){
						file2 >> matrixB[i][j];
					}
				}
				file2.close();
			}

			else
			{
				cout << "Unable to open file";
				return 0;
			}
		}
		else //Wrong input
		{
			cout << "Error: Wrong Input. The input is case senstive. Please re-run the program.";
			system("PAUSE");
			return 0;
		}

		cout << "\nPlease choose from the following menu.\n\n";
		cout << "1.  Matrix Addition.\n";
		cout << "2.  Matrix subtraction.\n";
		cout << "3.  Matrix  Multiplication.\n";
		cout << "4.  End the program.\n";

		cin >> userInput;

		switch (userInput) //Check userInput.
		{
		case 1:
			if (rowsA == rowsB && colA == colB)
				addition(matrixA, matrixB, rowsA, colA);
			else
				cout << "Error: Both matrices need to be the same size.";
			break;

		case 2:
			if (colA == rowsB)
				subtraction(matrixA, matrixB, rowsA, colA);
			else
				cout << "Error: The size of Row B needs to equal to the size of Col B";
			break;

		case 3:
			if (colA == rowsB)
				multiplication(matrixA, matrixB, rowsA, colA, rowsB, colB);
			else
				cout << "Error: The size of Row B needs to equal to the size of Col B";
				break;
		case 4:
			//end the program
			return 0;
			break;
		default:
			cout << "You entered the wrong input.";
			return 0;
		}
	}
	system("PAUSE");
}
int **AllocateDynamicArray(int nRows, int nCols)
{
	int **dynamicArray;

	dynamicArray = new int*[nRows];
	for (int i = 0; i < nRows; i++)
		dynamicArray[i] = new int[nCols];

	return dynamicArray;
}
void addition(int**& matrixA, int**& matrixB, int rows, int cols)
{
	cout << "Addition of Matrix A and Matrix B is:\n";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << matrixA[i][j] + matrixB[i][j] << " ";
		}
		cout << "\n";

	}
}
void subtraction(int** matr1, int** matr2, int rows, int cols)
{
	cout << "Subtraction of Matrix A and Matrix B is:\n";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << matr1[i][j] - matr2[i][j] << " ";
		}
		cout << "\n";

	}
}
void multiplication(int** matr1, int** matr2, int rows, int cols, int rows2, int cols2)
{
	cout << "Multiplication of Matrix A and Matrix B is:\n";
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols2; j++) {
			int sum = 0;
			for (int inner = 0; inner < cols; inner++) {
				sum += matr1[i][inner] * matr2[inner][j];
			
			}
			cout << sum << " ";
		}
		cout << "\n";
	}
}
///////////////////////////////////////////////////////////////////////////////
/*
********************** Welcome to Matrix Calculator ***********************
Here you can perform Addition, Subtraction, and Multiplication on Matrices.

To enter the size and values of the matrx type: 1
To read the size and values of the matrix from a file type: 2
To exit the program, enter a negative number.
1
Matrix A: Enter the size of rows and columns: 2 3
Enter the values of the matrix A:
1
2
3
4
5
6
Matrix B: Enter the size of rows and columns: 3 2
Enter the values of the matrix B:
7
8
9
10
11
12

Please choosen from the following menu.

1.  Matrix Addition.
2.  Matrix subtraction.
3.  Matrix  Multiplication.
4.  End the program.
3
Multiplication of Matrix A and Matrix B is:
58 64
139 154
********************** Welcome to Matrix Calculator ***********************
Here you can perform Addition, Subtraction, and Multiplication on Matrices.

To enter the size and values of the matrx type: 1
To read the size and values of the matrix from a file type: 2
To exit the program, enter a negative number.
-1
Error: Wrong Input. The input is case senstive. Please re-run the program.Press
any key to continue . . .
///////////////////////////////////////////////////////////////////////////////
********************** Welcome to Matrix Calculator ***********************
Here you can perform Addition, Subtraction, and Multiplication on Matrices.

To enter the size and values of the matrx type: 1
To read the size and values of the matrix from a file type: 2
To exit the program, enter a negative number.
2
Enter the name of the file that contains the dimensions of matrix A, followed by
the values:  C:\Users\Stevo\Desktop\matrixA.txt
Enter the name of the file that contains the dimensions of matrix B, followed by
the values:  C:\Users\Stevo\Desktop\matrixB.txt

Please choosen from the following menu.

1.  Matrix Addition.
2.  Matrix subtraction.
3.  Matrix  Multiplication.
4.  End the program.
3
Multiplication of Matrix A and Matrix B is:
58 64
139 154
********************** Welcome to Matrix Calculator ***********************
Here you can perform Addition, Subtraction, and Multiplication on Matrices.

To enter the size and values of the matrx type: 1
To read the size and values of the matrix from a file type: 2
To exit the program, enter a negative number.
-1
Error: Wrong Input. The input is case senstive. Please re-run the program.Press
any key to continue . . .
*/
