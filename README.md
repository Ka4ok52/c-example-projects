# C Example Projects
[![C Build & Test](https://github.com/Ka4ok52/c-example-projects/actions/workflows/build.yml/badge.svg)](https://github.com/Ka4ok52/c-example-projects/actions/workflows/build.yml) \
A project with examples of using `make`. \
> **Important:**
> 1. Run `make` from the project root! \
> 2. If you want to compile the example, move the source code to the `src` directory, as that is where `make` gathers the template code from! \
> 3. Run `make clean` before building with other flags!

---

## Makefile

### Command

| Command | Description |
| :--- | :--- |
| `make` / `make build` | Compiling the project (by default, the `Main` binary is created) |
| `make run` | Building and automatically launching the program|
| `make clean` | Removing compiled object files (`objs/`) and the binary |

---

### Build Variables and Flags

You can override variables directly during the `make` call, for example: \
Launching a release build without debugging, using a different binary name.
```bash
make run NAME=App DEBUG=0
```

| Variables | Default | Description | Example |
| :--- | :--- | :--- | :--- |
| `NAME` | `Main` | Name of the final executable file | `make NAME=App` |
| `DEBUG` | `1` | Build mode: `1` — with debug, `0` — without debug | `make DEBUG=0` |
| `CC` | `gcc` | The C compiler used | `make CC=clang` |
| `CFLAGS` | `-Wall -Wextra -std=c11` | Compilation flags | `make CFLAGS="-O3"` |

---

## Project structure

```text
.
├── Makefile
├── objs/
└── src/
    └── main.c
```
