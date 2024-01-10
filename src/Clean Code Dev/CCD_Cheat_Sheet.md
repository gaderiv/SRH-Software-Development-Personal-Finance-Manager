# Clean Code Development Cheat Sheet

## 1. Meaningful Names
Use function, variable and class names that describe their operation by name, making it easier to navigate through the code. It is important to avoid one-letter names or ambiguous abbreviations

Example in the code [click here to jump to the code](https://github.com/gaderiv/SRH-Software-Development-Personal-Finance-Manager/blob/e0e575aad41862babdd12c86c6904b2ca569db1e/src/main.cpp#L5-L160)

![image](https://github.com/gaderiv/SRH-Software-Development-Personal-Finance-Manager/assets/56294674/eff693f7-b1b0-4540-b6ae-991d4fea08c1)

## 2. Comments
Try to write your code to avoid the need to add comments, the code should be largely self-describing. You can use comments to separate specific areas to make it easier to find. If there is a need to use comments, use them to explain non-obvious or complex decisions or logic.

Example in the code [click here to jump to the code](https://github.com/gaderiv/SRH-Software-Development-Personal-Finance-Manager/blob/e0e575aad41862babdd12c86c6904b2ca569db1e/src/PFMLib/FinanceManager.h#L22-L50)

![image](https://github.com/gaderiv/SRH-Software-Development-Personal-Finance-Manager/assets/56294674/16f7e08b-5b3c-4784-b055-c1bcb0cc434e)

## 3. Functions
Remember to make functions/methods small and focused on a specific responsibility (Single Responsibility Principle). It is important to aim for a function to have no more than 20 lines of code, of course this is not always possible but it is important to keep this in the back of your mind. Use a nomenclature that explains the function itself. 

Example in the code [click here to jump to the code](https://github.com/gaderiv/SRH-Software-Development-Personal-Finance-Manager/blob/e0e575aad41862babdd12c86c6904b2ca569db1e/src/main.cpp#L5-L22)

![image](https://github.com/gaderiv/SRH-Software-Development-Personal-Finance-Manager/assets/56294674/dbcadfa6-ab0b-48dc-96c9-45a6a26fbbdc)

## 4. Formating
Use consistent formatting and adhere to the chosen style. Try to keep any tabs or spaces the same across all files. At the same time, try to keep the code readable

Example in the code [click here to jump to the code](https://github.com/gaderiv/SRH-Software-Development-Personal-Finance-Manager/blob/e0e575aad41862babdd12c86c6904b2ca569db1e/src/main.cpp#L205-L239)

![image](https://github.com/gaderiv/SRH-Software-Development-Personal-Finance-Manager/assets/56294674/ebd9db8d-7cda-4f12-a725-7ed41cbe46cf)

## 5. Error Handling
Use exceptions only in exceptional situations, do not use them to call up information in the console that a function has worked or is working. When using exceptions, provide clear information about what went wrong 

Example in the code [click here to jump to the code](https://github.com/gaderiv/SRH-Software-Development-Personal-Finance-Manager/blob/e0e575aad41862babdd12c86c6904b2ca569db1e/src/PFMLib/Budgeting.cpp#L26-L34)

![image](https://github.com/gaderiv/SRH-Software-Development-Personal-Finance-Manager/assets/56294674/39c9b4ed-cdcb-4c4c-8a2a-d4500076ba46)

## 6. STL Usage
Be familiar with and use the STL C++ Standard Library. Don't forget container classes for example vector. Try to use the functions available in them to improve the writing of algorithms, functions or methods

Example in the code [click here to jump to the code](https://github.com/gaderiv/SRH-Software-Development-Personal-Finance-Manager/blob/e0e575aad41862babdd12c86c6904b2ca569db1e/src/PFMLib/FinanceManager.h#L9-L21)

![image](https://github.com/gaderiv/SRH-Software-Development-Personal-Finance-Manager/assets/56294674/ca4a17a9-63b5-4d3c-8f3d-5dde84b7a97f)

## 7. Class Design
Follow the principle of one responsibility per class and prefer composition over inheritance. Use access specifiers such as public, private and protected to avoid unwanted use of or access to a variable/method/function

Example in the code [click here to jump to the code](https://github.com/gaderiv/SRH-Software-Development-Personal-Finance-Manager/blob/e0e575aad41862babdd12c86c6904b2ca569db1e/src/PFMLib/FinanceManager.h#L7-L30)

![image](https://github.com/gaderiv/SRH-Software-Development-Personal-Finance-Manager/assets/56294674/59d6651a-f2fc-461e-b8a5-7e0e21b6ef2a)

## 8. Refactoring
When writing code, even when we try to keep it clean we sometimes make a mess of it making the code less readable. Remember to refactor your code to improve code readability. 

Example in the code before [click here to jump to the code](https://github.com/gaderiv/SRH-Software-Development-Personal-Finance-Manager/commit/3653979d2540aaeef5316350c4bf457dc4704d94#diff-d0426b49b1040866a7a9f06b9123cc694841485766e70b709a65bc4d781b7909L34-L68:~:text=case%201%3A,successfully.%5Cn%22%3B)

Example in the code now [click here to jump to the code](https://github.com/gaderiv/SRH-Software-Development-Personal-Finance-Manager/blob/e0e575aad41862babdd12c86c6904b2ca569db1e/src/main.cpp#L189-L211)

Before:

![image](https://github.com/gaderiv/SRH-Software-Development-Personal-Finance-Manager/assets/56294674/0ed84178-cbd1-4cbe-b9da-25a3a70280df)

Now:

![image](https://github.com/gaderiv/SRH-Software-Development-Personal-Finance-Manager/assets/56294674/93fceb67-dac3-4ac5-a1a6-d6c20d1948cc)

## 9. Testing
For critical functionality, write unit tests to eliminate potential bugs in the code. Unit tests will support your work on the code and, before the code goes into production, help you to improve the performance of the program

Example in the code [click here to jump to the code](https://github.com/gaderiv/SRH-Software-Development-Personal-Finance-Manager/blob/master/src/UnitTests/UnitTests.cpp)

![image](https://github.com/gaderiv/SRH-Software-Development-Personal-Finance-Manager/assets/56294674/10d4ff9c-fef9-4451-8545-74176674bb73)



## 10. Const-Correctness
Use const to prevent messy overwriting of data in a variable as well as to ensure its immutability. Correct use of const will help you avoid getting messy erroneous data or results.

Example in the code [click here to jump to the code](https://github.com/gaderiv/SRH-Software-Development-Personal-Finance-Manager/blob/e0e575aad41862babdd12c86c6904b2ca569db1e/src/PFMLib/FinanceManager.h#L32-L41)

![image](https://github.com/gaderiv/SRH-Software-Development-Personal-Finance-Manager/assets/56294674/412353e3-b660-4006-a796-d1c643edf49d)
