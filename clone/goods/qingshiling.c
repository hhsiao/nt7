
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIR "清師令" NOR, ({ "qingshi ling", "qingshi", "ling" }) );
        set_weight(100);

        set("long", HIG "可使用他用來清除(qingshi <門派>)脫離師門不良記錄一個。\n" NOR);
                set("value", 1);
                set("no_sell", 1);
                set("unit", "塊");
                set("auto_load", 1);

        setup();
}

void init()
{
        add_action("do_qingshi", "qingshi");
}

int do_qingshi(string arg)
{
        object me;
        me = this_player();

        if( !arg ) return notify_fail("使用格式：qingshi <門派>，例如 qingshi 武當派\n");

        if( !query("detach/"+arg, me) )
                return notify_fail("你並沒有脫離過該門派的記錄啊！\n");

        delete("detach/"+arg, me);
        if( sizeof(query("detach", me)) < 1 )
                delete("detach", me);

        write(HIM "清師令使用成功，你的"+arg+"脫離記錄清除了！\n" NOR);
        write(HIG "清師令畫作一縷青煙逐漸消失了！\n" NOR);
        me->save();
        destruct(this_object());

        return 1;
}
