import time

def test():
	print("running a test\n")
	f = open("bckgrnd_test.txt", "w")
	for i in range(10):
		f.write("Running a python process, in the background!!\n")
		time.sleep(5)
	f.close()

test()
