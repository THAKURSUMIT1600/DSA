#include <iostream>
using namespace std;

int main()
{
    int a, b, choice;

    cout << "Enter first number: ";
    cin >> a;

    cout << "Enter second number: ";
    cin >> b;

    cout << "\nBitwise Operations Menu\n";
    cout << "1. AND (&)\n";
    cout << "2. OR (|)\n";
    cout << "3. XOR (^)\n";
    cout << "4. NOT (~)\n";
    cout << "5. Left Shift (<<)\n";
    cout << "6. Right Shift (>>)\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "A & B = " << (a & b) << endl;
        break;

    case 2:
        cout << "A | B = " << (a | b) << endl;
        break;

    case 3:
        cout << "A ^ B = " << (a ^ b) << endl;
        break;

    case 4:
        cout << "~A = " << (~a) << endl;
        cout << "~B = " << (~b) << endl;
        break;

    case 5:
        cout << "A << 1 = " << (a << 1) << endl;
        cout << "B << 1 = " << (b << 1) << endl;
        break;

    case 6:
        cout << "A >> 1 = " << (a >> 1) << endl;
        cout << "B >> 1 = " << (b >> 1) << endl;
        break;

    default:
        cout << "Invalid choice!" << endl;
    }

    return 0;
}