#include "UniqueArray.h"
#include <iostream>
#include "DynamicArray.h"

using namespace std;


UniqueArray::UniqueArray() : DynamicArray() {}

UniqueArray::UniqueArray(int capacity) : DynamicArray(capacity) {}

bool UniqueArray::contains(int value) const {
    for (int i = 0; i < getSize(); i++) {
        if (get(i) == value) {
            return true; // dizide eleman bulundu
        }
    }
    return false; // dizide eleman bulunamadı
}


void UniqueArray::push(int value) {
    //dizide eleman var mı kontrol et
    if (!contains(value)) {
        
        DynamicArray::push(value); //dizide yoksa ekle
    } else {
        cout << value << " degeri zaten dizide mevcut, eklenmedi." << endl;
    }
}

