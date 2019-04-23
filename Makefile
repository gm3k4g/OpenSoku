#Made on -- 03:29 AM - 24th Jan.
#Makefile for OpenSokuREDO

#Arguments specified below \
#==================================================
#Required for the project to compile
LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

#==================================================
#LINUX options

#Game
TARGET=build/openSoku

#g++ compiler
CXX = g++

#gcc compiler
CC = gcc

#==================================================
# Under construction!
#WINDOWS options

#Game 
#TARGET_WIN = $(TARGET).exe

#MINGW compiler

#g++ compiler

#gcc compiler
#==================================================


#All the objects(files) that need to be compiled for the project:
OBJS = 	src/archive.o\
		src/background.o\
		src/char_sprite.o\
		src/character_def.o\
		src/crc32.o\
		src/file_read.o\
		src/framedata.o\
		src/graph.o\
		src/input.o\
		src/mt.o\
		src/music.o\
		src/scene.o\
	 		src/chars/suwako.o\
	 		src/chars/reisen.o\
	 		src/chars/aya.o\
	 		src/chars/komachi.o\
	 		src/chars/iku.o\
			src/chars/tenshi.o\
			src/chars/alice.o\
			src/chars/marisa.o\
			src/chars/marisa_bullets.o\
			src/chars/alice_bullets.o\
			src/chars/cirno.o\
			src/chars/cirno_bullets.o\
			src/chars/utsuho.o\
			src/chars/suika.o\
			src/chars/yukari.o\
			src/chars/yuyuko.o\
			src/chars/remilia.o\
			src/chars/youmu.o\
			src/chars/patchouli.o\
			src/chars/sakuya.o\
			src/chars/reimu.o\
			src/chars/sanae.o\
			src/chars/namazu.o\
			src/chars/namazu_bullets.o\
			src/chars/meiling.o\
			src/chars/meiling_bullets.o\
		\
			src/menu/settings.o\
			src/menu/menus.o\
			src/menu/pause.o\
			src/menu/loading.o\
			src/menu/gameplay.o\
			src/menu/title.o\
		src/main.o\
		src/sfx.o\
		src/scene_fx.o\
		src/graph_efx.o\
		src/bullets.o\
		src/moveable.o\
		\
			src/fxsprite/fxSprite.o\
			src/fxsprite/fxTransform.o\
			src/fxsprite/fxTransformable.o\
		src/utils.o\
		src/meta.o\
		src/gui.o\
		src/text.o\
		src/weather.o\
		src/infoeffect.o\
		src/profile.o\
		src/cards.o\
		src/battle_ui.o\
		src/tail.o\
		src/c_scene_one.o\

#Create the build directory
MKDIR = mkdir "build" -p
.PHONY: MKDIR



# === Objects to be built soon ===
# chars/suika_bullets.o\
# chars/utsuho_bullets.o\
# chars/yukari_bullets.o\
# chars/yuyuko_bullets.o\
# chars/remilia_bullets.o\
# chars/youmu_bullets.o\
# chars/patchouli_bullets.o\
# chars/sakuya_bullets.o\
# chars/reimu_bullets.o\
# chars/sanae_bullets.o\
# chars/meiling_bullets.o\
# chars/suwako_bullets.o\
# chars/reisen_bullets.o\
# chars/aya_bullets.o\
# chars/komachi_bullets.o\
# chars/iku_bullets.o\
# chars/tenshi_bullets.o\
# !!!!!!!!!!!!!!!!!
# WE DO NOT KNOW IF THE CHARACTER BELOW IS POSSIBLE
# chars/namazu.o\
# chars/namazu_bullets.o\



#==================================================
#Typing "make" compiles the following



#Optimization options:
#-O3 -Os --std=c++11 -pedantic -o $(TARGET) $(OBJS) $(LIBS) -I /usr/include/ 
#================================================== 
#-O3 		---: Turn on all optimizations specified by -O2 and also turns
# various optimization flags on.

#-Os 		---: Optimize for size. This enables all -O2 optimizations
#except those that increase code size.

#-std=c++11 ---: Standard support.

#-pedantic 	---: Convert warnings into errors.

#-o 		---: Generate object file.
#==================================================
#Linux build v0.01
# Changelog: Initial creation of the linux makefile code!
#=================
#Linux build v0.02
# Changelog:
#	-Now creating "src/build" to avoid makefile errors
#------------
#Experimental!
#Build everything
linux: $(OBJS)
	@echo "Building project for LINUX.."
	@echo "Creating directories.."
	$(MKDIR)
	@echo "Compiling everything.."
	$(CXX) -O3 -Os --std=c++11 -pedantic -o $(TARGET) $(OBJS) $(LIBS) -I /usr/include/ -g
	#$(CXX) -o $(TARGET) archive.o $(LIBS)

