//
//  core.hpp
//  core
//
//  Created by Andrew Kuhl on 4/19/22.
//

#ifndef core_hpp
#define core_hpp

#include "tape.hpp"
#include "symbol.hpp"
#include "transition.hpp"

#include <iostream>
#include <string>

template <class T>
class Core {
    
private:
    T *Q; //pointer to states
    T *E; //pointer to input characters
    T *G; //pointer to tape symbols
    Transition<T> *d; //pointer to transitions
    int q0; //start state
    int qaccept; //accepting state
    int qreject; //rejecting state
    
    int currentstate;
    
public:
    Core() //Core Constructor
    {
        Q = nullptr;
        E = nullptr;
        G = nullptr;
        d = nullptr;
        currentstate = 0;
    }
    ~Core()
    {
        if(Q)
            delete Q;
        if(E)
            delete E;
        if(G)
            delete G;
        if(d)
            delete d;
    }
    void setStates(int n)
    {
        Q = new int[n];
        for(int i = 0; i < n; i++)
            Q[i]=i;
    }
    void setInput(T arr[])
    {
        int len = sizeof(arr)/sizeof(arr[0]);
        *E = new T[len];
        *E = arr;
    }
    void setTransitions(Transition<T> arr[])
    {
        int len = sizeof(arr)/sizeof(arr[0]);
        *d = new Transition<T>[len];
        *d = arr;
    }
    void setStart(T state)
    {
        q0 = state;
    }
    void setAccept(T state)
    {
        qaccept = state;
    }
    void setReject(T state)
    {
        qreject = state;
    }
    Transition<T> * getTransition(int state, Symbol<T> symbol)
    {
        int len = sizeof(*d)/sizeof(*d[0]);
        for(int i = 0; i < len; i++)
        {
            if(d[i]->getQs() == state && d[i]->getread() == symbol)
                return d[i];
        }
        return nullptr;
    }
    void read(Tape<T>* _tape)
    {
        Transition<T>* _t = getTransition(currentstate, _tape->read());
        if(_t)
        {
            execute(_t);
        }
        else
        {
            exit(1);
        }
    }
    void execute(Tape<T>* _tape, Transition<T>* _transition)
    {
        _tape->write(_transition->getwrite());
        _tape->move(_transition->getdirection());
        currentstate = _transition->getQf();
    }
};

#endif /* core_hpp */
