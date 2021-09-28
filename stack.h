/***********************************************************************
 * Module:
 *    Stack
 * Summary:
 *    Our custom implementation of std::stack
 *
 *      __       ____       ____         __
 *     /  |    .'    '.   .'    '.   _  / /
 *     `| |   |  .--.  | |  .--.  | (_)/ /
 *      | |   | |    | | | |    | |   / / _
 *     _| |_  |  `--'  | |  `--'  |  / / (_)
 *    |_____|  '.____.'   '.____.'  /_/
 *
 *
 *    This will contain the class definition of:
 *       stack             : similar to std::stack
 * Author
 *    Alexander Dohms, Steve Costigan, Jonathan Colwell, Corbin Layton 
 ************************************************************************/

#pragma once

#include <cassert>  // because I am paranoid
//#include "vector.h"
#include <vector>

namespace custom
{

/**************************************************
 * STACK
 * First-in-Last-out data structure
 *************************************************/
template<class T>
class stack
{
public:
  
   //
   // Construct
   //

   stack()                            { container.resize(7); }
   stack(const stack <T> &  rhs)      { container.resize(7); }
   stack(      stack <T> && rhs)      { container.resize(7); }
   stack(const std::vector<T> &  rhs) { container.resize(7); }
   stack(      std::vector<T> && rhs) { container.resize(7); }
   ~stack()                           {                      }

   //
   // Assign  -- Corbin
   //

   stack <T> & operator = (const stack <T> & rhs)
   {
       // COPY ASSIGNMENT - PDF PG 334
       /*FOR i < 0 … rhs.numElements
           array[i] <- rhs.array[i]
           numElements <- rhs.numElements*/
      return *this;
   }
   stack <T>& operator = (stack <T> && rhs)
   {
       // MOVE ASSIGNMENT - PDF PG 334
       /* container <- move(rhs.container)*/

      return *this;
   }
   void swap(stack <T>& rhs) // -- Steve
   {
       // MOVE ASSIGNMENT - PDF PG 334
        /*FOR i < 0 … N
           swap(array[i], rhs.array[i])
           swap(numElements, rhs.numElements) */
   }

   //
   // Access -- Jon
   //

         T& top() {
             // PDF PG 335
             /*ASSERT not empty()
                 RETURN array[size() – 1]*/
             return *(new T);
         }
   const T& top() const { return *(new T); }

   //
   // Insert -- Jon
   //

   void push(const T&  t) {
        // PDF PG 335
       /*IF numElements < N
           array[numElements++] <- t*/
   }
   void push(      T&& t) {  }

   //
   // Remove -- Jon
   //

   void pop()
   {
      // PDF PG 336
       /*stack.pop()
           IF not empty()
           --numElements*/
   }

   //
   // Status -- Steve
   //
   size_t  size () const {
       // PDF PG 336
       return container.size();
   }
   bool empty   () const {
       // PDF PG 336
       /*RETURN size() = 0 ? TRUE else FALSE*/
       return size() > 0 ? false : true;
   }
   
#ifdef DEBUG // make this visible to the unit tests
public:
#else
private:
#endif
   
  std::vector<T> container;  // underlying container
};



} // custom namespace


