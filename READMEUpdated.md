                                --------------------------------------
                                ---- Stock Market Simulation App -----
                                --------------------------------------
---------------------------------------------------------------------------------------------------
                                        ---- Contributors -----
---------------------------------------------------------------------------------------------------
Kunth Shah
Raghav Kajaria
Neel Patel
Maanya DN
Rishikarthik Velliangiri
---------------------------------------------------------------------------------------------------
                                ------Processes and features------
----------------------------------------------------------------------------------------------------

1. User Creation
2. DMAT Processes: Withdraw, Add, Check Balnce
3. Multiple Company option
4. Share Options: Buy, Sell quantity
5. Graph Analytics based on trend -> x amount of data points (x=5 in our case)

--------------------------------------------------------------------------------------------------
                                ------- Demo Input and Output ------
---------------------------------------------------------------------------------------------------

Sample Input: 

Enter Name: John
Enter Password: 123
Enter Your Age: 19
Enter amount to deposit: 9999999

Enter Company Index 
Choose 0                   // 0 is for Tata Shares
Choose 1                 
    qty 10             // Option to buy -> write 10 for quantity

Choose 1                 
    qty 10             // Option to buy -> write 10 for quantity

Choose 1                 
    qty 10             // Option to buy -> write 10 for quantity

Choose 1                 
    qty 0             // Option to buy -> write 0 for quantity

Choose 1                 
    qty 0             // Option to buy -> write 0 for quantity


--------------------------------------------
--------------------------------------------
Output: 


Time Unit 1: 51.5358
Time Unit 2: 52.5984
Time Unit 3: 53.6942
Time Unit 4: 0
Time Unit 5: 0
Bearish Engulfing Pattern: Price would likely decline    // Analysis Called based on pattern



---------------------------------------------------------------------------------------------------
                        ----------------Explaination-------------------
---------------------------------------------------------------------------------------------------

As the stock Market advances, we could see that there is change in share price, within the first 10 time slots, the share prices increased by more than 50rs. 
Later the stock stabalized. 

This analysis shows that the prices would likely increase in the future. This is an understanding of how the actual stock market intra-day candle chart depicts. The particular analysis called is: 
Bearish Engulfing Pattern. 

As mentioned earlier, in the actual stock market there are mutliple buyers and sellers. 
This simulation represents a small test case scenario. 

The que now gets cleared for the pattern to be repeated again for a new analysis to be called.


---------------------------------------

Basic Understanding Overview: 
A share market is controlled by sellers and buyers. The invinvible hand of the market changes the prices of the shares and allocates it the right way, 
this updates the share price. 
This stock market tool helps simulate this enviornment, in a controlled manner. The share price is determined by Quantity and Value of the company.
In the actual share market there are multiple buyers and sellers, however this model uses a single buyer and seller to infleunce the market. 


----------------------------------------
This is a capstone training project created at FLAME University
Last Updated: 9th December 2023

