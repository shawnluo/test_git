from collections import deque

movies = ["a", "b", 1, [2, 3, ['c', 'd']]]
""" print(movies[1])
print(movies[2])
print(movies[3]) """

def print_lol(movies):
    for it in movies:
        if isinstance(it, list):
            print()
            print_lol(it)
        else:
            print(it, end = " ")
       
print_lol(movies)