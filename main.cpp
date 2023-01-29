// ********************************************************* 
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year: Trimester 1, 2022/23 (T2215) 
// Lab: TT3L 
// Names: LEONG CHUN KIT | LIM KAI QIAN
// IDs: 1211102971 | 1211101232
// Emails: 1211102971@STUDENT.MMU.EDU.MY | 1211101232@STUDENT.MMU.EDU.MY 
// Phones: 0182288417 | 01137763826 
// ********************************************************* 


#include <iostream>
#include <vector>
#include <time.h>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <limits>
using namespace std;

class Character
{
public:
    class Alien
    {
    private:
        vector<int> alienLife{70};  // Original life of the alien.
        vector<int> alienAttack{0}; // 100, 20, 20, 20, 20, 20

    public:
        void setLife(int life) { alienLife.push_back(life); }  // Set another life using pushback.
        void clearLife() { alienLife.clear(); }                // Clear every life in the alienLife.
        int getLife(int index) { return alienLife.at(index); } // Get life at the specified index.
        int sizeLife() { return alienLife.size(); }            // Return the size of the vector.

        void setAttack(int attack) { alienAttack.push_back(attack); } // Set another life using pushback.
        int getAttack(int index) { return alienAttack.at(index); }    // Get life at the specified index.
        int sizeAttack() { return alienAttack.size(); }               // Return the size of the vector.
    };

    class Zombie
    {
    private:
        vector<int> zombieNo{};     // The number of the zombies.
        vector<int> zombieLife{};   // The life of the zombies. 100, 150, 200, 250
        vector<int> zombieAttack{}; // The attack of the zombies. 10, 15
        vector<int> zombieRange{};  // The range of the zombies. 1, 2, 3, 4, 5

    public:
        void setZombie(int zombieID) { zombieNo.push_back(zombieID); }
        int getZombie(int index) { return zombieNo.at(index); }
        int sizeZombie() { return zombieNo.size(); };

        void setLife(int life) { zombieLife.push_back(life); }  // Set another life using pushback.
        int getLife(int index) { return zombieLife.at(index); } // Get life at the specified index.
        int sizeLife() { return zombieLife.size(); };           // Return the size of the vector.

        void setAttack(int attack) { zombieAttack.push_back(attack); } // Set another life using pushback.
        int getAttack(int index) { return zombieAttack.at(index); }    // Get life at the specified index.
        int sizeAttack() { return zombieAttack.size(); }               // Return the size of the vector.

        void setRange(int range) { zombieRange.push_back(range); } // Set another life using pushback.
        int getRange(int index) { return zombieRange.at(index); }  // Get life at the specified index.
        int sizeRange() { return zombieRange.size(); }             // Return the size of the vector.
    };
};

