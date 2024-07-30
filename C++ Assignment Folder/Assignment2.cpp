#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

vector<string> addName(vector<string> someDataBase) {
    cout << "What game would you like to add?\n";
    string videoGameName;
    getline(cin, videoGameName);
    someDataBase.push_back(videoGameName);
    return someDataBase;
}

vector<string> editName(vector<string> someDataBase) {
    cout << "What game would you like to edit?\n";
    string videoGameName;
    getline(cin, videoGameName);
    auto found = find(someDataBase.begin(), someDataBase.end(), videoGameName);
    if(found != someDataBase.end()) {
        cout << "What would you like to change it to?\n";
        string editedName;
        getline(cin, editedName);
        *found = editedName;
    } else {
        cout << "That game is not in the database. Try again.\n";
    }
    return someDataBase;
}

vector<string> removeName(vector<string> someDataBase) {
    cout << "What game would you like to remove?\n";
    string videoGameName;
    getline(cin, videoGameName);
    auto found = (find(someDataBase.begin(), someDataBase.end(), videoGameName));
    if(found != someDataBase.end()) {
        someDataBase.erase(found);
    } else {
        cout << "That game is not in the database. Try again.\n";
    }
    return someDataBase;
}

void showNames(vector<string> someDataBase) {
    sort(someDataBase.begin(), someDataBase.end());
    for(int i = 0; i < someDataBase.size(); i++) {
        cout << i+1 << ". " << someDataBase[i] << "\n";
    }
}

string toLower(string someString) {
    for (auto& x : someString) {
        x = tolower(x);
    }
    return someString;
}

int main() {
    vector<string> favoriteGamesList {"XCOM 2", "Team Fortress 2"};
    string input;

    cout << "Hello Gamer, what would you like to do?\n";
    cout << "type 'add' to add a game to the list\n";
    cout << "type 'edit' to edit a game on the list\n";
    cout << "type 'remove' to remove a game from the list\n";
    cout << "type 'show' to show the list of games\n";
    cout << "type 'quit' to quit the program\n";

    getline(cin, input);
    input = toLower(input);
    
    do {

        if(input == "add") {
            favoriteGamesList = addName(favoriteGamesList);
            cout << "What would you like to do now?\n";
            getline(cin, input);
            input = toLower(input);
        } else if(input == "edit") {
            favoriteGamesList = editName(favoriteGamesList);
            cout << "What would you like to do now?\n";
            getline(cin, input);
            input = toLower(input);
        } else if(input == "remove") {
            favoriteGamesList = removeName(favoriteGamesList);
            cout << "Remove successful, what would you like to do?\n";
            getline(cin, input);
            input = toLower(input);
        } else if(input == "show") {
            showNames(favoriteGamesList);
            cout << "Here's your list! What would you like to do?\n";
            getline(cin, input);
            input = toLower(input);
        } else if(input == "quit") {
            break;
        } else {
            cout << "That is not a valid input.\n";
            cout << "Please type in a valid input\n";
            getline(cin, input);
            input = toLower(input);
        }

        
    } while (input != "quit");

    cout << "Thanks for using my program!\n";

    return 0;
}