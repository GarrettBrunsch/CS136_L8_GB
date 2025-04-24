
**4/24/2025**
*  **feedback.md is for instructor use only. DO NOT change the feedback.md**; make a copy if needed
* class definition style & standards:  first, member vars  none per line and do not forget to initialize them;  second functions: separate group of functions  by a blank line; either matching setter/getter pairs or list all setters back to back and list all getters back to back; start with a default c’tor, followed by  copy c’tor (if any), then other c’tors in the order of increased number of arguments, d’tor- right after c’tor(s), overloaded functions- list them back to back in the order of increased number of arguments;  all accessor/getter functions should be const; all functions with more than one statement should be normal (defined externally, outside of the class and below main()), no inline functions with more than one statement; initialize all member variables to appropriate default values at the time of definition; all member variables must be private; classes must provide a strong exception guarantee; must have default c’tor; implement Rule of Three when necessary
*  73 why rethrow; who is catching it? -2
* 85-89 What are you swapping? -2
* no main -20
* no test runs -10
* excessive use of printf/cout/cin/ file stream/stringstream and/or endl and/or << >>; applies to all output, not just menu-5
  * << not needed between strings
  * Should print a couple of blank lines before the menu to separate from the lines of text above it
  * no need for the “.” at the end of menu options; it is just clutter but no useful info to a user* no need for the “.” at the end of menu options; it is just clutter but no useful info to a user
  * input>>name>>id>gpal;
```text
//e.g.
cout << "\n\nMenu:\n”
“1. Encrypt\n”
“2. Decrypt\n”
“3. Quit\n"<<endl;
```
* remove #include \<utility\> -5
* 103 &  112 redundant, create a function and call in c’tors -5
* #107, 108, and like –  might terminate the c’tor prematurely if an exception is thrown=>an object will not be created=> you might have a name/var id for an object but not the object; still need to create the object even if it is in a default state? -5
* Rule of Three implementation
  * copy constructor:  -5
    * a new object ("destination" object) is being created by copying another object ("right" object, source object) of the same class
    * what would you do I f the copy process was not successful? keep in mind that if you terminate the c'tor function, the destination object will not be created; should you create an empty object instead? what would you do with already allocated memory?
  * copy assignment operator -5
    * the "left" object already exists and might have already allocated nodes
    * should you delete all nodes in your left object first and then copy nodes from the "right"  object? if yes, what happens if the copy process is not successful (could not copy all nodes)? If you delete all nodes in your left object before confirming that the copy process succeeded, you lost the original nodes in the left object and did not copy all nodes from the right object. Would you rather have your left object intact than have a bad copy of a right object?
  * destructor
    * do not forget to clean up dynamically allocated memory (DMA);  a function that deallocates all DMA is quite helpful- iyt can be called  in D’tor and other places such as catch(bad_alloc)
    * if you use delete on something that was not dynamically allocated, a compiler might throw an exception; check first, then use delete
* may resubmit no later than 05/04/25

