//Would you do it for a scooby snack?
using namespace std;
#include <iostream>
#include <string>

const string NUMBERS[10]={"ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN"};

int main(void){
    cout << "Would you do it for a Scooby Snack? ";
    string response;
    getline(cin,response);
    int tries = 1;
    while (response.compare("Rokay") != 0){
        cout << "Would you do it for " << NUMBERS[tries] << " Scooby Snacks? ";
        cin >> response;
        ++tries;
    }
    cout << "Here you go boy!\n";
    return 0;
}