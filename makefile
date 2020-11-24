TARGET = main

LDFLAGS := -I/usr/local/include -lallegro -lallegro_main -lallegro_image -lallegro_primitives

$(TARGET): main.o lib.a
	gcc $^ -o $@ $(LDFLAGS)


main.o: main.c
	gcc -c $< -o $@

lib.a: game.o Component.o
	ar rcs $@ $^

game.o: game.c game.h
	gcc -c -o $@ $<
	

Component.o: Player.c Component.h
	gcc -c -o $@ $<
	

clean:
	rm -f *.o *.a $(TARGET)