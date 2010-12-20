/*
 * Copyright (C) 2003-2010 Sebastien Helleu <flashcode@flashtux.org>
 *
 * This file is part of WeeChat, the extensible chat client.
 *
 * WeeChat is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * WeeChat is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with WeeChat.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __WEECHAT_GUI_COLOR_H
#define __WEECHAT_GUI_COLOR_H 1

enum t_gui_color_enum
{
    GUI_COLOR_SEPARATOR = 0,
    
    GUI_COLOR_CHAT,
    GUI_COLOR_CHAT_TIME,
    GUI_COLOR_CHAT_TIME_DELIMITERS,
    GUI_COLOR_CHAT_PREFIX_ERROR,
    GUI_COLOR_CHAT_PREFIX_NETWORK,
    GUI_COLOR_CHAT_PREFIX_ACTION,
    GUI_COLOR_CHAT_PREFIX_JOIN,
    GUI_COLOR_CHAT_PREFIX_QUIT,
    GUI_COLOR_CHAT_PREFIX_MORE,
    GUI_COLOR_CHAT_PREFIX_SUFFIX,
    GUI_COLOR_CHAT_BUFFER,
    GUI_COLOR_CHAT_SERVER,
    GUI_COLOR_CHAT_CHANNEL,
    GUI_COLOR_CHAT_NICK,
    GUI_COLOR_CHAT_NICK_SELF,
    GUI_COLOR_CHAT_NICK_OTHER,
    /*
     * following obsolete colors are kept here for compatibility
     * with WeeChat <= 0.3.3
     */
    GUI_COLOR_CHAT_NICK1_OBSOLETE,  /* not used any more since WeeChat 0.3.4 */
    GUI_COLOR_CHAT_NICK2_OBSOLETE,  /* not used any more since WeeChat 0.3.4 */
    GUI_COLOR_CHAT_NICK3_OBSOLETE,  /* not used any more since WeeChat 0.3.4 */
    GUI_COLOR_CHAT_NICK4_OBSOLETE,  /* not used any more since WeeChat 0.3.4 */
    GUI_COLOR_CHAT_NICK5_OBSOLETE,  /* not used any more since WeeChat 0.3.4 */
    GUI_COLOR_CHAT_NICK6_OBSOLETE,  /* not used any more since WeeChat 0.3.4 */
    GUI_COLOR_CHAT_NICK7_OBSOLETE,  /* not used any more since WeeChat 0.3.4 */
    GUI_COLOR_CHAT_NICK8_OBSOLETE,  /* not used any more since WeeChat 0.3.4 */
    GUI_COLOR_CHAT_NICK9_OBSOLETE,  /* not used any more since WeeChat 0.3.4 */
    GUI_COLOR_CHAT_NICK10_OBSOLETE, /* not used any more since WeeChat 0.3.4 */
    GUI_COLOR_CHAT_HOST,
    GUI_COLOR_CHAT_DELIMITERS,
    GUI_COLOR_CHAT_HIGHLIGHT,
    GUI_COLOR_CHAT_READ_MARKER,
    GUI_COLOR_CHAT_TEXT_FOUND,
    GUI_COLOR_CHAT_VALUE,
    GUI_COLOR_CHAT_PREFIX_BUFFER,
    
    /* number of colors */
    GUI_COLOR_NUM_COLORS,
};

/* WeeChat internal color attributes (should never be in protocol messages) */

#define GUI_COLOR_COLOR_CHAR           '\x19'
#define GUI_COLOR_COLOR_STR            "\x19"
#define GUI_COLOR_SET_WEECHAT_CHAR     '\x1A'
#define GUI_COLOR_SET_WEECHAT_STR      "\x1A"
#define GUI_COLOR_REMOVE_WEECHAT_CHAR  '\x1B'
#define GUI_COLOR_REMOVE_WEECHAT_STR   "\x1B"
#define GUI_COLOR_RESET_CHAR           '\x1C'
#define GUI_COLOR_RESET_STR            "\x1C"

#define GUI_COLOR_ATTR_BOLD_CHAR       '\x01'
#define GUI_COLOR_ATTR_BOLD_STR        "\x01"
#define GUI_COLOR_ATTR_REVERSE_CHAR    '\x02'
#define GUI_COLOR_ATTR_REVERSE_STR     "\x02"
#define GUI_COLOR_ATTR_ITALIC_CHAR     '\x03'
#define GUI_COLOR_ATTR_ITALIC_STR      "\x03"
#define GUI_COLOR_ATTR_UNDERLINE_CHAR  '\x04'
#define GUI_COLOR_ATTR_UNDERLINE_STR   "\x04"