int customize(int &row, int &column, int &zombie) // Customization for row, column and zombie amount.
{
    // Row setting.
    cout << "Board Settings" << endl;
    cout << "--------------" << endl;
    int error;
    do
    {
        error = false;
        cout << "Enter rows => ";
        cin >> row;
        if (cin.fail()) // Check invalid input.
        {
            cout << "Please enter a valid odd integer > 2." << endl;
            error = true;
            cin.clear();  // The clear() function can be used to clear these error flags and restore the cin object to a good state, allowing further input operations to be performed.
            cin.ignore(); // The cin.clear() can be used together with cin.ignore() to clear the error state of the stream and ignore any unread characters that may be in the input buffer.
        }
        else if (row < 3) // Check number < 3.
        {
            cout << "Please enter a valid odd integer > 2." << endl;
            error = 1;
            cin.clear();
            cin.ignore();
        }
        else if (row % 2 == 0) // Check even number.
        {
            cout << "Please enter a valid odd integer > 2." << endl;
            error = 1;
            cin.clear();
            cin.ignore();
        }
    } while (error == 1);

    // Column setting.
    do
    {
        error = 0;
        cout << "Enter columns => ";
        cin >> column;
        if (cin.fail()) // Check invalid input.
        {
            cout << "Please enter a valid odd integer > 2." << endl;
            error = 1;
            cin.clear();
            cin.ignore();
        }
        else if (column < 3) // Check number < 3
        {
            cout << "Please enter a valid odd integer > 2.." << endl;
            error = 1;
            cin.clear();
            cin.ignore();
        }
        else if (column % 2 == 0) // Check even number.
        {
            cout << "Please enter a valid odd integer > 2." << endl;
            error = 1;
            cin.clear();
            cin.ignore();
        }
    } while (error == 1);

    // Zombie setting.
    cout << endl;
    cout << "Zombie Settings" << endl;
    cout << "---------------" << endl;
    do
    {
        error = 0;
        cout << "Enter number of zombies => ";
        cin >> zombie;
        if (cin.fail())
        {
            cout << "Please enter a valid positive integer < 10." << endl;
            error = 1;
            cin.clear();
            cin.ignore();
        }
        else if (zombie < 1)
        {
            cout << "Please enter a valid positive integer < 10." << endl;
            error = 1;
            cin.clear();
            cin.ignore();
        }
        else if (zombie > 9)
        {
            cout << "Please enter a valid positive integer < 10." << endl;
            error = 1;
            cin.clear();
            cin.ignore();
        }
        cout << endl;
    } while (error == 1);
    cout << "Settings Updated." << endl;
    return row, column, zombie;
}

void setting(int &row, int &column, int &zombie) // Default page and ask user for customization.
{
    cout << "Default Game Settings" << endl;
    cout << "---------------------" << endl;
    cout << "Board Rows\t: " << row << endl;
    cout << "Board Columns\t: " << column << endl;
    cout << "Zombie Count\t: " << zombie << endl;
    bool next = false;
    while (next != true)
    {
        string change;
        cout << endl;
        cout << "Do you wish to change the game settings (y/n)? => ";
        cin >> change;
        if (change == "y" || change == "Y")
        {
            system("CLS");
            customize(row, column, zombie);
            next = true;
            system("PAUSE");
            return;
        }
        else if (change == "n" || change == "N")
        {
            return;
        }
        else
        {
            cout << "Please enter y/n." << endl;
        }
    }
}

void displayTitle(int &column, int &row) // Display ".: Alien vs Zombie :.".
{
    if (row > 9)
    {
        cout << "    ";
    }
    else
    {
        cout << "   ";
    }
    int x = column + 1;
    while (x > 11)
    {
        cout << " ";
        --x;
    }
    cout << ".: Alien vs Zombie :." << endl;
}

void displayBorder(int &column, int &row) // Display one horizontal line of border.
{
    int x = 1;
    if (row > 9)
    {
        cout << "    +";
    }
    else
    {
        cout << "   +";
    }
    while (x <= column)
    {
        cout << "-+";
        ++x;
    }
    cout << endl;
}

int displayRow(int &rowStart, int &row) // Display row count on the left side of board.
{
    cout << " ";
    int rowCount = rowStart + 1;
    if (row > 9)
    {
        cout.width(2);
    }
    cout.setf(ios::fixed);
    cout << rowCount << " ";
    ++rowStart;
    return rowCount;
}

void displayColumn(int &column, int &row) // Display column count on the bottom side of board.
{
    int columnStart = 0;
    int x = 0;
    if (column > 9)
    {
        if (row > 9)
        {
            cout << "    ";
        }
        else
        {
            cout << "   ";
        }
        for (int i = 1; i <= column; ++i)
        {
            if (i < 10)
            {
                cout << "  ";
            }
            else if (i % 10 == 0)
            {
                x = x + 1;
                cout << " " << x;
            }
            else
            {
                cout << " " << x;
            }
        }
        cout << endl;
    }
    if (row > 9)
    {
        cout << "    ";
    }
    else
    {
        cout << "   ";
    }
    for (int i = 1; i <= column; ++i)
    {
        if (columnStart == 9)
        {
            columnStart = 0;
        }
        else
        {
            columnStart = columnStart + 1;
        }
        cout << " " << columnStart;
    }
    cout << endl;
    cout << endl;
}

