//
//  tape.hpp
//  Lib
//
//  Created by Andrew Kuhl on 4/19/22.
//

#ifndef tape_h
#define tape_h


enum d { L, R };

template <class T>
class Tape {
private:
    
    struct TapeNode{ // TAPE SYMBOL , LEFT POINTER, RIGHT POINTER
            T e;
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
        
        if(node->e)
        {
            std::cout << node->e << " ";
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
    void newSymbol(T e_){
        if(last!=nullptr){
            TapeNode* newsym = new TapeNode();
            newsym->e = e_;
            newsym->left = last;
            last->right = newsym;
            last = last->right;
        }
        else
        {
            TapeNode* newsym = new TapeNode();
            newsym->e = e_;
            last = newsym;
            curr = newsym;
            head = newsym;
        }
    }
    void newSymbol(){
        if(last!=nullptr){
            TapeNode* newsym = new TapeNode();
            newsym->left = last;
            last->right = newsym;
            last = last->right;
        }
        else
        {
            TapeNode* newsym = new TapeNode();
            last = newsym;
            curr = newsym;
            head = newsym;
        }
    }

    T read(){return curr->e;}

    void write(T e_){curr->e = e_;}

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