#	---The Objects ---
#Build "archive.cpp"
src/archive.o: src/archive.cpp
	$(CXX) -c "src/archive.cpp" -o src/archive.o

#Build "background.cpp"
src/background.o: src/background.cpp
	$(CXX) -c "src/background.cpp" -o src/background.o

#Build "battle_ui.cpp"
src/battle_ui.o: src/battle_ui.cpp
	$(CXX) -c "src/battle_ui.cpp" -o src/battle_ui.o

#Build "bullets.cpp"
src/bullets.o: src/bullets.cpp
	$(CXX) -c "src/bullets.cpp" -o src/bullets.o

#Build "cards.cpp"
src/cards.o: src/cards.cpp
	$(CXX) -c "src/cards.cpp" -o src/cards.o

#Build "character_def.cpp"
src/character_def.o: src/character_def.cpp
	$(CXX) -c "src/character_def.cpp" -o src/character_def.o

#Build "char_sprite.cpp"
src/char_sprite.o: src/char_sprite.cpp
	$(CXX) -c "src/char_sprite.cpp" -o src/char_sprite.o

#Build "crc32.cpp"
src/crc32.o: src/crc32.cpp
	$(CXX) -c "src/crc32.cpp" -o src/crc32.o

#Build "c_scene_one.cpp"
src/c_scene_one.o: src/c_scene_one.cpp
	$(CXX) -c "src/c_scene_one.cpp" -o src/c_scene_one.o

#Build "file_read.cpp"
src/file_read.o: src/file_read.cpp
	$(CXX) -c "src/file_read.cpp" -o src/file_read.o

#Build "framedata.cpp"
src/framedata.o: src/framedata.cpp
	$(CXX) -c "src/framedata.cpp" -o src/framedata.o

#Build "chars/alice.cpp"
src/chars/alice.o: src/chars/alice.cpp
	$(CXX) -c "src/chars/alice.cpp" -o src/chars/alice.o

#Build "chars/marisa.cpp"
src/chars/marisa.o: src/chars/marisa.cpp
	$(CXX) -c "src/chars/marisa.cpp" -o src/chars/marisa.o

#Build "chars/marisa_bullets.cpp"
src/chars/marisa_bullets.o: src/chars/marisa_bullets.cpp
	$(CXX) -c "src/chars/marisa_bullets.cpp" -o src/chars/marisa_bullets.o

#Build "chars/alice_bullets.cpp"
src/chars/alice_bullets.o: src/chars/alice_bullets.cpp
	$(CXX) -c "src/chars/alice_bullets.cpp" -o src/chars/alice_bullets.o

#Build "chars/cirno.cpp"
src/chars/cirno.o: src/chars/cirno.cpp
	$(CXX) -c "src/chars/cirno.cpp" -o src/chars/cirno.o

#Build "chars/cirno_bullets.cpp"
src/chars/cirno_bullets.o: src/chars/cirno_bullets.cpp
	$(CXX) -c "src/chars/cirno_bullets.cpp" -o src/chars/cirno_bullets.o

#Build "chars/utsuho.cpp"
src/chars/utsuho.o: src/chars/utsuho.cpp
	$(CXX) -c "src/chars/utsuho.cpp" -o src/chars/utsuho.o

#Build "chars/suika.cpp"
src/chars/suika.o: src/chars/suika.cpp
	$(CXX) -c "src/chars/suika.cpp" -o src/chars/suika.o

#Build "chars/namazu.cpp"
src/chars/namazu.o: src/chars/namazu.cpp
	$(CXX) -c "src/chars/namazu.cpp" -o src/chars/namazu.o

#Build "chars/namazu_bullets.cpp"
src/chars/namazu_bullets.o: src/chars/namazu_bullets.cpp
	$(CXX) -c "src/chars/namazu_bullets.cpp" -o src/chars/namazu_bullets.o

#Build "chars/meiling.cpp"
src/chars/meiling.o: src/chars/meiling.cpp
	$(CXX) -c "src/chars/meiling.cpp" -o src/chars/meiling.o

#Build "chars/meiling_bullets.cpp"
src/chars/meiling_bullets.o: src/chars/meiling_bullets.cpp
	$(CXX) -c "src/chars/meiling_bullets.cpp" -o src/chars/meiling_bullets.o

#Build "menu/menus.cpp"
src/menu/menus.o: src/menu/menus.cpp
	$(CXX) -c "src/menu/menus.cpp" -o src/menu/menus.o

#Build "menu/title.cpp"
src/menu/title.o: src/menu/title.cpp
	$(CXX) -c "src/menu/title.cpp" -o src/menu/title.o

#Build "menu/pause.cpp"
src/menu/pause.o: src/menu/pause.cpp
	$(CXX) -c "src/menu/pause.cpp" -o src/menu/pause.o

