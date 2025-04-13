# Compilador utilizado
CC=gcc

# Flags de compilação
CFLAGS=-Iinclude

# Flags específicas para GLib
GLIB_CFLAGS=`pkg-config --cflags glib-2.0`
GLIB_LDFLAGS=`pkg-config --libs glib-2.0`

# Diretório das bibliotecas
LIBS=libs

# Ficheiros objeto
OBJ_FILES=src/main.o src/parser.o src/utilidades.o src/general_manager.o \
		  src/Queries/querie_1.o src/Queries/querie_2.o src/Queries/querie_3.o src/Queries/querie_4.o \
		  src/Queries/querie_5.o src/Queries/querie_6.o \
          src/Musics_Manager/musics.o src/Users_Manager/users.o src/Artists_Manager/artists.o \
          src/Users_Manager/users_manager.o src/Musics_Manager/musics_manager.o src/Artists_Manager/artists_manager.o \
          src/Artists_Manager/HT_Artists.o src/Musics_Manager/HT_Music.o src/Musics_Manager/TOP_Music.o \
          src/Users_Manager/HT_User.o src/Users_Manager/GR_User.o src/Albums_Manager/albums.o \
		  src/Albums_Manager/albums_manager.o src/Albums_Manager/HT_Albums.o src/History_Manager/history.o \
		  src/History_Manager/history_manager.o src/History_Manager/HT_LUS.o\
		  src/Iteratividade/iteratividade.o src/Iteratividade/querie_iter_1.o src/Iteratividade/querie_iter_2.o src/Iteratividade/querie_iter_3.o \
		  src/Iteratividade/querie_iter_4.o src/Iteratividade/querie_iter_5.o src/Iteratividade/querie_iter_6.o \
		  src/Artists_Manager/HT_ArtTOP.o src/testes.o

OBJ_TESTES_FILES=src/main_testes.o src/parser.o src/utilidades.o src/general_manager.o \
		  src/Queries/querie_1.o src/Queries/querie_2.o src/Queries/querie_3.o src/Queries/querie_4.o \
		  src/Queries/querie_5.o src/Queries/querie_6.o \
          src/Musics_Manager/musics.o src/Users_Manager/users.o src/Artists_Manager/artists.o \
          src/Users_Manager/users_manager.o src/Musics_Manager/musics_manager.o src/Artists_Manager/artists_manager.o \
          src/Artists_Manager/HT_Artists.o src/Musics_Manager/HT_Music.o src/Musics_Manager/TOP_Music.o \
          src/Users_Manager/HT_User.o src/Users_Manager/GR_User.o src/Albums_Manager/albums.o \
		  src/Albums_Manager/albums_manager.o src/Albums_Manager/HT_Albums.o src/History_Manager/history.o \
		  src/History_Manager/history_manager.o src/History_Manager/HT_LUS.o \
		  src/Iteratividade/iteratividade.o src/Iteratividade/querie_iter_1.o src/Iteratividade/querie_iter_2.o src/Iteratividade/querie_iter_3.o \
		  src/Iteratividade/querie_iter_4.o src/Iteratividade/querie_iter_5.o src/Iteratividade/querie_iter_6.o \
		  src/Artists_Manager/HT_ArtTOP.o src/testes.o

OBJ_ITERATIVO_FILES=src/main_iterativo.o src/parser.o src/utilidades.o src/general_manager.o \
		  src/Queries/querie_1.o src/Queries/querie_2.o src/Queries/querie_3.o src/Queries/querie_4.o \
		  src/Queries/querie_5.o src/Queries/querie_6.o \
		  src/Musics_Manager/musics.o src/Users_Manager/users.o src/Artists_Manager/artists.o \
		  src/Users_Manager/users_manager.o src/Musics_Manager/musics_manager.o src/Artists_Manager/artists_manager.o \
		  src/Artists_Manager/HT_Artists.o src/Musics_Manager/HT_Music.o src/Musics_Manager/TOP_Music.o \
		  src/Users_Manager/HT_User.o src/Users_Manager/GR_User.o src/Albums_Manager/albums.o \
		  src/Albums_Manager/albums_manager.o src/Albums_Manager/HT_Albums.o src/History_Manager/history.o \
		  src/History_Manager/history_manager.o src/History_Manager/HT_LUS.o \
		  src/Iteratividade/iteratividade.o src/Iteratividade/querie_iter_1.o src/Iteratividade/querie_iter_2.o src/Iteratividade/querie_iter_3.o \
		  src/Iteratividade/querie_iter_4.o src/Iteratividade/querie_iter_5.o src/Iteratividade/querie_iter_6.o \
		  src/Artists_Manager/HT_ArtTOP.o src/testes.o

