








#include "Array.hpp"

template <typename T>
Array<T>::Array() : _size(0), _array(NULL)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n), _array(new T[n])
{
}

template <typename T>
Array<T>::Array(Array<T> const &copy) : _size(copy._size), _array(new T[copy._size])
{
    for(unsigned int i = 0; i < _size; i++)
    {
        _array[i] = copy._array[i];
    }
}

template <typename T>
Array<T> &Array<T>::operator=(Array<T> const &copy)
{
    if(this == &copy)
        return (*this);
    if(_size)
        delete []_array;
    _size = copy._size;
    _array = new T[_size];
    for(unsigned int i = 0; i < _size; i++)
    {
        _array[i] = copy._array[i];
    }
    return (*this);
}

template <typename T>
T &Array<T>::operator[](const unsigned int index) const
{
    if(index >= _size)
        throw std::exception();
    return(_array[index]);
}

template <typename T>
unsigned int Array<T>::size() const
{
    return (_size);
}

template <typename T>
Array<T>::~Array()
{
    delete []_array;
}