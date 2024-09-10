#include <iostream>
#include<cstdlib>
#include <windows.h> 

using namespace std;

void getWinner(int userGuess, int compGuess, int &user_score, int &comp_score){
    if (userGuess == compGuess){

       printf("It's a tie\n");

    } else if ( userGuess == 1 && compGuess == 2){

        comp_score++;

    }
    else if ( userGuess == 2 && compGuess == 3){

        comp_score++;
        
    } else if ( userGuess == 3 && compGuess == 1){

        comp_score++;

    } else{

        user_score++;

    }

}

int main() {
    int user_input = 0;
    int user_score = 0;
    int comp_score = 0;
    bool test_user = false;
    time_t current_time = time(NULL);
    srand((unsigned) time(NULL));
    string items[3] ={"ROCK","PAPER","SCISSORS"};
    int gameOn = 1;
    bool gameLoop = true;

    cout << "Hello welcome to rock, paper, scissors." << endl;
    while(gameLoop){
        cout << "Pick one of following :\n1 - ROCK,\n2 - PAPER\n3-SCISSORS" << endl;
        cin >> user_input;
        test_user = (user_input==1) || (user_input==2) || (user_input==3);
        while (test_user == 0)
        {
            cout << "you picked wrong number! Try again." << endl;
            cout << "You have to pick 1, 2 or 3, sorry" << endl;
            cin >> user_input;
            test_user = (user_input==1) || (user_input==2) || (user_input==3);
        }
        int random_guess = (rand() % 3) + 1;
        
        cout << "You have picked: " << items[user_input - 1] << endl;
        cout << "Computer picked: " << items[random_guess -1] << endl;

        getWinner(user_input,random_guess,user_score,comp_score);

        cout << "Your score is: "<< user_score<< "\nComputer score is: " << comp_score << endl;
        printf("Do you want to continue? 1 - Yes, 0 - No");

        cin >> gameOn;
        if(!gameOn){
            gameLoop = false;
        }
    }
    return 0;
}