#include "DynamicArray.h"
#include <iostream>


//varsayılan constructor
DynamicArray::DynamicArray(){
    capacity = 2;
    size = 0;
    data = new int[capacity];
}
//parametreli constructor
DynamicArray:: DynamicArray(int kapasite){
    capacity = kapasite;
    size = 0;
    //Eğer verilen parametre negatif,0,1 gibi anlamsız değerlerse min 2 değerinden başlar
    if(capacity<2){
        capacity = 2;
    }
    data = new int[capacity];
}
//kopyalama constructor:
DynamicArray :: DynamicArray(const DynamicArray& orijinal){
    capacity = orijinal.capacity;
    size = orijinal.size;
    data = new int[capacity];
    for(int i = 0; i<size; i++){
        data[i] = orijinal.data[i];
    }
}
//destructor
DynamicArray::~DynamicArray(){
    if (data != nullptr){
        delete[] data;
    }   
}
//kapasite arttırma
void DynamicArray::resize(){
     capacity = 2* capacity;
        int* yeniDizi = new int[capacity];
        for (int i = 0; i < size; i++){
            yeniDizi[i] = data[i];
        }
        delete[] data;
        data = yeniDizi;
}
//push  
void DynamicArray::push(int deger){
    if (size == capacity){
       resize();
    }
    //size değişkeni her zaman bir sonraki boş yerin indeksini gösterir.
    data[size] = deger;
    size ++;
    
}
//pop
void DynamicArray::pop(){
    if(size>0){
        size = size -1;

    }else{
        cout<<"Dizi bos, eleman silinemez!!"<<endl;
    }
}
//get
int DynamicArray::get(int index) const{
    if (index<0 || index>= size){
        cout<< "İstenilen indekste veri yok"<< endl;
        return -1;
    }
    return data[index];
}
//set
void DynamicArray::set(int index, int value){
    if (index<0 || index >= size){
        cout<< "Aranan degerde degistirilecek veri yok"<<endl;
    }else{
        data[index] = value;
    }
    
}
//size döndürme
int DynamicArray::getSize() const{
    return size;
}
//kapasite döndürme
int DynamicArray::getCapacity() const{
    return capacity;
}
//dizi boş mu kontrol
bool DynamicArray::isEmpty() const{
    if(size == 0){
        return true;
    }else{
        return false;
    }
}
//dizi elemanlarını temizleme
void DynamicArray::clear(){
    size = 0;
}
//diziyi ekrana yazdırma
void DynamicArray::print() const{
    cout<<"[";
    for(int i = 0; i < size; i++){
        cout << data[i];
        if(i < size-1){
            cout<< ",";
        }
    }
    cout<<"]"<< endl;
}
//indeksleme operatörü
int& DynamicArray::operator[](int index){
    if (index<0|| index>=size)
    {
        cout<<"Belirtilen indeks gecersiz"<< endl;
        return data[0];
    }
    return data[index];
}
//atama operatörü
DynamicArray& DynamicArray::operator=(const DynamicArray& orijinal){
    if(this == &orijinal){
        return *this;
    }
    delete[] data;
    size = orijinal.size;
    capacity = orijinal.capacity;
    data = new int[capacity];
    for(int i = 0; i<size;i++){
        data[i]= orijinal.data[i];
    }
    //this adresteki nesnenin kendisidir
    return *this;
}
//iki diziyi birleştirme operatörü
DynamicArray DynamicArray::operator+(const DynamicArray& orijinal) const{
    int yenikapasite = size + orijinal.size;
    DynamicArray yeniDizi(yenikapasite);
    int i;
    for(i = 0; i<size; i++){
        yeniDizi.push(data[i]);
    }
    for ( i = 0; i < orijinal.size; i++){
        yeniDizi.push(orijinal.data[i]);
    }
    return yeniDizi;
}
//iki dizinin eşitlik operatörü
bool DynamicArray::operator==(const DynamicArray& orijinal) const{
    if (size != orijinal.size){
        return false;
    }
    for(int i = 0; i < size; i++){
        if (data[i] != orijinal.data[i]){
            return false;
        }
    }
   
    return true;
    
}
//iki dizinin fark operatörü
bool DynamicArray::operator!=(const DynamicArray& orijinal)const{
    if (size != orijinal.size){
        return true;
    }
    for(int i = 0; i< size; i++){
        if(data[i] != orijinal.data[i]){
            return true;
        }
    }
    return false;
}
// os, output stream 
ostream& operator<<(ostream& os, const DynamicArray& arr) {
    os << "[";
    for (int i = 0; i < arr.size; i++) {
        os << arr.data[i];
        if (i < arr.size - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}