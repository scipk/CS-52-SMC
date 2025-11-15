#include "Sequence.h"

namespace CS52 {

  class Container : public Sequence {

      private:
        int  _size;
        int  _capacity;
        int* _data;

      public:
        Container() {
            // dynamic array of 0 allocated memory
            _data = new int[0];
            _capacity = 0;
            _size = 0;
        };                              //default constructor
        Container(int size, int initial_value) {
            // dynamic array with enough allocated memory to fit the size needed
            _size = size;
            _capacity = size;
            _data = new int[size];
            for (int i = 0; i < size; i++) {
                _data[i] = initial_value;
            };
        };                                        //overloaded constructor
        Container(const Container& og_container) {
            // dynamic array with the same allocated memory capacity as the copied container
            _size = og_container.size();
            _capacity = og_container.capacity();
            _data = new int[_capacity];
            for (int i = 0; i < _size; i++) {
                _data[i] = og_container.at(i);
            }
        };            //copy constructor
        ~Container() {
            _size = 0;
            _capacity = 0;
            delete[] _data;
        };                             //Destructor

        // Override Sequences’s type()
        std::string type() const {
            return "CS52::Container";
        };

        // Returns a reference to the element at location i in an Container.
        int& at(int i) const{
            if (_size <= i)
                throw std::string("Error: Index does not exist at this location!\n");
            return _data[i];
        }; // throws an std::string exception

        // Returns the allocated storage for an Container.
        int capacity() const {
            return _capacity;
        };

        // Erases the elements of an Container but does not change capacity.
        void clear() {
            _size = 0;
            delete[] _data;
        };

        // Returns pointer to the first element in an Container.
        int* data() const {
            return &_data[0];
        };

        // If Container is empty return true , else false.
        bool empty() const {
            if (_size == 0) {
                return true;
            } else {
                return false;
            }
        };

        // Deletes the element at the end of an Container.
        void pop_back() {
            _data[_size] = 0;
            _size--;
        };

        // Add an element to the end of the Container.
        void push_back(int element) {
            // Special case when container is completely empty
            if (_capacity == 0) {
                int* temp_data = new int[1];
                delete[] _data;
                _data = temp_data;
                _capacity = 1;
            };

            // When the container is at maximum capacity
            if (_size == _capacity) {
                int* temp_data = new int[_capacity * 2];
                
                for (int i = 0; i < _capacity; i++) {
                    temp_data[i] = _data[i];
                }

                delete[] _data;
                _data = temp_data;
                _capacity *= 2;
            };

            // Adding the element and increasing size
            _data[_size] = element;
            _size++;
        };

        // Returns a reference to the first element in an Container.
        int& front() const {
            if (_size == 0)
                throw std::out_of_range("Error: This container is empty!\n");

            return _data[0];
        }; // throws an std :: out_of_range exception

        // Returns a reference to the last element in an Container.
        int& back() const {
            if (_size == 0)
                throw std::out_of_range("Error: This container is empty!\n");

            return _data[_size];
        }; // throws an std :: out_of_range

        // Returns the number of elements in the Container.
        int size() const {
            return _size;
        };

        // Search for a key in Container
        // return index of key or -1 if not found
        int find (int key) {
            
            for (int i = 0; i < _size; i++) {
                if (_data[i] == key)
                    return i;
            };

            return -1;
        };

        // Overloaded operators
        int& operator[] (int i) {
            if (i > _size) {
                throw std::out_of_range("Error: Index out of range!\n");
                return _data[0];
            };

            return _data[i];
        }; // [] array syntax
        Container& operator=(const Container& og_container) {
            _size = og_container.size();
            _capacity = og_container.capacity();
            delete[] _data;
            _data = new int[_capacity];
            for (int i = 0; i < _size; i++) {
                _data[i] = og_container.at(i);
            };
            return *this;
        }; // copy assignment
        // Overloaded minus (-) operator that subtracts
        // CS52::Container types & returns a new CS52::Container
        // m = [3 ,2 ,1] , n= [1 ,2 ,3]; o = m - n = [2 ,0 , -2]
        //
        // if rhs.size() < this->size()
        // return Container of rhs.size() ,
        // otherwise return Container this->size();
        //
        Container operator-(const Container& rhs) {
            if (rhs.size() < this->size()) {
                for (int i = 0; i < rhs.size(); i++) {
                    this->at(i) -= rhs.at(i);
                }
            } else {
                for (int i = 0; i < this->size(); i++) {
                    this->at(i) -= rhs.at(i);
                }
            }
            return *this;
        };

        // Overloaded stream insertion operator
        friend std::ostream& operator << (std::ostream& out, Container& c) {
            for (int i = 0; i < c.size(); i++) {
                out << c.at(i) << " ";
            }
            return out;
        };

    };//Container
}//namespace
