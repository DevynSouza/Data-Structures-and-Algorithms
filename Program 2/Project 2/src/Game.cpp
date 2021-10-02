#include "Game.hpp"

void Game::begin()
{

    SlotMachine *slotMachine = new SlotMachine(); //This is the default constructor so it should work
    PayoutTable *payoutTable = new PayoutTable(); 

    vector<char> reelVal;
    int balance = 100;

    cout << "\nHello and welcome to Slots(TM)\n \nEvery roll costs $1! Your current balance is: " << balance << "!" << endl;
    cout << "\nIn order to play enter 1 to play or 2 to quit." << endl;

    bool exit = true;

    while (exit)
    {
        if (balance < 1)
        {
            cout << "You have run out of money. Oh well better luck next time! Goodbye!" << endl;
            exit = false;
        }
        else
        {
            cout << "You're current balance is: " << balance << "!" << endl;
            cout << "Please enter 1 to play again or 2 to quit" << endl;
            int input;

            cin >> input;
            if (input == 1)
            {
                reelVal = slotMachine->Spin();

                balance -= 1;

                for (int idx = 0; idx < 7; idx += 3) {
                    if (reelVal[idx] == reelVal[idx + 1] && reelVal[idx] == reelVal[idx + 2]) {
                        if (reelVal[idx] == '7'){ 
                            cout << "JACKPOT!" << endl;
                        }

                        int payout = payoutTable->Payout(reelVal[idx]);
                        balance += payout;
                        cout << "You won $" << payout << "! Your balance is $" << balance <<  endl;
                    }
                    
                }
                //cout << "Vector[0]: " << vec[0] << " Vector[3]: " << vec[3] << " Vector[4]: " << vec[6] << endl;
            } //End of input 1

            if (input == 2)
            {
                cout << "Goodbye!" << endl;
                exit = false;
            } //end of input 2

        } //end of else statement

    } //End of while loop
}
