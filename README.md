#Maze Generator & Solver (C++)


Interactive, menu-driven program to generate, visualise, and solve mazes from the terminal.
Written in modern C++ and organised into small, testable components.

This README matches the files currently in this repo (e.g., Maze.cpp/.h, Agent.cpp/.h, mazeRunner.cpp, menuUtils.h, Makefile).

Features
Multiple generation & solving “agents” (see Agent* files)
Reproducible mazes via seeds
Step-through / delay controls (see DelayCarpet.h)
Save/restore maze state (see restore.h)
Clean separation of maze model (Maze.*) and runner/UI (mazeRunner.cpp, menuUtils.h)

Repo Structure
bash
Copy
Edit
.
├─ Maze.h / Maze.cpp            # Maze grid + carve/query helpers
├─ Agent.h / Agent.cpp          # Base agent (gen/solve behaviours)
├─ AgentNo.* (if present)       # Additional agent variants
├─ mazeRunner.cpp               # Entry point (menu-driven UI)
├─ menuUtils.h                  # Small helpers for menus/printing
├─ DelayCarpet.h                # Timing/animation throttling
├─ restore.h                    # Save/restore helpers
├─ Makefile                     # Build script
├─ buildFile.* / *.o            # Build artifacts (can be ignored)
├─ *.Identifier / .DS_Store     # macOS metadata (safe to ignore)
└─ README.md
Build
Option A — Makefile (recommended)
bash
Copy
Edit
make           # builds the default target (e.g., mazeRunner)
./mazeRunner   # run
Option B — Direct g++ (fallback)
bash
Copy
Edit
g++ -std=c++17 -O2 -Wall \
  Maze.cpp Agent.cpp mazeRunner.cpp \
  -o mazeRunner
./mazeRunner
If you add more .cpp files (e.g., AgentX.cpp), include them in the command or the Makefile.

Run
The program is interactive. Launch and use the on-screen menu:

bash
Copy
Edit
./mazeRunner
Typical flow (menu options may vary depending on your build):

Create maze – choose width/height and (optionally) seed.

Select generator – e.g., DFS/backtracker, Prim, etc.

Visualise – step through with delays (uses DelayCarpet.h).

Solve – pick a solver (BFS/DFS/A* if implemented).

Save / Restore – write/read state (via restore.h).

If “seed” is offered, use it to reproduce the same maze again.

Controls (common)
Enter to confirm a menu item

Numbers/letters to pick options

Esc/Ctrl-C to exit (or choose “Quit”)

(Exact keys depend on how menuUtils.h is wired; this section is intentionally generic.)

Configuration
Dimensions: choose from the menu (common sizes: 21×21, 51×51, etc.).

Seed: enter an integer to reproduce the maze later.

Delay: increase/decrease animation speed if step-through is enabled.

Implementation Notes
Maze holds the grid and exposes helpers to add/remove walls, query neighbors, and mark paths.

Agent encapsulates traversal logic (both generation and solving variants live here or in derived classes).

mazeRunner.cpp is the UI shell that orchestrates the flow and calls into Maze/Agent.

DelayCarpet.h provides simple timing for animations.

restore.h centralises save/load of state so you can pause & resume.

Roadmap
 Add more generation algorithms (Kruskal, Recursive Division)

 Add A* solver with Manhattan/Euclidean heuristics

 Export to JSON for external visualisers

 Unit tests for Maze and Agent behaviours

 Optional exporter to Minecraft (.mcfunction / .schem)

Development
Rebuild from scratch:

bash
Copy
Edit
make clean && make
Suggested .gitignore additions:

markdown
Copy
Edit
# Build artifacts
*.o
buildFile*
mazeRunner
# macOS metadata
.DS_Store
*.Identifier
License
MIT — do whatever you want, just keep the notice.

Acknowledgements
Built for coursework/practice; inspired by classic maze-generation and pathfinding algorithms.
