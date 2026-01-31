all:
	gcc src/FileSystem.c src/Loader.c src/Memory.c src/Process.c src/Structures.c src/MiniKernel.c -o MiniKernel

run:
	clear && ./MiniKernel

clean:
	rm MiniKernel