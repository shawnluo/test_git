# -*- coding: utf-8 -*-

#       Author @  Huoty
#  Create date @  2015-12-19 09:39:36

import pprint


class Person():
    person = 'alive' #这是类变量
    a = 300
    def __init__(self,name=1 ,age=2):
        self.name = name #这是实例变量
        self.age = age   #这是实例变量
        self.gender = '男' #这是实例变量
        Person.a = 456     #不能写这里，会出错
        self.person = 'good'
        self.__class__.b = 'hello'
        self.__class__.person = 'bad'
        
    @classmethod
    def run(cls):
        print('gooday')
        return cls.person
 
        
p1 = Person('wa', 18)

# print(p1.b)

# print(p1.a)

# print(Person.a)

# print(Person.b)

#print(p1.person)
print(Person.person)
print(Person.a)
print(Person().run())
