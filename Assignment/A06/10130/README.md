## 10130 - SuperSale
### Yuankai Ma

### Description: 
    Count the maximum value in certain weight that can take from the market.
    
### Walk Through:
    1. First data read in is the number of cases, create a loop to loop to case.
    2. Inside the loop, the first data that read in is the number of object. Then create a 2D array to store the object's value and Oweight.
       The next thing to read in is the number of people, and then is the Pweight that each people can carry. Start at the array[1][1]. 
       Create a Remain = Pweight - Oweight. If Remain greater than 0, add the current object's value to MaxValue, And go to the next object. 
       If the Remain < 0, go to the next object. and keep doing this step until the last object.
