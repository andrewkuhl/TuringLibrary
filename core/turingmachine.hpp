//
//  turingmachine.hpp
//  core
//
//  Created by Andrew Kuhl on 4/19/22.
//

#ifndef turingmachine_hpp
#define turingmachine_hpp

#include "tape.hpp"
#include "core.hpp"

template <class T>
class TuringMachine {
   
private:
    Tape<T> *tape;
    Core<T> *core;
    
public:
    TuringMachine()
    {
        tape = new Tape<T>;
        core = new Core<T>;
    }
    ~TuringMachine()
    {
        delete tape;
        delete core;
    }
};

#endif /* turingmachine_hpp */
