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
OBJS = 	archive.o\
		background.o\
		char_sprite.o\
		character_def.o\
		crc32.o\
		file_read.o\
		framedata.o\
		graph.o\
		input.o\
		mt.o\
		music.o\
		scene.o\
	 		chars/suwako.o\
	 		chars/reisen.o\
	 		chars/aya.o\
	 		chars/komachi.o\
	 		chars/iku.o\
			chars/tenshi.o\
			chars/alice.o\
			chars/marisa.o\
			chars/marisa_bullets.o\
			chars/alice_bullets.o\
			chars/cirno.o\
			chars/cirno_bullets.o\
			chars/utsuho.o\
			chars/suika.o\
			chars/yukari.o\
			chars/yuyuko.o\
			chars/remilia.o\
			chars/youmu.o\
			chars/patchouli.o\
			chars/sakuya.o\
			chars/reimu.o\
			chars/sanae.o\
			chars/namazu.o\
			chars/namazu_bullets.o\
			chars/meiling.o\
			chars/meiling_bullets.o\
		\
			menu/settings.o\
			menu/menus.o\
			menu/pause.o\
			menu/loading.o\
			menu/gameplay.o\
			menu/title.o\
		main.o\
		sfx.o\
		scene_fx.o\
		graph_efx.o\
		bullets.o\
		moveable.o\
		\
			fxsprite/fxSprite.o\
			fxsprite/fxTransform.o\
			fxsprite/fxTransformable.o\
		utils.o\
		meta.o\
		gui.o\
		text.o\
		weather.o\
		infoeffect.o\
		profile.o\
		cards.o\
		battle_ui.o\
		tail.o\
		c_scene_one.o\

#Create the build directory
MKDIR = mkdir "build" -p
.PHONY: MKDIR



# === Character list in order ===
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
	$(CXX) -O3 -Os --std=c++11 -pedantic -o $(TARGET) $(OBJS) $(LIBS) -I /usr/include/
	#$(CXX) -o $(TARGET) archive.o $(LIBS)

#	---The Objects ---
#Build "archive.cpp"
archive.o: archive.cpp
	$(CXX) -c "archive.cpp" -o archive.o

#Build "background.cpp"
background.o: background.cpp
	$(CXX) -c "background.cpp" -o background.o

#Build "battle_ui.cpp"
battle_ui.o: battle_ui.cpp
	$(CXX) -c "battle_ui.cpp" -o battle_ui.o

#Build "bullets.cpp"
bullets.o: bullets.cpp
	$(CXX) -c "bullets.cpp" -o bullets.o

#Build "cards.cpp"
cards.o: cards.cpp
	$(CXX) -c "cards.cpp" -o cards.o

#Build "character_def.cpp"
character_def.o: character_def.cpp
	$(CXX) -c "character_def.cpp" -o character_def.o

#Build "char_sprite.cpp"
char_sprite.o: char_sprite.cpp
	$(CXX) -c "char_sprite.cpp" -o char_sprite.o

#Build "crc32.cpp"
crc32.o: crc32.cpp
	$(CXX) -c "crc32.cpp" -o crc32.o

#Build "c_scene_one.cpp"
c_scene_one.o: c_scene_one.cpp
	$(CXX) -c "c_scene_one.cpp" -o c_scene_one.o

#Build "file_read.cpp"
file_read.o: file_read.cpp
	$(CXX) -c "file_read.cpp" -o file_read.o

#Build "framedata.cpp"
framedata.o: framedata.cpp
	$(CXX) -c "framedata.cpp" -o framedata.o

#Build "chars/alice.cpp"
chars/alice.o: chars/alice.cpp
	$(CXX) -c "chars/alice.cpp" -o chars/alice.o

#Build "chars/marisa.cpp"
chars/marisa.o: chars/marisa.cpp
	$(CXX) -c "chars/marisa.cpp" -o chars/marisa.o

#Build "chars/marisa_bullets.cpp"
chars/marisa_bullets.o: chars/marisa_bullets.cpp
	$(CXX) -c "chars/marisa_bullets.cpp" -o chars/marisa_bullets.o

#Build "chars/alice_bullets.cpp"
chars/alice_bullets.o: chars/alice_bullets.cpp
	$(CXX) -c "chars/alice_bullets.cpp" -o chars/alice_bullets.o

#Build "chars/cirno.cpp"
chars/cirno.o: chars/cirno.cpp
	$(CXX) -c "chars/cirno.cpp" -o chars/cirno.o

#Build "chars/cirno_bullets.cpp"
chars/cirno_bullets.o: chars/cirno_bullets.cpp
	$(CXX) -c "chars/cirno_bullets.cpp" -o chars/cirno_bullets.o

#Build "chars/utsuho.cpp"
chars/utsuho.o: chars/utsuho.cpp
	$(CXX) -c "chars/utsuho.cpp" -o chars/utsuho.o

