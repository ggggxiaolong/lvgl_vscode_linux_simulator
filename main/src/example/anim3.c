#include "anim.h"

static const lv_coord_t obj_width = 90;
static const lv_coord_t obj_height = 70;
static lv_obj_t *obj1 = NULL, *obj2 = NULL, *obj3 = NULL;
static lv_anim_timeline_t *anim_time_line = NULL;

static anim_set_height(void *obj, int32_t val)
{
    lv_obj_set_height(obj, val);
}

static anim_set_width(void *obj, int32_t val)
{
    lv_obj_set_width(obj, val);
}

static void anim_timeline_create(void)
{
    lv_anim_t a1;
    lv_anim_init(&a1);
    lv_anim_set_var(&a1, obj1);
    lv_anim_set_values(&a1, 0, obj_width);
    // 是够立刻生效
    lv_anim_set_early_apply(&a1, false);
    lv_anim_set_exec_cb(&a1, (lv_anim_exec_xcb_t)anim_set_width);
    lv_anim_set_path_cb(&a1, lv_anim_path_overshoot);
    lv_anim_set_time(&a1, 300);

    lv_anim_t a2;
    lv_anim_init(&a2);
    lv_anim_set_var(&a2, obj1);
    lv_anim_set_values(&a2, 0, obj_height);
    // 是够立刻生效
    lv_anim_set_early_apply(&a2, false);
    lv_anim_set_exec_cb(&a2, (lv_anim_exec_xcb_t)anim_set_height);
    lv_anim_set_path_cb(&a2, lv_anim_path_ease_out);
    lv_anim_set_time(&a2, 300);

    lv_anim_t a3;
    lv_anim_init(&a3);
    lv_anim_set_var(&a3, obj2);
    lv_anim_set_values(&a3, 0, obj_width);
    // 是够立刻生效
    lv_anim_set_early_apply(&a3, false);
    lv_anim_set_exec_cb(&a3, (lv_anim_exec_xcb_t)anim_set_width);
    lv_anim_set_path_cb(&a3, lv_anim_path_overshoot);
    lv_anim_set_time(&a3, 300);

    lv_anim_t a4;
    lv_anim_init(&a4);
    lv_anim_set_var(&a4, obj2);
    lv_anim_set_values(&a4, 0, obj_height);
    // 是够立刻生效
    lv_anim_set_early_apply(&a4, false);
    lv_anim_set_exec_cb(&a4, (lv_anim_exec_xcb_t)anim_set_height);
    lv_anim_set_path_cb(&a4, lv_anim_path_ease_out);
    lv_anim_set_time(&a4, 300);

    lv_anim_t a5;
    lv_anim_init(&a5);
    lv_anim_set_var(&a5, obj3);
    lv_anim_set_values(&a5, 0, obj_width);
    // 是够立刻生效
    lv_anim_set_early_apply(&a5, false);
    lv_anim_set_exec_cb(&a5, (lv_anim_exec_xcb_t)anim_set_width);
    lv_anim_set_path_cb(&a5, lv_anim_path_overshoot);
    lv_anim_set_time(&a5, 300);

    lv_anim_t a6;
    lv_anim_init(&a6);
    lv_anim_set_var(&a6, obj3);
    lv_anim_set_values(&a6, 0, obj_height);
    // 是够立刻生效
    lv_anim_set_early_apply(&a6, false);
    lv_anim_set_exec_cb(&a6, (lv_anim_exec_xcb_t)anim_set_height);
    lv_anim_set_path_cb(&a6, lv_anim_path_ease_out);
    lv_anim_set_time(&a6, 300);

    anim_time_line = lv_anim_timeline_create();
    lv_anim_timeline_add(anim_time_line, 0, &a1);
    lv_anim_timeline_add(anim_time_line, 0, &a2);
    lv_anim_timeline_add(anim_time_line, 200, &a3);
    lv_anim_timeline_add(anim_time_line, 200, &a4);
    lv_anim_timeline_add(anim_time_line, 400, &a5);
    lv_anim_timeline_add(anim_time_line, 400, &a6);
}

static void btn_start_event_handler(lv_event_t *e)
{
    lv_obj_t *btn = lv_event_get_target(e);
    if (anim_time_line)
    {
        anim_timeline_create();
    }
    bool reverse = lv_obj_has_state(btn, LV_STATE_CHECKED);
    lv_anim_timeline_set_reverse(anim_time_line, reverse);
    lv_anim_timeline_start(anim_time_line);
}

static void btn_del_event_handler(lv_event_t *e)
{
    LV_UNUSED(e);
    if (anim_time_line)
    {
        lv_anim_timeline_del(anim_time_line);
        anim_time_line = NULL;
    }
}

static void btn_stop_event_handler(lv_event_t *e)
{
    LV_UNUSED(e);
    if (anim_time_line)
    {
        lv_anim_timeline_stop(anim_time_line);
    }
}

static void slider_prg_event_handler(lv_event_t *e)
{
    lv_slider_t *slider = lv_event_get_target(e);
    if (!anim_time_line)
    {
        anim_timeline_create();
    }
    int32_t progress = lv_slider_get_value(slider);
    lv_anim_timeline_set_progress(anim_time_line, progress);
}

void example_anim_3(void)
{
    lv_obj_t *par = lv_scr_act();
    lv_obj_set_flex_flow(par, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(par, LV_FLEX_ALIGN_SPACE_AROUND, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

    lv_btn_t *btn = lv_btn_create(par);
    lv_label_t *label = lv_label_create(btn);
    lv_obj_add_event_cb(btn, btn_start_event_handler, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_add_flag(btn, LV_OBJ_FLAG_IGNORE_LAYOUT);
    lv_obj_add_flag(btn, LV_OBJ_FLAG_CHECKABLE);
    lv_label_set_text(label, "Start");
    lv_obj_align(btn, LV_ALIGN_TOP_MID, -100, 20);

    btn = lv_btn_create(par);
    lv_obj_add_event_cb(btn, btn_del_event_handler, LV_EVENT_CLICKED, NULL);
    lv_obj_add_flag(btn, LV_OBJ_FLAG_IGNORE_LAYOUT);
    label = lv_label_create(btn);
    lv_label_set_text(label, "Delete");
    lv_obj_align(btn, LV_ALIGN_TOP_MID, 0, 20);

    btn = lv_btn_create(par);
    lv_obj_add_event_cb(btn, btn_stop_event_handler, LV_EVENT_CLICKED, NULL);
    lv_obj_add_flag(btn, LV_OBJ_FLAG_IGNORE_LAYOUT);
    label = lv_label_create(btn);
    lv_label_set_text(label, "Stop");
    lv_obj_align(btn, LV_ALIGN_TOP_MID, 100, 20);

    lv_slider_t *slider = lv_slider_create(par);
    lv_obj_add_event_cb(slider, slider_prg_event_handler, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_add_flag(slider, LV_OBJ_FLAG_IGNORE_LAYOUT);
    lv_obj_align(slider, LV_ALIGN_BOTTOM_MID, 0, -20);
    lv_slider_set_range(slider, 0, 65535);

    obj1 = lv_obj_create(par);
    lv_obj_set_size(obj1, obj_width, obj_height);
    obj2 = lv_obj_create(par);
    lv_obj_set_size(obj2, obj_width, obj_height);
    obj3 = lv_obj_create(par);
    lv_obj_set_size(obj3, obj_width, obj_height);
}