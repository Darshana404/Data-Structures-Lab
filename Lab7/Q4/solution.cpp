// Code for Lab7 - Q4
#include <iostream>
#include <string>

using namespace std;

void processString(string &input) {
    int write = 0;
    for (int read = 0; read < input.length(); read++) {
        if (input[read] == '+') {
            if (write > 0) write--;
        } else {
            input[write++] = input[read];
        }
    }
    for (int i = 0; i < write; i++) {
        cout << input[i];
    }
    cout << endl;
}

int main() {
    string input;
    cin >> input;
    processString(input);
    return 0;
}
