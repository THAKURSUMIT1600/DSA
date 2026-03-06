#include <iostream>
using namespace std;

int binaryToDecimal(string binary)
{
    int result = 0;
    int power = 1;

    for (int i = binary.size() - 1; i >= 0; i--)
    {
        if (binary[i] == '1')
        {
            result += power;
        }
        power *= 2;
    }

    return result;
}

string decimalToBinary(int decimal)
{
    if (decimal == 0)
        return "0";

    string result = "";
    while (decimal > 0)
    {
        int remainder = decimal % 2;
        result.insert(result.begin(), remainder + '0');
        decimal = decimal / 2;
    }

    return result;
}

int main()
{
    int choice;
    cout << "Choose conversion:\n";
    cout << "1. Binary to Decimal\n";
    cout << "2. Decimal to Binary\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        string binary;
        cout << "Enter binary number: ";
        cin >> binary;
        int decimal = binaryToDecimal(binary); // Call the empty function
        cout << "Decimal equivalent: " << decimal << endl;
    }
    else if (choice == 2)
    {
        int decimal;
        cout << "Enter decimal number: ";
        cin >> decimal;
        string binary = decimalToBinary(decimal); // Call the empty function
        cout << "Binary equivalent: " << binary << endl;
    }
    else
    {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}