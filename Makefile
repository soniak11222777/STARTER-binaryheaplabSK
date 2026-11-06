examheap: examheap.o heap.o
	g++ -o examheap examheap.o heap.o 

examheap.o: examheap.cpp
	g++ -c examheap.cpp

heap.o: heap.cpp
	g++ -c heap.cpp

clean:
	rm examheap *.o

	