# Regra principal
all: programa-principal

# Regra para gerar o executável principal
programa-principal: $(OBJ_FILES)
	$(CC) $^ $(LIBS)/recomendador-linux-x86_64.o $(GLIB_LDFLAGS) -o $@

# Regra principal testes
all : programa-testes

# Regra para gerar o executável de testes
programa-testes: $(OBJ_TESTES_FILES)
	$(CC) $^ $(LIBS)/recomendador-linux-x86_64.o $(GLIB_LDFLAGS) -o $@

# Regra principal iterativo
all : programa-iterativo

# Regra para gerar o executável iterativo
programa-iterativo: $(OBJ_ITERATIVO_FILES)
	$(CC) $^ $(LIBS)/recomendador-linux-x86_64.o $(GLIB_LDFLAGS) -o $@

# Regras para gerar os arquivos objeto
src/main.o: src/main.c
	$(CC) $(CFLAGS) $(GLIB_CFLAGS) -c -o $@ $<

src/parser.o: src/parser.c
	$(CC) $(CFLAGS) $(GLIB_CFLAGS) -c -o $@ $<

src/Queries/querie_1.o: src/Queries/querie_1.c
	$(CC) $(CFLAGS) $(GLIB_CFLAGS) -c -o $@ $<

src/Queries/querie_2.o: src/Queries/querie_2.c
	$(CC) $(CFLAGS) $(GLIB_CFLAGS) -c -o $@ $<

src/Queries/querie_3.o: src/Queries/querie_3.c
	$(CC) $(CFLAGS) $(GLIB_CFLAGS) -c -o $@ $<

src/Queries/querie_4.o: src/Queries/querie_4.c
	$(CC) $(CFLAGS) $(GLIB_CFLAGS) -c -o $@ $<

src/Queries/querie_5.o: src/Queries/querie_5.c
	$(CC) $(CFLAGS) $(GLIB_CFLAGS) -c -o $@ $<

src/Queries/querie_6.o: src/Queries/querie_6.c
	$(CC) $(CFLAGS) $(GLIB_CFLAGS) -c -o $@ $<

src/utilidades.o: src/utilidades.c
	$(CC) $(CFLAGS) $(GLIB_CFLAGS) -c -o $@ $<

src/general_manager.o: src/general_manager.c
	$(CC) $(CFLAGS) $(GLIB_CFLAGS) -c -o $@ $<

src/Musics_Manager/musics.o: src/Musics_Manager/musics.c
	$(CC) $(CFLAGS) $(GLIB_CFLAGS) -c -o $@ $<

src/Users_Manager/users.o: src/Users_Manager/users.c
	$(CC) $(CFLAGS) -c -o $@ $<

src/Artists_Manager/artists.o: src/Artists_Manager/artists.c
	$(CC) $(CFLAGS) -c -o $@ $<

src/Users_Manager/users_manager.o: src/Users_Manager/users_manager.c
	$(CC) $(CFLAGS) $(GLIB_CFLAGS) -c -o $@ $<

src/Musics_Manager/musics_manager.o: src/Musics_Manager/musics_manager.c
	$(CC) $(CFLAGS) $(GLIB_CFLAGS) -c -o $@ $<

src/Artists_Manager/artists_manager.o: src/Artists_Manager/artists_manager.c
	$(CC) $(CFLAGS) $(GLIB_CFLAGS) -c -o $@ $<

src/Artists_Manager/HT_Artists.o: src/Artists_Manager/HT_Artists.c
	$(CC) $(CFLAGS) $(GLIB_CFLAGS) -c -o $@ $<

