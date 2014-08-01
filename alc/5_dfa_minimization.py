# 
# File:   dfa_min.py
# Author: viren
#
# Created on October 6, 2012, 10:13 AM
#

class DFA:
	def __init__(self, states, alphabet, delta, start, accepts):
		self.states = states
		self.start = start
		self.delta = delta
		self.accepts = accepts
		self.alphabet = alphabet
		self.current_state = start

	def print_tab(self):
		print "This DFA has %s states" % len(self.states)
		print "States:", (self.states)
		print "Alphabet:", self.alphabet
		print "Starting state:", self.start
		print "Accepting states:", self.accepts
		print "Transition function:"
		print "\tq", "\tq".join(map(str,self.states))
		for c in self.alphabet:
			results = map(lambda x: self.delta(x, c), self.states)
			print c, "\tq", "\tq".join(map(str, results))
	
	def s_hash(self, value):
		hash = {}
		for state in self.states:
			if value == {}:
				hash[state] = {}
			elif value == []:
				hash[state] = []
			else:
				hash[state] = value
		return hash	
		
	def reachable_from(self, q0, inclusive=True):
		reached = self.s_hash(False)
		if inclusive:
			reached[q0] = True
		to_process = [q0]
		while len(to_process):
			q = to_process.pop()
			for c in self.alphabet:
				next = self.delta(q, c)
				if reached[next] == False:
					reached[next] = True
					to_process.append(next)
		return filter(lambda q: reached[q], self.states)
	
	def is_reachable(self):
		return self.reachable_from(self.start)
	
	def delete_unreachable(self):
		reachable = self.is_reachable()
		self.states = reachable
		new_accepts = []
		for q in self.accepts:
			if q in self.states:
				new_accepts.append(q)
		self.accepts = new_accepts
	
	def mh_classes(self):
		# this function returns a partitions of states as myhill-nerode equivalence classes
		# the algorithm for minimization used in this program is among the simpler ones for dfa minimization
		# one disadvantage is that the ordering of states get mixed up
		changed = True
		classes = []
		if self.accepts != []:
			classes.append(self.accepts)
		nonaccepts = filter(lambda x: x not in self.accepts, self.states)
		if nonaccepts != []:
			classes.append(nonaccepts)
		while changed:
			changed = False
			for cl in classes:
				local_change = False
				for alpha in self.alphabet:
					next_class = None
					new_class = []
					for state in cl:
						next = self.delta(state, alpha)
						if next_class == None:
							for c in classes:
								if next in c:
									next_class = c
						elif next not in next_class:
							new_class.append(state)
							changed = True
							local_change = True
					if local_change == True:
						old_class = []
						for c in cl:
							if c not in new_class:
								old_class.append(c)
						classes.remove(cl)
						classes.append(old_class)
						classes.append(new_class)
						break
		return classes
	
	def collapse(self, partition):
		new_states = []
		new_start = None
		new_delta = None
		new_accepts = []
		new_current_state = None
		state_map = {}
		for state_class in partition:
			representative = state_class[0]
			new_states.append(representative)
			for state in state_class:
				state_map[state] = representative
				if state == self.start:
					new_start = representative
				if state == self.current_state:
					new_current_state = representative
		for acc in self.accepts:
			if acc in new_states:
				new_accepts.append(acc)
		transitions = {}
		for state in new_states:
			transitions[state] = {}
			for alpha in self.alphabet:
				transitions[state][alpha] = state_map[self.delta(state, alpha)]
		new_delta = (lambda s, a: transitions[s][a])
		self.states = new_states
		self.start = new_start
		self.delta = new_delta
		self.accepts = new_accepts
		self.current_state = new_current_state
		return state_map
	
	def minimize(self):
		self.delete_unreachable()			# remove states that are unreachable from the start state
		classes = self.mh_classes()			# get a set of equivalent states (m h classes)
		self.collapse(classes)				# reduce the states in the classes into a single state
   
def main():
	transition_table = [[1, 5], [6, 2], [0, 2], [2, 6], [7, 5], [2, 6], [6, 4], [6, 2]]
	states = [0, 1, 2, 3, 4, 5, 6, 7]
	alphabet = [0, 1]
	delta = lambda q, c: transition_table[q][c]
	start = 0
	accepts = [2]
	
	# another problem from krishnamurthy
	#
	# transition_table = [[1, 3], [2, 4], [1, 4], [2, 4], [4, 4]]
	# states = [0, 1, 2, 3, 4]
	# alphabet = [0, 1]
	# delta = lambda q, c: transition_table[q][c]
	# start = 0
	# accepts = [4]
		
	a = DFA(states, alphabet, delta, start, accepts)		# a is a class which stores the DFA
	
	print "\nBefore minimization: "
	a.print_tab()
	
	a.minimize()											# calls the DFA minimization function
	
	print "\n\nAfter minimization: "
	a.print_tab()
	
if __name__ == '__main__':
	main()
	# uncomment following line if running on windows to delay the window from closing
	# x = raw_input("\nPress any key to continue...")
