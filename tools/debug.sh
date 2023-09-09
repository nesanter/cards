#!/bin/bash
export ASAN_OPTIONS=fast_unwind_on_malloc=0
export LSAN_OPTIONS=suppressions=suppress.txt
./main

