//
//  machine.hpp
//  core
//
//  Created by Andrew Kuhl on 4/19/22.
//

#ifndef machine_hpp
#define machine_hpp

#include "tape.hpp"
#include <iostream>
#include <string>

template <class T>
class Machine {
    
private:
    Tape<T>* tape; //Tape object pointer
    
    struct Transition{ //transition obj
        int Qs, Qf;
        T read, write;
        d direction;
    };
    
    T *Q; //pointer to states
    T *E; //pointer to input characters
    T *G; //pointer to tape symbols
    Transition *d; //pointer to transitions
    int q0; //start state
    int qaccept; //accepting state
    int qreject; //rejecting state
    
public:
    Machine() //Machine Constructor
    {
        tape = new Tape<T>; //Tape Init
        Q = nullptr;
        E = nullptr;
        G = nullptr;
        d = nullptr;
    }
    ~Machine()
    {
        if(tape)
            delete tape;
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
    void setTape(T arr[])
    {
        int len = sizeof(arr)/sizeof(arr[0]);
        *G = new T[len];
        *G = arr;
    }
    void setTransitions(Transition arr[])
    {
        int len = sizeof(arr)/sizeof(arr[0]);
        *d = new Transition[len];
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
    T read()
    {
        return tape->read();
    }
    void write(T input)
    {
        tape->write(input);
    }
    void move(::d direction)
    {
        if(direction == d::R)
        {
            tape->move(R);
        }
        else if(direction == d::L)
        {
            tape->move(L);
        }
        else exit(1);
    }
    
    
    void setInput(){}
};

#endif /* machine_hpp */
