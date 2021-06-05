# make build
# Usage: sudo bash install.sh (Recommended) OR sudo make


all : bin/main

# Binary file, uncomment the instruction and comment the game to test the files

bin/main : obj/pruebaConjuntoFinal.o lib/libparticula.a
	g++ -o bin/main obj/pruebaConjuntoFinal.o -Llib -lparticula
	@echo 'Build Successfully!'
# bin/main : obj/ovnis.o lib/libparticula.a
# 	g++ -o bin/main obj/ovnis.o -Llib -lparticula -lraylib
# 	@echo 'Build Successfully'

# Creating Library
lib/libparticula.a : obj/ConjuntoParticulas.o obj/Particula.o obj/Pintar.o
	@echo "Creating Library..."
	ar rsv lib/libparticula.a obj/ConjuntoParticulas.o obj/Particula.o obj/Pintar.o

# Object files

obj/pruebaConjuntoFinal.o : src/pruebaConjuntoFinal.cpp include/Particula.h include/ConjuntoParticulas.h
	g++ -c src/pruebaConjuntoFinal.cpp -o obj/pruebaConjuntoFinal.o -Iinclude -lraylib

obj/ovnis.o : src/ovnis.cpp include/Particula.h include/ConjuntoParticulas.h include/Pintar.h
	g++ -c src/ovnis.cpp -o obj/ovnis.o -Iinclude -lraylib

obj/ConjuntoParticulas.o : src/ConjuntoParticulas.cpp include/Particula.h include/ConjuntoParticulas.h
	g++ -c src/ConjuntoParticulas.cpp -o obj/ConjuntoParticulas.o -Iinclude -lraylib

obj/Particula.o : src/Particula.cpp include/Particula.h
	g++ -c src/Particula.cpp -o obj/Particula.o -Iinclude -lraylib

obj/Pintar.o : src/Pintar.cpp include/Particula.h include/ConjuntoParticulas.h include/Pintar.h
	g++ -c src/Pintar.cpp -o obj/Pintar.o -Iinclude -lraylib

# Cleaners
cleanObj:
	@echo 'Cleaning...'
	rm obj/*.o
	rm lib/*.a
clean: cleanObj
	rm bin/*