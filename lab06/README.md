#Question 2

Part A:
My code is stable because duplicate values in my code do not swap with each 
other and keep their relative position to each other. I selected several tests 
which test its stability as well as hand traced an iteratation which confirmed 
that the duplicate values keep their relative position to each other. The if
statement within the selection sort portions of my code checks to see if the 
current value it is checking and the min are the same. The code will then only
swap them if they are NOT the same. This ensures that they will not change 
positions with each other. I also iterate forwards through the array so if any
other values must switch with the duplicates, the first instance of the 
duplicate will move forward first and so on, thus keeping them in the same 
relative positioning to each other. In this way, my selectionsort function
is a stable sort. 

Part B: In order to implement the program, I placed this section in main.cc
along with commented code expalining why each test proves stability. 