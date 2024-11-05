#include <iostream>
#include <stack>
#include <sstream>
#include <string>

using namespace std;

string reverseWords(string sentence) {
    stack<char> stack;
    stringstream ss(sentence);
    string word, reversedSentence;

    while (ss >> word) {  
        for (char ch : word) {
            stack.push(ch);
        }

        while (!stack.empty()) {
            reversedSentence += stack.top();
            stack.pop();
        }
        reversedSentence += " ";  
    }

    if (!reversedSentence.empty()) {
        reversedSentence.pop_back();
    }

    return reversedSentence;
}

int main() {
    string kalimat;
    cout << "Masukkan Kalimat (minimal 3 kata): ";
    getline(cin, kalimat);

    string hasil = reverseWords(kalimat);
    cout << "Hasil: " << hasil << endl;

    return 0;
}
