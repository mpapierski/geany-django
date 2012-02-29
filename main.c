/*
 *      GeanyDjango - Manage your Django projects in Geany.
 *
 *      Copyright 2012 Michał Papierski <michal(at)papierski(dot)net>
 *
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 *
 */
#include <assert.h>

#include <geanyplugin.h>

#include "geany_django.h"

static GeanyPlugin* geany_plugin;
static GeanyData* geany_data;
static GeanyFunctions* geany_functions;

PLUGIN_VERSION_CHECK(GEANY_API_VERSION)
PLUGIN_SET_INFO(
	"GeanyDjango",
	"Manage Django project in Geany",
	"0.1",
	"Michał Papierski <michal@papierski.net>");

/**
 *  Plugin code
 */
static geany_django_t* plugin_data = NULL;

static void on_about(geany_django_t* that)
{
	GtkWidget* dialog;
	GeanyData* geany_data = that->geany_data;

	assert(!!that);
	assert(that == plugin_data);

	/* I have issues with dialogs_show_msgbox */

	dialog = gtk_message_dialog_new(
		GTK_WINDOW(geany->main_widgets->window),
		GTK_DIALOG_DESTROY_WITH_PARENT,
		GTK_MESSAGE_INFO,
		GTK_BUTTONS_OK,
		"Help");
	gtk_window_set_title(GTK_WINDOW(dialog),
		"GeanyDjango");
	gtk_message_dialog_format_secondary_text(GTK_MESSAGE_DIALOG(dialog),
		"A tool which helps you in development of your Django projects.");
	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);
}


/**
 * On plugin init
 */
void plugin_init(GeanyData* data)
{
    /* Init */
	plugin_data = plugin_data_new(data);
	plugin_data->on_about = &on_about;
	plugin_data_setup(plugin_data);	
}

/**
 * On plugin unload
 */
void plugin_cleanup(void)
{
    /* Cleanup */
	plugin_data_dispose(&plugin_data);
}

/**
 * Plugin help
 */
void plugin_help(void)
{
	on_about(plugin_data);
}
