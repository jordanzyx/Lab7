#include <stdio.h>
#include "header.h"

int main() {

    FILE *infile = NULL;
    FILE *outfile = NULL;

    infile = fopen("C:\\Users\\Jordan\\CLionProjects\\Lab7\\input.txt","r");
    outfile = fopen("C:\\Users\\Jordan\\CLionProjects\\Lab7\\output.txt","w");

    solve(infile,outfile);

    return 0;
}