src/Musics_Manager/HT_Music.o: src/Musics_Manager/HT_Music.c
	$(CC) $(CFLAGS) $(GLIB_CFLAGS) -c -o $@ $<

src/Musics_Manager/TOP_Music.o: src/Musics_Manager/TOP_Music.c
	$(CC) $(CFLAGS) $(GLIB_CFLAGS) -c -o $@ $<

src/Users_Manager/HT_User.o: src/Users_Manager/HT_User.c
	$(CC) $(CFLAGS) $(GLIB_CFLAGS) -c -o $@ $<

src/Users_Manager/GR_User.o: src/Users_Manager/GR_User.c
	$(CC) $(CFLAGS) $(GLIB_CFLAGS) -c -o $@ $<

src/main_testes.o: src/main_testes.c
	$(CC) $(CFLAGS) $(GLIB_CFLAGS) -c -o $@ $<

src/main_iterativo.o: src/main_iterativo.c
	$(CC) $(CFLAGS) $(GLIB_CFLAGS) -c -o $@ $<

src/Albums_Manager/albums.o: src/Albums_Manager/albums.c
	$(CC) $(CFLAGS) $(GLIB_CFLAGS) -c -o $@ $<

src/Albums_Manager/albums_manager.o: src/Albums_Manager/albums_manager.c
	$(CC) $(CFLAGS) $(GLIB_CFLAGS) -c -o $@ $<

src/Albums_Manager/HT_Albums.o: src/Albums_Manager/HT_Albums.c
	$(CC) $(CFLAGS) $(GLIB_CFLAGS) -c -o $@ $<

src/History_Manager/history.o: src/History_Manager/history.c
	$(CC) $(CFLAGS) $(GLIB_CFLAGS) -c -o $@ $<

src/History_Manager/history_manager.o: src/History_Manager/history_manager.c
	$(CC) $(CFLAGS) $(GLIB_CFLAGS) -c -o $@ $<

src/History_Manager/HT_LUS.o: src/History_Manager/HT_LUS.c
	$(CC) $(CFLAGS) $(GLIB_CFLAGS) -c -o $@ $<

src/Iteratividade/iteratividade.o: src/Iteratividade/iteratividade.c
	$(CC) $(CFLAGS) $(GLIB_CFLAGS) -c -o $@ $<

src/Iteratividade/querie_iter_1.o: src/Iteratividade/querie_iter_1.c
	$(CC) $(CFLAGS) $(GLIB_CFLAGS) -c -o $@ $<

src/Iteratividade/querie_iter_2.o: src/Iteratividade/querie_iter_2.c
	$(CC) $(CFLAGS) $(GLIB_CFLAGS) -c -o $@ $<

src/Iteratividade/querie_iter_3.o: src/Iteratividade/querie_iter_3.c
	$(CC) $(CFLAGS) $(GLIB_CFLAGS) -c -o $@ $<

src/Iteratividade/querie_iter_4.o: src/Iteratividade/querie_iter_4.c
	$(CC) $(CFLAGS) $(GLIB_CFLAGS) -c -o $@ $<

src/Iteratividade/querie_iter_5.o: src/Iteratividade/querie_iter_5.c
	$(CC) $(CFLAGS) $(GLIB_CFLAGS) -c -o $@ $<

src/Iteratividade/querie_iter_6.o: src/Iteratividade/querie_iter_6.c
	$(CC) $(CFLAGS) $(GLIB_CFLAGS) -c -o $@ $<

src/Artists_Manager/HT_ArtTOP.o: src/Artists_Manager/HT_ArtTOP.c
	$(CC) $(CFLAGS) $(GLIB_CFLAGS) -c -o $@ $<

src/testes.o: src/testes.c
	$(CC) $(CFLAGS) $(GLIB_CFLAGS) -c -o $@ $<

# Regra de limpeza
clean:
	rm -f src/*.o src/Iteratividade/*.o src/Queries/*.o src/Albums_Manager/*.o src/History_Manager/*.o src/Musics_Manager/*.o src/Users_Manager/*.o src/Artists_Manager/*.o programa-principal programa-testes programa-iterativo
