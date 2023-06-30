# import multiprocessing
# import random
# from functools import reduce


# def func(number):
#     random_list = random.sample(range(1000000), number)
#     return reduce(lambda x, y: x*y, random_list)

    
# number = 50000
# process1 = multiprocessing.Process(target=func, args=(number,))
# process2 = multiprocessing.Process(target=func, args=(number,))

# process1.start()
# process2.start()

# process1.join()
# process2.join()



# python code to demonstrate working of reduce()
 
# importing functools for reduce()
import functools
 
# initializing list
lis = [1, 3, 5, 6, 2]
 
# using reduce to compute sum of list
print("The sum of the list elements is : ", end="")
print(functools.reduce(lambda a, b: a+b, lis))
 
# using reduce to compute maximum element from list
print("The maximum element of the list is : ", end="")
print(functools.reduce(lambda a, b: a if a > b else b, lis))