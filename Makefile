##-----------------------------LICENSE NOTICE------------------------------------
##  This file is part of CPCtelera: An Amstrad CPC Game Engine
##  Copyright (C) 2015 ronaldo / Fremos / Cheesetea / ByteRealms (@FranGallegoBR)
##
##  This program is free software: you can redistribute it and/or modify
##  it under the terms of the GNU General Public License as published by
##  the Free Software Foundation, either version 3 of the License, or
##  (at your option) any later version.
##
##  This program is distributed in the hope that it will be useful,
##  but WITHOUT ANY WARRANTY; without even the implied warranty of
##  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
##  GNU General Public License for more details.
##
##  You should have received a copy of the GNU General Public License
##  along with this program.  If not, see <http://www.gnu.org/licenses/>.
##------------------------------------------------------------------------------

###########################################################################
##                          CPCTELERA ENGINE                             ##
##                  Main Building Makefile for Projects                  ##
##-----------------------------------------------------------------------##
## This file contains the rules for building a CPCTelera project. These  ##
## These rules work generically for every CPCTelera project.             ##
## Usually, this file should be left unchanged:                          ##
##  * Project's build configuration is to be found in build_config.mk    ##
##  * Global paths and tool configuration is located at $(CPCT_PATH)/cfg/##
###########################################################################

##
## PROJECT CONFIGURATION (you may change things there to setup this project)
##
include cfg/build_config.mk

##
## USE GLOBAL MAKEFILE (general rules for building CPCtelera projects)
##
include $(CPCT_PATH)/cfg/global_main_makefile.mk


##
## CREATING ASSETS
##
PALETE={ 0 2 3 5 6 8 9 11 13 14 15 16 20 22 24 26 }
generate_assets:
	cd src/assets &&\
	cpct_img2tileset -m 0 -tw 140 -th 40 -pf $(PALETE) caliv.png &&\
	cpct_img2tileset -m 0 -tw 136 -th 36 -pf $(PALETE) games.png
#	cpct_img2tileset -m 0 -tw 8 -th 8 -pf $(PALETE) skate.png
#	mv src/assets/*.c src/assets/*.h src/
#	cpct_img2tileset -m 0 -tw 4 -th 4 -pf $(PALETE) tiles_bg.png &&\
#	cpct_img2tileset -m 0 -tw 110 -th 93 -pf $(PALETE) alce.png &&\
#	cpct_img2tileset -m 0 -tw 8 -th 8 -pf $(PALETE) tiles.png &&\
#	cpct_img2tileset -m 0 -im 0 -tw 16 -th 24 -pf $(PALETE) player.png &&\
#	cpct_img2tileset -m 0 -tw 8 -th 8 -pf $(PALETE) car.png &&\
#	cpct_img2tileset -m 0 -tw 8 -th 32 -pf $(PALETE) wallwindow32.png
