FILES = src/*.cpp
SDL_FLAGS = -lSDL2 -lSDL2_image
INCLUDE = -I ./include

debug:
	g++ -Wall -std=c++20 -stdlib=libc++ $(SDL_FLAGS) -g ${FILES} -o ./make/build/game-v1.0.0-osx   $(INCLUDE)

.PHONY: clean osxv winv clang WORK

WORK:
	g++ -Wall -std=c++20 -stdlib=libc++ -g ${FILES} ${SDL_FLAGS} -o ./make/build/game-v1.0.0-osx   $(INCLUDE) -I ./Frameworks/SDL2.framework


clean:
	rm -rf ./make/bin/* ./make/build/*

-osxv:
	g++ -Wall -std=c++20 -stdlib=libc++ $(SDL_FLAGS) -g ${FILES} -v -o ./make/build/game-v1.0.0-osx   $(INCLUDE)

-winv:
	g++ -Wall -std=c++20 -stdlib=libc++ $(SDL_FLAGS) -g ${FILES} -v -o ./make/bin/game-v1.0.0-win $(INCLUDE)

clang:
	clang++ -Wall -std=c++20 -stdlib=libc++ $(SDL_FLAGS) -g ${FILES} -o ./make/build/game-v1.0.0-osx   $(INCLUDE)
