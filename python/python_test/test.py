import logging
import threading
import time
import sys
import unittest
from selenium import webdriver

class planet:
    def __init__(self):
        pass

x = 100

class Mars:
    #global x
#    x = 100

    name = 'good'
    
    def __init__(self, watch):
        #Mars.name = self.name
        #self.name = name
        #Mars.name = 'xfd'
        self.watch = watch
        pass

    @classmethod
    def getParam(cls, snail):
        #print(cls.name)
        return cls(snail + 'kk')


def main(argv):
    format = "%(asctime)s: %(message)s"
    logging.basicConfig(format = format, level = logging.DEBUG)

    mars1 = Mars('ccc')
    print(mars1.watch)

    mars2 = Mars.getParam('xxxxxxxxxx')
    print(mars2.watch)


if __name__ == "__main__":
    log = logging.getLogger("my-logger")
    main(sys.argv[1:])
    
    

# from datetime import date
 
# class Person:
#     def __init__(self, name, age):
#         self.name = name
#         self.age = age
 
#     # a class method to create a
#     # Person object by birth year.
#     @classmethod
#     def fromBirthYear(cls, name, year):
#         return cls(name, date.today().year - year)
 
#     # a static method to check if a
#     # Person is adult or not.
#     @staticmethod
#     def isAdult(age):
#         return age > 18
 
# person1 = Person('mayank', 21)
# person2 = Person.fromBirthYear('mayank', 1996)
 
# print(person1.age)
# print(person2.age)
 
# # print the result
# print(Person.isAdult(22))