* Single responsibility principle 
	
	In Itau, in the engine, we implemented a component just to read the file and we could implement more efficiently without changing anything about the parser itself. More specifically we benefit from the fact that the parser was deployed into 2 types of servers, with different ram configs
	
* Open closed
	
	In Itau, the engine for parsing implemented a mechanism for extension that allowed to treat specific business rules. With this we never had the need to change the parser to accomodate new types of assets

* Liskov-substitution
	
	Here at PagSeguro, we develop machine learning models and deploy them using Python. Our base abstract python classes handles the ingestion of data and the calling for the prediction, for a plain vanilla model which does not need any special treatment on the data. 

* Interface segregation
	
	In Itau, in the engine, we separated each responsibility in interfaces, business owners had very diverse needs. For modelling, the need the assets parsed and ready for consumption, but they dont need to change values; people doing pricing need to parse and test different values for specific characteristics on a given asset; devops make load tests regularly so they just need to read the files. So each team could use their set of interfaces and use just what they need

* Dependency inversion
	
	In Globant, we build an e-commerce site that allows you to customize an ERP, choosing modules (HR, sales, taxes, inventory). The hard part of the customization is that an ERP has a central module which in essence manages all others.
	We decoupled this central module into an abstract class and then you could customize the specific modules.
	
* Memory management in c++
	
	static - the stack, allocation made in compilation time, tied to data types
	
	dynamic - the heap, allocation made in run time. pointer has 4 bytes

* Testing - equivalence partitioning, boundary-value analysis, likelihood X impact

* Metrics (sonarQube) - depth of inheritance, cyclomatic complexity