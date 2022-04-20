//
//  tape.hpp
//  Lib
//
//  Created by Andrew Kuhl on 4/19/22.
//

#ifndef tape_h
#define tape_h


#include <iostream>
#include "symbol.hpp"
#include <string>

enum d { L, R };

template <class T>
class Tape {
private:
    
    struct TapeNode{ // TAPE SYMBOL , LEFT POINTER, RIGHT POINTER
            Symbol<T> symbol;
            TapeNode* left;
            TapeNode* right;
        
            TapeNode(){left = nullptr; right = nullptr;}
        };
            
            TapeNode* head; // POINTER TO HEAD NODE
            TapeNode* last; // POINTER TO LAST NODE
            TapeNode* curr; // POINTER TO CURRENT NODE
    
    void printing(TapeNode* node)
    {
        if (node==nullptr)
        {
            std::cout << "\n";
            return;
        }
        
        if(node->symbol.get())
        {
            std::cout << node->symbol.get() << " ";
        }
        else
        {
            std::cout << "_" << " ";
        }
        
        printing(node->right);
    }
public:
            Tape(){head = nullptr; last = nullptr; curr = nullptr;}
            ~Tape(){deleteTape(head);}
            void deleteTape(TapeNode* headptr){
                if(headptr == nullptr)
                    return;
                deleteTape(headptr->right);
                delete headptr;
            }
    void newSymbol(Symbol<T> _symbol){
        if(last!=nullptr){
            TapeNode* newsym = new TapeNode();
            newsym->e = _symbol;
            newsym->left = last;
            last->right = newsym;
            last = last->right;
        }
        else
        {
            TapeNode* newsym = new TapeNode();
            newsym->e = _symbol;
            last = newsym;
            curr = newsym;
            head = newsym;
        }
    }

    T read(){return curr->symbol.get();}

    void write(T _symbol){curr->symbol.set(_symbol);}

    void move(d direction){
        if(direction == d::L){
            if(curr->left != nullptr)
                curr = curr->left;
        }
        if(direction == d::R){
            if(curr->right == nullptr)
            {
                newSymbol();
            }
            curr = curr->right;
        }
    }
    void print()
    {
        printing(head);
    }
};

#endif /* tape_h */
