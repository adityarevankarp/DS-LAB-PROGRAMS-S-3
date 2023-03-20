#include<iostream>

#include<stdlib.h>
#define MAXSIZE 10
using namespace std;
int insertion(int item, int a[ ], int n)
{
    int c,p;
    if(n==MAXSIZE)
    {
        cout << "HEAP IS FULL!!!\n";
        
    }
    c=n;
    p=(c-1)/2;
    while(c!=0&&item>a[p])
    {
        a[c]=a[p];
        c=p;
        p=(c-1)/2;
    }
    a[c]=item;
    return n+1;
}
void display(int a[ ], int n)
{
    int i;
    if(n==0)
    {
        cout << "HEAP IS EMPTY!!!\n";
        return;
    }
    cout << "The array elements are \n";
    for(i=0;i<n;i++)
        cout << a[i] <<endl;
}

int main()
{
    int a[MAXSIZE],n=0,ch,item;
    for(;;)
    {
        cout << "\n1.INSERT\n    2.DISPLAY\n    EXIT\n";
        cin >> ch;
        switch(ch)
        {
            case 1:	
                cout << "Enter the element";
                cin >> item;
                n=insertion(item,a,n);
            break;
            case 2:
                display(a,n);
            break;
            default:exit(0);       
        }
    }
}
