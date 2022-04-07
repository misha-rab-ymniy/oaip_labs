#ifndef POINTERS_H
#define POINTERS_H
#include <QDebug>

template<class T>
class unique_ptr;

template<class T>
class shared_ptr;

template <class T>
class weak_ptr;

template<class T>
class unique_ptr
{
private:
    T* ptr;
public:
    unique_ptr()
        : ptr(nullptr) {}

    unique_ptr(const unique_ptr& other) {
        reset(other.release());
    }

    unique_ptr(T* unObj)
        : ptr(unObj) {}


    unique_ptr(unique_ptr&& other) noexcept
        : ptr(other.release()) {}

    void reset(T* ptr)
    {
        delete this->ptr;
        this->ptr = ptr;
    }

    T* release()
    {
        T* tmp = ptr;
        ptr = nullptr;
        return tmp;
    }

    T* get() const
    {
        return ptr;
    }

    ~unique_ptr()
    {
        delete ptr;
    }

    T* operator->() const noexcept
    {
        return ptr;
    }

    T& operator*() const noexcept
    {
        return *ptr;
    }

    unique_ptr& operator=(unique_ptr&& other) noexcept
    {
        reset(other.release());
        return *this;
    }

    operator bool() const noexcept
    {
        return static_cast<bool>(ptr);
    }
};

template<class T>
class shared_ptr {
private:
    T* ptr;
    unsigned* str_counter;
    unsigned* weak_counter;
public:
    friend class weak_ptr<T>;
    shared_ptr() : ptr(nullptr), str_counter(nullptr), weak_counter(nullptr) {}

    shared_ptr(T* shObj) : ptr(shObj)
    {
        if (ptr == nullptr)
        {
            return;
        }
        str_counter = new unsigned(1);
        weak_counter = new unsigned(1);
    }

    shared_ptr(shared_ptr<T>& other) : ptr(other.ptr), str_counter(other.str_counter),
        weak_counter(other.weak_counter)
    {
        if (ptr == nullptr || !(*weak_counter))
        {
            return;
        }

        ++(*str_counter);
        ++(*weak_counter);
    }

    shared_ptr(shared_ptr<T>&& other) : ptr(other.ptr)
    {
        if (ptr == nullptr)
        {
            return;
        }
        str_counter = other.str_counter;
        ++(*str_counter);
    }

    shared_ptr(weak_ptr<T>& other)
        : str_counter(other.str_counter),
        weak_counter(other.weak_counter),
        ptr(other.ptr)
    {
        if (ptr == nullptr)
        {
            return;
        }
        ++(*str_counter);
        ++(*weak_counter);
    }

    ~shared_ptr()
    {
        qDebug() << "SHARED";
        if (ptr == nullptr || weak_counter == nullptr)
        {
            return;
        }
        if (*weak_counter == 1)
        {
            delete weak_counter;
            delete str_counter;
            delete ptr;
        }
        else
        {
            --(*str_counter);
            --(*weak_counter);
        }
    }

    void reset(T* ptr)
    {
        delete this->ptr;
        delete this->strongCounter;
        delete this->weakCounter;
        str_counter = new unsigned(1);
        weak_counter = new unsigned(1);
        this->ptr = ptr;
    }

    void reset()
    {
        if (ptr == nullptr || weak_counter == nullptr)
        {
            return;
        }
        else if (*str_counter == 1)
        {
            delete str_counter;
            delete weak_counter;
            delete ptr;
        }
        else
        {
            --(*str_counter);
            --(*weak_counter);
        }
    }

    unsigned use_count() const {
        return (str_counter) ? *str_counter : 0;
    }

    T* get() const
    {
        return ptr;
    }

    T* operator->() const noexcept
    {
        return ptr;
    }

    T& operator*() const noexcept
    {
        return *ptr;
    }

    shared_ptr& operator=(shared_ptr<T>&& other) noexcept
    {
        ptr = other.ptr;
        str_counter = other.str_counter;

        return *this;
    }
};

template <class T>
class weak_ptr
{
private:
    T* ptr;
    unsigned* str_counter;
    unsigned* weak_counter;
public:
    friend class shared_ptr<T>;
    weak_ptr() : ptr(nullptr), str_counter(nullptr), weak_counter(nullptr) {}
    weak_ptr(T* shObj)
        : ptr(shObj)
    {
        if (ptr == nullptr)
        {
            return;
        }
        weak_counter = new unsigned(1);
        str_counter = new unsigned(0);
    }
    weak_ptr(shared_ptr<T>& other) : ptr(other.ptr), str_counter(other.str_counter), weak_counter(other.weak_counter)
    {
        if (ptr == nullptr)
        {
            return;
        }
        ++(*weak_counter);
    }

    weak_ptr(weak_ptr<T>& other) : ptr(other.ptr), str_counter(other.str_counter), weak_counter(other.weak_counter)
    {
        if (ptr == nullptr)
        {
            return;
        }
        ++(*weak_counter);
    }

    ~weak_ptr() {
        qDebug() << "WEAK";
        if (ptr == nullptr || weak_counter == nullptr)
        {
            return;
        }
        if (*weak_counter == 1)
        {
            delete weak_counter;
            delete str_counter;
            delete ptr;
        }
        else
        {
            --(*str_counter);
            --(*weak_counter);
        }
    }

    shared_ptr<T> lock() {

        shared_ptr<T>* tmp = new shared_ptr<T>;
        if (*(this->weak_counter))
        {
            tmp->ptr = this->ptr;
            tmp->str_counter = this->str_counter;
            tmp->weak_counter = this->weak_counter;
            ++(*(tmp->str_counter));
            ++(*(tmp->weak_counter));
        }
        return *tmp;
    }

    void reset(){
        if (ptr == nullptr || weak_counter == nullptr)
        {
            return;
        }
        else if (*weak_counter == 1)
        {
            --*(weak_counter);
            delete ptr;
        }
        else
        {
            --(*weak_counter);
        }
    }
};

#endif // POINTERS_H
