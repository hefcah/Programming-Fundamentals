
#include <iostream>
#include <string>
using namespace std;
void start();
void clearboard(char table[][8], int rows, int columns);
void queen(char arr[][8], int size, string chess);
void rook(char arr[][8], int size, string chess);
void king(char arr[][8], int size, string chess,string vs);
void knight(char arr[][8], int size, string chess);
void bishop(char arr[][8], int size, string chess);
void display(char table[][8], int rows, int columns);

int main() {
	start();
    return 0;
}
void start()
{
	string vs="";
    string chess;
    char arr[8][8];
    cout<<"\t\t>>>>>>>>>>Initial board<<<<<<<<"<<endl;
	clearboard(arr,8,8);
    display(arr, 8, 8);
    cout << "Please choose any of: king, queen, bishop, rook or knight" << endl;
    cin >> chess;
    if (chess == "queen") {
        queen(arr, 8, chess);
    } else if (chess == "rook") {
        rook(arr, 8, chess);
    } else if (chess == "king") {
        king(arr, 8,  chess, vs);
    } else if (chess == "bishop") {
        bishop(arr, 8, chess);
    } else if (chess == "knight") {
        knight(arr, 8,  chess);
    }

    cout<<"please chose the opponent of king among: queen, bishop, rook or knight"<<endl;
    cin>>vs;
	king(arr, 8, chess,vs);
}
void display(char table[][8], int rows, int columns) {
    cout << "_________________" << endl;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout<<"|" << table[i][j];
        }
        cout <<"|"<< endl;
        
    }
    cout<<endl;
}
void clearboard(char table[][8], int rows, int columns)
{
	for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            table[i][j] = '_';
        }
    }
}
void queen(char arr[][8], int size, string chess) {
    int x, y;
        cout << "Please enter the initial position of queen" << endl;
        cout << "Rows: ";
        cin >> x;
        cout << "Columns: ";
        cin >> y;
        
        for (int i = 0; i < 8; i++) {
        	if(arr[x][i]=='K'||arr[i][y]=='K')
            {
            	cout<<"\t\t>>>>>>>>>>check Mate<<<<<<<<<"<<endl;
			}
            arr[x][i] = '*';
            arr[i][y] = '*';
        }
        for (int i = 1; x + i < 8 && y + i < 8; i++) {
            if(arr[x + i][y + i]=='K')
            {
            	cout<<"\t\t>>>>>>>>>>check Mate<<<<<<<<<"<<endl;
			}
			arr[x + i][y + i] = '*';
        }
        for (int i = 1; x - i >= 0 && y - i >= 0; i++) {
        	if(arr[x - i][y - i]=='K')
            {
            	cout<<"\t\t>>>>>>>>>>check Mate<<<<<<<<<"<<endl;
			}
            arr[x - i][y - i] = '*';
        }
        for (int i = 1; x + i < 8 && y - i >= 0; i++) {
        	if(arr[x + i][y - i]=='K')
            {
            	cout<<"\t\t>>>>>>>>>>check Mate<<<<<<<<<"<<endl;
			}
            arr[x + i][y - i] = '*';
        }
        for (int i = 1; x - i >= 0 && y + i < 8; i++) {
        	if(arr[x - i][y + i]=='K')
            {
            	cout<<"\t\t>>>>>>>>>>check Mate<<<<<<<<<"<<endl;
			}
            arr[x - i][y + i] = '*';
        }
        arr[x][y] = 'Q';
        display(arr, 8, 8);
        clearboard(arr,8,8);
        
    
}
void rook(char arr[][8],int size,string chess)
{
    int x, y;

        cout << "Please enter the initial position of rook" << endl;
        cout << "Rows: ";
        cin >> x;
        cout << "Columns: ";
        cin >> y;
        for (int i = 0; i < 8; i++) {
        	if(arr[x][i]=='K'||arr[i][y]=='K')
            {
            	cout<<"\t\t>>>>>>>>>>check Mate<<<<<<<<<"<<endl;
			}
            arr[x][i] = '*';
            arr[i][y] = '*';
        }
        arr[x][y] = 'R';
        display(arr, 8, 8);
        clearboard(arr,8,8);
}
void king(char arr[][8], int size, string chess, string vs)
{
    int x, y,count=0;
    while (chess != "finish")
    {
    	count++;
    	if(count==1)
    	{
        cout << "Please enter the initial position of king" << endl;
        cout << "Rows: ";
        cin >> x;
        cout << "Columns: ";
        cin >> y;
    	}
    	


        arr[x][y] = 'K';
        arr[x + 1][y] = '*';
        arr[x - 1][y] = '*';
        arr[x][y + 1] = '*';
        arr[x][y - 1] = '*';
        arr[x + 1][y + 1] = '*';
        arr[x + 1][y - 1] = '*';
        arr[x - 1][y + 1] = '*';
        arr[x - 1][y - 1] = '*';
        if(count!=1)
    	{
    	if(arr[x + 1][y] == '*')
    	arr[x + 1][y]='_';
        if(arr[x - 1][y] == '*')
        arr[x - 1][y]='_';
        if(arr[x][y + 1] == '*')
        arr[x][y + 1]='_';
        if(arr[x][y - 1] == '*')
        arr[x][y - 1] = '_';
        if(arr[x + 1][y + 1] == '*')
        arr[x + 1][y + 1] = '_';
        if(arr[x + 1][y - 1] == '*')
        arr[x + 1][y - 1] = '_';
        if(arr[x - 1][y + 1] == '*')
        arr[x - 1][y + 1] = '_';
        if(arr[x - 1][y - 1] == '*')
        arr[x - 1][y - 1] = '_';
//		}
//        if(count!=1)
//		{
		if(arr[x][y]=='K')
    	arr[x][y]='*';
			cout<<"Enter the position you want to move the king"<<endl;
			cout<<"Enter Row"<<endl;
			cin>>x;
			cout<<"Enter column"<<endl;
			cin>>y;
			arr[x + 1][y] = '*';
    	    arr[x - 1][y] = '*';
        	arr[x][y + 1] = '*';
	        arr[x][y - 1] = '*';
    	    arr[x + 1][y + 1] = '*';
        	arr[x + 1][y - 1] = '*';
	        arr[x - 1][y + 1] = '*';
    	    arr[x - 1][y - 1] = '*';
			arr[x][y]='K';

		}
		
        if (vs == "queen")
        {
            queen(arr, 8, chess);
        }
        if(vs=="rook")
		{
			rook(arr, 8, chess);
		}
        if(vs=="knight")
		{
			knight(arr, 8, chess);
		}
		if(vs=="bishop")
		{
			bishop(arr, 8, chess);
		}
		if(count==1)
		{
        display(arr, 8, 8);
        clearboard(arr, 8, 8);
		}
		string more;

        cout << "If end finish else cont" << endl;
        cin >> more;
        if (more == "cont")
        {
            continue;
        }
        else
        {
            break;
        }
    }
}
void knight(char arr[][8],int size,string chess)
{
    int x, y;

        cout << "Please enter the initial position of knight" << endl;
        cout << "Rows: ";
        cin >> x;
        cout << "Columns: ";
        cin >> y;
        arr[x][y] = 'k';
        if(arr[x+2][y+1]=='K'||arr[x+2][y-1]=='K'||arr[x-2][y-1]=='K'||arr[x-2][y+1]=='K'||arr[x+1][y+2]=='K'||arr[x-1][y+2]=='K'||arr[x-1][y-2]=='K'||arr[x+1][y-2]=='K')
            {
            	cout<<"\t\t>>>>>>>>>>check Mate<<<<<<<<<"<<endl;
			}
            arr[x+2][y+1] = '*';
            arr[x+2][y-1] = '*';
            arr[x-2][y-1] = '*';
            arr[x-2][y+1] = '*';        
            arr[x+1][y+2] = '*';
            arr[x-1][y+2] = '*';
            arr[x-1][y-2] = '*';
            arr[x+1][y-2] = '*';
        display(arr, 8, 8);
		clearboard(arr,8,8);

}
void bishop(char arr[][8],int size,string chess)
{
    int x, y;

        cout << "Please enter the initial position of bishop" << endl;
        cout << "Rows: ";
        cin >> x;
        cout << "Columns: ";
        cin >> y;
        arr[x][y] = 'B';
        for (int i = 1; x + i < 8 && y + i < 8; i++) {
            arr[x + i][y + i] = '*';
        }
        for (int i = 1; x - i >= 0 && y - i >= 0; i++) {
            arr[x - i][y - i] = '*';
        }
        for (int i = 1; x + i < 8 && y - i >= 0; i++) {
            arr[x + i][y - i] = '*';
        }
        for (int i = 1; x - i >= 0 && y + i < 8; i++) {
            arr[x - i][y + i] = '*';
        }
        display(arr, 8, 8);
        clearboard(arr,8,8);

}