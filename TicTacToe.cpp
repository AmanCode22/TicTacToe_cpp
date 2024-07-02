#include <iostream>
#include <ctime>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>

using namespace std;

string printBoard(vector<string>& user, vector<string>& robo) {
    string board = "|T1| |T2| |T3|\n"
                   "|M1| |M2| |M3|\n"
                   "|B1| |B2| |B3|\n";

    for (const string& u : user) {
        size_t pos = board.find(u);
        if (pos != string::npos) {
            board.replace(pos, u.length(), "O");
        }
    }

    for (const string& r : robo) {
        size_t pos = board.find(r);
        if (pos != string::npos) {
            board.replace(pos, r.length(), "X");
        }
    }

    return board;
}

bool winLogic(vector<string>& trophy, vector<vector<string>>& winLogic_) {
    vector<bool> possible;

    for (int j = 0; j < winLogic_.size(); j++) {
        for (int k = 0; k < winLogic_[j].size(); k++) {
            string jk = winLogic_[j][k];
            if ((find(trophy.begin(), trophy.end(), jk) != trophy.end())) {
                possible.push_back(true);
            }
        }
        if (possible.size() == 3) {
            return true;
        } else {
            possible.clear();
        }
    }
    return false;
}

int indexOf(string arr[], int len, string item) {
    for (int j = 0; j < len; j++) {
        if (item == arr[j]) {
            return j;
        }
    }
    return -1;
}

vector<string> removeItem(string arr[], int len, string item) {
    vector<string> final;
    for (int j = 0; j < len; j++) {
        if (item != arr[j]) {
            final.push_back(arr[j]);
        }
    }
    return final;
}

void doIt(string dt_[], int len) {
    vector<string> user;
    vector<string> robo;
    vector<string> dt(dt_, dt_ + len); // Convert array to vector
    vector<string> board_dt = dt;
    vector<vector<string>> winLogic_ = {
        {"M1", "T1", "B1"}, {"T1", "T2", "T3"}, {"B1", "B2", "B3"},
        {"M1", "M2", "M3"}, {"M2", "T2", "B2"}, {"M3", "T3", "B3"},
        {"T1", "M2", "B3"}, {"T3", "M2", "B1"}
    };

    bool whl = true;
    while (whl) {
        string input;
        cout << "Your turn::: ";
        cin >> input;
        transform(input.begin(), input.end(), input.begin(), ::toupper);
        int ind = indexOf(dt.data(), dt.size(), input);
        if (ind == -1) {
            cout << "Invalid input. Try again!\n";
            continue;
        }
        cout << input << " occupied by you\n";
        dt = removeItem(dt.data(), dt.size(), input); // Update dt using removeItem
        user.push_back(input);
        if (winLogic(user, winLogic_)) {
            cout << "User won!!!!!\n";
            cout << printBoard(user, robo);
            return;
        }
        srand(time(NULL));
        int random = rand();
        random = random % dt.size();
        string dta = dt[random];
        dt = removeItem(dt.data(), dt.size(), dta);
        robo.push_back(dta);
        cout << "Robot occupied " << dta << "\n";
        if (winLogic(robo, winLogic_)) {
            cout << "Robot won!!!!!\n";
            cout << printBoard(user, robo);
            return;
        }
        cout << "FOLLOWING ARE LEFT:-\n";
        for (const string& jk : dt) {
            cout << jk << "\n";
        }
        cout << "This is the updated board with 'O' as user and 'X' as robot:\n";
        cout << printBoard(user, robo);
        if (dt.empty()) { // Check if dt is empty
            whl = false;
        }
    }
}

int main(int argc, char* argv[]) {
    cout << "      ||||||| •• TIC TAC TOE BY AMAN ADLAKHA •• |||||||\n";
    cout << "THE INDEX OF THE GAMEBOARD ARE:-\n";
    cout << "|T1| |T2| |T3|\n";
    cout << "|M1| |M2| |M3|\n";
    cout << "|B1| |B2| |B3|\n";

    string data[9] = {"T1", "T2", "T3", "M1", "M2", "M3", "B1", "B2", "B3"};

    doIt(data, 9);

    return 0;
}