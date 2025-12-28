#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(YEL "解除干將綁定符" NOR, ({ "remove symbol", "remove", "symbol" }));
        set_weight(3000);
        /*if (clonep())
                set_default_object(__FILE__);
        else*/ {
                set("long", YEL "該符文可以解除(unbind)物品的被幹將聖符綁定。\n" NOR);
                set("unit", "塊");
                set("value", 5000);
        }
        setup();
}

void init()
{
        add_action("do_unbind", "unbind");
}

int do_unbind(string arg)
{
        string id, file;
        object obj;
        object me;
        object ob;

        if (! arg || arg == "")
                return notify_fail("你要往什麼道具上使用該神符？\n");

        me = this_player();
        if (! objectp(ob = present(arg, me)) &&
            ! objectp(ob = present(arg, environment(me))))
                return notify_fail("你身上和附近沒有這樣道具啊。\n");

        if (ob == this_object() || ob->is_character())
                return notify_fail("你想要幹什麼?\n");

        if( query("item_owner", ob) != query("id", me) )
                return notify_fail("你只能解除你自己的物品！\n");

        if( !sscanf(base_name(ob), "/data/template/%*s") )
                return notify_fail("這個物品沒有用干將聖符綁定過！\n");

        if( !ob->is_xunzhang() )
                return notify_fail("目前只開放解除勳章類的綁定！\n");

        if( query("equipped", ob) )
                return notify_fail("你先解除" + ob->name() + "的裝備再說！\n"); 

        id = replace_string(query("id", ob), " ", "-");
        file = "/clone/medal/"+id+".c";
        if( !objectp(obj = new(file)) )
                return notify_fail("解除勳章失敗，請聯繫巫師解決！\n");

        obj->move(me);
        rm(base_name(ob)+".c");

        tell_object(me, "你把" + name() + "蓋在" + ob->name() + "上，然後口中唸唸有詞，"
                        "只見聖符化作一道紅光飛入" + ob->name() + "體內！\n");

        tell_object(me, HIC "你感受" + ob->name() + HIC"已經解除了綁定。\n" NOR);

        destruct(ob);
        destruct(this_object());
        return 1;
}

int query_autoload()
{
        return 1;
}

