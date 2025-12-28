// This program is a part of NT MudLIB

#include <ansi.h>
#define GIFT_NAME "新手禮品盒"
inherit ITEM;

int do_fen(string arg);

void create()
{
        set_name(HIR + GIFT_NAME + NOR, ({"giftbox", "box"}));
        set_weight(200);
        /*if (clonep())
                set_default_object(__FILE__);
        else*/ {
                set("unit", "件");
                set("long", @LONG
可以不用留學而獲得原有留學增加的先天天賦，方便新手。
打開的指令為open box，解密的幫助文件help add_gift。
LONG );
                set("value", 1);
                set("auto_load", 1);
                /*
                set("no_give", 1);
                set("no_get", 1);
                set("no_steal", 1);
                set("no_put", 1);
                set("no_sell", 1);
                set("no_drop", 1);
                */
        }
        setup();
}

void init()
{
        object me = this_player();

        if( me == environment() )
        {
                add_action("do_open", "open");
        }
}

int do_open(string arg)
{
        object me = this_player();

        if( !arg || (arg != "box" && arg != "giftbox") )
                return notify_fail("指令格式：open box\n");

        if( query("welcomegift", me) )
                return notify_fail("你已經使用過新手禮品盒了！\n");
        
        message_vision("$N充滿憧憬地拆開了一個新手禮品盒，頓時鋪天蓋地的紅光將$N籠罩在內。\n", me);
        
        if( !query("sl_gift/yzc", me) )
        {
                addn("con", 1, me);
                set("sl_gift/yzc", 1, me); // 般若掌
                tell_object(me, HIM "你獲得原需要學習般若掌才能獲得１點先天悟性。\n" NOR);
        }

        if( !query("sl_gift/int", me) )
        {
                addn("int", 1, me);
                set("sl_gift/int", 1, me); // 禪宗心法
                tell_object(me, HIM "你獲得原需要學習禪宗心法才能獲得１點先天悟性。\n" NOR);
        }
                
        if( !query("sl_gift/con", me) )
        {
                addn("con", 1, me);
                set("sl_gift/con", 1, me); // 一指禪
                tell_object(me, HIM "你獲得原需要學習一指禪才能獲得１點先天根骨。\n" NOR);
        }

        if( !query("sl_gift/str", me) )
        {
                addn("str", 1, me);
                set("sl_gift/str", 1, me); // 金剛拳
                tell_object(me, HIM "你獲得原需要學習金剛拳才能獲得１點先天臂力。\n" NOR);
        }       

        if( !query("sl_gift/zg", me) )
        {
                addn("dex", 1, me);
                set("sl_gift/zg", 1, me); // 無常杖
                tell_object(me, HIM "你獲得原需要學習醉棍才能獲得１點先天身法。\n" NOR);
        }

        if( query("gender", me) == "男性" && !query("sl_gift/huoyandao", me) )
        {
                addn("con", 1, me);
                set("sl_gift/huoyandao", 1, me); // 火焰刀
                tell_object(me, HIM "你獲得原需要學習火焰刀才能獲得１點先天根骨。\n" NOR);
        }

        if( query("gender", me) == "女性" && !query("sl_gift/mhyn", me) )
        {
                addn("dex", 1, me);
                set("sl_gift/mhyn", 1, me); // 大乘涅磐功
                tell_object(me, HIM "你獲得原需要學習大乘涅磐功才能獲得１點先天身法。\n" NOR);
        }                
                                        
        set("welcomegift", 1, me);
        me->save();
        
        tell_object(me, HIM"你獲得了原來需要留學才能獲得的先天獎勵，這些先天獎勵可以通過help add_gift瞭解。\n"NOR);
        message_vision("紅光慢慢退去，$N好像發生了一些變化。\n", me);
        return 1;
}

void owner_is_killed() { destruct(this_object()); }

