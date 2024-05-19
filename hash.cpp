#include "../commons.cpp"
#include "listaDuplamenteEncadeada.cpp"

#define TAM 8

template <typename hashType>
struct Hash{
    private:  DLinkedList<hashType> dLinkedListVector[TAM];
    
    private: int unlock(int key){
        key = key%TAM;
        return key;
    }

    public: bool insert(hashType member, int key){
        int position = unlock(key);

        if(dLinkedListVector[position].insert(member)) return true;
        return false;
    }

    public: bool remove(hashType member, int key){
        int position = unlock(key);

        if(dLinkedListVector[position].remove(member)) return true;
        return false;
    }

    public: void show(){
        for(int i = 0; i < TAM; i++){
            cout << i+1 << " - ";
            dLinkedListVector[i].show();
            cout << "\n";
        }
    }
};
