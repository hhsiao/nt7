// $file_name.c                                                 /* COMMENT_ENTRY */
// Create by TEMPLATE_D. $time.                                 /* COMMENT_ENTRY */
// skull.c
// Written by Lonely                                            /* COMMENT_EXIT  */

#include <ansi.h>

inherit TESSERA;

void create()
{
//**    set_name("$name", ({ "$id", }));                        /* NAME_ENTRY */
        set_name(HIR "朱雀·火" NOR, ({"zhu que", "fire"}));/* NAME_EXIT  */
        set_weight(20);
        //**            set("$dbase_key", "$dbase_value\n");            /* DBASE_ENTRY */
                set("long", HIR "可用於鑲嵌10LV，屬性火。\n" NOR); /* DBASE_EXIT  */
                set("value", 100000);
                set("unit", "塊");
                set("can_be_tessera", 1);
                set("magic/type", "fire");
                set("magic/power", 500);
        setup();
}
