#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(NOR + HIM "帝王符圖碎片-50" NOR, ({ "diwang suipian50", "diwang", "suipian" }) );
        set_weight(100);
        /*if( clonep() )
                set_default_object(__FILE__);
        else*/ {
                set("unit", "張");
                set("long", NOR + WHT "傳說乃上古黃帝，炎帝及蚩尤留下的圖騰碎片，大道五十，天衍四十九，遁去其一。\n"
                            "可以用這個遁去的一來重置(reset)你的圖騰技能。\n" NOR);
                set("value", 0);
                set("no_give", 1);
                set("no_drop", 1);
        }
        set("auto_load", 1);
        setup();
}

void init()
{
        if( this_player() == environment() )
                add_action("do_reset", "reset");
}

int do_reset(string arg)
{
        object ob = this_player();
        string spk1, spk2;
        string *spks = ({
                "zhuque", 
                "tianshen", 
                "qijin", 
                "taxue", 
                "diwang", 
        });

        if( !arg || sscanf(arg, "%s to %s", spk1, spk2) != 2 )
                return notify_fail("重置圖騰技能指令格式：reset <zhuque> to <taxue>\n");

        if( !query("special_skill/"+spk1, ob) )
                return notify_fail("你還不會這種圖騰技能！\n");

        if( member_array(spk1, spks) == -1 )
                return notify_fail("你這個不是圖騰技能！\n");

        if( member_array(spk2, spks) == -1 )
                return notify_fail("你想要重置後的不是圖騰技能！\n");

        if( query("special_skill/"+spk2, ob) )
                return notify_fail("你已經擁有這個圖騰技能！\n");

        if( spk1 == "diwang" )
        {
                addn("int", -2, ob);
                addn("str", -2, ob);
                addn("con", -2, ob);
                addn("dex", -2, ob);
        }
        
        if( spk2 == "diwang" )
        {
                addn("int", 2, ob);
                addn("str", 2, ob);
                addn("con", 2, ob);
                addn("dex", 2, ob);
        }

        delete("special_skill/"+spk1, ob);
        set("special_skill/"+spk2, 1, ob);
        write(HIR "恭喜你重置圖騰技能成功！\n" NOR);
        destruct(this_object());
        return 1;
}


