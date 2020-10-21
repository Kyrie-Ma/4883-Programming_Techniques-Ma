## 10684 - The jackpot
### Yuankai Ma
![2020-10-21](https://user-images.githubusercontent.com/60235679/96675982-e3235180-1331-11eb-9951-02c14872cace.png)

### Description: 
    Count the maximum possible gain out of a sequence of bets. If no possibility to win money output message "Losing streak"

### Walk through: 
    1. Use while loop to read one data when it is not equal to 0. If it equal to 0 end the while loop and end the program.
    2. Create a for loop base on the data just read in.
    3. Read in the data in each time of loop. The initialize gain is 0 and add the data into it in each time of loop. Whenever 
       the gain is equal to 0 or smaller than 0, set the gain equal to 0. The Initialize maximum gain is 0. Compare the gain 
       with the maximum gain, whenever the gain is bigger than the maximum gain, maximum gain equal to the gain.
    4. After the loop enter if the maximum gain greater than 0. Print the maximum gain as The Maximum winning streak.
       If the maximum gain is equal to 0 or smaller than 0. Print the massage of Losing streak. And set the gain and the 
       maximum gain equal to 0. And go to the next while loop until it read in a 0.
