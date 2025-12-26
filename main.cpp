#include "DynamicArray.h"
#include "SortedArray.h"
#include "UniqueArray.h"
#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
// 1. DynamicArray testi
DynamicArray arr1;
arr1.push(10);
arr1.push(30);
arr1.push(50);
arr1.push(70);
arr1.push(90);
cout<<"arr1 dizisi: " ;
arr1.print(); 
// 2. İndeksleme operatörü
arr1[0] = 20;
arr1[2] = 60;
arr1[4] = 80;
cout << "arr1[0] = " << arr1[0] << endl;
cout << "arr1[2] = " << arr1[2] << endl;
cout << "arr1[4] = " << arr1[4] << endl; 
// get ve set
cout << "get(1) = " << arr1.get(1) << endl;
arr1.set(1,5);
cout << "set(1,5) sonrasi arr1: ";
arr1.print();
//pop
arr1.pop();
cout << "pop() sonrasi arr1: ";
arr1.print();
//isEmpty ve getsize
cout << "arr1 bos mu? " << (arr1.isEmpty() ? "Evet" : "Hayir") << endl;
cout << "arr1 boyutu: " << arr1.getSize() << endl;  
cout << "arr1 capacity: " << arr1.getCapacity() << endl;
// 3. Birleştirme operatörü
DynamicArray arr2;
arr2.push(100);
arr2.push(120);
arr2.push(140);
arr2.push(160);
DynamicArray arr3 = arr1 + arr2;
cout<< "arr1 ve arr2 birlestirildi: ";
arr3.print(); 
//== ve != operatörleri
DynamicArray arr4 = arr1;
cout << "arr4 dizisi: " << arr4 <<endl;
arr1[1] = 8;
cout <<"arr1[1] = 8 olarak degistirildi." << endl;

if(arr1 != arr4){
    cout << "diziler birbirine esit degil."<< endl;
}
else{
    cout <<"diziler birbirine esit." << endl;
}

cout << "arr1 dizisi: " << arr1 << endl;
cout <<"arr4 dizisi: "<<arr4 << endl;

// 4. SortedArray testi
SortedArray sorted;
sorted.push(250);
sorted.push(260);
sorted.push(130);
sorted.push(300);
sorted.push(247);
sorted.push(120);
sorted.print(); 
int index = sorted.binarySearch(247);
cout << index << endl;
int bulunamayanIndex = sorted.binarySearch(500);
cout << bulunamayanIndex << endl;
// 5. UniqueArray testi
UniqueArray unique;
unique.push(40);
unique.push(50);
unique.push(60);
unique.push(70);
cout << "UniqueArray icerigi: ";
unique.print();
unique.push(60);
unique.push(80);
cout<< "UniqueArray icerigi: ";
unique.print();
cout << "60 var mi? " << (unique.contains(60) ? "Evet" : "Hayir") << endl;
cout << "90 var mi? " << (unique.contains(90) ? "Evet" : "Hayir") << endl;
return 0;
}