"""Short Detail of all the typr of inheritance
1)Single Inheritance     --> Single base class and derived class
2)Muliple Inheritance    --> Single Child class and more than one parent class
3)MultiLevel Inheritance --> Level by level inheritance Parent->Child->Next Child(Like GrandFrather->Father->Son)
4)Hybird Inheritance     --> Contain Mutiple and Single Inheritance
5)Hierarical Inheritance -->Single base class and Multiple derived class
In which is a simple exmaple of all type inheritence"""


"""class Empolyee:
    def __init__(self,name,id):
        # self.__name = name  # -->(__) 👉 --> Making varaible Private 
        # self.__id = id
        self._name = name     # -->(_)  👉 --> Making Varaiable Prptected
        self._id = id
        
    def DetailShow(self):
        print(f"The name of employee {self.__id} is {self.__name} ")

#--------------------------INHERITANCE-----------------------------
#class Derived (Base) 👉 -->Syntax of inheritance
class Programmer(Empolyee):
    def ShowLanguage(self):
       print("Default Language is Python")
       self._name = "Abdullah"
       print(self._name)

e1 = Empolyee("Ali", 12)
# e1.DetailShow()
e2 = Programmer("Ahmed", 13)
# print(e1._Empolyee__name) # 👉 -->Access The Private Varaible
# print(e1._Empolyee__id)   # 👉 -->Access The Private Varaible
print(e1._id)   # 👉 -->Access The Protected Varaible
print(e1._name) # 👉 -->Access The Protected Varaible
print(e2._name) # 👉 -->Access The Protected Varaible
# e2.DetailShow()
e2.ShowLanguage()"""
#--------------------------SINGLE INHERITANCE-----------------------------
#Single Inheritance in which one based and one derived class
"""class Animal:
    def __init__(self,name):
        self.name = name
    def make_sound(self):
        print("Make Sound")

class Dog(Animal):

    def __init__(self, name):
        self.name = name
    def make_sound(self):
        print("Barks")

class Cat(Animal):
    def __init__(self, name):
        self.name =name

    def make_sound(self):
        print("Meow")


#---------------------------MAIN----------------------------
dog = Dog("Dog")
print(dog.name)
dog.make_sound()

cat = Cat("Cat")
print(cat.name)
cat.make_sound()"""

#------------------------MULTIPLE INHERTITANCE------------------
# Multiple inheritance is a powerful feature in object-oriented programming
#  that allows a class to inherit attributes and methods from multiple parent classes
#in which single child class inherit by more than one parent class
"""
class Employee:
    def __init__(self,name,id):
        self.name = name
        self.id = id

    def show(self):
        print(f"Name is {self.name} and id is {self.id}")

class Allowance:
    def __init__(self,allowanceName):
        self.allowanceName = allowanceName

    def show(self):
        print(f"Allowance Name is {self.allowanceName}")

class AllowanceEmployee(Allowance,Employee): #-->First class method is call all the time
    def __init__(self,allowanceName, name, id):
        Employee.__init__(self, id, name)
        Allowance.__init__(self, allowanceName)
    def show(self):
        Employee.show(self)
        Allowance.show(self)    
AE = AllowanceEmployee("House", "Aqeel", 1)
AE.show()
"""

#------------------------MULTILEVEL INHERTITANCE------------------
# Multilevel inheritance is a type of inheritance in object-oriented programming
#  where a derived class inherits from another derived class.
#   This type of inheritance allows you to build a hierarchy of classes
#    where one class builds upon another,
#  leading to a more specialized class.
"""
class Person:
    def __init__(self,name,age):
        self.name = name
        self.age = age

    def Show_Detail(self):
        print(f"Name is: {self.name}\nAge is:{self.age}")

class Employee(Person):
    def __init__(self, name, age,id):
        Person.__init__(self, name, age)
        self.id = id
    def Show_Detail(self):
        Person.Show_Detail(self)
        print(f"Id is: {self.id}")

class Faculty(Employee):
    def __init__(self, name, age, id,allowance):
        Employee.__init__(self, name, age, id)
        self.allowance = allowance
    def Show_Detail(self):
        Employee.Show_Detail(self)
        print(f"Allowance is:{self.allowance}")

F1 = Faculty("Ali", 23, 1, 12000)
F1.Show_Detail()

F2 = Faculty("Amna", 24, 2, 15000)  
F2.Show_Detail() """

#------------------------HYBIRD INHERTITANCE------------------
# Hybrid inheritance is a combination of multiple inheritance and single inheritance in object-oriented programming.
# It is a type of inheritance in which
#multiple inheritance is used to inherit the properties of multiple base classes into a single derived class, 
# and single inheritance is used to inherit the properties of the derived class into a sub-derived class.
"""class Vechicle:
    def __init__(self,type):
        self.type = type
    def detail(self):
        print(f"Type of object->{self.type}")

class Car(Vechicle):
    def __init__(self, type,name):
        Vechicle.__init__(self, type)
        self.name = name
    def detail(self):
        Vechicle.detail(self)
        print(f"Name of object->{self.name}")   
class Toyota(Car):
    def __init__(self, type, name,car):
        Car.__init__(self, type, name)
        self.car = car
    def detail(self):
        Car.detail(self)
        print(f"Company of car->{self.car}")
class Honda(Car):
    def __init__(self, type, name,car):
        Car.__init__(self, type, name) 
        self.car = car
    def detail(self):
        Car.detail(self)
        print(f"Company of car->{self.car}")

H1 = Honda("Vehicle","Car","Honda")
H1.detail()  
print("\n\n")
T1 = Toyota("Vehicle","Car","Toyota")
T1.detail()"""


#------------------------HIERARCHICAL INHERTITANCE------------------
# Hierarchical Inheritance is a type of inheritance in Object-Oriented Programming where multiple subclasses
# inherit from a single base class. In other words, a single base class acts as a parent class for multiple subclasses.
# This is a way of establishing relationships between classes in a hierarchical manner.
"""
class Employee:
    def __init__(self,id, name):
        self.id = id
        self.name = name
    def ShowInfo(self):
        print(f"Employee id is {self.id} and name is {self.name}")
class Faculty(Employee):
    def __init__(self, id, name,allownace):
        Employee.__init__(self, id, name)
        self.allowance = allownace
    def ShowInfo(self):
        Employee.ShowInfo(self)
        print(f"Allowance is {self.allowance}")
class Staff(Employee):
    def __init__(self, id, name,task):
        Employee.__init__(self, id, name)
        self.task = task
    def ShowInfo(self):
        Employee.ShowInfo(self)
        print(f"Task is {self.task}")                       

F1 = Faculty(1, "Aqeel", 25000)
F1.ShowInfo()
print("\n\n")
S1 = Staff(2,"Ali","Cleaning")
S1.ShowInfo()"""