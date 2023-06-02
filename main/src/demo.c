#include "lvgl.h"
#include "demo.h"

#ifdef EXAMPLE_1
void example_start_1(void)
{
    lv_obj_t *src = lv_scr_act();
    lv_obj_set_style_bg_color(src, lv_color_hex(0x003a57), LV_PART_MAIN);
    lv_obj_t *label = lv_label_create(src);
    lv_label_set_text(label, "Hello, This is MrTan");
    lv_obj_set_style_text_color(src, lv_color_hex(0xffffff), LV_PART_MAIN);
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
}
#endif

#ifdef EXAMPLE_2

static void btn_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *btn = lv_event_get_target(e);
    if (code == LV_EVENT_CLICKED)
    {
        static uint8_t cnt = 0;
        cnt++;
        lv_obj_t *label = lv_obj_get_child(btn, 0);
        lv_label_set_text_fmt(label, "Button: %d", cnt);
    }
}

/**
 * 创建一个带label的按钮，并响应点击事件
 */
void example_start_2(void)
{
    lv_obj_t *src = lv_scr_act();
    lv_obj_t *btn = lv_btn_create(src);
    lv_obj_set_pos(btn, 10, 10);
    lv_obj_set_size(btn, 120, 50);
    lv_obj_add_event_cb(btn, btn_event_cb, LV_EVENT_ALL, NULL);
    lv_obj_t *label = lv_label_create(btn);
    lv_label_set_text(label, "Button");
    lv_obj_center(label);
}
#endif

#ifdef EXAMPLE_3
//---------------------------------------------------------
static lv_style_t style_btn;
static lv_style_t style_btn_pressed;
static lv_style_t style_btn_red;
static lv_color_t darken(const lv_color_filter_dsc_t *dsc, lv_color_t color, lv_opa_t opa)
{
    LV_UNUSED(dsc);
    return lv_color_darken(color, opa);
}

static void style_init(void)
{
    lv_style_init(&style_btn);
    lv_style_set_radius(&style_btn, 10);
    lv_style_set_bg_opa(&style_btn, LV_OPA_COVER);
    lv_style_set_bg_color(&style_btn, lv_palette_lighten(LV_PALETTE_GREY, 3));
    lv_style_set_bg_grad_color(&style_btn, lv_palette_main(LV_PALETTE_GREY));
    lv_style_set_bg_grad_dir(&style_btn, LV_GRAD_DIR_VER);

    lv_style_set_border_color(&style_btn, lv_color_black());
    lv_style_set_border_opa(&style_btn, LV_OPA_20);
    lv_style_set_border_width(&style_btn, 2);

    lv_style_set_text_color(&style_btn, lv_color_black());

    static lv_color_filter_dsc_t color_filter;
    lv_color_filter_dsc_init(&color_filter, darken);
    lv_style_init(&style_btn_pressed);
    lv_style_set_color_filter_dsc(&style_btn_pressed, &color_filter);
    lv_style_set_color_filter_opa(&style_btn_pressed, LV_OPA_20);

    lv_style_init(&style_btn_red);
    lv_style_set_bg_color(&style_btn_red, lv_palette_main(LV_PALETTE_RED));
    lv_style_set_bg_grad_color(&style_btn_red, lv_palette_lighten(LV_PALETTE_RED, 3));
}

void example_start_3(void)
{
    style_init();
    lv_obj_t *btn = lv_btn_create(lv_scr_act());
    lv_obj_remove_style_all(btn);
    lv_obj_set_pos(btn, 10, 10);
    lv_obj_set_size(btn, 120, 50);
    lv_obj_add_style(btn, &style_btn, 0);
    lv_obj_add_style(btn, &style_btn_pressed, LV_STATE_PRESSED);

    lv_obj_t *label = lv_label_create(btn);
    lv_label_set_text(label, "Button");
    lv_obj_center(label);

    lv_obj_t *btn2 = lv_btn_create(lv_scr_act());
    // lv_obj_remove_style_all(btn2);
    lv_obj_set_pos(btn2, 10, 80);
    lv_obj_set_size(btn2, 120, 50);
    // lv_obj_add_style(btn2, &style_btn, LV_STATE_DEFAULT);
    lv_obj_add_style(btn2, &style_btn_red, LV_STATE_DEFAULT);
    lv_obj_add_style(btn2, &style_btn_pressed, LV_STATE_PRESSED);
    lv_obj_set_style_radius(btn2, LV_RADIUS_CIRCLE, 0);

    label = lv_label_create(btn2);
    lv_label_set_text(label, "Button 2");
    lv_obj_center(label);
}
#endif