void displayAlienLife(Character::Alien &aliens) // Display the life of alien.
{
    cout.width(3);
    cout << aliens.getLife(0);
}

void displayAlienAttack(Character::Alien &aliens) // Display the attack of alien.
{
    cout.width(3);
    cout << aliens.getAttack(0);
}

int displayZombieNo(Character::Zombie &zombies, int &zombiesNo) // Display the life of zombies.
{
    cout << zombies.getZombie(zombiesNo);
    return zombiesNo;
}

void displayZombieLife(Character::Zombie &zombies, int &zombiesNo) // Display the life of zombies.
{
    cout.width(3);
    cout << zombies.getLife(zombiesNo);
}

void displayZombieAttack(Character::Zombie &zombies, int &zombiesNo) // Display the attack of zombies.
{
    cout.width(3);
    cout << zombies.getAttack(zombiesNo);
}

void displayZombieRange(Character::Zombie &zombies, int &zombiesNo) // Display the range of zombies.
{
    cout.width(2);
    cout << zombies.getRange(zombiesNo);
}

void displayCharacter(Character::Alien &aliens, Character::Zombie &zombies, int &zombie) // Display the life, attack and range of alien and zombie.
{
    int zombiesNo;
    cout << "Alien    : Life ";
    displayAlienLife(aliens);
    cout << ", Attack ";
    displayAlienAttack(aliens);
    cout << endl;
    for (zombiesNo = 0; zombiesNo < zombie; ++zombiesNo)
    {
        cout << "Zombie " << zombiesNo + 1 << " : Life ";
        displayZombieLife(zombies, zombiesNo);
        cout << ", Attack ";
        displayZombieAttack(zombies, zombiesNo);
        cout << ", Range ";
        displayZombieRange(zombies, zombiesNo);
        cout << endl;
    }
    cout << endl;
}

void displayBoard(string **arr, int &row, int &column, int &zombie, int &rowStart, Character::Alien &aliens, Character::Zombie &zombies) // Display the game board.
{
    rowStart = 0;
    displayTitle(column, row);
    displayBorder(column, row);
    for (int i = 0; i < row; ++i)
    {
        displayRow(rowStart, row);
        for (int j = 0; j < column; ++j)
        {
            cout << "|" << arr[i][j];
        }
        cout << "|" << endl;
        displayBorder(column, row);
    }
    displayColumn(column, row);
    displayCharacter(aliens, zombies, zombie);
}

void assignZombie(int &row, int &column, int &zombie, string **arr, int **PositionZombie) // Generate zombies for the board.
{
    int numberAssignInt = 1;
    int randomRow, randomColumn;
    for (int i = 0; i < zombie; ++i)
    {
        do
        {
            randomRow = rand() % row;
            randomColumn = rand() % column;
        } while (arr[randomRow][randomColumn] == "A" || arr[randomRow][randomColumn] == "1" || arr[randomRow][randomColumn] == "2" || arr[randomRow][randomColumn] == "3" || arr[randomRow][randomColumn] == "4" || arr[randomRow][randomColumn] == "5" || arr[randomRow][randomColumn] == "6" || arr[randomRow][randomColumn] == "7" || arr[randomRow][randomColumn] == "8" || arr[randomRow][randomColumn] == "9");

        string numberAssignStr = to_string(numberAssignInt);
        arr[randomRow][randomColumn] = numberAssignStr;
        PositionZombie[i][0] = randomRow; // Assign the Row and Column of each zombie in the array
        PositionZombie[i][1] = randomColumn;
        numberAssignInt = numberAssignInt + 1;
    }
    // for (int i = 0; i < zombie; ++i){                   //For testing purpose
    //     for (int j = 0; j < 2; ++j){
    //         cout << PositionZombie[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // system("PAUSE");
}

int **ZombiePosition(int &zombie)
{
    int **PositionZombie = new int *[zombie];
    for (int i = 0; i < zombie; i++)
    {
        PositionZombie[i] = new int[2];
    }
    return PositionZombie;
}

