 /*
 * app.c -- main
 */

#include <stdio.h>

#include <app.h>

GtkApplication* app;

static void
activate(GtkApplication *app, gpointer user_data)
{
	(void)user_data;

	GtkWidget *window;
	GtkWidget *textview;

	window = gtk_application_window_new(app);

	gtk_window_set_title(GTK_WINDOW(window), "ULTRACALC");
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 200);

	textview = gtk_text_view_new();

	gtk_text_view_set_wrap_mode(
	    GTK_TEXT_VIEW(textview),
	    GTK_WRAP_WORD
	);

	gtk_container_add(
	    GTK_CONTAINER(window),
	    textview
	);

	gtk_widget_show_all(window);
}

int
run(int argc, char** argv)
{
	int status;
	
	puts("ultracalc - hello!");
#if GLIB_CHECK_VERSION(2, 74, 0)
	app = gtk_application_new(NULL, G_APPLICATION_DEFAULT_FLAGS);
#else
	app = gtk_application_new(NULL, G_APPLICATION_FLAGS_NONE);
#endif
	g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
	status = g_application_run(G_APPLICATION(app), 0, NULL);
	g_object_unref(app);

	return status;
}
