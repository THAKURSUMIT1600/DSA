#include <iostream>
using namespace std;

int main() {
    cout << "Welcome to Array Game" << endl;

    int size;
    cout << "Enter the array size: ";
    cin >> size;

    int* arr = new int[size];
    int count = 0;
    int option;

    while (true) {
        cout << "\nSelect the Following Option\n";
        cout << "Press 1 for Inserting element\n";
        cout << "Press 2 for Deleting element\n";
        cout << "Press 3 for Updating element\n";
        cout << "Press 4 for Printing element\n";
        cout << "Press 5 for Exit\n";
        cin >> option;

        if (option == 1) {
            // INSERT STRUCTURE
            cout << "Insert operation selected\n";
             int pos,value;
            cout<<"Enter the Position"<<endl;
            cin>>pos;
            if (pos < 0 || pos > count || count >= size) {
                cout << "Invalid Position or Array Full!";
            } else {
                cout<<"Enter the Value"<<endl;
                cin>>value;
                for(int i=count;i>pos;i--){
                    arr[i]=arr[i-1];
                }
                arr[pos]=value;
                count++;
                cout << "Element Inserted!" << endl;
            } 
        }

        else if (option == 2) {
            // DELETE STRUCTURE
            cout << "Delete operation selected\n";
             int pos;
            cout<<"Enter the Position"<<endl;
            cin>>pos;
            if (pos < 0 || pos >= count) {
                cout << "Invalid Position!";
            } else {
               
               for(int i=pos;i<count-1;i++){
                arr[i]=arr[i+1];
            }
            count--;
            cout << "Element Deleted!" << endl;
            } 
        }

        else if (option == 3) {
            // UPDATE STRUCTURE
            cout << "Update operation selected\n";
            int pos,value;
            cout<<"Enter the Position"<<endl;
            cin>>pos;
            if (pos < 0 || pos >= count) {
                cout << "Invalid Position!";
            } else {
                cout << "Enter new value: ";
                cin >> value;
                arr[pos] = value;
                cout << "Element Updated!";
            }
        }

        else if (option == 4) {
            // PRINT STRUCTURE
            cout << "Print operation selected\n";
            if(count==0){
                cout<<"Array is Empty"<<endl;
            }
            else{
                for(int i=0;i<count;i++){
                    cout<<arr[i]<<" ";
                }
                cout << endl;
            }
        }

        else if (option == 5) {
            // EXIT STRUCTURE
            cout << "Exiting Program...\n";
            break;
        }

        else {
            cout << "Invalid Option!\n";
        }
    }

    delete[] arr;
    return 0;
}
