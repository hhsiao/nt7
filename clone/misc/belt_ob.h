#include <ansi.h>
#include <armor.h>

inherit MEDAL;
inherit F_NOCLONE;
inherit F_OBSAVE;

int is_medal_belt() { return 1; }
void create() {
    set_name(HIM "勳章掛帶" NOR, ({ "medal belt", "medal", "belt" }) );
    set_weight(10);

    set("unit", "張");
    set("long", HIM "一條勳章掛帶。將各種勳章鑲嵌(insert)在掛帶上，裝備掛帶後即可發揮勳章特殊作用。\n" +
        HIM "同時你也可以取下(take xunzhang)所有的鑲嵌的勳章。\n" NOR);
    set("value", 100);
    set("armor_prop/armor", 1);
    set("no_sell", 1);

    if (! check_clone()) return 0;
    restore();
    setup();
}

void init() {
    if(this_player() == environment() )
    {
        add_action("do_insert", "insert");
        add_action("do_remove", "take");
    }
}

int do_insert(string arg) {
    object me, ob;
    object tessera;
    mapping apply_prop, data;
    mapping *ins;
    string *apply;
    int i;

    me = this_player();
    ob = this_object();

    if(!arg || !objectp(tessera = present(arg, me)) )
        return notify_fail("你要鑲嵌什麼？\n");

    if(tessera == me )
        return notify_fail("你腦潮啊？\n");

    if(!tessera->is_xunzhang() )
        return notify_fail("你只能鑲嵌勳章類物品！\n");

    if(query("equipped") )
        return notify_fail("你先將佩戴的勳章掛帶解除下來再說！\n");

    if(me->query_skill("certosina", 1) < 200 )
        return notify_fail("你覺得你的鑲嵌技藝還不夠嫻熟，不敢貿然動手。\n");

    if (sscanf(base_name(tessera), "/data/%*s"))
        return notify_fail("這類物品無法用來鑲嵌。\n");

    if(query("enchase/medal" + query("enchase/SN", tessera)) )
        return notify_fail("勳章掛帶已經鑲嵌此勳章，不能重複鑲嵌同種勳章。\n");

    apply_prop = query("armor_prop", tessera);
    if(!mapp(apply_prop) || sizeof(apply_prop) < 1 )
        return notify_fail(tessera->name() + "已經是廢棄的，鑲嵌這個沒有任何意義。\n");

    message_vision(HIM "$N" HIM "將" + tessera->name() + NOR HIM"鑲嵌到了$n" HIM "上面，\n只見上面$n"
        HIM "隱隱的顯過了一道奇異的光芒，隨即變得平靜，說不出的平凡。\n\n" NOR, me, this_object());
    tell_object(me, HIC "你感受勳章掛帶發生了不可言喻的變化。\n" NOR);

    apply = keys(apply_prop);
    data = copy(query("enchase/apply_prop"));
    if(!mapp(data) ) data = ([]);

    for(i = 0; i<sizeof(apply); i++ )
    {
        if (undefinedp(data[apply[i]]) )
            data[apply[i]] = apply_prop[apply[i]];
        else
            data[apply[i]] += apply_prop[apply[i]];
    }

    set("enchase/apply_prop", data);
    set("enchase/medal"+query("enchase/SN", tessera), 1);
    ins = query("insert");
    if(!ins )
    {
        ins = ({});
    }
    ins += ({ ([ "file": base_name(tessera),
        "name": query("name", tessera),
        "id": query("id", tessera),
        "SN": query("enchase/SN", tessera),
        "armor_prop": apply_prop ])
    });

    set("insert", ins);
    destruct(tessera);
    save();

    return 1;
}

int do_remove(string arg) {
    mapping *ins;
    mapping enc;
    object belt;
    object me;
    object ob;
    int i, n;

    me = this_player();
    belt = this_object();

    if(!arg || arg != "xunzhang" )
        return notify_fail("你要取下什麼？\n");

    if(base_name(belt) != "/data/item/belt/"+query("id", me) )
        return notify_fail("你只能取下你自己的勳章掛帶上的勳章！\n");

    if(query("equipped", belt) )
        return notify_fail("你先將佩戴的勳章掛帶解除下來再說！\n");

    ins = query("insert", belt);
    if(!(n = sizeof(ins)) )
        return notify_fail("勳章掛帶上沒有鑲嵌任何勳章！\n");

    for(i = 0; i<n; i++ )
    {
        enc = ins[i];
        if(undefinedp(enc["file"]) ) continue;
        ob = new(enc["file"]);
        ob->move(me, 1);
        tell_object(me, HIC "你從勳章掛帶上取下一枚"+ob->name() + "。\n" NOR);
    }

    delete("enchase", belt);
    delete("insert", belt);

    save();

    return 1;
}

int receive_summon(object me) {
    object env;

    if((env = environment()) && env == me ) {
        write(name() + "不就在你身上嘛？你召喚個什麼勁？\n");
        return 1;
    }

    if(env == environment(me) ) {
        message_vision(HIG "只見地上的" + name() +
            HIG "化作一道光芒，飛躍至$N" HIW
            "的掌中！\n\n" NOR, me);
    } else {
        if(env ) {
            if(env->is_character() && environment(env) )
                env = environment(env);

            message("vision", HIG "突然" + name() + HIG "化作一道"
                HIG "光芒消失了！\n\n" NOR, env);

            if(interactive(env = environment()) ) {
                tell_object(env, HIM + name() +
                    HIM "忽然離你而去了！\n" NOR);
            }
        }

        message_vision(HIG "一道光芒劃過，只見$N"
            HIG "掌中多了一個$n" HIG "！\n\n" NOR,
            me, this_object());
    }

    //move(me, 1);
    if(!this_object()->move(me) )
    {
        tell_object(me, HIR "由於你的負重太高，"+this_object()->name() + HIR "化作一道光芒，已然了無蹤跡。\n" NOR);
        destruct(this_object());
        return 1;
    }
    this_object()->wear();
    return 1;
}

int hide_anywhere(object me) {
    if(query("jingli", me)<100){
        tell_object(me, "你試圖令" + name() +
            "遁去，可是精力不濟，難以發揮它的能力。\n");
        return 0;
    }
    addn("jingli", -100, me);

    message_vision(HIM "$N" HIM "輕輕一旋" + name() +
        HIM "，已然了無蹤跡。\n", me);
    save();
    destruct(this_object());
    return 1;
}

// 接受存盤數據的接口函數
int receive_dbase_data(mixed data) {
    if(!mapp(data) )
        return 0;

    map_delete(data, "equipped");
    this_object()->set_dbase(data);

    return 1;
}

// 進行保存數據的接口函數
mixed save_dbase_data() {
    mapping data;

    data = this_object()->query_entire_dbase();

    return data;
}

mixed query_autoload() { return (query("equipped") ? query("equipped") : "kept"); }
varargs void autoload(string parameter, object owner) {
    if(parameter == "worn" )
        this_object()->wear();
}

/*
 * void remove(string euid)
 * {
 * save();
 * }
 */
