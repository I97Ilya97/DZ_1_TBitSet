#ifndef TBITSET_H
#define TBITSET_H

#include <cstdlib>
#include <string>
#include <iostream>

class TBitSet
{
private:
    bool * Data;
    size_t d_size;
public:
    TBitSet()
    {
        Data = new bool[1];
        d_size = 1;
    }
    TBitSet(bool * data, size_t data_size)
    {

        std::cout<<"Creating new BitSet\n";

        std::cout<<"sizeof(data) = "<<data_size<<"\n";
        Data = new bool[data_size];

        size_t i = 0;
        d_size = data_size;
        if(!data)return;
        while (i<data_size){
            Data[i] = data[i];
            i++;
        }
    }

    ///Через это будем читать из
    ///элемента с номером index
    bool operator[](size_t index) const
    {
        return Data[index];
    }


    ///Через это мы будем записывать
    ///в элемент с номером index
    bool& operator[](size_t index)
    {
        return Data[index];
    }

    bool operator !=(TBitSet& b)
    {
        bool retval = false;
        if(b.size()!=d_size)return retval;
        size_t i = 0;
        while(i<d_size)
        {
            if(Data[i]!=b[i])
            {
                retval = true;
                break;
            }
            i++;
        }
        return retval;
    }
    bool operator ==(TBitSet & b)
    {
        bool retval = true;
        if(b.size()!=d_size)return false;
        size_t i = 0;
        while(i<d_size)
        {
            if(Data[i]!=b[i])
            {
                retval = false;
                break;
            }
            i++;
        }
        return retval;
    }
    bool test(size_t i)
    {
        if(i>d_size)return false;
        return Data[i];
    }
    bool all()
    {
        bool retval = true;
        size_t i = 0;
        while(i<d_size)
        {
            if(!Data[i])
            {
                retval = false;
                break;
            }
            i++;
        }
        return retval;
    }
    bool any()
    {
        bool retval = false;
        size_t i = 0;
        while(i<d_size)
        {
            if(Data[i])
            {
                retval = true;
                break;
            }
            i++;
        }
        return retval;
    }
    bool none()
    {
        bool retval = true;
        size_t i = 0;
        while(i<d_size)
        {
            if(Data[i])
            {
                retval = false;
                break;
            }
            i++;
        }
        return retval;
    }

    size_t count()
    {
        size_t retval = 0;
        size_t i = 0;
        while(i<d_size)
        {
            if(Data[i])
            {
                retval += 1;
            }
            i++;
        }
        return retval;
    }
    size_t size()
    {
        return d_size;
    }

    TBitSet& operator&=(TBitSet& a){

        size_t i = 0;
        TBitSet * retval = this;
        while(i<d_size){
            (*retval)[i] = a[i]&Data[i];
            i++;
        }
        return *retval;

    }
    TBitSet& operator|=(TBitSet& a){

        size_t i = 0;
        TBitSet * retval = this;
        while(i<d_size){
            (*retval)[i] = a[i]|Data[i];
            i++;
        }
        return *retval;

    }
    TBitSet& operator^=(TBitSet& a){

        size_t i = 0;
        TBitSet * retval = this;
        while(i<d_size){
            (*retval)[i] = a[i]^Data[i];
            i++;
        }
        return *retval;

    }
    TBitSet& operator~(void){

        size_t i = 0;
        TBitSet * retval = this;
        while(i<d_size){
            (*retval)[i] = !Data[i];
            i++;
        }
        return *retval;

    }

