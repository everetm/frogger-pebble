/*  Frogger for pebble game
 *  All arkwork made by Mason Everett
 *  mdawg.me
 */

#include <pebble.h>
  
static Window *s_main_window;
static GBitmap *s_bitmap;
static BitmapLayer *s_bitmap_layer;
static void game_start();

static void main_window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);
  
  s_bitmap = gbitmap_create_with_resource(RESOURCE_ID_BACKGROUND2);
  
  s_bitmap_layer = bitmap_layer_create(bounds);
  bitmap_layer_set_bitmap(s_bitmap_layer, s_bitmap);
  layer_add_child(window_layer, bitmap_layer_get_layer(s_bitmap_layer));
  game_start(window);
}
static void main_window_unload(Window* window) {
  bitmap_layer_destroy(s_bitmap_layer);
  gbitmap_destroy(s_bitmap);
}
static void game_start(Window* window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);
  
  s_bitmap = gbitmap_create_with_resource(RESOURCE_ID_FROGF_BLACK);
  
  s_bitmap_layer = bitmap_layer_create(bounds);
  bitmap_layer_set_bitmap(s_bitmap_layer, s_bitmap);
  bitmap_layer_set_alignment(s_bitmap_layer, 4);
  layer_add_child(window_layer, bitmap_layer_get_layer(s_bitmap_layer));
  
}

static void init(void) {
  s_main_window = window_create();
  window_set_fullscreen(s_main_window,true);
  window_set_window_handlers(s_main_window,(WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });
  const bool animated = true;
  window_stack_push(s_main_window, animated);
}

static void deinit(void) {
  window_destroy(s_main_window);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
