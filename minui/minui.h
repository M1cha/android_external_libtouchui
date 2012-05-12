/*
 * Copyright (C) 2007 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _MINUI_H_
#define _MINUI_H_

#include <stdlib.h>
#include <stdbool.h>
#include <linux/fb.h>
#include <pixelflinger/pixelflinger.h>

#if defined(PIXELS_BGRA)
# define PIXEL_FORMAT GGL_PIXEL_FORMAT_BGRA_8888
# define PIXEL_SIZE   4
#elif defined(PIXELS_RGBA)
# define PIXEL_FORMAT GGL_PIXEL_FORMAT_RGBA_8888
# define PIXEL_SIZE   4
#elif defined(PIXELS_RGBX)
# define PIXEL_FORMAT GGL_PIXEL_FORMAT_RGBX_8888
# define PIXEL_SIZE   4
#elif defined(PIXELS_BGR_16BPP)
# define PIXEL_FORMAT GGL_PIXEL_FORMAT_RGB_565
# define PIXEL_SIZE   2
# define COLORS_REVERSED
#else
# define PIXEL_FORMAT GGL_PIXEL_FORMAT_RGB_565
# define PIXEL_SIZE   2
#endif

typedef void* gr_surface;
typedef unsigned short gr_pixel;

int gr_init(void);
void gr_exit(void);
struct fb_fix_screeninfo* gr_get_fb_fix_screeninfo();

int gr_fb_width(void);
int gr_fb_height(void);
gr_pixel *gr_fb_data(void);
void gr_flip(void);
void gr_fb_blank(bool blank);

void gr_color(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
void gr_fill(int x, int y, int w, int h);
int gr_text(int x, int y, const char *s);
int gr_measure(const char *s);
void gr_font_size(int *x, int *y);

void gr_blit(gr_surface source, int sx, int sy, int w, int h, int dx, int dy);
unsigned int gr_get_width(gr_surface surface);
unsigned int gr_get_height(gr_surface surface);
GGLSurface* gr_get_surface();


// input event structure, include <linux/input.h> for the definition.
// see http://www.mjmwired.net/kernel/Documentation/input/ for info.
struct input_event;

int ev_init(void);
void ev_exit(void);
int ev_get(struct input_event *ev, unsigned dont_wait);

// Resources
#ifndef RES_IMAGES_FOLDER
#define RES_IMAGES_FOLDER "/system/bootmenu/images"
#endif

// Returns 0 if no error, else negative.
int res_create_surface(const char* name, gr_surface* pSurface);
void res_free_surface(gr_surface* pSurface);

int gr_fb_test(void);

// Vibrator
int vibrate(int timeout_ms);

#define VIBRATOR_TIME_MS        22
#define VIBRATOR_HARD_MS        41
#endif
