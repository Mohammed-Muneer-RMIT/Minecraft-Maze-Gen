# Maze Generator & Solver (C++)

Interactive, menu-driven program to **generate**, **visualise**, and **solve** mazes from the terminal.  
Written in modern C++ and organised into small, testable components.

## Features
- Multiple generation & solving agents
- Reproducible mazes via seeds
- Step-through / delay controls
- Save/restore maze state
- Clean separation of **maze model** (`Maze.*`) and **runner/UI** (`mazeRunner.cpp`, `menuUtils.h`)

## Repo Structure
.
├─ Maze.h / Maze.cpp            # Maze grid + carve/query helpers  
├─ Agent.h / Agent.cpp          # Base agent (gen/solve behaviours)  
├─ mazeRunner.cpp               # Entry point (menu-driven UI)  
├─ menuUtils.h                  # Helpers for menus/printing  
├─ DelayCarpet.h                 # Timing/animation throttling  
├─ restore.h                     # Save/restore helpers  
├─ Makefile                      # Build script  
├─ *.o / buildFile*              # Build artifacts  
├─ .DS_Store / *.Identifier      # macOS metadata (ignore)  
└─ README.md  

## Build

**Option A — Makefile**
```bash
make           # builds the default target
./mazeRunner   # run
```

**Option B- Direct g++(fallback)**
g++ -std=c++17 -O2 -Wall \
  Maze.cpp Agent.cpp mazeRunner.cpp \
  -o mazeRunner
./mazeRunner

Run
Launch and use the on-screen menu:
./mazeRunner



Typical flow:

Create maze – choose width/height and optionally seed
Select generator – choose algorithm
Visualise – step through with delays
Solve – pick a solver (BFS/DFS/A*, etc.)
Save / Restore – store and reload maze state

Configuration
Dimensions: choose from menu (e.g., 21×21, 51×51)
Seed: integer for reproducible maze
Delay: control animation speed

Roadmap
 More generation algorithms
 A* solver with heuristics
 JSON export for visualisers
 Unit tests
 Optional Minecraft exporter
