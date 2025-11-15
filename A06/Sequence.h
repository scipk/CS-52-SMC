#include <iostream>

namespace CS52 {
    /* Sequence class Declaration */
    class Sequence
    {
        public:
            virtual int size() const = 0;
            virtual int capacity() const = 0;
            virtual std::string type() const = 0;
            virtual ~Sequence() {};
    };
}