/*
 * main.c -- main
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <arg>\n", argv[0]);
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
