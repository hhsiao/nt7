#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIC "蛇年" HIY "腦黃金" NOR, ({ "nao huangjin", "nao", "huangjin" }) );
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIG "上面寫著「" HIY "2003年我家不收禮，收禮只"
                            "收腦黃金" HIG "」看樣子是高級貨。\n" NOR);
                set("value", 500000);
                set("no_sell", 1);
                set("unit", "盒");
                set("only_do_effect", 1);
        }
}

int do_effect(object me)
{
              message_vision(HIW "$N" HIW "哈哈一笑，將一整盒腦黃金連同"
                       "盒子一塊吞下肚去。\n" NOR, me);
               addn("combat_exp", 100000000, me);
               addn("potential", 30000000, me);
         addn("experience", 15000000, me);

        destruct(this_object());
        return 1;
}
