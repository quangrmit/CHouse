# CHouse
A project by Greenie

## To-do list
### High-priority
* Validate input data from all methods in Member class
* Validate input data from all methods in Authorization class
* Add credit points to house owner and minus credit points from occupier when check out
* Filter out houses search result if occupier not have enough credit points, or min occupier rating is larger than occupier rating
* Add method to Member to allow member to view specific member detail if exist in request (unclosed request)


### Mid-priority

* Add cancel request method to member
* Add seperate view house reviews method to Member
* snake case -> camel case

## Should-do list
* member is confirmed to be automatically occupy a house (should have a method to start occupy a house)
* allow member to review anytime
* Remove cin, cout in member
* Allow username and password to have space
* Explain how data file is organized in report
* Add delete pointers where possible
* Automatically unlist house if date has been expired 
* Allow admin to search house, member
* Allow guest to search house
* Proof-reading report

## Known bugs
* Table generator not working
* When creating new members, house ID can't be known

## Small notes
* Member will have 500 credit point when first register
* City can only be Ha Noi, Hue, Sai Gon
* Member can only occupy one house at a time
* Member can't cancel request once has been approved
