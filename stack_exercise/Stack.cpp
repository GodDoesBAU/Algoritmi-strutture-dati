#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;
class Stack {
    private:
        class Node{
            private:
                Node* previusPointer;

            public:
                int value;

                Node(int valueToAdd = NULL){
                    this->value = valueToAdd;
                    this->previusPointer = nullptr;
                }

                Node* GetIstance(){
                    return this;
                };

                Node* getPreviusPointer(){
                    return this->previusPointer;
                };

                void setPreviusPointer(Node* ptr){
                    this->previusPointer = ptr->GetIstance();
                };
        };


    public:
        int length;
    private:
        Node* TopNode;

    public:
        // Costruttore

        Stack(int startingValue = NULL){
            this->length = 1; 
            Node* initial = new Node(startingValue);
            this->push(initial);
        };

        // Distruttore
        ~Stack();

        void push(Node* toAdd){
            this->length++;
            toAdd->setPreviusPointer(this->TopNode);
            this->TopNode = toAdd;
        }; // Inserisce un elemento in cima allo stack

        int pop(){
            if(this->length > 0){
                int poppedValue = this->TopNode->value;
                this->TopNode = this->TopNode->getPreviusPointer();
                this->length--;
                return poppedValue;
            }else
                return NULL;
        };               // Rimuove l'elemento in cima allo stack
        Node* top(){
            return this->TopNode;
        } ;            // Restituisce l'elemento in cima allo stack
        bool isEmpty() ;     // Verifica se lo stack è vuoto
        int size() ;         // Restituisce la dimensione dello stack
};

#endif // STACK_H