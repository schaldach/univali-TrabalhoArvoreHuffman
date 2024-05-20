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

    //Inserts an information in the start of list.
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

    bool insertInOrder(T *v){
        NodeD<T>* newNode = new NodeD<T>;
        if (newNode == nullptr) return false;
        newNode->info = *v;

        if(start == nullptr){
          start = newNode;
          end = newNode;
          length++;
          return true;
        }
        if(v->freq < start->info.freq){
          start->previous = newNode;
          newNode->next = start;
          start = newNode;
          length++;
          return true;
        }
        if(v->freq > end->info.freq){
          end->next = newNode;
          newNode->previous = end;
          end = newNode;
          length++;
          return true;
        }

        NodeD<T>* targetNodeD = start;
        while(targetNodeD != nullptr){
          if(targetNodeD->info.freq > v->freq){
            newNode->next = targetNodeD;
            newNode->previous = targetNodeD->previous;
            targetNodeD->previous = newNode;
            newNode->previous->next = newNode;
            length++;
            return true;
          }
          targetNodeD = targetNodeD->next;
        }
        return false;
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

    void retirar(T &v){
        if(start == nullptr){
          return;
        }

        NodeD<T>* startNode = start;
        start = startNode->next;
        if(start != nullptr){
            start->previous = nullptr;
        }
        if(startNode == end){
          end = nullptr;
        }

        v = startNode->info;
        delete startNode;
        length--;
      }

    public: int getLength(){
        return length;
    }
    public: void show(){
        NodeD<T>* currentNode = start;
        while(currentNode != nullptr){
            if(currentNode == start) cout << "[";
            (currentNode->info.character != '\0') ? cout << currentNode->info.character : cout << "merged";
            cout << ":" << currentNode->info.freq;
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
