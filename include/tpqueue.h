// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <cassert>

template<typename T>
class TPQueue
{
private:
  T* arr;
  int size;
  int begin,
    end;
  int count;
public:
  TPQueue():size(100), begin(0), end(0), count(0) {
    arr = new T[size];
  }

  ~TPQueue() {
    delete[] arr;
  }

  void push(const T &item) { 
    assert(count < size);
    int index = -1;
    int i = begin;
    while (i < end) {
      if (i == size)
        i = 0;
      if (item.prior > arr[i].prior) {
        index = i;
        break;
      }
      i++;
    }
    if (index != -1) {
      i = end;
      while (i != index) {
        if (i == 0)
        {
          T x = arr[i];
          arr[i] = arr[size - 1];
          arr[size - 1] = x;
          i = size - 1;
        } else {
          T x = arr[i];
          arr[i] = arr[i - 1];
          arr[i - 1] = x;
          i--;
        }
      }
      arr[index] = item;
    } else {
      arr[i] = item;
    }
    if (end + 1 == size) {
      end = 0;
      count++;
    } else {
      end++;
      count++;
    }
  }

  T pop() {
    assert(count > 0);

    T item = arr[begin];
    count--;

    if (begin + 1 == size) {
      begin = 0;
    } else {
      begin++;
    }
    return item;
  }

  T get() const {
    assert(count > 0);
    return arr[begin];
  }   

  bool isEmpty() const {
    return count == 0;
  }

  bool isFull() const {
    return count == size;
  }
};

struct SYM {
  char ch;
  int  prior;
};

#endif // INCLUDE_TPQUEUE_H_
