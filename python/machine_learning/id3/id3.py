import math
import os
import sys

def entropy(data, attr):
	""" 
	Calculate entropy of a given data for the target attribute 
	"""
	freq = {}
	H = 0.0
	
	# Calculate the frequency of each value in the target attribute
	for entry in data:
		if freq.has_key(entry[attr]):
			freq[entry[attr]] += 1.0
		else:
			freq[entry[attr]] = 1.0
	
	# Calculate the entropy of the data for the target attribute
	for f in freq.values():
		H += (-f / len(data)) * math.log(f / len(data), 2)
	
	return H

def gain(data, attr, t_attr):
	""" 
	Calculates the information gain that would result by splitting the data
	"""
	freq = {}
	S = 0.0
	
	# Calculate the frequency of each of the value in the target attribute
	for entry in data:
		if freq.has_key(entry[attr]):
			freq[entry[attr]] += 1.0
		else:
			freq[entry[attr]] = 1.0
	
	# Calculate the sum of the entropy for each subset of records
	# weighted by probability of occurring in the training set
	for val in freq.keys():
		prob = freq[val] / sum(freq.values())
		subset = [rec for rec in data if rec[attr] == val]
		S += prob * entropy(subset, t_attr)
	
	return entropy(data, t_attr) - S

def most_frequent(value_list):
	""" 
	Return the most frequent element in a list 
	"""
	lst = value_list[:]
	count_dict = dict([(val, lst.count(val)) for val in lst])
	return max(count_dict.items(), key = lambda x : x[1])[0]
			
def majority_value(data, t_attr):
	""" 
	Return the value that appear the most 
	in training set for a give attribute 
	"""
	data = data[:]
	return most_frequent([entry[t_attr] for entry in data])

def get_values(data, attr):
	"""
    Creates a list of values in the chosen attribut for each record in data,
    and return the list.  
    """
	data = data[:]
	return list(set([entry[attr] for entry in data]))

def choose_attr(data, attrs, t_attr):
	"""
    Cycles through all the attributes and returns the attribute with the
    highest information gain (or lowest entropy).
    """
	data = data[:]
	gain_dict = dict([(attr, gain(data, attr, t_attr)) \
					   for attr in attrs if attr != t_attr])
	return max(gain_dict.items(), key = lambda x : x[1])[0]

def get_examples(data, attr, value):
	"""
    Returns a list of all the records in <data> with the value of <attr>
    matching the given value.
    """
	data = data[:]
	ret_lst = []
	if not data:
		return  ret_lst
	else:
		entry = data.pop()
		if entry[attr] == value:
			ret_lst.append(entry)
			ret_lst.extend(get_examples(data, attr, value))
			return ret_lst
		else:
			ret_lst.extend(get_examples(data, attr, value))
			return ret_lst

def get_classification(entry, tree):
	"""
	Recursively traverses the decision tree
	and returns a classification for the givel record
	"""
	
	# If the current node is leaf
	if type(tree) == type("string"):
		return tree
		
	# Traverse until leaf node is found
	else:
		attr = tree.keys()[0]
		t = tree[attr][entry[attr]]
		return get_classification(entry, t)

def classify(data, tree):
	"""
    Returns a list of classifications for each of the records in the data
    list as determined by the given decision tree.
    """
	data = data[:]
	classification = []
	
	for entry in data:
		classification.append(get_classification(entry, tree))
	
	return classification

def create_decision_tree(data, attrs, t_attr):
	"""
	Returns a new decision tree based on the examples given.
	"""
	data = data[:]
	vals = [entry[t_attr] for entry in data]
	default = majority_value(data, t_attr)
	
	if not data or (len(attrs) - 1) <= 0:
		return default
	
	elif vals.count(vals[0]) == len(vals):
		return vals[0]
	
	else:
		# Choose the next best attribute to best classify our data
		best = choose_attr(data, attrs, t_attr)

		# Create a new decision tree/node with the best attribute and an empty
		# dictionary object--we'll fill that up next.
		tree = {best:{}}

		# Create a new decision tree/sub-node for each of the values in the
		# best attribute field
		for val in get_values(data, best):
			# Create a subtree for the current value under the "best" field
			subtree = create_decision_tree(
				get_examples(data, best, val), \
				[attr for attr in attrs if attr != best], \
				t_attr)

			# Add the new subtree to the empty dictionary object in our new
			# tree/node we just created.
			tree[best][val] = subtree
	
	return tree
	
def get_input_file():
	filename = sys.argv[1]

	try:
		fin = open(filename, "r")
	except IOError:
		print "Error: The file '{0}' was not \
			   found on this system.".format(filename)
		sys.exit(0)

	return fin

def read_data(fin):
    # Create a list of all the lines in the data file
    lines = [line.strip() for line in fin.readlines()]

    # Remove the attributes from the list of lines and create a list of
    # the attributes.
    lines.reverse()
    attrs = [attr.strip() for attr in lines.pop().split()]
    t_attr = attrs[-1]
    lines.reverse()

    # Create a list of the data in the data file
    data = []
    for line in lines:
		data.append(dict(zip(attrs,[datum.strip() \
					for datum in line.split()])))
        
    # Copy the data list into the examples list for testing
    examples = data[:]
    
    # Create the decision tree
    tree = create_decision_tree(data, attrs, t_attr)

    # Classify the records in the examples list
    classification = classify(examples, tree)

    # Print out the classification for each record
    for item in classification:
        print item

    return tree

def print_tree(tree, str):
    if type(tree) == dict:
        print "%s%s" % (str, tree.keys()[0])
        for item in tree.values()[0].keys():
            print "%s\t%s" % (str, item)
            print_tree(tree.values()[0][item], str + "\t")
    else:
        print "%s\t->\t%s" % (str, tree)

if __name__ == "__main__":
    fin = get_input_file()
    print "------------------------\n"
    print "--   Classification   --\n"
    print "------------------------\n"
    print "\n"    
    tree = read_data(fin)
    print "\n"
    print "------------------------\n"
    print "--   Decision Tree    --\n"
    print "------------------------\n"
    print "\n"
    print_tree(tree, "")
    fin.close()
		