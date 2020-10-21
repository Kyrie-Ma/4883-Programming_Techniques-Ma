## 10130 - SuperSale
### Yuankai Ma
![2020-10-21 (2)](https://user-images.githubusercontent.com/60235679/96708385-cb15f700-135e-11eb-9158-eec968aea1c0.png)

### Description: 
    Count the maximum value in certain weight that can take from the market.
    
### Walk Through:
    1. First data read in is the number of cases, create a loop to loop to case.
    2. Inside the loop, the first data that read in is the number of object. Then create a 2D array to store the object's value 
    and Oweight.The next thing to read in is the number of people, and then is the Pweight that each people can carry. Start 
    at the array[1][1]. Create a Remain = Pweight - current Oweight. If Remain greater than 0, add the current object's value to
    MaxValue1,And go to the next object. If the Remain < 0, go to the next object. and keep doing this step until the last object.
    
    After it finish, set the Remain = 0, move to the next arrary which is start at array[2][1], and the Remain = Pweight - current
    Oweight. If Remain greater than 0, add the current object's value to MaxValue2,And go to the next object. If the Remain < 0, go
    to the next object. And the next object is start from the first object. After it finish, compare the MaxValue1 and the MaxValue2,
    store the bigger one at MaxValue1, set the MaxValue2 = 0 which is use for the next object loop. Keep doing this two loop until
    the end of the object. Then we will get the maximum value for this person can carry, then we can go to the next person and do the
    same two loop base on his biggest weight.
    3. Add all person's maximum value and print it out.
