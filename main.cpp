#include <iostream>

class RockPaperScissors
{
private:
    // The values that we will use to represent the moves of the player and the computer
    int player_value;
    int ai_value;
    
    // The actual moves that the player and the computer can make according to the values above
    std::string player_choice;
    std::string ai_choice;

    void ask_player(); // Ask the player to make a move
    std::string calulate_move(); // Calculate the move of the player because it definatly needs a seperate function
    std::string ai_play(); // Make an AI play and pick a move
    void compare_and_conclude(); // Compare the moves and decide who won
    void try_again(); // Ask the player if he wants to play again

public:
    // A function that will run the whole game
    void run() {
        ask_player();
        calulate_move();
        ai_play();
        compare_and_conclude();
        try_again();
    }
};

void RockPaperScissors::ask_player() {
    std::cout << "Hello to rock, paper, Scissors\n";
    std::cout << "What do you want to pick. Rock, paper or Scissors";
    std::cout << "\n1) Rock\n2) Paper\n3) Scissors\n> ";
    std::cin >> player_value; // Make the player pick a move and store it in player_value
}

std::string RockPaperScissors::calulate_move() {
    if (player_value == 1){
        return player_choice = "Rock";
    }
    if (player_value == 2){
        return player_choice = "Paper";
    }
    if (player_value == 3){
        return player_choice = "Scissors";
    } else {
        std::cout << "Please try something from 1 to 3\n";
        try_again();
    }

    return player_choice;
}

std::string RockPaperScissors::ai_play() {
    srand(time(nullptr)); // I will not try to attemp to know what this one does

    ai_value = (rand() % 3) + 1;
    /*
    Pick a random number. Now because we say (rand() % 3) it will make it pick between 0 and 2
    but because we put the + 1 in the end it gets fixed between 1, 2 and 3
    */
    
    // assign the intiger to a string
    if (ai_value == 1) {
        return ai_choice = "Rock";
    }
    if (ai_value == 2) {
        return ai_choice = "Paper";
    }
    if (ai_value == 3) {
        return ai_choice = "Scissors";
    }

    return ""; // Make sure it's not accesible(Why I don't know)
}

void RockPaperScissors::compare_and_conclude()
{
    // I think that everything seems self exlanitory
    if (player_choice == "Rock"){
        if (ai_choice == "Paper")
        {
            std::cout << "You lose! Paper beats Rock\n";
        } else if (ai_choice == "Scissors")
        {
            std::cout << "You win! Rock beats Scissors\n";
        } else if (ai_choice == "Rock")
        {
            std::cout << "It's a tie!\n";
        }
    }
    else if (player_choice == "Paper")
    {
        if (ai_choice == "Scissors")
        {
            std::cout << "You lose! Scissors beats Paper\n";
        }
        else if (ai_choice == "Rock")
        {
            std::cout << "You win! Paper beats Rock\n";
        }
        else if (ai_choice == "Paper")
        {
            std::cout << "It's a tie!\n";
        }
    }
    else if (player_choice == "Scissors")
    {
        if (ai_choice == "Rock")
        {
            std::cout << "You lose! Rock beats Scissors\n";
        } else if (ai_choice == "Paper")
        {
            std::cout << "You win! Scissors beats Paper\n";
        }
        else if (ai_choice == "Scissors")
        {
            std::cout << "It's a tie!\n";
        }
    }

}

void RockPaperScissors::try_again() {
    std::cout << "Do you want to play again? (Y/N) ";
    std::string answer;
    std::cin >> answer;
    if (answer == "Y" || answer == "y") {
        run();
    } else {
        std::cout << "Thanks for playing!\n";
        system("pause");
    }
}

int main()
{
    RockPaperScissors game; // Make an instance of the game

    game.run(); // Run the game

    return 0;
}