string randomObject() // Randomize object.
{
    string finalObject;
    // string object[8] = {"^", "v", "<", ">", "h", "p", "r", " "};
    // finalObject = object[rand() % 8];
    finalObject = "p";
    // string object[7] = {"^", "v", "<", ">", "h", "p", " "};
    // finalObject = object[rand() % 7];
    return finalObject;
}

void generateRandom(string **arr, int &row, int &column) // Assign random objects to each land.
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            arr[i][j] = randomObject();
        }
    }
}

string **generate2DArr(int &row, int &column) // Initialize 2D array.
{
    string **arr = new string *[row];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new string[column];
    }
    return arr;
}

int randomLife() // Randomize zombie life.
{
    int finalLife;
    int life[4] = {100, 150, 200, 250};
    finalLife = life[rand() % 4];
    return finalLife;
}

int randomAttack() // Randomize zombie attack.
{
    int finalAttack;
    int attack[2] = {10, 15};
    finalAttack = attack[rand() % 2];
    return finalAttack;
}

int randomRange() // Randomize zombie range.
{
    int finalRange;
    int range[5] = {1, 2, 3, 4, 5};
    finalRange = range[rand() % 5];
    return finalRange;
}

void generateZombie(Character::Zombie &zombies, int &zombie, int &row, int &column, string **arr, int **PositionZombie) // Generate zombies with random life, attack and range.
{
    for (int i = 0; i < zombie; ++i)
    {
        zombies.setZombie(i);
        int zombieLife = randomLife();
        zombies.setLife(zombieLife);
        int zombieAttack = randomAttack();
        zombies.setAttack(zombieAttack);
        int zombieRange = randomRange();
        zombies.setRange(zombieRange);
    }
    assignZombie(row, column, zombie, arr, PositionZombie);
}

void help() // Show command list.
{
    cout << "1. up\t\t- Move Up" << endl;
    cout << "2. down\t\t- Move Down" << endl;
    cout << "3. left\t\t- Move Left " << endl;
    cout << "4. right\t- Move Right" << endl;
    cout << "5. arrow\t- Change the direction of an arrow using row and column" << endl;
    cout << "6. help\t\t- Display the user commands" << endl;
    cout << "7. save\t\t- Save the game " << endl;
    cout << "8. load\t\t- Load previous saved game" << endl;
    cout << "9. quit\t\t- exit the game" << endl;
    return;
}

string moveUp(int &x, int &y, string **arr, string &hit) // Action for alien to move up.
{
    if (x - 1 >= 0)
    {
        arr[x][y] = ".";
        x = x - 1;
        hit = arr[x][y];
        arr[x][y] = "A";
        return hit;
    }
    else
    {
        return hit;
    }
}

string moveDown(int &x, int &y, string **arr, string &hit, int &row) // Action for alien to move down.
{
    if (x + 1 <= row - 1)
    {
        arr[x][y] = ".";
        x = x + 1;
        hit = arr[x][y];
        arr[x][y] = "A";
        return hit;
    }
    else
    {
        return hit;
    }
}

string moveLeft(int &x, int &y, string **arr, string &hit) // Action for alien to move up.
{
    if (y - 1 >= 0)
    {
        arr[x][y] = ".";
        y = y - 1;
        hit = arr[x][y];
        arr[x][y] = "A";
        return hit;
    }
    else
    {
        return hit;
    }
}

string moveRight(int &x, int &y, string **arr, string &hit, int &column) // Action for alien to move up.
{
    if (y + 1 <= column - 1)
    {
        arr[x][y] = ".";
        y = y + 1;
        hit = arr[x][y];
        arr[x][y] = "A";
        return hit;
    }
    else
    {
        return hit;
    }
}

