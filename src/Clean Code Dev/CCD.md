&rarr; Reducing amount of code in void main() for better view and creating functions instead

[THEN](https://github.com/gaderiv/SRH-Software-Development-Personal-Finance-Manager/commit/3653979d2540aaeef5316350c4bf457dc4704d94#:~:text=case%201%3A,successfully.%5Cn%22%3B), [NOW](https://github.com/gaderiv/SRH-Software-Development-Personal-Finance-Manager/blob/e0e575aad41862babdd12c86c6904b2ca569db1e/src/main.cpp#L189-L211)

Reducing amount of code in switch helped me with organizing space and makes it more readible.

&rarr; [Explanatory variables](https://github.com/gaderiv/SRH-Software-Development-Personal-Finance-Manager/blob/e0e575aad41862babdd12c86c6904b2ca569db1e/src/main.cpp#L164-L166)

explanatory variables helped me with knowing what should I use. I did not wasted my time searching for "how do I called this variable?", names are clear and uniqe for me. Some people might be a little bit confused with those names but when the will see my POV itt will be easy to use them for everyone

&rarr; [Good comments](https://github.com/gaderiv/SRH-Software-Development-Personal-Finance-Manager/blob/e0e575aad41862babdd12c86c6904b2ca569db1e/src/PFMLib/FinanceManager.h#L22-L50)

Since my functions are self-explanatory I barely use comments. I mostly use comments to point the most important things to better catch the thing where is something. Also when it will come to the point of big algorithm comments might explain complexity of logic

&rarr; [Error handling](https://github.com/gaderiv/SRH-Software-Development-Personal-Finance-Manager/blob/e0e575aad41862babdd12c86c6904b2ca569db1e/src/PFMLib/Budgeting.cpp#L26-L34)

Error handling in my case I used for files, sometimes user is unavailable somehow to create file so it is important to know what exactly happendd. 

&rarr; [Intuitive Function names and clear intention of the function/method](https://github.com/gaderiv/SRH-Software-Development-Personal-Finance-Manager/blob/e0e575aad41862babdd12c86c6904b2ca569db1e/src/main.cpp#L130-L158)

Intuitive function names explains me a lot with what is going on. It helps me plan better and use them by calling the thing what they will be doing. It also helps me find a bug when it comes to unit test because I know which function/funcktions are responsible for it 
