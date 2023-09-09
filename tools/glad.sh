
GLADFLAGS="--generator=c --profile core --out-path=glad.gen"

python -m venv glad.gen/venv && \
./glad.gen/venv/bin/pip -q install glad && \
./glad.gen/venv/bin/python -m glad $GLADFLAGS --quiet
