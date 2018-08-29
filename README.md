# Library-system-using-C
a Simple library system college project that I decided to spice things up in

Our project is a library system that stores for each book the title, the author, publisher , ISBN , date of publications , number of copies , current available number of copies and categories.
Also our project stores members’ first and last name , ID , address , phone number , age and e-mail.

It also stores the borrowing information like the date borrowed, date due to return and date returned.

It includes  six menus including : 
1-Book management.
2-member Management.
3-Borrow Management.
4-administrative actions.
5-print books , members or borrows.
6-save changes.
7-Exit
User manual
------------------
The program Starts with the Main menu:
Main Menu is divided into 7 menus which are
1-Book Management Menu
-------------------------------------
In which the user can access 3 options which are "Add book" in which the user can add a book to the system and "Search Books" in which the user can search for a book and "Add copy" in which a user can add a copy to an existing book.
The admin can access the "Delete Books" function by entering the Admin's Password and in this menu the admin can delete a book from the system.
2-Member Management Menu
-----------------------------------------

And the second menu is the Member management menu which contains 2 options one of them is for the user and the other is only accessible to the admin.
The add member option:The user can add a member to the system by entering his first and last names and his ID and Age and phone number and email address and Address
(put add member function)
The remove member function is a function only for the admin and he can Access it by entering the Admin's password and he enters the id of the user and confirms Delete and the member will be deleted from the system
3-Borrow Management Menu
-----------------------------------------
The third menu is is the Borrow Management menu which contains 2 options and both are accessible to the user
 
The first one is:borrow a book in which the books are all printed on the screen and the user enters his ID and the system checks if he borrowed 3 books if he did, then he can't borrow anymore books if he didn't, The user enters the wanted book's ISBN and now the system knows that he borrowed the book and the available number of books decreases by one

The second one is:Return a borrowed book in which the user enters the book's ISBN that he wants to return and the book is returned to the system


4-Adminstartive Actions Menu
----------------------------------------

The fourth menu is Adminstrative Actions which is only accessible by entering the Admin's password 

it contains 2 options
which are "over due books" and "most popular books"
in Overdue books, the system checks its files to find the books that were borrowed but didn't return on the required due date or before and prints them on the screen

the other option is, The most popular books in which the most 5 borrowed books are printed in descending order
5-Print  Menu
-----------------------------------

The fifth menu is Print Books,Members ,Borrows Menus which has 3 options which are accessible to the user.
the options prints all the saved books ,Members,Borrows respectivley due to it's option

6-Save Changes Menu
------------------------------
The sixth Menu is Save changes menu 
 which has 4 options, 3 of them is save books,members or borrows separately 
and the fourth one is save all which checks if there is any changes and if there is they will be saved

7-Exit Menu
------------------
the seventh menu is Exit Menu
which contains 2 options which are save and exit and Exit without saving 
the 1st option saves all the changes before exiting
and the 2nd option gives u a hint that u changed in whatever u changed in during your use of the program if you choose to discard all changes, the program places them in a temp file and when the program starts for the next time it will ask you if you want to save them, If not it will remove the temp files permanently 
