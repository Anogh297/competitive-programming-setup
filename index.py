from sys import stdin, stdout
from math import gcd, sqrt, ceil, floor, log, factorial, comb, perm
from heapq import heappush, heappop, heapify, nlargest, nsmallest
from itertools import combinations, permutations, product, accumulate
from functools import reduce, lru_cache  # memoization
from collections import deque, Counter, defaultdict as dd, OrderedDict
from bisect import bisect_left, bisect_right, insort  # For binary search and sorted insert
from operator import add, mul, itemgetter, attrgetter  # Functional-style operators
from random import randint, choice, shuffle

flush = lambda: stdout.flush()
readln = lambda: stdin.readline().strip("\n")
readint = lambda: int(stdin.readline())
print = lambda *args: stdout.write("".join(map(str, args)) + "\n")

mod = 1e9 + 7


# your code...
