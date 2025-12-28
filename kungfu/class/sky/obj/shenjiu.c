#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW "天乙神酒" NOR, ({"tianyi shenjiu", "jiu", "shenjiu", "tianyi"}));
        /*if (clonep())
                set_default_object(__FILE__);
        else*/ {
                set("long", HIW "這是一瓶天乙神酒，便是隻聞聞也讓你昏昏欲醉。\n" NOR);
                set("unit", "瓶");
                set("no_sell", 1);
                set("value", 50000);
        }
        setup();
}

void init()
{
        add_action("do_eat", "drink");
}

int do_eat(string arg)
{
        object ob;
        object me = this_player();

        if (! id(arg) && arg != "tianyi shenjiu"
           && arg != "jiu" && arg != "shenjiu"
           && arg != "tianyi")
                return notify_fail("你要喝什麼東西？\n");

        if (me->is_busy())
                return notify_fail("急什麼，小心別噎著了。\n");

        if (!random(4))
        {
                message_vision(WHT "$N" WHT "喝了幾口，卻發現瓶內所裝不"
                               "過是普通的女兒紅。\n" NOR, me);
                destruct(this_object());
                return 1;
        }

        message_vision(HIW "$N" HIW "一仰頭，將天乙神酒喝了下去，精神頓"
                       "時為之一振。\n" NOR, me);

        if (query_temp("tianyishenjiu_time", me) < time()) {
        set("jingli", query("max_jingli", me), me);
        set("neili", query("max_neili", me), me);
        set("jing", query("max_jing", me), me);
        set("qi", query("max_qi", me), me);
        set("eff_jing", query("max_jing", me), me);
        set("eff_qi", query("max_qi", me), me);
        } else
        {
                message_vision(WHT "$N" WHT "酒喝多了，沒有產生什麼理想效果。\n" NOR, me);
        }
        if (!random(10)) {
            me->improve_skill("force", 5000000);
            if (stringp(me->query_skill_mapped("force")))
                me->improve_skill(me->query_skill_mapped("force"), 5000000);
        addn("tianyishenjiu_time", 1,me); 
        tell_object(me, HIC "你對唐詩劍法的領悟加深了。\n" NOR); 

        }

        me->affect_by("drunk", ([
                "level" : 500 + random(500),
                "id"    : query("id", me),
                "duration" : 500 + random(500)
        ]));

        me->start_busy(1);
        destruct(this_object());
        set_temp("tianyishenjiu_time", time() + 120, me);
        return 1;
}
