#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(string kalimat) {
    stack<char> stack;
    kalimat.erase(remove(kalimat.begin(), kalimat.end(), ' '), kalimat.end());
    transform(kalimat.begin(), kalimat.end(), kalimat.begin(), ::tolower);

    for (char ch : kalimat) {
        stack.push(ch);
    }

    string reversedKalimat;
    while (!stack.empty()) {
        reversedKalimat += stack.top();
        stack.pop();
    }

    return kalimat == reversedKalimat;
}

int main() {
    string kalimat;
    cout << "Masukkan Kalimat: ";
    getline(cin, kalimat);

    if (isPalindrome(kalimat)) {
        cout << "Kalimat tersebut adalah: Palindrom" << endl;
    } else {
        cout << "Kalimat tersebut adalah: Bukan Palindrom" << endl;
    }

    return 0;
}
