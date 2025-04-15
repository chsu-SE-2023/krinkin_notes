#include     <iostream>

    // This file is bigger then 20-30 lines. I can't get it smaller, but
    // functional...

/*
* This class represents some sorted array
* This example uses bubble sorting
*/

    class    SortedArray    {
private:
	int*   array;
    int  arr_size;
public:
	SortedArray(int* arr, int size) {
        // Yes, array sorted in constructor
		array  =    arr;
        this->arr_size = size;

        for (int j =    1; j <    size;   j++) {
            bool   isSorted  =    true;


            for (int i = 0; i < size - j; i++) {
                  if (array[i] > array[i + 1]) {
                    int  tmp =   array[i];

                      array[i]   = array[i + 1];
                       array[i + 1] = tmp;

                     isSorted    = false;
                  }
               }
              if (   isSorted    )    break;
          }
	}


    int   size()    const { return     arr_size; }


	int*    get_array()    const {     return array; }
};

void     arr_print(int*      arr, int size) {
    for    (int i = 0; i < size; i++) { // Some comment
        std::cout     <<    arr[i]    <<    " ";
    }
    std::cout    <<    std::endl;
}

int main() { // Even more comments
    int* arr    =    new int[10]    { 5, 7, 3, 0, 1, 8, 4, 2, 6, 9 };
          std::cout << "Unsorted array: ";     arr_print(arr, 10);
    // AHhahahahahahhaahhahaha, it is comment, btw
    SortedArray*   s_arr =    new SortedArray(arr, 10);
             std::cout << "Sorted array: ";     arr_print(  s_arr->get_array(),     s_arr->size()  );
    return    0;
}