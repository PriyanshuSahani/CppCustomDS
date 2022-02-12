#include<iostream>
#include<string>

using namespace std;

//Creating a dynamic and easy to use array of type int
class Array {
private:
    int Capacity = 2;
    int Length; // Number of elements the array currently holds
    int *Items = new int[2];
    int Default; // Value returned when user trie to access out of bound element
    
    void Resize(double factor) {
        cout<< "Factor = "<< int(factor)<< endl;
        int *pTemp = new int[int(Capacity*factor)];
        for ( int i=0; i<Length; ++i ) {
            pTemp[i] = Items[i];
        }
        int *Items = pTemp;
        Capacity = int(Capacity*factor);
    }
    void Delete( int position ) {
        Capacity/=2;
        int *pDeleter = new int[Capacity];
        int count = 0;
        for ( int i=0; i<Length; ++i ) {
            if ( i!=position ) {
                pDeleter[count] = Items[i];
                ++count;
            }

        }
        
        int *Items = pDeleter;
    }
public:
    Array(int size, int default_val = 0) {
        Length = 0;
        Resize(size/2);
        Capacity = size;
        Default = default_val;
    }
    void Print() {
        for ( int i=0; i<Length; ++i ) {
            cout<< Items[i]<< endl;
        }
    }
    int GetLength() {
        return Length;
    }
    void Shrink() {
        if ( Length<=Capacity/2 ) {
            Resize(0.5);
        }
    }
    void Append(int value) {
        if (Length == Capacity) {
            Resize(2);
        }
        Items[Length] = value;
        ++Length;
    }
    void Insert(int value, int position) {
        Items[position] = value;
    }
    int Return(int index) {
        if ( index>0 && index<Length ) {
            return Items[index];
        }
        return Default;
    }
    int GetCapacity() {
        return Capacity;
    }
    void DeleteIndex(int pos) {
        if ( (pos>=0) && (pos<Length) ) {
            if (Length>Capacity/4) {
                cout<< "Primary deltion:"<< endl;
                for ( int i=pos; i<(Length-1); ++i ) {
                    Items[i] = Items[i+1];
                }
                Items[Length-1] = Default;
            } else {
                cout<< "Redirecting to secondary:"<< endl;
                Delete(pos);
            }
            -- Length;
        
        }
    }
};

int main() {
    cout<< "\n============"<< endl;
    Array a1(4);// Create
    cout<< "Just created:"<< endl;
    cout<< "Length = "<< a1.GetLength()<< endl;
    cout<< "Capacity = "<< a1.GetCapacity()<< endl;
    // Add elements
    cout<< "Added limitted elements:"<< endl;
    for (int i=0; i<4; ++i) {
        a1.Append(2*i);
    }
    cout<< "Length = "<< a1.GetLength()<< endl;
    cout<< "Capacity = "<< a1.GetCapacity()<< endl;
    cout<< "Printing:"<< endl;
    a1.Print();
    // Remove elements
    // cout<< "Deleting element 1:"<< endl;
    // a1.DeleteIndex(1);
    // cout<< "Length = "<< a1.GetLength()<< endl;
    // cout<< "Capacity = "<< a1.GetCapacity()<< endl;
    // cout<< "Printing:"<< endl;
    // a1.Print();

    cout<< "Added extra elements:"<< endl;
    for (int i=4; i<8; ++i) {
        a1.Append(2*i);
    }
    cout<< "Length = "<< a1.GetLength()<< endl;
    cout<< "Capacity = "<< a1.GetCapacity()<< endl;
    cout<< "Printing:"<< endl;
    a1.Print();
    cout<< "Return value at 3; Expected 6:"<< endl;
    cout<< a1.Return(3)<< endl;

    cout<< "Deleting 7 elements:"<< endl;
    a1.DeleteIndex(0);
    a1.DeleteIndex(0);
    a1.DeleteIndex(0);
    a1.DeleteIndex(0);
    a1.DeleteIndex(0);
    a1.DeleteIndex(0);
    a1.DeleteIndex(0);
    cout<< "Length = "<< a1.GetLength()<< endl;
    cout<< "Capacity = "<< a1.GetCapacity()<< endl;
    a1.Print();

    

}






