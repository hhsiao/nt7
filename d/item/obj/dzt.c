// /u/hotjc/dzt.c

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIG "打造臺" NOR, ({ "dazao tai", "tai" }) );
        set_weight(3000);
        /*if( clonep() )
                set_default_object(__FILE__);
        else*/ {
          set("long", HIG @LONG
這是一個簽名、強化、綠化、升級裝備的打造臺。
鑲嵌物品              enchase
附魔屬性              enchant
防具升級              forge
裝備打孔              notch
寶石合併              combine
洗 裝 備              melt
裝備強化              qianghua
裝備綠化              dosuit
LONG NOR );
                set("value", 2000);
                set("unit", "片");
                set("no_get", 1);
                set("auto_load", 1);
        }
        setup();
}