#Build "menu/loading.cpp"
src/menu/loading.o: src/menu/loading.cpp
	$(CXX) -c "src/menu/loading.cpp" -o src/menu/loading.o

#Build "menu/gameplay.cpp"
src/menu/gameplay.o: src/menu/gameplay.cpp
	$(CXX) -c "src/menu/gameplay.cpp" -o src/menu/gameplay.o

#Build "fx_sprite.cpp"
#fx_sprite.o: fx_sprite.cpp
#	$(CXX) -c "fx_sprite.cpp" -o fx_sprite.o

#Build "graph.cpp"
src/graph.o: src/graph.cpp
	$(CXX) -c "src/graph.cpp" -o src/graph.o

#Build "graph_efx.cpp"
src/graph_efx.o: src/graph_efx.cpp
	$(CXX) -c "src/graph_efx.cpp" -o src/graph_efx.o

#Build "gui.cpp"
src/gui.o: src/gui.cpp
	$(CXX) -c "src/gui.cpp" -o src/gui.o

#Build "infoeffect.cpp"
src/infoeffect.o: src/infoeffect.cpp
	$(CXX) -c "src/infoeffect.cpp" -o src/infoeffect.o

#Build "input.cpp"
src/input.o: src/input.cpp
	$(CXX) -c "src/input.cpp" -o src/input.o

#Build "main.cpp"
src/main.o: src/main.cpp
	$(CXX) -c "src/main.cpp" -o src/main.o

#Build "meta.cpp"
src/meta.o: src/meta.cpp
	$(CXX) -c "src/meta.cpp" -o src/meta.o

#Build "moveable.cpp"
src/moveable.o: src/moveable.cpp
	$(CXX) -c "src/moveable.cpp" -o src/moveable.o

#Build "fxsprite/fxSprite.cpp"
src/fxpsrite/fxSprite.o: src/fxsprite/fxSprite.cpp
	$(CXX) -c "src/fxsprite/fxSprite.cpp" -o src/fxsprite/fxSprite.o

#Build "fxsprite/fxTransform.cpp"
src/fxsprite/fxTransform.o: src/fxsprite/fxTransform.cpp
	$(CXX) -c "src/fxsprite/fxTransform.cpp" -o src/fxsprite/fxTransform.o

#Build "fxsprite/fxTransformable.cpp"
src/fxpsrite/fxTransformable.o: src/fxsprite/fxTransformable.cpp
	$(CXX) -c "src/fxsprite/fxTransformable.cpp" -o src/fxsprite/fxTransformable.o

#Build "mt.cpp"
src/mt.o: src/mt.cpp
	$(CXX) -c "src/mt.cpp" -o src/mt.o

#Build "music.cpp"
src/music.o: src/music.cpp
	$(CXX) -c "src/music.cpp" -o src/music.o

#Build "profile.cpp"
src/profile.o: src/profile.cpp
	$(CXX) -c "src/profile.cpp" -o src/profile.o

#Build "scene.cpp"
src/scene.o: src/scene.cpp
	$(CXX) -c "src/scene.cpp" -o src/scene.o

#Build "scene_fx.cpp"
src/scene_fx.o: src/scene_fx.cpp
	$(CXX) -c "src/scene_fx.cpp" -o src/scene_fx.o

#Build "settings.cpp"
src/settings.o: src/settings.cpp
	$(CXX) -c "src/settings.cpp" -o src/settings.o

#Build "sfx.cpp"
src/sfx.o: src/sfx.cpp
	$(CXX) -c "src/sfx.cpp" -o src/sfx.o

#Build "tail.cpp"
src/tail.o: src/tail.cpp
	$(CXX) -c "src/tail.cpp" -o src/tail.o

#Build "text.cpp"
src/text.o: src/text.cpp
	$(CXX) -c "src/text.cpp" -o src/text.o

#Build "utils.cpp"
src/utils.o: src/utils.cpp
	$(CXX) -c "src/utils.cpp" -o src/utils.o

#Build "weather.cpp"
src/weather.o: src/weather.cpp
	$(CXX) -c "src/weather.cpp" -o src/weather.o

#==================================================
#Under construction!
#Windows build v0.01
#win32: $(OBJS)
#	@echo "Compiling project for WINDOWS..."
#	$(CXX_WIN) -O3 -Os --std=c++11 -o $(TARGET_WIN) $(OBJS) $(WINOBJ) $(LIBS_WIN) -I $(MINGW)/include/ 

#==================================================
#Delete all created files
clean:
	@echo "Removing and cleaning everything..."

	#Erase all objects in current directory
	rm -f $(TARGET) $(TARGET_WIN) *.o

	#Erase all objects in all subdirectories
	find . -name '*.o' -delete
	find . -name '$(TARGET)' -delete


#==================================================
