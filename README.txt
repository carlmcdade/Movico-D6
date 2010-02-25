When procedural code fails in its implementation of OOP developers turn to helper modules. Helper modules are performance killers. They act as a pseudo form of a Class to subclass system but lack the functionality of OOP Abstracts, Interfaces etc. Polymorphism is only available while using active modules which leads to a performance hit with each module activated.

Caching is a fix for the burden of loading dozens of modules at runtime and the performance hit experienced under a heavy number of user requests per second. Drupals menu system contains access control and url routing making them subject to unwanted caching and the constant emptying of the menu cache. This hinders the development of on the fly access control and has other unwanted after effects.

The template system for the application layer for modules is dependent on the presentation layer of the entire website. This means that modules developed using template.php in a theme cannot be easily moved without taking template.php and possibly dozens of template files with them. The caching of theme templates hinders development while tools like devel module exist they tend to be crutches rather than solutions to the problem.

What is Movico?

What the Movico (MVC) module does is act as a connector and wrapper for an organized OOP application using the popular MVC design pattern. Six tersely coded functions let the web developer build software in Drupal using PHP object oriented features, recognizable design patterns and Classes for structure. Many of the problems encountered by using typical practices in Drupal module development are removed through the careful use of OOP structures and design. The organization, cataloging of functionality and documentation become easier. Placing as either a Model, View or Controller along with proper designation of code part as Classes, subclasses and methods makes for better code readability. Long term maintenance and upgrading to future version of Drupal are made easier with removal unneeded use of core functionality. One of the best things about building a module like this is that it becomes more of an autonomous or “third party” web application. This makes it quite simple to remove Drupals hooks from the application and move it to another environment or make it a self-reliable web app. This is why the Movico module will always only contain the bare minimum of code necessary to make the underlying application work. A developer will never feel as though it is too much trouble to yank the Movico module dump Drupal and go it alone.

Benefits:

▪ Speedy development using OOP and MVC letting developers use those same skills and knowledge in Drupal and cross to other PHP projects designed in OOP.
▪ Simplicity and organization of code using object oriented design.
▪ True dynamic access control without the need for menu cache refreshing.
▪ A faster more dynamic and autonomous template system for modules. Create templates and variables that are free of theme templates and template.php files. Removes the need to refresh the theme registry cache.
▪ More scalability without after effects.
▪ Easier to add third-party solutions that use OOP design.