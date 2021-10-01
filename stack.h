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
#include <iostream>
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

                                                                            //////////////////////////////////////////////////////////////////////////////////////////
        stack() { container.resize(0); }                                    // -- Alexander PDF PG 333  {  numElements <- 0 }                 DEFAULT CONSTRUCTOR
        stack(const stack <T>& rhs) { *this = rhs; }                // -- Corbin PDF PG 333     {  *this <- rhs }                     COPY CONSTRUCTOR
        stack(stack <T>&& rhs) { *this = std::move(rhs); }                     // -- Jon    PDF PG 333     {  *this <- move(rhs) }               MOVE CONSTRUCTOR
        stack(const std::vector<T>& rhs) { container = rhs.container; }           // -- Jon    PDF PG 333     {  container <- rhs.container }       COPY INITIALIZE CONSTRUCTOR
        stack(std::vector<T>&& rhs) { container = std::move(rhs.container); }    // -- Alex   PDF PG 333     {  container <- move(rhs.container) } MOVE INITIALIZE CONSTRUCTOR
        ~stack(){};                       // -- Steve  Don't know     // Alexander: "I don't think anything needs to go here.                  DECONSTRUCTOR
                                                                            //////////////////////////////////////////////////////////////////////////////////////////

        //
        // Assign  -- Corbin
        //

        stack <T>& operator = (const stack <T>& rhs) // Steve: trying to get it going for swap, but ran into issues.
        {
            
            for (int i = 0; i >= sizeof(rhs.container[size()]); i++) {
                container[i] = rhs.container[i];
                container[size()] = rhs.container[size()];
            }
            // COPY ASSIGNMENT - PDF PG 334
            /*FOR i < 0 … rhs.numElements
                array[i] <- rhs.array[i]
                numElements <- rhs.numElements*/

            /*for (int i = 0; i < size(); i++) {
                container.pop_back();
            }
            container = &rhs.container;*/
            //size_t max = (rhs.container.size() > container.size() ? rhs.container.size() : container.size());

            //for (int i = 0; i < rhs.container.size()-1; i++) {
            //    container.push_back(&rhs.container[size()-1]);
            //    rhs.container.pop_back();
            //    //push(rhs.container[i]);
            //    //container[i] = rhs.container[i];
            //}

            return *this;
        }
        stack <T>& operator = (stack <T>&& rhs)
        {
            // MOVE ASSIGNMENT - PDF PG 334
            /* container <- move(rhs.container)*/
            container = std::move(rhs.container);
            
            return *this;
        }
        void swap(stack <T>& rhs) // -- Steve
        {
            // MOVE ASSIGNMENT - PDF PG 334
             /*FOR i < 0 … N
                swap(array[i], rhs.array[i])
                swap(numElements, rhs.numElements) */

            /*T tempdata = container;
            rhs.container = this.container;
            this.container = tempdata;*/
            /*int i = 0;
            for (T item : rhs)
            {
                tempdata[i++] = item;
            }*/
            
            /* Alexander: "I tried my hand at using numElements instead."
            for (int i = 0; i <= numElements; i++)
            {
                swap(container[i],rhs.container[i]);
                swap(numElements, rhs.numElements);
            }
             */
        }

        //
        // Access -- Jon
        //

        T& top() {
            // PDF PG 335
            /*ASSERT not empty()
                RETURN array[size() – 1]*/
            //Let's make sure theres at least something in the array.
            assert(!empty());
            return container[size() - 1];
        }
        const T& top() const { return container[size() - 1]; }

        //
        // Insert -- Jon
        //

        void push(const T& t) {
            // PDF PG 335
            container.push_back(t);
        }
        void push(T&& t) { // THIS ONE LOOKS LIKE A MOVE PUSH!!!! Just now noticing....
            container.push_back(t);
        }

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
        size_t  size() const {
            // PDF PG 336
            return container.size();
        }
        bool empty() const {
            // PDF PG 336
            return size() > 0 ? false : true;
        }

#ifdef DEBUG // make this visible to the unit tests
    public:
#else
    private:
#endif

        
        std::vector<T> container;  // underlying container
        //int numElements = sizeof(container); // Can't use
    };



} // custom namespace


