//
// Created by HichTala on 24/06/25.
//

#ifndef DRAW_H
#define DRAW_H

#include <obs-module.h>

enum input_type { INPUT_TYPE_SOURCE, INPUT_TYPE_SCENE };

struct draw_source_data {
	enum input_type input_type;

	// Detector channel (1 or 2). Selects which shared-memory pair this source
	// uses, so two detectors (one per player) can run at the same time.
	int channel;

	// Crop applied to the captured input before it is sent to the detector
	// (pixels removed from each edge). Lets the user focus detection on a
	// region of the camera without affecting the source elsewhere.
	uint32_t crop_left;
	uint32_t crop_top;
	uint32_t crop_right;
	uint32_t crop_bottom;

	// Rotate the captured input 180° before sending it to the detector
	// (useful when the camera is mounted upside down). Detector-only.
	bool rotate_180;

	obs_weak_source_t *source;

	void *region;
	void *shared_frame;
	size_t shared_frame_size;
	uint32_t source_width;
	uint32_t source_height;

	gs_texrender_t *render;
	gs_stagesurf_t *stage;
	uint32_t stage_width;
	uint32_t stage_height;
	gs_texture_t *display_texture;
	uint32_t display_width;
	uint32_t display_height;
	bool processing;
};
typedef struct draw_source_data draw_source_data_t;

extern struct obs_source_info draw_source;

#endif //DRAW_H
