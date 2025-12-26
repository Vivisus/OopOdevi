#include "SortedArray.h"
#include <iostream>
//Constructorlar
SortedArray :: SortedArray() :DynamicArray(){}
SortedArray :: SortedArray(int capasity): DynamicArray(capasity){}
SortedArray :: SortedArray(const SortedArray& other) : DynamicArray(other){}

void SortedArray :: push(int deger){
    DynamicArray::push(deger);
    int boyut = getSize();
    int index = boyut -1;
    //swap işlemi yapılıyor
    while( index >0 && get(index)< get(index-1)){
        int temp = get(index); //anlık değer
        int prev = get(index-1); // önceki değer
        //değerler yer değiştiriyor
        set(index,prev);
        set(index-1, temp);
        index --;
    }
}
int SortedArray::binarySearch(int aranandeger){
    int baslangic = 0;
    int son = getSize() -1;
    while (baslangic <=son){
        int ortadeger = (baslangic + son)/2;
        if (aranandeger > get(ortadeger)){
            //orta değere bakıldığı için bir fazla/eksik kısmına bakılıyor
            baslangic = ortadeger +1;
        }else if (aranandeger < get(ortadeger)){
            son = ortadeger -1;
        }else{
             cout<< "Aranan değer bulundu indeksi: ";
            return ortadeger;
        } 
    }
    cout<< "Aranan değer bulunamadı";
        return -1;
}