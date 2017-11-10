/**
 * @file lv_btn.h
 * 
 */

#ifndef LV_BTN_H
#define LV_BTN_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include "lv_conf.h"
#if USE_LV_BTN != 0

/*Testing of dependencies*/
#if USE_LV_CONT == 0
#error "lv_btn: lv_cont is required. Enable it in lv_conf.h (USE_LV_CONT  1) "
#endif

#include "lv_cont.h"
#include "../lv_obj/lv_indev.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/*Button states*/
typedef enum
{
    LV_BTN_STATE_RELEASED,
    LV_BTN_STATE_PRESSED,
    LV_BTN_STATE_TGL_RELEASED,
    LV_BTN_STATE_TGL_PRESSED,
    LV_BTN_STATE_INACTIVE,
    LV_BTN_STATE_NUM,
}lv_btn_state_t;

typedef enum
{
    LV_BTN_ACTION_RELEASE,
    LV_BTN_ACTION_PRESS,
    LV_BTN_ACTION_LONG_PRESS,
    LV_BTN_ACTION_LONG_PRESS_REPEATE,
    LV_BTN_ACTION_NUM,
}lv_btn_action_t;

/*Data of button*/
typedef struct
{
	lv_cont_ext_t cont; /*Ext. of ancestor*/
	/*New data for this type */
	lv_action_t actions[LV_BTN_ACTION_NUM];
	lv_style_t * styles[LV_BTN_STATE_NUM];        /*Styles in each state*/

    lv_btn_state_t state;                         /*Current state of the button from 'lv_btn_state_t' enum*/
    uint8_t toggle :1;                            /*1: Toggle enabled*/
    uint8_t long_press_action_executed :1;        /*1: Long press action executed (Handled by the library)*/
}lv_btn_ext_t;


/**********************
 * GLOBAL PROTOTYPES
 **********************/


/**
 * Create a button objects
 * @param par pointer to an object, it will be the parent of the new button
 * @param copy pointer to a button object, if not NULL then the new object will be copied from it
 * @return pointer to the created button
 */
lv_obj_t * lv_btn_create(lv_obj_t * par, lv_obj_t * copy);

/*=====================
 * Setter functions
 *====================*/

/**
 * Enable the toggled states. On release the button will change from/to toggled state.
 * @param btn pointer to a button object
 * @param tgl true: enable toggled states, false: disable
 */
void lv_btn_set_toggle(lv_obj_t * btn, bool tgl);

/**
 * Set the state of the button
 * @param btn pointer to a button object
 * @param state the new state of the button (from lv_btn_state_t enum)
 */
void lv_btn_set_state(lv_obj_t * btn, lv_btn_state_t state);

/**
 * Toggle the state of the button (ON->OFF, OFF->ON)
 * @param btn pointer to a button object
 */
void lv_btn_toggle(lv_obj_t * btn);

/**
 * Set a function to call when the button event happens
 * @param btn pointer to a button object
 * @param action type of event form 'lv_action_t' (press, release, long press, long press repeat)
 */
void lv_btn_set_action(lv_obj_t * btn, lv_btn_action_t type, lv_action_t action);

/**
 * Set the layout on a button
 * @param btn pointer to a button object
 * @param layout a layout from 'lv_cont_layout_t'
 */
static inline void lv_btn_set_layout(lv_obj_t * btn, lv_cont_layout_t layout)
{
    lv_cont_set_layout(btn, layout);
}

/**
 * Enable the horizontal or vertical fit.
 * The button size will be set to involve the children horizontally or vertically.
 * @param btn pointer to a button object
 * @param hor_en true: enable the horizontal fit
 * @param ver_en true: enable the vertical fit
 */
static inline void lv_btn_set_fit(lv_obj_t * btn, bool hor_en, bool ver_en)
{
    lv_cont_set_fit(btn, hor_en, ver_en);
}

/**
 * Set styles of a button is each state. Use NULL for any style to leave it unchanged
 * @param btn pointer to button object
 * @param rel pointer to a style for releases state
 * @param pr  pointer to a style for pressed state
 * @param tgl_rel pointer to a style for toggled releases state
 * @param tgl_pr pointer to a style for toggled pressed state
 * @param ina pointer to a style for inactive state
 */
void lv_btn_set_style(lv_obj_t * btn, lv_style_t *rel, lv_style_t *pr,
                                      lv_style_t *tgl_rel, lv_style_t *tgl_pr,
                                      lv_style_t *ina);

/*=====================
 * Getter functions
 *====================*/

/**
 * Get the current state of the button
 * @param btn pointer to a button object
 * @return the state of the button (from lv_btn_state_t enum)
 */
lv_btn_state_t lv_btn_get_state(lv_obj_t * btn);

/**
 * Get the toggle enable attribute of the button
 * @param btn pointer to a button object
 * @return ture: toggle enabled, false: disabled
 */
bool lv_btn_get_toggle(lv_obj_t * btn);

/**
 * Get the release action of a button
 * @param btn pointer to a button object
 * @return pointer to the release action function
 */
lv_action_t lv_btn_get_action(lv_obj_t * btn, lv_btn_action_t type);

/**
 * Get the layout of a button
 * @param btn pointer to button object
 * @return the layout from 'lv_cont_layout_t'
 */
static inline lv_cont_layout_t lv_btn_get_layout(lv_obj_t * btn)
{
    return lv_cont_get_layout(btn);
}

/**
 * Get horizontal fit enable attribute of a button
 * @param btn pointer to a button object
 * @return true: horizontal fit is enabled; false: disabled
 */
static inline bool lv_btn_get_hor_fit(lv_obj_t * btn)
{
    return lv_cont_get_hor_fit(btn);
}

/**
 * Get vertical fit enable attribute of a container
 * @param btn pointer to a button object
 * @return true: vertical fit is enabled; false: disabled
 */
static inline bool lv_btn_get_ver_fit(lv_obj_t * btn)
{
    return lv_cont_get_ver_fit(btn);
}

/**
 * Get the style of a button in a given state
 * @param btn pointer to a button object
 * @param state a state from 'lv_btn_state_t' in which style should be get
 * @return pointer to the style in the given state
 */
lv_style_t * lv_btn_get_style(lv_obj_t * btn, lv_btn_state_t state);

/**********************
 *      MACROS
 **********************/

#endif  /*USE_LV_BUTTON*/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif  /*lv_btn_H*/
