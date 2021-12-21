#include <iostream>

// Function declarations
int main();
// starting the game 
void start_game();

void display(int );

// store the guesses in a pointer
char *user_guesses();

//function that checks if users guesses matches actual word -> return all the letters that match
char *check_guesses(char *, char *);

// Function definitions
int main(){
    start_game();
    return 0;
}

/*
Expected output 

Press 'S' to start and 'Q' to quit:

If 'Q'
Thanks for playing 

If 'S'

// Display instrctions 
Guessed Letters: 

A-D--F-   -> Depending on the length of the word

Guess a letter: 'A'

Replace '-' with the letter 

*/


void start_game() {
    // Display the welcome message and prompt user to start game 

    std::cout << "Welcome to Binary Hangman!!!" << std::endl;
    std::cout << "Press [S] to start and [Q] to quit" << std::endl;

    std::cout << "Input: ";
    char start_or_end{};
    std::cin >> start_or_end;

    std::cout << std::endl;
    
    if (start_or_end == 'S'  || start_or_end == 's') {
        std::cout << "Let\'s start" << std::endl;
        std::cout << std::endl;

        display(5);
        user_guesses();
        char *people_guess{new char[8]{'A', 'B', 'C', 'D'}};
        char *actual_word{new char[8]{'B','C'}};
        check_guesses(people_guess, actual_word);

    } else if (start_or_end == 'Q' ||start_or_end ==  'q') {
        std::cout << "Thanks for playing" << std::endl;
    } else {
        std::cout << "Please enter a valid character: " << std::endl;

        while (start_or_end != 'S' || start_or_end != 's' || start_or_end != 'Q' || start_or_end != 'q') {
            std::cout << "Input: ";
            char start_or_end{};
            std::cin >> start_or_end;

            if (start_or_end == 'S'  || start_or_end == 's') {
                std::cout << "Let\'s start" << std::endl;
                display(5);
                user_guesses();
                break;
            } else if (start_or_end == 'Q' ||start_or_end ==  'q') {
                std::cout << "Thanks for playing" << std::endl;
                break;
            }
        }
    }
}

void display(int len) {
    /*
    Instrcutions are as follows

    Enter your guesses using either 0 or 1 
    Enter it in the form of an 8 bit number
    */
   std::cout <<  "Enter your guesses using either 0 or 1" << std::endl;
   std::cout << "Enter it in the form of an 8 bit number" << std::endl;

   std::cout << std::endl;

   std::cout << "The length of the word is shown below: " << std::endl;
   std::cout << std::endl;

   // print a '-' for each of the length of the word
   for (std::size_t i{0}; i < len; ++i) {
       std::cout << "- ";
   }
   std::cout << std::endl;
}

// every time function is triggered the users guesses will be stored in a new array
char *user_guesses(){
    std::cout << "Let\'s start guessing" << std::endl;
    std::cout << std::endl;
    
    char *new_arr{new char[8]{}};
    for (int i{1}; i <= 8; ++i) {
        std::cout << "Guess number " << i << ": ";
        std::cin >> new_arr;
    }

    return new_arr;
}


char *check_guesses(char *user_guess, char *actual_word) {
    char *correct_letters{new char[8]{}};
    int i{0};
    while (i < 6) {
        if (user_guess[i] == actual_word[i]) {
            correct_letters[i] = user_guess[i];
        }
        i++;
    }
    return correct_letters;
}





