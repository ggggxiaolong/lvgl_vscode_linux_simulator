#include "anim.h"

/**
 * 位移动画
*/
static void anim_x_cd(void *var, int32_t v)
{
    lv_obj_set_x(var, v);
}

static void sw_event_cd(lv_event_t *e)
{
    lv_obj_t *sw = lv_event_get_target(e);
    lv_obj_t *label = lv_event_get_user_data(e);

    if (lv_obj_has_state(sw, LV_STATE_CHECKED))
    {
        lv_anim_t a;
        lv_anim_init(&a);
        lv_anim_set_var(&a, label);
        lv_anim_set_values(&a, lv_obj_get_x(label), 100);
        lv_anim_set_time(&a, 500);
        lv_anim_set_exec_cb(&a, anim_x_cd);
        lv_anim_set_path_cb(&a, lv_anim_path_overshoot);
        lv_anim_start(&a);
    }
    else
    {
        lv_anim_t a;
        lv_anim_init(&a);
        lv_anim_set_var(&a, label);
        lv_anim_set_values(&a, lv_obj_get_x(label), -lv_obj_get_width(label));
        lv_anim_set_time(&a, 500);
        lv_anim_set_exec_cb(&a, anim_x_cd);
        lv_anim_set_path_cb(&a, lv_anim_path_ease_in);
        lv_anim_start(&a);
    }
}

void example_anim_1(void)
{
    lv_label_t *label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "Hello animations!");
    lv_obj_set_pos(label, 100, 0);

    lv_switch_t *sw = lv_switch_create(lv_scr_act());
    lv_obj_center(sw);
    lv_obj_add_state(sw, LV_STATE_CHECKED);
    lv_obj_add_event_cb(sw, sw_event_cd, LV_EVENT_VALUE_CHANGED, label);
}