string continuousMove(string &hit, string &lastMove, int &x, int &y, string **arr, int &row, int &column) // Identify what is the next hit.
{
    if (lastMove == "^")
    {
        hit = moveUp(x, y, arr, hit);
    }
    else if (lastMove == "v")
    {
        hit = moveDown(x, y, arr, hit, row);
    }
    else if (lastMove == "<")
    {
        hit = moveLeft(x, y, arr, hit);
    }
    else if (lastMove == ">")
    {
        hit = moveRight(x, y, arr, hit, column);
    }
    return hit;
}

void distanceCounter(int &row, int &column, string **arr)
{
    int rowA, colA;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (arr[i][j] == "A")
            {
                rowA = i;
                colA = j;
            }
        }
    }
    for (int i = 0; i < (row); ++i)
    {
        for (int j = 0; j < (column); ++j)
        {
            if (arr[i][j] == "1")
            {
                int row1 = i;
                int col1 = j;
                int manhattanDistance1 = abs(rowA - row1) + abs(colA - col1);
                cout << "Manhattan distance between A and 1: " << manhattanDistance1 << endl;
            }
        }
    }
    for (int i = 0; i < (row); ++i)
    {
        for (int j = 0; j < (column); ++j)
        {
            if (arr[i][j] == "2")
            {
                int row2 = i;
                int col2 = j;
                int manhattanDistance2 = abs(rowA - row2) + abs(colA - col2);
                cout << "Manhattan distance between A and 2: " << manhattanDistance2 << endl;
            }
        }
    }
    for (int i = 0; i < (row); ++i)
    {
        for (int j = 0; j < (column); ++j)
        {
            if (arr[i][j] == "3")
            {
                int row3 = i;
                int col3 = j;
                int manhattanDistance3 = abs(rowA - row3) + abs(colA - col3);
                cout << "Manhattan distance between A and 3: " << manhattanDistance3 << endl;
            }
        }
    }
    for (int i = 0; i < (row); ++i)
    {
        for (int j = 0; j < (column); ++j)
        {
            if (arr[i][j] == "4")
            {
                int row4 = i;
                int col4 = j;
                int manhattanDistance4 = abs(rowA - row4) + abs(colA - col4);
                cout << "Manhattan distance between A and 4: " << manhattanDistance4 << endl;
            }
        }
    }
    for (int i = 0; i < (row); ++i)
    {
        for (int j = 0; j < (column); ++j)
        {
            if (arr[i][j] == "5")
            {
                int row5 = i;
                int col5 = j;
                int manhattanDistance5 = abs(rowA - row5) + abs(colA - col5);
                cout << "Manhattan distance between A and 5: " << manhattanDistance5 << endl;
            }
        }
    }
    for (int i = 0; i < (row); ++i)
    {
        for (int j = 0; j < (column); ++j)
        {
            if (arr[i][j] == "6")
            {
                int row6 = i;
                int col6 = j;
                int manhattanDistance6 = abs(rowA - row6) + abs(colA - col6);
                cout << "Manhattan distance between A and 6: " << manhattanDistance6 << endl;
            }
        }
    }
    for (int i = 0; i < (row); ++i)
    {
        for (int j = 0; j < (column); ++j)
        {
            if (arr[i][j] == "7")
            {
                int row7 = i;
                int col7 = j;
                int manhattanDistance7 = abs(rowA - row7) + abs(colA - col7);
                cout << "Manhattan distance between A and 7: " << manhattanDistance7 << endl;
            }
        }
    }
    for (int i = 0; i < (row); ++i)
    {
        for (int j = 0; j < (column); ++j)
        {
            if (arr[i][j] == "8")
            {
                int row8 = i;
                int col8 = j;
                int manhattanDistance8 = abs(rowA - row8) + abs(colA - col8);
                cout << "Manhattan distance between A and 8: " << manhattanDistance8 << endl;
            }
        }
    }
    for (int i = 0; i < (row); ++i)
    {
        for (int j = 0; j < (column); ++j)
        {
            if (arr[i][j] == "9")
            {
                int row9 = i;
                int col9 = j;
                int manhattanDistance9 = abs(rowA - row9) + abs(colA - col9);
                cout << "Manhattan distance between A and 9: " << manhattanDistance9 << endl;
            }
        }
    }
}

