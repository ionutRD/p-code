import sys

class GridMDP:
	""" 
	A two dimension MDP.
	"""
	def __init__(self, grid, init_state = (0, 0), delta = .9):
		self.init_state = (0, 0)
		self.delta = delta
		self.actions_list = [(0,1),(0,-1),(1,0),(-1,0)]
		self.final_states = []
		self.grid = grid
		self.rows = len(grid)
		self.cols = len(grid[0])
		self.reward = {}
		self.states = set()
		for x in range(self.rows):
			for y in range(self.cols):
				self.reward[x, y] = grid[x][y]
				self.states.add((x, y))
	
	def R(self, state):
		""" 
		Return a numeric reward for this state 
		"""
		return self.reward[state]
	
	def T(self, state, action):
		""" 
		From a state and an action, 
		return a list of pairs <probability, action>
		"""
		i, j = state
		if action == (-1, 0):
			if j == 0:
				return [(0.9, (i - 1, j)), (0.1, state)]
			else:
				return [(0.9, (i - 1, j)), (0.1, (i, j - 1))]
		elif action == (1, 0):
			if j == 0:
				return [(0.6, (i + 1, j)), (0.2, state), (0.2, (i, j + 1))]
			elif j == self.cols - 1:
				return [(0.6, (i + 1, j)), (0.2, (i, j - 1)), (0.2, state)]
			else:
				return [(0.6, (i + 1, j)), (0.2, (i, j - 1)), (0.2, (i, j + 1))]
		elif action == (0, 1):
			return [(1, (i, j + 1))]
		elif action == (0, -1):
			if i == self.rows - 1:
				return [(0.8, (i, j - 1)), (0.2, state)]
			else:
				return [(0.8, (i, j - 1)), (0.2, (i + 1, j))]
	
	def apply_state(self, state, action):
		"""
		Performa an action to a given state
		"""
		return (state[0] + action[0], state[1] + action[1])
		
	def actions(self, state):
		""" 
		Return all possible actions given the current action 
		"""
		if state in self.final_states:
			return [None]
		
		actions = []
		if 0 < state[0]:
			actions.append((-1, 0))
		
		if 0 < state[1]:
			actions.append((0, -1))
		
		if state[0] < self.rows - 1:
			actions.append((1, 0))
		
		if state[1] < self.cols - 1:
			actions.append((0, 1))
		
		return actions
	

def value_iteration(mdp, eps = 0.001):
	""" 
	Solving MDP by iteration 
	"""
	U1 = dict([(s, 0) for s in mdp.states])
	R, T, delta = mdp.R, mdp.T, mdp.delta
	while True:
		U = U1.copy()
		gamma = 0
		for s in mdp.states:
			U1[s] = R(s) + delta * max([sum([p * U[s1] \
					for (p, s1) in T(s, a)]) for a in mdp.actions(s)])
			gamma = max(gamma, abs(U1[s] - U[s]))
		
		if gamma < eps:
			return U

def argmax(seq, fn):
	"""
	Return the maximum element from a list 
	after applying fn for each element 
	"""
	best = seq[0]
	best_score = fn(best)
	for x in seq:
		x_score = fn(x)
		if  x_score > best_score:
			best, best_score = x, x_score
	return best
			
def best_policy(mdp, U):
	"""
	Determine mdp best policy 
	"""
	
	pi = {}
	for s in mdp.states:
		pi[s] = argmax(mdp.actions(s), \
					   lambda a : utility(a, s, U, mdp))
	return pi

def utility(a, s, U, mdp):
	""" 
	Determine the expected utility in a state 
	given an action and a utility
	"""
	
	return sum([p * U[s1] for (p, s1) in mdp.T(s, a)])
	
def read_grid(file_name):
	"""
	Read the grid from the input file
	"""
	
	try:
		fhandle = open(file_name, "r")
		grid = []
		for f in fhandle:
			line = map(float, f.split())
			grid.append(line)
		return grid
	except IOError, e:
		sys.stderr.write("An IO Error occurred while \
						 trying to read from {0}".format(file_name))

if __name__ == "__main__":
	grid = read_grid(sys.argv[1])
	rows = len(grid)
	cols = len(grid[0])
	mdp = GridMDP(grid)
	U = value_iteration(mdp)
	pi = best_policy(mdp, U)
	print "---------------------"
	print "		UTILITY			"
	print "---------------------"	
	for value, key in U.items():
		print value, ":", key
	print "---------------------"
	print "		BEST POLICY     "
	print "---------------------"
	pair_pi = pi.items()
	pair_pi.sort()
	for value, key in pair_pi:
		print value, ":", key