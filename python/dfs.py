'''
An n-by-n matrix codes for the relationship
dynamics among n people. A value of 1 for 
element i,j in the matrix tells us that 
person i and person j are friends. Friendship
edges are bidirectional. Thus, element i,j in 
the matrix will match element j,i. A person is always friends with themself. This sll means the
friendship matrix is symmetrical.

Code for a solution that finds the friendship
circles given a friendship matri., For example,
[1,1,0
 1,1,0
 0,0,1]
the latter matrix tells us that the zeroth and first persons are friends with one another while the second person is by themself. Thus, the friendship circles would be {0,1} and {2}. 
'''

import numpy as np

class solution(object):
	def __init__(self,arr):
		self.arr = arr
		self.n  = arr.shape[0]
		
	def findfriends(self):
		def search(i):
			self.visit.add(i)
			self.curr_group.add(i)
			for j in range(self.n):
				if self.arr[i,j] == 1:
					self.arr[i,j] = 0
					if j not in self.visit:
						search(j)
		
		# keep track of visited friends
		self.visit = set()
		# keepmtrack of disparate circles 
		self.groups = []
		
		# loop through friends
		for i in range(self.n):
			# proceed to define new circle only if
			# that friend has not yet been visited
			# then begin DFS search from that friend
			if i not in self.visit:
				self.curr_group = set()
				search(i)
				self.groups.append(self.curr_group)

		print(self.groups)
			
a=np.array([[1,1,1,1],[1,1,0,0],[0,0,1,1],[1,0,1,1]])

b = np.array([[1,1,1,0,1,0],[1,1,0,1,0,0],[1,0,1,0,1,1],[0,1,0,1,0,0],[1,0,1,0,1,0],[0,0,1,0,0,1]])

c = np.array([[1,1,1,0,0,0],[1,1,0,0,0,0],[1,0,1,0,0,0],[0,0,0,1,1,0],[0,0,0,1,1,0],[0,0,0,0,0,1]])

print('Matrix:')
print(a)
print('Circles:')
sol_a = solution(a)
sol_a.findfriends()

print()

print('Matrix:')
print(b)
print('Circles:')
sol_b = solution(b)
sol_b.findfriends()

print()

print('Matrix:')
print(c)
print('Circles:')
sol_c = solution(c)
sol_c.findfriends()