void hitObject(string &hit, Character::Alien &aliens, string &lastMove, int &row, int &column, string **arr) // Display different outputs based on what it hits.
{
    if (hit == "^")
    {
        cout << "Alien finds a arrow." << endl;
        cout << "Alien's attack is increased by 20." << endl;
        cout << endl;
        lastMove = "^";
    }
    else if (hit == "v")
    {
        cout << "Alien finds a arrow." << endl;
        cout << "Alien's attack is increased by 20." << endl;
        cout << endl;
        lastMove = "v";
    }
    else if (hit == "<")
    {
        cout << "Alien finds a arrow." << endl;
        cout << "Alien's attack is increased by 20." << endl;
        cout << endl;
        lastMove = "<";
    }
    else if (hit == ">")
    {
        cout << "Alien finds a arrow." << endl;
        cout << "Alien's attack is increased by 20." << endl;
        cout << endl;
        lastMove = ">";
    }
    else if (hit == "h")
    {
        cout << "Alien finds a health pack." << endl;
        cout << "Alien's life is increased by 20." << endl;
        cout << endl;
        aliens.setLife(20);
        int totalLife = aliens.getLife(0) + aliens.getLife(1);
        aliens.clearLife();
        if (totalLife > 100)
        {
            totalLife = 100;
        }
        aliens.setLife(totalLife);
    }
    else if (hit == "p")
    {
        cout << "Alien found a pod!" << endl;
        cout << "Zombie "
             << " receives a damage of 10." << endl;
        cout << endl;
        distanceCounter(row, column, arr);
    }
    else if (hit == "r")
    {
        cout << "Alien stumbles upon a rock." << endl;
        cout << "Alien discovers a "
             << " beneath the rock." << endl;
        cout << endl;
    }
    else if (hit == " ")
    {
        cout << "Alien finds an empty space." << endl;
        cout << endl;
    }
    else if (hit == ".")
    {
    }
}

void zombieAttack(Character::Zombie &zombies, Character::Alien &aliens, int **PositionZombie, int i, string **arr, int &row, int &column) // Zombie detect and attack alien if nearby
{
    bool attack = false;
    // cout << zombies.getAttack(i) << " "     // For testing purpose.
    //      << zombies.getRange(i) << " "
    //      << endl;
    // system("PAUSE");
    for (int a = 1; a <= zombies.getRange(i); a++)
    {
        // cout << a << "test 1" << endl;
        if (PositionZombie[i][0] - a >= 0 && arr[PositionZombie[i][0] - a][PositionZombie[i][1]] == "A")
        { // To prevent oversize and detect upper position
            attack = true;
            break;
        }
        // cout << a << "test 2" << endl;
        if (PositionZombie[i][0] + a <= row - 1 && arr[PositionZombie[i][0] + a][PositionZombie[i][1]] == "A")
        { // To prevent oversize and detect lower position.
            attack = true;
            break;
        }
        // cout << a << "test 3" << endl;
        if (PositionZombie[i][1] + a <= column - 1 && arr[PositionZombie[i][0]][PositionZombie[i][1] + a] == "A")
        { // To prevent oversize and detect right position.
            attack = true;
            break;
        }
        // cout << a << "test 4" << endl;
        if (PositionZombie[i][1] - a >= 0 && arr[PositionZombie[i][0]][PositionZombie[i][1] - a] == "A")
        { // To prevent oversize and detect left position.
            attack = true;
            break;
        }
        for (int b = 0; b <= zombies.getRange(i) - a; b++)
        {
            // cout << b << "test 5" << endl;
            if (PositionZombie[i][1] + b <= column - 1 && PositionZombie[i][0] - a >= 0 && arr[PositionZombie[i][0] - a][PositionZombie[i][1] + b] == "A")
            { // To detect upper right diagonal position.
                attack = true;
                break;
            }
            // cout << b << "test 6" << endl;
            if (PositionZombie[i][1] - b >= 0 && PositionZombie[i][0] - a >= 0 && arr[PositionZombie[i][0] - a][PositionZombie[i][1] - b] == "A")
            { // To detect upper left diagonal position.
                attack = true;
                break;
            }
            // cout << b << "test 7" << endl;
            if (PositionZombie[i][1] + b <= column - 1 && PositionZombie[i][0] + a <= row - 1 && arr[PositionZombie[i][0] + a][PositionZombie[i][1] + b] == "A")
            { // To detect lower right diagonal position.
                attack = true;
                break;
            }
            // cout << b << "test 8" << endl;
            if (PositionZombie[i][1] - b >= 0 && PositionZombie[i][0] + a <= row - 1 && arr[PositionZombie[i][0] + a][PositionZombie[i][1] - b] == "A")
            { // To detect lower left diagonal position.
                attack = true;
                break;
            }
        }
    }

    if (attack == false)
    {
        cout << "Zombie " << i + 1 << " is unable to attack alien." << endl;
        cout << "Alien is too far away." << endl;
    }
    else if (attack == true)
    {
        cout << "Zombie " << i + 1 << " attacks Alien." << endl;
        cout << "Alien receives a damage of " << zombies.getAttack(i) << "." << endl;
        aliens.setLife(zombies.getAttack(i));
        int totalLife = aliens.getLife(0) - aliens.getLife(1);
        aliens.clearLife();
        if (totalLife < 0)
        {
            totalLife = 0;
        }
        aliens.setLife(totalLife);
    }
    cout << endl;
}

