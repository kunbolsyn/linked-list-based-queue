#include "queue.h"

queue::queue( ):
    queue_size(0),
    front(nullptr),
    back(nullptr)
{
    
}

queue::queue( const queue& q ):
    queue_size(0),
    front(nullptr),
    back(nullptr)
{
    node* cur = q.front;
    while(cur){
        node* next = cur->next;
        push(cur->value);
        cur = next;
    }
}

const queue& queue::operator = ( const queue& q ){
    if(front != q.front){
        clear();
        node* cur = q.front;
        while(cur){
            node* next = cur->next;
            push(cur->value);
            cur = next;
        }
    }
    return *this;
}

queue::~queue( ){
    clear();
}

queue::queue( std::initializer_list< std::string > init ):
    queue_size(0),
    front(nullptr),
    back(nullptr)
{
    for(std::string s : init){
        push(s);
    }
}

void queue::push( const std::string& s ){
    node* new_back = new node(s);
    new_back->next = nullptr;
    
    if(queue_size == 0){
        front = new_back;
        back = new_back;
    } else {
        back->next = new_back;
        back = new_back;
    }
    queue_size++;
}

void queue::pop( ){
    if(queue_size == 0){
        throw std::runtime_error("pop: queue is empty");
    } else if(queue_size == 1){
        delete front;
        front = nullptr;
        back = nullptr;
    } else {
        node* old_front = front;
        front = front->next;
        delete old_front;
    }
    queue_size--;
}

void queue::clear( ){
    while(queue_size != 0){
        pop();
    }
}

void queue::reset( size_t s ){
    if(s > queue_size){
        throw std::runtime_error("reset: the number is larger than the size");
    } else {
        while(queue_size != s){
            pop();
        }
    }
}

const std::string& queue::peek( ) const{
    if(queue_size == 0){
        throw std::runtime_error("peek: queue is empty");
    } else {
        return front->value;
    }
}

size_t queue::size( ) const{
    return queue_size;
}

bool queue::empty( ) const{
    if (queue_size == 0){
        return true;
    } else {
        return false;
    }
}

void queue::print( std::ostream& out ) const{
    node* cur = front;
    size_t i = 1;
    
    while(cur){
        node* next = cur->next;
        if(i != queue_size){
            out << cur->value << ", ";
        } else {
            out << cur->value;
        }
        cur = next;
        i++;
    }
}