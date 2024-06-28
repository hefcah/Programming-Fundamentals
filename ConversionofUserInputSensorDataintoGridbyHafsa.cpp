
#include <iostream>
using namespace std;

int main()
{
    int x=0, y=0;
    //integers take number of rows and columns as user input.
    
    cout<<"Enter number of rows\t:\t";
    cin>>x;
    cout<<"Enter number of columns\t:\t";
    cin>>y;
    cout<<"\n#######################################################\n";
    
    char array[x][y];//array according to user input.
    int on_counter=0;//integer that counts number of entries that are on.
    
    //user inputs array data.
    cout<<"Enter censor data:\n";
    for(int i=0; i<x; i++)
    {
        for(int j=0; j<y; j++)
        {
            cout<<"Array["<<i+1<<"]["<<j+1<<"]:";
            cin>>array[i][j];
        }
    }
    cout<<"\n#######################################################\n";
    
    //Displays the grid with a suitable display.
    cout<<"\n\n\nUser Grid:\n\n";
    for(int i=0; i<x; i++)
    {
        for(int j=0; j<y; j++)
        {
           cout<<array[i][j]<<"\t";
        }
        cout<<endl;
    }
    
    cout<<"\n#######################################################\n";
    //Converts the digits to symbols.
    cout<<"\n\nSensor Grid:\n\n";
    for(int i=0; i<x; i++)
    {
        for(int j=0; j<y; j++)
        {
           if(array[i][j]=='0')
           {
               array[i][j]='.';
           }
           else if(array[i][j]=='1')
           {
               array[i][j]='X';
               on_counter++;
               //counts how many times the sensor was on.
           }
        }
    }
    
    //final display of array.
    for(int i=0; i<x; i++)
    {
        for(int j=0; j<y; j++)
        {
           cout<<array[i][j]<<"\t";
        }
        cout<<endl;
    }
    
    float percentage=0;
    //percantage formula used for calculation.
    //(given*100/total);
    percentage=(on_counter*100)/(x*y);
    //fina display of percentage.
    cout<<"\n\nPercentage of censors on the grid\t:\t"<<percentage;

    return 0;
}//end of the program.
