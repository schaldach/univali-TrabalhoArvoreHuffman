#include "../commons.cpp"

template <typename dLinkedListType>
struct DLinkedListNode{
    dLinkedListType info;

    DLinkedListNode* previous = nullptr;
    DLinkedListNode* next = nullptr;
};

template <typename dLinkedListType>
struct DLinkedList{
    private: DLinkedListNode<dLinkedListType>* start = nullptr;
    private: DLinkedListNode<dLinkedListType>* end = nullptr;
    private: int length = 0;

    //Inserts an information in the end of list.
    public: bool insert(dLinkedListType inserted){
        DLinkedListNode<dLinkedListType>* newNode = new DLinkedListNode<dLinkedListType>;
        if (newNode == nullptr) return false;

        newNode->info = inserted;

        if (end == nullptr) {
            start = newNode;
            end = newNode;
            length++;
            return true;    
        }else {
            newNode->previous = end;
            end->next = newNode;
            end = newNode;
            length++;
            return true;
        }
    }

    //Remove an information in any position of list.
    public: bool remove(dLinkedListType removed){
        if(start == nullptr) return false;

        DLinkedListNode<dLinkedListType>* currentNode = start->next;
        DLinkedListNode<dLinkedListType>* previousNode = start;

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
        DLinkedListNode<dLinkedListType>* currentNode = start;
        while(currentNode != nullptr){
            if(currentNode == start) cout << "[";
            cout << currentNode->info;
            cout << (currentNode == end ? "]" : ", ");
            currentNode = currentNode->next;
        }
    }
    bool selfDelete() {
        if (this->start == nullptr) return false;
        DLinkedListNode<dLinkedListType>* auxNode;
        auxNode = new DLinkedListNode<dLinkedListType>;
        DLinkedListNode<dLinkedListType>* currentNode = start;
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