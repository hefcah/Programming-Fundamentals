
#include <iostream>
using namespace std;

int main()
{
    const int rows=15;
    const int columns=30;
    char seats[rows][columns];
    int row_prices[rows];
    int total_price=0, seat_price=0;
    int sold=0;
    int row_seats[rows]; 
    int rn=0;
    
    cout<<"Enter ticket prices for each row.\n";
    for(int i=0; i<rows; i++)
    {
        cout<<"Row # "<<i+1<<":";
        cin>>row_prices[i];
    }
    
    int tickets=0;
    cout<<"Enter number of tickets you want to book\t:\t";
    cin>>tickets;
    
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<columns; j++)
        {
            seats[i][j]='#';
        }
    }
    
    int x=0, y=0;
    for(int i=0; i<tickets; i++)
    {
        cout<<"\nBooking for ticket no. "<<i+1<<endl;
        cout<<"Number of row\t:\t";
        cin>>x;
        cout<<"Number of column\t:\t";
        cin>>y;
        if(seats[x][y]!='*') 
        {
            seats[x][y]='*';
            cout<<"Seat price\t:\t"<<row_prices[x]<<endl;
            total_price+=row_prices[x];
            sold++;
        }
        else
        {
            cout<<"\nInvalid input.\n";
        }
    }
    
    for(int i=0; i<rows; i++)
    {
        row_seats[i]=0;   
        for(int j=0; j<columns; j++)
        {
            if(seats[i][j]=='*')
            {
                row_seats[i]++;
            }
        }
    }
    
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<columns; j++)
        {
            cout<<seats[i][j]<<"\t";
        }
        cout<<endl;
    }
    
    cout<<"Menu\n1.How many seats booked.\n2How many seats booked in a row.\n3How many seats booked in the auditorium.\n";
    int choice=0;
    cin>>choice;
    
    switch(choice)
    {
        case 1:
            cout<<"Total seats booked\t:\t"<<sold<<endl;
            cout<<"Total money generated\t:\t"<<total_price;
        break;
        
        case 2:
            cout<<"Enter row number\t:\t";
            cin>>rn;
            cout<<"Seats booked per row:\n";
            cout<<row_seats[rn];
            
            cout<<"Available seats in the row\t:\n";
            for(int i=0; i<columns; i++)
            {
                if(seats[rn][i]!='*')
                {
                    cout<<seats[rn][i]<<endl;
                }
                
            }
        break;
        
        case 3:
            cout<<"Seats booked in the auditorium\t:\t"<<sold<<endl;
            cout<<"Total empty seats\t:\t"<<(30*15)-sold;
            cout<<"Seats available\t:\t";
            for(int i=0; i<rows; i++)
            {
                for(int j=0; j<columns; j++)
                {
                   if(seats[i][j]!='*')
                   {
                       cout<<seats[i][j]<<endl;
                   }
                }
                
            }
        break;
        
        default:
            cout<<"Invalid Input.\n";
        break;    
    }
}