void zombieMove(Character::Zombie &zombies, Character::Alien &aliens, int &row, int &column, string **arr, int **PositionZombie, int &rowStart, int &zombie) // Action for zombie to move
{
    rowStart = 0;
    system("cls");
    displayBoard(arr, row, column, zombie, rowStart, aliens, zombies);
    for (int i = 0; i < zombie; i++)
    {

        // cout << "Zombie " << i+1 << "\t"                            // For testing purpose.
        //      << "Health \t" << zombies.getLife(i)
        //      << "\t Attack \t" << zombies.getAttack(i)
        //      << "\t Range \t" << zombies.getRange(i) << endl;
        string direction[4] = {"left", "right", "up", "down"};
        string move = direction[rand() % 4];
        rowStart = 0;
        cout << "Zombie " << i + 1 << "'s turn." << endl;
        if (move == "up")
        { // Movement depend on direcction move.
            cout << "Zombie " << i + 1 << " moves up." << endl;
            if (PositionZombie[i][0] > 0 && arr[PositionZombie[i][0] - 1][PositionZombie[i][1]] != "A")
            {                                                          // Prevent hit the border of hit the alien.
                arr[PositionZombie[i][0]][PositionZombie[i][1]] = " "; // Change the original zombie's position into empty.
                PositionZombie[i][0] = PositionZombie[i][0] - 1;
                arr[PositionZombie[i][0]][PositionZombie[i][1]] = to_string(i + 1); // Place the zombie in the new position.
            }
        }
        else if (move == "down")
        {
            cout << "Zombie " << i + 1 << " moves down." << endl;
            if (PositionZombie[i][0] < row - 1 && arr[PositionZombie[i][0] + 1][PositionZombie[i][1]] != "A")
            {
                arr[PositionZombie[i][0]][PositionZombie[i][1]] = " ";
                PositionZombie[i][0] = PositionZombie[i][0] + 1;
                arr[PositionZombie[i][0]][PositionZombie[i][1]] = to_string(i + 1);
            }
        }
        else if (move == "left")
        {
            cout << "Zombie " << i + 1 << " moves left." << endl;
            if (PositionZombie[i][1] > 0 && arr[PositionZombie[i][0]][PositionZombie[i][1] - 1] != "A")
            {
                arr[PositionZombie[i][0]][PositionZombie[i][1]] = " ";
                PositionZombie[i][1] = PositionZombie[i][1] - 1;
                arr[PositionZombie[i][0]][PositionZombie[i][1]] = to_string(i + 1);
            }
        }
        else
        {
            cout << "Zombie " << i + 1 << " moves right." << endl;
            if (PositionZombie[i][1] < column - 1 && arr[PositionZombie[i][0]][PositionZombie[i][1] + 1] != "A")
            {
                arr[PositionZombie[i][0]][PositionZombie[i][1]] = " ";
                PositionZombie[i][1] = PositionZombie[i][1] + 1;
                arr[PositionZombie[i][0]][PositionZombie[i][1]] = to_string(i + 1);
            }
        }
        cout << endl;
        system("PAUSE");
        system("CLS");
        displayBoard(arr, row, column, zombie, rowStart, aliens, zombies);
        zombieAttack(zombies, aliens, PositionZombie, i, arr, row, column);
        system("PAUSE");
        system("CLS");
        displayBoard(arr, row, column, zombie, rowStart, aliens, zombies);
    }
}

