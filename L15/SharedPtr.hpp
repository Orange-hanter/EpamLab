#define INCREACE (count != nullptr && ++(*count));
#define DECREACE (count != nullptr && --(*count));

template<typename T>
struct SharedPtr
{
    // реализуйте следующие методы
    //
    explicit SharedPtr(T* ptr = 0) :ptr_(ptr), count(nullptr) {
        if (ptr != nullptr) {
            count = new size_t(0);
            INCREACE
        }
    }

    ~SharedPtr() {
        if (ptr_ == nullptr) {
            return;
        }
        DECREACE;
        verify();
    }

    SharedPtr(const SharedPtr& ptr) {
        this->ptr_ = ptr.ptr_;
        if (ptr_ != nullptr) {
            this->count = ptr.count;
            INCREACE
        }
    }

    SharedPtr& operator=(const SharedPtr& ptr) {
        if (ptr_ == ptr.ptr_) return *this;
        if (ptr_ != nullptr) INCREACE;
        verify();
        this->ptr_ = ptr.ptr_;
        this->count = ptr.count;
        INCREACE
    }

    T* get() const {
        return ptr_ != nullptr ? ptr_ : nullptr;
    }


    // 1 - освобождение указателя
    // 2 - инициализация указателя
    // 3 - изменение указателя на ново созданный объект
    void reset(T* ptr = 0) {
        if (ptr_ != nullptr) {
            DECREACE;
            verify();
            count = nullptr;
            ptr_ = nullptr;
        }
        if (ptr != nullptr) {
            ptr_ = ptr;
            count = nullptr;
            count = new int(0);
            INCREACE;
        }
    }

    T& operator*() const {
        return *ptr_;
    }

    T* operator->() const {
        return ptr_;
    }

private:
    // Return:
    // True - if data was cleared
    // False - if object is still exist
    bool verify() {
        if (count != nullptr && *count > 0) return false;
        delete ptr_;
        delete count;
        ptr_ = nullptr;
        count = nullptr;
        return true;
    }

private:
    size_t* count;
    T* ptr_;
};