#include <iostream>
#include <random>
using namespace std;


int get_random(int &n_small, int &n_large){
    std::random_device random_device;
    std::mt19937 random_engine{random_device()};
    std::uniform_int_distribution<int> distribution{n_small, n_large};
    int rand_n = distribution(random_engine);
    return rand_n;
}


int main(){
    int n_small,n_large;
    int n_guess = 100000;

    cout << "Welcome to the GUESSING GAME!\nI will generate a number and you will guess it!"<< endl;

    cout << "Please provide the smallest number:\n";
    cin >> n_small;

    cout << "Please provide the largest number:\n";
    cin >> n_large;

    int n_random = get_random(n_small,n_large);
    cout << "I've generated a number. Try to guess it!" << endl;

    bool to_guess = true;
    int cnt = 0;
    while(to_guess){
        cnt ++;
        cout << "Please provide the next guess: ";
        cin >> n_guess;
        if(n_guess<n_random){
            cout << "Your number is too small. Try again!" << endl;
        }else if(n_guess>n_random){
            cout << "Your number is too big. Try again!" << endl;
        } else{
            printf("You've done it! You guessed the number %i in %i guesses!\n",n_random,cnt);
            to_guess = false;
        }
    }
    


    return 0;
}