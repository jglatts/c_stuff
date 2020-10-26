
def makeGraph(nodes, edges, filename): 
	f = open(filename, "w")
	f.write(str(nodes) + " " + str(edges) + "\n")
	for i in range(nodes):
		f.write(str(i+1) + " " + str(((i * 156) % 25) + 9))	 #replace w/ random ints
		f.write("\n")
	f.close()


makeGraph(100, 100, "py_graph.txt")
