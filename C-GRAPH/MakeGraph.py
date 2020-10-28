import sys

def makeGraph(nodes, edges, filename):
        f = open(filename, "w")
        f.write(str(nodes) + " " + str(edges) + "\n")
        for i in range(nodes):
                f.write(str(i+1) + " " + str(((i+1 * 156) % nodes) + 1))
                f.write("\n")
        f.close()

if __name__ == "__main__":
        makeGraph(int(sys.argv[1]), int(sys.argv[2]), sys.argv[3])
