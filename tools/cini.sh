#!/bin/bash
# Copyright © 2023 Noah Santer <n.ed.santer@gmail.com>
#
# This file is part of cards.
#
# cards is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# cards is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with cards.  If not, see <https://www.gnu.org/licenses/>.

[ -d cini.gen/cini ] && rm -rf cini.gen/cini

git clone https://github.com/nesanter/cini cini.gen/cini &&
    cp cini.gen/cini/include/ini/{ini.h,map.h,opts.h,table.h} cini.gen/include/ini &&
    cp cini.gen/cini/src/{ini.c,map.c,handle.c,table.c} cini.gen/src
