// #include <bits/stdc++.h>
// using namespace std;


// class DynamicArray
// {
//   int *a;
//   int sz, cap;
// public:
//   DynamicArray() {
//     a = NULL, sz = 0, cap = 0;
//   }

//   void push_back(int num) {
//     if (sz < cap) {
//       a[sz] = num;
//       sz++;
//     }
//     else {
//       int *b;

//       if (cap > 0)
//         b = new int[2 * cap], cap *= 2;
//       else
//         b = new int[1], cap = 1;

//       for (int i = 0; i < sz; ++i)
//         b[i] = a[i];

//       delete[] a; // freeing the memory taken by a.

//       a = b;
//       a[sz] = num;
//       sz++;
//     }
//   }

//   int size() {
//     return sz;
//   }

//   int capacity() {
//     return cap;
//   }

//   void pop_back() {
//     if (sz > 0)
    //   arr[sz - 1] = 0, sz--;
//   }

//   int operator[](int i) {

//     if (i >= 0 and i < sz)
//       return a[i];

//     else
//       return -1;
//   }
// };

// int main() {
//   // your code goes here
//   return 0;
// }