/*
	VitaShell
	Copyright (C) 2015-2016, TheFloW

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __IO_PROCESS_H__
#define __IO_PROCESS_H__

#include "file.h"

#define COPY_MODE_NORMAL 0
#define COPY_MODE_MOVE 1
#define COPY_MODE_EXTRACT 2

#define SPLIT_SUFFIX ".SPLIT"
#define SPLIT_SIZE_NAME "SIZE"
#define SPLIT_PART_SIZE (256 * 1024)
#define SPLIT_MAX_FILES 512

typedef struct {
	uint32_t max;
} UpdateArguments;

typedef struct {
	FileList *file_list;
	FileList *mark_list;
	int index;
} DeleteArguments;

typedef struct {
	FileList *file_list;
	FileList *copy_list;
	char *archive_path;
	int copy_mode;
} CopyArguments;

typedef struct {
	FileList *file_list;
	int index;
} SplitArguments;

typedef struct {
	FileList *file_list;
	int index;
} JoinArguments;

int delete_thread(SceSize args_size, DeleteArguments *args);
int copy_thread(SceSize args_size, CopyArguments *args);
int split_thread(SceSize args_size, SplitArguments *args);
int join_thread(SceSize args_size, JoinArguments *args);

#endif