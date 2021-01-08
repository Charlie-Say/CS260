Make a chart to compare the algorithmic complexity (use Big-O notation) of your insert, remove, and search algorithms you used for your structures.

Function: enqueue()
O(1) - This function creates a new node and shifts all the previous nodes into the next position. It runs in linear time because it is only taking in one input (data) at a time and does not require it to loop at all so it is constant.

Function: display()
O(n) - This function takes the first index and prints it, then moves to the next index and continues to print in linear time till the last node is equal to NULL. It only runs through the list/array one time.

Function: sortList()
O(n^n) - This function compares the previous node to the next to see if it is greater than the previous node to move data into the correct sorting position. Depending on the positions and how random the numbers are on the list will determine the power of "n". The number of loops to completely sort the list will be determined by how many numbers will need to be compared until all data reaches the correct sorting position.

