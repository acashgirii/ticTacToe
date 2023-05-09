#include<iostream>
using namespace std;

int printArr(char a[3][3])
{
    cout<<endl;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<"\t"<<a[i][j];
        }
        cout<<endl;
    }
}

int user2(char a[3][3], int m, int n)
{   
    if(m>2 || n>2)
    {
        cout<<"Error"<<endl;
    }
    else
    {
        a[m][n]='o';
        cout<<endl;
        printArr(a);
    }
}

bool user2Wins(char a[3][3])
{
    bool flag2=false;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(a[0][0]=='o' && a[1][1]=='o' && a[2][2]=='o')
            {
                flag2 = true;
            }
            else if(a[0][0]=='o' && a[0][1]=='o' && a[0][2]=='o')
            {
                flag2=true;
            }
            else if(a[1][0]=='o' && a[1][1]=='o' && a[1][2]=='o')
            {
                flag2=true;
            }
            else if(a[2][0]=='o' && a[2][1]=='o' && a[2][2]=='o')
            {
                flag2=true;
            }
            else if(a[0][0]=='o' && a[1][0]=='o' && a[2][0]=='o')
            {
                flag2=true;
            }
            else if(a[0][1]=='o' && a[1][1]=='o' && a[2][1]=='o')
            {
                flag2 = true;
            }
            else if(a[2][0]=='o' && a[2][1]=='o' && a[2][2]=='o')
            {
                flag2=true;
            }
            else
            {
                flag2=false;
            }
        }
    }
    return flag2;
}

int userInput(char a[3][3], int x, int y)
{
    if(x>2 || y>2)
    {
        cout<<"Error"<<endl;
    }
    else
    {
        a[x][y]='x';
        printArr(a); 
    }
}

bool userWins(char a[3][3])
{
    bool flag=false;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(a[0][0]=='o' && a[1][1]=='x' && a[2][2]=='o')
            {
                flag = true;
            }
            else if(a[0][0]=='x' && a[0][1]=='x' && a[0][2]=='x')
            {
                flag=true;
            }
            else if(a[1][0]=='x' && a[1][1]=='x' && a[1][2]=='x')
            {
                flag=true;
            }
            else if(a[2][0]=='x' && a[2][1]=='x' && a[2][2]=='x')
            {
                flag=true;
            }
            else if(a[0][0]=='x' && a[1][0]=='x' && a[2][0]=='x')
            {
                flag=true;
            }
            else if(a[0][1]=='x' && a[1][1]=='x' && a[2][1]=='x')
            {
                flag = true;
            }
            else if(a[2][0]=='x' && a[2][1]=='x' && a[2][2]=='x')
            {
                flag=true;
            }
            else
            {
                flag=false;
            }
        }
    }
    return flag;
}

int actual(char mat[3][3], int x, int y, int m, int n)
{
    int flagstaff = false;
    while(flagstaff!=true)
    {
    cout<<"User1 Turn:"<<endl;
    cin>>x>>y;
    userInput(mat,x,y);
    bool x=userWins(mat);
    if(x==true)
    {
        break;
    }
    cout<<"User2 Turn:"<<endl;
    cin>>m>>n;
    user2(mat,m,n);
    bool y=user2Wins(mat);
    if(y==true)
    {
        break;
    }

    }
}

int main()
{
  
  char mat[3][3]={
                    {'-','-','-'},
                    {'-','-','-'},
                    {'-','-','-'}
                 };

    int x,y,m,n;

    cout<<"Initial Table: "<<endl;
    printArr(mat);

    bool flag = userWins(mat);
    bool flag2 = user2Wins(mat);
    actual(mat,x,y,m,n);

    if(flag==true)
    {
        cout<<"User One Wins!"<<endl;
    }
    else if(flag2==true)
    {
        cout<<"User Two Wins!"<<endl;
    }
    else if(flag==false && flag2==false)
    {
        cout<<"It Is A Tie!"<<endl;
    }
    //computer(mat);
}