#ifdef EXAMPLE_4
static lv_obj_t *label;

static void slider_event_cb(lv_event_t *e)
{
    lv_obj_t *slider = lv_event_get_target(e);

    lv_label_set_text_fmt(label, "%d", lv_slider_get_value(slider));
    lv_obj_align_to(label, slider, LV_ALIGN_OUT_TOP_MID, 0, -15);
}

void example_start_4(void)
{
    lv_obj_t *slider = lv_slider_create(lv_scr_act());
    lv_obj_set_width(slider, 200);
    lv_obj_center(slider);
    lv_obj_add_event_cb(slider, slider_event_cb, LV_EVENT_VALUE_CHANGED, NULL);

    label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "0");
    lv_obj_align_to(label, slider, LV_ALIGN_OUT_TOP_MID, 0, -15);
}
#endif

#ifdef STYLE_1
void example_style_1(void)
{
    static lv_style_t style;
    lv_style_init(&style);
    lv_style_set_radius(&style, 5);

    lv_style_set_width(&style, 150);
    lv_style_set_height(&style, LV_SIZE_CONTENT);

    // lv_style_set_pad_ver(&style, 20);
    lv_style_set_pad_left(&style, 5);
    // 50%
    lv_style_set_x(&style, lv_pct(50));
    lv_style_set_y(&style, 80);

    lv_obj_t *obj = lv_obj_create(lv_scr_act());
    lv_obj_add_style(obj, &style, LV_STATE_DEFAULT);

    lv_obj_t *label = lv_label_create(obj);
    lv_label_set_text(label, "Hello");
}
#endif

#ifdef STYLE_2
/**
 * 渐变背景色
 */
void example_style_2(void)
{
    static lv_style_t style;
    lv_style_init(&style);
    lv_style_set_radius(&style, 5);

    lv_style_set_bg_opa(&style, LV_OPA_COVER);
    static lv_grad_dsc_t grad;
    grad.dir = LV_GRAD_DIR_VER;
    grad.stops_count = 2;
    grad.stops[0].color = lv_palette_lighten(LV_PALETTE_GREY, 1);
    grad.stops[1].color = lv_palette_main(LV_PALETTE_BLUE);
    grad.stops[0].frac = 128;
    grad.stops[1].frac = 192;

    lv_style_set_bg_grad(&style, &grad);

    lv_obj_t *obj = lv_obj_create(lv_scr_act());
    lv_obj_add_style(obj, &style, 0);
    lv_obj_center(obj);
}
#endif

#ifdef STYLE_3
/**
 * border 样式
 */
void example_style_3(void)
{
    static lv_style_t style;
    lv_style_init(&style);

    lv_style_set_radius(&style, 10);
    lv_style_set_bg_opa(&style, LV_OPA_COVER);
    lv_style_set_bg_color(&style, lv_palette_lighten(LV_PALETTE_GREY, 1));

    lv_style_set_border_color(&style, lv_palette_main(LV_PALETTE_BLUE));
    lv_style_set_border_width(&style, 5);
    lv_style_set_border_opa(&style, LV_OPA_50);
    lv_style_set_border_side(&style, LV_BORDER_SIDE_BOTTOM | LV_BORDER_SIDE_RIGHT);

    lv_obj_t *obj = lv_obj_create(lv_scr_act());
    lv_obj_add_style(obj, &style, 0);
    lv_obj_center(obj);
}
#endif

#ifdef STYLE_4
/**
 * 设置outline
 */
void example_style_4(void)
{
    static lv_style_t style;
    lv_style_init(&style);

    lv_style_set_radius(&style, 5);
    lv_style_set_bg_opa(&style, LV_OPA_COVER);
    lv_style_set_bg_color(&style, lv_palette_lighten(LV_PALETTE_GREY, 1));

    lv_style_set_outline_width(&style, 2);
    lv_style_set_outline_color(&style, lv_palette_main(LV_PALETTE_BLUE));
    lv_style_set_outline_pad(&style, 8);

    lv_obj_t *obj = lv_obj_create(lv_scr_act());
    lv_obj_add_style(obj, &style, 0);
    lv_obj_center(obj);
}
#endif

