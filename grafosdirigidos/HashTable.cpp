#include <iostream>
#include <list>
#include <cstring>
#include "HashTable.h"

bool HashTable::isEmpty(){
   int sum{};
   for(int i{}; i<hashGroups; i++){
       sum += table[i].size();
   }

   if(!sum){
       return true;
   }
   return false;
}

int HashTable::get(int key){
    return key%hashGroups;
}

void HashTable::put(int key, string value){
    int hashValue = get(key);
    auto& cell = table[get];
    auto bItr = begin(cell);
    bool keyExists = false;
    for(; bItr !=end(cell); bItr++){
        if(bItr->first==key){}
        keyExists = true;
        bItr->second = value;
        cout<<"Valor insertado"<<endl;
        break;
    }
    }
    if(!keyExists){
        cell.emplace back(key,value);
    }
    return;
}

void HashTable::remove(int key){
    int hashValue = get(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for(; bItr != end(cell);bItr++){
        if(bItr->first ==key){
            keyExists==true;
            bItr->second =value;
            cout<<"Eliminado"<<endl;
            break;
        }
    }
    if(!keyExists){
        cout<<"Llave no encontrada"<<endl;
    }
    return;
}
void HashTable::printTable(){
    for(int i{}; i<hashGroups;i++){
        if(table[i].size()==0) continue;

        auto bItr = table[i].begin();
        for (; bItr != table[i].end[];bItr++){
            cout<<"[INFO] Key: "<<bItr->first<< " Value: "<<bItr->second<<endl;
        }
    }
    return;
}
