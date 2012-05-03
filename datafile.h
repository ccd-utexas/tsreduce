/*
 * Copyright 2010, 2011, 2012 Paul Chote
 * This file is part of Puoko-nui, which is free software. It is made available
 * to you under the terms of version 3 of the GNU General Public License, as
 * published by the Free Software Foundation. For more information, see LICENSE.
 */

#include "aperture.h"

#ifndef DATAFILE_H
#define DATAFILE_H

// Maximum number of frames to load when creating a flat or dark frame
#define MAX_FRAMES 100

// Maximum number of observations to process in a single run
#define MAX_OBS 10000

// Maximum number of targets to track
#define MAX_TARGETS 10

// Maximum number of ranges to block
#define MAX_BLOCKED_RANGES 10

// Maximum length of the header keys (except for the framedir path)
// If you change this, you must change the sscanf lines to match
#define HEADER_MAXLENGTH 128

typedef struct
{
    double star[MAX_TARGETS];
    double sky[MAX_TARGETS];
    double2 pos[MAX_TARGETS];
    double time;
    double ratio;
    char filename[64];
} record;

typedef struct
{
    FILE *file;
    int version;
    char frame_dir[PATH_MAX];
    char frame_pattern[HEADER_MAXLENGTH];
    char dark_template[HEADER_MAXLENGTH];
    char flat_template[HEADER_MAXLENGTH];
    target targets[MAX_TARGETS];
    int num_targets;
    time_t reference_time;
    
    record obs[MAX_OBS];
    int num_obs;
    int plot_fit_degree;
    double plot_max_raw;
    int plot_num_uhz;
    double plot_min_uhz;
    double plot_max_uhz;
    
    double2 blocked_ranges[MAX_BLOCKED_RANGES];
    int num_blocked_ranges;
    
} datafile;

datafile load_reduced_data(char *dataFile);

#endif