// Parham Khodadi
// CS 52
// Professor Bishop
// 6/4/2022

#include <iostream>

namespace CS52 {

  class Container {

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
        Container(int size, int initial_value ) {
            // dynamic array with enough allocated memory to fit the size needed
            _data = new int[size];
            for (int i = 0; i < size; i++) {
                _data[i] = initial_value;
            };
            _size = size;
            _capacity = size;
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

        // Overloaded stream insertion operator
        friend std::ostream& operator << (std::ostream& out, Container& c) {
            for (int i = 0; i < c.size(); i++) {
                out << c.at(i) << " ";
            }
            return out;
        };

    };//Container
}//namespace

void info(CS52::Container& c){
            std::cout << "Size is: " << c.size() << "\n";
            std::cout << "Capacity is: " << c.capacity() << "\n";
            std::cout << "Contents : ";
            for (int i = 0; i < c.size (); i++) {
                std::cout << c[i] << " ";
            }
            std::cout << "\n";
}

int main()
{
    // default constructor , push_back , at methods
    std::cout << "// default constructor , push_back , at \nCS52::Container a;\n";
    CS52::Container a;
    std::cout << "\na.push_back(10); a.push_back(88)\n";
    a.push_back(10); a.push_back(88);
    std::cout << "a.at(0) = 99;\n";
    a.at(0) = 99;
    info(a);

    //b
    std::cout << "\n//overloaded constructor, [] op, at, find, empty, clear, \
    exception handling: front, at \nCS52::Container b(2,5);\n";

    CS52::Container b(2,5);
    std::cout << "b is " << b << "\n";

    std::cout << "\n//Add more elements to b\n";
    std::cout << "b.push_back(10); b.push_back(2);\n";
    std::cout << "b.push_back(99); b.push_back(-5);\n";
    b.push_back(10); b.push_back(2);
    b.push_back(99); b.push_back(-5);

    std::cout << "\n//array index [] and at()\n";
    std::cout << "b[0] = 25; b[1] = 1;\n";
    b[0] = 25; b[1] = 1;
    std::cout << "b.at(0) ; b.at(1) ;\n";
    std::cout << b.at(0) << " " << b.at(1) << "\n";

    std::cout << "\n//find method\nint i = b.find(25); ";
    std::cout << "i = " << b.find(25);
    std::cout << "\nint i = b.find(999); ";
    std::cout << "i = " << b.find(999);

    std::cout << "\n\n//empty method, size, and capacity\n";
    std::cout << "b.empty() " << (b.empty() ? "True" : "False") << "\n";
    std::cout << "b.clear()\n";
    b.clear();
    info(b);
    std::cout << "b.empty() " << (b.empty() ? "True" : "False") << "\n";

    std::cout << "\n\n//Exception handling:";
    try {
        std::cout << "\nb.front() = "; std::cout << b.front();
    }
    catch (std::out_of_range e) { std::cerr << e.what(); }
    try {
        std::cout << "\nb.at(9) = "; std::cout << b.at(9);
    }
    catch (std::string msg) { std::cerr << "\n" << msg << std::endl; }

    //c
    std::cout << "\n//copy constructor, copy assignment, pop_back, reserve,\
    \n//resize, capacity, size\nCS52::Container c(b);\n";

    std::cout << "\n//Add more elements to b\n";
    std::cout << "b.push_back(11); b.push_back(7);\n";
    std::cout << "b.push_back(3); b.push_back(23);\n";
    b.push_back(11); b.push_back(7);
    b.push_back(3); b.push_back(23);
    CS52::Container c(b);
    info (c);

    //d
    std::cout << "\n//copy assignment\n";
    CS52::Container d;
    d = c;
    std::cout << "CS52::Container d = c; " << "\n";
    std::cout << "d is " << d << "\n";

    std::cout << "\n//size vs capacity()\n";
    std::cout << "d.size() is " << d.size() << "\n";
    std::cout << "d.capacity() is " << d.capacity() << "\n";

    std::cout << "\n//pop_back()\n";
    std::cout << "d.pop_back(); d.pop_back();\n";
    d.pop_back(); d.pop_back();

    std::cout << "\n//size vs capacity\n";
    std::cout << "d.size() is " << d.size() << "\n";
    std::cout << "d.capacity() is " << d.capacity() << "\n";

    std::string stop;
    std::cin >> stop;

    return EXIT_SUCCESS;
}// main