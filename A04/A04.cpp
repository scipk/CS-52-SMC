#include <iostream>

//
// Container prototypes go here
//
struct Container{
    // Construct a Container c with a size s and initial value val .
    // Defaults are zero .
    void construct_container ( Container& c, int s = 0, int val = 0 );

    // Destroy Container c and return memory to the freestore ( heap ).
    void destroy_container ( Container& c );

    // Returns pointer to the first element in Container c.
    int * data ( const Container& c );

    // Returns the number of elements in Container c.
    int size ( const Container& c );

    // Returns a reference to the element at location i in Container v.
    // ( optional ) Throws std :: string exception if out of bounds
    int & at ( Container& c , int i );

    // Returns a reference to the last element in Container c.
    // ( optional ) Throws std :: out_of_range exception if Container is empty
    int & back ( const Container& c );

    // Returns the allocated storage for Container c.
    int capacity ( const Container& c );

    // Erases the elements of Container c but does not change capacity .
    void clear ( Container& c );

    // If Container c is empty return true , else false .
    bool empty ( const Container& c );

    // Returns a reference to the first element in the Container .
    // ( optional ) Throws exception if Container is empty .
    int & front ( const Container& c );

    // Deletes the last element of Container c.
    void pop_back ( Container& c );

    // Add element to the end of the Container c.
    void push_back ( Container& c, int element );

    // Search for a key in Container c,
    // return index of key or -1 if not found
    int find_key ( Container &c, int key );

    int size        = 0;
    int capacity    = 0;
    int *data       = nullptr;
}

int main()
{
    Container box, bin; // create two Containers

    // Test all functions for correctness .
    // Examples output shown on page 4 & 5
    // Tests do not need to be exactly as shown ,
    // example driver on page 3

    return 0

}

// Container function definitions go here
