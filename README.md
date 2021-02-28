# Cplusplus-Program
Repo for C++ SNHU


Summarize the project and what problem it was solving.

Program will allow a user to set up investment calculations based on input. WIll prompt for, an initial investment amount, a deposit amount, interest rate and the amount of years. A table will b e displayed showing yearly totals with a monthly deposit and one without a deposit. 


What did you do particularly well?

I believe that creating functions that serve a particular purpose was one of my goals while writting this program. Not every function happend  to be single purpose, the majority was, In that I believe I created portable code that will be able to be passed on. Ie creating a function that will clear the cin buffer. I found myself repeating the same 2 lines in multiple areas, that to me crys for a function.  


Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?

I could improve this code by adding more efficient data validation. Creating a more narrow range to avoid values to overflow thus creating 
junk data, and possibly memory leaks. 


Did you find writing any piece of this code challenging, and how did you overcome this? What tools and/or resources are you adding to your support network?

The main challange that I found with this code was the output formatting using iomanip. Attempting to get the output table to line up
specifiaclly with adding a '$' in front of the second and third column was a challange. I manageged to oversome with a bit of a workaround  - seperating the $ from the value instead of tying them together. It appears as it would in excel using the Accounting number format. So it seemed almost natural to have it that way anyways. Just not what I was intending to do. 


What skills from this project will be particularly transferable to other projects and/or course work?

THe intigration of using classes and objects will be a valuable tool for programming in the future. Functions are a large part of this as well. Being able to utilize funtions to create more readable code will also be a vital part of my sucess. 


How did you make this program maintainable, readable, and adaptable?

I kept remembering from my former taechings that a function should serve one purpose. For the most part I believe that I have achieved this. And in doing so I bellieve that I have created functions that can be reused for almost any project that requires it. For instance the Selection() function can be used for anything that would require a selection with data validation. It would require minimal rewrites be become portable. 
