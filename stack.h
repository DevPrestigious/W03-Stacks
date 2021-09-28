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

   stack()                            { container.resize(7); } // -- Corbin PDF PG 333 {  numElements <- 0 }                 DEFAULT CONSTRUCTOR
   stack(const stack <T> &  rhs)      { container.resize(7); } // -- Corbin PDF PG 333 {  *this <- rhs }                     COPY CONSTRUCTOR
   stack(      stack <T> && rhs)      { container.resize(7); } // -- Jon    PDF PG 333 {  *this <- move(rhs) }               MOVE CONSTRUCTOR
   stack(const std::vector<T> &  rhs) { container.resize(7); } // -- Jon    PDF PG 333 {  container <- rhs.container }       COPY INITIALIZE CONSTRUCTOR
   stack(      std::vector<T> && rhs) { container.resize(7); } // -- Alex   PDF PG 333 {  container <- move(rhs.container) } MOVE INITIALIZE CONSTRUCTOR
   ~stack()                           {                      } // -- Steve  Don't know                                       DECONSTRUCTOR

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
       /*for (int i = 0; i < size(); i++) {
           swap();
       }*/
   }

   //
   // Access -- Jon
   //

         T& top() {
             // PDF PG 335
             /*ASSERT not empty()
                 RETURN array[size() – 1]*/
             assert(!empty());
                 return container[size() - 1];
             
         }
   const T& top() const { return *(new T); }

   //
   // Insert -- Jon
   //

   void push(const T&  t) {
        // PDF PG 335
       
       container.push_back(t);
           

   }
   void push(      T&& t) {
       container.push_back(t);
   }

   //
   // Remove -- Jon
   //

   void pop()
   {
      // PDF PG 336
       /*stack.pop()
           IF not empty()
           --numElements*/
       if (!empty())
           container[size() - 1] = NULL;
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


