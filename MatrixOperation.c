#include<stdio.h>
// Write a program to multiply two matrices. Assume the dimensions of the matrices are compatible.
void MuloMatrx(int r1,int c1,int matrix1[r1][c1],int r2,int c2,int  matrix2[r2][c2],float mul[r1][c2]);
void AddoMatrix(int r,int c,int matrix1[r][c],int  matrix2[r][c]);
void SuboMatrix(int r,int c,int matrix1[r][c],int  matrix2[r][c]);
void StoreValue(int r1,int c1,int r2,int c2,int matrix1[r1][c1],int matrix2[r2][c2]);
int main() {
    int choice;
    int r1,c1;  //row of matrix 1 &  column of matrix 1
    int matrix1[r1][c1];
    int r2,c2;  //row of matrix 2 &  column of matrix 2
    int matrix2[r2][c2];
    do
    {
    printf("\n|-------------------Welcome to Matrix Operations Program----------------|\n");
    printf("What Operation you want to perform ?\n(Enter the number enclosed before the choice)\n(1) Addition of Matrices\n(2) Subtraction of Matrices\n(3) Multiplication of Matrices\n(4) Exit\n");
    scanf("%d", &choice);
        switch (choice)
    {
    case 1:
    printf("Enter the number rows of matrix : ");
    scanf("%d",&r1);
    printf("Enter the number columns of matrix : ");
    scanf("%d",&c1);
    StoreValue(r1,c1,r1,c1,matrix1,matrix2);
    AddoMatrix(r1,c1,matrix1,matrix2);
        break;

    case 2:
    printf("Enter the number rows of matrix : ");
    scanf("%d",&r1);
    printf("Enter the number columns of matrix : ");
    scanf("%d",&c1);
    StoreValue(r1,c1,r1,c1,matrix1,matrix2);
    SuboMatrix(r1,c1,matrix1,matrix2);
        break;

    case 3:
    printf("Enter the number rows of matrix1 : ");
    scanf("%d",&r1);
    printf("Enter the number columns of matrix1 : ");
    scanf("%d",&c1);
    printf("Enter the number rows of matrix2 : ");
    scanf("%d",&r2);
    printf("Enter the number columns of matrix2 : ");
    scanf("%d",&c2);
        if (c1==r2) // Criteria for Matrix Multiplication ,If true
    {
        float mul[r1][c2]; // Defining new matrix as it will be Storing values from Multiplication
        MuloMatrx(r1,c1,matrix1,r2,c2,matrix2,mul); // calling multiplication  performing function
    }
    else{
        printf("The Matrix Multiplication Cannot Performed"); // Matrix Multiplication is not Possible.
    }
        break;
    
    case 4:
        break;

    default:
    printf("\n--------------------------------------------------\nError : Please Input from the given choices Only!\n--------------------------------------------------\n");
        break;
    }
    } while (choice);
    
    
    return 0;
}

void StoreValue(int r1,int c1,int r2,int c2,int matrix1[r1][c1],int matrix2[r2][c2]) {
    for (int  i = 0; i < r1 ; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            printf("Enter the Matrix1 '%d%d' value : ",i,j);
            scanf("%d",&matrix1[i][j]);  // storing values in matrix1 for performing operations
        }
    }

    for (int  i = 0; i < r2 ; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            printf("Enter the Matrix2 '%d%d' value : ",i,j);
            scanf("%d",&matrix2[i][j]);  // storing values in matrix2 for performing operations
        }
    }
    return ;
}

void AddoMatrix(int r,int c,int matrix1[r][c],int  matrix2[r][c]) {
    int sumomatrices[r][c];
    printf("\n|----------Let's Do Matrix Addition----------|\n");
    for (int  i = 0; i < r ; i++)
    {
        for (int j = 0; j < c; j++)
        {
            sumomatrices[i][j] = matrix1[i][j] + matrix1[i][j] ;
        }
    }
    printf("The Resulting Matrix : -\n") ;
    for (int  i = 0; i < r ; i++)
    {
        printf("|");
        for (int j = 0; j < c; j++)
        {
            printf(" %d",sumomatrices[i][j]) ;
            if (j ==(c-1))
            {
                printf("|\n");
            }
        }
    }
    return ;
}

void SuboMatrix(int r,int c,int matrix1[r][c],int  matrix2[r][c]) {
    int subomatrices[r][c];
    printf("\n|----------Let's Do Matrix Subtraction----------|\n");
    for (int  i = 0; i < r ; i++)
    {
        for (int j = 0; j < c; j++)
        {
            subomatrices[i][j] = matrix1[i][j] - matrix1[i][j] ;
        }
    }
    printf("The Resulting Matrix : -\n") ;
    for (int  i = 0; i < r ; i++)
    {
        printf("|");
        for (int j = 0; j < c; j++)
        {
            printf(" %d",subomatrices[i][j]) ;
            if (j ==(c-1))
            {
                printf("|\n");
            }
        }
    }
    return ;
}

void MuloMatrx(int r1,int c1,int matrix1[r1][c1],int r2,int c2,int matrix2[r2][c2],float mul[r1][c2]) {
    // Intiallizing Each Element to 0 For Avoiding garbage values from memory
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            mul[i][j] = 0 ;
        }
        
    }
    
    for (int i = 0; i < r1 ; i++) // outter loop for number of rows in formed Matrix after matrix Multiplication
    {
        for (int j = 0; j < c2; j++) // inner loop for number of columns in formed after the matrix Multiplication
        {
          for (int k = 0; k < c1; k++) //  Loop for Increamenting first Matrix column  & second Matrix rows (as same) 
          {
             mul[i][j] += matrix1[i][k]*matrix2[j][k] ;
          }
          
        }
        
    }
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("The '%d%d' index value is : %f\n",i,j,mul[i][j]); // printing value stored in resulting matrix
        }
    }
}