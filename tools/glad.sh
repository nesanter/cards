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

GLADFLAGS="--generator=c --profile core --out-path=glad.gen"

python -m venv glad.gen/venv && \
./glad.gen/venv/bin/pip -q install glad && \
./glad.gen/venv/bin/python -m glad $GLADFLAGS --quiet