#ifdef STYLE_5
void example_style_5(void)
{
    static lv_style_t style;
    lv_style_init(&style);

    lv_style_set_radius(&style, 5);
    lv_style_set_bg_opa(&style, LV_OPA_COVER);
    lv_style_set_bg_color(&style, lv_palette_lighten(LV_PALETTE_GREY, 1));

    lv_style_set_shadow_width(&style, 55);
    lv_style_set_shadow_color(&style, lv_palette_main(LV_PALETTE_BLUE));
    lv_style_set_shadow_ofs_x(&style, 10);
    lv_style_set_shadow_ofs_y(&style, 20);

    lv_obj_t *obj = lv_obj_create(lv_scr_act());
    lv_obj_add_style(obj, &style, 0);
    lv_obj_center(obj);
}
#endif

#ifdef STYLE_6
void example_style_6(void)
{
    static lv_style_t style;
    lv_style_init(&style);
    lv_style_set_radius(&style, 5);
    // 设置背景不透明
    lv_style_set_bg_opa(&style, LV_OPA_COVER);
    lv_style_set_bg_color(&style, lv_palette_lighten(LV_PALETTE_GREY, 3));
    lv_style_set_border_width(&style, 2);
    lv_style_set_border_color(&style, lv_palette_main(LV_PALETTE_BLUE));

    lv_style_set_img_recolor(&style, lv_palette_main(LV_PALETTE_GREEN));
    lv_style_set_img_recolor_opa(&style, LV_OPA_50);
    // lv_style_set_transform_angle(&style, 300);

    lv_obj_t *obj = lv_img_create(lv_scr_act());
    lv_obj_add_style(obj, &style, 0);

    LV_IMG_DECLARE(img_cogwheel_argb);
    lv_img_set_src(obj, &img_cogwheel_argb);
    lv_obj_center(obj);
}
#endif

#ifdef STYLE_7
/**
 * 椭圆样式
 */
void example_style_7(void)
{
    static lv_style_t style;
    lv_style_init(&style);
    lv_style_set_arc_color(&style, lv_palette_main(LV_PALETTE_RED));
    lv_style_set_arc_width(&style, 4);

    lv_obj_t *object = lv_arc_create(lv_scr_act());
    lv_obj_add_style(object, &style, 0);
    lv_obj_center(object);
}
#endif

#ifdef STYLE_8
/**
 * 文字样式
 */
void example_style_8(void)
{
    static lv_style_t style;
    lv_style_init(&style);

    lv_style_set_radius(&style, 5);
    lv_style_set_bg_opa(&style, LV_OPA_COVER);
    lv_style_set_bg_color(&style, lv_palette_lighten(LV_PALETTE_GREY, 2));
    lv_style_set_border_width(&style, 2);
    lv_style_set_border_color(&style, lv_palette_main(LV_PALETTE_BLUE));
    lv_style_set_pad_all(&style, 10);

    lv_style_set_text_color(&style, lv_palette_main(LV_PALETTE_BLUE));
    lv_style_set_text_letter_space(&style, 5);
    lv_style_set_text_line_space(&style, 20);
    lv_style_set_text_decor(&style, LV_TEXT_DECOR_UNDERLINE);

    lv_obj_t *obj = lv_label_create(lv_scr_act());
    lv_obj_add_style(obj, &style, 0);
    lv_label_set_text(obj, "Text of\n"
                           "a label");
    lv_obj_center(obj);
}
#endif

#ifdef STYLE_9
/**
 * 画线的样式
 */
void example_style_9(void)
{
    static lv_style_t style;
    lv_style_init(&style);

    lv_style_set_line_color(&style, lv_palette_main(LV_PALETTE_BLUE));
    lv_style_set_line_width(&style, 6);
    lv_style_set_line_rounded(&style, true);

    lv_obj_t *obj = lv_line_create(lv_scr_act());
    lv_obj_add_style(obj, &style, 0);

    static lv_point_t p[] = {{10, 30}, {30, 50}, {100, 0}};
    lv_line_set_points(obj, p, 3);

    lv_obj_center(obj);
}
#endif

#ifdef STYLE_10
/**
 * 渐变
 */
