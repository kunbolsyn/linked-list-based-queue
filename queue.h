#ifndef QUEUE_
#define QUEUE_ 1

#include <iostream>
#include <initializer_list>
#include <string>

class queue
{

   struct node
   {
      std::string value;
      node *next;

      node(const std::string &value, node *next = nullptr) : value(value),
                                                             next(next)
      {
      }
   };

   size_t queue_size;
   node *front;
   node *back;

public:
   queue();

   queue(const queue &q);

   const queue &operator=(const queue &q);

   ~queue();

   queue(std::initializer_list<std::string> init);

   void push(const std::string &s);

   void pop();

   void clear();

   void reset(size_t s);

   const std::string &peek() const;

   size_t size() const;

   bool empty() const;

   void print(std::ostream &out) const;

   friend int main(int argc, char *argv[]);
};

inline std::ostream &operator<<(std::ostream &out, const queue &q)
{
   q.print(out);
   return out;
}

#endif