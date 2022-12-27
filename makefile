app: main.o activations.o helper.o perceptron.o algebra.o writer.o
	gcc -o main object_files/*.o

main.o: main.c
	gcc -I src/ -o object_files/main.o -c main.c

activations.o: src/activations.c
	gcc -o object_files/activations.o -c src/activations.c
helper.o: src/helper.c
	gcc -o object_files/helper.o -c src/helper.c
perceptron.o: src/perceptron.c
	gcc -o object_files/perceptron.o -c src/perceptron.c

algebra.o: src/algebra.c
	gcc -o object_files/algebra.o -c src/algebra.c
writer.o: src/writer.c
	gcc -o object_files/writer.o -c src/writer.c