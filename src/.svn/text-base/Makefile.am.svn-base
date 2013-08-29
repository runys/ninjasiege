# Author: Edson Alves - edsonalves@unb.br
# Date: 21/12/2012

# Library description
lib_LTLIBRARIES = 

# Programs excluded from instalation
bin_PROGRAMS = ninjasiege

# Library flags
# libitem_la_LDFLAGS = -static

# Library sources
# libitem_la_SOURCES = 

# Libraries needed to build our library
# libitem_la_LIBADD = 

# Program description
ninjasiege_SOURCES = main.cpp mapa.cpp jogo.cpp tela.cpp escutavel.cpp tempo.cpp ambiente.cpp \
					 jogo_detectarSaidaAplicativo.cpp jogo_detectarTodosEventos.cpp jogo_estadoEntradaJogo.cpp \
					 jogo_estadoFimJogo.cpp jogo_estadoJogando.cpp jogo_estadoMenuJogo.cpp \
					 jogo_estadoSairAplicativo.cpp jogo_desenharTudo.cpp \
					 torre.cpp inimigo.cpp fading.cpp jogo_fazerTodaLogica.cpp \
					 mestre.cpp wave.cpp ataque.cpp \
					 util.cpp botao.cpp hud.cpp jogo_estadosInternos.cpp menuprincipal.cpp

# Libraries needed to build program
ninjasiege_LDADD = -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -lm

# Include flags
INCLUDES = -I../include -Wall -Wno-long-long -W -pedantic -ansi

