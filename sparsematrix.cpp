#include<iostream>
using namespace std;
#define SROW 50
#define MROW 20
#define MCOL 20
int main( )
{
    int mat[MROW][MCOL],sparse[SROW][3];
    int i,j,nzero=0,mr,mc,sr,s,elem;
    cout<<"Enter number of rows:\n";
    cin>>mr;
    cout<<"Enter number of columns:\n";
    cin>>mc;
    cout<<"Enter the matrix\n";
    for(i=1;i<=mr;i++)
    {
        for(j=1;j<=mc;j++)
        {
            cin>>mat[i][j];
            if(mat[i][j] != 0)
            {
                nzero++;
            }
        }
    }
    sr=nzero+1;
    sparse[1][1]=mr;
    sparse[1][2]=mc;
    sparse[1][3]=nzero;
    s=2;
    for(i=1;i<=mr;i++)
    {
        for(j=1;j<=mc;j++)
        {   
            if(mat[i][j] != 0 )
            {
                sparse[s][1]=i;
                sparse[s][2]=j;
                sparse[s][3]=mat[i][j];
                s++;
            }
        }
    }
    cout<<"the sparse matrix is \n";
    for(i=1;i<=sr;i++)
    {
        for(j=1;j<=3;j++)
        {
            cout<<sparse[i][j];
        }
        cout<<"\n";
    }
    cout<<"Enter the element to be searched \n";
    cin>>elem;
    for(i=2;i<=sr;i++)
        {   
        if(sparse[i][3]==elem)
        {  
        cout<<"Element found at"<< sparse[i][1] << " " << sparse[i][2] << endl;
        
        return 1;
        } 
    }
    printf("Element not found");
    
    return 0;
}
