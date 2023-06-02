#include "anim.h"

static void anim_set_x(void *obj, int32_t v)
{
    lv_obj_set_x(obj, v);
}

static void anim_set_size(void *obj, int32_t v)
{
    lv_obj_set_size(obj, v, v);
}

void example_anim_2(void)
{
    lv_obj_t *obj = lv_obj_create(lv_scr_act());
    lv_obj_set_style_radius(obj, LV_RADIUS_CIRCLE, LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(obj, lv_palette_main(LV_PALETTE_RED), LV_STATE_DEFAULT);
    lv_obj_set_align(obj, LV_ALIGN_LEFT_MID);
    lv_anim_t anim;
    lv_anim_init(&anim);
    lv_anim_set_var(&anim, obj);
    lv_anim_set_values(&anim, 10, 50);
    lv_anim_set_time(&anim, 1000);
    lv_anim_set_playback_delay(&anim, 100);
    lv_anim_set_playback_time(&anim, 300);
    lv_anim_set_repeat_delay(&anim, 500);
    lv_anim_set_repeat_count(&anim, LV_ANIM_REPEAT_INFINITE);
    lv_anim_set_path_cb(&anim, lv_anim_path_ease_in_out);

    lv_anim_set_exec_cb(&anim, anim_set_size);
    lv_anim_start(&anim);
    lv_anim_set_values(&anim, 10, 240);
    lv_anim_set_exec_cb(&anim, anim_set_x);
    lv_anim_start(&anim);
}