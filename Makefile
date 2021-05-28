
all : bin/main


# Binary file, uncomment the instruction and comment the game to test the files

# bin/main : obj/pruebaConjunto.o lib/libparticula.a
# 	g++ -o bin/main obj/pruebaConjunto.o -Llib -lparticula
bin/main : obj/capturaOvnis.o lib/libparticula.a
	g++ -o bin/main obj/capturaOvnis.o -Llib -lparticula -lraylib

# Creating Library
lib/libparticula.a : obj/ConjuntoParticulas.o obj/Particula.o obj/Pintar.o
	ar rsv lib/libparticula.a obj/ConjuntoParticulas.o obj/Particula.o obj/Pintar.o

# Object files
obj/pruebaConjunto.o : src/pruebaConjunto.cpp include/Particula.h include/ConjuntoParticulas.h include/Pintar.h
	g++ -c src/pruebaConjunto.cpp -o obj/pruebaConjunto.o -Iinclude -lraylib

obj/capturaOvnis.o : src/capturaOvnis.cpp include/Particula.h include/ConjuntoParticulas.h include/Pintar.h
	g++ -c src/capturaOvnis.cpp -o obj/capturaOvnis.o -Iinclude -lraylib

obj/ConjuntoParticulas.o : src/ConjuntoParticulas.cpp include/Particula.h include/ConjuntoParticulas.h
	g++ -c src/ConjuntoParticulas.cpp -o obj/ConjuntoParticulas.o -Iinclude -lraylib

obj/Particula.o : src/Particula.cpp include/Particula.h
	g++ -c src/Particula.cpp -o obj/Particula.o -Iinclude -lraylib

obj/Pintar.o : src/Pintar.cpp include/Particula.h include/ConjuntoParticulas.h include/Pintar.h
	g++ -c src/Pintar.cpp -o obj/Pintar.o -Iinclude -lraylib

# Cleaners
clean:
	rm obj/*.o
	rm lib/*.a
cleanBin:
	rm bin/*