# Hotel Management System (C Programming)

This is a C program that help hotels manage all their operations seamlessly.

To use, you need to:

- Download or clone this repository
- Run the program in any IDE, or online compiler that supports C language. Example: https://www.onlinegdb.com/

The hotel management system provides the following services:

<img width="483" alt="checkavailability1" src="https://user-images.githubusercontent.com/103124512/170775472-661eea2e-ccf6-4756-bc4b-baf83a8b9958.png">

**Check availavility of a room type:**

Check availability returns to the user a list of empty single/double/studio rooms depending on the choices he/she makes. 
This function is updated automatically when an empty room for example becomes occupied by an individual or a group of individual

<img width="728" alt="checkavailability2" src="https://user-images.githubusercontent.com/103124512/170775651-b2c698dd-861a-484a-a7ce-4d814670745b.png">

**Check in:**

When a customer arrives and wants to register at the hotel, he/she will be prompted to enter a set of information, including what room he/she wants to occupy.

<img width="797" alt="CheckIn1" src="https://user-images.githubusercontent.com/103124512/170776260-fed131c4-49cf-479e-a158-95a7b81faaff.png">

*Since the single room n:3 is now occupied, the check availability function does not return it among the available single rooms when called.* 

<img width="717" alt="checkavailability3" src="https://user-images.githubusercontent.com/103124512/170776578-4597b5ff-ac9c-45c1-9997-39a5c0e0cfca.png">

**Check out:**

When a customer wants to check out, he will be prompted to enter the number of the room he/she was occupying (In real life, this will correspond to returning the room key). If the number provided is correct, meaning that the room was indeed full, the customer will be able to check out. He will then receives a bill worth a specified amount (a generated .txt file)

<img width="467" alt="checkoutBill" src="https://user-images.githubusercontent.com/103124512/170777503-bf04f858-0e87-4023-af73-02b94b6d2b65.png">

N.B. It is important to point out that the program generates another file that stores the history of all transactions made. This file should normally not be communicated to customers.

<img width="356" alt="history" src="https://user-images.githubusercontent.com/103124512/170778045-44369f8f-4ca1-4f9d-bf0b-9a0fbf69239d.png">

**Hotel earning:**

This function returns all the revenues that the hotel has earned.

<img width="478" alt="hotelEarnings" src="https://user-images.githubusercontent.com/103124512/170778968-79936d4e-6556-4464-829a-6836390b7b9a.png">

Earnings are computed according to the room type and the number of nights spent at the hotel.

<img width="381" alt="Screenshot 2022-05-27 at 20 40 34" src="https://user-images.githubusercontent.com/103124512/170779160-bc9c518d-8958-497b-bc89-d9dadfc39ab2.png">

**Error Checking:**

This program checks all inputs provided by the user. If the inputs do not match what is expected, an error message is displayed and the user is prompted to re-enter a valid input (thanks to while loops)

*Example:*

<img width="788" alt="ErrorChecking" src="https://user-images.githubusercontent.com/103124512/170779667-c52372b0-2f0f-4ece-addc-2052dcfd5ebb.png">


