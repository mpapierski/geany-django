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
#include <stdlib.h>
#include "geany_django.h"

geany_django_t* plugin_data_new(GeanyData* data)
{
	geany_django_t* result = (geany_django_t*)calloc(1, sizeof(geany_django_t));
	result->geany_data = data;
	return result;
}

void plugin_data_dispose(geany_django_t** data)
{
	gtk_widget_destroy((*data)->main_menu_item);
	free(*data);
}

static void callback_wrapper_cb(GtkMenuItem* menuitem, gpointer gdata)
{
	geany_django_t* that = gdata;
	if ((GtkWidget*)menuitem == that->main_menu_item)
		(*that->on_about)(that);
}

void plugin_data_setup(geany_django_t* plugin_data)
{
	GeanyData* geany_data = plugin_data->geany_data; /* GTK_CONTAINER needs this */

	plugin_data->main_menu_item = gtk_menu_item_new_with_mnemonic("GeanyDjango");
	gtk_widget_show(plugin_data->main_menu_item);
	gtk_container_add(GTK_CONTAINER(geany->main_widgets->tools_menu), plugin_data->main_menu_item);
	g_signal_connect(plugin_data->main_menu_item, "activate",
			G_CALLBACK(callback_wrapper_cb), plugin_data);
}
