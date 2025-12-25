#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>
using namespace std;
class DynamicArray{
    private:
    int* data; // Heap bellekteki dizinin başlangıç adresini tutar
    int size;  // Dizideki eleman sayısı
    int capacity;  // Dizinin toplam kapasitesi
public:
    DynamicArray();                         
    DynamicArray(int cap);                  
    DynamicArray(const DynamicArray& orijinal); 
    virtual ~DynamicArray();    // İleride miras alan yapıların ürettiği sınıflar silindiğinde bellek sızıntısı olmaması için

    virtual void push(int value); // türetilmiş sınıflar değiştireceği için virtual
    void pop();
    int get(int index) const;
    void set(int index, int value);
    int getSize() const;
    int getCapacity() const;
    bool isEmpty() const;
    void clear();
    void print() const;

    int& operator[](int index);               
    //Toplama operatörü               
    DynamicArray operator+(const DynamicArray& other) const; 
    // Atama operatörü
    DynamicArray& operator=(const DynamicArray& other);  
    //Karşılaştırma operatörleri
    bool operator==(const DynamicArray& other) const;      
    bool operator!=(const DynamicArray& other) const;       
    //Çıktı operatörü
    friend ostream& operator<<(ostream& os, const DynamicArray& arr);
protected:
void resize();
};

#endif
