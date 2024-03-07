# -*- coding: utf-8 -*-

#       Author @  Huoty
#  Create date @  2015-12-19 09:39:36

import sys
import pprint
from functools import reduce
import os
import random

from collections import deque
from transformers import pipeline

classifier = pipeline("sentiment-analysis")
res = classifier("Today is a nice day!");
print(res)


# prompt: Breadth First Search python code
graph = {
    '5' : ['3', '7'],
    '3' : ['2', '4'],
    '7' : ['8'],
    '2' : [],
    '4' : ['8'],
    '8' : []
}

visited = []
queue = []

def bfs(visited, graph, node) :
  visited.append(node);
  queue.append(node)

  while queue:
    m = queue.pop(0)
    print(m, end = " ")

    for neighbour in graph[m]:
      if neighbour not in visited:
        visited.append(neighbour)
        queue.append(neighbour)

bfs(visited, graph, '5')