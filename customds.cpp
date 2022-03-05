#include <iostream>
#include <string>
#include "customds.h"
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
        if (position>Length) {
            cout<< "Warning! earlier indices are not assigned.";
        }
        Items[position] = value;
    }
    int Return(int index) {
        if ( index>0 && index<Length ) {
            return Items[index];
        }
        return Default;
    }
    int Find(int value) {
        for ( int i=0; i<Length; ++i ) {
            if ( Items[i] == value ) {
                return i;
            }
        return -1; //-1 indicates that the value/number was not found
        }
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
