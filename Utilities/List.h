#ifndef NULL
#define NULL 0
#endif

#ifndef List_H_Included
#define List_H_Included
typedef unsigned int sizeT;

template < typename VT > struct listNode {
  listNode < VT > * Next = NULL, * Previous = NULL;
  VT value;
};

template < typename VT > class List {
  protected:
    listNode < VT > * start = NULL, * end = NULL;
  sizeT size;
  public:
    void Add(VT valueToAdd,
      const sizeT index) {
      if (index > this -> size)
        throw "Invalid Position";
      else if (index == size) {
        if (!size)
          start = end = new listNode < VT > ;
        else {
          end -> Next = new listNode < VT > ;
          end -> Next -> Previous = end;
          end = end -> Next;
        }
        end -> value = valueToAdd;
      } else {
        listNode < VT > * temp = getInstance(index), * valueNodeToAdd = new listNode < VT > ;
        if (temp == start)
          start = valueNodeToAdd;

        valueNodeToAdd -> value = valueToAdd;
        valueNodeToAdd -> Previous = temp -> Previous;
        valueNodeToAdd -> Next = temp;

        if (valueNodeToAdd -> Previous)
          valueNodeToAdd -> Previous -> Next = valueNodeToAdd;
        temp -> Previous = valueNodeToAdd;
      }

      this -> size = this -> size + 1;
    } // Adds a value to the specific index

  void Add(VT valueToAdd) {
    Add(valueToAdd, this -> size);
  }

  void Remove(const sizeT indexToRemove) {
    listNode < VT > * temp = this -> getInstance(indexToRemove);
    if (start == temp)
      start = temp -> Next;
    if (end == temp)
      end = temp -> Previous;

    if (temp -> Previous != NULL)
      temp -> Previous -> Next = temp -> Next;
    if (temp -> Next != NULL)
      temp -> Next -> Previous = temp -> Previous;

    delete temp;
    this -> size = this -> size - 1;
  } // Removes a value at a index

  void Remove() {
    Remove(this -> size - 1);
  }
  
  List() {}~List() {}
};
#endif