#Build "chars/suika.cpp"
chars/suika.o: chars/suika.cpp
	$(CXX) -c "chars/suika.cpp" -o chars/suika.o

#Build "chars/namazu.cpp"
chars/namazu.o: chars/namazu.cpp
	$(CXX) -c "chars/namazu.cpp" -o chars/namazu.o

#Build "chars/namazu_bullets.cpp"
chars/namazu_bullets.o: chars/namazu_bullets.cpp
	$(CXX) -c "chars/namazu_bullets.cpp" -o chars/namazu_bullets.o

#Build "chars/meiling.cpp"
chars/meiling.o: chars/meiling.cpp
	$(CXX) -c "chars/meiling.cpp" -o chars/meiling.o

#Build "chars/meiling_bullets.cpp"
chars/meiling_bullets.o: chars/meiling_bullets.cpp
	$(CXX) -c "chars/meiling_bullets.cpp" -o chars/meiling_bullets.o

#Build "menu/menus.cpp"
menu/menus.o: menu/menus.cpp
	$(CXX) -c "menu/menus.cpp" -o menu/menus.o

#Build "menu/title.cpp"
menu/title.o: menu/title.cpp
	$(CXX) -c "menu/title.cpp" -o menu/title.o

#Build "menu/pause.cpp"
menu/pause.o: menu/pause.cpp
	$(CXX) -c "menu/pause.cpp" -o menu/pause.o

#Build "menu/loading.cpp"
menu/loading.o: menu/loading.cpp
	$(CXX) -c "menu/loading.cpp" -o menu/loading.o

#Build "menu/gameplay.cpp"
menu/gameplay.o: menu/gameplay.cpp
	$(CXX) -c "menu/gameplay.cpp" -o menu/gameplay.o

#Build "fx_sprite.cpp"
#fx_sprite.o: fx_sprite.cpp
#	$(CXX) -c "fx_sprite.cpp" -o fx_sprite.o

#Build "graph.cpp"
graph.o: graph.cpp
	$(CXX) -c "graph.cpp" -o graph.o

#Build "graph_efx.cpp"
graph_efx.o: graph_efx.cpp
	$(CXX) -c "graph_efx.cpp" -o graph_efx.o

#Build "gui.cpp"
gui.o: gui.cpp
	$(CXX) -c "gui.cpp" -o gui.o

#Build "infoeffect.cpp"
infoeffect.o: infoeffect.cpp
	$(CXX) -c "infoeffect.cpp" -o infoeffect.o

#Build "input.cpp"
input.o: input.cpp
	$(CXX) -c "input.cpp" -o input.o

#Build "main.cpp"
main.o: main.cpp
	$(CXX) -c "main.cpp" -o main.o

#Build "meta.cpp"
meta.o: meta.cpp
	$(CXX) -c "meta.cpp" -o meta.o

#Build "moveable.cpp"
moveable.o: moveable.cpp
	$(CXX) -c "moveable.cpp" -o moveable.o

#Build "fxsprite/fxSprite.cpp"
fxpsrite/fxSprite.o: fxsprite/fxSprite.cpp
	$(CXX) -c "fxsprite/fxSprite.cpp" -o fxsprite/fxSprite.o

#Build "fxsprite/fxTransform.cpp"
fxsprite/fxTransform.o: fxsprite/fxTransform.cpp
	$(CXX) -c "fxsprite/fxTransform.cpp" -o fxsprite/fxTransform.o

#Build "fxsprite/fxTransformable.cpp"
fxpsrite/fxTransformable.o: fxsprite/fxTransformable.cpp
	$(CXX) -c "fxsprite/fxTransformable.cpp" -o fxsprite/fxTransformable.o

#Build "mt.cpp"
mt.o: mt.cpp
	$(CXX) -c "mt.cpp" -o mt.o

#Build "music.cpp"
music.o: music.cpp
	$(CXX) -c "music.cpp" -o music.o

#Build "profile.cpp"
profile.o: profile.cpp
	$(CXX) -c "profile.cpp" -o profile.o

#Build "scene.cpp"
scene.o: scene.cpp
	$(CXX) -c "scene.cpp" -o scene.o

#Build "scene_fx.cpp"
scene_fx.o: scene_fx.cpp
	$(CXX) -c "scene_fx.cpp" -o scene_fx.o

#Build "settings.cpp"
settings.o: settings.cpp
	$(CXX) -c "settings.cpp" -o settings.o

#Build "sfx.cpp"
sfx.o: sfx.cpp
	$(CXX) -c "sfx.cpp" -o sfx.o

#Build "tail.cpp"
tail.o: tail.cpp
	$(CXX) -c "tail.cpp" -o tail.o

#Build "text.cpp"
text.o: text.cpp
	$(CXX) -c "text.cpp" -o text.o

#Build "utils.cpp"
utils.o: utils.cpp
	$(CXX) -c "utils.cpp" -o utils.o

#Build "weather.cpp"
weather.o: weather.cpp
	$(CXX) -c "weather.cpp" -o weather.o

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
