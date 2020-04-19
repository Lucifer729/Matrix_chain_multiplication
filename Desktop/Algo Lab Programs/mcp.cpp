#include<iostream>
#include<limits.h>
 using namespace std;
int b[100][100] ;
int m[100][100];
	void printOrder(int i,int j){
 	if(i==j){
 		cout<<"A"<<i;
	 }
	 else
   {
      cout<<"( ";
      printOrder(i,b[i][j]);
      printOrder(b[i][j]+1,j);
      cout<<" )";
   }
}

  void printMat(int n) {
        cout<<"\nMatrix m:"<<endl;
        for (int i=1;i<n;i++) {
            for (int j=1;j<n;j++) {
                if(i<=j)
                    cout<<m[i][j]<<"\t";
                else
                    cout<<"\t";
            }
            cout<<endl;
        }
        
        cout<<"\nMatrix b:"<<endl;
        for (int i=1;i<n;i++) {
            for (int j=1;j<n;j++) {
                if(i<=j)
                    cout<<b[i][j]<<"\t";
                else
                    cout<<"\t";
            }
            cout<<endl;
        }
    }


int MatrixChainMultiplication(int p[], int n)
{
    cout<<"number= "<<n<<endl;
    int i,j,k,L,q;
 
    for (i=1;i<n;i++)
        m[i][i]=0;    
    for (L=2; L<n; L++)
    {
        for (i=1; i<n-L+1; i++)
        {
            j = i+L-1;
            m[i][j] = INT_MAX;  
 
            for (k=i; k<=j-1; k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]; 
                if (q < m[i][j])
                {
                    m[i][j] = q;    
                    b[i][j]=k;
                    printMat(n);
                }
            }
        }
    }
 
    return m[1][n-1]; 
}

 
int main()
{
//    int n,i,rows[],col[];
//    cout<<"Enter number of matrices\n";
//    cin>>n;
//    for(i=0;i<n;i++){
//    	cout<<"enter the no of rows for matrix"<<i<<"-->";
//    	cin>>rows[i];
//    	if(rows[i]!=col[i]){
//    		cout<<"wrong input";		}
//    	cout<<"enter the no of columns for matrix"<<i<<"-->";
//    	cin>>col[i];
//
//	}
//    int arr[n];
//    cout<<"Enter dimensions \n";
//    for(i=0;i<=n;i++)
//    {
////        cout<<"Enter d"<<i<<" :: ";
////        cin>>arr[i];
//    }
// 

		int n,row,col;
		cout<<"Enter number of matrices to be multiplied: "<<endl;
    	cin>>n;
    	n=n+1;
    	int arr[n];
    	       //int temp=num;
        for(int i=0;i<n-1;i++){
            cout<<"Enter the number of rows of matrix "<<i<<":";
            cin>>row;
            cout<<"Enter the number of Columns of matrix "<<i<<":";
        	cin>>col;
            if(i==0){
                arr[0]=row;
                arr[1]=col;
            }
            else if(arr[i]!=row){
                    cout<<"Wrong number of rows for matrix multiplication.--> number of rows now set as "<<arr[i]<<endl;
                    arr[i+1]=col;
                }
            else{
                arr[i+1]=col;
            }
        }
            cout<<"array:"<<endl;
             for(int j=0;j<n;j++){
                cout<<arr[j]<<" ";
            }
            cout<<endl;


    int size = sizeof(arr)/sizeof(arr[0]);
 	
 	
 	
	cout<<"Minimum number of multiplications is "<<MatrixChainMultiplication(arr, size)<<endl;
	cout<<"order in which matrices should be multiplied is-->";
	printOrder(1,n-1);
	printMat(n);
    return 0;
}
