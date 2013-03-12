import math
import os
import sys

def entropy(data, attr):
	"""
	Compute the entropy
	"""
	freq = {}
	H = 0.0
	
	for entry in data:
		if freq.has_key(entry[attr]):
			freq[entry[attr]] += 1.0
		else:
			freq[entry[attr]] = 1.0

	for f in freq.values():
		H += (-f / len(data)) * math.log(f / len(data), 2)
	
	return H

def gain(data, attr, t_attr):
	"""
	Compute the gain
	"""
	freq = {}
	S = 0.0
	
	for entry in data:
		if freq.has_key(entry[attr]):
			freq[entry[attr]] += 1.0
		else:
			freq[entry[attr]] = 1.0
	
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
    highest information gain.
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
		best = choose_attr(data, attrs, t_attr)

		tree = {best:{}}

		for val in get_values(data, best):
			subtree = create_decision_tree(
				get_examples(data, best, val), \
				[attr for attr in attrs if attr != best], \
				t_attr)

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
    lines = [line.strip() for line in fin.readlines()]

    lines.reverse()
    attrs = [attr.strip() for attr in lines.pop().split()]
    t_attr = attrs[-1]
    lines.reverse()

    data = []
    for line in lines:
		data.append(dict(zip(attrs,[datum.strip() \
					for datum in line.split()])))
        
    examples = data[:]
    
    tree = create_decision_tree(data, attrs, t_attr)
	
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
    tree = read_data(fin)
    print "\n"
    print "------------------------"
    print "	    Decision Tree      "
    print "------------------------"
    print "\n"
    print_tree(tree, "")
    fin.close()
		