void example_style_10(void)
{
    static const lv_style_prop_t props[] = {LV_STYLE_BG_COLOR, LV_STYLE_BORDER_COLOR, LV_STYLE_BORDER_WIDTH, 0};

    static lv_style_transition_dsc_t trans_def;
    lv_style_transition_dsc_init(&trans_def, props, lv_anim_path_linear, 100, 200, NULL);

    static lv_style_transition_dsc_t trans_pr;
    lv_style_transition_dsc_init(&trans_pr, props, lv_anim_path_linear, 500, 0, NULL);

    static lv_style_t style_def;
    lv_style_init(&style_def);
    lv_style_set_transition(&style_def, &trans_def);

    static lv_style_t style_pr;
    lv_style_init(&style_pr);
    lv_style_set_bg_color(&style_pr, lv_palette_main(LV_PALETTE_RED));
    lv_style_set_border_width(&style_pr, 6);
    lv_style_set_border_color(&style_pr, lv_palette_darken(LV_PALETTE_RED, 3));
    lv_style_set_transition(&style_pr, &trans_pr);

    lv_obj_t *obj = lv_obj_create(lv_scr_act());
    lv_obj_add_style(obj, &style_def, 0);
    lv_obj_add_style(obj, &style_pr, LV_STATE_PRESSED);

    lv_obj_center(obj);
}
#endif

#ifdef STYLE_11
void example_style_11(void)
{
    static lv_style_t style_base;
    lv_style_init(&style_base);
    lv_style_set_radius(&style_base, 10);
    lv_style_set_bg_color(&style_base, lv_palette_main(LV_PALETTE_BLUE));
    lv_style_set_border_color(&style_base, lv_palette_darken(LV_PALETTE_BLUE, 3));
    lv_style_set_border_width(&style_base, 2);
    lv_style_set_shadow_width(&style_base, 10);
    lv_style_set_shadow_opa(&style_base, LV_OPA_50);
    lv_style_set_shadow_ofs_y(&style_base, 5);
    lv_style_set_text_color(&style_base, lv_color_white());
    lv_style_set_width(&style_base, 100);
    lv_style_set_height(&style_base, LV_SIZE_CONTENT);

    static lv_style_t style_warn;
    lv_style_init(&style_warn);
    lv_style_set_bg_color(&style_warn, lv_palette_main(LV_PALETTE_YELLOW));
    lv_style_set_border_color(&style_warn, lv_palette_darken(LV_PALETTE_YELLOW, 3));
    lv_style_set_text_color(&style_warn, lv_palette_darken(LV_PALETTE_YELLOW, 4));

    lv_obj_t *btn_base = lv_btn_create(lv_scr_act());
    lv_obj_add_style(btn_base, &style_base, LV_STATE_DEFAULT);
    lv_obj_t *label = lv_label_create(btn_base);
    lv_label_set_text(label, "Base");
    lv_obj_center(label);
    lv_obj_align(btn_base, LV_ALIGN_LEFT_MID, 20, 0);

    lv_obj_t *btn_warn = lv_btn_create(lv_scr_act());
    lv_obj_add_style(btn_warn, &style_base, LV_STATE_DEFAULT);
    lv_obj_add_style(btn_warn, &style_warn, LV_STATE_DEFAULT);
    label = lv_label_create(btn_warn);
    lv_label_set_text(label, "Warn");
    lv_obj_center(label);
    lv_obj_align(btn_warn, LV_ALIGN_RIGHT_MID, -20, 0);
}
#endif

#ifdef STYLE_12
/**
 * 设置样式在修改
 */
void example_style_12(void)
{
    static lv_style_t style;
    lv_style_init(&style);
    lv_style_set_bg_color(&style, lv_palette_main(LV_PALETTE_GREEN));
    lv_style_set_border_color(&style, lv_palette_lighten(LV_PALETTE_GREEN, 3));
    lv_style_set_border_width(&style, 3);

    lv_obj_t *obj = lv_obj_create(lv_scr_act());
    lv_obj_add_style(obj, &style, LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(obj, lv_palette_main(LV_PALETTE_ORANGE), LV_STATE_DEFAULT);
    lv_obj_center(obj);
}
#endif


// #ifdef STYLE_2
// #endif

// #ifdef STYLE_2
// #endif

// #ifdef STYLE_2
// #endif

// #ifdef STYLE_2
// #endif

// #ifdef STYLE_2
// #endif

// #ifdef STYLE_2
// #endif

// #ifdef STYLE_2
// #endif

// #ifdef STYLE_2
// #endif

// #ifdef STYLE_2
// #endif

// #ifdef STYLE_2
// #endif

// #ifdef STYLE_2
// #endif

// #ifdef STYLE_2
// #endif