    TBitSet& operator<<=(size_t i)
    {
        size_t i1 = 0;

        if(i>d_size)
        {
            ///Забить все нулями
            while(i1<d_size)
            {
                Data[i1] = 0;
                i1++;
            }
            return *this;
        }
        ///Сдвинуть нужные данные
        while(i1<(d_size - i))
        {
            Data[i1] = Data[i1+i];
            i1++;
        }
        ///Заполнить появившуюся пустоту нулями
        while(i1<d_size)
        {
            Data[i1] = false;
            i1++;
        }
        return *this;
    }
    TBitSet& operator>>=(size_t i){

        size_t i1 = 0;

        if(i>d_size)
        {
            ///Забить все нулями
            while(i1<d_size)
            {
                Data[i1] = 0;
                i1++;
            }
            return *this;
        }
        ///Сдвинуть нужные данные
        while(i1<(d_size - i))
        {
            Data[(d_size - i1 - 1)] = Data[(d_size - i1 - i - 1)];
            i1++;
        }
        ///Заполнить появившуюся пустоту нулями
        i1 = 0;
        while(i1<i)
        {
            Data[i1] = false;
            i1++;
        }
        return *this;
    }
    TBitSet& operator<<(size_t i)
    {
        bool * data = new bool[d_size];
        size_t i1 = 0;

        if(i>d_size)
        {
            ///Забить все нулями
            while(i1<d_size)
            {
                data[i1] = 0;
                i1++;
            }
            return *(new TBitSet(data, d_size));
        }
        ///Сдвинуть нужные данные
        while(i1<(d_size - i))
        {
            data[i1] = Data[i1+i];
            i1++;
        }
        ///Заполнить появившуюся пустоту нулями
        while(i1<d_size)
        {
            data[i1] = false;
            i1++;
        }
        return *(new TBitSet(data, d_size));
    }
    TBitSet& operator>>(size_t i){
        bool * data = new bool[d_size];
        size_t i1 = 0;

        if(i>d_size)
        {
            ///Забить все нулями
            while(i1<d_size)
            {
                data[i1] = 0;
                i1++;
            }
            return *(new TBitSet(data, d_size));
        }
        ///Сдвинуть нужные данные
        while(i1<(d_size - i))
        {
            data[i1+i] = Data[i1];
            i1++;
        }
        ///Заполнить появившуюся пустоту нулями
        while(i1<d_size)
        {
            data[d_size - (i1+1)] = false;
            i++;
        }
        return *(new TBitSet(data, d_size));
    }
    ///Все забить единицами или значением val
    void set(bool val=1){
        size_t i = 0;
        while(i<d_size){
            Data[i] = val;
            i++;
        }
    }
    ///Забить все нулями
    void reset(){
        size_t i = 0;
        while(i<d_size){
            Data[i] = false;
            i++;
        }
    }
    ///Инвертировать каждое значение
    void flip(){
        size_t i = 0;
        while(i<d_size){
            Data[i] = !Data[i];
            i++;
        }
    }

    ///Преобразовать:
    ///В строку
    std::string to_string(){
        std::string retval;
        size_t i = 0;
        while(i < d_size){
            retval+=(Data[i])?'0':'1';
            i++;
        }
        return retval;

    }
    ///В long
    unsigned long to_ulong(){
        unsigned long retval = 0;
        size_t i = 0;
        while((i<d_size)&&(i<sizeof(unsigned long))){
            retval|=(Data[i])<<i;
            i++;
        }
        return retval;
    }


    TBitSet& operator&(TBitSet& a){
        size_t retval_size = d_size;
        if (a.size()!= d_size){
            retval_size = (a.size()>d_size)?d_size:a.size();
        }

        size_t i = 0;
        TBitSet * retval = new TBitSet(nullptr, retval_size);
        while(i<retval_size){
            (*retval)[i] = a[i]&Data[i];
            i++;
        }
        return *retval;
    }
    TBitSet& operator|(TBitSet& a){
        size_t retval_size = d_size;
        if (a.size()!= d_size){
            retval_size = (a.size()>d_size)?d_size:a.size();
        }

        size_t i = 0;
        TBitSet * retval = new TBitSet(nullptr, retval_size);
        while(i<retval_size){
            (*retval)[i] = a[i]|Data[i];
            i++;
        }
        return *retval;
    }
    TBitSet operator^(TBitSet& a){
        size_t retval_size = d_size;
        if (a.size()!= d_size){
            retval_size = (a.size()>d_size)?d_size:a.size();
        }

        size_t i = 0;
        TBitSet * retval = new TBitSet(nullptr, retval_size);
        while(i<retval_size){
            (*retval)[i] = a[i]!=Data[i];
            i++;
        }
        return *retval;
    }
    std::string operator<<(TBitSet& a){
        return a.to_string();
    }
    TBitSet& operator>>(std::string a){
        char * input = (char *)a.data();
        bool *retval = new bool[a.size()];
        size_t i = 0;
        while(i<a.size()){
            if(input[i]=='0'){
                retval[i] = false;
            }
            else
            {
                retval[i] = true;
            }
        }
        return *(new TBitSet(retval, a.size()));
    }
    ~TBitSet(){
        if(Data){
            delete(Data);
        }
    }

};

#endif
