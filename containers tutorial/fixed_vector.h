#pragma once

#include <algorithm> // for std::copy_n


template <class T, unsigned int kMaxSize>
class fixed_vector
{
public:
  // Member types

  // https://en.cppreference.com/w/cpp/language/type_alias
  using value_type = T;
  using size_type = int;
  using pointer = T*;
  using const_pointer = T const*;
  using reference = T&;
  using const_reference = T const&;

  using iterator = T*;
  using const_iterator = T const*;


  // Member functions

  fixed_vector () : m_data {}, m_current_size {} { }
  fixed_vector (size_type count, const_reference value) : m_data {}, m_current_size { count }
  {
      if (count > kMaxSize)
      {
          m_current_size = kMaxSize;
      }
          for (size_type i = 0; i < m_current_size; i++)
          {
              m_data[i] = value;
          }
      
  }
  explicit fixed_vector (size_type count) : m_data {}, m_current_size { count }
  {
      if (count > kMaxSize)
      {
          m_current_size = kMaxSize;
      }
  }
  fixed_vector (fixed_vector const& other) : fixed_vector () { *this = other; }

  fixed_vector& operator= (fixed_vector const& other)
  {
    resize (other.m_current_size);
    std::copy_n (other.m_data, other.m_current_size, m_data);

    return *this;
  }


  // Element access

  reference operator [] (size_type pos) {m_data[pos];}
  const_reference operator [] (size_type pos) const { m_data[pos]; }

  reference front() { m_data[0]; }
  const_reference front() const { m_data[0]; }

  reference back() { m_data[m_current_size - 1]; }
  const_reference back () const { m_data[m_current_size - 1]; }


  // Iterators

  iterator begin () { return m_data; }
  const_iterator begin () const { return m_data; }

  iterator end () { return m_data + m_current_size; }
  const_iterator end () const { return m_data + m_current_size; }


  // Capacity

  bool empty () const { return m_current_size == 0; }

  size_type size () const { return m_current_size; }

  size_type max_size () const { return kMaxSize; }


  // Modifiers

  void clear() { m_current_size = 0; }

  iterator erase (iterator pos)
  {
    // TODO:
    // 1. get num elements between first element and element at {pos}
    // 2. copy the data from {pos + 1} to the end to {pos}, effectively move everything after {pos} forward 1 place
    // 3. 'delete' the last element
    // 4. return the iterator (pointer) to the element now at {pos}, using the distance created between in step 1

    // e.g.
    // m_current_size = 8, kMaxSize = 8
    // |-------------------------------|
    // | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
    // |-------------------------------|
    //                                end
    //
    //
    // my_fixed_vector.erase ({iterator to element at index 2});
    //
    //
    // 1. m_current_size = 8, kMaxSize = 8
    //    |-------------------------------|
    //    | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
    //    |-------------------------------|
    //              ^                    end
    //              |
    //              |
    //    get distance between begin and element to be deleted
    //    number of hops from begin to iterator
    //    https://en.cppreference.com/w/cpp/iterator/distance
    //    offset = 2
    //
    // 2. m_current_size = 8, kMaxSize = 8
    //    |-------------------------------|
    //    | 0 | 1 | 3 | 4 | 5 | 6 | 7 | 7 |
    //    |-------------------------------|
    //              ^                    end
    //              |
    //              |
    //    shift data forward 1 place
    //
    // 3. actual array is NOT deleted or re-allocated
    //    data beyond last element is still there, we just cant get to it!
    //    m_current_size = 7, kMaxSize = 8
    //    |---------------------------|----
    //    | 0 | 1 | 3 | 4 | 5 | 6 | 7 | 7 |
    //    |---------------------------|----
    //              ^                end
    //              |                     unused data
    //              |
    //
    // 4. return: begin + {offset}
    //
      auto offset = std::distance(begin(), pos);
      for (auto i = pos; i < end(); i++)
      {
          m_data[*pos] = m_data[*pos + 1];
      }
      m_current_size--;
      return begin() + offset;
  }

  void push_back (const_reference value)
  {
      if (m_current_size < kMaxSize)
      {
          m_data[m_current_size] = value;
          m_current_size++;
      }
  }

  void pop_back ()
  {
      if (m_current_size > 0)
      {
          m_current_size--;
      }
  }

  void resize (size_type count)
  {
      if (count < 0)
      {
          count = 0;
      }
      else if (count > kMaxSize)
      {
          count = kMaxSize;
      }
      m_current_size = count;
  }


private:
  value_type m_data [kMaxSize]; // the data
  size_type m_current_size;     // the number of elements currently in the vector
                                // gives the index of the last element + 1
};
