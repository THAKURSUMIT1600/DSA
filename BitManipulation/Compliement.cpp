#include <iostream>
using namespace std;

string onesComplement(string binary)
{
    for (int i = 0; i < binary.size(); i++)
    {
        if (binary[i] == '1')
        {
            binary[i] = '0';
        }
        else
        {
            binary[i] = '1';
        }
    }
    return binary;
}

string twosComplement(string binary)
{
    for (int i = 0; i < binary.size(); i++)
    {
        if (binary[i] == '1')
        {
            binary[i] = '0';
        }
        else
        {
            binary[i] = '1';
        }
    }
    int carry = 1;

    for (int i = binary.size() - 1; i >= 0; i--)
    {
        if (carry == 0)
            break;

        if (binary[i] == '1')
        {
            binary[i] = '0';
            carry = 1;
        }
        else
        {
            binary[i] = '1';
            carry = 0;
        }
    }

    return binary;
}

int main()
{
    int choice;
    int dec;
    cout << "Enter Decimal number: ";
    cin >> dec;

    string binary = "";
    while (dec > 0)
    {
        int remainder = dec % 2;
        binary.insert(binary.begin(), remainder + '0');
        dec = dec / 2;
    }
    while (binary.length() < 8)
    {
        binary.insert(binary.begin(), '0');
    }

    cout << "Bit Manipulation Program\n";
    cout << "1. 1's Complement\n";
    cout << "2. 2's Complement\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        string result = onesComplement(binary);
        cout << "1's Complement: " << result << endl;
    }
    else if (choice == 2)
    {
        string result = twosComplement(binary);
        cout << "2's Complement: " << result << endl;
    }
    else
    {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}