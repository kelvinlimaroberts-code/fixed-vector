//#include "fixed_vector.h"
#include "fixed_vector.h"

#include <cassert>   // for assert
#include <algorithm> // for std::sort, std::transform, std::rotate, std::reverse


int main ()
{
  // RUN IN DEBUG MODE (SO THE ASSERTS WORK)
  // IF THE PROGRAM JUST ENDS (WITH NO POPUPS), IT'S ALL WORKING :)
  // IF IT DOESN'T COMPILE, CHECK YOU HAVE FIXED EVERYTHING IN 'fixed_vector_STARTER.h'
  // IF AN ASSERT FAILS A POPUP WILL APPEAR, SELECT 'RETRY' AND YOU WILL BE TAKEN TO THE ASSERT THAT FAILED!


  fixed_vector <int, 10> my_fixed_vector_1;                     // default constructor
  fixed_vector <int, 10> my_fixed_vector_2 (5, 4);              // conversion constructor, set current size, set value of new elements
  fixed_vector <int, 10> my_fixed_vector_3 (6);                 // conversion constructor, set current size, default construct new elements
  fixed_vector <int, 10> my_fixed_vector_4 (my_fixed_vector_2); // copy constructor

  assert (my_fixed_vector_1.size () == 0);

  assert (my_fixed_vector_2.size () == 5);
  for (int i = 0; i < my_fixed_vector_2.size (); ++i)
  {
    assert (my_fixed_vector_2 [i] == 4);
  }

  assert (my_fixed_vector_3.size () == 6);

  assert (my_fixed_vector_4.size () == my_fixed_vector_2.size ());
  for (int i = 0; i < my_fixed_vector_4.size (); ++i)
  {
    assert (my_fixed_vector_2 [i] == my_fixed_vector_4 [i]);
  }


  my_fixed_vector_2 = my_fixed_vector_3;                        // = operator

  assert (my_fixed_vector_2.size () == my_fixed_vector_3.size ());
  for (int i = 0; i < my_fixed_vector_2.size (); ++i)
  {
    assert (my_fixed_vector_2 [i] == 0);
  }


  //my_fixed_vector_1 [0] = 44;                                 // invalid, current size = 0
  my_fixed_vector_2 [0] = 44;                                   // set element 0 to 44
  int my_int1 = my_fixed_vector_2 [0];                          // get copy of element 0
  assert (my_int1 == 44);
  int& my_int2 = my_fixed_vector_2 [1];                         // get reference element 1
  my_int2 = 99;                                                 // set element 1 via reference
  assert (my_fixed_vector_2 [1] == 99);
  int const& my_int3 = my_fixed_vector_2 [2];                   // get const reference to element 2
  assert (my_int3 == 0);


  //my_fixed_vector_1.front () = 52;                            // invalid, current size = 0
  my_fixed_vector_2.front () = 52;                              // set first element
  int my_int21 = my_fixed_vector_2.front ();                    // get copy of first element
  assert (my_int21 == 52);
  int& my_int22 = my_fixed_vector_2.front ();                   // get reference to first element
  my_int22 = 201;                                               // set first element via reference
  assert (my_fixed_vector_2 [0] == 201);
  int const& my_int23 = my_fixed_vector_2.front ();             // get const reference to first element
  assert (my_int23 == 201);


  //my_fixed_vector_1.back () = 64;                             // invalid, current size = 0
  my_fixed_vector_2.back () = 64;                               // set last element
  int my_int31 = my_fixed_vector_2.back ();                     // get copy of last element
  assert (my_int31 == 64);
  int& my_int32 = my_fixed_vector_2.back ();                    // get reference to last element
  my_int32 = 99;                                                // set last element via reference
  assert (my_fixed_vector_2 [my_fixed_vector_2.size () - 1] == 99);
  int const& my_int33 = my_fixed_vector_2.back ();              // get const reference to last element
  assert (my_int33 == 99);


  bool is_empty1 = my_fixed_vector_1.empty ();                  // is container empty, true, current size == 0
  assert (is_empty1);
  bool is_empty2 = my_fixed_vector_2.empty ();                  // is container empty, false, current size != 0
  assert (!is_empty2);


  int size1 = my_fixed_vector_1.size ();                        // get current size
  assert (size1 == 0);
  int size2 = my_fixed_vector_2.size ();                        // get current size
  assert (size2 == 6);


  int max_size1 = my_fixed_vector_1.max_size ();                // what is the maximum capacity of elements the container can hold?
  int max_size2 = my_fixed_vector_2.max_size ();
  assert (max_size1 == 10);
  assert (max_size2 == 10);


  assert (my_fixed_vector_1.size () == 0);
  my_fixed_vector_1.clear ();                                   // already empty
  assert (my_fixed_vector_1.size () == 0);
  assert (my_fixed_vector_2.size () == 6);
  my_fixed_vector_2.clear ();                                   // sets current size = 0, no actual delete!
  assert (my_fixed_vector_2.size () == 0);
  bool is_empty3 = my_fixed_vector_2.empty ();                  // my_fixed_vector_2 is now empty, current size == 0
  assert (is_empty3);


  for (int i = 0; i < my_fixed_vector_3.size (); ++i)           // fill up my_fixed_vector_3
  {                                                             // with some dummy data
    my_fixed_vector_3 [i] = i * 10;
  }

  auto it_begin1 = my_fixed_vector_3.begin ();                  // get iterator to beginning of container (begin points to first element in container)
  int my_int41 = *it_begin1;                                    // get value of element currently pointed to by it_begin1
  assert (my_int41 == 0);
  ++it_begin1;                                                  // incerement it_begin1 so it now points to the second element in the container
  int my_int42 = *it_begin1;                                    // get value of element currently pointed to by it_begin1
  assert (my_int42 == 10);
  auto it_begin2 = my_fixed_vector_3.erase (it_begin1);         // remove element pointed to iterator from the container, returns iterator to element now at that position
  int my_int43 = *it_begin2;                                    // get value of element pointed to by it_begin2 (second element of container)
  assert (my_int43 == 20);


  auto it_end1 = my_fixed_vector_3.end () - 1;                  // get iterator to beginning of container (begin points to first element in container)
  int my_int51 = *it_end1;                                      // get value of element currently pointed to by it_end1
  assert (my_int51 == 50);
  --it_end1;                                                    // decrement it_end1 so it now points to the second last element in the container
  int my_int52 = *it_end1;                                      // get value of element currently pointed to by it_end1
  assert (my_int52 == 40);
  auto it_end2 = my_fixed_vector_3.erase (it_end1);             // remove element pointed to iterator from the container, returns iterator to element now at that position
  int my_int53 = *it_end2;                                      // get value of element pointed to by it_end2 (last element of container)
  assert (my_int53 == 50);


  int my_int61 = my_fixed_vector_3.back ();                     // get copy of last element
  assert (my_int61 == 50);
  my_fixed_vector_3.push_back (77);                             // add a new element at the end of the array
  int my_int62 = my_fixed_vector_3.back ();                     // get copy of last element
  assert (my_int62 == 77);
  my_fixed_vector_3.pop_back ();                                // remove last element
  int my_int63 = my_fixed_vector_3.back ();                     // get copy of last element
  assert (my_int63 == 50);


  int size3 = my_fixed_vector_4.size ();                        // get current size
  assert (size3 == 5);
  my_fixed_vector_4.resize (1);                                 // resize container to contain 1 element, keeps leading elements (0, 1, ...)
  int size4 = my_fixed_vector_4.size ();                        // get current size
  assert (size4 == 1);
  my_fixed_vector_4.resize (0);                                 // resize container to contain 0 elements
  int size5 = my_fixed_vector_4.size ();                        // get current size
  assert (size5 == 0);
  my_fixed_vector_4.resize (6);                                 // resize container to contain 0 elements
  int size6 = my_fixed_vector_4.size ();                        // get current size (what are the value of those 6 elements?)
  assert (size6 == 6);
  //my_fixed_vector_4.resize (15);                              // invalid, container can only hold a maximum of 10 elements


  my_fixed_vector_3.resize (my_fixed_vector_3.max_size ());     // fill up my_fixed_vector_3
  for (int i = 0; i < my_fixed_vector_3.size (); ++i)           // with some dummy data
  {
    my_fixed_vector_3 [i] = my_fixed_vector_3.size () - i - 1;
  }


  std::sort (my_fixed_vector_3.begin (),                        // sorts a range into ascending order
    my_fixed_vector_3.end ());
  for (int i = 0; i < my_fixed_vector_3.size (); ++i)
  {
    assert (my_fixed_vector_3 [i] == i);
  }
  std::transform (my_fixed_vector_3.begin (),                   // applies a function to a range of elements
    my_fixed_vector_3.end (),                                   // storing results in a destination range
    my_fixed_vector_3.begin (),
    [](int i) { return i * 10; });
  for (int i = 0; i < my_fixed_vector_3.size (); ++i)
  {
    assert (my_fixed_vector_3 [i] == i * 10);
  }


  std::rotate (my_fixed_vector_3.begin (),                      // just some extra compatibility tests for you to check
    my_fixed_vector_3.begin () + 3,                             // https://en.cppreference.com/w/cpp/algorithm
    my_fixed_vector_3.end ());
  std::reverse (my_fixed_vector_3.begin (),
    my_fixed_vector_3.end ());


  return 0;
}
