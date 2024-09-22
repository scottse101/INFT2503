#include <iostream>
#include <string>

using namespace std;

int main() {
    string word1, word2, word3;
    cout << "Skriv inn tre ord: ";
    cin >> word1 >> word2 >> word3;

    string sentence = word1 + " " + word2 + " " + word3 + ".";
    cout << "Setningen er: " << sentence << endl;

    cout << "Lengden på '" << word1 << "' er: " << word1.length() << endl;
    cout << "Lengden på '" << word2 << "' er: " << word2.length() << endl;
    cout << "Lengden på '" << word3 << "' er: " << word3.length() << endl;
    cout << "Lengden på setningen er: " << sentence.length() << endl;

    string sentence2 = sentence;
    cout << "Setning 2 er: " << sentence2 << endl;

    if (sentence2.length() >= 12) {
        sentence2[9] = 'x';  
        sentence2[10] = 'x';
        sentence2[11] = 'x';
    }
    cout << "Setning 1: " << sentence << endl;
    cout << "Setning 2 etter endring: " << sentence2 << endl;

    if (sentence.length() >= 5) {
        string sentence_start = sentence.substr(0, 5); 
        cout << "De fem første tegnene er: " << sentence_start << endl;
    }

    size_t found = sentence.find("hallo");
    if (found != string::npos) {
        cout << "'hallo' er funnet på posisjon: " << found << endl;
    } else {
        cout << "'hallo' ble ikke funnet i setningen." << endl;
    }

    size_t pos = sentence.find("er");
    while (pos != string::npos) {
        cout << "'er' funnet på posisjon: " << pos << endl;
        pos = sentence.find("er", pos + 1);
    }

    return 0;
}
