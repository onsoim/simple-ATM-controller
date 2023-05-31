# Simple ATM controller

The purpose of this project is **write code for a simple ATM controller** with functions/classes/methods, etc.

> An **ATM controller** (**ATMC**) is a system used in financial institutions to route financial transactions between [ATMs](https://en.wikipedia.org/wiki/Automated_teller_machine "Automated teller machine"), [core banking systems](https://en.wikipedia.org/wiki/Core_banking "Core banking") and other banks. An ATMC is sometimes referred to as an "EFTPOS Switch." An ATM controller is key infrastructure in an [interbank network](https://en.wikipedia.org/wiki/Interbank_network "Interbank network").

<br>

## Requirements

1. Insert Card
  
2. PIN number
  
3. Select Account
  
4. See Balance/Deposit/Withdraw
  
<br>

> Consider integrating with a real bank system.

- Real cash bin in the ATM
  
  - e.g., can't withdraw money exceeding the amount from the cash bin
    
- Test feasibility
  
- Testing the controller part

<br>

```textile
Write code for a simple ATM. It doesn't need any UI (either graphical or console), but a controller should be implemented and tested.

Requirements
At least the following flow should be implemented:
Insert Card => PIN number => Select Account => See Balance/Deposit/Withdraw

For simplification, there are only 1 dollar bills in this world, no cents. Thus account balance can be represented in integer.

Your code doesn't need to integrate with a real bank system, but keep in mind that we may want to integrate it with a real bank system in the future. It doesn't have to integrate with a real cash bin in the ATM, but keep in mind that we'd want to integrate with that in the future. And even if we integrate it with them, we'd like to test our code. Implementing bank integration and ATM hardware like cash bin and card reader is not a scope of this task, but testing the controller part (not including bank system, cash bin etc) is within the scope.

A bank API wouldn't give the ATM the PIN number, but it can tell you if the PIN number is correct or not.

Based on your work, another engineer should be able to implement the user interface. You don't need to implement any REST API, RPC, network communication etc, but just functions/classes/methods, etc.

You can simplify some complex real world problems if you think it's not worth illustrating in the project.

How to submit
Please upload the code for this project to GitHub or anywhere, and post a link to your repository below. Please attach the instruction to clone your project, build and run tests in README.md file in the root directory of the repository.
```
