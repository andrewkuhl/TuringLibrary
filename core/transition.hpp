//
//  transition.hpp
//  core
//
//  Created by Andrew Kuhl on 4/19/22.
//

#ifndef transition_hpp
#define transition_hpp

#include <stdio.h>
#include "symbol.hpp"
#include "tape.hpp"

template <class T>
class Transition{ //transition obj
        
private:
    int Qs;
    int Qf;
    Symbol<T> read;
    Symbol<T> write;
    ::d direction;
    
public:
    Transition(int _Qs, int _Qf, Symbol<T> _read, Symbol<T> _write, ::d _direction)
    {
        setQs(_Qs);
        setQf(_Qf);
        setread(_read);
        setwrite(_write);
        setdirection(_direction);
    }
    void setQs(int _Qs)
    {
        Qs = _Qs;
    }
    void setQf(int _Qf)
    {
        Qf = _Qf;
    }
    void setread(Symbol<T> _read)
    {
        read = _read;
    }
    void setwrite(Symbol<T> _write)
    {
        write = _write;
    }
    void setdirection(::d _direction)
    {
        direction = _direction;
    }
    int getQs()
    {
        return Qs;
    }
    int getQf()
    {
        return Qf;
    }
    Symbol<T> getread()
    {
        return read;
    }
    Symbol<T> getwrite()
    {
        return write;
    }
    ::d getdirection()
    {
        return direction;
    }
};

#endif /* transition_hpp */

