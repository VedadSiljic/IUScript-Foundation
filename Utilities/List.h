#ifndef NULL
#define NULL 0
#endif

#ifndef List_H_Included
#define List_H_Included
typedef unsigned int sizeT;

template <typename VT> struct listNode {
  listNode<VT> *Next = NULL, *Previous = NULL;
  VT value;
};
#endif