lorenz:lorenz.c
	gcc -o lorenz lorenz.c -framework OpenGL -framework GLUT
clean:
	rm lorenz
