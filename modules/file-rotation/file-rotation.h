/*
 * Copyright (c) 2022 Shikhar Vashistha
 * Copyright (c) 2022 László Várady
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published
 * by the Free Software Foundation, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * As an additional exemption you are allowed to compile & link against the
 * OpenSSL libraries as published by the OpenSSL project. See the file
 * COPYING for details.
 *
 */

#ifndef FILE_ROTATION_H_INCLUDED
#define FILE_ROTATION_H_INCLUDED

#include "syslog-ng.h"
#include "driver.h"
#include "signal-slot-connector/signal-slot-connector.h"

typedef struct _FileRotationPlugin FileRotationPlugin;

typedef enum
{
  FILE_ROTATION_SUCCESS,
  FILE_ROTATION_FAILURE,
} FileRotationResult;

struct _FileRotationPlugin
{
  LogDriverPlugin super;
  SignalSlotConnector *ssc;
  gchar *interval;
  GList *file_names;
  gsize number_of_file_rotations;
  gsize number_of_time_rotated;
  gchar *date_format;
  gsize size;
  gchar *filename;
};

FileRotationPlugin *file_rotation_new(void);

void file_rotation_set_size(FileRotationPlugin *self, gsize size);
void file_rotation_set_interval(FileRotationPlugin *self, gchar *interval);
void file_rotation_set_date_format(FileRotationPlugin *self, gchar *date_format);
void file_rotation_set_number_of_file_rotatations(FileRotationPlugin *self, gsize rotate);
void process_file_removal(FileRotationPlugin *self, const gchar *filename);

#endif
