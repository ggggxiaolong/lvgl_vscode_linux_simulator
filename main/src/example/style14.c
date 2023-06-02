#include "lvgl.h"

static lv_style_t style_btn;

/**
 * 当已添加基础主题的样式的对象添加新样式的时候回调
 */
static void new_theme_apply_cd(lv_theme_t *th, lv_obj_t *obj)
{
    LV_UNUSED(th);

    // 是否是按钮样式
    if (lv_obj_check_type(obj, &lv_btn_class))
    {
        lv_obj_add_style(obj, &style_btn, LV_STATE_DEFAULT);
    }
}

static void new_theme_init_and_set(void)
{
    // 初始化样式
    lv_style_init(&style_btn);
    lv_style_set_bg_color(&style_btn, lv_palette_main(LV_PALETTE_GREEN));
    lv_style_set_border_color(&style_btn, lv_palette_darken(LV_PALETTE_GREEN, 3));
    lv_style_set_border_width(&style_btn, 3);

    // 以当前的样式新建样式
    lv_theme_t *th_act = lv_disp_get_theme(NULL);
    static lv_theme_t th_new;
    th_new = *th_act;

    lv_theme_set_parent(&th_new, th_act);
    lv_theme_set_apply_cb(&th_new, new_theme_apply_cd);

    lv_disp_set_theme(NULL, &th_new);
}

void example_style_14(void)
{
    lv_obj_t *btn;
    lv_obj_t *label;

    btn = lv_btn_create(lv_scr_act());
    lv_obj_align(btn, LV_ALIGN_TOP_MID, 9, 20);

    label = lv_label_create(btn);
    lv_label_set_text(label, "Original theme");
    new_theme_init_and_set();

    btn = lv_btn_create(lv_scr_act());
    lv_obj_align(btn, LV_ALIGN_BOTTOM_MID, 0, -20);
    label = lv_label_create(btn);
    lv_label_set_text(label, "New themes");
}