#ifndef COMPARABLE
#define COMPARABLE

template<typename T> class Comparable
{
    public:
        virtual int compares_to(const T& t) const = 0;
};

#endif