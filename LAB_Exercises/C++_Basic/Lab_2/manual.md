# In this lab, we will:

• Explore the concepts of dynamic memory allocation using the new and delete operators in C++.
• Learn how to allocate and deallocate memory for both single variables and arrays (1D and 2D).

# To perform dynamic memory allocation, we use the new and delete operators:

• new operator: Allocates memory on the heap.
• delete operator: Deallocates memory previously allocated by new.

# Tasks

Task 1: Dynamic Array Allocation (1D)
▪ Use the new operator to allocate an integer array of user-specified size.
▪ Prompt the user to input values for each array element.
▪ Print the values of the array.
▪ Finally, use the delete[] operator to deallocate the array.

Task 2: Dynamic Array Allocation (2D) with Equal Rows
▪ Use the new operator to allocate a two-dimensional character array, where the number of rows and columns is provided by the user.
▪ Ask the user to input a string for each row of the array.
▪ Print all the strings stored in the 2D array.
▪ Use the delete[] operator to deallocate the memory.

Task 3: Dynamic Array Allocation (2D) with Uneven Rows
▪ Use the new operator to allocate a two-dimensional integer array where the number of rows and
columns are provided by the user. In this case, each row will have a different number of columns.
▪ Prompt the user for the number of elements in each row and then input values for each element.
▪ Print the elements of the entire 2D array.
▪ Finally, deallocate the memory using the delete[] operator.
