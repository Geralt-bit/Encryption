#include <iostream>
#include <string>
using namespace std;

// Function to perform Caesar encryption or decryption on a word
string caesarCipher(const string word, int shift, bool encrypt) {
    string result = "";

    for (char letter : word) {
        if (isalpha(letter)) {
            char base = isupper(letter) ? 'A' : 'a';
            int modifier = encrypt ? 1 : -1;  // 1 for encryption : -1 for decryption
            result += static_cast<char>((letter - base + modifier * shift + 26) % 26 + base);
        }
        else {
            result += letter;
        }
    }
    return result;
}

int main() {
    int shift;
    string word;
    char choice;

    cout << "Do you want to (E)ncrypt or (D)ecrypt? ";
    cin >> choice;

    bool encrypt;
    if (toupper(choice) == 'E') {
        encrypt = true;
    }
    else if (toupper(choice) == 'D') {
        encrypt = false;
    }

    cout << "Enter the word: ";
    cin >> word;

    cout << "Enter key (number of positions to shift): ";
    cin >> shift;

    if (encrypt) {
        cout << "Encrypted word: " << caesarCipher(word, shift, true) << endl;
    }
    else {
        cout << "Decrypted word: " << caesarCipher(word, shift, false) << endl;
    }

    return 0;
}
