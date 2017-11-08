/*
	Optimized Matrix Multiplication
	by: Sean Groebe

	Optimized Matrix Multiplication Chain
	Prints out Total Cost and corresponding K-Table
	O(n^3)
*/



#include <iostream>

using namespace std;

void printMatrix(int** array, int row, int col);
void printOptimalParens(int** kArray, int i, int j);

int main()
{
   int numMat;
   cout<<"Please enter the Number of Matricies: ";
   cin>>numMat;

   int *p;
   int psize = numMat + 1;
   p = new int[psize];

   cout<<"Pleeeeease enter in your dimensions: ";
   for(int i = 0; i < psize; i++)
   {
      cout<<"P"<<i<<" : ";
      cin>>p[i];
   }

   //an array which holds the cost table
   int **cost;
   cost = new int*[psize];  // sets up an array of row pointers
   for(int i =0; i < psize; i++)
   {
       cost[i] = new int[psize]; // allocates each row of the grades array
   }

   //an array which holds the splits
   int ** kArray;
   kArray = new int*[psize];
   for(int i=0; i<(psize); i++)
   {
      kArray[i]=new int[psize];
   }

   for(int length = 1; length < numMat; length++)
   {
      for(int i = 1; i<numMat-length + 1; i++)
      {

         int j = i+ length;
     int tempCost;
     int k = i;
     int minCost = cost[i][k] + cost[k+1][j] + p[i-1]*p[k]*p[j];
     int kay = i;
     for(; k<j; k++)
     {
       tempCost = cost[i][k] + cost[k+1][j] + p[i-1]*p[k]*p[j];
       if(tempCost<minCost)
       {
          minCost = tempCost;
          kay = k;
       }
     }

    cost[i][j] = minCost;
    kArray[i][j] = kay;
      }
   }

   cout<<"\nTotal Cost Table\n************************************"<<endl;
   printMatrix(cost, psize, psize);

   cout<<"Corresponding K-Table\n***********************************"<<endl;
   printMatrix(kArray,psize,psize);

   cout<<endl<<endl;
   cout<<"This corresponds to the following multiplication chain"<<endl;
   printOptimalParens(kArray, 1, numMat);
   cout<<endl;
   return 0;
}

void printMatrix(int** array, int row, int col)
{
   for(int i = 1; i<row; i++)
   {
      for(int j=1; j<col; j++)
         cout<<array[i][j]<<"\t|\t";
      cout<<endl;
   }
}

void printOptimalParens(int** kArray, int i, int j)
{
   if(i==j)
    {
       cout<<"A"<<i<<" ";
    }
    else
    {
       cout<<"(";
       printOptimalParens(kArray,i, kArray[i][j]);
       printOptimalParens(kArray, kArray[i][j] + 1, j);
       cout<<")";
    }
}