string commandUser(string &command) // Allow user to input command.
{
    cout << "command > ";
    cin >> command;
    cout << endl;
    return command;
}

int main()
{
    Character::Alien aliens;
    Character::Zombie zombies;
    srand(time(NULL));
    int row = 5;
    int rowStart;
    int column = 9;
    int zombie = 1;
    bool exit = false;
    bool generate = true;
    setting(row, column, zombie);
    int **PositionZombie = ZombiePosition(zombie); // create an array too store the position of zombie
    string **arr = generate2DArr(row, column);
    int x = (row - 1) / 2;
    int y = (column - 1) / 2;
    while (generate != false)
    {
        generateRandom(arr, row, column);
        string alien = "A";
        arr[x][y] = alien;
        generate = false;
    }
    generateZombie(zombies, zombie, row, column, arr, PositionZombie);
    string command;
    while (exit != true)
    {
        system("CLS");
        displayBoard(arr, row, column, zombie, rowStart, aliens, zombies);
        commandUser(command);
        string lastMove;
        string hit;
        if (command == "quit")
        {
            break;
        }
        else if (command == "up" || command == "down" || command == "left" || command == "right")
        {
            if (command == "up")
            {
                hit = moveUp(x, y, arr, hit);
                lastMove = "^";
            }
            else if (command == "down")
            {
                hit = moveDown(x, y, arr, hit, row);
                lastMove = "v";
            }
            else if (command == "left")
            {
                hit = moveLeft(x, y, arr, hit);
                lastMove = "<";
            }
            else if (command == "right")
            {
                hit = moveRight(x, y, arr, hit, column);
                lastMove = ">";
            }
            hitObject(hit, aliens, lastMove, row, column, arr);
            // cout << hit << endl; // For testing purpose.
            system("PAUSE");
            while (true)
            {
                if ((x == 0 && lastMove == "^") || (x == (row - 1) && lastMove == "v") || (y == 0 && lastMove == "<") || (y == (column - 1) && lastMove == ">"))
                {
                    break;
                }
                else
                {
                    system("CLS");
                    displayBoard(arr, row, column, zombie, rowStart, aliens, zombies);
                    hit = continuousMove(hit, lastMove, x, y, arr, row, column);
                    hitObject(hit, aliens, lastMove, row, column, arr);
                    // cout << hit << endl; // For testing purpose.
                    system("PAUSE");
                }
            }
        }
        else if (command == "arrow")
        {
            cout << endl;
            system("PAUSE");
        }
        else if (command == "help")
        {
            help();
            cout << endl;
            system("PAUSE");
        }
        else if (command == "save")
        {
            cout << endl;
            system("PAUSE");
        }
        else if (command == "load")
        {
            cout << endl;
            system("PAUSE");
        }
        else
        {
            cout << "Please enter a valid command." << endl;
            cout << "You can view the command list by entering command \'help\'." << endl;
            cout << endl;
            system("PAUSE");
        }
        zombieMove(zombies, aliens, row, column, arr, PositionZombie, rowStart, zombie);
    }
}