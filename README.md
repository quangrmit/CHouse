# CHouse
A project by Greenie

## To-do list
### High-priority
* Validate input data from all methods in Member class
* Validate input data from all methods in Authorization class
* Check all method against assessment requirments
* Write report
* Add credit points to house owner and minus credit points from occupier when check out
* Fix Table generator
* Filter out houses search result if occupier not have enough credit points, or min occupier rating is larger than occupier rating
* Add method to Member to allow member to view specific member detail if exist in request


### Mid-priority

* Allow admin to search house, member
* Allow guest to search house
* Add cancel request method to member
* Add seperate view reviews method to Member

## Should-do list
* Allow username and password to have space
* Explain how data file is organized in report
* Proof-reading report
* Add delete pointers where possible
* Automatically unlist house if date has been expired 

## Known bugs
* Member, House constructor not works when there are no reviews
* Join() from utils not work when there are no reivews
* When creating new members, house ID can't be known

## Small notes
* Member will have 500 credit point when first register
* City can only be Ha Noi, Hue, Sai Gon
* Member can only occupy one house at a time
* Member can't cancel request once has been approved
