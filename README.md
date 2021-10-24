On setting up:

The student will need to have the raylib folder installed on their C drive. This is important, as the .vscode files depend on this in order to have a working path to the g++ compiler in raylib.

The student will need to select the correct compiler by going to Terminal -> Configure Default Build Task, then selecting C:\raylib\mingw\bin\g++.exe. This will ensure that the compiler g++ that comes with raylib is used for this project.

The .vscode files included with this project must be in the .vscode folder for the student's project, as they ensure that raylib is a known path and including raylib.h will not result in a compilation error. The student must use these files and not the ones that come with raylib, as those aren't configured to compile the project as C++, so including C++ libraries would fail.
