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
#if !defined(GEANY_DJANGO_H)
#define GEANY_DJANGO_H

#include <geanyplugin.h>

/**
 * Main plugin structure
 */
typedef struct geany_django_t
{
	/**
 	 * About callback
 	 */
	void (*on_about)(struct geany_django_t* /* this */);

	/**
 	 * Geany data
 	 */
	GeanyData* geany_data;

	/**
 	 * Plugin main menu
 	 */
	GtkWidget* main_menu_item;
} geany_django_t;

/**
 * Create new geany_django_t structure
 * @param geany_data Geany data
 * @return Filled in geany_django plugin structure.
 */
geany_django_t* plugin_data_new(GeanyData* geany_data);

/**
 * Dispose geany_django plugin data
 * @param plugin_data Pointer to plugin data structure pointer
 */
void plugin_data_dispose(geany_django_t** plugin_data);

/**
 * Setup plugin data (create widgets, etc)
 * @param Not-null plugin data structure
 */
void plugin_data_setup(geany_django_t* plugin_data);

#endif
