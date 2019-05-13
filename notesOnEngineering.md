* SOLID
    * for examples, see [Notes in the interview](./notesOnInterviewMs20190219.md)
    * Single responsibility: every class must have just one reason to change
    * Open-Closed: open for extension, closed for modifications 
    * Liskov substitution: a class should be replaceable by its parent
    * Interface segregation: use only what you need
    * Dependency inversion: rely on abstractions

* Design patterns
    * creational
        * factory: Creates an instance of several derived classes
            * **why use**: encapsulate creation of complex objects
            * used in Qualicorp,  we have specfic business rules when instantiating medical entities 
        * singleton: A class of which only a single instance can exist
            * **why use**: objects using shared resource and multiple parts will acess simultaneously
            * used in Itaú, we have to make sure only one instance of engine was being used when importing rules
        * prototype: A fully initialized instance to be copied or cloned
            * **why use**: convenience for creating objects, mainly when they are created dinamically at runtime
            * never used
    * structural 
        * adapter: Match interfaces of different classes
            * **why use**: allow incompatible objects to work together by converting the interface of one of the classes to the interface of the other
            * used in PagSeguro, when building models. They have different parameterization
        * decorator: Add responsibilities to objects dynamically
            * **why use**: when you have different behaviours to be chosen at runtime and/or an object has many behaviors. Decorator reduce number of different types of object that need to be created
            * used in Itaú to categorize investment funds. How interests are paid, if you need to comply to specific regulation rules (there were several, e.g., irs specific), how fees are charged
        * facade: A single class that represents an entire subsystem
            * **why use**: to abstract a complex system
            * used in Itaú to interact with compliance systems
        * bridge: Separates an object’s interface from its implementation
            * **why use**: to let abstraction and implementation vary independently
            * never used
    * behavioral
        * chain of responsability: A way of passing a request between a chain of objects
            * **why use**: when orchestration is needed and you have actions that spam thru objects
            * used in Itaú doing reports to Central Bank for investment funds. Each item of the chain appended a chunk of info
        * command: Encapsulate a command request as an object
        * observer: A way of notifying change to a number of classes
        * visitor: Defines a new operation to a class without change
        * strategy: Encapsulates an algorithm inside a class
            * **why use**: when actions are byproduct of a decision
            * used in PagSeguro when generating maps based in data gathered at payment devices. depending on the amount of data for a given transaction, an algorithm is chosen
        * template: Defer the exact steps of an algorithm to a subclass
        * state: Alter an object's behavior when its state changes

* Demeter principle: theory of least information. Only relate to your closest unit; dont relate to strangers; just talk to your immediate friends

* Data Structures
    * Arrays
    * Queue: FIFO
    * Stack: LIFO
    * Linked List
    * Heap: every node is less or equal than the parent
    * Trees
        * Binary Trees
        * Binary Search Trees
            * Example
                F 
            D           J
         B    E       G     K
       A   C             I
                      H  
            * Traversal
                * Breadth-first: go on each level. It will print _F D J B E G K A C I H_
                * Depth-first
                    *PreOrder:read root-left-right. It will print _F D B A C E J G I H K_
                    *InOrder:read left-root-right. It will print _A B C D E F G H I J K_
                    *PostOrder:read left-right-root. It will print _A C B E D H I G K J F_ 
* Sorting
    *Heap sort: average O(nLog(n)), worst O(nLog(n)), best O(n)
    * Quick sort: average O(nLog(n)), worst O(n^2)
        * Find a pivot
        * Partition so all itens less than the pivot are before it and all itens greater are after
        * Apply quick sort to each partition
    * Merge Sort: O(nLog(n))
        * Divide evenly until have 1 item on each side
        * Order the last tree
        * Merge the itens
        * Recurse
    * Bubble Sort: pick the first one and then iterate thru the end, "bubbling" the biggest to the end of the array; then go again, iterating from the first to the n-1th; then again from the first to the n-2th. Always bubbling the biggest to the end.
        average O(n^2), worst O(n^2), best O(n)
    * Insertion sort: pick the second one, compare with all others before until you find one greater or it is the first one; then goes to next, until final element. The insertion sort goes forward in the array and compare to all before it.
        average O(n^2), worst O(n^2), best O(n)
    * Selection Sort: pick the first element, find the smallest from 0 to end and put in position 0; then, pick the second element, find the smallest from 1 to end and put in position 1; go over until the end.
        average O(n^2), worst O(n^2), best O(n^2)