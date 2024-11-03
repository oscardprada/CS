#include <iostream>
#include <algorithm>
using namespace std;

string addBinary(string a, string b) {
        string ans;
        int i, j;
        i = a.size() - 1;
        j = b.size() - 1;
        for (int carry = 0; i >= 0 || j >= 0 || carry; --i, --j) {
            carry += (i >= 0 ? a[i] - '0' : 0) + (j >= 0 ? b[j] - '0' : 0);
            ans.push_back((carry % 2) + '0');
            carry /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }


int main(){
    string num1, num2;

    cout << "Sum of two binary numbers\n";
    cout << "Type a number: ";
    cin >> num1;
    cout << "Type another number: ";
    cin >> num2;

    cout << addBinary(num1, num2);

return 0;

}