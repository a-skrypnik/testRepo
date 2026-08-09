# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Overview

This is a small, single-translation-unit C++17 sandbox for experimenting with
`std::variant`/`std::visit` and observing C++ value-semantics (copy vs. move
construction, object lifetime) via console logging. It is not a library or
application with a build system — it's a scratch project.

## Build & Run

There is no build system (no CMake/Makefile). Compile directly with a C++17
capable compiler:

```bash
g++ -std=c++17 main.cpp -o main && ./main
# or
clang++ -std=c++17 main.cpp -o main && ./main
```

C++17 is required: the code uses fold expressions (`print`) and structured
bindings (`for (auto& [a, b] : m)`).

There are no tests and no linter configured in this repo.

## Code Structure

- `main.cpp` — entry point. Defines a variadic `print()` helper, builds a
  `std::vector<std::variant<A, B>>`, and exercises it via `std::visit`.
- `AorB/A.hpp`, `AorB/B.hpp` — near-identical header-only classes (`A` and
  `B`). Each has a static per-class instance counter (`NUMBER_OF_OBJECTS`)
  used to assign an `id` to every instance, and every special member
  (default ctor, copy ctor, move ctor, `const`-rvalue ctor, dtor) logs to
  `std::cout` when invoked. Both also expose `draw()`. This logging is the
  whole point of the classes: running `main` prints a trace of exactly when
  objects are constructed, copied, moved, and destroyed as they're placed
  into and drawn from the vector.
- `xeus-cling-0.15.3-he80cb83_2.conda` — a prebuilt conda package for the
  xeus-cling Jupyter C++ kernel, present in the repo (not built from source
  here).

## Conventions

- `A` and `B` are deliberately parallel/duplicated implementations — when
  changing behavior in one, check whether the same change belongs in the
  other.
- New "drawable" types intended for the `AorB` variant should follow the
  same shape: default/copy/move constructors that log their action and
  assigned `id`, plus a `draw()` method, so traces stay comparable across
  types.
