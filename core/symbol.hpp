//
//  symbol.hpp
//  core
//
//  Created by Andrew Kuhl on 4/19/22.
//

#ifndef symbol_hpp
#define symbol_hpp

template <class T>
class Symbol {
    
private:
    T value;
    
public:
    Symbol(T _value){set(_value);}
    void set(T _value){value = _value;}
    T get(){return value;}
    
};

#endif /* symbol_hpp */
