#include <iostream>
#include <string> // Needed to use strings
#include <cstdlib> // Needed to use random numbers
#include <ctime>
using namespace std;
void rules();
int main()
{
    string P_Name;
    int Available_balance; // stores player's Available_balance
    int Bet_Amount;
    int guess;
    int dice; // stores the random number
    char choice;
    srand(time(0)); // "Seed" the random generator
    cout << "\n\t\t========WELCOME TO CASINO WORLD=======\n\n";
    cout << "\n\nWhat's your Name : ";
    getline(cin, P_Name);
    cout << "\n\nEnter the starting Available_balance to play game : $";
    cin >> Available_balance;
    do
    {
        system("cls");
        rules();
        cout << "\n\nYour current Available_balance is $ " << Available_balance << "\n";
// Get player's betting Available_balance
        do
        {
            cout << "Hey, " << P_Name<<", enter amount to bet : $";
            cin >> Bet_Amount;
            if(Bet_Amount > Available_balance)
                cout << "Betting Available_balance can't be more than current Available_balance!\n"
                       <<"\nRe-enter Available_balance\n ";
        }while(Bet_Amount > Available_balance);
// Get player's numbers
        do
        {
            cout << "Guess any betting number between 1 & 10 :";
            cin >> guess;
            if(guess <= 0 || guess > 10)
                cout << "\nNumber should be between 1 to 10\n"
                    <<"Re-enter number:\n ";
        }while(guess <= 0 || guess > 10);
        dice = 1+(rand()%10);
        if(dice == guess)
        {
            cout << "\n\nYou are in luck!! You have won Rs." << Bet_Amount * 10;
            Available_balance = Available_balance + Bet_Amount * 10;
        }
        else
        {
            cout << "Oops, better luck next time !! You lost $ "<< Bet_Amount <<"\n";
            Available_balance = Available_balance - Bet_Amount;
        }
        cout << "\nThe winning number was : " << dice <<"\n";
        cout << "\n"<<P_Name<<", You have Available_balance of $ " << Available_balance << "\n";
        if(Available_balance == 0)
        {
            cout << "You have no money to play ";
            break;
        }
        cout << "\n\n-->Do you want to play again (y/n)? ";
        cin >> choice;
    }while(choice =='Y'|| choice=='y');
    cout << "\n\n\n";
    cout << "\n\nThanks for playing the game. Your Available_balance is $ " << Available_balance << "\n\n";
    return 0;
}
void rules()
{
    cout << "\t\t======CASINO NUMBER GUESSING RULES!======\n";
    cout << "\t1. Choose a number between 1 to 10\n";
    cout << "\t2. Winner gets 10 times of the money bet\n";
    cout << "\t3. Wrong bet, and you lose the amount you bet\n\n";
}

