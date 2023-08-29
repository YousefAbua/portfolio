/******************************************************************************

BattleShip
by Yousef Abualeinan
//
// This is a representation of the game "Battleship"
//

*******************************************************************************/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

// Print the Board
void PrintBoard(vector<vector<char>>playerBoard, int size) {
    
    // Number for the Columns
    for (int i = 0; i < size; ++i) {
        printf("\033[1;33m"); // bold yellow
        cout << "\t" << i+1;
    }
    cout << "\n\t\n";
    
    // Printing blank board
    for(int i=0; i<size; i++) {
        // letter for the Rows
        printf("\033[1;33m");  // bold yellow
        cout << (static_cast<char>('A'+i)) << "\t";
        for(int j=0; j<size; j++){
            printf("\033[0m"); // reset
            cout << playerBoard[i][j] << "\t";
        }
        cout << "\n\t\n";
    }
}

// Select the map
void MapSelection(int size, vector<vector<char>>&board) {
    int boardNum = rand()%3;
    // Easy
    if (size == 6) {
        if (boardNum == 0) {
    	
        	// 2 Long ship
        	board[0][0] = 1;
        	board[1][0] = 1;
        
        	// 3 Long ship
        	for (int i = 0; i < 3; i++) {
        	    board[2+i][2] = 1;
        	}
        	
        	// 3 Long ship
    	    for (int i = 0; i < 3; i++) {
    	        board[0][2+i] = 1;
    	    }
        
        	// 4 Long ship
        	for (int i = 0; i < 4; i++) {
        		board[1+i][5] = 1;
        	}
        
        	// 5 Long ship
        	for (int i = 0; i < 5; i++) {
        		board[5][0+i] = 1;
        	}
        }
	    else if (boardNum == 1) {
	    
    	    // 2 Long ship
    	    board[2][0] = 1;
    	    board[3][0] = 1;
    	    
    	    // 3 Long ship
    	    for (int i = 0; i < 3; ++i) {
    	        board[0+i][4] = 1;
    	    }
    	    
    	    // 3 Long ship
    	    for (int i = 0; i < 3; ++i) {
    	        board[2+i][5] = 1;
    	    }
    	    
    	    // 4 Long ship
    	    for (int i = 0; i < 4; ++i) {
    	        board[5][0+i] = 1;
    	    }
    	    
    	    // 5 Long ship
    	    for (int i = 0; i < 5; ++i) {
    	        board[0+i][2] = 1;
    	    }
    	}
    	else { 
    	    
    	    // 2 Long ship
    	    board[0][0] = 1;
    	    board[0][1] = 1;
    	    
    	    // 3 Long ship
    	    for (int i = 0; i < 3; ++i) {
    	        board[5][0+i] = 1;
    	    }
    	    
    	    // 3 Long ship
    	    for (int i = 0; i < 3; ++i) {
    	        board[3][0+i] = 1;
    	    }
    	    
    	    // 4 Long ship
    	    for (int i = 0; i < 4; ++i) {
    	        board[4][0+i] = 1;
    	    }
    	    
    	    // 5 Long ship
    	    for (int i = 0; i < 5; ++i) {
    	        board[1][0+i] = 1;
    	    }
    	}
    }
    // Medium
    else if (size == 8) {
        if (boardNum == 0) {
            // 2 Long Ship
            board[6][5] = 1;
            board[6][6] = 1;
            
            // 3 Long Ship
            for (int i = 0; i < 3; ++i) {
                board[7][0+i] = 1;
            }
            
            // 3 Long Ship
            for (int i = 0; i < 3; ++i) {
                board[3+i][0] = 1;
            }
            
            // 4 Long Ship
            for (int i = 0; i < 4; ++i) {
                board[1+i][7] = 1;
            }
            
            // 5 Long Ship
            for (int i = 0; i < 5; ++i) {
                board[0][0+i] = 1;
            }
        }
        else if (boardNum == 1) {
            // 2 Long Ship
            board[1][2] = 1;
            board[1][3] = 1;
            
            // 3 Long Ship
            for (int i = 0; i < 3; ++i) {
                board[1+i][6] = 1;
            }
            
            // 3 Long Ship
            for (int i = 0; i < 3; ++i) {
                board[0+i][0] = 1;
            }
            
            // 4 Long Ship
            for (int i = 0; i < 4; ++i) {
                board[6][4+i] = 1;
            }
            
            // 5 Long Ship
            for (int i = 0; i < 5; ++i) {
                board[4][0+i] = 1;
            }
        }
        else {
            // 2 Long Ship
            board[5][6] = 1;
            board[5][7] = 1;
            
            // 3 Long Ship
            for (int i = 0; i < 3; ++i) {
                board[7][0+i] = 1;
            }
            
            // 3 Long Ship
            for (int i = 0; i < 3; ++i) {
                board[1+i][6] = 1;
            }
            
            // 4 Long Ship
            for (int i = 0; i < 4; ++i) {
                board[0+i][2] = 1;
            }
            
            // 5 Long Ship
            for (int i = 0; i < 5; ++i) {
                board[1+i][0] = 1;
            }
        }
    }
    // Hard
    else {
        if (boardNum == 0) {	
            // 2 Long Ship
            board[4][0] = 1; 
            board[5][0] = 1;
            
            // 3 Long Ship
            for (int i = 0; i < 3; i++){ 
                board[4][6+i] = 1;
            }
            
            // 3 Long Ship
            for (int i = 0; i < 3; ++i) {
                board[5+i][3] = 1;
            }
            
            // 4 Long Ship
            for (int i = 0; i < 4; i++){ 
                board[2][3+i] = 1;
            }
        
            
            // 5 Long Ship
            for (int i = 0; i < 5; i++){ 
                board[9][5+i] = 1;
            }
        }
        else if (boardNum == 1) {
            // 2 Long Ship
            board[2][2] = 1; 
            board[2][3] = 1;
            
            // 3 Long Ship
            for (int i = 0; i < 3; i++){ 
                board[2+i][9] = 1;
            }
            
            // 3 Long Ship
            for (int i = 0; i < 3; ++i) {
                board[9][7+i] = 1;
            }
            
            // 4 Long Ship
            for (int i = 0; i < 4; i++){ 
                board[8][0+i] = 1;
            }
        
            
            // 5 Long Ship
            for (int i = 0; i < 5; i++){ 
                board[5][3+i] = 1;
            }
        }
        else {
            // 2 Long Ship
            board[8][2] = 1; 
            board[8][3] = 1;
            
            // 3 Long Ship
            for (int i = 0; i < 3; i++){ 
                board[6][6+i] = 1;
            }
            
            // 3 Long Ship
            for (int i = 0; i < 3; ++i) {
                board[3+i][3] = 1;
            }
            
            // 4 Long Ship
            for (int i = 0; i < 4; i++){ 
                board[2][5+i] = 1;
            }
        
            
            // 5 Long Ship
            for (int i = 0; i < 5; i++){ 
                board[9][5+i] = 1;
            }
        }
    }
}

