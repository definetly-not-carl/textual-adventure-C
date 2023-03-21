#include <string.h>
#define NOBUILD_IMPLEMENTATION
#include "./nobuild.h"

#define LIBS "-I./src/headers/headers"

void compile(void){
    RM("exec_this");;
    CMD("gcc", "-o", "exec_this", LIBS, "./txt.c", "./src/headers/implementation/NewFunctions.c", "./src/headers/implementation/NewInteractions.c", "./src/headers/implementation/interface.c");
    INFO("Ora esegui exec_this - eventualmente con flag degug");
}

void debug(void){
    compile();
    CMD("./exec_this","debug");
    RM("exec_this");
}

int main(int argc, char **argv){
    GO_REBUILD_URSELF(argc, argv);
    INFO("Hi there, we are creating this file in order to let you build only one file that will compile everything dor you!");
    compile();
    const char *program = shift_args(&argc, &argv);
    if (argc>0) {
        const char *subcmd = shift_args(&argc, &argv);
        if (strcmp(subcmd, "run")==0) {
            CMD("./exec_this");
        } else if (strcmp(subcmd, "debug")==0) {
            debug();
        }
    } else {
        INFO("Ran without arguments");
    }
    return 0;
}