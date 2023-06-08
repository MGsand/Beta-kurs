.PHONY: clean

CFLAGS = -Wall -Wextra
CPPFLAGS = -MMD

LIBPATH = obj/src/lib

cdall: bin/kursovikkk

test: bin/gtest

bin/kursovikkk: obj/src/format/kursovikkk.o obj/src/lib/lib.a
	$(CC) $(CFLAGS) -o $@ $^

bin/gtest: ctests/main.o obj/src/lib/test_1.o  thirdparty/ctest.h obj/src/lib/functions.o 
	$(CC) $(CFLAGS) -o $@ $^

ctests/main.o: ctests/main.c
	$(CC) -c $(CFLAGS) $< $(CPPFLAGS) -o $@ -I test

obj/src/lib/test_1.o: thirdparty/test_1.c 
	$(CC) -c $(CFLAGS) $< $(CPPFLAGS) -o $@ -I src/lib

obj/src/lib/lib.a: obj/src/lib/functions.o
	ar rcs $@ $^

obj/src/format/kursovikkk.o: src/format/kursovikkk.cpp
	$(CC) -c $(CFLAGS) $< $(CPPFLAGS) -o $@ -I src/lib
	
obj/src/lib/functions.o: src/lib/functions.cpp src/lib/functions.h
	$(CC) -c $(CFLAGS) $< $(CPPFLAGS) -o $@ -I src/lib
	
clean: 
	rm bin/kursovikkk
	rm obj/src/format/*.d
	rm obj/src/format/*.o
	rm obj/src/lib/*.d
	rm obj/src/lib/*.o
	rm obj/src/lib/*.a

-include obj/src/format/kursovukkk.d obj/src/lib/functions.d
