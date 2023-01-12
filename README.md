# CHouse
A project by Greenie

## To-do list
### High-priority
* Validate input data from all methods in Member class
* Table generator for view all unreview request,


### Mid-priority

* Add cancel request to CLI
* Add view member detail to CLI
* snake case -> camel case

## Should-do list
* allow member to review anytime
* Remove cin, cout in member
* Explain how data file is organized in report
* Add delete pointers where possible
* Automatically unlist house if date has been expired 


## Accepted bugs - constraints
* Date can't subtract 2 dates from different years
* Member can accept request that aren't matched with the future list date
* checkout can only work if user only have one approve request
* Can't check double before parsing
* string to date can cause throw stoi error 
* Can't catch date constructor cerr


## Small notes
* Member will have 500 credit point when first register
* City can only be Ha Noi, Hue, Sai Gon
* Member can only occupy one house at a time
* Member can't cancel request once has been approved