// Count the ramining slots to attack
int ShipCounter(vector<vector<char>>board){
    int counter = 0;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board.size(); ++j) {
            if (board[i][j] == 1) {
                counter+=1;
            }
        }
    }
    return counter;
}

// Check if the attack is a hit
void Attack(vector<vector<char>>board, vector<vector<char>>&playerBoard, int x, int y, int &counter){
    if (board[x][y] == 1) {
        playerBoard[x][y] = 'H';
        PrintBoard(playerBoard, playerBoard.size());
        printf("\033[1;32m"); // bold green
        cout << "Hit! Next Target\n";
        printf("\033[0m"); // reset
        counter -= 1;
    }
    else {
        playerBoard[x][y] = 'M';
        PrintBoard(playerBoard, playerBoard.size());
        printf("\033[1;31m"); // bold red
        cout << "Miss! Try Again!\n";
        printf("\033[0m"); // reset 
    }
}

int main() {
    srand(time(0));
    char x;
    int y;
    string play;
    string difficulty;
    string userName;
    int numShipsLeft = 0;
    int size = 0;
    
    printf("\033[1;35m"); // bold magenta
    cout << "Would you like to play Battleship? Yes or No? ";
    printf("\033[0m"); // reset
    cin >> play;
   
    // Loops to ask the player at the end if they want to play again
    while ((play == "yes")||(play == "Yes")||(play == "YES")||(play == "YEs"||(play == "YeS"))) {
        // Stores the name of the player
        printf("\033[1;35m"); // bold magenta
        cout << "\nWhat is your name (no spaces)? ";
        printf("\033[0m"); // reset
        cin >> userName;
        
        // Welcomes the player
        printf("\033[1;36m"); // bold cyan
        cout << "\n=-=-=-=-=-=-=  Welcome to Battleship " << userName << " =-=-=-=-=-=-=\n";
    	printf("\033[0m"); // reset
    	cout << "The O represents the unknown sea\nA missed target will turn into a M\nLand a hit and it will turn into a H\n\n\n";
        
        // Loops to force the player to enter a valid size
        while ((size != 6)&&(size!=8)&&(size!=10)) { 
        	cout << "Easy: 6x6 Board\nMedium: 8x8 Board\nHard: 10x10 Board\n";
        	printf("\033[1;35m"); // bold magenta
        	cout << "Enter Difficulty (Easy/Medium/Hard): ";
        	printf("\033[0m"); // reset
        	cin >> difficulty;
            
        	if ((difficulty == "easy") || (difficulty == "Easy")) {
        		size = 6;
        	} else if ((difficulty == "medium") || (difficulty == "Medium")) {
        		size = 8;
        	} else if ((difficulty == "hard") || (difficulty == "Hard")) {
        		size = 10;
        	} else {
        	    printf("\033[1;31m"); // bold red 
        		cout << "Invalid difficulty, try again.\n";
        		printf("\033[0m"); // reset
        	}
        }
        
        // Declares the vectors as character values initilized with O
        vector<vector<char>>userBoard(size,vector<char>(size, 'O'));
        vector<vector<char>>enemyBoard(size,vector<char>(size));
        
        // Instructions on the difficulties
        cout << "Each map contains 5 ships\n1x Length 2\t2x Legnth 3\t1x Length 4\t1x Length 5\n";
        
        cout << "Selecting your map... please wait\n";
        
        // Selection of the map
        MapSelection(size, enemyBoard);
        cout << "Selection Complete.\n";
        cout << "Good Luck Captain " << userName << "!\n";
            printf("\033[1;36m"); // bold cyan
            cout << "=-=-=-=-=-=-=-=-=-=-=-=-=\n\n";
            printf("\033[0m"); // reset
        
        // Prints blank board for user to see
        PrintBoard(userBoard, size);
        numShipsLeft = ShipCounter(enemyBoard);
        cout << "There are ";
        printf("\033[1;34m"); // bold blue
        cout << numShipsLeft;
        printf("\033[1;0m"); // reset
        cout << " possible hits.\n";
        printf("\033[1;36m"); // bold cyan
        cout << "=-=-=-=-=-=-=-=-=-=-=-=-=\n";
        printf("\033[0m"); // reset
        
        // Input player attack as long as there are ships left to hit
        while (numShipsLeft != 0) {
            printf("\033[1;35m"); // bold magenta
            cout << "Where would you like to attack? \n";
            printf("\033[0m"); // reset
            cout << "Enter the row letter (do not enter two letters): \n";
            cin >> x;
            cout << "Enter the column number (do not enter a letter): \n";
            cin >> y;
            // Ensures the values are capitals because A is 65 and so on
            x = toupper(x);
            
            // Transfers the value to be an integer so the index can be tracked
            static_cast<int>(x);
            // Subtract 65 to make the value start at 0 as a proper index
            x = x - 65;
            y = y - 1;
            // If the input is too low or too high, as the user for a new input
            // ensures that the code wont quit on accidental inputs 
            if ((x < 0) || (x > size - 1)) {
                printf("\033[1;33m"); // bold yellow
                cout << "Invalid row input try again.\n";
                printf("\033[1;36m"); // bold cyan
                cout << "=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                printf("\033[0m"); // reset
                continue;
            }
            else if ((y < 0) || (y > size - 1)) {
                printf("\033[1;33m"); // bold yellow
                cout << "Invalid column input try again.\n";
                printf("\033[1;36m"); // bold cyan
                cout << "=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                printf("\033[0m"); // reset
                continue;
            }
            Attack(enemyBoard, userBoard, x, y, numShipsLeft);
            cout << "There are ";
            printf("\033[1;34m"); // bold blue
            cout << numShipsLeft;
            printf("\033[1;0m"); // reset
            cout << " possible hits.\n";
            printf("\033[1;36m"); // bold cyan
            cout << "=-=-=-=-=-=-=-=-=-=-=-=-=\n";
            printf("\033[0m"); // reset
        }
        // If there are no ships left, the player won
        if (numShipsLeft == 0) {
            printf("\033[1;36m"); // bold cyan
            cout << "=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=\n";
            printf("\033[1;32m"); // bold green
            cout << "You have completed the game! Congratualtions " << userName << "!\n";
            printf("\033[1;36m"); // bold cyan
            cout << "=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=\n";
            printf("\033[1;35m"); // bold magenta
            cout << "Would you like to play again? Yes or No? \n";
            printf("\033[0m"); // reset
            cin >> play;
        }
    }
    
    return 0;
}







