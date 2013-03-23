import sys

class GridMDP:
	""" 
	A two dimension MDP.
	"""
	def __init__(self, dim = 3, init_state = (0, 2), \
				 actions = [1, -1, 0], delta = .9, alpha = .8):
		self.init_state = init_state
		self.crt_state = init_state
		self.dim = dim
		self.delta = delta
		self.alpha = alpha
		self.actions = actions
		self.reward = {}
		self.quality = {}
		self.states = set()
		
		# Initialize states and rewards
		for x in range(self.dim):
			for y in range(self.dim):
				self.reward[x, y] = 0.0
				self.states.add((x, y))
		
		# Initialize Q
		for state in self.states:
			self.quality[state] = {}
			for action in self.actions:
				if action == 0 and state[0] == state[1]:
					self.quality[state][action] = 0.5
				else:
					self.quality[state][action] = 0.0
	
	def R(self, state):
		""" 
		Return a numeric reward for this state 
		"""
		return self.reward[state]
		
	def apply_state(self, action):
		"""
		Performa an action to a given state
		"""
		d_pos = self.crt_state[0]
		a_pos = self.crt_state[1]
		
		# Defender moves
		if action in [1, -1]:
			d_pos += action
		# Defender wins
		elif action == 0 and a_pos == d_pos:
			return ((a_pos, a_pos), 2)
		
		# Attacker moves
		if d_pos < a_pos:
			a_pos -= 1
		elif d_pos > a_pos:
			a_pos += 1
		# Attacker wins
		elif d_pos == a_pos:
			return ((a_pos, a_pos), 1)
		
		return ((d_pos, a_pos), 0)
		
	def get_actions(self, state):
		""" 
		Return all possible actions given the current action 
		"""
		d_pos = state[0]
		if d_pos == 0:
			return [1, 0]
		
		if d_pos == self.dim - 1:
			return [-1, 0]
		
		return [1, -1, 0]
	
	def draw_grid(self, win = 0):
		"""
		Draw the grid based on current state
		"""
		d_pos = self.crt_state[0]
		a_pos = self.crt_state[1]
		s = ''
		for i in range(self.dim):
			if a_pos == i:
				s += 'A'
			else:
				s += '-'
		print s
		
		n = self.dim * 2 - 2
		for i in range(n):
			s = ''
			for j in range(self.dim):
				if j == a_pos and win == 2 and i == 0:
					s += '*'
				elif j == a_pos and win == 1 and i == n - 1:
					s += '*'
				elif j == a_pos and win:
				
					s += '|'
				else:
					s += '='
			print s
		
		s = ''
		for i in range(self.dim):
			if d_pos == i:
				s += 'd'
			else:
				s += '-'
		print s
		
	def new_quality(self, state, action, new_state, R):
		"""
		Compute the new quality based on current state
		and action
		"""
		possible_actions = self.get_actions(new_state)
		
		self.quality[state][action] = (1 - self.alpha) * \
									   self.quality[state][action] + \
									   self.alpha * \
									   (R + self.delta * \
									   max([self.quality[new_state][a] for a in possible_actions]))
		print "state=", state, "action=", action, "quality=", self.quality[state][action]
	
	def choose_best(self):
		possible_actions = self.get_actions(self.crt_state)
		
		maxq = float("-inf")
		best_action = None
		for a in possible_actions:
			if maxq < self.quality[self.crt_state][a]:
				maxq = self.quality[self.crt_state][a]
				best_action = a
		
		return best_action
	

def play(agent):
	while True:
		new_action = agent.choose_best()
		new_state, win = agent.apply_state(new_action)
		#print agent.quality
		
		if win == 2:
			agent.reward[new_state] = 100
		elif win == 1:
			agent.reward[new_state] = -100
		else:
			agent.reward[new_state] = -10
		
		agent.new_quality(agent.crt_state, new_action, new_state, agent.reward[new_state])
		
		print agent.crt_state, new_action, new_state
		
		if win == 2:
			print "Defender wins :)"
			agent.crt_state = new_state
		elif win == 1:
			print "Attacker wins :("
			agent.crt_state = new_state
		else:
			agent.crt_state = new_state
		
		agent.draw_grid(win)
		
		if win:
			agent.crt_state = agent.init_state
			print "\n"
			print "+----------------+"
			print "|NEW GAME STARTED|"
			print "+----------------+"
			agent.draw_grid(0)
		
		print "Press any key to continue or Q to quit"
		key = raw_input()
		if key in ['q', 'Q']:
			exit(0)
					
if __name__ == "__main__":
	grid_dimension = int(sys.argv[1])
	agent = GridMDP(dim = grid_dimension, init_state = (0,grid_dimension - 1))
	agent.draw_grid(0)
	play(agent)
