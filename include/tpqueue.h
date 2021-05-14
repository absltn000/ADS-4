// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <cassert>

template<typename T>
class TPQueue
{
    
private:
    
    T *arr;          // массив с данными
    int size;        // максимальное количество элементов в очереди (размер массива)
    int begin,       // начало очереди
        end;         // конец очереди
    int count;
// счетчик элементов
public:
    
TPQueue<T>::TPQueue(int sizeQueue) :
  size(sizeQueue),
  begin(0), end(0), count(0)
{
  arr = new T[size];
}


~TPQueue()
{
  delete[] arr;
}




void push(const T& item)
{

  assert(count < size);
  int index = -1;
  int i = begin - 1;
  do {
    i++;
    if (i == size)
      i = 0;
    if (item.prior > arr[i]) {
      index = i;
      break;
    }
  } while (i < end);
  if (end + 1 == size) {
    end = 0;
    count++;
  } else {
    end++;
    count++;
  }
  if (index != -1) {
    while (i == end) {
      if (i == size - 1)
        swap(arr[i], arr[0]);
      else
        swap(arr[i].arr[i + 1]);
    }
    arr[index] = item;
  } else {
    arr[end] = item;
  }
}



T pop()
{
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

T get() const
{
  assert(count > 0);
  return arr[begin];
}


bool isEmpty() const
{
  return count == 0;
}


bool isFull() const
{
  return count == size - 1;
}



};

struct SYM {
  char ch;
  int  prior;
};


#endif // INCLUDE_TPQUEUE_H_