#define GUI_COLOR(color) ((gui_color[color]) ? gui_color[color]->string : "")
#define GUI_NO_COLOR     GUI_COLOR_RESET_STR

#define GUI_COLOR_CUSTOM_BAR_FG    (gui_color_get_custom ("bar_fg"))
#define GUI_COLOR_CUSTOM_BAR_DELIM (gui_color_get_custom ("bar_delim"))
#define GUI_COLOR_CUSTOM_BAR_BG    (gui_color_get_custom ("bar_bg"))

#define GUI_COLOR_FG_CHAR                     'F'
#define GUI_COLOR_FG_STR                      "F"
#define GUI_COLOR_BG_CHAR                     'B'
#define GUI_COLOR_BG_STR                      "B"
#define GUI_COLOR_FG_BG_CHAR                  '*'
#define GUI_COLOR_FG_BG_STR                   "*"
#define GUI_COLOR_PAIR_CHAR                   '@'
#define GUI_COLOR_PAIR_STR                    "@"
#define GUI_COLOR_BAR_CHAR                    'b'
#define GUI_COLOR_BAR_STR                     "b"
#define GUI_COLOR_BAR_FG_CHAR                 'F'
#define GUI_COLOR_BAR_FG_STR                  "F"
#define GUI_COLOR_BAR_DELIM_CHAR              'D'
#define GUI_COLOR_BAR_DELIM_STR               "D"
#define GUI_COLOR_BAR_BG_CHAR                 'B'
#define GUI_COLOR_BAR_BG_STR                  "B"
#define GUI_COLOR_BAR_START_INPUT_CHAR        '_'
#define GUI_COLOR_BAR_START_INPUT_STR         "_"
#define GUI_COLOR_BAR_START_INPUT_HIDDEN_CHAR '-'
#define GUI_COLOR_BAR_START_INPUT_HIDDEN_STR  "-"
#define GUI_COLOR_BAR_MOVE_CURSOR_CHAR        '#'
#define GUI_COLOR_BAR_MOVE_CURSOR_STR         "#"

#define GUI_COLOR_PAIR_FLAG 0x10000
#define GUI_COLOR_PAIR_MASK 0xFFFF

/* color structure */

struct t_gui_color
{
    int foreground;                 /* foreground color                     */
    int background;                 /* background color                     */
    int attributes;                 /* attributes (bold, ..)                */
    char *string;                   /* WeeChat color: "\x19??", ?? is #color*/
};

/* custom color in palette */

struct t_gui_color_palette
{
    char *alias;                    /* alias name for this color pair       */
    int foreground;                 /* foreground color                     */
    int background;                 /* background color                     */
    int r, g, b;                    /* red/green/blue values for color      */
};

/* color variables */

extern struct t_gui_color *gui_color[];
extern struct t_hashtable *gui_color_hash_palette_color;
extern struct t_hashtable *gui_color_hash_palette_alias;
extern struct t_weelist *gui_color_list_with_alias;

/* color functions */

extern const char *gui_color_search_config (const char *color_name);
extern const char *gui_color_get_custom (const char *color_name);
extern char *gui_color_decode (const char *string, const char *replacement);
extern char *gui_color_string_replace_colors (const char *string);
extern void gui_color_free (struct t_gui_color *color);
extern int gui_color_palette_get_alias (const char *alias);
extern struct t_gui_color_palette *gui_color_palette_get (int number);
extern void gui_color_palette_add (int number, const char *value);
extern void gui_color_palette_remove (int number);
extern void gui_color_palette_change (int number, const char *value);

/* color functions (GUI dependent) */

extern int gui_color_search (const char *color_name);
extern int gui_color_assign (int *color, char const *color_name);
extern int gui_color_assign_by_diff (int *color, const char *color_name,
                                     int diff);
extern int gui_color_get_number ();
extern const char *gui_color_get_name (int num_color);
extern void gui_color_init_pair (int number);
extern void gui_color_init_pairs ();
extern void gui_color_init_weechat ();
extern void gui_color_display_terminal_colors ();
extern void gui_color_palette_build_aliases ();
extern struct t_gui_color_palette *gui_color_palette_new (int number,
                                                          const char *value);
extern void gui_color_palette_free (struct t_gui_color_palette *color_palette);

#endif /* __WEECHAT_GUI_COLOR_H */
