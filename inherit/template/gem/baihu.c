// $file_name.c                                                 /* COMMENT_ENTRY */
// Create by TEMPLATE_D. $time.                                 /* COMMENT_ENTRY */
// skull.c
// Written by Lonely                                            /* COMMENT_EXIT  */

#include <ansi.h>

inherit TESSERA;

void create()
{
//**    set_name("$name", ({ "$id", }));                        /* NAME_ENTRY */
        set_name(HIY "白虎·金" NOR, ({"bai hu", "metal"})); /* NAME_EXIT  */
        set_weight(20);
        //**            set("$dbase_key", "$dbase_value\n");            /* DBASE_ENTRY */
                set("long", HIY "可用於鑲嵌10LV，屬性金。\n" NOR); /* DBASE_EXIT  */
                set("value", 100000);
                set("unit", "塊");
                set("can_be_tessera", 1);
                set("magic/type", "metal");
                set("magic/power", 500);
        setup();
}
