/*
 * plugin.c -- plugin for hotwrap
 *
 * Hotwrap is an utility that lets modules (.so files with a plugin_main_impl)
 * to hot-reload.
 *
 * This project is built as both a library and a binary for this reason.
 */

#include <app.h>

int
plugin_main_impl(int argc, char** argv)
{
	run();
	return 0;
}

