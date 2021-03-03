#ifndef SORTBTREE_HPP
#define SORTBTREE_HPP
#include <iostream>

using namespace std;

template <class TheClass>
class Node{
    private:
        Node * Sub;
        Node * Sup;
        TheClass   n_key;
        unsigned int n=1;

        void pushL ( const TheClass& );
        void pushR ( const TheClass& );
        void destroy ( void );
    public:
        bool bool_l = true, bool_r = true;

        Node ( TheClass key ){
            this->n_key = key;
            Sub = NULL;
            Sup = NULL;
        }

        ~Node ( void )
        { this->destroy(); }

        TheClass * getSub ( void );
        TheClass * getSup ( void );

        void push ( const TheClass& newKey );
        void printOrdered ( void );
        void getNext      ( TheClass * );

        unsigned int getN ( void ) const; 

        TheClass * getList( void );
};

template <typename TheClass>
void Node<TheClass>::destroy ( void ){
    if( this->bool_l ){
        this->Sub = NULL;
        delete this->Sub;
    }else{ (this->Sub)->destroy(); }
    if( this->bool_r ){
        this->Sup = NULL;
        delete this->Sup;
    }else{ (this->Sup)->destroy(); }
}

template <typename TheClass>
void Node<TheClass>::pushL ( const TheClass& newKey ){
    if( this->bool_l ){
        this->Sub = new Node ( newKey );
        this->bool_l = false;
    }
    else
        (this->Sub)->pushL ( newKey );
}

template <typename TheClass>
void Node<TheClass>::pushR ( const TheClass& newKey ){
    if( this->bool_r ){
        this->Sup = new Node ( newKey );
        this->bool_r = false;
    }
    else
        (this->Sup)->pushR ( newKey );
}

template <typename TheClass>
void Node<TheClass>::push ( const TheClass& newKey ){
    if( this->n_key>newKey ){
        if( this->bool_l )
            this->pushL ( newKey );
        else
            (this->Sub)->push ( newKey );
    }else{
        if( this->bool_r )
            this->pushR ( newKey );
        else
            (this->Sup)->push ( newKey );
    }
    ++n;
}

template<typename TheClass>
TheClass * Node<TheClass>::getSub (void)
{ return this->Sub; }

template<typename TheClass>
TheClass * Node<TheClass>::getSup (void)
{ return this->Sup; }

template<typename TheClass>
void Node<TheClass>::printOrdered (void){
    if( this->Sub!=NULL ){ (this->Sub)->printOrdered(); }
    cout << this->n_key << ' ';
    if( this->Sup!=NULL ){ (this->Sup)->printOrdered(); }
}

unsigned int MyIndex = 0;

template<typename TheClass>
void Node<TheClass>::getNext ( TheClass * _list ){
    if( this->Sub!=NULL ){ (this->Sub)->getNext(_list); }
    _list[MyIndex] = this->n_key;
    ++MyIndex;
    if( this->Sup!=NULL ){ (this->Sup)->getNext(_list); }
}

template<typename TheClass>
TheClass * Node<TheClass>::getList ( void ){ 
    TheClass * _list = (TheClass*) malloc (this->n*sizeof(TheClass)); 
    this->getNext( _list );    
    MyIndex = 0;
    return _list;
}

template<typename TheClass>
unsigned int Node<TheClass>::getN ( void ) const
{ return n; }

#endif
