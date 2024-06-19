#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;


vector<int> generateLuckyNumbers() {
    vector<int> numbers(48);
    for (int i = 0; i < 48; ++i) {
        numbers[i] = i + 1;
    }

    random_shuffle(numbers.begin(), numbers.end());
    vector<int> luckyNumbers(numbers.begin(), numbers.begin() + 35);
    sort(luckyNumbers.begin(), luckyNumbers.end());
    return luckyNumbers;
}


vector<int> getUserNumbers() {
    vector<int> userNumbers;
    int num;
    cout << "Unesite vasih 6 brojeva (1-48): " << endl;
    for (int i = 0; i < 6; ++i) {
        do {
            cout << "Broj " << i + 1 << ": ";
            cin >> num;
        } while (num < 1 || num > 48);
        userNumbers.push_back(num);
    }
    sort(userNumbers.begin(), userNumbers.end());
    return userNumbers;
}


int countMatches(const vector<int>& luckyNumbers, const vector<int>& userNumbers) {
    int matches = 0;
    for (int num : userNumbers) {
        if (find(luckyNumbers.begin(), luckyNumbers.end(), num) != luckyNumbers.end()) {
            ++matches;
        }
    }
    return matches;
}

int main() {
    srand(time(0));

    vector<int> luckyNumbers = generateLuckyNumbers();
    vector<int> userNumbers = getUserNumbers();

    cout << "Izvuceni brojevi su: ";
    for (int num : luckyNumbers) {
        cout << num << " ";
    }
    cout << endl;

    int matches = countMatches(luckyNumbers, userNumbers);
    cout << "Broj pogodaka: " << matches << endl;

    if (matches == 6) {
        cout << "Cestitamo! Pogodili ste svih 6 brojeva!" << endl;
    }
    else {
        cout << "Pokusajte ponovo." << endl;
    }

    return 0;
}
