#ifndef LISTADUPLAMENTEENCADEADA_CPP
#define LISTADUPLAMENTEENCADEADA_CPP
#include "commons.cpp"

template <typename T>
struct NodeD{
    T info;

    NodeD* previous = nullptr;
    NodeD* next = nullptr;
};

template <typename T>
struct DLinkedList{
    NodeD<T>* start = nullptr;
    NodeD<T>* end = nullptr;
    int length = 0;

    //Inserts an information in the end of list.
    public: bool insert(T* inserted){
        NodeD<T>* newNode = new NodeD<T>;
        if (newNode == nullptr) return false;

        newNode->info = *inserted;

        if (end == nullptr) {
            start = newNode;
            end = newNode;
            length++;
            return true;    
        }else {
            newNode->next = start;
            start->previous = newNode;
            start = newNode;
            length++;
            return true;
        }
    }

    bool findCharacter(char c){
        NodeD<T>* targetNodeD = start;
        while(targetNodeD != nullptr){
            if(targetNodeD->info.character == c) return true;
            targetNodeD = targetNodeD->next;
        }
        return false;
    }

    void updateFreq(char c){
        NodeD<T>* targetNodeD = start;
        while(targetNodeD != nullptr){
            if(targetNodeD->info.character == c){
                targetNodeD->info.freq++;
                return;
            }
            targetNodeD = targetNodeD->next;
        }
    }

    void adicionarNaOrdem(T* v){
        NodeD<T>* newNodeD = new NodeD<T>;
        if (newNodeD == nullptr) return;
        
        newNodeD->info = *v;

        if(start == nullptr){
          start = newNodeD;
          end = newNodeD;
          return;
        }
        if(v->freq < start->info->freq){
          start->previous = newNodeD;
          newNodeD->next = start;
          start = newNodeD;
          return;
        }
        if(v->freq > end->info->freq){
          end->next = newNodeD;
          newNodeD->previous = end;
          end = newNodeD;
          return;
        }

        NodeD<T>* targetNodeD = start;
        while(targetNodeD != nullptr){
          if(targetNodeD->info->freq >= v->freq){
            newNodeD->next = targetNodeD;
            newNodeD->previous = targetNodeD->previous;
            targetNodeD->previous = newNodeD;
            newNodeD->previous->next = newNodeD;
            return;
          }
          targetNodeD = targetNodeD->next;
        }
      }

bool estaOrdenada(){
  NodeD<T>* targetNodeD = start;
  while(targetNodeD != nullptr && targetNodeD->next != nullptr){
    NodeD<T>* nextNodeD = targetNodeD->next;
    if(nextNodeD->info.freq < targetNodeD->info.freq){
      return false;
    }      
    targetNodeD = nextNodeD;
  }
  return true;
}

void ordenarLista(){
  while(!this->estaOrdenada()){
    NodeD<T>* targetNodeD = start;
    while(targetNodeD != nullptr && targetNodeD->next != nullptr){
      NodeD<T>* nextNodeD = targetNodeD->next;

      if(nextNodeD->info.freq < targetNodeD->info.freq){
        if(targetNodeD->previous != nullptr){
          targetNodeD->previous->next = nextNodeD;
        }
        if(nextNodeD->next != nullptr){
            nextNodeD->next->previous = targetNodeD;
        }

        targetNodeD->next = nextNodeD->next;
        nextNodeD->next = targetNodeD;
        nextNodeD->previous = targetNodeD->previous;
        targetNodeD->previous = nextNodeD;


        if(targetNodeD == start){
          start = nextNodeD;
        }
        if(nextNodeD == end){
          end = targetNodeD;
        }
      }
      else{
        targetNodeD = nextNodeD;
      }
    }
  }
}

    //Remove an information in any position of list.
    public: bool remove(T removed){
        if(start == nullptr) return false;

        NodeD<T>* currentNode = start->next;
        NodeD<T>* previousNode = start;

        //If the information is the first of list.
        if (previousNode->info == removed) {
                if (previousNode == start && previousNode == end) {
                    delete previousNode;
                    start = nullptr;
                    end = nullptr;
                    length--;
                    return true;
                }
                start = currentNode;
                start->previous = nullptr;
                delete previousNode;
                length--;
                return true;
            }

            bool isFound = false;

            while (currentNode != nullptr && !isFound) {
                if (currentNode->info == removed) {
                    isFound = true;
                }
                else {
                    previousNode = currentNode;
                    currentNode = currentNode->next;
                }
            }

            if (!isFound) return false;

            //If the information is the last of list.
            if (currentNode == end) {
                end = previousNode;
                end->next = nullptr;
                delete currentNode;
                length--;
                return true;
            }

            //If the information is in the midle of list.
            previousNode->next = currentNode->next;
            currentNode->next->previous = previousNode;
            delete currentNode;
            length--;
            return true;
    }
    public: int getLength(){
        return length;
    }
    public: void show(){
        NodeD<T>* currentNode = start;
        while(currentNode != nullptr){
            if(currentNode == start) cout << "[";
            cout << currentNode->info.character << ":" << currentNode->info.freq;
            cout << (currentNode == end ? "]" : ", ");
            currentNode = currentNode->next;
        }
    }
    bool selfDelete() {
        if (this->start == nullptr) return false;
        NodeD<T>* auxNode;
        auxNode = new NodeD<T>;
        NodeD<T>* currentNode = start;
        while (currentNode != nullptr) {
            auxNode = currentNode->next;
            delete currentNode;
            currentNode = auxNode;
        }
        start = nullptr;
        end = nullptr;
        return true;
    }
};
#endif
