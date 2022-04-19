//
//  turingmachine.hpp
//  core
//
//  Created by Andrew Kuhl on 4/19/22.
//

#ifndef turingmachine_hpp
#define turingmachine_hpp

#include "core.hpp"

template <class T>
class TuringMachine {
   
private:
    Machine<T> *machine;
    
public:
    TuringMachine(int states, T ialph[], T talph[], Transition trans[], T start, T accept, T reject)
    {
        machine = new Machine<T>;
        
        machine->setStates(states);
        machine->setInput(ialph);
        machine->setTape(talph);
        machine->setTransitions(trans);
        machine->setStart(start);
        machine->setAccept(accept);
        machine->setReject(reject);
    }
    ~TuringMachine()
    {
        delete machine;
    }
};

#endif /* turingmachine_hpp */
