#include<iostream>
using namespace std;

int main() {
    cout << "Enter: ";
    string str = "";
    int sum = 0;

    while (str != "$") {
        int temp = 0;

        cin >> str;

        for (int i = 0; i < str.length(); i++) {
            if (str[i] >= '0' && str[i] <= '9') {
                temp = 10 * (str[i] - '0');
                break;
            }
        }
        

        for (int i = str.length() - 1; i >= 0; i--) {
            if (str[i] >= '0' && str[i] <= '9') {
                temp = temp + (str[i] - '0');
                break;
            }
        }

        sum += temp;
    }

    cout << "\nSum is: " << sum;
}
