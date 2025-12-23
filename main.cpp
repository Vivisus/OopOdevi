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
arr1.push(20);
arr1.push(30);
arr1.print(); // Çıktı: [10, 20, 30]
// 2. İndeksleme operatörü
arr1[1] = 25;
cout << "arr1[1] = " << arr1[1] << endl; // Çıktı: 25
// 3. Birleştirme operatörü
DynamicArray arr2;
arr2.push(40);
arr2.push(50);
DynamicArray arr3 = arr1 + arr2;
arr3.print(); // Çıktı: [10, 25, 30, 40, 50]
// 4. SortedArray testi
SortedArray sorted;
sorted.push(50);
sorted.push(10);
sorted.push(30);
sorted.push(20);
sorted.print(); // Çıktı: [10, 20, 30, 50]
int index = sorted.binarySearch(30);
cout << "30 bulundu, indeks: " << index << endl;
// 5. UniqueArray testi
UniqueArray unique;
unique.push(10);
unique.push(20);
unique.push(10); // Bu eklenmemeli
unique.push(30);
unique.print(); // Çıktı: [10, 20, 30]
cout << "20 var mı? " << (unique.contains(20) ? "Evet" : "Hayır") << endl;
return 0;
}