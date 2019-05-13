## TDD

* it is a discipline to help grow a quality design. In Unit testing, you test proper behavior of a unit of test. A unit is the smallest testable piece of an application (or a unit is a small piece of isolated logic that affects some systematic behavior)
	
## 3 rules of TDD
1. Write production code only to pass a failing unit test.
2. Write no more of a unit test than sufficient to fail (compilation failures are failures).
3. Write no more production code than necessary to pass the one failing unit test.
	
## Terminology for doubles
* Test double: An element that emulates a production element for testing purposes
* Stub: A test double that returns hard-coded values
* Spy: A test double that captures information sent to it for later verification
* Mock: A test double that self-verifies based on expectations sent to it
* Fake: A test double that provides a light-weight implementation of a production class	

## Schools of mock
* London school: focus TDD as a design exploration tool. Emphasis on object interactions, _Tell-Don't-Ask_, you ask an object to do something. You se a lot of mockery
* Classic (Cleveland school): Verify behavior by inspecting state. Use much less mocks, only use when a dependency concern forces it.
	
## TDD and acceptance testing
* difference is who writes code. TDD is written by programmers and acceptance is written by customers

## Transformation priority premise
* proposes a priority list of transformations. Each transformation represents an alteration of code from specific to slightly more generic. Using the TPP, you choose a test that drives the highest-priority transformation against your existing code.
* the list of transformations
	* ({}→nil) Replace no code with code that employs nil.
	* (nil→constant) Replace nil with a constant. 
	* (constant→constant+) Replace a simple constant with a more complex  constant
	* (constant→scalar) Replace a constant with a variable or argument.
	* (statement→statements) Add unconditional statements.
	* (unconditional→if) Split the execution path.
	* (scalar→array) Replace a variable/argument with an array.
	* (array→container) Replace an array with a more complex container.
	* (statement→recursion) Replace a statement with a recursive call.
	* (if→while) Replace a conditional with a loop.
	* (expression→function) Replace an expression with a function.
	* (variable→assignment) Replace the value of a variable.

## Quality tests
* FIRST breaks down into the following:
	* F for Fast
	* I for Isolated
	* R for Repeatable
	* S for Self-verifying
	* T for Timely
* One assert per test
* Test abstraction (“amplification of the essential and elimination of the irrelevant.” Martin, R. )

##Mikado
* Set a naive goal and implement
* Compile
* Inspect errors
* Ditch your solution
* Propose corrections
* Set new goal based on corrections an implement
* Back to compilation, repeat until you're satisfied